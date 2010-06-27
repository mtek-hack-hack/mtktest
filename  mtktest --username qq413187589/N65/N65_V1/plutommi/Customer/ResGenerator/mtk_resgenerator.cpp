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
 *  mtk_resgenerator.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   To Generator Resource C files.
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *              HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== *******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "pixteldatatypes.h"
#include "CustDataRes.h"
#include "CustMenuRes.h"
#include "CustResDef.h"
#include "mmi_features.h"


/* buffer size for shell command */
#define SHELL_CMD_BUFLEN    (MAX_FILENAME_LEN + 100)
/* buffer size for unzip command */
#define UNZIP_CMD_BUFLEN    256

/* type definition */
typedef struct
{
    U16 Num;
} CUSTOM_ID_MAP;

typedef struct
{
    U16 minId;
    U16 maxId;
    U16 index;
} CUSTOM_ID_SEARCH_MAP;

typedef struct
{
    S8 filename[MAX_FILENAME_LEN];
} CUSTOM_NAME_LIST;


/* Extern variable */
extern "C" CUSTOM_IMAGE                nCustImageNames[];
extern "C" CUSTOM_IMAGE_MAP            ImageIdMap[];
extern "C" CUSTOM_IMAGE_SEARCH_MAP     ImageIdSearchMap[];
extern "C" IMAGENAME_LIST              ImageNameList[];
extern "C" CUSTOM_IMAGE_MAP            ImageIdMapEXT[];
extern "C" CUSTOM_IMAGE_SEARCH_MAP     ImageIdSearchMapEXT[];
extern "C" IMAGENAME_LIST              ImageNameListEXT[];

extern "C" CUSTOM_AUDIO             nCustAudioNames[];
extern "C" CUSTOM_AUDIO_MAP         AudioIdMap[];
extern "C" CUSTOM_AUDIO_SEARCH_MAP  AudioIdSearchMap[];
extern "C" AUDIONAME_LIST           AudioNameList[];
extern "C" CUSTOM_AUDIO_MAP         AudioIdMapEXT[];
extern "C" CUSTOM_AUDIO_SEARCH_MAP  AudioIdSearchMapEXT[];
extern "C" AUDIONAME_LIST           AudioNameListEXT[];

extern "C" CUSTOM_MENU              nCustMenus[];
extern "C" unsigned short           CurrMaxMenuItemIndex;   //Max menu Ids

extern "C" unsigned short           CurrMaxImageId;         //Max String Ids
extern "C" unsigned short           CurrMaxSearchImageId;   //Max String Ids
extern "C" unsigned short           CurrMaxImageNum;        //Max Number Ids
extern "C" unsigned short           CurrMaxImageIdEXT;
extern "C" unsigned short           CurrMaxSearchImageIdEXT;
extern "C" unsigned short           CurrMaxImageNumEXT;
extern "C" image_type_enum          ExtImageFlag;

extern "C" unsigned short           CurrMaxAudioId;         //Max String Ids
extern "C" unsigned short           CurrMaxSearchAudioId;   //Max String Ids
extern "C" unsigned short           CurrMaxAudioNum;        //Max Number Ids
extern "C" unsigned short           CurrMaxAudioIdEXT;
extern "C" unsigned short           CurrMaxSearchAudioIdEXT;
extern "C" unsigned short           CurrMaxAudioNumEXT;
extern "C" BOOL                     ExtAudioFlag;

extern "C" FILE*                    dest_file;
extern "C" int                      toolFlag;
extern "C" int                      resultFailFlag;

extern "C" unsigned short           CurrMaxENFBAssociatedIDNum;
extern "C" CUSTOM_ENFB_STR          ENFBAssociatedIDList[];

/* Extern functions */
extern "C" void PopulateResData(void);
extern "C" void Extract_Name(S8 *dest, S8* src, U32 res_type);
extern "C" void InitStrPopulate();
extern "C" int  MergeStrRes(void);
extern "C" int  GenerateStrResFile(void);


/*****************************************************************************
 * FUNCTION
 *  GenerateENFBAssociatedIDFile
 * DESCRIPTION
 *  generate ENFB associated ID map file
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL GenerateENFBAssociatedIDFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp;
    CUSTOM_ENFB_STR *enfb;
    int i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open file */
    fp = fopen(ENFB_DATA_FILENAME, "w");
    if(fp == NULL)
    {
        return MMI_FALSE;
    }

    /* print copyright */
    fprintf(fp, "/**\n *	Copyright Notice\n *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,\n *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.\n *  (It is illegal to remove this copyright notice from this software or any\n *  portion of it)\n */\n");
    fprintf(fp, "\n/************************************************************** \n FILENAME\t: CustENFBAssociatedMap.c \n PURPOSE\t: ENFB associated list file. \n REMARKS\t: nil \n AUTHOR\t\t: Customization Tool \n DATE\t\t: . \n **************************************************************/\n");

    /* print include file */
    fprintf(fp, "#include \"CustDataRes.h\"\n\n");

    /* dump extern variable */
    for (i = 1; i <= (int)CurrMaxENFBAssociatedIDNum; i++)
    {
        enfb = (CUSTOM_ENFB_STR *)&ENFBAssociatedIDList[i];
        for (j = 0; j < (int)enfb->count; j++)
        {
            fprintf(fp, "extern const U8 %s[];\n", enfb->Ptr[j]);
        }
    }
    fprintf(fp, "\n");

    /* print list count */
    fprintf(fp, "const U32 CurrMaxENFBAssociatedIDNum = %d;\n\n", CurrMaxENFBAssociatedIDNum + 1);

    /* dump ID list */
    for (i = 1; i <= (int)CurrMaxENFBAssociatedIDNum; i++)
    {
        enfb = (CUSTOM_ENFB_STR *)&ENFBAssociatedIDList[i];
        fprintf(fp, "const U16 Associated_IDs_%d[] = {", i);
        for (j = 0; j < (int)enfb->count - 1; j++)
        {
            fprintf(fp, "%d, ", enfb->IDs[j]);
        }
        fprintf(fp, "%d};\n", enfb->IDs[enfb->count - 1]);
    }
    fprintf(fp, "\n");

    /* dump ptr list */
    for (i = 1; i <= (int)CurrMaxENFBAssociatedIDNum; i++)
    {
        enfb = (CUSTOM_ENFB_STR *)&ENFBAssociatedIDList[i];
        fprintf(fp, "const CUSTOM_IMAGE Associated_Ptr_%d[] = {\n", i);
        for (j = 0; j < (int)enfb->count - 1; j++)
        {
            fprintf(fp, "\t(U8*)&%s,\n", enfb->Ptr[j]);
        }
        fprintf(fp, "\t(U8*)&%s\n};\n", enfb->Ptr[enfb->count - 1]);
    }
    fprintf(fp, "\n");

    /* dump CUSTOM_ENFB list */
    fprintf(fp, "const CUSTOM_ENFB AssociatedID_map[] = \n{\n");
    if (CurrMaxENFBAssociatedIDNum > 0)
    {
        fprintf(fp, "\t{0, 0, 0},\n");
    }
    else
    {
        fprintf(fp, "\t{0, 0, 0}\n");
    }
    if (CurrMaxENFBAssociatedIDNum > 0)
    {
        for (i = 1; i < (int)CurrMaxENFBAssociatedIDNum; i++)
        {
            enfb = (CUSTOM_ENFB_STR *)&ENFBAssociatedIDList[i];
            fprintf(fp, "\t{%d, (U16 *)&Associated_IDs_%d, (CUSTOM_IMAGE *)&Associated_Ptr_%d},\n", enfb->count, i, i);
        }
        fprintf(fp, "\t{%d, (U16 *)&Associated_IDs_%d, (CUSTOM_IMAGE *)&Associated_Ptr_%d}\n",
                ENFBAssociatedIDList[CurrMaxENFBAssociatedIDNum].count,
                CurrMaxENFBAssociatedIDNum, CurrMaxENFBAssociatedIDNum);
    }
    fprintf(fp, "};\n");

    /* free memory */
    for (i = 1; i <= (int)CurrMaxENFBAssociatedIDNum; i++)
    {
        enfb = (CUSTOM_ENFB_STR *)&ENFBAssociatedIDList[i];
        free(enfb->IDs);
        for (j = 0; j < (int)enfb->count; j++)
        {
            free(enfb->Ptr[j]);
        }
        free(enfb->Ptr);
    }

    fprintf(stderr, "Output CustENFBImgMap.c... done\n");

    fclose(fp);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  UnzipImage
 * DESCRIPTION
 *  unzip image to the destination folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void UnzipImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempCommand[UNZIP_CMD_BUFLEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(tempCommand,"rd /S/Q %s\\mainlcd\\", CUST_IMG_PATH);
    system(tempCommand);

    sprintf(tempCommand,"rd /S/Q %s\\sublcd\\", CUST_IMG_PATH);
    system(tempCommand);

    sprintf(tempCommand, "7za.exe x -y %s\\image.zip -o%s\\", CUST_IMG_PATH, CUST_IMG_PATH);
    system(tempCommand);

#ifndef __OPTR_NONE__
    sprintf(tempCommand, "7za.exe x -y %s\\operator_image.zip -o%s\\", CUST_OPERATOR_IMG_PATH, CUST_IMG_PATH);
    system(tempCommand);
#endif /* __OPTR_NONE__ */

#if defined(CUST_SUBLCD_PATH)
    sprintf(tempCommand, "7za.exe x -y %s\\image.zip -o%s\\", CUST_SUBLCD_PATH, CUST_IMG_PATH);
    system(tempCommand);

#ifndef __OPTR_NONE__
    sprintf(tempCommand, "7za.exe x -y %s\\operator_image.zip -o%s\\", CUST_OPERATOR_SUBLCD_PATH, CUST_IMG_PATH);
    system(tempCommand);
#endif /* __OPTR_NONE__ */
#endif /* defined (CUST_SUBLCD_PATH) */
}


/*****************************************************************************
 * FUNCTION
 *  UnzipAudio
 * DESCRIPTION
 *  unzip audio to the destination folder
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void UnzipAudio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempCommand[UNZIP_CMD_BUFLEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(tempCommand, "7za.exe x -y %s\\audio.zip -o%s\\", CUST_ADO_PATH, CUST_ADO_PATH);
    system(tempCommand);

#ifndef __OPTR_NONE__
    sprintf(tempCommand, "7za.exe x -y %s\\operator_audio.zip -o%s\\", CUST_OPERATOR_ADO_PATH, CUST_ADO_PATH);
    system(tempCommand);
#endif /* __OPTR_NONE__ */
}


/*****************************************************************************
 * FUNCTION
 *  Trace
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fmt     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void Trace(char *fmt,...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list MyList;
    char nPrintableStr[1000];   //Assumed..this can chane if need to dump more bytes

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    va_start(MyList,fmt);
    vsprintf(nPrintableStr,fmt,MyList);
    va_end(MyList);
    printf(nPrintableStr);
}


/*****************************************************************************
 * FUNCTION
 *  PopulateSearchMap_Ext
 * DESCRIPTION
 *  populate search map
 * PARAMETERS
 *  pIdMap              [IN]    ID map
 *  pIdSearchMap        [OUT]   ID search map
 *  pCurrMaxId          [OUT]   current max ID
 *  pCurrMaxSearchId    [OUT]   current max search ID
 *  MaxIdSize           [IN]    max ID
 * RETURNS
 *  void
 *****************************************************************************/
static void PopulateSearchMap_Ext(
                CUSTOM_ID_MAP *pIdMap,
                CUSTOM_ID_SEARCH_MAP *pIdSearchMap,
                unsigned short *pCurrMaxId,
                unsigned short *pCurrMaxSearchId,
                U16 MaxIdSize)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0, j = 0;
    U16 index = 0, start = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MaxIdSize; i++)
    {
        if (pIdMap[i].Num != ((U16) - 1))
        {
            if (!start)
            {
                pIdSearchMap[j].minId = pIdSearchMap[j].maxId = i;
                pIdSearchMap[j].index = index;
                index++;
                start = 1;
            }
            else 
            {
                pIdSearchMap[j].maxId = i;
                index++;
            }
        }
        else    
        {
            if (start) 
            {
                j++;
                start = 0;
            }
        }
    }
    
    *pCurrMaxSearchId = j;
    j = 0;
    for (i = 0; i < MaxIdSize; i++) 
    {
        if (pIdMap[i].Num != (U16)-1)
        {
            if (i != j)
            {
                pIdMap[j].Num = pIdMap[i].Num;
                pIdMap[i].Num = -1;
            }
            j++;
        }
    }
    *pCurrMaxId = j;
}


/*****************************************************************************
 * FUNCTION
 *  PopulateImageSearch
 * DESCRIPTION
 *  populate image search map
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PopulateImageSearch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PopulateSearchMap_Ext(
        (CUSTOM_ID_MAP *)ImageIdMap,
        (CUSTOM_ID_SEARCH_MAP *)ImageIdSearchMap,
        (unsigned short *)&CurrMaxImageId,
        (unsigned short *)&CurrMaxSearchImageId,
        MAX_IMAGE_IDS_SIZE);
    PopulateSearchMap_Ext(
        (CUSTOM_ID_MAP *)ImageIdMapEXT,
        (CUSTOM_ID_SEARCH_MAP *)ImageIdSearchMapEXT,
        (unsigned short *)&CurrMaxImageIdEXT,
        (unsigned short *)&CurrMaxSearchImageIdEXT,
        MAX_IMAGE_IDS_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  PopulateAudioSearch
 * DESCRIPTION
 *  populate audio search map
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PopulateAudioSearch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PopulateSearchMap_Ext(
        (CUSTOM_ID_MAP *)AudioIdMap,
        (CUSTOM_ID_SEARCH_MAP *)AudioIdSearchMap,
        (unsigned short *)&CurrMaxAudioId,
        (unsigned short *)&CurrMaxSearchAudioId,
        MAX_AUDIO_IDS_SIZE);
    PopulateSearchMap_Ext(
        (CUSTOM_ID_MAP *)AudioIdMapEXT,
        (CUSTOM_ID_SEARCH_MAP *)AudioIdSearchMapEXT,
        (unsigned short *)&CurrMaxAudioIdEXT,
        (unsigned short *)&CurrMaxSearchAudioIdEXT,
        MAX_AUDIO_IDS_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  GenerateResFile_Ext
 * DESCRIPTION
 *  generate resource file
 * PARAMETERS
 *  flag                [IN]    CustPack or not
 *  type                [IN]    image or audio
 *  pName               [IN]    resource name list
 *  nSize               [IN]    size
 *  str_CustDataHW      [IN]    output header name
 *  str_mtk_CurrMaxNum  [IN]    output variable name
 *  str_CurrMaxNum      [IN]    output variable name
 *  str_mtk_nCustNames  [IN]    output variable name
 *  str_nCustNames      [IN]    output variable name
 *  str_NameList        [IN]    output variable name
 *  str_CustType        [IN]    output type name
 *  curr_data_filename  [IN]    output file name
 * RETURNS
 *  void
 *****************************************************************************/
static void GenerateResFile_Ext(
                BOOL flag,
                RESOURCE_TYPE_LIST type,
                CUSTOM_NAME_LIST *pName,
                U16 nSize,
                char *str_CustDataHW,
                char *str_mtk_CurrMaxNum,
                char *str_CurrMaxNum,
                char *str_mtk_nCustNames,
                char *str_nCustNames,
                char *str_NameList,
                char *str_CustType,
                char *curr_data_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *pFile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pFile = fopen(curr_data_filename, "w"))
    {
        fprintf(pFile, "/**\n *	Copyright Notice\n *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,\n *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.\n *  (It is illegal to remove this copyright notice from this software or any\n *  portion of it)\n */\n");
        fprintf(pFile, "\n/************************************************************** \n FILENAME	:  \n PURPOSE		: Resource file. \n REMARKS		: nil \n AUTHOR		: Customization Tool \n DATE		: . \n **************************************************************/\n");
        fprintf(pFile, "#include \"CustDataRes.h\"\n");
        if((type == RES_IMAGE) && (flag == FALSE))
        {
            fprintf ( pFile, "#include \"CustGameDataHW.h\"\n");
        }
        fprintf(pFile, "#include \"%s\"\n", str_CustDataHW);
        fprintf(pFile, "#include \"CustResDef.h\"\n\n");

        if(type == RES_IMAGE)
        {
            if(flag == FALSE)
            {
                fprintf(pFile, "const S8 CustImgPath[]=CUST_IMG_PATH;\n");
            }
            else
            {
                fprintf(pFile, "\/\/const S8 CustImgPath[]=CUST_IMG_PATH;\n");
            }
        }
        if(type == RES_AUDIO)
        {
            if(flag == FALSE)
            {
                fprintf(pFile, "const S8 CustAdoPath[]=CUST_ADO_PATH;\n");
            }
            else
            {
                fprintf(pFile, "\/\/const S8 CustAdoPath[]=CUST_ADO_PATH;\n");
            }
        }

#ifdef __MULTI_BIN_LOAD__
        fprintf(pFile, "const unsigned short  %s=%d;\n", str_mtk_CurrMaxNum, nSize);
#else
        fprintf(pFile, "unsigned short  %s=%d;\n", str_CurrMaxNum, nSize);
#endif

        /* writing the image filename inside the file. */
        if(nSize)
        {
            int i = 0;

#ifdef __MULTI_BIN_LOAD__
            fprintf(pFile, "const %s	%s[]={\n", str_CustType, str_mtk_nCustNames);
#else
            fprintf(pFile, "const %s	%s[]={\n", str_CustType, str_nCustNames);
#endif

            for(i = 0; i < nSize; i++)
            {
                S8 pBuffName[200];

                Extract_Name(pBuffName, pName[i].filename, type);
                fprintf(pFile, "(U8*)&%s,\n", pBuffName);
            }

            fprintf(pFile, "};\n\n\n\n");
        }
        else
        {
#ifdef __MULTI_BIN_LOAD__
            fprintf(pFile, "const %s	%s[];\n", str_CustType, str_mtk_nCustNames);
#else
            fprintf(pFile, "const %s	%s[];\n", str_CustType, str_nCustNames);
#endif
        }

        if(flag == TRUE)
        {
            if(type == RES_IMAGE)
            {
#ifdef __MULTI_BIN_LOAD__
                fprintf(pFile, "const CUSTPACK_IMAGE_HEADER mtk_image_header={%d, (%s *)%s};", nSize, str_CustType, str_mtk_nCustNames);
#else
                fprintf(pFile, "const CUSTPACK_IMAGE_HEADER mtk_image_header={%d, (%s *)%s};", nSize, str_CustType, str_nCustNames);
#endif
            }

            if(type == RES_AUDIO)
            {
#ifdef __MULTI_BIN_LOAD__
                fprintf(pFile, "const CUSTPACK_AUDIO_HEADER mtk_audio_header={%d, (%s *)%s};", nSize, str_CustType, str_mtk_nCustNames);
#else
                fprintf(pFile, "const CUSTPACK_AUDIO_HEADER mtk_audio_header={%d, (%s *)%s};", nSize, str_CustType, str_nCustNames);
#endif
            }

        }
        
        fclose(pFile);
    }
}



/*****************************************************************************
 * FUNCTION
 *  GenerateImageResFile
 * DESCRIPTION
 *  generate image resource file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void GenerateImageResFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtImageFlag = SYSTEM_IMAGE;
    GenerateResFile_Ext(
            FALSE,
            RES_IMAGE,
            (CUSTOM_NAME_LIST *)ImageNameList,
            CurrMaxImageNum,
            "CustImgDataHW.h",
            "mtk_CurrMaxImageNum",
            "CurrMaxImageNum",
            "mtk_nCustImageNames",
            "nCustImageNames",
            "ImageNameList",
            "CUSTOM_IMAGE",
            IMG_DATA_FILENAME);
    ExtImageFlag = EXT_IMAGE;
    GenerateResFile_Ext(
            TRUE,
            RES_IMAGE,
            (CUSTOM_NAME_LIST *)ImageNameListEXT,
            CurrMaxImageNumEXT,
            "CustImgDataHWExt.h",
            "mtk_CurrMaxImageNumEXT",
            "CurrMaxImageNumEXT",
            "mtk_nCustImageNamesEXT",
            "nCustImageNamesEXT",
            "ImageNameListEXT",
            "CUSTOM_IMAGE",
            IMG_DATA_FILENAME_EXT);
}


/*****************************************************************************
 * FUNCTION
 *  GenerateAudioResFile
 * DESCRIPTION
 *  generate aurio resource file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void GenerateAudioResFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtAudioFlag = FALSE;
    GenerateResFile_Ext(
            FALSE,
            RES_AUDIO,
            (CUSTOM_NAME_LIST *)AudioNameList,
            CurrMaxAudioNum,
            "CustAdoDataHW.h",
            "mtk_CurrMaxAudioNum",
            "CurrMaxAudioNum",
            "mtk_nCustAudioNames",
            "nCustAudioNames",
            "AudioNameList",
            "CUSTOM_AUDIO",
            ADO_DATA_FILENAME);
    ExtAudioFlag = TRUE;
    GenerateResFile_Ext(
            TRUE,
            RES_AUDIO,
            (CUSTOM_NAME_LIST *)AudioNameListEXT,
            CurrMaxAudioNumEXT,
            "CustAdoDataHWExt.h",
            "mtk_CurrMaxAudioNumEXT",
            "CurrMaxAudioNumEXT",
            "mtk_nCustAudioNamesEXT",
            "nCustAudioNamesEXT",
            "AudioNameListEXT",
            "CUSTOM_AUDIO",
            ADO_DATA_FILENAME_EXT);
}


/*****************************************************************************
 * FUNCTION
 *  GenerateMapFile_Ext
 * DESCRIPTION
 *  generate ID map file
 * PARAMETERS
 *  pMap                [IN]    ID map
 *  nSize               [IN]    size
 *  str_IdMap           [IN]    output variable name
 *  str_CustMap         [IN]    output variable name
 *  str_CurrMaxId       [IN]    output variable name
 *  str_CustType        [IN]    output variable name
 *  curr_map_filename   [IN]    output file name
 * RETURNS
 *  void
 *****************************************************************************/
static void GenerateMapFile_Ext(
                CUSTOM_ID_MAP *pMap,
                U16 nSize,
                char *str_IdMap,
                char *str_CustMap,
                char *str_CurrMaxId,
                char *str_CustType,
                char *curr_map_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *pFile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pFile = fopen(curr_map_filename, "w"))
    {
        fprintf(pFile, "/**\n *	Copyright Notice\n *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,\n *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.\n *  (It is illegal to remove this copyright notice from this software or any\n *  portion of it)\n */\n");
        fprintf(pFile, "\n/************************************************************** \n FILENAME	: %s \n PURPOSE		: Resource Map file. \n REMARKS		: nil \n AUTHOR		: Customization Tool \n DATE		: . \n **************************************************************/\n", str_CustMap);
        fprintf(pFile, "#include \"CustDataRes.h\"\n\n\n");
        fprintf(pFile, "unsigned short %s=%d;\n", str_CurrMaxId, nSize);
        
        /* writing the map array inside the file. */
        if(nSize)
        {
            int i;

            fprintf(pFile, "const %s %s[]={\n", str_CustType, str_IdMap);
            for(i = 0; i < nSize; i++)
            {
                fprintf(pFile,"\t{%d},\n", pMap[i].Num);
            }
            fprintf(pFile, "};\n\n\n\n");
        }
        else
        {
            fprintf(pFile, "const %s %s[1];\n", str_CustType, str_IdMap);
        }
        fclose(pFile);
    }
}


/*****************************************************************************
 * FUNCTION
 *  GenerateImageMapFile
 * DESCRIPTION
 *  generate image ID map file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void GenerateImageMapFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtImageFlag = SYSTEM_IMAGE;
    GenerateMapFile_Ext(
            (CUSTOM_ID_MAP *)ImageIdMap,
            CurrMaxImageId,
            "ImageIdMap",
            "CustImageMap.c",
            "CurrMaxImageId",
            "CUSTOM_IMAGE_MAP",
            IMG_MAP_FILENAME);
    ExtImageFlag = EXT_IMAGE;
    GenerateMapFile_Ext(
            (CUSTOM_ID_MAP *)ImageIdMapEXT,
            CurrMaxImageIdEXT,
            "ImageIdMapEXT",
            "CustImageMapExt.c",
            "CurrMaxImageIdEXT",
            "CUSTOM_IMAGE_MAP",
            IMG_MAP_FILENAME_EXT);
}


/*****************************************************************************
 * FUNCTION
 *  GenerateAudioMapFile
 * DESCRIPTION
 *  generate audio ID map file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void GenerateAudioMapFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtAudioFlag = FALSE;
    GenerateMapFile_Ext(
            (CUSTOM_ID_MAP *)AudioIdMap,
            CurrMaxAudioId,
            "AudioIdMap",
            "CustAudioMap.c",
            "CurrMaxAudioId",
            "CUSTOM_AUDIO_MAP",
            ADO_MAP_FILENAME);
    ExtAudioFlag = TRUE;
    GenerateMapFile_Ext(
            (CUSTOM_ID_MAP *)AudioIdMapEXT,
            CurrMaxAudioIdEXT,
            "AudioIdMapEXT",
            "CustAudioMapExt.c",
            "CurrMaxAudioIdEXT",
            "CUSTOM_AUDIO_MAP",
            ADO_MAP_FILENAME_EXT);
}


/*****************************************************************************
 * FUNCTION
 *  GenerateMapSearchFile_Ext
 * DESCRIPTION
 *  generate ID search map file
 * PARAMETERS
 *  pMap                [IN]    ID search map
 *  nSize               [IN]    size
 *  str_CurrMaxSearchId [IN]    output variable name
 *  str_IdSearchMap     [IN]    output variable name
 *  str_CustType        [IN]    output variable name
 *  curr_map_filename   [IN]    output file name
 * RETURNS
 *  void
 *****************************************************************************/
static void GenerateMapSearchFile_Ext(
                CUSTOM_ID_SEARCH_MAP *pMap,
                U16 nSize,
                char *str_CurrMaxSearchId,
                char *str_IdSearchMap,
                char *str_CustType,
                char *curr_map_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *pFile;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pFile = fopen(curr_map_filename, "a"))
    {
        fprintf(pFile, "unsigned short %s=%d;\n", str_CurrMaxSearchId, nSize);
        
        /* writing the search map array inside the file. */
        if(nSize)
        {
            fprintf(pFile, "const %s %s[]={\n", str_CustType, str_IdSearchMap);
            for(i = 0; i < nSize; i++)
            {
                fprintf(pFile, "\t{%d,%d,%d},\n", pMap[i].minId, pMap[i].maxId, pMap[i].index);
            }
            fprintf(pFile, "};\n\n\n\n");
        }
        else
        {
            fprintf(pFile, "%s %s[1];", str_CustType, str_IdSearchMap);
        }
        fclose(pFile);
    }
}


/*****************************************************************************
 * FUNCTION
 *  GenerateImageMapSearchFile
 * DESCRIPTION
 *  generate image search map file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void GenerateImageMapSearchFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtImageFlag = SYSTEM_IMAGE;
    GenerateMapSearchFile_Ext(
            (CUSTOM_ID_SEARCH_MAP *)ImageIdSearchMap,
            CurrMaxSearchImageId,
            "CurrMaxSearchImageId",
            "ImageIdSearchMap",
            "CUSTOM_IMAGE_SEARCH_MAP",
            IMG_MAP_FILENAME);
    ExtImageFlag = EXT_IMAGE;
    GenerateMapSearchFile_Ext(
            (CUSTOM_ID_SEARCH_MAP *)ImageIdSearchMapEXT,
            CurrMaxSearchImageIdEXT,
            "CurrMaxSearchImageIdEXT",
            "ImageIdSearchMapEXT",
            "CUSTOM_IMAGE_SEARCH_MAP",
            IMG_MAP_FILENAME_EXT);
}


/*****************************************************************************
 * FUNCTION
 *  GenerateAudioMapSearchFile
 * DESCRIPTION
 *  generate audio search map file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void GenerateAudioMapSearchFile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExtAudioFlag = FALSE;
    GenerateMapSearchFile_Ext(
            (CUSTOM_ID_SEARCH_MAP *)AudioIdSearchMap,
            CurrMaxSearchAudioId,
            "CurrMaxSearchAudioId",
            "AudioIdSearchMap",
            "CUSTOM_AUDIO_SEARCH_MAP",
            ADO_MAP_FILENAME);
    ExtAudioFlag = TRUE;
    GenerateMapSearchFile_Ext(
            (CUSTOM_ID_SEARCH_MAP *)AudioIdSearchMapEXT,
            CurrMaxSearchAudioIdEXT,
            "CurrMaxSearchAudioIdEXT",
            "AudioIdSearchMapEXT",
            "CUSTOM_AUDIO_SEARCH_MAP",
            ADO_MAP_FILENAME_EXT);
}


/*****************************************************************************
 * FUNCTION
 *  GenerateMenuFile
 * DESCRIPTION
 *  generate menu resource file
 * PARAMETERS
 *  nSize       [IN]    size
 * RETURNS
 *  int
 *****************************************************************************/
static int GenerateMenuFile(U16 nSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE* pFile;
    CUSTOM_MENU* pCustMenu = (CUSTOM_MENU*)nCustMenus;
    S8 nItemData[100];      /* Assumed ..*/
    S8 MenuItemString[500]; /* Assumed ..*/
    int i,j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pFile = fopen(MENU_DATA_FILENAME, "w"))
    {
        fprintf(pFile, "/**\n *	Copyright Notice\n *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,\n *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.\n *  (It is illegal to remove this copyright notice from this software or any\n *  portion of it)\n */\n");
        fprintf(pFile, "\n/************************************************************** \n FILENAME	: CustMenuRes.c \n PURPOSE		: Menu Resource file. \n REMARKS		: nil \n AUTHOR		: Customization Tool \n DATE		: . \n **************************************************************/\n");

        /* put the headers needed here */
        fprintf(pFile, "#include \"CustMenuRes.h\"\n\n\n");
        fprintf(pFile, "unsigned short  CurrMaxMenuItemIndex=%d;\n", nSize);

        /* writing the string array inside the file. */
        if(nSize)
        {
            for(i = 0; i < nSize; i++)
            {
                if(pCustMenu[i].nNumofMenuItem)
                {
                    sprintf(MenuItemString, "const U16 nOrderMenuItem_%d[]={", i);
                    for(j = 0; j < (pCustMenu[i].nNumofMenuItem - 1); j++)
                    {
                        sprintf(nItemData, "%d,", pCustMenu[i].nOrderMenuItemId[j]);
                        strcat(MenuItemString, nItemData);
                    }
                    sprintf(nItemData, "%d};", pCustMenu[i].nOrderMenuItemId[j]);
                    strcat(MenuItemString, nItemData);          
                    fprintf(pFile, "%s\n", MenuItemString);
                }
                
            }
            fprintf(pFile, "\n const CUSTOM_MENU		mtk_nCustMenus[]={\n");
            for(i = 0; i < nSize; i++)
            {
                if(pCustMenu[i].nNumofMenuItem)
                    sprintf(MenuItemString, "{%d,%d,%d,%d,%d,%d,%d,%d,(U16 *)nOrderMenuItem_%d},", pCustMenu[i].nMenuItemId, pCustMenu[i].nParentId, pCustMenu[i].nNumofMenuItem, pCustMenu[i].nHideFlag, pCustMenu[i].nMovable, pCustMenu[i].nDispAttribute, pCustMenu[i].nStrId, pCustMenu[i].nImageId, i);
                else
                    sprintf(MenuItemString, "{%d,%d,%d,%d,%d,%d,%d,%d,(U16 *)0},", pCustMenu[i].nMenuItemId, pCustMenu[i].nParentId, pCustMenu[i].nNumofMenuItem, pCustMenu[i].nHideFlag, pCustMenu[i].nMovable, pCustMenu[i].nDispAttribute, pCustMenu[i].nStrId, pCustMenu[i].nImageId);
                fprintf(pFile, "%s\n", MenuItemString);

            }

            fprintf(pFile, "};\n");
        }
        else
        {
            fprintf(pFile, "const CUSTOM_MENU		nCustMenus[1];");
        }
        fclose(pFile);
    }
    else
    {
        return 0;
    }
    return 1;
}


extern "C" void ToolPopulateInitial(void);
extern "C" void ToolPopulateDone(void);
extern "C" MMI_BOOL Iload(S8 *string, U16* pType);
extern "C" MMI_BOOL Aload(S8 *string, U16* pType);
extern "C" S8 ToUpper(S8 ch);

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern "C" int disableENFB;
#endif


/*****************************************************************************
 * FUNCTION
 *  main
 * DESCRIPTION
 *  main function of mtk_resgenerator
 * PARAMETERS
 *  
 * RETURNS
 *  int
 *****************************************************************************/
int main(int argc, char *argv[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempCommand[SHELL_CMD_BUFLEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(argc == 5)   //Check if run by CustPack tool
    {
        if(strcmp(argv[1], "-f")==0 && (strcmp(argv[2], "-i")==0 || strcmp(argv[2], "-a")==0))//-i: image, -a: audio
        {
            U16 nType;
            S16 nStrlen;
            S8 upperFileName[MAX_FILENAME_LEN];
        
            dest_file = fopen(argv[4], "wb");
            if (dest_file == NULL){
                resultFailFlag = 1;
                printf("dest_file could not open!\n");
            }

            toolFlag = 1;
            ToolPopulateInitial();

            nStrlen = strlen(argv[3]) ;
            while (nStrlen>=0)
            {
                upperFileName[nStrlen] = ToUpper(argv[3][nStrlen]);
                --nStrlen;
            }

        #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
            disableENFB = 1;
        #endif
            if(strcmp(argv[2], "-i")==0)
            {
                Iload(upperFileName, &nType);
            }
            else if(strcmp(argv[2], "-a")==0)
            {
                Aload(upperFileName, &nType);
            }
        #ifdef __MMI_RESOURCE_ENFB_SUPPORT__
            disableENFB = 0;
        #endif
            //ToolPopulateDone();

            if(dest_file != NULL)
            {
                fclose(dest_file);
            }

            if(resultFailFlag==1)
            {
                sprintf(tempCommand, "del -F %s", argv[4]);
                system(tempCommand);
            }
        }
        else
        {
            printf("Usage: mtk_resgenerator.exe -f [-i or -a] ImageFilename OutputFilename\n");
        }
        
        return 1;
    }

    if(argc==3)
    {
        if(strcmp(argv[1], "-g")==0 && strcmp(argv[2], "-x")==0)
        {
            UnzipImage();
            UnzipAudio();
        }
        else
        {
            printf("Usage: mtk_resgenerator.exe -g -x\n");
            return 0;
        }
    }
    
    if((argc==2 || argc==3) && strcmp(argv[1], "-g")==0)
    {
        printf("MediaTek Resource Generate System 0.1\n");
        InitStrPopulate();
        PopulateResData();

        PopulateImageSearch();
        GenerateImageResFile();
        GenerateImageMapFile();
        GenerateImageMapSearchFile();

        PopulateAudioSearch();
        GenerateAudioResFile();
        GenerateAudioMapFile();
        GenerateAudioMapSearchFile();

        GenerateMenuFile(CurrMaxMenuItemIndex);

        GenerateENFBAssociatedIDFile();

        if (MergeStrRes() == 0)
            GenerateStrResFile();

        return 1;
    }

    printf("Usage: mtk_resgenerator.exe -g\n");
    return 0;
}
