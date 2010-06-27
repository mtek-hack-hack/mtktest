/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   custom_imps_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file contains IMPS configuration default value. 
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------*/




#ifdef __IMPS__
#include "kal_release.h"
#include "mmi2imps_struct.h"
#include "custom_imps_config.h"
#include "fat_fs.h"

extern int sprintf(char *buffer, const char *format, ... );
extern kal_uint16 app_ansii_to_unicodestring(kal_int8 *pOutBuffer, kal_int8 *pInBuffer);

kal_uint8 imps_directory[10]; 
kal_uint8 imps_client_id[IMPS_MAX_URL_LEN]= {"http://www.mtk.com/impsapp"};

const imps_accepted_content_type_struct imps_content_type[] =
{
        /*Note:Per SPEC,mime type must not be text/plain here*/
    {"image/*",204800/*must less than max_push_len*/,0,0},
    {"audio/*",204800,0,0},
    {"video/*",204800,0,0},    
    /*Don't remove this line! Add elements before it */        
    {"",0,0,0}
};

const imps_my_client_info_struct imps_pa_client_info =
{
    KAL_FALSE,/*any_content*/
    "eng",/*lang:Three-letter language code as specified in[ISO639-2].*/
    512,/*accepted_text_len:must be less than 1024,because the max ctrl_buff size is 2K (utf8->UCS2)*/
    307200,/*max_push_len*/        
    (imps_accepted_content_type_struct*)imps_content_type     
};

const imps_custom_client_capability_struct imps_client_capability =
{
   307200,
   0x06,//IMPS_SUPPORTED_BEARER_WSP|IMPS_SUPPORTED_BEARER_HTTP
   307200,
   0x0b,//IMPS_CIR_METHOD_WAPSMS|IMPS_CIR_METHOD_WAPUDP|IMPS_CIR_METHOD_STCP
   IMPS_CLIENT_ID_TYPE_URL_RANDOM,//IMPS_CLIENT_ID_TYPE_URL_RANDOM
   (kal_uint8*)imps_client_id,
   (kal_uint8*)IMPS_DEFAULT_HEADER,
   (kal_uint8*)IMPS_OBJECT_HEADER,
   (imps_my_client_info_struct*)&imps_pa_client_info,
#ifdef JATAAYU_SUPPORT
   60*KAL_TICKS_1_SEC,      /* 60s: double timeout for pipeline not being supported in Jataayu */
#else
   30*KAL_TICKS_1_SEC,      /* 30s: default timeout period defined in WV CSP V1.2 */
#endif
   240                      /* Default Time-To-Live value, count by second */
};

const imps_custom_client_capability_struct * imps_client_capability_p = &imps_client_capability;


void imps_custom_work_directory(void)
{

    kal_int32 fd;
    kal_wchar ucs2_folder[IMPS_MAX_FILE_PATH_LEN];

    /*Create folders(@imps,@imps\image) in system drive*/
    kal_mem_set((kal_char*) ucs2_folder, 0, IMPS_MAX_FILE_PATH_LEN * 2);
    app_ansii_to_unicodestring((kal_int8 *)ucs2_folder,(kal_int8 *)"Z:\\@imps\\");
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        fd = FS_CreateDir(ucs2_folder);
    }
    else
   	 {
        FS_Close(fd);
        }   	 	

    /*image*/
    kal_mem_set((kal_char*) ucs2_folder, 0, IMPS_MAX_FILE_PATH_LEN * 2);    
    kal_wsprintf(ucs2_folder,"%s%s","Z:\\@imps\\",IMPS_STATUS_CONTENT_FOLDER);
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        FS_CreateDir(ucs2_folder);
    }
    else
    {
        FS_Close(fd);
    }

    
#ifdef IMPS_IN_LARGE_STORAGE
    /*Create folders(imps) in user drive*/
    sprintf((char*)imps_directory, "%c%s",IMPS_APP_DISK,":\\imps\\");
    kal_mem_set((kal_char*) ucs2_folder, 0, IMPS_MAX_FILE_PATH_LEN * 2);
    app_ansii_to_unicodestring((kal_int8 *)ucs2_folder,(kal_int8 *)imps_directory);
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        fd = FS_CreateDir(ucs2_folder);
        FS_SetAttributes((unsigned short*)ucs2_folder,FS_ATTR_DIR|FS_ATTR_HIDDEN);	    
    }
    else
    {
        FS_Close(fd);
    }
#else
    strcpy((char*)imps_directory,"Z:\\@imps\\");
#endif

    /*reply*/
    kal_mem_set((kal_char*) ucs2_folder, 0, IMPS_MAX_FILE_PATH_LEN * 2);
    kal_wsprintf(ucs2_folder, "%s%s", imps_directory, IMPS_HTTP_REPLY_FOLDER);
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        FS_CreateDir(ucs2_folder);
    }
    else
    {
        FS_Close(fd);
    }

    /*user*/
    kal_mem_set((kal_char*) ucs2_folder, 0, IMPS_MAX_FILE_PATH_LEN * 2);
    kal_wsprintf(ucs2_folder, "%s%s", imps_directory, IMPS_USER_CONTENT_FOLDER);
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        FS_CreateDir(ucs2_folder);
    }
    else
    {
        FS_Close(fd);
    }    

    /*Received*/
    kal_mem_set((kal_char*) ucs2_folder, 0, IMPS_MAX_FILE_PATH_LEN * 2);
    kal_wsprintf(ucs2_folder, "%c:\\%w", IMPS_PUBLIC_DRV, IMPS_DEFAULT_FILE_PATH);
    fd = FS_Open(ucs2_folder, FS_OPEN_DIR | FS_READ_ONLY);
    if (fd < 0)
    {
        FS_CreateDir(ucs2_folder);
    }
    else
    {
        FS_Close(fd);
    }      
}

#endif
