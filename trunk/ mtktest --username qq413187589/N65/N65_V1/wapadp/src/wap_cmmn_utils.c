/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   wap_cmmn_utils.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains common utility functions for WAP solutions.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"

#include "fat_fs.h"         /* file system */
#include "L4Dr.h"
#include "FileManagerGProt.h"


/*****************************************************************************
 * FUNCTION
 *  wap_prepare_root_folder
 * DESCRIPTION
 *  This function is to prepare the root folder for WAP solutions. If the folder
 *  exists but is not for the calling solution, it is deleted and recreated.
 * CALLS
 *  
 * PARAMETERS
 *  path           [IN]        WAP root folder path (length < 120)
 *  identifier     [IN]        string to identify the solution
 * RETURNS
 *  1 if the folder is created, 0 if nothing has been changed.
 *****************************************************************************/
int wap_prepare_root_folder(const WCHAR* path, const char *identifier)
{
    FS_HANDLE handle;
    char tmpsz[16] = "";
    WCHAR buf[128];
    UINT bytes;
    int ret;

    ASSERT(kal_wstrlen(path) < 120);
    ASSERT(strlen(identifier) < 16);

    /* Check if the folder exists or not */
    if (FS_GetAttributes(path) >= 0)
    {
        /* Folder exists, check whether the id file exists */
        memset(buf, 0, 128 * sizeof(WCHAR));
        kal_wstrcat(buf, path);
        kal_wstrcat(buf, (const WCHAR*)L"\\idz");

        if (FS_GetAttributes(buf) >= 0)
        {
            /* File exists, read the identifier in it */
            handle = FS_Open((const WCHAR*)buf, FS_OPEN_SHARED | FS_READ_ONLY);
            
            EXT_ASSERT(handle >= 0, handle, 0, 0);
            
            ret = FS_Read(handle, tmpsz, 16, &bytes);

            EXT_ASSERT(ret == FS_NO_ERROR, ret, 0, 0);

            FS_Close(handle);

            if(strcmp((const char *)tmpsz, identifier) == 0)
            {
                /* Folder is for the current solution, nothing to do. */
                return 0;
            }
        }
        goto RMDIR;
    }
    goto MKDIR;
      
RMDIR:
    /* Remove the folder sicne it's not for the current solution */
    FS_XDelete(path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);

MKDIR:
    /* Create the root folder */
    ret = FS_CreateDir(path);

    EXT_ASSERT(ret == FS_NO_ERROR, ret, 0, 0); 

    memset(buf, 0, 128 * sizeof(WCHAR));
    kal_wstrcat(buf, path);
    kal_wstrcat(buf, (const WCHAR*)L"\\idz");

    /* Create the identifier file here, and write the identifier */
    handle = FS_Open((const WCHAR*)buf, FS_CREATE | FS_READ_WRITE);
    
    EXT_ASSERT(handle >= 0, handle, 0, 0);
    
    ret = FS_Write(handle, (void *)identifier, strlen(identifier), &bytes);

    EXT_ASSERT(ret == FS_NO_ERROR, ret, 0, 0);

    FS_Close(handle);

    return 1;
}


