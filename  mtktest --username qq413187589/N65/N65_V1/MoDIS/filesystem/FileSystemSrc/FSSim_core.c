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
 *  FSSim_core.c
 *
 * Project:
 * --------
 *  FSSIM
 *
 * Description:
 * ------------
 *  This file implements core functions of File System Simulation.
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
 *============================================================================
 ****************************************************************************/

#define _WIN32_WINNT 0x0500
#define UNICODE

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#ifndef MMI_ON_WIN32
#include "kal_release.h"
#endif

#include "fs_type.h"
#include "fat_fs.h"

#include "FSSim_def.h"

#ifdef MMI_ON_WIN32
#include "DebugInitDef.h"   /* for PRINT_INFORMATION() */
#endif

#include "Conversions.h"
extern unsigned char PhnsetGetDefEncodingType(void);

#define CRITICAL_SECTION_BEGIN   OSC_Sys_Schedule_Enable(0)
#define CRITICAL_SECTION_END     OSC_Sys_Schedule_Enable(1)


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_pick_mapped_local_path                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function determine mapped local path  initialization.       */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
static void fssim_pick_mapped_local_path(void)
{
    TCHAR tmp_name[MAX_PATH], *pch;
    TCHAR profile_value[MAX_PATH];

    /* README :
     *   Basicaly, Read .INI first, if value set, use it.
     *   If *NOT*, use relative path
     *
     *   after this sub-routine finish, fssim_root_dir will be set
     */

    GetModuleFileName( NULL, fssim_root_dir, MAX_PATH);
    pch = wcsrchr( fssim_root_dir, L'\\');
    *(++pch) = 0;

    wcscpy(tmp_name, fssim_root_dir);
    wcscat(tmp_name, FSSIM_INI_FILENAME);
    GetPrivateProfileString(FSSIM_INI_SECTION, FSSIM_INI_KEY,
                            L"", profile_value, sizeof(profile_value), tmp_name);

    if( wcslen(profile_value) >= 3 /* T:\ */ )
    {
        wcsncpy(fssim_root_dir, profile_value, MAX_PATH);

        fssim_printf(("[FS_SIM] Pick INI mapped local path setting\n"));

#ifdef DEBUG_FSSIM
        fssim_printf(("fssim_pick_mapped_local_path(): INI setting path = "));
        fssim_print_str(fssim_root_dir);
#endif  /* DEBUG_FSSIM */
    }
    else
    {
            /* Append relative path */
        wcscat( fssim_root_dir, FSSIM_RELATIVE_PATH_FOR_ROOT_DIR );
#ifdef DEBUG_FSSIM
        fssim_printf(("fssim_pick_mapped_local_path(): execution path + relative_path = "));
        fssim_print_str(fssim_root_dir);
#endif  /* DEBUG_FSSIM */
    }

            /* Get and Remember Current Dir path */
    GetCurrentDirectory(MAX_PATH, tmp_name);

            /* Set and Get Current Dir path --- To eliminate relative mark */
    if( ! SetCurrentDirectory( fssim_root_dir ) )
    {       /* Fail Handle */
        fssim_printf(("Cannot Locate the Root Dir ; Error Code: %d\nPath:", GetLastError()));
        fssim_print_str(fssim_root_dir);
        EXT_ASSERT(0, 0, 0, 0);
    }
    GetCurrentDirectory(MAX_PATH, fssim_root_dir);

            /* Resotre the Path */
    SetCurrentDirectory(tmp_name);

    wcscat( fssim_root_dir, L"\\" );
#ifdef DEBUG_FSSIM
    fssim_printf(("fssim_init(): fssim_root_dir = "));
    fssim_print_str(fssim_root_dir);
#endif  /* DEBUG_FSSIM */
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_init                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function performs initialization.                           */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
static void fssim_get_drive_watermark(FSSIM_DRVINFO_T *);
static void fssim_init()
{
    HANDLE hDir;
    int i, isinit;
    TCHAR drv_name[MAX_PATH], *pch;
    DWORD retval;

    __try {

        isinit = 0;

        /* create mutex */

        fssim_mutex = fssim_create_mutex();

        ASSERT(fssim_mutex != NULL);

        fssim_sort_mutex = fssim_create_mutex();

        ASSERT(fssim_sort_mutex != NULL)

        fssim_disk_space_mutex = fssim_create_mutex();

        ASSERT(fssim_disk_space_mutex != NULL)

        /* call out to determine local mapped path as fssim_root_dir */
        fssim_pick_mapped_local_path();

        /* prepare the template directory name */
        
        wcscpy(drv_name, fssim_root_dir);
        pch = drv_name + wcslen(drv_name);
        
        wcscpy(pch, FSSIM_DRIVE_DIR);

        /* create/open all drive directories */

        for (i = 0; i < FSSIM_MAX_DRIVE; i++) {

            pch = drv_name + wcslen(drv_name);

            wcsncpy(pch - 2, &(fssim_drvinfo[i].drive), 1);

            /* initialize fssim_drvinfo[] */

            fssim_drvinfo[i].is_current = (i == 0)? 1: 0;   /* system drive the is default current drive */

            wcscpy(fssim_drvinfo[i].dir_name, drv_name);

#ifdef DEBUG_FSSIM
            fssim_printf(("fssim_init(): fssim_drvinfo[%d].dir_name = ", i));
            fssim_print_str(fssim_drvinfo[i].dir_name);
#endif  /* DEBUG_FSSIM */

            /* try to open the direcotry */

            hDir = CreateFile(drv_name, GENERIC_READ | GENERIC_WRITE,
                              FILE_SHARE_READ, NULL, OPEN_EXISTING,
                              FILE_ATTRIBUTE_NORMAL | FILE_FLAG_BACKUP_SEMANTICS, NULL);

            if (hDir != INVALID_HANDLE_VALUE) {

                CloseHandle(hDir);

            } else {

                /* the directory doesn't exist */

                /* try to create the directory */

                if (CreateDirectory(drv_name, NULL) == 0) {

                    retval = GetLastError();

                    fssim_printf(("FSSim_Init(): fail to create directory %s, error code = %u\n", drv_name, retval));

                    ASSERT(0);
                }
            }

        } /* for (i = 0; i < FSSIM_MAX_DRIVE; i++) */

        /* initialize fssim_drvmap */

        memset(&fssim_drvmap, 0, sizeof(FSSIM_DRVMAP_T));

        /* initialize fssim_file */

        memset(&fssim_file, 0, sizeof(FSSIM_FILE_T) * (1 + FSSIM_MAX_FILE) );

        /* initialize fssim_vfgen 
         * XXX: Simulator use dynamic array for virtual filename generate and lookup
         * XXX: while there's no such table on target platform.
         */
        memset(&fssim_vfgen, 0, sizeof(FSSIM_VFTABLE_T) );
        fssim_vfgen.allocat_size = 8;
        fssim_vfgen.data = (FSSIM_VIRTUAL_FILENAME_T *)
            malloc( sizeof(FSSIM_VIRTUAL_FILENAME_T) * fssim_vfgen.allocat_size );
        ASSERT( fssim_vfgen.data != NULL );
        memset(fssim_vfgen.data, 0, sizeof(FSSIM_VIRTUAL_FILENAME_T) * fssim_vfgen.allocat_size );

        isinit = 1;
    }
    __finally {

        if (isinit == 0) {

            fssim_printf(("FSSIM error: fail to initialize\n"));

            ASSERT(0);
        }

        FS_MappingDrive(FSSIM_SYSTEM_DRIVE, FSSIM_REMAP_SYSTEM_DRIVE);
        fssim_get_drive_watermark( &(fssim_drvinfo[0]) );
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_alloc_fh                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to allocate a new file handle.             */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      file handle                                                      */
/*                                                                       */
/*************************************************************************/
static int fssim_alloc_fh()
{
    int i;
    static unsigned int fhseq = 0x1077;

    if (fssim_mutex == NULL) {
        fssim_init();
    }

    fssim_take_mutex(fssim_mutex);

    for (i = 1; i <= FSSIM_MAX_FILE; i++, fhseq++) {

        if (fssim_file[i].state == STATE_FREE) {

            fssim_file[i].state  = STATE_INUSE;
            fssim_file[i].unique = fhseq++;
            fssim_file[i].taskid = fssim_get_task_self_id();
            fssim_file[i].drive  = -1;

            break;
        }
    }

    fssim_give_mutex(fssim_mutex);

    if (i == (FSSIM_MAX_FILE + 1)) {

        /* file handles are exhausted */

        fssim_printf(("fssim_new_fh(): file handles are exhausted\n"));

        ASSERT(0);
        return -1;
    } else
        return i;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_free_fh                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to free a new file handle.                 */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      fh  -  file handle                                               */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
static void fssim_free_fh(const int fh)
{
    if (fssim_mutex == NULL) {
        fssim_init();
    }

    fssim_take_mutex(fssim_mutex);

    if (fssim_file[fh].state == STATE_INUSE)
        ASSERT(fssim_file[fh].handle == INVALID_HANDLE_VALUE);

    memset( &(fssim_file[fh]), 0, sizeof(FSSIM_FILE_T));

    fssim_file[fh].state = STATE_FREE;

    fssim_give_mutex(fssim_mutex);

}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_conv_fn                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to convert a file name.                    */
/*      (x:\  ==>  DRIVEx\)                                              */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      dst  -  destination buffer                                       */
/*      src  -  source file name                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
int fssim_get_default_drive(void);
static void fssim_conv_fn(TCHAR *dest, const TCHAR *source)
{
    TCHAR *pmap, *pchdst;
    const TCHAR *pchsrc;

    ASSERT(dest != NULL && source != NULL);

    /* copy dest , source */
    pchdst = dest;
    pchsrc = source;

    /* Type 1 : only drive name specified , (ex  X: only) */
    if (wcslen(pchsrc) == 2 && _wcsicmp(pchsrc + 1, L":") == 0) {

        /* copy root directory name first */

        wcscpy(pchdst, fssim_root_dir);

        pchdst += wcslen(pchdst);

        /* copy drive directory name (DRIVE_X) */

        wcscpy(pchdst, FSSIM_DRIVE_DIR);

        pchdst += wcslen(pchdst);

        *(pchdst - 2) = *pchsrc;

        /* don't need to copy remain source , point to NULL termined */
        pchsrc += 2;
    }

    /* Type 2 : no drive name specified , must be relative path */
    else if (wcsncmp(pchsrc + 1, L":\\", wcslen(L":\\")) != 0) {

        /* get default drive and its default dir name */
        wcscpy(pchdst, fssim_drvinfo[fssim_get_default_drive()].dir_name);

        pchdst += wcslen(pchdst);

        /* check if \\ append ? noop : append '\' */
        if (*(pchdst - 2) != L'\\') {

            *pchdst++ = L'\\';
        }
    }

    /* Type 3 : drive name specified , general case */
    else {

        /* copy root directory name first */
        wcscpy(pchdst, fssim_root_dir);

        pchdst += wcslen(pchdst);

        /* copy drive directory name (DRIVE_X) */

        wcscpy(pchdst, FSSIM_DRIVE_DIR);

        pchdst += wcslen(pchdst);

        *(pchdst - 2) = *pchsrc;

        /* point pchsrc to the remain path */
        pchsrc += wcslen(L"X:\\");
    }

    /* Check if remap drive name required */
    pmap = wcsstr(dest + wcslen(fssim_root_dir) , FSSIM_DRIVE_DIR_PREFIX);
    EXT_ASSERT(pmap != NULL, 0, 0, 0);

    if (fssim_drvmap.original != 0) {

        /* try to map the drive letter */

        if (!wcsnicmp(pmap + wcslen(FSSIM_DRIVE_DIR_PREFIX), &(fssim_drvmap.mapped), 1)) {

            /* the drive name is equal to the to-be-mapped drive letter */

            wcsncpy(pmap + wcslen(FSSIM_DRIVE_DIR_PREFIX), &(fssim_drvmap.original), 1);
        }
    }

    /* copy remain path and check if dest length over MAX_PATH */
    EXT_ASSERT( (wcslen(pchsrc) + (pchdst - dest)) < MAX_PATH , 0 , 0, 0 );
    wcscpy( pchdst, pchsrc );
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_retrieve_fn                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to retrieve a file name.                   */
/*      (DRIVEx\  ==>  x:\)                                              */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      filename  -  destination buffer                                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
static void fssim_retrieve_fn(TCHAR *filename)
{
    TCHAR strbuf[MAX_PATH], *pch;

#ifdef DEBUG_FSSIM
    fssim_printf(("fssim_retrieve_fn(): filename = "));
    fssim_print_str(filename);
#endif  /* DEBUG_FSSIM */

    /* build a string of pattern "\\DRIVE_" */

    wcscpy(strbuf, L"\\");

    wcscpy(strbuf + 1, FSSIM_DRIVE_DIR);

    wcscpy(strbuf + wcslen(strbuf) - 2, L"\0");   /* remove "X" and "//" */

#ifdef DEBUG_FSSIM
    fssim_printf(("fssim_retrieve_fn(): strbuf = "));
    fssim_print_str(strbuf);
#endif  /* DEBUG_FSSIM */

    /* find "\\DRIVE_" */

    pch = wcsstr(filename, strbuf);

    if (pch == NULL) {

        fssim_printf(("fssim_retrieve_fn(): cannot find a legal drive name\n"));

        fssim_print_str(filename);

        ASSERT(0);
    } else {

#ifdef DEBUG_FSSIM
        fssim_printf(("fssim_retrieve_fn(): pch = "));
        fssim_print_str(pch);
#endif  /* DEBUG_FSSIM */

        /* move pch to the string of drive name (C or D or E or...) */

        pch += wcslen(strbuf);

#ifdef DEBUG_FSSIM
        fssim_printf(("fssim_retrieve_fn(): pch = "));
        fssim_print_str(pch);
#endif  /* DEBUG_FSSIM */

        /* copy the drive name */
        filename[0] = pch[0];
        wcscpy(filename + 1, L":");

        /* copy the director name after the drive name */

        wcscpy(filename + wcslen(filename), pch + 1);

        if (!_wcsicmp(filename + wcslen(filename) - 1, L":")) {

            /* there is no "\\" following ":" */

            /* append ":" */

            wcscpy(filename + wcslen(filename), L"\\");
        }

#ifdef DEBUG_FSSIM
        fssim_printf(("fssim_retrieve_fn(): retrieving filename = "));
        fssim_print_str(filename);
#endif  /* DEBUG_FSSIM */

    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_get_short_name                                             */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get short file name from a given path.  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      src   -   source path                                            */
/*      dst   -   destination buffer                                     */
/*      len   -   length of dst                                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Number of bytes transfered                                       */
/*                                                                       */
/*************************************************************************/
static int fssim_get_short_name(const TCHAR *src, TCHAR *dst, DWORD len)
{
    DWORD retval;
    TCHAR strbuf[MAX_PATH], *pch, *pchOld;

    ASSERT(src != NULL && dst != NULL);

    CRITICAL_SECTION_BEGIN;
    retval = GetShortPathName(src, strbuf, MAX_PATH);
    CRITICAL_SECTION_END;

    if (retval == 0) {

#ifdef DEBUG_FSSIM

        fssim_printf(("GetShortPathName() failed in fssim_get_short_name()\n"));
        fssim_printf(("error code = %d\n", GetLastError()));

#endif  /* DEBUG_FSSIM */

        return 0;
    }

    if (!wcscmp(strbuf + wcslen(strbuf) - 1, L"\\")) {

        /* the last character is "\\" */

        /* remove it */

        wcsncpy(strbuf + wcslen(strbuf) - 1, L"\0", 1);
    }

    /* extract last name from the path */

    pch = wcsstr(strbuf, L"\\");

    pchOld = pch;

    while (pch != NULL) {

        pchOld = pch;

        pch = wcsstr(pch + 1, L"\\");
    }

    pch = (pchOld == NULL)? strbuf: pchOld + 1;

    if (len < wcslen(pch)) {

        wcsncpy(dst, pch, len);

        dst[ len ] = '\0';

        return len;
    } else {

        wcsncpy(dst, pch, wcslen(pch));

        dst[ wcslen(pch) ] = '\0';

        return wcslen(pch);
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_isopen                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to check whether is file is opened or not. */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      filename  -  file name of the file to check                      */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Non-zero if it is opened; zero if it is not opened               */
/*                                                                       */
/*************************************************************************/
static int fssim_isopen(const TCHAR *filename)
{
    int i, result = 0;

    if (fssim_mutex == NULL) {
        fssim_init();
    }

    fssim_take_mutex(fssim_mutex);

    for (i = 1; i <= FSSIM_MAX_FILE; i++) {

        if (fssim_file[i].state == STATE_INUSE) {

            if (!_wcsicmp(fssim_file[i].filename, filename)) {

                result = 1;

                break;
            }
        }
    }

    fssim_give_mutex(fssim_mutex);

    return result;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_progress                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is the callback routine for move/copy operation.   */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*                                                                       */
/*************************************************************************/
static DWORD CALLBACK fssim_progress(
  LARGE_INTEGER TotalFileSize,          // file size
  LARGE_INTEGER TotalBytesTransferred,  // bytes transferred
  LARGE_INTEGER StreamSize,             // bytes in stream
  LARGE_INTEGER StreamBytesTransferred, // bytes transferred for stream
  DWORD dwStreamNumber,                 // current stream
  DWORD dwCallbackReason,               // callback reason
  HANDLE hSourceFile,                   // handle to source file
  HANDLE hDestinationFile,              // handle to destination file
  LPVOID lpData                         // from CopyFileEx
)
{
    int fh = (int)lpData;

    if (fssim_file[fh].isabort == 1)

        return PROGRESS_STOP;

    if (fh >= 0 && fssim_file[fh].copyprogress != NULL)

        fssim_file[fh].copyprogress(FS_MOVE_PGS_ING, (DWORD)TotalFileSize.QuadPart, (DWORD)TotalBytesTransferred.QuadPart, fh);

    return PROGRESS_CONTINUE;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_conv_errcode                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to convert WIN32 error code to FS error    */
/*      code.                                                            */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      err   -   WIN32 error code                                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS error code                                                    */
/*                                                                       */
/*************************************************************************/
static int fssim_conv_errcode(DWORD err, char *msg)
{
    int ret_err;

    switch (err) {

    case ERROR_INVALID_NAME:

        /* the name is not valid */

        ret_err = FS_INVALID_FILENAME;

        break;

    case ERROR_FILE_NOT_FOUND:

        /* the file doesn't exist */

        ret_err = FS_FILE_NOT_FOUND;

        break;

    case ERROR_SHARING_VIOLATION:

        ret_err = FS_ACCESS_DENIED;

        break;

    case ERROR_ACCESS_DENIED:

        ret_err = FS_ACCESS_DENIED;

        break;

    case ERROR_REQUEST_ABORTED:

        ret_err = FS_ABORTED_ERROR;

        break;

    case ERROR_PATH_NOT_FOUND:

        ret_err = FS_PATH_NOT_FOUND;

        break;

    default:

        /* un-handled error */

#ifdef DEBUG_FSSIM

        fssim_printf((msg));

        fssim_printf(("error code = %d\n", err));

#endif  /* DEBUG_FSSIM */

        ret_err = FS_NO_ERROR;

        break;
    }

    return ret_err;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_is_file_exist                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to check whether the file exists or not.   */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      filename   -   file name to check                                */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      1 if the file exists; 0 if the file doesn't exist                */
/*                                                                       */
/*************************************************************************/
static int fssim_is_file_exist(TCHAR *filename)
{
    DWORD error;

    SetLastError(ERROR_SUCCESS);

    CRITICAL_SECTION_BEGIN;
    GetFileAttributes(filename);
    CRITICAL_SECTION_END;

    error = GetLastError();

    if (error == ERROR_PATH_NOT_FOUND || error == ERROR_FILE_NOT_FOUND)

        return 0;

    else

        return 1;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_is_name_valid                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to check whether the file is valid or not. */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      filename   -   file name to check                                */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      1 if the file name is valid; 0 if the file is not valid          */
/*                                                                       */
/*************************************************************************/
static int fssim_is_name_valid(TCHAR *filename)
{
    SetLastError(ERROR_SUCCESS);

    CRITICAL_SECTION_BEGIN;
    GetFileAttributes(filename);
    CRITICAL_SECTION_END;

    if (GetLastError() == ERROR_INVALID_NAME)

        return 0;

    else

        return 1;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_search_dir                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to search a directory and to invoke        */
/*      the callback function for each found file/directory.             */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      dirname    -   name of the directory to search                   */
/*      flag       -   flag                                              */
/*      callback   -   callback function                                 */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      number of found find/directory                                   */
/*                                                                       */
/*************************************************************************/
static int fssim_search_dir(TCHAR *dirname, DWORD flag, fssim_search_callbak callback, void *param)
{
    WIN32_FIND_DATA data;
    HANDLE hSearch;
    int is_finish, cnt, retval;
    TCHAR strbuf[MAX_PATH], strbuf2[MAX_PATH];
    DWORD error;

    ASSERT(dirname != NULL);

    __try {

        wcscpy(strbuf, dirname);
        wcscpy(strbuf + wcslen(strbuf), L"\\*");

        CRITICAL_SECTION_BEGIN;
        hSearch = FindFirstFile(strbuf, &data);
        CRITICAL_SECTION_END;

        if (hSearch == INVALID_HANDLE_VALUE) {

#ifdef DEBUG_FSSIM

            fssim_printf(("FindFirstFile() failed in fssim_search_dir()\n"));

            fssim_printf(("error code = %d\n", GetLastError()));

#endif  /* DEBUG_FSSIM */

            return 0;
        }

        is_finish = 0;

        cnt = 0;    /* cnt is used to count the number of found file/directory */

        while (is_finish == 0) {

            if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {

                if(wcscmp(data.cFileName, L".") == 0 || wcscmp(data.cFileName, L"..") == 0) {

                    /* nop */

                } else {

                    /* find a directory */

                    if ((flag & FS_DIR_TYPE) != 0) {

                        /* check if filtering out system/hidden attribute */
                        if (((data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM) &&
                             (flag & FS_FILTER_SYSTEM_ATTR))
                           ||
                            ((data.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) &&
                             (flag & FS_FILTER_HIDDEN_ATTR))
                           )
                        {
                           /* do nothing */

                        } else {

                            /* increase the counter */

                            cnt++;
                        }
                    }

                    /* copy the full path of the found directory to strbuf2 */

                    wcscpy(strbuf2, dirname);

                    if( strbuf2[wcslen(strbuf2) - 1] != '\\' )
                        wcscpy(strbuf2 + wcslen(strbuf2), L"\\");

                    wcscpy(strbuf2 + wcslen(strbuf2), data.cFileName);

                    if (callback != NULL) {

                        /* invoke the callback function */

                        retval = callback(strbuf2, data.cFileName, param, FSSIM_BEFORE_RECURSIVE);
                        
                        if (retval != 0) {

                            /* there is an error */

                            /* abort */

                            return retval;
                        }
                    }

                    if ((flag & FS_RECURSIVE_TYPE) != 0) {

                        /* recursive searching */

                        cnt += fssim_search_dir(strbuf2, flag, callback, param);

                    }

                    if (callback != NULL) {

                        /* invoke the callback function */

                        retval = callback(strbuf2, data.cFileName, param, FSSIM_AFTER_RECURSIVE);
                    
                        if (retval != 0) {

                            /* there is an error */

                            /* abort */

                            return retval;
                        }
                    }
                }

            } else {

                /* find a file */

                if ((flag & FS_FILE_TYPE) != 0) {

                    /* check if filtering out system attribute */
                    if (flag & FS_FILTER_SYSTEM_ATTR) {

                        if (!(data.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM))

                            /* increase the counter */

                            cnt++;

                    } else {

                        /* increase the counter */

                        cnt++;
                    }
                }

                if (callback != NULL) {

                    /* copy the full path of the found file to strbuf2 */

                    wcscpy(strbuf2, dirname);

                    if( strbuf2[wcslen(strbuf2) - 1] != '\\' )
                        wcscpy(strbuf2 + wcslen(strbuf2), L"\\");

                    wcscpy(strbuf2 + wcslen(strbuf2), data.cFileName);

                    /* invoke the callback function */

                    retval = callback(strbuf2, data.cFileName, param, FSSIM_BEFORE_RECURSIVE);
                
                    if (retval != 0) {

                        /* there is an error */

                        /* abort */

                        return retval;
                    }
                }

            }

            CRITICAL_SECTION_BEGIN;
            error = FindNextFile(hSearch, &data);
            CRITICAL_SECTION_END;

            if (!error) {

                error = GetLastError();

                if (error == ERROR_NO_MORE_FILES) {

                    /* no more file */

                    is_finish = 1;

                } else {

#ifdef DEBUG_FSSIM

                    fssim_printf(("FindNextFile() failed in fssim_search_dir()\n"));

                    fssim_printf(("error code = %d\n", error));

#endif  /* DEBUG_FSSIM */
                }
            }

        }   /* while () */

    }
    __finally {

        if (!FindClose(hSearch)) {

#ifdef DEBUG_FSSIM

            fssim_printf(("FindClose() failed in fssim_search_dir()\n"));

            fssim_printf(("error code = %d\n", GetLastError()));

            return 0;

#endif  /* DEBUG_FSSIM */
        }
    }

    return cnt;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_copy_dir                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is a callback function of fssim_search_dir and is  */
/*      used to copy found file and found directory                      */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      fullname   -   full name of found file/directory                 */
/*      filename   -   file name of found file/directory                 */
/*      param      -   pointer to FSSIM_COPYDIR_PARAM_T                  */
/*      order      -   FSSIM_BEFORE_RECURSIVE or FSSIM_AFTER_RECURSIVE   */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      zero for success; non-zero for failure                           */
/*                                                                       */
/*************************************************************************/
int fssim_copy_dir(TCHAR *fullname, TCHAR *filename, void *param, int order)
{
    FSSIM_COPYDIR_PARAM_T *copydir;
    DWORD attributes;
    TCHAR srcbuf[MAX_PATH], dstbuf[MAX_PATH], *pch, *pchTmp;

    ASSERT(fullname != NULL && filename != NULL && param != NULL);

    copydir = (FSSIM_COPYDIR_PARAM_T *)param;

    if (fssim_file[copydir->fh].isabort == 1) {

        /* the copy is aborted */

        return FS_ABORTED_ERROR;
    }

    attributes = GetFileAttributes(fullname);

    if (attributes & FILE_ATTRIBUTE_DIRECTORY) {

        /* a directory is found in fssim_search_dir */

        if (order == FSSIM_BEFORE_RECURSIVE) {

            /* create the directory */

            wcscpy(dstbuf, copydir->path);

            wcscpy(dstbuf + wcslen(dstbuf), L"\\");

            wcscpy(dstbuf + wcslen(dstbuf), filename);

            if (!CreateDirectory(dstbuf, NULL)) {

#ifdef DEBUG_FSSIM

                if (GetLastError() != ERROR_ALREADY_EXISTS) {

                    fssim_printf(("CreateDirectory() failed in fssim_copy_dir()\n"));

                    fssim_printf(("error code = %d\n", GetLastError()));
                }

#endif  /* DEBUG_FSSIM */
            }

            /*
             * NoteXXX: fssim_search_dir will recursivelly search directories.
             *          We need to update copydir->path because we will copy file
             *          under the new found direcotry.
             */

            /* append created directory name after copydir->path */

            wcscpy(copydir->path + wcslen(copydir->path), L"\\");

            wcscpy(copydir->path + wcslen(copydir->path), filename);

        } else if (order == FSSIM_AFTER_RECURSIVE) {

            /*
             * NoteXXX: After recursive searching is done,
             *          we need to restore copydir->path.
             */

            /* find the last occurrence of filename in copydir->path */

            pch = wcsstr(copydir->path, filename);

            do {

                pchTmp = pch;

                pch = wcsstr(pch + wcslen(filename), filename);

            } while (pch != NULL);

            pchTmp[-1] = 0;

        } else

            ASSERT(0);

    } else {

        /* a file is found in fssim_search_dir */

        /* copy the found file */

        wcscpy(srcbuf, fullname);

        wcscpy(dstbuf, copydir->path);

        wcscpy(dstbuf + wcslen(dstbuf), L"\\");

        wcscpy(dstbuf + wcslen(dstbuf), filename);

        if (!CopyFileEx(srcbuf, dstbuf, NULL, (LPVOID)copydir->fh, NULL, 0)) {

#ifdef DEBUG_FSSIM

            fssim_printf(("CopyFile() failed in fssim_copy_dir()\n"));

            fssim_printf(("error code = %d\n", GetLastError()));

#endif  /* DEBUG_FSSIM */
        }
        
    }

    if (order == FSSIM_BEFORE_RECURSIVE && fssim_file[copydir->fh].copyprogress != NULL){

        /* increase the complete counter */

        copydir->completed++;

        /* invoke the progress callback function */

        fssim_file[copydir->fh].copyprogress(FS_MOVE_PGS_ING, copydir->total, copydir->completed, copydir->fh);

    }

    return 0;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_del_dir                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is a callback function of fssim_search_dir and is  */
/*      used to delete found file and found directory                    */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      fullname   -   full name of found file/directory                 */
/*      filename   -   file name of found file/directory                 */
/*      param      -   no use                                            */
/*      order      -   FSSIM_BEFORE_RECURSIVE or FSSIM_AFTER_RECURSIVE   */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      zero for success; non-zero for failure                           */
/*                                                                       */
/*************************************************************************/
int fssim_del_dir(TCHAR *fullname, TCHAR *filename, void *param, int order)
{
    DWORD attributes, error;
    FSSIM_FORMAT_PARAM_T *format;

    ASSERT(fullname != NULL && filename != NULL);

    attributes = GetFileAttributes(fullname);

    if (attributes & FILE_ATTRIBUTE_DIRECTORY) {

        /* a directory is found in fssim_search_dir */

        /* delete the directory */

        if (order == FSSIM_AFTER_RECURSIVE) {

            if (!RemoveDirectory(fullname)) {

                error = GetLastError();

                if (error == ERROR_DIR_NOT_EMPTY) {

                    return FS_ACCESS_DENIED;

                } else {

#ifdef DEBUG_FSSIM

                    fssim_printf(("RemoveDirectory() failed in fssim_del_dir()\n"));

                    fssim_printf(("error code = %d\n", GetLastError()));

#endif  /* DEBUG_FSSIM */

                }
            }
        }

    } else {

        /* a file is found in fssim_search_dir */

        /* delete the found file */

        if (!DeleteFile(fullname)) {

#ifdef DEBUG_FSSIM

            fssim_printf(("DeleteFile() failed in fssim_del_dir()\n"));

            fssim_printf(("error code = %d\n", GetLastError()));

#endif  /* DEBUG_FSSIM */

        }
    }

    if (order == FSSIM_BEFORE_RECURSIVE && param != NULL) {

        format = (FSSIM_FORMAT_PARAM_T *)param;

        if (fssim_file[format->fh].formatprogress != NULL){

            /* increase the complete counter */

            format->completed++;

            /* invoke the progress callback function */

            fssim_file[format->fh].formatprogress((const char *)format->drive, format->level, format->total, format->completed);
        }
    }

    return 0;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_del_files                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is a callback function of fssim_search_dir and is  */
/*      used to delete found file only to avoid fail on non-empty dir    */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      fullname   -   full name of found file/directory                 */
/*      filename   -   file name of found file/directory                 */
/*      param      -   no use                                            */
/*      order      -   FSSIM_BEFORE_RECURSIVE or FSSIM_AFTER_RECURSIVE   */
/*                     but ignored                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      zero for success; non-zero for failure                           */
/*                                                                       */
/*************************************************************************/
int fssim_del_files(TCHAR *fullname, TCHAR *filename, void *param, int order)
{
    DWORD attributes;

    ASSERT(fullname != NULL && filename != NULL);

    attributes = GetFileAttributes(fullname);

    if (attributes & FILE_ATTRIBUTE_DIRECTORY) {

    } else {

        /* a file is found in fssim_search_dir */

        /* delete the found file */

        if (!DeleteFile(fullname)) {

#ifdef DEBUG_FSSIM

            fssim_printf(("DeleteFile() failed in fssim_del_dir()\n"));

            fssim_printf(("error code = %d\n", GetLastError()));

#endif  /* DEBUG_FSSIM */

        }
    }

    return 0;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_sum_allocated_clusters                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is a callback function of fssim_search_dir and is  */
/*      used to sum of all allocated clusters                            */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      fullname   -   full name of found file/directory                 */
/*      filename   -   file name of found file/directory                 */
/*      param      -   pointer to FSSIM_SUM_SIZE_PARAM_T                 */
/*      order      -   FSSIM_BEFORE_RECURSIVE or FSSIM_AFTER_RECURSIVE   */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      zero for success; non-zero for failure                           */
/*                                                                       */
/*************************************************************************/
int fssim_sum_allocated_clusters(TCHAR *fullname, TCHAR *filename, void *param, int order)
{
    FSSIM_SUM_SIZE_PARAM_T *this_sum, *sub_folder;
    WIN32_FILE_ATTRIBUTE_DATA file_info;
    int error;

    ASSERT(fullname != NULL && filename != NULL && param != NULL);

    this_sum = (FSSIM_SUM_SIZE_PARAM_T *)param;

    if( GetFileAttributesEx(fullname, GetFileExInfoStandard, &file_info) == 0) {

        error = GetLastError();

#ifdef DEBUG_FSSIM

            fssim_printf(("GetFileAttributesEx() failed in fssim_sum_allocated_clusters()\n"));
            fssim_printf(("error code = %d\n", error));

#endif  /* DEBUG_FSSIM */

        EXT_ASSERT( 0, error, 0, 0);
    }

    /* Dump Info For Debug
    fssim_print_str(filename);
    printf("TYPE: %c , This sum folder %d, alloc %d \n", (file_info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) ? 'D' : 'F',
                    this_sum->directory_entry_cnt, this_sum->allocated_cluster_cnt);
     */

    if (file_info.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {

        /* a directory is found in fssim_search_dir */
        this_sum->directory_entry_cnt += (1 + (wcslen(filename) / 13) + 1);

        if (order == FSSIM_BEFORE_RECURSIVE) {

            /*
             * malloc and push/copy curr sum into new structure,
             * reset directory_entry_cnt, allocated_cluster_cnt
             * link curr_sum next to new structure
             */
            sub_folder = (FSSIM_SUM_SIZE_PARAM_T *) malloc(sizeof(FSSIM_SUM_SIZE_PARAM_T));
            memcpy(sub_folder, this_sum, sizeof(FSSIM_SUM_SIZE_PARAM_T));

            this_sum->directory_entry_cnt = 2;
            this_sum->allocated_cluster_cnt = 0;
            this_sum->next = sub_folder;

        } else if (order == FSSIM_AFTER_RECURSIVE) {

            /*
             * NoteXXX: After recursive searching is done,
             * we pick-up/pop next structure value,
             * sum the cluster_cnt, re-link and cut, then free it.
             */
            sub_folder = this_sum->next;

            this_sum->allocated_cluster_cnt +=
                ((this_sum->directory_entry_cnt * sizeof(FS_DOSDirEntry) - 1) / this_sum->size_of_cluster_unit + 1);

            this_sum->allocated_cluster_cnt += sub_folder->allocated_cluster_cnt;
            this_sum->directory_entry_cnt = sub_folder->directory_entry_cnt;
            this_sum->next = sub_folder->next;

            free(sub_folder);

        } else

            ASSERT(0);

    } else {

        /* a file is found in fssim_search_dir */
        this_sum->directory_entry_cnt += (1 + (wcslen(filename) / 13) + 1);

        ASSERT(file_info.nFileSizeHigh == 0);
        if (file_info.nFileSizeLow > 0)
            this_sum->allocated_cluster_cnt += ((file_info.nFileSizeLow - 1) / this_sum->size_of_cluster_unit + 1);
    }

    return 0;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_conv_attr                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used convert file attributes from RTF to WIN32. */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      attr   -   file attributes to convert                            */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      converted file attribute                                         */
/*                                                                       */
/*************************************************************************/
DWORD fssim_conv_attr(BYTE attr)
{
    DWORD ret_val = 0;

    if (attr & FS_ATTR_READ_ONLY)

        ret_val |= FILE_ATTRIBUTE_READONLY;

    if (attr & FS_ATTR_HIDDEN)

        ret_val |= FILE_ATTRIBUTE_HIDDEN;

    if (attr & FS_ATTR_SYSTEM)

        ret_val |= FILE_ATTRIBUTE_SYSTEM;

    if (attr & FS_ATTR_DIR)

        ret_val |= FILE_ATTRIBUTE_DIRECTORY;

    if (attr & FS_ATTR_ARCHIVE)

        ret_val |= FILE_ATTRIBUTE_ARCHIVE;

    return ret_val;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_rev_conv_attr                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used convert file attributes from WIN32 to RTF. */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      attr   -   file attributes to convert                            */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      converted file attribute                                         */
/*                                                                       */
/*************************************************************************/
BYTE fssim_rev_conv_attr(DWORD attr)
{
    BYTE ret_val = 0;

    if (attr & FILE_ATTRIBUTE_READONLY)

        ret_val |= FS_ATTR_READ_ONLY;

    if (attr & FILE_ATTRIBUTE_HIDDEN)

        ret_val |= FS_ATTR_HIDDEN;

    if (attr & FILE_ATTRIBUTE_SYSTEM)

        ret_val |= FS_ATTR_SYSTEM;

    if (attr & FILE_ATTRIBUTE_DIRECTORY)

        ret_val |= FS_ATTR_DIR;

    if (attr & FILE_ATTRIBUTE_ARCHIVE)

        ret_val |= FS_ATTR_ARCHIVE;

    return ret_val;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_match_pattern                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used check whether a name matches a pattern     */
/*      or not.                                                          */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      pattern   -   pattern to compare                                 */
/*      name      -   name to compare                                    */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      1 for match; 0 for no match                                      */
/*                                                                       */
/*************************************************************************/
static int fssim_match_pattern(const TCHAR *p, const TCHAR *n)
{
    const TCHAR * LastWild = NULL;
    const TCHAR * LastWildN = NULL;
 
    ASSERT(p!= NULL && n!= NULL);

    while (1)
    {
        while ( p[0] && n[0] )
        {
           TCHAR P = towupper(p[0]);
           TCHAR N = towupper(n[0]);
  
           if (P == 0x2a)
           {
              LastWild = p;
              if (towupper(p[1]) == N)
              {
                 LastWildN = n;
                 p++;
                 P = towupper(p[0]);
              }
           }
           if ((P == N) || (P == 0x3F))
              p++, n++;
           else if (P == 0x2A)
              n++;
           else
              break;
        }
        if ( (n[0]==0) && (p[0]==0 || (p[0]==0x2a && p[1]==0)) )
           return 1;
        if (LastWild && LastWildN && LastWildN[1])
        {
           p = LastWild;
           n = ++LastWildN;
        }
        else
           return 0;
    }
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_search_drive                                               */
/*      fssim_locate_drive                                               */
/*      fssim_get_default_drive                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      Those 3 functions are used to process drive letter search,       */
/*      accept UINT, path string, and the last choose to get default.    */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      patchname  -   the path wide character string                    */
/*      drvIdx     -   the drive letter located                          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      index of fssim_drvinfo, if < 0 , not found                       */
/*                                                                       */
/*************************************************************************/

static int fssim_search_drive(UINT drvIdx)
{
    int i;

    for (i = 0; i < FSSIM_MAX_DRIVE; i++) {

        if (fssim_drvinfo[i].drive == drvIdx || fssim_drvinfo[i].remap_drive == drvIdx) {

            break;
        }
    }

    return i;
}

static int fssim_get_default_drive(void)
{
    int i;

    for (i = 0; i < FSSIM_MAX_DRIVE; i++) {

        if (fssim_drvinfo[i].is_current == 1) {

            return i;
        }
    }

    EXT_ASSERT( 0, 0, 0, 0);

    return (-1);
}

static int fssim_locate_drive(const TCHAR *pathname)
{
    TCHAR strbuf[8];
    UINT  drv;

    wcsncpy(strbuf, pathname, wcslen(L"?:\\"));
    
    *(strbuf + wcslen(L"?:\\")) = 0;
    
    if (fssim_match_pattern(L"?:\\", strbuf) == 0) {

        return (-1);
    }

    drv = (iswlower(strbuf[0])) ? (strbuf[0] - 0x20) : strbuf[0];

    return fssim_search_drive(drv);
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_update_direntry_datetime                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to partial update datetime structure.      */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      fh         -   file handle of the file                           */
/*      direntry   -   pointer to a FS_DOSDirEntry                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
static void fssim_update_direntry_datetime(int fh, FS_DOSDirEntry *direntry)
{
    FILETIME create_ft, write_ft;
    SYSTEMTIME create_st, write_st;

    /* get file time */

    GetFileTime(fssim_file[fh].handle, &create_ft, NULL, &write_ft);

    FileTimeToSystemTime(&create_ft, &create_st);

    FileTimeToSystemTime(&write_ft, &write_st);

    /*
     * Set DirEntry.
     */

    // XXX Debug use
    // printf("creat time DWHIGH = %X , DWLOW = %X\n", create_ft.dwLowDateTime, create_ft.dwHighDateTime);

    direntry->CreateDateTime.Day = create_st.wDay;

    direntry->CreateDateTime.Hour = create_st.wHour;

    direntry->CreateDateTime.Minute = create_st.wMinute;

    direntry->CreateDateTime.Month = create_st.wMonth;

    direntry->CreateDateTime.Second2 = create_st.wSecond / 2;

    direntry->CreateDateTime.Year1980 = create_st.wYear - 1980;

    direntry->DateTime.Day = write_st.wDay;

    direntry->DateTime.Hour = write_st.wHour;

    direntry->DateTime.Minute = write_st.wMinute;

    direntry->DateTime.Month = write_st.wMonth;

    direntry->DateTime.Second2 = write_st.wSecond / 2;

    direntry->DateTime.Year1980 = write_st.wYear - 1980;

    return;
}
/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_convert_win32_find_filename_to_dosfilename                 */
/*      fssim_conv_direntry_from_win32_find                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to set a FS_DOSDirEntry structure from     */
/*      Win32 FIND DATA structure                                        */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      infoptr    -   pointer to a FS_DOSDirEntry                       */
/*      dataptr    -   pointer to a WIN32_FIND_DATA                      */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
static void
fssim_convert_win32_find_filename_to_dosfilename(char *majornameptr, char *extensionptr, TCHAR *filename)
{
    mmi_chset_enum phone_enc;
    char  output_buffer[10];
    TCHAR input_buffer[10];
    int   i;
    TCHAR *extptr;

    phone_enc = PhnsetGetDefEncodingType();

    /* process the major name part ; 8 TCHAR convert to 8 char */
    memset(majornameptr, ' ', sizeof(char) * 8);

    memset( input_buffer, 0, sizeof(TCHAR) * 9);
    wcsncpy( input_buffer, filename, 8);

    extptr = wcsstr(input_buffer, L".");
    if (extptr != NULL)
    {   
        /* find dot , segment the name by NULL termined it */
        *extptr = '\0';
    }
    
    i = mmi_chset_convert(MMI_CHSET_UCS2, phone_enc, (char*)input_buffer, (char*)output_buffer, 10);
    if (i > 0) strncpy(majornameptr, output_buffer, i - 2); /* the null terminated occupied 2 char */

    /* process the extension name part ; 3 TCHAR convert to 3 char */
    memset(extensionptr, ' ', sizeof(char) * 3);

    extptr = wcsstr(filename, L".");
    if (extptr == NULL)
    {
        /* No extension name , finished and done */
        return;
    }

    memset( input_buffer, 0, sizeof(TCHAR) * 4);
    wcsncpy( input_buffer, extptr + 1, 3);

    i = mmi_chset_convert(MMI_CHSET_UCS2, phone_enc, (char*)input_buffer, (char*)output_buffer, 5);
    if (i > 0) strncpy(extensionptr, output_buffer, i - 2); /* the null terminated occupied 2 char */
}

static void fssim_conv_direntry_from_win32_find(FS_DOSDirEntry *infoptr, WIN32_FIND_DATA *dataptr)
{   SYSTEMTIME createtime, writetime;
    TCHAR *pch;

    /* get creation time */

    FileTimeToSystemTime(&(dataptr->ftCreationTime), &createtime);

    /* get last write time */

    FileTimeToSystemTime(&(dataptr->ftLastWriteTime), &writetime);

    /* set infoptr structure */

    pch = dataptr->cAlternateFileName;

    if (*pch == 0) {

        /* data.cFileName is not a LFN */

        pch = dataptr->cFileName;
    }
    
    fssim_convert_win32_find_filename_to_dosfilename( (char*) &(infoptr->FileName), (char*) &(infoptr->Extension), pch);

    infoptr->Attributes = fssim_rev_conv_attr(dataptr->dwFileAttributes);

    infoptr->CreateTimeTenthSecond = 0;

    infoptr->CreateDateTime.Day = createtime.wDay;

    infoptr->CreateDateTime.Hour = createtime.wHour;

    infoptr->CreateDateTime.Minute = createtime.wMinute;

    infoptr->CreateDateTime.Month = createtime.wMonth;

    infoptr->CreateDateTime.Second2 = createtime.wSecond;

    infoptr->CreateDateTime.Year1980 = createtime.wYear - 1980;

    infoptr->LastAccessDate = 0;

    infoptr->FirstClusterHi = 0;

    infoptr->DateTime.Day = writetime.wDay;

    infoptr->DateTime.Hour = writetime.wHour;

    infoptr->DateTime.Minute = writetime.wMinute;

    infoptr->DateTime.Month = writetime.wMonth;

    infoptr->DateTime.Second2 = writetime.wSecond;

    infoptr->DateTime.Year1980 = writetime.wYear - 1980;

    infoptr->FirstCluster = 0;

    infoptr->FileSize = dataptr->nFileSizeLow;

    if (dataptr->nFileSizeHigh != 0) {

        fssim_printf(("file size is too large to set the value in FileInfo->FileSize\n"));
    }

    return;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_copy_and_convert_filename                                  */
/*      fssim_copy_filename_from_win32_find                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to copy file name to string buffer with    */
/*      MaxLength limiation, the source is a Win32 Find Data             */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      strptr     -   file name string buffer pointer                   */
/*      dataptr    -   pointer to a WIN32_FIND_DATA                      */
/*      MaxLength  -   the string buffer content                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      { FS_NOT_MATCH, FS_LFN_MATCH, FS_SFN_MATCH } enum                */
/*                                                                       */
/*************************************************************************/
static void
fssim_copy_and_convert_filename(WCHAR *destptr, WCHAR *srcptr, UINT MaxLength)
{
    /* convert filename to phone default encoding character by character */
    mmi_chset_enum phone_enc;
    unsigned int length;
    kal_uint8 src_buff[4];
    kal_uint8 dest_buff[4];

    memset(src_buff,  0, 4);
    memset(dest_buff, 0, 4);
    phone_enc = PhnsetGetDefEncodingType();

    for ( length=0 ; *srcptr; srcptr++, destptr++, length ++ )
    {
        src_buff[0] = (kal_uint8) ((*srcptr) & 0xFF);
        src_buff[1] = (kal_uint8) ((*srcptr) >> 8);

        if (mmi_chset_convert(MMI_CHSET_UCS2, phone_enc, (char*)src_buff, (char*)dest_buff, 4))
        {
            *destptr = (WCHAR)((dest_buff[1] << 8 | dest_buff[0]));
        }
        else
        {
            *destptr = (WCHAR)0xA440;
        }

        ASSERT(MaxLength > length);
    }

    *destptr = '\0';
}

static FS_FIND_ENUM 
fssim_copy_filename_from_win32_find(WCHAR *strptr, WIN32_FIND_DATA *dataptr, UINT MaxLength)
{
    unsigned int NameLength;

    EXT_ASSERT(MaxLength > 0, 0, 0, 0);

    NameLength = wcslen(dataptr->cFileName); /* NOTE: not include \0 tail */

    if (NameLength < MaxLength) {

        if (*(dataptr->cAlternateFileName) != 0) {
            /* Win32 Find Long File Name and Buffer enough */

            wcscpy(strptr, dataptr->cFileName);

            /* the file name is LFN */
            return FS_LFN_MATCH;

        } else {
            /* Win32 Find Short File Name and Buffer enough */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            /* Return LFN_MATCH due to unicode encoding */
            wcscpy(strptr, dataptr->cFileName);
            return FS_LFN_MATCH;
        }

    } else if (*(dataptr->cAlternateFileName) == 0) {
       /* cFileName is SFN , but length not enough */

        wcsncpy(strptr, dataptr->cFileName, MaxLength - 1);
        strptr[MaxLength - 1] = '\0';

        return FS_NOT_MATCH;
    }
        /* Win32 Find Long File Name but Buffer not enough */

    NameLength = wcslen(dataptr->cAlternateFileName);

    if (NameLength < MaxLength)
    {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        wcscpy(strptr, dataptr->cAlternateFileName);
        return FS_LFN_MATCH;
    }

        /* the last case, length not enough even it's SFN */
    return FS_NOT_MATCH;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_copy_dosfilename_from_dosdirentry                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to copy 8.3 dosfilename to string buffer.  */
/*      The source is a DosDirEntry Structure                            */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      filename   -   file name string buffer pointer                   */
/*      dataptr    -   pointer to a FS_DOSDirEntry structure             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
void
fssim_copy_dosfilename_from_dosdirentry(WCHAR *FileName, FS_DOSDirEntry *dataptr)
{
    int  i, j;
    char SFN_buffer[8 + 1 + 3 + 2]; 

    /* 1st step : re-construct the short file name into SFN_buffer */
    /* <1-a> copy the major file name part */
    for (i = 0; i < 8; i++) {

        if (dataptr->FileName[i] != ' ')

            SFN_buffer[i] = dataptr->FileName[i];

        else

            break;
    }
    /* <1-b> count length of extenstion first */
    for (j = 2; j >= 0; j--) if (dataptr->Extension[j] != ' ') break;

    /* <1-c> set '.' */
    if (j > -1) {

        SFN_buffer[i] = '.';

        i++;
    }

    /* <1-d> copy the extension name part */
    for (j = 0; j < 3; j++) {

        if (dataptr->Extension[j] != ' ')

            SFN_buffer[i + j] = dataptr->Extension[j];

        else

            break;
    }
    SFN_buffer[i + j] = '\0';

    /* 2. Convert SFN_Buffer to UCS2 encoding */
    mmi_chset_convert( PhnsetGetDefEncodingType(),
                       MMI_CHSET_UCS2,
                       SFN_buffer,
                       (char*)FileName,
                       sizeof(TCHAR) * ( 8 + 1 + 3 + 1)
                     );
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_set_direntry                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to set a FS_DOSDirEntry data structure.    */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      fh         -   file handle of the file                           */
/*      filename   -   file name of the file                             */
/*      direntry   -   pointer to a FS_DOSDirEntry                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
static void fssim_set_direntry(int fh, TCHAR *filename, FS_DOSDirEntry *direntry)
{
    TCHAR shortname[FSSIM_SFN_LEN], *pch;
    int i, cnt;

    /*
     * Set DirEntry.
     */

    memset(direntry, 0, sizeof(FS_DOSDirEntry));

    CRITICAL_SECTION_BEGIN;
    direntry->Attributes = fssim_rev_conv_attr(GetFileAttributes(filename));
    CRITICAL_SECTION_END;

    fssim_update_direntry_datetime(fh, direntry);

    CRITICAL_SECTION_BEGIN;
    direntry->FileSize = GetFileSize(fssim_file[fh].handle, NULL);
    CRITICAL_SECTION_END;

    /* get short file name */

    cnt = fssim_get_short_name(filename, shortname, FSSIM_SFN_LEN);

#if 0
	//Huyanwei Del It
    ASSERT(cnt > 0);
#endif

    memset(direntry->FileName, ' ', sizeof(char) * 8);

    memset(direntry->Extension, ' ', sizeof(char) * 3);

    i = 0;

    pch = shortname;

    while (*pch != 0) {

        if (!wcsncmp(pch, L".", wcslen(L".")) || i == 8)

            break;

        else

            direntry->FileName[i] = *((char *)pch);

        i++;

        pch++;
    }

    i = 0;

    pch = wcsstr(pch, L".");

    if (pch != NULL) {

        /* bypass "." */

        pch++;

        while (*pch != 0) {

            if (i >= 3)

                break;

            direntry->Extension[i] = *((char *)pch);

            i++;

            pch++;
        }
    }

    ASSERT(i <= 4);
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_comp_none                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used compare two FSSIM_SORT_T data structure.   */
/*      The compare polity is that a directory is always less than       */
/*      a file.                                                          */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      arg1   -   pointer to a FSSIM_SORT_T                             */
/*      arg2   -   pointer to a FSSIM_SORT_T                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      < 0 if arg1 less than arg2                                       */
/*      0 if arg1 equivalent to arg2                                     */
/*      > 0 if arg1 greater than arg2                                    */
/*                                                                       */
/*************************************************************************/
int fssim_comp_none(const void *arg1, const void *arg2)
{
    FSSIM_SORT_T *elem1, *elem2;

    ASSERT(arg1 != NULL && arg2 != NULL);

    elem1 = (FSSIM_SORT_T *)arg1;

    elem2 = (FSSIM_SORT_T *)arg2;

    if ((elem1->fileinfo.Attributes & FS_ATTR_DIR) && !(elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a directory and elem2 presents a file */

        return -1;

    else if (!(elem1->fileinfo.Attributes & FS_ATTR_DIR) && (elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a file and elem2 presents a direcotry */

        return 1;

    else

        return 0;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_comp_name                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used compare file name of two FSSIM_SORT_T      */
/*      data structure.                                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      arg1   -   pointer to a FSSIM_SORT_T                             */
/*      arg2   -   pointer to a FSSIM_SORT_T                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      < 0 if arg1 less than arg2                                       */
/*      0 if arg1 equivalent to arg2                                     */
/*      > 0 if arg1 greater than arg2                                    */
/*                                                                       */
/*************************************************************************/
int fssim_comp_name(const void *arg1, const void *arg2)
{
    FSSIM_SORT_T *elem1, *elem2;

    ASSERT(arg1 != NULL && arg2 != NULL);

    elem1 = (FSSIM_SORT_T *)arg1;

    elem2 = (FSSIM_SORT_T *)arg2;

    if ((elem1->fileinfo.Attributes & FS_ATTR_DIR) && !(elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a directory and elem2 presents a file */

        return -1;

    else if (!(elem1->fileinfo.Attributes & FS_ATTR_DIR) && (elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a file and elem2 presents a direcotry */

        return 1;

    else

        return wcsicmp(elem1->filename, elem2->filename);
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_comp_type                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used compare file type of two FSSIM_SORT_T      */
/*      data structure.                                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      arg1   -   pointer to a FSSIM_SORT_T                             */
/*      arg2   -   pointer to a FSSIM_SORT_T                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      < 0 if arg1 less than arg2                                       */
/*      0 if arg1 equivalent to arg2                                     */
/*      > 0 if arg1 greater than arg2                                    */
/*                                                                       */
/*************************************************************************/
int fssim_comp_type(const void *arg1, const void *arg2)
{
    FSSIM_SORT_T *elem1, *elem2;
    TCHAR *pch1, *pch2, *pchOld;

    ASSERT(arg1 != NULL && arg2 != NULL);

    elem1 = (FSSIM_SORT_T *)arg1;

    elem2 = (FSSIM_SORT_T *)arg2;

    if ((elem1->fileinfo.Attributes & FS_ATTR_DIR) && !(elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a directory and elem2 presents a file */

        return -1;

    else if (!(elem1->fileinfo.Attributes & FS_ATTR_DIR) && (elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a file and elem2 presents a direcotry */

        return 1;

    else {

        /* extract file extension */

        pch1 = wcsstr(elem1->filename, L".");

        pchOld = pch1;

        while (pch1 != NULL) {

            pchOld = pch1;

            pch1 = wcsstr(pch1 + 1, L".");
        }

        pch1 = (pchOld == NULL)? NULL: pchOld + 1;

        pch2 = wcsstr(elem2->filename, L".");

        pchOld = pch2;

        while (pch2 != NULL) {

            pchOld = pch2;

            pch2 = wcsstr(pch2 + 1, L".");
        }

        pch2 = (pchOld == NULL)? NULL: pchOld + 1;

        if (pch1 != NULL && pch2 == NULL)

            /* file in elem2 doesn't have a file extension */

            return 1;

        else if (pch1 == NULL && pch2 != NULL)

            /* file in elem1 doesn't have a file extenstion */

            return -1;

        else if (pch1 == NULL && pch2 == NULL)

            /* both files doesn't have a file extenstion */

            return wcsicmp(elem1->filename, elem2->filename);

        else if (!wcsicmp(pch1, pch2))

            /* both extension are equal */

            return wcsicmp(elem1->filename, elem2->filename);

        else

            return wcsicmp(pch1, pch2);
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_comp_attr                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used compare attribute of two FSSIM_SORT_T      */
/*      data structure.                                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      arg1   -   pointer to a FSSIM_SORT_T                             */
/*      arg2   -   pointer to a FSSIM_SORT_T                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      < 0 if arg1 less than arg2                                       */
/*      0 if arg1 equivalent to arg2                                     */
/*      > 0 if arg1 greater than arg2                                    */
/*                                                                       */
/*************************************************************************/
int fssim_comp_attr(const void *arg1, const void *arg2)
{
    FSSIM_SORT_T *elem1, *elem2;

    ASSERT(arg1 != NULL && arg2 != NULL);

    elem1 = (FSSIM_SORT_T *)arg1;

    elem2 = (FSSIM_SORT_T *)arg2;

    if ((elem1->fileinfo.Attributes & FS_ATTR_DIR) && !(elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a directory and elem2 presents a file */

        return -1;

    else if (!(elem1->fileinfo.Attributes & FS_ATTR_DIR) && (elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a file and elem2 presents a direcotry */

        return 1;

    else

        return (elem1->fileinfo.Attributes - elem2->fileinfo.Attributes);
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_comp_size                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used compare file size of two FSSIM_SORT_T      */
/*      data structure.                                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      arg1   -   pointer to a FSSIM_SORT_T                             */
/*      arg2   -   pointer to a FSSIM_SORT_T                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      < 0 if arg1 less than arg2                                       */
/*      0 if arg1 equivalent to arg2                                     */
/*      > 0 if arg1 greater than arg2                                    */
/*                                                                       */
/*************************************************************************/
int fssim_comp_size(const void *arg1, const void *arg2)
{
    FSSIM_SORT_T *elem1, *elem2;

    ASSERT(arg1 != NULL && arg2 != NULL);

    elem1 = (FSSIM_SORT_T *)arg1;

    elem2 = (FSSIM_SORT_T *)arg2;

    if ((elem1->fileinfo.Attributes & FS_ATTR_DIR) && !(elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a directory and elem2 presents a file */

        return -1;

    else if (!(elem1->fileinfo.Attributes & FS_ATTR_DIR) && (elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a file and elem2 presents a direcotry */

        return 1;

    else

        return (elem1->fileinfo.FileSize - elem2->fileinfo.FileSize);
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_comp_time                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used compare file time of two FSSIM_SORT_T      */
/*      data structure.                                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      arg1   -   pointer to a FSSIM_SORT_T                             */
/*      arg2   -   pointer to a FSSIM_SORT_T                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      < 0 if arg1 less than arg2                                       */
/*      0 if arg1 equivalent to arg2                                     */
/*      > 0 if arg1 greater than arg2                                    */
/*                                                                       */
/*************************************************************************/
int fssim_comp_time(const void *arg1, const void *arg2)
{
    FSSIM_SORT_T *elem1, *elem2;
    int result;

    ASSERT(arg1 != NULL && arg2 != NULL);

    elem1 = (FSSIM_SORT_T *)arg1;

    elem2 = (FSSIM_SORT_T *)arg2;

    if ((elem1->fileinfo.Attributes & FS_ATTR_DIR) && !(elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a directory and elem2 presents a file */

        return -1;

    else if (!(elem1->fileinfo.Attributes & FS_ATTR_DIR) && (elem2->fileinfo.Attributes & FS_ATTR_DIR))

        /* elem1 presents a file and elem2 presents a direcotry */

        return 1;

    else {
		#ifdef __MMI_LVM__ //把最近的放到前面,与传统的相反
		extern unsigned char LVM_InRecordList(void);
		FSSIM_SORT_T *elem3 = 0;
		if (LVM_InRecordList()) {
			elem3 = elem1;
			elem1 = elem2;
			elem2 = elem3;
		}
		#endif
        /* compare year */

        result = elem1->fileinfo.DateTime.Year1980 - elem2->fileinfo.DateTime.Year1980;

        if (result != 0)

            return result;

        /* compare month */

        result = elem1->fileinfo.DateTime.Month - elem2->fileinfo.DateTime.Month;

        if (result != 0)

            return result;

        /* compre day */

        result = elem1->fileinfo.DateTime.Day - elem2->fileinfo.DateTime.Day;

        if (result != 0)

            return result;

        /* compare hour */

        result = elem1->fileinfo.DateTime.Hour - elem2->fileinfo.DateTime.Hour;

        if (result != 0)

            return result;

        /* compre minute */

        result = elem1->fileinfo.DateTime.Minute - elem2->fileinfo.DateTime.Minute;

        if (result != 0)

            return result;

        /* compare second */

        result = elem1->fileinfo.DateTime.Second2 - elem2->fileinfo.DateTime.Second2;

        return result;
    }
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_cleanup_generated_vfn                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to cleanup generated and registered        */
/*      virtual file name                                                */
/*      Must inside the critical section!                                */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHanle -  the file hanlde that gererate vfn                   */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
static void fssim_cleanup_generated_vfn(FS_HANDLE File)
{
    unsigned int i;

    for ( i = 0; i < fssim_vfgen.usage_size; ) {

        if (fssim_vfgen.data[i].vf_gen_fh_unique == fssim_file[File].unique) {

            fssim_vfgen.usage_size--;

            if (i != fssim_vfgen.usage_size) {

                memcpy( fssim_vfgen.data + i,
                        fssim_vfgen.data + fssim_vfgen.usage_size, sizeof(FSSIM_VIRTUAL_FILENAME_T) );

                memset( fssim_vfgen.data + fssim_vfgen.usage_size, 0, sizeof(FSSIM_VIRTUAL_FILENAME_T) );
            }

        } else {

            i++;
        }
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_close_fh                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to free a new file handle.                 */
/*      Must inside the critical section!                                */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      fh  -  file handle                                               */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
static void fssim_close_fh(const int fh)
{
    BOOL         retval;
    unsigned int map_fh;

    ASSERT(fssim_file[fh].handle != INVALID_HANDLE_VALUE);

    retval = CloseHandle(fssim_file[fh].handle);

    if (!retval) /* CloseHandle Failure */
    {
        DWORD    error;
        error = GetLastError();

        fssim_printf(("CloseHandle() failed in fssim_close_fh(), fh = %d\n", fh));
        fssim_printf(("error code = %d\n", error));

        ASSERT(0);
    }

    fssim_file[fh].handle= INVALID_HANDLE_VALUE;

    for ( map_fh = 1; map_fh <= FSSIM_MAX_FILE; map_fh++) {

        ASSERT( fssim_vfgen.link[map_fh] != fh ); /* XXX Prevent Virtual File Life-Cycle violate */
    }

    fssim_cleanup_generated_vfn(fh);
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_init_drive_quota                                           */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to init the gFS_IntQuotaSet                */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                   gFS_IntQuotaSet Qmax, Qmin, Qnow                    */
/*                                                                       */
/*************************************************************************/
static void fssim_init_drive_quota(void)
{   int i, j, k;
    int system_drive_idx, clustersize;
    int MRS;
    WCHAR strbuf[FS_MAX_PATH], quota_path[FS_MAX_PATH];
    FSSIM_SUM_SIZE_PARAM_T top_folder;

    system_drive_idx = fssim_search_drive((UINT)FSSIM_SYSTEM_DRIVE);
    clustersize = fssim_drvinfo[system_drive_idx].bytespersector * fssim_drvinfo[system_drive_idx].sectorspercluser;

    for (MRS = 0, i = FS_MAX_QSET - 1; i >= 0; i--) {
        /* Check table setting */
        ASSERT(gFS_ExtQuotaSet[i].Path[1] == 0x3A);   //':'
        ASSERT(gFS_ExtQuotaSet[i].Path[2] == 0x5C);   //'\'
        ASSERT(gFS_ExtQuotaSet[i].Path[3] == 0x40);   //'@'

        k = strlen((char *)gFS_ExtQuotaSet[i].Path) - 1;
        ASSERT(gFS_ExtQuotaSet[i].Path[k] == 0x5C);   //'\'     
        for (j = 4; j < k; j++)
            ASSERT(gFS_ExtQuotaSet[i].Path[j] != 0x5C);//not support multi-level folder

        ASSERT(gFS_ExtQuotaSet[i].Priority <= FS_QP_DEL_ENUM);
        ASSERT(gFS_ExtQuotaSet[i].Qmax != 0);
        ASSERT(gFS_ExtQuotaSet[i].Qmin <= gFS_ExtQuotaSet[i].Qmax);
        ASSERT(gFS_ExtQuotaSet[i].Qmin >  0);
        ASSERT((gFS_ExtQuotaSet[i].Uint == FS_COUNT_IN_BYTE) || (gFS_ExtQuotaSet[i].Uint == FS_COUNT_IN_CLUSTER));

        /* Check system drive match */
        j = fssim_search_drive((UINT)gFS_ExtQuotaSet[i].Path[0]);

        if (j != system_drive_idx) {

            continue;
        }

        /* Int Quota Set Qmax */
        if (gFS_ExtQuotaSet[i].Qmax == FS_QMAX_NO_LIMIT) {

            gFS_IntQuotaSet[i].Qmax = 0;

        } else if (gFS_ExtQuotaSet[i].Uint == FS_COUNT_IN_BYTE) {

            gFS_IntQuotaSet[i].Qmax = (gFS_ExtQuotaSet[i].Qmax - 1) / clustersize + 1;

        } else /* gFS_ExtQuotaSet[i].Uint == FS_COUNT_IN_CLUSTER */ {

            gFS_IntQuotaSet[i].Qmax = gFS_ExtQuotaSet[i].Qmax;
        }

        ASSERT(gFS_IntQuotaSet[i].Qmax < fssim_drvinfo[system_drive_idx].totalclusters);

        /* Int Quota Set Qmin */
        if (gFS_ExtQuotaSet[i].Uint == FS_COUNT_IN_BYTE) {

            gFS_IntQuotaSet[i].Qmin = (gFS_ExtQuotaSet[i].Qmin - 1) / clustersize + 1;

        } else /* gFS_ExtQuotaSet[i].Uint == FS_COUNT_IN_CLUSTER */ {

            gFS_IntQuotaSet[i].Qmin = gFS_ExtQuotaSet[i].Qmin;
        }
        MRS += gFS_IntQuotaSet[i].Qmin;

        /* Int Quota Set Qnow -- convert path to wide char */
        quota_path[0] = (WCHAR) FSSIM_SYSTEM_DRIVE;
        for (j = 1; j <= k; j++) {
            quota_path[j] = (WCHAR) gFS_ExtQuotaSet[i].Path[j];
        }
        quota_path[j] = 0;

        /* Int Quota Set Qnow -- map to simulator's path   */
        fssim_conv_fn(strbuf, quota_path);
        if (!fssim_is_file_exist(strbuf)) /* the folder doesn't exist */ {

            gFS_IntQuotaSet[i].Qnow = 0;
            continue;
        }

        /* Int Quota Set Qnow -- initialize the structure  */
        top_folder.directory_entry_cnt = 2;
        top_folder.allocated_cluster_cnt = 0;
        top_folder.size_of_cluster_unit = clustersize;

        /* Int Quota Set Qnow -- issue the recursive loop  */
        fssim_search_dir(strbuf, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
                         fssim_sum_allocated_clusters, (void*) &top_folder);

        top_folder.allocated_cluster_cnt +=
                    ((top_folder.directory_entry_cnt * sizeof(FS_DOSDirEntry) - 1) / top_folder.size_of_cluster_unit + 1);

        /* Int Quota Set Qnow -- now we got the Qnow , YA! */
        gFS_IntQuotaSet[i].Qnow = top_folder.allocated_cluster_cnt;
    }

    if (fssim_drvinfo[system_drive_idx].totalclusters < (UINT) MRS) {
        printf("WARNING!!! minal reserved space for quota mgt (%d) > system drive configured space (%d)\n",
                MRS, fssim_drvinfo[system_drive_idx].totalclusters);
    }

    ASSERT(MRS < fssim_drvinfo[system_drive_idx].totalclusters);
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_update_quota_set                                           */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function update the run-time quota structure value          */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileName    -  the updating FileName                             */
/*      clusterdiff -  (pos) allocate more, (negative) free cluster      */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Bool           quota premit (True) or forbidden (False)          */
/*                                                                       */
/*************************************************************************/
static int fssim_update_quota_set(const WCHAR *FullPath, int clusterdiff)
{   int i, j, k;
    int quota_entry_hit, system_drive_idx;
    int RFS_for_Other, FreeClusterCount;

    /* filter out non-system-drive */
    if (FullPath[0] != (WCHAR) FSSIM_SYSTEM_DRIVE && FullPath[0] != (WCHAR) FSSIM_REMAP_SYSTEM_DRIVE) {
        return 1;
    }

    /* Dump Debug Info */
    /* fssim_print_str(FullPath);
     * printf("cluster change %d\n", clusterdiff);
     */

    /* first round, search path hit */
    for (RFS_for_Other = 0, quota_entry_hit = -1, i = FS_MAX_QSET - 1; i >= 0; i--) {

        /* compare the FullPath */
        k = strlen((char *)gFS_ExtQuotaSet[i].Path);
        
        for (j = 1; (j < k) && (FullPath[j] == (WCHAR)gFS_ExtQuotaSet[i].Path[j]) ; j++) {}

        if (j == k) /* compare success ! */ {
            quota_entry_hit = i;
        }

        /* sum the RFS_for_Other */
        if(gFS_IntQuotaSet[i].Qmin > gFS_IntQuotaSet[i].Qnow)
            RFS_for_Other += (gFS_IntQuotaSet[i].Qmin - gFS_IntQuotaSet[i].Qnow);
    }

    /* second run, see if special NVRAM ? */
    if (quota_entry_hit == -1 && wcsncmp(FullPath, fssim_nvram_path, wcslen(fssim_nvram_path)) != 0) {
        /* ALL MISS, BYE! */
        return 1;
    }

    /* Thrid run, Now we check quota usage */
    system_drive_idx = fssim_search_drive((UINT)FSSIM_SYSTEM_DRIVE);
    FreeClusterCount = (fssim_drvinfo[system_drive_idx].totalclusters > fssim_drvinfo[system_drive_idx].takenclusters) ?
            fssim_drvinfo[system_drive_idx].totalclusters - fssim_drvinfo[system_drive_idx].takenclusters : 0;

    if (quota_entry_hit == -1) /* NVRAM case, no need to update Qnow */ {

        if (RFS_for_Other > FreeClusterCount - clusterdiff) {
            /* sorry, there's no room for NVRAM */
            return 0;
        }
        return 1;
    }

    if (gFS_IntQuotaSet[quota_entry_hit].Qmax &&
       (gFS_IntQuotaSet[quota_entry_hit].Qmax < gFS_IntQuotaSet[quota_entry_hit].Qnow + clusterdiff) ) {

        return 0;
    }

    if (gFS_IntQuotaSet[quota_entry_hit].Qmin > gFS_IntQuotaSet[quota_entry_hit].Qnow)
        /* discount the RFS_for_Other contribution by quota_entry_hit */
        RFS_for_Other -= (gFS_IntQuotaSet[quota_entry_hit].Qmin - gFS_IntQuotaSet[quota_entry_hit].Qnow);

    if (RFS_for_Other > FreeClusterCount - clusterdiff) {
        /* sorry, you must stop writing and resere room for other application */
        return 0;
    }

    j = (FreeClusterCount > RFS_for_Other) ? FreeClusterCount - RFS_for_Other : 0;

    if (gFS_IntQuotaSet[quota_entry_hit].Qmax && j < clusterdiff) {
        /* sorry, you must stop writing and resere room for other application */
        return 0;
    }

    /* Forth run, Now we update internal Qnow */
    gFS_IntQuotaSet[quota_entry_hit].Qnow += clusterdiff;
    return 1;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_get_drive_watermark                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to calculate the allocated clusters        */
/*      in given drive                                                   */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      drive_ptr -  the fssim_drvinfo structure pointer                 */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                   fssim_drvinfo structure's takenclusters             */
/*                                                                       */
/*************************************************************************/
static void fssim_get_drive_watermark(FSSIM_DRVINFO_T *drive_ptr)
{
    TCHAR strbuf[MAX_PATH], root[] = L"X:\\";
    FSSIM_SUM_SIZE_PARAM_T top_folder;

    root[0] = drive_ptr->drive;
    fssim_conv_fn(strbuf, root);

    /* initialize the structure */
    top_folder.directory_entry_cnt = 2;
    top_folder.allocated_cluster_cnt = 0;
    top_folder.size_of_cluster_unit = drive_ptr->bytespersector * drive_ptr->sectorspercluser;

    /* issue the recursive loop */
    fssim_search_dir(strbuf, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
                     fssim_sum_allocated_clusters, (void*) &top_folder);

    top_folder.allocated_cluster_cnt +=
                ((top_folder.directory_entry_cnt * sizeof(FS_DOSDirEntry) - 1) / top_folder.size_of_cluster_unit + 1);

    drive_ptr->takenclusters = top_folder.allocated_cluster_cnt;
    /*
     *  printf("%c 's takenclusters = %d\n", drive_ptr->drive, drive_ptr->takenclusters);
     */

    /*
     * Check If require to initalize gFS_IntQuotaSet
     */
    if (drive_ptr->drive == FSSIM_SYSTEM_DRIVE) {

        fssim_init_drive_quota();
    }
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_update_watermark_by_fh                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to update the allocated clusters by given  */
/*      file handle, Stop out-of-disk-space operation if over.           */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      drive_ptr -  the fssim_drvinfo structure pointer                 */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*      FS_DISK_FULL                                                     */
/*                                                                       */
/*************************************************************************/
static int fssim_update_watermark_by_fh(FSSIM_FILE_T *file_ptr, int offset)
{   FSSIM_DRVINFO_T *drive_ptr;
    int valid_size;
    UINT before_cluster_cnt;
    UINT update_cluster_cnt;

    fssim_take_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex BEGIN */

    drive_ptr = &(fssim_drvinfo[file_ptr->drive]);

    if (drive_ptr->takenclusters == 0) {

        fssim_get_drive_watermark(drive_ptr);
    }

    valid_size = file_ptr->DirEntry.FileSize;
    before_cluster_cnt = (valid_size > 0) ?
        ((valid_size - 1)/(drive_ptr->bytespersector * drive_ptr->sectorspercluser) + 1) : 0;

    valid_size += offset;
    update_cluster_cnt = (valid_size > 0) ?
        ((valid_size - 1)/(drive_ptr->bytespersector * drive_ptr->sectorspercluser) + 1) : 0;

    if (update_cluster_cnt == before_cluster_cnt) {

        fssim_give_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex END   */
        return FS_NO_ERROR;
    }

    /*
     * check if required to do quota update
     */
    if (drive_ptr->drive == FSSIM_SYSTEM_DRIVE          &&
        file_ptr->filename[3] == 0x40 /* '@' */         &&
        /* quota set query */ /* quota run-time hook here */
        fssim_update_quota_set(file_ptr->filename, update_cluster_cnt - before_cluster_cnt) == 0) {

        fssim_give_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex END   */
        return FS_APP_QUOTA_FULL;
    }

    /*
    printf("valid_size = %d, takenclusters = %d, before_cluster_cnt = %d, update_cluster_cnt = %d\n",
        valid_size, drive_ptr->takenclusters, before_cluster_cnt, update_cluster_cnt);
     */

    EXT_ASSERT( drive_ptr->takenclusters >= before_cluster_cnt, 0, 0, 0);
    drive_ptr->takenclusters -= before_cluster_cnt;

    if (drive_ptr->takenclusters + update_cluster_cnt > drive_ptr->totalclusters) {

        drive_ptr->takenclusters += before_cluster_cnt; /* roll back */

        fssim_give_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex END   */
        return FS_DISK_FULL;
    }

    drive_ptr->takenclusters += update_cluster_cnt;

    fssim_give_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex END   */
    return FS_NO_ERROR;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      fssim_check_move_api_params                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to assistence FS_Move complex parameters   */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      src       -  the source path                                     */
/*      dest      -  the destination path                                */
/*      flag      -  the FS_Move indication flags                        */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
static int fssim_check_move_api_params(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, UINT Flag, int * is_virtual)
{
    TCHAR src[MAX_PATH], dst[MAX_PATH];
    int drv_idx1, drv_idx2;
    DWORD attributes;

    if (!_wcsicmp(SrcFullPath, DstFullPath)) {

        /* destination is equal to source */
        return FS_PARAM_ERROR;
    }

    if ((Flag & FS_MOVE_COPY) == 0 && (Flag & FS_MOVE_KILL) == 0) {

        return FS_PARAM_ERROR;
    }

    if (Flag & ~(FS_MOVE_COPY | FS_MOVE_KILL | FS_MOVE_OVERWRITE)) {

        return FS_PARAM_ERROR;
    }

    if (wcslen(SrcFullPath) >= MAX_PATH || wcslen(DstFullPath) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }

    fssim_conv_fn(src, SrcFullPath);
    fssim_conv_fn(dst, DstFullPath);

    /* Error checking and handling */
    if (fssim_is_file_exist(dst) == 1 && (Flag & FS_MOVE_OVERWRITE) == 0) {

        return FS_FILE_EXISTS;
    }

    if (fssim_is_name_valid(dst) == 0) {

        return FS_INVALID_FILENAME;
    }

    /* Virtual File Name Compare Hook */
    if (wcsncmp(SrcFullPath, fssim_vfname_prefix, wcslen(fssim_vfname_prefix)) == 0) {

        *is_virtual = 1;

        if (Flag & FS_MOVE_KILL) {

            return FS_READ_ONLY_ERROR;
        }

        return FS_NO_ERROR;

    } else {

        *is_virtual = 0;
    }

    if (fssim_isopen(src) || fssim_isopen(dst)) {

        return FS_ACCESS_DENIED;
    }

    if (fssim_is_file_exist(src) == 0) {

        return FS_PATH_NOT_FOUND;
    }

    drv_idx1 = fssim_locate_drive( SrcFullPath );
    drv_idx2 = fssim_locate_drive( DstFullPath );

    if ((Flag & FS_MOVE_KILL) && drv_idx1 != drv_idx2) {

        attributes = GetFileAttributes(src);

        if (attributes & FILE_ATTRIBUTE_READONLY) {
        
           return FS_READ_ONLY_ERROR;
        }
    }

    return FS_NO_ERROR;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FSUTIL_copy_file                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to assistence FS_Move complex parameters   */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      src       -  the source path                                     */
/*      dest      -  the destination path                                */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
#define FSUTIL_COPY_BUFFER_LENGTH    (8 * 1024)
static FSUTIL_copy_file(const WCHAR * SrcFullPath, const WCHAR * DstFullPath)
{
    FS_HANDLE fh_r, fh_w;
    unsigned int rlength;
    unsigned int wlength;
    int           status;
    void     *copybuffer;

    fh_r = FS_Open(SrcFullPath, FS_READ_ONLY);

    if (fh_r == FS_ACCESS_DENIED) {

        fh_r = FS_Open(SrcFullPath, FS_READ_ONLY|FS_OPEN_SHARED);
    }

    if (fh_r < FS_NO_ERROR) return fh_r;

    fh_w = FS_Open(DstFullPath, FS_CREATE_ALWAYS);

    if (fh_w < FS_NO_ERROR) return fh_w;
    
    copybuffer = malloc(FSUTIL_COPY_BUFFER_LENGTH);

    status = FS_Read(fh_r, copybuffer, FSUTIL_COPY_BUFFER_LENGTH, &rlength);
    while(status == FS_NO_ERROR && rlength > 0)
    {
        status = FS_Write(fh_w, copybuffer, rlength, &wlength);
        if (status != FS_NO_ERROR) {
            break;
        }
        status = FS_Read(fh_r, copybuffer, FSUTIL_COPY_BUFFER_LENGTH, &rlength);
    }
    free(copybuffer);

    FS_Close(fh_r);
    FS_Close(fh_w);

    return status;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Open                                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to open a file/directory.                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileName  -  file name of to-be-open file                        */
/*      Flag      -  various flags                                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      File handle                                                      */
/*                                                                       */
/*************************************************************************/
int FS_Open(const WCHAR *FileName, UINT Flag)
{
    int fh = -1, is_exist, i;
    unsigned int j, is_virtual, map_fh;
    TCHAR strbuf[MAX_PATH], *pch;
    DWORD access, share, create, attribute, error;

    ASSERT(FileName != NULL);

    __try {

        if (fssim_mutex == NULL) {

            fssim_init();
        }

        /* Virtual File Name Compare Hook */
        if (wcsncmp(FileName, fssim_vfname_prefix, wcslen(fssim_vfname_prefix)) == 0) {

            is_virtual = 1;
            
        } else {

            is_virtual = 0;

            /* Stop irregular path input */
            if (wcslen(FileName) >= MAX_PATH) {

                return FS_PATH_OVER_LEN_ERROR;
            }

            /* convert file name (i.e., X:\ ==> DRIVE_X\) */
            fssim_conv_fn(strbuf, FileName);

        }

        /* varify flags */

        if (Flag & FS_CREATE_ALWAYS) {

            if (Flag & (FS_READ_ONLY | FS_ATTR_READ_ONLY))

                   return FS_READ_ONLY_ERROR;

            if (Flag & (FS_ATTR_DIR | FS_ATTR_VOLUME))

                   return FS_PARAM_ERROR;
        }

        if ((Flag & FS_PROTECTION_MODE) && (Flag & FS_NONBLOCK_MODE))

            return FS_ATTR_CONFLICT;

        if (Flag & FS_OPEN_DIR)
            Flag &= ~FS_OPEN_NO_DIR;

        SetLastError(ERROR_SUCCESS);

        if (is_virtual == 0)
        {
            CRITICAL_SECTION_BEGIN;
            attribute = GetFileAttributes(strbuf);
            CRITICAL_SECTION_END;
        }

        error = GetLastError();

        if (error == ERROR_INVALID_NAME) { /* the name is not valid */

            return FS_INVALID_FILENAME;
        } else if (is_virtual > 0) {

            /* virtual filename --- check if registered */ 
            fssim_take_mutex(fssim_mutex);

            for (j = 0; j < fssim_vfgen.usage_size; j++) {

                pch = fssim_vfgen.data[j].name_once;

                if ( wcsncmp( FileName, pch, wcslen(pch) ) == 0
                  && (FileName[ wcslen(pch) ] == 0x0 || FileName[ wcslen(pch) ] == 0x2e) ) {
                    /* virtual filename entry found */

                    is_virtual = j+1;
                    break;
                }
            }

            if (j == fssim_vfgen.usage_size ) {

                fssim_give_mutex(fssim_mutex);

                return FS_INVALID_FILENAME;
            }

            /* virtual filename --- check mapping */

            for (i = 1; i <= FSSIM_MAX_FILE; i++) {

                if (fssim_file[i].state == STATE_INUSE &&
                    fssim_file[i].unique== fssim_vfgen.data[j].vf_gen_fh_unique) {

                        map_fh = i;
                        break;
                }
            }
            
            if (i == (FSSIM_MAX_FILE+1)) {

                fssim_give_mutex(fssim_mutex);

                return FS_INVALID_FILE_HANDLE;
            }

            /* virtual filename --- check sharing
             * virtual file must be open with FS_READ_ONLY flag and check sharing is not required 
             */
            
            fssim_give_mutex(fssim_mutex);

            /* virtual filename --- verify flags */

            if ((Flag & FS_READ_ONLY) == 0) {

                    return FS_ACCESS_DENIED;
            }

        } else if (!fssim_is_file_exist(strbuf)) {

            /* the file does not exist */

            is_exist = 0;

            if (Flag & (FS_CREATE_ALWAYS | FS_CREATE)) {

                if (Flag & FS_READ_ONLY)

                    return FS_READ_ONLY_ERROR;

                if (!_wcsicmp(strbuf + wcslen(strbuf) - 1, L"\\")) { /* remove the last "/" */

                    *(strbuf + wcslen(strbuf) - 1) = L'\0';
                }
            } else {

                return FS_FILE_NOT_FOUND;
            }
        } else {
            
            /* the file exists */

            is_exist = 1;

            fssim_take_mutex(fssim_mutex);

            for (i = 1; i <= FSSIM_MAX_FILE; i++) {

                if (fssim_file[i].state == STATE_INUSE) {

                    if (!_wcsicmp(fssim_file[i].filename, FileName)) {

                        /* the same file is opened */

                        if ((fssim_file[i].flags & Flag & FS_READ_ONLY) == 0 &&    /* not both read-only */
                            (fssim_file[i].flags & Flag & FS_OPEN_SHARED) == 0) {  /* not both open-shared */

                            fssim_give_mutex(fssim_mutex);

                            return FS_ACCESS_DENIED;

                        } else {

                            break;
                        }
                    }
                }
            }

            fssim_give_mutex(fssim_mutex);


            /* verify flags */

            if (Flag & FS_CREATE_ALWAYS) {

                if (attribute & (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_DIRECTORY))

                    return FS_READ_ONLY_ERROR;
            }

            if ((Flag & FS_READ_ONLY) == 0) {

                if (attribute & FILE_ATTRIBUTE_READONLY)

                    return FS_READ_ONLY_ERROR;
            }

            if (attribute & FILE_ATTRIBUTE_DIRECTORY) {

                    if ((Flag & FS_OPEN_NO_DIR) || ((Flag & FS_READ_ONLY) == 0))

                        return FS_READ_ONLY_ERROR;
            }
        }

        /* allocate a file handle */

        fh = fssim_alloc_fh();

        if (fh == -1)
            return FS_TOO_MANY_FILES;

        if (is_virtual > 0) {

            /* setup virtual file handler, link relationship and leave guarded section */

            fssim_file[fh].handle = INVALID_HANDLE_VALUE;
            fssim_file[fh].flags  = (fssim_file[map_fh].flags & ~FS_OPEN_SHARED) | (Flag & FS_OPEN_SHARED);
            fssim_file[fh].drive  = fssim_file[map_fh].drive;
            fssim_file[fh].DirEntry.FileSize = fssim_vfgen.data[is_virtual - 1].vf_size;
            wcscpy(fssim_file[fh].filename, FileName);

            fssim_vfgen.link[fh]  = map_fh;
            fssim_vfgen.pos[fh]   = 0;
            fssim_vfgen.bias[fh]  = fssim_vfgen.data[is_virtual - 1].vf_offset;
            fssim_vfgen.link_unique[fh] = fssim_file[map_fh].unique;

            ASSERT (fssim_file[map_fh].unique == fssim_vfgen.data[is_virtual - 1].vf_gen_fh_unique);

            __leave;
        }
        /* set CreateFile() access mode */

        if (Flag & FS_READ_ONLY) {

            access = GENERIC_READ;
        } else {

            /* FS_READ_WRITE is the default setting */

            access = GENERIC_READ | GENERIC_WRITE;
        }

       /* set CreateFile() share mode */

        share = FILE_SHARE_READ;

        if (Flag & FS_OPEN_SHARED)
            share |= FILE_SHARE_WRITE;

        /* set CreateFile() create policy */

        if (Flag & FS_CREATE_ALWAYS) {

            create = CREATE_ALWAYS;
        } else if (Flag & FS_CREATE) {

            if (is_exist == 1)


                create = OPEN_EXISTING;
            else

                create = OPEN_ALWAYS;
        } else {

            create = OPEN_EXISTING;
        }

        /* set CreateFile() attributes */

        attribute = FILE_ATTRIBUTE_NORMAL | FILE_FLAG_BACKUP_SEMANTICS;

        if (Flag & (FS_CREATE | FS_CREATE_ALWAYS)) {

            /* set specified attributes */

            if (Flag & FS_ATTR_HIDDEN)
                attribute |= FILE_ATTRIBUTE_HIDDEN;

            if (Flag & FS_ATTR_SYSTEM)
                attribute |= FILE_ATTRIBUTE_SYSTEM;

            if (Flag & FS_ATTR_ARCHIVE)
                attribute |= FILE_ATTRIBUTE_ARCHIVE;
        }

#ifdef DEBUG_FSSIM
        fssim_printf(("FS_Open(): strbuf = "));
        fssim_print_str(strbuf);
#endif  /* DEBUG_FSSIM */

        /* create/open the file */

        CRITICAL_SECTION_BEGIN;
        fssim_file[fh].handle = CreateFile(strbuf, access, share, NULL, create, attribute, NULL);
        CRITICAL_SECTION_END;

        if (fssim_file[fh].handle == INVALID_HANDLE_VALUE) {

            error = GetLastError();

            if (error == ERROR_PATH_NOT_FOUND) {

                /* the path is not found */

                return FS_PATH_NOT_FOUND;
            } else {

                /* Error. All flags are verified above. We should not fail */

                error = GetLastError();

                fssim_printf(("CreateFile() failed in FS_Open()\n"));
                fssim_printf(("error code = %d\n", error));

                ASSERT(0);
            }
        }

        /*
         * Set other fileds in the file handle.
         */

        fssim_file[fh].flags = Flag;

        fssim_file[fh].isabort = 0;

        wcscpy(fssim_file[fh].filename, FileName);

        fssim_file[fh].copyprogress = NULL;

        fssim_file[fh].findattr1 = fssim_file[fh].findattr2 = 0;

        /* get the drive letter of the locating drive of the file */
        pch = wcsstr(strbuf, FSSIM_DRIVE_DIR_PREFIX);

        if (pch != NULL) {

            /* there is a drive name specified */

            pch += wcslen(FSSIM_DRIVE_DIR_PREFIX);

            for (i = 0; i < FSSIM_MAX_DRIVE; i++) {

                if (!wcsnicmp(pch, &(fssim_drvinfo[i].drive), 1)) {

                    fssim_file[fh].drive = i;

                    break;
                } else if (!wcsnicmp(pch, &(fssim_drvinfo[i].remap_drive), 1)) {

                    fssim_file[fh].drive = i;

                    break;
                }
            }
        } else {

            /* no drive name is specified */

            /* find the current directory */

            for (i = 0; i < FSSIM_MAX_DRIVE; i++) {

                if (fssim_drvinfo[i].is_current == 1) {

                    fssim_file[fh].drive = i;

                    break;
                }
            }
        }

        ASSERT(fssim_file[fh].drive != -1);

        fssim_set_direntry(fh, strbuf, &(fssim_file[fh].DirEntry));
    }
    __finally {

        if ((fh >= 1) && (fh <= FSSIM_MAX_FILE)
            && (is_virtual == 0)
            && (fssim_file[fh].handle == INVALID_HANDLE_VALUE)) {

            fssim_free_fh(fh);
        }
    }

    return fh;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_OpenHint                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to open a file handle.                     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileName  -  file name of to-be-open file                        */
/*      Flag      -  various flags                                       */
/*      DSR_Hint  -  dummy input                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      File handle                                                      */
/*                                                                       */
/*************************************************************************/
int FS_OpenHint(const WCHAR * FileName, UINT Flag, FS_FileLocationHint *DSR_Hint)
{
    ASSERT(FileName != NULL);

    return FS_Open(FileName, Flag);
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Close                                                         */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to close a file handle handle.             */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      File  -  file handle                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_Close(FS_HANDLE File)
{
    int  map_fh=0;

    /* verify file handle */

    if (File > FSSIM_MAX_FILE || File <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[File].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_vfgen.link[File] > 0)

        map_fh = fssim_vfgen.link[File];

    else if (fssim_file[File].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    /* close the file handle */
    fssim_take_mutex(fssim_mutex); /* critical section { */
    if (map_fh > 0) {

        fssim_vfgen.link[File] = 0;

    } else {

        fssim_close_fh(File);
    }
    fssim_give_mutex(fssim_mutex); /* critical section } */

    fssim_free_fh(File);

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_CloseAll                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to close all file handles.                 */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Number of files closed or error code                             */
/*                                                                       */
/*************************************************************************/
int FS_CloseAll()
{
    int i, cnt, result;
    BOOL retval;

    if (fssim_mutex == NULL) {
        fssim_init();
    }

    cnt = 0;
    
    result = FS_NO_ERROR;

    /* critical section { */
    fssim_take_mutex(fssim_mutex);
    for (i = 1; i <= FSSIM_MAX_FILE; i++) {

        if (fssim_vfgen.link[i] > 0 && fssim_file[i].state == STATE_INUSE) {
            
            fssim_vfgen.link[i] = 0;

            /* equivalence to fssim_free_fh(i); */
            memset( &(fssim_file[i]), 0, sizeof(FSSIM_FILE_T));
            fssim_file[i].state = STATE_FREE;

            cnt++;

        } else if (fssim_file[i].state == STATE_INUSE) {

            retval = CloseHandle(fssim_file[i].handle);

            fssim_file[i].handle= INVALID_HANDLE_VALUE;

            /* equivalence to fssim_free_fh(i); */
            memset( &(fssim_file[i]), 0, sizeof(FSSIM_FILE_T));
            fssim_file[i].state = STATE_FREE;

            if (retval)
                cnt++;
            else
                result = fssim_conv_errcode(GetLastError(), "CloseHandle Fail\n");
        }
    }

    fssim_vfgen.usage_size = 0; /* total clean generated virtual file name */
    memset( fssim_vfgen.data, 0, fssim_vfgen.allocat_size * sizeof(FSSIM_VIRTUAL_FILENAME_T) );

    fssim_give_mutex(fssim_mutex); /* } critical section */

    if (result == FS_NO_ERROR)

        return cnt;
    else

        return result;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Read                                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to read data from a file.                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle  -  file handle of file to read                       */
/*      DataPtr     -  memory address to put read data                   */
/*      Length      -  number of bytes to read                           */
/*      Read        -  number of bytes read                              */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_Read(FS_HANDLE FileHandle, void *DataPtr, UINT Length, UINT *Read)
{
    UINT DummyRead;
    int map_fh, saved_pos;

    ASSERT(DataPtr != NULL);

    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE && fssim_vfgen.link[FileHandle] == 0)

        return FS_INVALID_FILE_HANDLE;

    if (fssim_file[FileHandle].isabort == 1)
        return FS_ABORTED_ERROR;

    if (Read == NULL)
        Read = &DummyRead;

    if (fssim_vfgen.link[FileHandle] > 0) {

        /* Virtual File Handle Read */

        map_fh = fssim_vfgen.link[FileHandle];

        if (fssim_vfgen.link_unique[FileHandle] != fssim_file[map_fh].unique ||
            fssim_file[map_fh].state != STATE_INUSE ||
            fssim_file[map_fh].handle == INVALID_HANDLE_VALUE ) { /* virtual file map error */
            return FS_VF_MAP_ERROR;
        }

        LockFile(fssim_file[map_fh].handle,
                 fssim_vfgen.bias[FileHandle], 0, fssim_file[FileHandle].DirEntry.FileSize, 0);

        saved_pos = SetFilePointer(fssim_file[map_fh].handle, 0, NULL, FILE_CURRENT);

        SetFilePointer(fssim_file[map_fh].handle,
                       fssim_vfgen.bias[FileHandle] + fssim_vfgen.pos[FileHandle], NULL, FILE_BEGIN);

        if ( (Length + fssim_vfgen.pos[FileHandle]) > fssim_file[FileHandle].DirEntry.FileSize) {
            Length = fssim_file[FileHandle].DirEntry.FileSize - fssim_vfgen.pos[FileHandle];
        }

        ReadFile(fssim_file[map_fh].handle, DataPtr, Length, Read, NULL);

        fssim_vfgen.pos[FileHandle] += Length;

        SetFilePointer(fssim_file[map_fh].handle, saved_pos, NULL, FILE_BEGIN);

        UnlockFile(fssim_file[map_fh].handle,
                 fssim_vfgen.bias[FileHandle], 0, fssim_file[FileHandle].DirEntry.FileSize, 0);

    } else {
        ReadFile(fssim_file[FileHandle].handle, DataPtr, Length, Read, NULL);
    }

#ifdef DEBUG_FSSIM
    if (Length != *Read) {

        fssim_printf(("ReadFile() failed in FS_Read()\n"));

        fssim_printf(("error code = %d, Length = %d, *Read = %d\n", GetLastError(), Length, *Read));
    }
#endif  /* DEBUG_FSSIM */

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Write                                                         */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to write data to a file.                   */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle  -  file handle of file to write                      */
/*      DataPtr     -  memory address of write data                      */
/*      Length      -  number of bytes to write                          */
/*      Written     -  number of bytes written                           */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Number of files closed or error code                             */
/*                                                                       */
/*************************************************************************/
int FS_Write(FS_HANDLE FileHandle, void *DataPtr, UINT Length, UINT *Written)
{
    UINT DummyWritten;
    int StartPos, FileSize;
    int result;

    ASSERT(DataPtr != NULL);

    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE && fssim_vfgen.link[FileHandle] == 0)

        return FS_INVALID_FILE_HANDLE;

    if (fssim_file[FileHandle].isabort == 1)
        return FS_ABORTED_ERROR;

    if (fssim_file[FileHandle].flags & FS_READ_ONLY)
        return FS_READ_ONLY_ERROR;

    if (Written == NULL)
        Written = &DummyWritten;

    StartPos = SetFilePointer(fssim_file[FileHandle].handle, 0, NULL, FILE_CURRENT);

    FileSize = GetFileSize(fssim_file[FileHandle].handle, NULL);

    ASSERT( FileSize >= 0 && StartPos >= 0 );

    fssim_file[FileHandle].DirEntry.FileSize = FileSize;

    if ((UINT)StartPos + Length > (UINT)FileSize) {

        result = fssim_update_watermark_by_fh(&fssim_file[FileHandle], (StartPos + Length - FileSize));

        if (result < 0) { /* Disk may full */
            return result;
        }
    }

    WriteFile(fssim_file[FileHandle].handle, DataPtr, Length, Written, NULL);

    if ((UINT)StartPos + *Written > (UINT)FileSize) {

        fssim_file[FileHandle].DirEntry.FileSize = StartPos + *Written;
    }

#ifdef DEBUG_FSSIM
    if (Length != *Written) {

        fssim_printf(("WriteFile() failed in FS_Write()\n"));

        fssim_printf(("error code = %d, Length = %d, *Written = %d\n", GetLastError(), Length, *Written));
    }
#endif  /* DEBUG_FSSIM */

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_SetSeekHint                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle   -  no use                                           */
/*      HintNum      -  no use                                           */
/*      Hint         -  no use                                           */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_SetSeekHint(FS_HANDLE FileHandle, UINT HintNum, FS_FileLocationHint *Hint)
{
    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Seek                                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to move a file pointer.                    */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle  -  file handle of file to move the file pointer      */
/*      Offset      -  bytes to move pointer                             */
/*      Whence      -  starting point                                    */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      The value of new file pointer or error code                      */
/*                                                                       */
/*************************************************************************/
int FS_Seek(FS_HANDLE FileHandle, int Offset, int Whence)
{
    DWORD method, startpos, newpos, size, size_high;
    int map_fh=0, result;

    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_vfgen.link[FileHandle] > 0)

        map_fh = fssim_vfgen.link[FileHandle];

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    /* verify virtual file map or physical file size */

    if (map_fh > 0) {

        if (fssim_vfgen.link_unique[FileHandle] != fssim_file[map_fh].unique ||
            fssim_file[map_fh].state != STATE_INUSE ||
            fssim_file[map_fh].handle == INVALID_HANDLE_VALUE ) { /* virtual file map error */

            return FS_VF_MAP_ERROR;
        }

        size = fssim_file[FileHandle].DirEntry.FileSize;

    } else {
        size_high = 0;
        size = GetFileSize(fssim_file[FileHandle].handle, &size_high);
        if (size_high > 0) {
            fssim_printf(("==================================================================\n"));
            fssim_printf(("Fatal Error!! The file size of file handle %d exceeds 0xFFFFFFFF!!\n", FileHandle));
            fssim_printf(("file size = 0x%X%X\n", size_high, size));
            fssim_printf(("==================================================================\n"));
            EXT_ASSERT(0, 0, 0, 0);
        }
    }

    /* evaluate start position and new position */

    switch (Whence) {
    case FS_FILE_BEGIN:
        
        method = FILE_BEGIN;
        startpos = 0;

        break;

    case FS_FILE_CURRENT:
        
        method = FILE_CURRENT;
        if (map_fh > 0)
            startpos = fssim_vfgen.pos[FileHandle];
        else
            startpos = SetFilePointer(fssim_file[FileHandle].handle, 0, NULL, FILE_CURRENT);

        break;

    case FS_FILE_END:

        method = FILE_END;
        startpos = size;

        break;

    default:
        return FS_PARAM_ERROR;
    }

    newpos = startpos + Offset;

    if ((Offset < 0) && (newpos > startpos))
        return FS_INVALID_FILE_POS;

    if ((Offset > 0) && (newpos < startpos))
        return FS_INVALID_FILE_POS;

    if ((newpos > size) && (fssim_file[FileHandle].flags & FS_READ_ONLY)) {

        return FS_INVALID_FILE_POS;
    }

    if (map_fh > 0) {

        fssim_vfgen.pos[FileHandle] = newpos;
    } else {

        newpos = SetFilePointer(fssim_file[FileHandle].handle, Offset, NULL, method);

        /* need to extend the file (to sync behavior with Target) */
        if( newpos > size ) {

            result = fssim_update_watermark_by_fh(&fssim_file[FileHandle], (newpos - size));

            if( result < 0 ) {

                return result;
            }

            if( SetEndOfFile(fssim_file[FileHandle].handle) == 0 ) { /* fail */

                return fssim_conv_errcode( GetLastError(), "Extend File for Seek Failure\n");
            } 
        }
    }

    return (int)newpos;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Commit                                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to flush all buffers associated to a file. */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle  -  file handle of file to flush buffers              */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_Commit(FS_HANDLE FileHandle)
{
    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    FlushFileBuffers(fssim_file[FileHandle].handle);

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_ReleaseFH                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to close all file handles owned by a task. */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      TaskID  -  task id (if NULL, all file handles are clsed)         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_ReleaseFH(void * TaskId)
{
    int i;

    if (TaskId == NULL) {

        /* close all file handles */

        FS_CloseAll();

        return FS_NO_ERROR;
    } else {

        fssim_take_mutex(fssim_mutex); /* { critical section */

        /* REMARK -- close virtual file handler first */
        for (i = 1; i <= FSSIM_MAX_FILE; i++) {

            if (fssim_file[i].taskid == TaskId && fssim_file[i].state == STATE_INUSE && fssim_vfgen.link[i] > 0) {

                /* equivalence to FS_Close(i); with virtufl file handler */
                fssim_vfgen.link[i] = 0;
                /* equivalence to fssim_free_fh(i); */
                memset( &(fssim_file[i]), 0, sizeof(FSSIM_FILE_T));
                fssim_file[i].state = STATE_FREE;
            }
        }

        /* REMARK -- close real file handler next */
        for (i = 1; i <= FSSIM_MAX_FILE; i++) {

            if (fssim_file[i].taskid == TaskId && fssim_file[i].state == STATE_INUSE) {

                fssim_close_fh(i);
                /* equivalence to fssim_free_fh(i); */
                memset( &(fssim_file[i]), 0, sizeof(FSSIM_FILE_T));
                fssim_file[i].state = STATE_FREE;
            }
        }
        fssim_give_mutex(fssim_mutex); /* } critical section */

        return FS_NO_ERROR;
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Abort                                                         */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to abort the operation of the current      */
/*      file handle.                                                     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      ActionHandle  - file handle of the file to abort                 */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_Abort(UINT ActionHandle)
{
    fssim_file[ActionHandle].isabort = 1;

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetFileInfo                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get a file's information.               */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      File      -  file handle of the file to get information          */
/*      FileInfo  -  data structure to store file information            */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_GetFileInfo(FS_HANDLE FileHandle, FS_FileInfo *FileInfo)
{
    int map_fh=0;

    ASSERT(FileInfo != NULL);

    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_vfgen.link[FileHandle] > 0)

        map_fh = fssim_vfgen.link[FileHandle];

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)
        
        return FS_INVALID_FILE_HANDLE;

    FileInfo->DirEntry = &(fssim_file[FileHandle].DirEntry);

    fssim_update_direntry_datetime(FileHandle, &(fssim_file[FileHandle].DirEntry));

    FileInfo->FullName = (char *)fssim_file[FileHandle].filename;

    if (map_fh > 0) {

        /* virtual file */

        FileInfo->FilePos = fssim_vfgen.pos[FileHandle];
        FileInfo->AllocatedSize = 0;

    } else {

        FileInfo->FilePos = SetFilePointer(fssim_file[FileHandle].handle, 0, NULL, FILE_CURRENT);
        FileInfo->AllocatedSize = GetFileSize(fssim_file[FileHandle].handle, NULL);
    }

    FileInfo->ClusterChains = 0;

    FileInfo->VolumeSerialNumber = 0;

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetFileSize                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to the file size.                          */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle  -  file handl of file to get the size                */
/*      Size        -  file size                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_GetFileSize(FS_HANDLE FileHandle, UINT *Size)
{
    DWORD size_high;
    int map_fh=0;

    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_vfgen.link[FileHandle] > 0)

        map_fh = fssim_vfgen.link[FileHandle];

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    if (map_fh > 0) {

        *Size = fssim_file[FileHandle].DirEntry.FileSize;
        return FS_NO_ERROR;
    }

    size_high = 0;

    *Size = GetFileSize(fssim_file[FileHandle].handle, &size_high);

    if (size_high > 0) {
        fssim_printf(("==================================================================\n"));
        fssim_printf(("Fatal Error!! The file size of file handle %d exceeds 0xFFFFFFFF!!\n", FileHandle));
        fssim_printf(("file size = 0x%08X%08X\n", size_high, *Size));
        fssim_printf(("==================================================================\n"));
        ASSERT(0);
    }

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetFilePosition                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to the current file pointer.               */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle   -  file handl of file to get the file pointer       */
/*      Position     -  storage for the current file pointer             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_GetFilePosition(FS_HANDLE FileHandle, UINT *Position)
{
    int map_fh=0;

    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_vfgen.link[FileHandle] > 0)

        map_fh = fssim_vfgen.link[FileHandle];

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)
        
        return FS_INVALID_FILE_HANDLE;

    if (map_fh > 0) {

        *Position = fssim_vfgen.pos[FileHandle];

    } else {

        *Position = SetFilePointer(fssim_file[FileHandle].handle, 0, NULL, FILE_CURRENT);
    }

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_SetFileTime                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle  -  no use                                            */
/*      Time        -  no use                                            */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_SetFileTime(FS_HANDLE FileHandle, const FS_DOSDateTime * Time)
{
    FILETIME write_ft;
    SYSTEMTIME write_st;
    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_vfgen.link[FileHandle] > 0)

        return FS_PARAM_ERROR;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)
        
        return FS_INVALID_FILE_HANDLE;

    /* convert the structure */
    write_st.wYear  = Time->Year1980 + 1980;

    write_st.wMonth = Time->Month;

    write_st.wDay   = Time->Day;

    write_st.wHour  = Time->Hour;

    write_st.wMinute= Time->Minute;

    write_st.wSecond= Time->Second2 * 2;

    write_st.wMilliseconds = 0;

    SetLastError(ERROR_SUCCESS);

    if ( !SystemTimeToFileTime( &write_st, &write_ft ) ) {
        printf("SystemTimeToFileTime Fail : %d\n", GetLastError() );
    }
    /* set file time */

    if ( !SetFileTime(fssim_file[FileHandle].handle, NULL, NULL, &write_ft) ) {
        printf("SetFileTime Fail : %d\n", GetLastError() );
    }

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetAttributes                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get a file's attribute.                 */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileName  -  file name of the file to get                        */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Attributes(positive value) or error code(negative value)         */
/*                                                                       */
/*************************************************************************/
int FS_GetAttributes(const WCHAR * FileName)
{
    TCHAR strbuf[MAX_PATH];
    DWORD attributes;
    int result;

    ASSERT(FileName != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    /* Stop irregular path input */
    if (wcslen(FileName) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }

    fssim_conv_fn(strbuf, FileName);

    if (!fssim_is_name_valid(strbuf))

        /* the name is not valid */

        return FS_INVALID_FILENAME;

    else if (!fssim_is_file_exist(strbuf))

        /* the file doesn't exist */

        return FS_FILE_NOT_FOUND;

    SetLastError(ERROR_SUCCESS);

    CRITICAL_SECTION_BEGIN;
    attributes = GetFileAttributes(strbuf);
    CRITICAL_SECTION_END;

    result = 0;

    if (attributes & FILE_ATTRIBUTE_READONLY)

        result |= FS_ATTR_READ_ONLY;

    if (attributes & FILE_ATTRIBUTE_HIDDEN)

        result |= FS_ATTR_HIDDEN;

    if (attributes & FILE_ATTRIBUTE_SYSTEM)

        result |= FS_ATTR_SYSTEM;

    if (attributes & FILE_ATTRIBUTE_DIRECTORY)

        result |= FS_ATTR_DIR;

    if (attributes & FILE_ATTRIBUTE_ARCHIVE)

        result |= FS_ATTR_ARCHIVE;

    return result;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_SetAttributes                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to set a file's attribute.                 */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileName    -  file name of the file to set                      */
/*      Attributes  -  file attributes                                   */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_SetAttributes(const WCHAR * FileName, BYTE Attributes)
{
    TCHAR strbuf[MAX_PATH];
    DWORD win_attributes;
    DWORD rtf_attributes;

    ASSERT(FileName != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    /* Stop irregular path input */
    if (wcslen(FileName) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf, FileName);

    if (!fssim_is_name_valid(strbuf))

        /* the name is not valid */

        return FS_INVALID_FILENAME;

    else if (!fssim_is_file_exist(strbuf))

        /* the file doesn't exist */

        return FS_FILE_NOT_FOUND;

    SetLastError(ERROR_SUCCESS);

    CRITICAL_SECTION_BEGIN;
    win_attributes = GetFileAttributes(strbuf);
    CRITICAL_SECTION_END;

    if (win_attributes & FILE_ATTRIBUTE_DIRECTORY)

        rtf_attributes |= FS_ATTR_DIR;

    if ((Attributes & FS_ATTR_VOLUME) || ((rtf_attributes ^ Attributes) & FS_ATTR_DIR))

        /* FS_ATTR_VOLUME is not allowed, and FS_ATTR_DIR can not be switch */
        return FS_ACCESS_DENIED;

    win_attributes = 0;

    if (Attributes & FS_ATTR_READ_ONLY)

        win_attributes |= FILE_ATTRIBUTE_READONLY;

    if (Attributes & FS_ATTR_HIDDEN)

        win_attributes |= FILE_ATTRIBUTE_HIDDEN;

    if (Attributes & FS_ATTR_SYSTEM)

        win_attributes |= FILE_ATTRIBUTE_SYSTEM;

    if (Attributes & FS_ATTR_ARCHIVE)

        win_attributes |= FILE_ATTRIBUTE_ARCHIVE;

    SetFileAttributes(strbuf, win_attributes);

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Delete                                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to delete a file.                          */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileName    -  file name of the file to delete                   */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_Delete(const WCHAR * FileName)
{   TCHAR strbuf[MAX_PATH];
    WIN32_FILE_ATTRIBUTE_DATA file_info;
    int error, idx, clustersize, clustercount;

    ASSERT(FileName != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    /* Stop irregular path input */
    if (wcslen(FileName) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf, FileName);

    if (!fssim_is_name_valid(strbuf))

        /* the name is not valid */

        return FS_INVALID_FILENAME;

    else if (!fssim_is_file_exist(strbuf))

        /* the file doesn't exist */

        return FS_FILE_NOT_FOUND;

    CRITICAL_SECTION_BEGIN;
    if( GetFileAttributesEx(strbuf, GetFileExInfoStandard, &file_info) == 0) {

        error = GetLastError();
#ifdef DEBUG_FSSIM

            fssim_printf(("GetFileAttributesEx() failed in FS_Delete()\n"));
            fssim_printf(("error code = %d\n", error));

#endif  /* DEBUG_FSSIM */

        EXT_ASSERT( 0, error, 0, 0);
    }
    CRITICAL_SECTION_END;

    if (file_info.dwFileAttributes & (FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_READONLY))

            return FS_READ_ONLY_ERROR;

    CRITICAL_SECTION_BEGIN;
    error = DeleteFile(strbuf);
    CRITICAL_SECTION_END;

    if (!error)

        return fssim_conv_errcode(GetLastError(), "DeleteFile() failed in FS_Delete()\n");

    /* search drive index for filename , update drive's takenclusters */

    idx = fssim_locate_drive( FileName );
    clustersize = fssim_drvinfo[idx].sectorspercluser * fssim_drvinfo[idx].bytespersector;

    fssim_take_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex BEGIN */

    if (fssim_drvinfo[idx].takenclusters == 0) {

        fssim_get_drive_watermark(&fssim_drvinfo[idx]);
    }

    ASSERT(file_info.nFileSizeHigh == 0);
    if (file_info.nFileSizeLow > 0) {

        clustercount = ((file_info.nFileSizeLow - 1) / clustersize + 1);

        /* update quota mgt and disk space */
        fssim_drvinfo[idx].takenclusters -= clustercount;
        fssim_update_quota_set(FileName, 0 - clustercount);
    }

    fssim_give_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex END   */

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_PseudoMerge                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to concatenate two files.                  */
/*      Append file 2 to file 1 and delete file 2.                       */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileName1  -  file name of the file to be appended               */
/*      FileName2  -  file name of the file to append                    */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_PseudoMerge(const WCHAR * FileName1, const WCHAR * FileName2)
{
    TCHAR strbuf1[MAX_PATH], strbuf2[MAX_PATH];
    const TCHAR *drive1, *drive2;
    DWORD attributes;
    FS_HANDLE f1, f2;
    char buff[FSSIM_BUFF_SIZE];
    int result, i, cluster_size;
    DWORD read, written;

    ASSERT(FileName1 != NULL && FileName2 != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    /*
     * Verify file 1.
     */

    /* Stop irregular path input */
    if (wcslen(FileName1) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf1, FileName1);

    if (!fssim_is_name_valid(strbuf1))

        /* the name is not valid */

        return FS_INVALID_FILENAME;
    
    else if (!fssim_is_file_exist(strbuf1))

        /* file 1 doesn't exist */

        return FS_FILE_NOT_FOUND;

    CRITICAL_SECTION_BEGIN;
    attributes = GetFileAttributes(strbuf1);
    CRITICAL_SECTION_END;

    if (attributes & (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_DIRECTORY))

        return FS_READ_ONLY_ERROR;

    if (fssim_isopen(FileName1))

        return FS_ACCESS_DENIED;

    /*
     * Verify file 2.
     */

    /* Stop irregular path input */
    if (wcslen(FileName2) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf2, FileName2);

    if (!fssim_is_name_valid(strbuf2))

        /* the name is not valid */

        return FS_INVALID_FILENAME;

    else if (!fssim_is_file_exist(strbuf2))

        /* file 2 doesn't exist */

        return FS_NO_ERROR;

    SetLastError(ERROR_SUCCESS);
    CRITICAL_SECTION_BEGIN;
    attributes = GetFileAttributes(strbuf2);
    CRITICAL_SECTION_END;

    if (attributes & (FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_DIRECTORY))

        return FS_READ_ONLY_ERROR;

    if (fssim_isopen(FileName2))

        return FS_ACCESS_DENIED;


    /* search drive index for path1 */

    i = fssim_locate_drive( FileName1 );

    if( i >= FSSIM_MAX_DRIVE ) {

        return FS_DRIVE_NOT_FOUND;

    } else if ( i < 0 ) {

        i = fssim_get_default_drive();
    }

    ASSERT(i >= 0 && i < FSSIM_MAX_DRIVE);

    drive1 = &(fssim_drvinfo[i].drive);

    /* search drive index for path 2 */

    i = fssim_locate_drive( FileName2 );

    if( i >= FSSIM_MAX_DRIVE ) {

        return FS_DRIVE_NOT_FOUND;

    } else if ( i < 0 ) {

        i = fssim_get_default_drive();
    }

    ASSERT(i >= 0 && i < FSSIM_MAX_DRIVE);

    drive2 = &(fssim_drvinfo[i].drive);

    /* let's PseudoMerge now */

    if (*drive1 != *drive2)

        return FS_ACCESS_DENIED;
    /*
     * Open two files. Read file 2 and write to file 1.
     */

    __try {

        f1 = FS_Open(FileName1, FS_READ_WRITE);

        if (f1 < 0)

            return f1;

        f2 = FS_Open(FileName2, FS_READ_ONLY);

        if (f2 < 0)

            return f2;

        /* move the file pointer of file 1 to the end */
        result = FS_Seek(f1, 0, FS_FILE_END);

        if (result < 0)

            /* abort the operation while there is a error */

            return result;

        /* make file1 be cluster aligned */
        cluster_size = fssim_drvinfo[i].bytespersector * fssim_drvinfo[i].sectorspercluser;
        result = result % cluster_size;

        if (result != 0) {
            /* This will extend file to cluster size align */
            result = FS_Seek(f1, cluster_size - result, FS_FILE_END);
        }

        do {

            result = FS_Read(f2, buff, FSSIM_BUFF_SIZE * sizeof(char), &read);

            if (result != FS_NO_ERROR)

                /* abort the opeartion while there is a error */

                return result;

            result = FS_Write(f1, buff, read, &written);

            if (result != FS_NO_ERROR)

                /* abort the operation while there is a error */

                return result;
        } while (read != 0);
    }
    __finally {

        if (f1 >= 0)
            FS_Close(f1);

        if (f2 >= 0)
            FS_Close(f2);

    }

    return FS_Delete(FileName2);
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetCurrentDir                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get the current direcotry name/         */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DirName    -  buffer to store the current directory name         */
/*      MaxLength  -  the size of the buffer                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_GetCurrentDir(WCHAR * DirName, UINT MaxLength)
{
    TCHAR strbuf[MAX_PATH];
    int   idx;

    ASSERT(DirName != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    idx = fssim_get_default_drive();
    wcscpy(strbuf, fssim_drvinfo[idx].dir_name);

#ifdef DEBUG_FSSIM
    fssim_printf(("FS_GetCurrentDir(): drive idx = %d, strbuf = ", idx));
    fssim_print_str(strbuf);
#endif  /* DEBUG_FSSIM */

    fssim_retrieve_fn(strbuf);

    if ((wcslen(strbuf) + 1) > MaxLength)

        FS_STRING_BUFFER_TOO_SMALL;

    wcscpy(DirName, strbuf);

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_SetCurrentDir                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to set the current direcotry name.         */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DirName    -  directory name to set                              */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_SetCurrentDir(const WCHAR * DirName)
{
    TCHAR strbuf[MAX_PATH];
    DWORD attributes;
    int i, j;

    ASSERT(DirName != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }
 
    __try {

        i = fssim_locate_drive( DirName );

        if( i >= FSSIM_MAX_DRIVE ) {

            return FS_DRIVE_NOT_FOUND;
        }

        /* Stop irregular path input */
        if (wcslen(DirName) >= MAX_PATH) {
    
            return FS_PATH_OVER_LEN_ERROR;
        }
    
        fssim_conv_fn(strbuf, DirName);

#ifdef DEBUG_FSSIM

        fssim_printf(("FS_SetCurrentDir(): strbuf = "));
        fssim_print_str(strbuf);

#endif  /* DEBUG_FSSIM */

        if (!fssim_is_name_valid(strbuf))

            /* the name is not valid */

            return FS_INVALID_FILENAME;

        else if (!fssim_is_file_exist(strbuf))

            /* the file doesn't exist */

            return FS_PATH_NOT_FOUND;

        SetLastError(ERROR_SUCCESS);
        attributes = GetFileAttributes(strbuf);

        if ((attributes & FILE_ATTRIBUTE_DIRECTORY) == 0) {

            /* not a director name */

            return FS_PATH_NOT_FOUND;
        }

        /* update fssim_drvinfo[] */
        fssim_take_mutex(fssim_mutex);

        if (wcsstr(DirName + 1, L":")) {

            /* a drive name is specified */

            /* find and update the current drive information */

            for (j = 0, i = FSSIM_MAX_DRIVE; j < FSSIM_MAX_DRIVE; j++) {

                if (!wcsnicmp(&(fssim_drvinfo[j].drive), &(DirName[0]), 1)) {

                    fssim_drvinfo[j].is_current = 1;
                
                    i = j;

                } else if (!wcsnicmp(&(fssim_drvinfo[j].remap_drive), &(DirName[0]), 1)) {

                    fssim_drvinfo[j].is_current = 1;
                
                    i = j;

                } else {

                    fssim_drvinfo[j].is_current = 0;
                }
            }

        } else {

            /* no drive name is specified */

            /* only need to find the current drive information */

            for (i = 0; i < FSSIM_MAX_DRIVE; i++) {

                if (fssim_drvinfo[i].is_current == 1)
                
                    break;
            }

        }

        ASSERT(i < FSSIM_MAX_DRIVE);

        wcscpy(fssim_drvinfo[i].dir_name, strbuf);

#ifdef DEBUG_FSSIM

            fssim_printf(("FS_SetCurrentDir(): fssim_drvinfo[%d].dir_name = ", i));
            fssim_print_str(fssim_drvinfo[i].dir_name);

#endif  /* DEBUG_FSSIM */

        fssim_give_mutex(fssim_mutex);

    }
    __finally {

    }

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_CreateDir                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to create a direcotry.                     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DirName    -  directory name to create                           */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_CreateDir(const WCHAR *DirName)
{
    TCHAR strbuf[MAX_PATH];
    DWORD error;

    ASSERT(DirName != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    /* Stop irregular path input */
    if (wcslen(DirName) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }

    fssim_conv_fn(strbuf, DirName);

#ifdef DEBUG_FSSIM

    fssim_printf(("FS_CreateDir() trying to create path = "));
    fssim_print_str(strbuf);

#endif  /* DEBUG_FSSIM */

    if (!fssim_is_name_valid(strbuf))

        /* the name is not valid */

        return FS_INVALID_FILENAME;

    else if (fssim_is_file_exist(strbuf))

        /* the file exists */

        return FS_FILE_EXISTS;

    else {

        CRITICAL_SECTION_BEGIN;
        error = CreateDirectory(strbuf, NULL);
        CRITICAL_SECTION_END;

        if (error == 0)

            return fssim_conv_errcode(GetLastError(), "CreateDirectory() failed in FS_CreateDir()\n");

        else

            return FS_NO_ERROR;
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_RemoveDir                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to remove a direcotry.                     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DirName    -  directory name to remove                           */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_RemoveDir(const WCHAR * DirName)
{
    TCHAR strbuf[MAX_PATH];
    DWORD attributes, error;
    int   idx;

    ASSERT(DirName != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    /* Stop irregular path input */
    if (wcslen(DirName) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf, DirName);

    SetLastError(ERROR_SUCCESS);
    CRITICAL_SECTION_BEGIN;
    attributes = GetFileAttributes(strbuf);
    CRITICAL_SECTION_END;

    if (GetLastError() == ERROR_INVALID_NAME)

        /* the name is not valid */

        return FS_INVALID_FILENAME;

    else if (!fssim_is_file_exist(strbuf))

        /* the file doesn't exist */

        return FS_PATH_NOT_FOUND;

    else if ((attributes & FILE_ATTRIBUTE_DIRECTORY) == 0)

        /* not a directory */

        return FS_PATH_NOT_FOUND;

    else if ((attributes & FILE_ATTRIBUTE_READONLY) == FILE_ATTRIBUTE_READONLY)

        /* the directory is read-only */

        return FS_READ_ONLY_ERROR;

    else if (fssim_isopen(DirName))

        /* the directory is opened */

        return FS_ACCESS_DENIED;


    idx = fssim_get_default_drive();

    if (!_wcsicmp(strbuf, fssim_drvinfo[idx].dir_name)) {

        /* DirName is the current directory */

        /* cannot remove the current directory */

        return FS_ACCESS_DENIED;
    }

    CRITICAL_SECTION_BEGIN;
    error = RemoveDirectory(strbuf);
    CRITICAL_SECTION_END;

    if (error == 0) {

        error = GetLastError();

        if (error == ERROR_DIR_NOT_EMPTY)
        
            return FS_ACCESS_DENIED;

        else

            return fssim_conv_errcode(error, "RemoveDirectory() failed in FS_RemoveDir()\n");

    } else {

        return FS_NO_ERROR;
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Extend                                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to change the allocated file size,         */
/*      but not the current file size, of a file.                        */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle   -  file handle to extend                            */
/*      Length       -  number of bytes to extend                        */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_Extend(FS_HANDLE FileHandle, UINT Length)
{
    int TotalBytes;
    int FileSize;
    int result;

    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_vfgen.link[FileHandle] > 0) /* virturl file; not normal file */

        return FS_READ_ONLY_ERROR;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].flags & FS_READ_ONLY)

        return FS_READ_ONLY_ERROR;

    SetLastError(ERROR_SUCCESS);

    TotalBytes = SetFilePointer(fssim_file[FileHandle].handle, 0, NULL, FILE_CURRENT);

    FileSize = SetFilePointer(fssim_file[FileHandle].handle, 0, NULL, FILE_END);

    if (TotalBytes < 0 || FileSize < 0)

        return fssim_conv_errcode(GetLastError(), "SetFilePointer() failed in FS_Extend()\n");

    TotalBytes += Length;

    if (TotalBytes < 0)

        return FS_FILE_TOO_LARGE;

    if (TotalBytes > FileSize) {

        result = fssim_update_watermark_by_fh(&fssim_file[FileHandle], (TotalBytes - FileSize));

        if (result < 0) { /* Disk may full */

            return result;
        }

        /* send back the allocated/taken cluster, because we must ensure FS_CheckFile() can do nothing */
        fssim_update_watermark_by_fh(&fssim_file[FileHandle], (FileSize - TotalBytes));

    }

    return FS_NO_ERROR;
/* Try to use SetFileValidData() function call to implement FS_Extend() but link failure, skip */
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
#endif 
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Truncate                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to truncate a file.                        */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle   -  file handle to extend                            */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_Truncate(FS_HANDLE FileHandle)
{
    DWORD pos, attributes;
    TCHAR strbuf[MAX_PATH];
    int FileSize, size_high;
 
    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_vfgen.link[FileHandle] > 0) /* virturl file; not normal file */

        return FS_READ_ONLY_ERROR;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].flags & FS_READ_ONLY)

        return FS_READ_ONLY_ERROR;

    /* get the current file pointer */

    pos = SetFilePointer(fssim_file[FileHandle].handle, 0, NULL, FILE_CURRENT);

    if (pos == 0) {

        /* file pointer is 0 */

        fssim_conv_fn(strbuf, fssim_file[FileHandle].filename);

        SetLastError(ERROR_SUCCESS);
        attributes = GetFileAttributes(strbuf);

        if (attributes & FILE_ATTRIBUTE_DIRECTORY)

            return FS_ACCESS_DENIED;
    }

    FileSize = GetFileSize(fssim_file[FileHandle].handle, &size_high);

    /* set end-of-file to truncate the file */
    if (SetEndOfFile(fssim_file[FileHandle].handle) == 0) {

        return fssim_conv_errcode(GetLastError(), "SetEndOfFile() failed in FS_Truncate()\n");

    } else {

        fssim_update_watermark_by_fh(&fssim_file[FileHandle], pos - FileSize);
        fssim_file[FileHandle].DirEntry.FileSize = pos;

        return FS_NO_ERROR;
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_MakeFileName                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get the file name (LFN or SFN) from a   */
/*      file handle.                                                     */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle   -   file handle                                     */
/*      Flag         -   FS_LONGNAME_ATTR or 0                           */
/*      FileName     -   buffer of file name                             */
/*      MaxLength    -   length of buffer                                */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_MakeFileName(FS_HANDLE FileHandle, UINT Flag, WCHAR *FileName, UINT MaxLength)
{
    TCHAR *pch, *pchOld, strbuf[MAX_PATH];

    /* verify parameters */
    if (MaxLength < ((8+3+1+1) * sizeof(TCHAR))) {

        return FS_PARAM_ERROR;
    }

    if (FileName == NULL) {

        return FS_PARAM_ERROR;
    }

    /* verify file handle */
    if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    /* convert file name */
    fssim_conv_fn(strbuf, fssim_file[FileHandle].filename);

    /* extract last name from the path */

    pch = wcsstr(strbuf, L"\\");

    pchOld = pch;

    while (pch != NULL) {

        pchOld = pch;

        pch = wcsstr(pch + 1, L"\\");
    }

    pch = (pchOld == NULL)? strbuf: pchOld + 1;

    if (Flag & FS_LONGNAME_ATTR) {

        /* long file name is required */

        if ((MaxLength / sizeof(TCHAR)) < wcslen(pch)) {

            /* buffer is not sufficient */

            /* NOP don't return since we need to copy short file name */
        } else {

            /* user buffer is sufficient */

            wcscpy(FileName, pch);

            return FS_NO_ERROR;
        }
    }

    /* short file name is required if we arrived here */
    fssim_copy_dosfilename_from_dosdirentry( FileName, &(fssim_file[FileHandle].DirEntry));

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Rename                                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to rename a file.                          */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileName   -   file name to be renamed                           */
/*      NewName    -   file name to rename                               */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_Rename(const WCHAR *FileName, const WCHAR *NewName)
{
    TCHAR strbuf1[MAX_PATH], strbuf2[MAX_PATH];
    const TCHAR *drive1, *drive2;
    int i;

    ASSERT(FileName != NULL && NewName != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    if (fssim_isopen(FileName)) {

        /* file 1 is opened */

        return FS_ACCESS_DENIED;
    }

    /* Stop irregular path input */
    if (wcslen(FileName) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf1, FileName);

    /* Stop irregular path input */
    if (wcslen(NewName) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf2, NewName);

    if (!fssim_is_name_valid(strbuf2)) {

        /* the file name is not valid */

        return FS_INVALID_FILENAME;

    }

    /* search drive index for path1 */

    i = fssim_locate_drive( FileName );

    if( i >= FSSIM_MAX_DRIVE ) {

        return FS_DRIVE_NOT_FOUND;

    } else if ( i < 0 ) {

        i = fssim_get_default_drive();
    }

    ASSERT(i >= 0 && i < FSSIM_MAX_DRIVE);

    drive1 = &(fssim_drvinfo[i].drive);

    /* search drive index for path 2 */

    i = fssim_locate_drive( NewName );

    if( i >= FSSIM_MAX_DRIVE ) {

        return FS_DRIVE_NOT_FOUND;

    } else if ( i < 0 ) {

        i = fssim_get_default_drive();
    }

    ASSERT(i >= 0 && i < FSSIM_MAX_DRIVE);

    drive2 = &(fssim_drvinfo[i].drive);

    /* cannot rename if file 1 and file 2 located on different drive */
    if (*drive1 != *drive2)

        return FS_ACCESS_DENIED;

    if (!fssim_is_file_exist(strbuf1)) {

        /* file 1 not found */
        return FS_FILE_NOT_FOUND;

    } else if (wcscmp(strbuf1, strbuf2)==0) {

        /* Same file name */
        return FS_NO_ERROR;

    } else if (fssim_is_file_exist(strbuf2)) {

        /* file 2 exists */
        return FS_FILE_EXISTS;
    }

    /* let's Move now */

    CRITICAL_SECTION_BEGIN;
    i = MoveFile(strbuf1, strbuf2);
    CRITICAL_SECTION_END;

    if (i == 0) {

        return fssim_conv_errcode(GetLastError(), "MoveFile() failed in FS_Rename()\n");

    } else {

        return FS_NO_ERROR;
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Move                                                          */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to move a file.                            */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      SrcFullPath   -   file name to be moved                          */
/*      DstFullPath   -   file name to move                              */
/*      Flag          -   flags                                          */
/*      Progress      -   callback function                              */
/*                                                                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_Move(const WCHAR * SrcFullPath, const WCHAR * DstFullPath, UINT Flag, FS_ProgressCallback Progress,
            BYTE *RecursiveStack, const UINT StackSize)
{
    TCHAR src[MAX_PATH], dst[MAX_PATH];
    int result = FS_NO_ERROR, fh = -1, drv_idx1, drv_idx2;
    int is_virtual;
    DWORD attributes, cnt, error;
    FSSIM_COPYDIR_PARAM_T copydir;

    ASSERT(SrcFullPath != NULL && DstFullPath != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    __try {

        if (Progress != NULL)

            Progress(FS_MOVE_PGS_PREPARE, 0, 0, 0);
        
        result = fssim_check_move_api_params(SrcFullPath, DstFullPath, Flag, &is_virtual);

        if (result != FS_NO_ERROR) {

            return result;
        }

        /* allocate a file handle for abort operation */

        fh = fssim_alloc_fh();

        if (fh == -1) {

            result = FS_TOO_MANY_FILES;

            return result;
        } else {

            fssim_file[fh].handle = INVALID_HANDLE_VALUE;

            fssim_file[fh].flags = Flag;

            fssim_file[fh].isabort = 0;

            wcscpy(fssim_file[fh].filename, SrcFullPath);

            fssim_file[fh].copyprogress = Progress;

            fssim_file[fh].findattr1 = fssim_file[fh].findattr2 = 0;

            memset(&(fssim_file[fh].DirEntry), 0, sizeof(FS_DOSDirEntry));
        }

        if (Progress != NULL) {

            Progress(FS_MOVE_PGS_START, 0, 0, 0);
        }

        /* operation start --- virtual file copy */
        if (is_virtual == 1)
        {
            result = FSUTIL_copy_file(SrcFullPath, DstFullPath);

            if (result != FS_NO_ERROR) {

                return result;
            }
            __leave;
        }

        /* operation start --- otherwise */
        fssim_conv_fn(src, SrcFullPath);
        fssim_conv_fn(dst, DstFullPath);

        if (Flag & FS_MOVE_KILL) {

            /* move operation */

            if (MoveFileWithProgress(src, dst, fssim_progress, (LPVOID)fh, MOVEFILE_REPLACE_EXISTING) == 0) {

                error = GetLastError();
            } else {

                error = ERROR_SUCCESS;
            }

        } else {

            /* copy operation */

            attributes = GetFileAttributes(src);

            if (attributes & FILE_ATTRIBUTE_DIRECTORY) {

                /* copy a directory */

                /* CopyFileEx cannot copy a directory */

                /* do all stuffs by myself */

                /* create the directory in the destination */

                if (!CreateDirectory(dst, NULL)) {

#ifdef DEBUG_FSSIM

                    if (GetLastError() != ERROR_ALREADY_EXISTS) {

                        fssim_printf(("CreateDirectory() failed in FS_Move()\n"));

                        fssim_printf(("error code = %d\n", GetLastError()));
                    }
#endif  /* DEBUG_FSSIM */
                }

                /* count the number of files and directories first */

                cnt = fssim_search_dir(src, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, NULL);

                /* initialize the parameter(copydir) of the callback function(fssim_copy_dir) */

                copydir.completed = 0;

                copydir.fh = fh;

                wcscpy(copydir.path, dst);

                copydir.total = cnt;

                /* perform copy operation this time */

                cnt = fssim_search_dir(src, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, fssim_copy_dir, &copydir);

                if (cnt != copydir.total) {

                    /* some files are not copied since the operation is aborted */

                    return FS_ABORTED_ERROR;

                } else {

                    error = ERROR_SUCCESS;
                }

            } else {

                /* copy a file */

                /* invoke CopyFileEx directly */

                if (CopyFileEx(src, dst, fssim_progress, (LPVOID)fh, NULL, 0) == 0) {

                    error = GetLastError();

                } else {

                    error = ERROR_SUCCESS;
                }

            }
        }

        if (error != ERROR_SUCCESS)

            return fssim_conv_errcode(error, "MoveFileWithProgress()/CopyFileEx() failed in FS_Move()\n");

        else

            return FS_NO_ERROR;

    }
    __finally {

        if (Progress != NULL) {

            if (result < FS_NO_ERROR)

                Progress(FS_MOVE_PGS_FAIL, 0, 0, 0);

            else

                Progress(FS_MOVE_PGS_DONE, 0, 0, 0);
        }

        if (fh != -1) {

            fssim_file[fh].handle= INVALID_HANDLE_VALUE;

            fssim_free_fh(fh);
        }

        /* Reset the Drive's watermark */
        drv_idx2 = fssim_locate_drive( DstFullPath );
        drv_idx1 = fssim_locate_drive( SrcFullPath );

        fssim_get_drive_watermark(&fssim_drvinfo[drv_idx2]);

        if (drv_idx1 != drv_idx2 && drv_idx1 >= 0) {

            fssim_get_drive_watermark(&fssim_drvinfo[drv_idx1]);
        }

    }

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_Count                                                         */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to count files and directories in a folder.*/
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FullPath   -   the folder to count                               */
/*      Flag       -   flags                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Number of couting result or error code                           */
/*                                                                       */
/*************************************************************************/
int FS_Count(const WCHAR *FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
    TCHAR strbuf[MAX_PATH];
    DWORD attributes;

    ASSERT(FullPath != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    /* verify Flag */

    if (((Flag & FS_FILE_TYPE) == 0) && ((Flag & FS_DIR_TYPE) == 0) && 
        ((Flag & FS_RECURSIVE_TYPE) == 0))

        return FS_PARAM_ERROR;

    else if (Flag & ~(FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE | FS_FILTER_SYSTEM_ATTR | FS_FILTER_HIDDEN_ATTR))

        return FS_PARAM_ERROR;


    /* Stop irregular path input */
    if (wcslen(FullPath) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf, FullPath);

    if (!fssim_is_name_valid(strbuf))

        /* the folder name is not valid */

        return FS_INVALID_FILENAME;

    else if (!fssim_is_file_exist(strbuf))

        /* the folder doesn't exist */

        return FS_PATH_NOT_FOUND;

    CRITICAL_SECTION_BEGIN;
    attributes = GetFileAttributes(strbuf);
    CRITICAL_SECTION_END;

    if ((attributes & FILE_ATTRIBUTE_DIRECTORY) == 0)

        /* not a folder */

        return FS_PARAM_ERROR;

    return fssim_search_dir(strbuf, Flag, NULL, NULL);
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_XDelete                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to delete files/directories in a folder.   */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FullPath   -   the folder to delete                              */
/*      Flag       -   flags                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Number of deleted files or error code                            */
/*                                                                       */
/*************************************************************************/
int FS_XDelete(const WCHAR *FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
    TCHAR strbuf[MAX_PATH];
    DWORD attributes;
    int result, drv_idx;

    ASSERT(FullPath != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    /* verify Flag */

    if (((Flag & FS_FILE_TYPE) == 0) && ((Flag & FS_DIR_TYPE) == 0) && 
        ((Flag & FS_RECURSIVE_TYPE) == 0))

        return FS_PARAM_ERROR;

    else if (Flag & ~(FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE))

        return FS_PARAM_ERROR;


    /* Stop irregular path input */
    if (wcslen(FullPath) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf, FullPath);

    if (!fssim_is_name_valid(strbuf))

        /* the folder name is not valid */

        return FS_INVALID_FILENAME;

    else if (!fssim_is_file_exist(strbuf))

        /* the folder doesn't exist */

        return FS_PATH_NOT_FOUND;

    CRITICAL_SECTION_BEGIN;
    attributes = GetFileAttributes(strbuf);
    CRITICAL_SECTION_END;

    if ((attributes & FILE_ATTRIBUTE_DIRECTORY) == 0)

        /* not a folder */

        return FS_PARAM_ERROR;

    if ((Flag & FS_DIR_TYPE) == 0) {

        result = fssim_search_dir(strbuf, Flag, fssim_del_files, NULL);

    } else {

        result = fssim_search_dir(strbuf, Flag, fssim_del_dir, NULL);

        /* Don't Forget to Remove *this* Direcotry if Recursive Flag ON */
        if ((Flag & FS_RECURSIVE_TYPE) && (RemoveDirectory(strbuf) == 0)) {

#ifdef DEBUG_FSSIM
            fssim_printf(("RemoveDirectory() failed in FS_XDelete()\n"));

            fssim_printf(("error code = %d\n", GetLastError()));
#endif  /* DEBUG_FSSIM */

        }

    }

    /* Now, Let's re-calculate the drive's watermark */
    drv_idx = fssim_locate_drive( FullPath );
    fssim_get_drive_watermark(&fssim_drvinfo[drv_idx]);

    return result;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_FindFirst                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to find a file.                            */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      NamePattern   -   pattern of file name to search (may contain    */
/*                        "*" or "?")                                    */
/*      Attr          -   a set of file attributes to match              */
/*      AttrMask      -   a set of file attributes not to match          */
/*      FileInfo      -   a pointer to FS_DOSDirEntry structure          */
/*      FileName      -   buffer to store the found file                 */
/*      MaxLength     -   length of the FileName buffer                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      File handle or error code                                        */
/*                                                                       */
/*************************************************************************/
int FS_FindFirst(const WCHAR *NamePattern, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry *FileInfo, WCHAR *FileName, UINT MaxLength)
{
    TCHAR strbuf[MAX_PATH];
    HANDLE hSearch;
    WIN32_FIND_DATA data;
    DWORD attr1, attr2, error;
    int is_found;
    FS_HANDLE fh;

    ASSERT(NamePattern != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    /* Stop irregular path input */
    if (wcslen(NamePattern) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf, NamePattern);

    CRITICAL_SECTION_BEGIN;
    hSearch = FindFirstFile(strbuf, &data);
    CRITICAL_SECTION_END;

    if (hSearch == INVALID_HANDLE_VALUE) {

#ifdef DEBUG_FSSIM

        error = GetLastError();

        if (error != ERROR_FILE_NOT_FOUND) {

            fssim_printf(("FindFirstFile() failed in FS_FindFirst()\n"));

            fssim_printf(("error code = %d\n", GetLastError()));
        }

#endif  /* DEBUG_FSSIM */

        return FS_NO_MORE_FILES;
    }

    /* convert attributes */

    attr1 = fssim_conv_attr(Attr);

    attr2 = fssim_conv_attr(AttrMask);

    /* OR two attributes to get the full set */

    attr2 |= attr1;

    is_found = 0;

    while (1) {

        if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {

            if (wcscmp(data.cFileName, L".") == 0 || wcscmp(data.cFileName, L"..") == 0) {

                /* nop */

            } else if ((data.dwFileAttributes & attr2) == attr1) {

                /* match the specified attributes */

                is_found = 1;

                break;

            }

        } else if ((data.dwFileAttributes & attr2) == attr1) {

            /* match the specified attributes */

            is_found = 1;

            break;
        }

        CRITICAL_SECTION_BEGIN;
        error = FindNextFile(hSearch, &data);
        CRITICAL_SECTION_END;

        if (!error) {

            error = GetLastError();

            if (error != ERROR_NO_MORE_FILES) {

#ifdef DEBUG_FSSIM

                fssim_printf(("FindNextFile() failed in FS_FindFirst()\n"));

                fssim_printf(("error code = %d\n", error));

#endif  /* DEBUG_FSSIM */
            }

            is_found = 0;

            break;
        }

    }

    if (is_found == 1) {

        /* find the file */

        /* allocate a file handle */

        fh = fssim_alloc_fh();

        if (fh == -1) {

            /* there is no more file handle available */

            if (!FindClose(hSearch)) {

#ifdef DEBUG_FSSIM

                fssim_printf(("FindClose() failed in FS_FindFirst()\n"));

                fssim_printf(("error code = %d\n", GetLastError()));

#endif  /* DEBUG_FSSIM */
            }

            return FS_TOO_MANY_FILES;
        }

        fssim_file[fh].handle = hSearch;

        fssim_file[fh].flags = FS_OPEN_DIR | FS_READ_ONLY | FS_CACHE_DATA;

        fssim_file[fh].isabort = 0;

        wcscpy(fssim_file[fh].filename, NamePattern);

        fssim_file[fh].copyprogress = NULL;

        fssim_file[fh].findattr1 = Attr;

        fssim_file[fh].findattr2 = AttrMask;

        memset(&(fssim_file[fh].DirEntry), 0, sizeof(FS_DOSDirEntry));
        
        /* setup DosDirEntry data structure from win32 find data */

        fssim_conv_direntry_from_win32_find(FileInfo, &data);

        /* set FileName buffer from win32 find data with buffer length limitation */

        FileInfo->NTReserved = 
        fssim_copy_filename_from_win32_find(FileName, &data, MaxLength / sizeof(TCHAR));

        return fh;

    } else {

        /* cannot find any file */

        if (!FindClose(hSearch)) {

#ifdef DEBUG_FSSIM

            fssim_printf(("FindClose() failed in FS_FindFirst()\n"));

            fssim_printf(("error code = %d\n", GetLastError()));

#endif  /* DEBUG_FSSIM */
        }

        return FS_NO_MORE_FILES;
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_FindNext                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to find a file.                            */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle   -   file handle returned from FS_FindFirst          */
/*      FileInfo     -   a pointer to FS_DOSDirEntry structure           */
/*      FileName     -   buffer to store the found file                  */
/*      MaxLength    -   length of the FileName buffer                   */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_FindNext(FS_HANDLE FileHandle, FS_DOSDirEntry *FileInfo, WCHAR *FileName, UINT MaxLength)
{
    DWORD attr1, attr2;
    int is_found;
    WIN32_FIND_DATA data;
    DWORD  error;

    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].isabort == 1)

        return FS_ABORTED_ERROR;

    /* convert attributes */

    attr1 = fssim_conv_attr((BYTE)fssim_file[FileHandle].findattr1);

    attr2 = fssim_conv_attr((BYTE)fssim_file[FileHandle].findattr2);

    /* OR two attributes to get the full set */

    attr2 |= attr1;

    is_found = 0;

    do {

        CRITICAL_SECTION_BEGIN;
        error = FindNextFile(fssim_file[FileHandle].handle, &data);
        CRITICAL_SECTION_END;

        if (!error) {

            error = GetLastError();

            if (error != ERROR_NO_MORE_FILES) {

#ifdef DEBUG_FSSIM

                fssim_printf(("FindNextFile() failed in FS_FindNext()\n"));

                fssim_printf(("error code = %d\n", error));

#endif  /* DEBUG_FSSIM */
            }

            is_found = 0;

            break;
        }

        if (data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {

            if (wcscmp(data.cFileName, L".") == 0 || wcscmp(data.cFileName, L"..") == 0)

                continue;
        }

        if ((data.dwFileAttributes & attr2) == attr1) {

            /* match the specified attributes */

            is_found = 1;

            break;
        }

    } while (1);

    if (is_found == 1) {

        /* find the file */
        
        /* setup DosDirEntry data structure from win32 find data */

        fssim_conv_direntry_from_win32_find(FileInfo, &data);

        /* set FileName buffer from win32 find data with buffer length limitation */

        FileInfo->NTReserved = 
        fssim_copy_filename_from_win32_find(FileName, &data, MaxLength / sizeof(TCHAR));

        return FS_NO_ERROR;

    } else {

        return FS_NO_MORE_FILES;
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_FindClose                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to close a file handle returned from       */
/*      FS_FindFirst.                                                    */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle   -   file handle returned from FS_FindFirst          */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_FindClose(FS_HANDLE FileHandle)
{
    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    if (!FindClose(fssim_file[FileHandle].handle)) {

#ifdef DEBUG_FSSIM

        fssim_printf(("FindClose() failed in FS_FindClose()\n"));

        fssim_printf(("error code = %d\n", GetLastError()));

#endif  /* DEBUG_FSSIM */
    }

    fssim_file[FileHandle].handle= INVALID_HANDLE_VALUE;

    fssim_free_fh(FileHandle);

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_FindFirstN                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to find N-th file.                         */
/*      NoteXXX: The searching rule is just like FS_FindFirst.           */
/*               But each file should either contain an attribute        */
/*               specified in ArrayMask or match patterns specified      */
/*               in PatternArray.                                        */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      NamePattern    -   pattern of file name to search (may contain   */
/*                         "*" or "?") and must contain a drive name     */
/*      PatternArray   -   array of extra patterns                       */
/*      PatternNum     -   number of elements in PatternArray            */
/*      ArrayMask      -   an extra set of file attributes to match      */
/*      Attr           -   a set of file attributes to match             */
/*      AttrMask       -   a set of file attributes not to match         */
/*      FileInfo       -   a pointer to FS_DOSDirEntry structure         */
/*      FileName       -   buffer to store the found file                */
/*      MaxLength      -   length of the FileName buffer                 */
/*      EntryIndex     -   specify N(N-th file to find)                  */
/*      Flag           -   flag for getting file name                    */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      File handle or error code                                        */
/*                                                                       */
/*************************************************************************/
int FS_FindFirstN(const WCHAR *NamePattern, FS_Pattern_Struct *PatternArray, UINT PatternNum,
                  BYTE ArrayMask, BYTE Attr, BYTE AttrMask, FS_DOSDirEntry *FileInfo,
                  WCHAR *FileName, UINT MaxLength, UINT EntryIndex, UINT Flag)
{
    int f, retval, is_found;
    unsigned int i, cnt;
    TCHAR strbuf[MAX_PATH];

    ASSERT(NamePattern != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    if (PatternNum >= 1)

        ASSERT(PatternArray != NULL);

    /* extract first 3 words */

    wcsncpy(strbuf, NamePattern, wcslen(L"?:\\"));
    
    *(strbuf + wcslen(L"?:\\")) = 0;
    
    if (fssim_match_pattern(L"?:\\", strbuf) == 0) {

        /* no drive name is specified */

        return FS_PARAM_ERROR;
    }

    cnt = 0;

    is_found = 0;

    f = FS_FindFirst(NamePattern, Attr, AttrMask, FileInfo, strbuf, MAX_PATH * sizeof(TCHAR));

    if (f < 0) {

        return f;
    }

    __try {

        do {

            /* check if need to match ArrayMask or PatternArray[] */
            if (PatternNum == 0) {

                /* don't have to check anymore */

                if (cnt == EntryIndex) {

                    is_found = 1;

                    return f;
                } else {

                    cnt++;
                }
            }

            if (FileInfo->Attributes & ArrayMask) {

                /* the found file contains attributes specified in ArrayMask */

                if (cnt == EntryIndex) {

                    is_found = 1;

                    return f;
                } else {

                    cnt++;
                }
            } else {

                /* check if the filename matches patterns specified in PatternArray */

                for (i = 0; i < PatternNum; i++) {

                    if (PatternArray[i].Pattern == NULL) {

                        return FS_PARAM_ERROR;
                    }

                    if (fssim_match_pattern(PatternArray[i].Pattern, strbuf) == 1) {

                        /* match patterns specified in PatternArray */

                        if (cnt == EntryIndex) {

                            is_found = 1;

                            return f;
                        } else {

                            cnt++;
                        }
                    }
                }   /* for () */

            }

            retval = FS_FindNext(f, FileInfo, strbuf, MAX_PATH * sizeof(TCHAR));

            if (retval != FS_NO_ERROR)

                return retval;
        } while (1);

    }   /* __try */
    __finally {

        if (is_found == 0) {

            /* no file can be found */

            FS_FindClose(f);
        } else {

            /* copy strbuf to FileName */

            if ((MaxLength / sizeof(TCHAR) - 1) < wcslen(strbuf)) {

                /* user buffer is not sufficient */

                if (Flag == FS_FIND_LFN_TRUNC) {

                    wcsncpy(FileName, strbuf, MaxLength / sizeof(TCHAR) - 1);
                    FileName[ (MaxLength / sizeof(TCHAR)) - 1] = '\0';

                } else {

                    /* short file name is required if we arrived here */
                    /* NoteXXX : NTReserved flag always LFN_Match
                     *           since we call FS_FindFirst() with MAX_PATH length buffer
                     */

                    ASSERT(MaxLength >= sizeof(TCHAR) * (8 + 1 + 3 + 1));
                    fssim_copy_dosfilename_from_dosdirentry(FileName, FileInfo);
                }

            } else {

                /* user buffer is sufficient */

                wcscpy(FileName, strbuf);
            }
        }
    }

    /*
     * NoteXXX: Below code should not be executed.
     *          They are added to eliminate compile errors.
     */

    ASSERT(0);

    return FS_NO_MORE_FILES;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_FindNextN                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to find N-th file.                         */
/*      NoteXXX: The searching rule is just like FS_FindNext.            */
/*               But each file should either contain an attribute        */
/*               specified in ArrayMask or match patterns specified      */
/*               in PatternArray.                                        */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      NamePattern    -   pattern of file name to search (may contain   */
/*                         "*" or "?") and must contain a drive name     */
/*      PatternArray   -   array of extra patterns                       */
/*      PatternNum     -   number of elements in PatternArray            */
/*      ArrayMask      -   an extra set of file attributes to match      */
/*      FileInfo       -   a pointer to FS_DOSDirEntry structure         */
/*      FileName       -   buffer to store the found file                */
/*      MaxLength      -   length of the FileName buffer                 */
/*      Flag           -   flag for getting file name                    */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      File handle or error code                                        */
/*                                                                       */
/*************************************************************************/
int FS_FindNextN(FS_HANDLE Handle, FS_Pattern_Struct * PatternArray, UINT PatternNum, 
                 BYTE ArrayMask, FS_DOSDirEntry *FileInfo, WCHAR *FileName, UINT MaxLength, UINT Flag)
{
    int retval, is_found;
    unsigned int i;
    TCHAR strbuf[MAX_PATH];

    if (PatternNum >= 1)

        ASSERT(PatternArray != NULL);

    __try {

        is_found = 0;

        do {

            retval = FS_FindNext(Handle, FileInfo, strbuf, MAX_PATH * sizeof(TCHAR));

            if (retval != FS_NO_ERROR)

                return retval;

            /* check if need to match ArrayMask or PatternArray[] */
            if (PatternNum == 0) {

                /* don't have to check anymore */

                is_found = 1;

                return FS_NO_ERROR;
            }

            if (FileInfo->Attributes & ArrayMask) {

                /* the found file contains attributes specified in ArrayMask */

                is_found = 1;

                return FS_NO_ERROR;
            } else {

                /* check if the filename matches patterns specified in PatternArray */

                for (i = 0; i < PatternNum; i++) {

                    if (PatternArray[i].Pattern == NULL) {

                        return FS_PARAM_ERROR;
                    }

                    if (fssim_match_pattern(PatternArray[i].Pattern, strbuf) == 1) {

                        /* match patterns specified in PatternArray */

                        is_found = 1;

                        return FS_NO_ERROR;
                    }
                }   /* for () */

            }

        } while (1);
    }   /* __try */
    __finally {

        if (is_found == 1) {

            /* copy strbuf to FileName */

            if ((MaxLength / sizeof(TCHAR) - 1) < wcslen(strbuf)) {

                /* user buffer is not sufficient */

                if (Flag == FS_FIND_LFN_TRUNC) {

                    wcsncpy(FileName, strbuf, MaxLength / sizeof(TCHAR) - 1);
                    FileName[ (MaxLength / sizeof(TCHAR)) - 1] = '\0';

                } else {

                    /* short file name is required if we arrived here */
                    /* NoteXXX : NTReserved flag always LFN_Match
                     *           since we call FS_FindNext() with MAX_PATH length buffer
                     */

                    ASSERT(MaxLength >= sizeof(TCHAR) * (8 + 1 + 3 + 1));
                    fssim_copy_dosfilename_from_dosdirentry(FileName, FileInfo);
                }

            } else {

                /* user buffer is sufficient */

                wcscpy(FileName, strbuf);
            }
        }
    }

    /*
     * NoteXXX: Below code should not be executed.
     *          They are added to eliminate compile errors.
     */

    ASSERT(0);

    return FS_NO_MORE_FILES;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_XFindReset                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to sort finding files.                     */
/*      NoteXXX: The searching rule is just like FS_FindFirst.           */
/*               But each file should either contain an attribute        */
/*               specified in ArrayMask or match patterns specified      */
/*               in PatternArray.                                        */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      Pattern        -   pattern of file name to search (may contain   */
/*                         "*" or "?") and must contain a drive name     */
/*      PatternArray   -   array of extra patterns                       */
/*      PatternNum     -   number of elements in PatternArray            */
/*      ArrayMask      -   an extra set of file attributes to match      */
/*      AttrMask       -   a set of file attributes not to match         */
/*      Flag           -   flags                                         */
/*      Timeout        -   flag for infinate waiting or no wait          */
/*      Position       -   pointer to internal memory storing results    */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Number of sorting results or error code                          */
/*                                                                       */
/*************************************************************************/
int FS_XFindReset(const WCHAR *Pattern, FS_Pattern_Struct *PatternArray, UINT PatternNum,
                  BYTE ArrayMask, BYTE AttrMask, UINT Flag, UINT Timeout, UINT *Position)
{
    TCHAR strbuf[MAX_PATH];
    int cnt, f, result;
    FS_DOSDirEntry info;

    ASSERT(Pattern != NULL);

    if (fssim_sort_mutex == NULL) {

        fssim_init();
    }

    if (PatternNum >= 1)

        ASSERT(PatternArray != NULL);

    /* extract first 3 words */

    wcsncpy(strbuf, Pattern, wcslen(L"?:\\"));
    
    *(strbuf + wcslen(L"?:\\")) = 0;
    
    if (fssim_match_pattern(L"?:\\", strbuf) == 0) {

        /* no drive name is specified */

        return FS_PARAM_ERROR;
    }

    /* verify flags */

    if ((Flag & FS_FILE_TYPE) == 0 && (Flag & FS_DIR_TYPE) == 0)

        return FS_PARAM_ERROR;
         
    if ((Flag & FS_NO_SORT) == 0 && (Flag & FS_SORT_NAME) == 0 &&
      (Flag & FS_SORT_SIZE) == 0 && (Flag & FS_SORT_ATTR) == 0 &&
      (Flag & FS_SORT_TIME) == 0 && (Flag & FS_SORT_TYPE) == 0)

        return FS_PARAM_ERROR;
   
    if (Flag & ~(FS_FILE_TYPE | FS_DIR_TYPE | FS_NO_SORT | FS_SORT_NAME | FS_SORT_SIZE | FS_SORT_ATTR | FS_SORT_TIME | FS_SORT_TYPE))

       return FS_PARAM_ERROR;


    result = 0;

    cnt = 0;

    if (fssim_sort_cnt != 0) {

        /* XXX Simulator semaphore not ready, so return FS_ACCESS_DENIED for all attempt */
        return FS_ACCESS_DENIED;

        /* there is some one executing FS_XFindxxx */

        if (Timeout == FS_NO_WAIT)

            return FS_LOCK_MUTEX_FAIL;
    }

    __try {

        fssim_take_mutex(fssim_sort_mutex); /* sort feature mutex --- BEGIN */

        f = FS_FindFirstN(Pattern, PatternArray, PatternNum, ArrayMask, 0, AttrMask, &info, strbuf, MAX_PATH * sizeof(TCHAR), 0, FS_FIND_DEFAULT);

        if (f < 0) {

            result = f;

            return result;
        }

        if (((info.Attributes & FS_ATTR_DIR) && (Flag & FS_DIR_TYPE)) ||
            (!(info.Attributes & FS_ATTR_DIR) && (Flag & FS_FILE_TYPE))) {

            /* store the finding file or directory */     

            wcscpy(fssim_sort[cnt].filename, strbuf);

            memcpy(&(fssim_sort[cnt].fileinfo), &info, sizeof(FS_DOSDirEntry));

            cnt++;
        }

        do {

            result = FS_FindNextN(f, PatternArray, PatternNum, ArrayMask, &info, strbuf, MAX_PATH * sizeof(TCHAR), FS_FIND_DEFAULT);

            if (result == FS_NO_ERROR) {

                /* find a file or directory */

                if (((info.Attributes & FS_ATTR_DIR) && (Flag & FS_DIR_TYPE)) ||
                    (!(info.Attributes & FS_ATTR_DIR) && (Flag & FS_FILE_TYPE))) {

                    /* store the finding result */

                    wcscpy(fssim_sort[cnt].filename, strbuf);

                    memcpy(&(fssim_sort[cnt].fileinfo), &info, sizeof(FS_DOSDirEntry));

                    cnt++;
                }

                if (cnt >= MT_MAX_FILE_NUM) {

                    /* too many files */

                    result = FS_TOO_MANY_FILES;

                    return result;

                }
            } else if (result != FS_NO_MORE_FILES) {

                /* there is error */

                return result;
            }

        } while (result != FS_NO_MORE_FILES);

        /* now we have all finding results stored in fssim_sort */

#ifdef __MMI_LVM__
{
		/* in the local voice memory list, the latest record is on the top */
		extern unsigned char LVM_InRecordList(void);
		if (LVM_InRecordList()) {
			Flag = FS_SORT_TIME;
		}
}
#endif
        /* sort finding results */

        if (Flag & FS_NO_SORT)

            /* only let directories prioir to files */

            qsort(fssim_sort, cnt, sizeof(FSSIM_SORT_T), fssim_comp_none);

        else if (Flag & FS_SORT_NAME)

            /* sort by name */

            qsort(fssim_sort, cnt, sizeof(FSSIM_SORT_T), fssim_comp_name);

        else if (Flag & FS_SORT_TYPE)

            /* sort by type */

            qsort(fssim_sort, cnt, sizeof(FSSIM_SORT_T), fssim_comp_type);

        else if (Flag & FS_SORT_ATTR)

            /* sort by attributes */

            qsort(fssim_sort, cnt, sizeof(FSSIM_SORT_T), fssim_comp_attr);

        else if (Flag & FS_SORT_SIZE)

            /* sort by size */

            qsort(fssim_sort, cnt, sizeof(FSSIM_SORT_T), fssim_comp_size);

        else if (Flag & FS_SORT_TIME)

            /* sort by time */

            qsort(fssim_sort, cnt, sizeof(FSSIM_SORT_T), fssim_comp_time);

        else

            ASSERT(0);

        result = cnt;
    }
    __finally {

        if (f >= 0)

            FS_FindClose(f);

        if (result < 0)

            /* there is error */

            fssim_give_mutex(fssim_sort_mutex); /* sort feature mutex --- END */

        else {

            fssim_sort_cnt = cnt;

            *Position = (DWORD)fssim_sort;
        }
    }

    return result;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_XFindStart                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get sorted files.                       */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      Pattern     -   pattern of file name to search (may contain      */
/*                         "*" or "?") and must contain a drive name     */
/*      FileInfo    -   a pointer to FS_DOSDirEntry structure            */
/*      FileName    -   buffer to store the found file                   */
/*      MaxLength   -   length of the FileName buffer                    */
/*      Index       -   index of sorting results                         */
/*      Position    -   pointer gotten from FS_XFindReset                */
/*      Flag        -                                                    */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      next index or error code                                         */
/*                                                                       */
/*************************************************************************/
int FS_XFindStart(const WCHAR *Pattern, FS_DOSDirEntry *FileInfo, WCHAR *FileName,
                  UINT MaxLength, UINT Index, UINT *Position, UINT Flag)
{
    ASSERT(FileName != NULL);

    ASSERT(Position != NULL);

    ASSERT(*Position == (DWORD)fssim_sort);

    if (fssim_sort_cnt <= 0)

        return FS_ACCESS_DENIED;

    if (Index >= (DWORD)fssim_sort_cnt)

        return FS_NO_MORE_FILES;

    /* copy FileInfo */

    memcpy(FileInfo, &(fssim_sort[Index].fileinfo), sizeof(FS_DOSDirEntry));

    /* copy file name */

    if ((MaxLength / sizeof(TCHAR) - 1) < wcslen(fssim_sort[Index].filename)) {

        /* user buffer is not sufficient */

        if (Flag == FS_FIND_LFN_TRUNC) {

            wcsncpy(FileName, fssim_sort[Index].filename, MaxLength / sizeof(TCHAR) - 1);
            FileName[ (MaxLength / sizeof(TCHAR)) - 1] = '\0';

        } else {

            /* short file name is required if we arrived here */
            /* NoteXXX : NTReserved flag always LFN_Match
             *           since we call FS_FindFirst() FS_FindNext() with MAX_PATH length buffer
             */

            ASSERT(MaxLength >= sizeof(TCHAR) * (8 + 1 + 3 + 1));
            fssim_copy_dosfilename_from_dosdirentry(FileName, FileInfo);
        }

    } else {

        /* user buffer is sufficient */

        wcscpy(FileName, fssim_sort[Index].filename);
    }

    Index++;

    return Index;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_XFindClose                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to close a sorting.                        */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      Position   -   pointer gotten from FS_XFindReset                 */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_XFindClose(UINT *Position)
{
    ASSERT(Position != NULL);

    ASSERT(*Position == (DWORD)fssim_sort);

    fssim_sort_cnt = 0;

    fssim_give_mutex(fssim_sort_mutex); /* sort feature mutex --- END */

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_CreateMasterBootRecord                                        */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      SectorBuffer   -  no use                                         */
/*      DiskGeometry   -  no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_CreateMasterBootRecord(void *SectorBuffer, const FS_PartitionRecord *DiskGeometry)
{
    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetPartitionInfo                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get the information about a partition.  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DriveName       -   name of the drive to get information         */
/*      PartitionInfo   -   pointer to a FS_PartitionInfo structure      */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_GetPartitionInfo(const WCHAR *DriveName, FS_PartitionRecord *PartitionInfo)
{
    TCHAR strbuf[MAX_PATH], drive;
    int i, offset;

    ASSERT(DriveName != NULL && PartitionInfo != NULL);

    /* extract the drive name from DriveName */

    wcsncpy(strbuf, DriveName, wcslen(L"?:\\"));

    if (fssim_match_pattern(L"?:\\", strbuf) == 0) {

        /* the drive name is not specified */

        /* use the current directory */

        for (i = 0; i < FSSIM_MAX_DRIVE; i++) {

            if (fssim_drvinfo[i].is_current) {

                drive = fssim_drvinfo[i].drive;

                break;
            }
        }
    } else {

        /* the drive name is specified */

        drive = strbuf[0];
    }

    ASSERT(drive != 0);

    /* get drive number */

    offset = (char)drive - (char)FSSIM_SYSTEM_DRIVE;

    if ((char)drive >= 'c' && (char)drive <= 'z') {

        /* the first drive letter is lowercase */

        offset -= ('c' - 'C');
    }

    if (offset >= FSSIM_MAX_DRIVE) {

        /* drive number exceeds the maximum */

        return FS_DRIVE_NOT_FOUND;
    } else {

        memcpy(PartitionInfo, &(fssim_partition[offset]), sizeof(FS_PartitionRecord));
    }

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_CommitAll                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to flush dirty buffers to the disk.        */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DriveName   -   name of the drive to commit                      */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_CommitAll(const WCHAR *DriveName)
{
    int i;

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    fssim_take_mutex(fssim_mutex); /* critical section { */

    for (i = 1; i <= FSSIM_MAX_FILE; i++) {

        if (fssim_file[i].state == STATE_INUSE && fssim_file[i].handle != INVALID_HANDLE_VALUE)

            FlushFileBuffers(fssim_file[i].handle);
    }

    fssim_give_mutex(fssim_mutex); /* critical section } */

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetDrive                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get drive letter of the specific drive. */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      Type      -   drive type                                         */
/*      Serial    -   drive number                                       */
/*      AltMask   -   alternative drive                                  */
/*                                                                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Drive name or error code                                         */
/*                                                                       */
/*************************************************************************/
int FS_GetDrive(UINT Type, UINT Serial, UINT AltMask)
{
    int DriveMap[5], Result;

    /* verify parameters */

    if (((Type & (FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE)) == 0) ||
        ((Type & ~(FS_DRIVE_I_SYSTEM | FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE)) != 0) || 
        ((Type != FS_DRIVE_V_REMOVABLE) && (Serial > 2)) || 
        ((Type == FS_DRIVE_V_REMOVABLE) && (Serial > 1)) || 
        (Serial < 1) ||
        ((AltMask != FS_NO_ALT_DRIVE) && (AltMask & FS_NO_ALT_DRIVE)) ||
        ((AltMask != FS_ONLY_ALT_SERIAL) && (AltMask & FS_ONLY_ALT_SERIAL)))

        return FS_PARAM_ERROR;

    memset(DriveMap, 0, sizeof(int) * 5);

    switch (FSSIM_MAX_DRIVE) {
    
    case 5: /* 221 */

        DriveMap[0] = 'C';
        DriveMap[1] = 'D';
        DriveMap[2] = 'E';
        DriveMap[3] = 'F';
        DriveMap[4] = 'G';

        break;

    case 4:

        if (FSSIM_NORFLASH_CNT == 2) {

            if (FSSIM_NANDFLASH_CNT == 2) { /* 220 */

                DriveMap[0] = 'C';
                DriveMap[1] = 'D';
                DriveMap[2] = 'E';
                DriveMap[3] = 'F';
            } else { /* 211 */

                DriveMap[0] = 'C';
                DriveMap[1] = 'D';
                DriveMap[2] = 'E';
                DriveMap[4] = 'F';
            }
        } else { /* 121 */

            DriveMap[0] = 'D';
            DriveMap[2] = 'C';
            DriveMap[3] = 'E';
            DriveMap[4] = 'F';
        }

        break;

    case 3:

        if (FSSIM_NORFLASH_CNT == 2) {

            if (FSSIM_NANDFLASH_CNT == 0) { /* 201 */

                DriveMap[0] = 'C';
                DriveMap[2] = 'D';
                DriveMap[4] = 'E';
            } else { /* 210 */

                DriveMap[0] = 'C';
                DriveMap[1] = 'D';
                DriveMap[2] = 'E';
            }
        } else if (FSSIM_NORFLASH_CNT == 1) {

            if (FSSIM_NANDFLASH_CNT == 2) { /* 120 */

                DriveMap[0] = 'D';
                DriveMap[2] = 'C';
                DriveMap[3] = 'E';
            } else { /* 111 */

                DriveMap[0] = 'D';
                DriveMap[2] = 'C';
                DriveMap[4] = 'E';
            }
        } else { /* 021 */

            DriveMap[0] = 'C';
            DriveMap[2] = 'D';
            DriveMap[4] = 'E';
        }

        break;

    case 2:

        if (FSSIM_NORFLASH_CNT == 2) { /* 200 */

            DriveMap[0] = 'C';
            DriveMap[2] = 'D';
        } else if (FSSIM_NORFLASH_CNT == 1) {

            if (FSSIM_NANDFLASH_CNT == 1) { /* 110 */

                DriveMap[0] = 'D';
                DriveMap[2] = 'C';
            } else { /* 101 */

                DriveMap[2] = 'C';
                DriveMap[4] = 'D';
            }
        } else {
            if (FSSIM_NANDFLASH_CNT == 2) { /* 020 */

                DriveMap[0] = 'C';
                DriveMap[2] = 'D';
            }else { /* 011 */

                DriveMap[2] = 'C';
                DriveMap[4] = 'D';
            }
        }
        break;

    default:

        DriveMap[2] = 'C';

        break;
    }

    /* match type first */

    Result = -1;

    switch (Type) {

    case FS_DRIVE_I_SYSTEM:
            
        /* Match system drive */

        if (DriveMap[Serial + 1] != 0)

            Result = DriveMap[Serial + 1];

        break;

    case FS_DRIVE_V_NORMAL:
        
        /* Match normal drive */

        if (DriveMap[Serial - 1] != 0)

            Result = DriveMap[Serial - 1];

        break;

    case FS_DRIVE_V_REMOVABLE:
        
        /* Match removable drive */
        if (DriveMap[4] != 0)

            Result = DriveMap[4];

        break;

    default:

        return FS_PARAM_ERROR;

        break;
    }

    if (Result == -1 && (AltMask & FS_NO_ALT_DRIVE))

        return FS_DRIVE_NOT_FOUND;     

   
    /* match serial then */

    if (Result == -1 && (AltMask & FS_ONLY_ALT_SERIAL)) {

        switch (Type) {

        case FS_DRIVE_I_SYSTEM:
            
            /* Match system drive */

            if ((Serial == 1) && (DriveMap[Serial + 1] != 0))

               Result = DriveMap[Serial+1];

            else if((Serial == 2) && (DriveMap[Serial] != 0))

               Result = DriveMap[Serial];

            break;

         case FS_DRIVE_V_NORMAL:
             
            /* Match normal drive */

            if((Serial == 1) && (DriveMap[Serial] != 0))

               Result = DriveMap[Serial];

            else if((Serial == 2) && (DriveMap[Serial - 2] != 0))

               Result = DriveMap[Serial-2];

            break;

         default:

            return FS_PARAM_ERROR;

            break;
        }
    }

    if (Result == -1) {

        /* Match other alter last */

        if (DriveMap[1] && (AltMask & FS_DRIVE_V_NORMAL))
            
            Result = DriveMap[1];

        else if(DriveMap[0] && (AltMask & FS_DRIVE_V_NORMAL))
            
            Result = DriveMap[0];

        else if(DriveMap[4] && (AltMask & FS_DRIVE_V_REMOVABLE))
            
            Result = DriveMap[4];

        else if(DriveMap[3] && (AltMask & FS_DRIVE_I_SYSTEM))
            
            Result = DriveMap[3];

        else if(DriveMap[2] && (AltMask & FS_DRIVE_I_SYSTEM))
            
            Result = DriveMap[2];
   
    }

    if (Result != -1)

        return Result;
    else

        return FS_DRIVE_NOT_FOUND;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_MappingDrive                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to map a drive letter to another.          */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      UpperOldDrv   -   drive name to be mapped                        */
/*      UpperNewDrv   -   drive name to map                              */
/*                                                                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_MappingDrive(UINT UpperOldDrv, UINT UpperNewDrv)
{
    int i;

    if (fssim_mutex == 0)

        fssim_init();

    /* verify parameters */

    if (UpperOldDrv < 67 || UpperOldDrv > (FSSIM_MAX_DRIVE + 65 - 1) || 
        UpperNewDrv < (FSSIM_MAX_DRIVE + 65) || UpperNewDrv > 90 || UpperNewDrv == 88)

        return FS_PARAM_ERROR;

    /* update fssim_drvmap */

    fssim_take_mutex(fssim_mutex);

    memcpy(&fssim_drvmap.original, &UpperOldDrv, sizeof(char));

    memcpy(&fssim_drvmap.mapped, &UpperNewDrv, sizeof(char));

    fssim_give_mutex(fssim_mutex);

    for (i = 0; i < FSSIM_MAX_DRIVE; i++) {

        if (!wcsnicmp((TCHAR *)&UpperOldDrv, &(fssim_drvinfo[i].drive), 1)) {

            /* update fssim_drvinfo[] */

            wcsncpy(&(fssim_drvinfo[i].remap_drive), (TCHAR *)&UpperNewDrv, 1);
        }
    }

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GeneralFormat                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to format a drive.                         */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DriveName   -   name of drive to format                          */
/*      Level       -   level of format                                  */
/*      Progess     -   progress callback function                       */
/*                                                                       */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Error code                                                       */
/*                                                                       */
/*************************************************************************/
int FS_GeneralFormat(const WCHAR *DriveName, UINT Level, FS_FormatCallback Progress)
{
    TCHAR drive[4], strbuf[MAX_PATH];
    unsigned int cnt, i, fh;
    FSSIM_FORMAT_PARAM_T format;

    if (fssim_mutex == NULL)

        fssim_init();

    /* verify parameters */

    if (Level != FS_FORMAT_HIGH && Level != FS_FORMAT_LOW)

        return FS_PARAM_ERROR;

    /* extract drive letter of drive to format */

    memset(drive, 0, sizeof(TCHAR) * 4);

    if (!wcsncmp(DriveName, FSSIM_DRIVE_FORMAT, wcslen(FSSIM_DRIVE_FORMAT))) {

        if (!wcsncmp(DriveName + wcslen(FSSIM_DRIVE_FORMAT) + 1, L":", 1)) {

            wcsncpy(drive, DriveName + wcslen(FSSIM_DRIVE_FORMAT), 1);
        }
    }

    if (drive[0] == 0)

        return FS_PARAM_ERROR;

    /* validate the drive name */

    cnt = (char)drive[0] - (char)FSSIM_SYSTEM_DRIVE;

    if ((char)drive[0] >= 'c' && (char)drive[0] <= 'z') {

        /* the first drive letter is lowercase */

        cnt -= ('c' - 'C');
    }

    if (cnt >= FSSIM_MAX_DRIVE) {

        /* drive number exceeds the maximum */

        return FS_DRIVE_NOT_FOUND;

    }

    for (i = 0; i < FSSIM_MAX_DRIVE; i++) {

        /* check if the drive is remapped */
        if (!wcsnicmp(drive, &fssim_drvmap.mapped, 1)) {

            /* remap the drive letter */

            wcsncpy(drive, &fssim_drvmap.original, 1);
        }
    }

    /* release all files handles which file is located in the drive */

    fssim_take_mutex(fssim_mutex); /* critical section { */
    for (i = 1; i <= FSSIM_MAX_FILE; i++) {

        if (fssim_file[i].state == STATE_INUSE && !wcsnicmp(drive, &(fssim_drvinfo[fssim_file[i].drive].drive), 1)) {

#ifdef DEBUG_FSSIM

            fssim_printf(("file handle %d is released in FS_GeneralFormat\n", i));

#endif  /* DEBUG_FSSIM */

            /* check if virtual file handle */
            if (fssim_file[i].handle == INVALID_HANDLE_VALUE && fssim_vfgen.link[i] > 0)
            {
                fssim_vfgen.link[i] = 0;
            }
            else /* Normal file handle */
            {
                CloseHandle(fssim_file[i].handle);
                fssim_file[i].handle= INVALID_HANDLE_VALUE;
            }

            /* equivalence to fssim_free_fh(i); */
            memset( &(fssim_file[i]), 0, sizeof(FSSIM_FILE_T));
            fssim_file[i].state = STATE_FREE;
        }
    }

    for (i = 0; i < FSSIM_MAX_DRIVE; i++) {

        if (!wcsnicmp(&(fssim_drvinfo[i].drive), drive, 1)) {

            /* find the drvinfo of this drive */

            /* set the current directory of the drive to the root of the drive */

            wcscpy(fssim_drvinfo[i].dir_name, fssim_root_dir);

            wcscpy(fssim_drvinfo[i].dir_name + wcslen(fssim_drvinfo[i].dir_name), FSSIM_DRIVE_DIR);

            wcsncpy(fssim_drvinfo[i].dir_name + wcslen(fssim_drvinfo[i].dir_name) - 2, drive, 1);

        }
    }

    fssim_give_mutex(fssim_mutex); /* } critical section */

    fssim_take_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex BEGIN */

    /* clear drive's watermark, make it re-calculate next time */
    cnt = (char)drive[0] - (char)FSSIM_SYSTEM_DRIVE;
    fssim_drvinfo[cnt].takenclusters = 0;

    fssim_give_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex END   */

    /* make up a string specifying a drive to format */

    wcsncpy(drive + 1, L":\\", wcslen(L":\\"));

    /* allocate a file handle for abort operation */

    fh = fssim_alloc_fh();

    if (fh == -1) {

        return FS_TOO_MANY_FILES;

    } else {

        fssim_take_mutex(fssim_mutex);

        fssim_file[fh].handle = INVALID_HANDLE_VALUE;

        fssim_file[fh].flags = 0;

        fssim_file[fh].isabort = 0;

        wcscpy(fssim_file[fh].filename, drive);

        fssim_file[fh].formatprogress = Progress;

        fssim_file[fh].findattr1 = fssim_file[fh].findattr2 = 0;

        memset(&(fssim_file[fh].DirEntry), 0, sizeof(FS_DOSDirEntry));

        fssim_give_mutex(fssim_mutex);
    }

    /* count the number of files and directories first */

    fssim_conv_fn(strbuf, drive);

#ifdef DEBUG_FSSIM
    fssim_printf(("strbuf = "));
    fssim_print_str(strbuf);
#endif  /* DEBUG_FSSIM */

    cnt = fssim_search_dir(strbuf, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, NULL);

    /* initialize the parameter(format) of the callback function(fssim_del_dir) */

    format.drive = drive;

    format.total = cnt;

    format.completed = 0;

    format.level = Level;

    format.fh = fh;

    cnt = fssim_search_dir(strbuf, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, fssim_del_dir, &format);

    if (cnt != format.total) {

        /* some files are not deleted since the operation is aborted */

        if (Progress != NULL)

            Progress((const char *)drive, FS_FMT_PGS_FAIL, 0, 0);

        return FS_ABORTED_ERROR;

    } else {

        if (Progress != NULL)

            Progress((const char *)drive, FS_FMT_PGS_DONE, cnt, cnt);

        return FS_NO_ERROR;
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_CreateBootSector                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      BootSector             -   no use                                */
/*      Partition              -   no use                                */
/*      MediaDescriptor        -   no use                                */
/*      MinSectorsPerCluster   -   no use                                */
/*      Flags                  -   no use                                */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      32                                                               */
/*                                                                       */
/*************************************************************************/
int FS_CreateBootSector(void *BootSector, const FS_PartitionRecord *Partition,
                        BYTE MediaDescriptor, UINT MinSectorsPerCluster, UINT Flags)
{
    return 32;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_SplitPartition                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      MasterBootRecord   -   no use                                    */
/*      Sectors            -   no use                                    */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      0                                                                */
/*                                                                       */
/*************************************************************************/
int FS_SplitPartition(void *MasterBootRecord, UINT Sectors)
{
    return 0;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetDiskInfo                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get a drive's information.              */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DriveName   -   a valid file name                                */
/*      DiskInfo    -   pointer to FS_DiskInfo                           */
/*      Flags       -   flags                                            */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Flags or error code                                              */
/*                                                                       */
/*************************************************************************/
int FS_GetDiskInfo(const WCHAR *DriveName, FS_DiskInfo *DiskInfo, int Flags)
{
    TCHAR drive = 0;
    int i;

    ASSERT(DriveName != NULL && DiskInfo != NULL);

    /* extract the drive name from DriveName */

    i = fssim_locate_drive( DriveName );

    if( i >= FSSIM_MAX_DRIVE ) {

        return FS_DRIVE_NOT_FOUND;

    } else if ( i < 0 ) {

        i = fssim_get_default_drive();
    }

    ASSERT(i >= 0 && i < FSSIM_MAX_DRIVE);

    /* set FS_DiskInfo */

    memset(DiskInfo, 0, sizeof(FS_DiskInfo));

    DiskInfo->DriveLetter = (char) fssim_drvinfo[i].drive;

    DiskInfo->BytesPerSector = fssim_drvinfo[i].bytespersector;

    DiskInfo->SectorsPerCluster = fssim_drvinfo[i].sectorspercluser;

    DiskInfo->TotalClusters = fssim_drvinfo[i].totalclusters;

    DiskInfo->BadClusters   = 0;

    fssim_take_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex BEGIN */

    if (fssim_drvinfo[i].takenclusters == 0) {
        fssim_get_drive_watermark( &(fssim_drvinfo[i]) );
    }

    /* printf("takenclusters = %d\n", fssim_drvinfo[i].takenclusters);
     */

    DiskInfo->FreeClusters  = (fssim_drvinfo[i].takenclusters >= fssim_drvinfo[i].totalclusters) ?
                              0 : fssim_drvinfo[i].totalclusters - fssim_drvinfo[i].takenclusters;

    fssim_give_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex END   */

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_ShotDown                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      none                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      None                                                             */
/*                                                                       */
/*************************************************************************/
void FS_ShutDown(void)
{
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_UnlockAll                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      none                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Number of devices                                                */
/*                                                                       */
/*************************************************************************/
int FS_UnlockAll(void)
{
    return FSSIM_NORFLASH_CNT + FSSIM_NANDFLASH_CNT + FSSIM_MEMCARD_CNT;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_SanityCheck                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      none                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_SanityCheck(void)
{
    if (fssim_mutex == NULL) {
        fssim_init();
    }
    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_SetDiskFlag                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      none                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_SetDiskFlag(void)
{
    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_ClearDiskFlag                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      none                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_ClearDiskFlag(void)
{
    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_CheckDiskFlag                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      none                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_CheckDiskFlag(void)
{
    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetDevType                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get the device type.                    */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      Path   -   a full path containing the drive name                 */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Deivce type or error code                                        */
/*                                                                       */
/*************************************************************************/
int FS_GetDevType(const WCHAR *Path)
{
    int offset;

    ASSERT(Path != NULL);

    /* extract the drive name from Path */

    if (fssim_match_pattern(L"?:\\*", Path) == 0) {

        /* the drive name is not specified */

        return FS_DRIVE_NOT_FOUND;
    } else {

        /* the drive name is specified */

        offset = (char)Path[0] - (char)FSSIM_SYSTEM_DRIVE;

        if ((char)Path[0] >= 'c' && (char)Path[0] <= 'z') {

            /* the first drive letter is lowercase */

            offset -= ('c' - 'C');
        }
    }

    if (offset >= FSSIM_MAX_DRIVE) {

        /* drive number exceeds the maximum */

        return FS_DRIVE_NOT_FOUND;
    } else {

        return fssim_drvinfo[offset].dev;
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetDevStatus                                                  */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get the device status.                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      QueryTarget-   the index number get from FS_GetDrive             */
/*                  OR the type enum get from FS_GetDevType              */
/*      Flag       -   FS_MOUNT_STATE_ENUM                               */
/*                     FS_FEATURE_STATE_ENUM                             */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_GetDevStatus(UINT QueryTarget, UINT Flag)
{
    unsigned int offset;

    if ((char)QueryTarget >= 'c' && (char)QueryTarget <= 'z') {

        /* the drive letter is lowercase */

        QueryTarget -= ('c' - 'C');
    }
    
    if (QueryTarget >= FS_DEVICE_TYPE_MAX_VALUE) {
        /* QueryTarget  should be a driveIdx */

        offset = (char)QueryTarget - (char)FSSIM_SYSTEM_DRIVE;

        if (offset >= FSSIM_MAX_DRIVE) {
            /* drive number exceeds the maximum */

            return FS_PARAM_ERROR;
        }

        /* Align 'offset' to device offset */
        offset = fssim_drvinfo[offset].dev;
    }
    else {
        /* QueryTarget  should be a deviceType */
        offset = QueryTarget;
    }

    switch (Flag) {

    case FS_MOUNT_STATE_ENUM:

        if (fssim_device[offset].mount_state > 0) {

            /* no-op */
        } else if (offset == FS_DEVICE_TYPE_CARD) {

            return FS_MSDC_MOUNT_ERROR;
        } else {

            return FS_FLASH_MOUNT_ERROR;
        }
        break;

    case FS_FEATURE_STATE_ENUM:

        if (fssim_device[offset].busy_status > 0) {

            return FS_DEVICE_BUSY;
        }

        break;

    default:
        return FS_PARAM_ERROR;
    }

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_TestMSDC                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      slot_id   -   no use                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_MSDC_NOT_PRESENT                                              */
/*                                                                       */
/*************************************************************************/
int FS_TestMSDC(void *slot_id)
{
    return FS_MSDC_NOT_PRESENT;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_CloseMSDC                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DriveIdx    -   no use                                           */
/*      Mode        -   no use                                           */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_CloseMSDC(UINT DriveIdx, UINT Mode)
{
    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_SetTrace                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      Flag      -   no use                                             */
/*      Timeout   -   no use                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_SetTrace(UINT Flag, UINT Timeout)
{
    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_DumpFHTable                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      none                                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_DumpFHTable(void)
{
    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_CheckFile                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is implement to do no-thing here. See FS_Extend()  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileName   -                                                     */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_CheckFile(const WCHAR *FileName)
{   TCHAR strbuf[FS_MAX_PATH];
    DWORD attributes;

    /* Stop irregular path input */
    if (wcslen(FileName) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf, FileName);

    if (!fssim_is_name_valid(strbuf))

        /* the folder name is not valid */

        return FS_INVALID_FILENAME;

    else if (!fssim_is_file_exist(strbuf))

        /* the folder doesn't exist */

        return FS_FILE_NOT_FOUND;

    CRITICAL_SECTION_BEGIN;
    attributes = GetFileAttributes(strbuf);
    CRITICAL_SECTION_END;

    if ((attributes & FILE_ATTRIBUTE_DIRECTORY) == 1)

        /* it's a folder */

        return FS_FILE_NOT_FOUND;

    /* Don't touch anything */
    return FS_NO_ERROR;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_CheckDrive                                                    */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DriveIdx      -   device of drive to get                         */
/*      CheckBuffer   -   no use                                         */
/*      BufferSize    -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_CheckDrive(const UINT DriveIdx, BYTE *Checkbuffer, const UINT BufferSize)
{   int i;

    i = fssim_search_drive( DriveIdx );

    if (i >= FSSIM_MAX_DRIVE || i < 0) {

        return FS_DRIVE_NOT_FOUND;
    }

    if (Checkbuffer == NULL) {

        return FS_FAIL_GET_MEM;
    }

    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_ParseFH                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get the index of file table.            */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle   -   handle of file to parse                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Index of error code                                              */
/*                                                                       */
/*************************************************************************/
int FS_ParseFH(FS_HANDLE FileHandle)
{
    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE && fssim_vfgen.link[FileHandle] == 0)

        return FS_INVALID_FILE_HANDLE;

    else

        return FileHandle;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_QmGetFree                                                     */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      Path   -   no use                                                */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FSSIM_QUOTA_SIZE                                                 */
/*                                                                       */
/*************************************************************************/
int FS_QmGetFree(const BYTE *Path)
{
    int i, k, RFS_for_Other, system_drive_idx;
    int FreeSpace1, FreeSpace2;
    int clustersize, FreeClusterCount;

    system_drive_idx = fssim_search_drive((UINT)FSSIM_SYSTEM_DRIVE);
    i = fssim_search_drive((UINT)Path[0]);

    if (i == FSSIM_MAX_DRIVE) {

        return FS_DRIVE_NOT_FOUND;
    }

    if (i != system_drive_idx) {

        return FS_ACCESS_DENIED;
    }

    fssim_take_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex BEGIN */

    /* if takenclusters and gFS_IntQuotaSet not initialized */
    if (fssim_drvinfo[system_drive_idx].takenclusters == 0) {

        fssim_get_drive_watermark(&(fssim_drvinfo[system_drive_idx]));
    }

    /* Search Path and count the minal reserved space (exclude matched one) */
    for (i = FS_MAX_QSET - 1; i >= 0; i--) {
        
        if (Path[0] != gFS_ExtQuotaSet[i].Path[0] &&
            Path[0] != fssim_drvinfo[system_drive_idx].drive &&
            Path[0] != fssim_drvinfo[system_drive_idx].remap_drive)
            continue;

        /* NOTE: must be system drive */
        if (strncmp(Path+1, gFS_ExtQuotaSet[i].Path+1, FS_MAX_PATH/2) == 0) {

            for(RFS_for_Other = 0, k = FS_MAX_QSET - 1; k >= 0; k--) {

               if(k != i) {

                  if(gFS_IntQuotaSet[k].Qmin > gFS_IntQuotaSet[k].Qnow)
                     RFS_for_Other += (gFS_IntQuotaSet[k].Qmin - gFS_IntQuotaSet[k].Qnow);
               }
            }
            break;
        }
    }

    if (i == -1) /* not found */ {

        fssim_give_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex END   */
        return FS_PATH_NOT_FOUND;
    }

    /* Debug Dump */
    /* printf("Quota Entry %d , %s found\n", i, gFS_ExtQuotaSet[i].Path);
     */

    /* calculate how many space occupied by matched one */
    clustersize = fssim_drvinfo[system_drive_idx].bytespersector * fssim_drvinfo[system_drive_idx].sectorspercluser;
    FreeClusterCount = (fssim_drvinfo[system_drive_idx].totalclusters > fssim_drvinfo[system_drive_idx].takenclusters) ?
            fssim_drvinfo[system_drive_idx].totalclusters - fssim_drvinfo[system_drive_idx].takenclusters : 0;

    FreeSpace1 = (FreeClusterCount > RFS_for_Other) ?
                 (FreeClusterCount - RFS_for_Other) : 0;

    /* Debug Dump */
    /* printf("FreeClusterCount %d, clustersize %d, FreeSpace1 %d, RFS_for_Other %d\n",
            FreeClusterCount, clustersize, FreeSpace1, RFS_for_Other);
       printf("Entry Qmax %d, Qnow %d\n", gFS_IntQuotaSet[i].Qmax, gFS_IntQuotaSet[i].Qnow);
     */

    if (gFS_IntQuotaSet[i].Qmax == 0) /*FS_QMAX_NO_LIMIT */{

        fssim_give_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex END   */
        return FreeSpace1 * clustersize;
    }

    FreeSpace2 = (gFS_IntQuotaSet[i].Qmax > gFS_IntQuotaSet[i].Qnow) ?
                 (gFS_IntQuotaSet[i].Qmax - gFS_IntQuotaSet[i].Qnow) : 0;

    fssim_give_mutex(fssim_disk_space_mutex); /* disk-space-feature mutex END   */

    /* return minial value */
    if (FreeSpace1 > FreeSpace2) {

        return FreeSpace2 * clustersize;
    }
    return FreeSpace1 * clustersize;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetClusterSize                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get cluster size of a drive.            */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DriveIdx   -   device of drive to get                            */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Cluster size or error code                                       */
/*                                                                       */
/*************************************************************************/
int FS_GetClusterSize(UINT DriveIdx)
{
    int offset;

    offset = fssim_search_drive( DriveIdx );

    if (offset < 0 || offset >= FSSIM_MAX_DRIVE) {

        return FS_DRIVE_NOT_FOUND;
    } else {

        return fssim_drvinfo[offset].bytespersector * fssim_drvinfo[offset].sectorspercluser;
    }
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetFolderSize                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      DirName   -   no use                                             */
/*      Flag      -   no use                                             */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      0                                                                */
/*                                                                       */
/*************************************************************************/
int FS_GetFolderSize(const WCHAR *FullPath, UINT Flag, BYTE *RecursiveStack, const UINT StackSize)
{
    TCHAR strbuf[MAX_PATH];
    DWORD attributes;
    FSSIM_SUM_SIZE_PARAM_T top_folder;
    int idx;

    ASSERT(FullPath != NULL);

    if (fssim_mutex == NULL) {

        fssim_init();
    }

    /* verify Flag */

    if (Flag != FS_COUNT_IN_BYTE && Flag != FS_COUNT_IN_CLUSTER)
        
        return FS_PARAM_ERROR;

    /* Stop irregular path input */
    if (wcslen(FullPath) >= MAX_PATH) {

        return FS_PATH_OVER_LEN_ERROR;
    }
    
    fssim_conv_fn(strbuf, FullPath);

    if (!fssim_is_name_valid(strbuf))

        /* the folder name is not valid */

        return FS_INVALID_FILENAME;

    else if (!fssim_is_file_exist(strbuf))

        /* the folder doesn't exist */

        return FS_PATH_NOT_FOUND;

    CRITICAL_SECTION_BEGIN;
    attributes = GetFileAttributes(strbuf);
    CRITICAL_SECTION_END;

    if ((attributes & FILE_ATTRIBUTE_DIRECTORY) == 0)

        /* not a folder */

        return FS_PARAM_ERROR;

    /* locate the drive */
    idx = fssim_locate_drive(FullPath);

    /* initialize the structure */
    top_folder.directory_entry_cnt = 2;
    top_folder.allocated_cluster_cnt = 0;
    top_folder.size_of_cluster_unit = fssim_drvinfo[idx].bytespersector * fssim_drvinfo[idx].sectorspercluser;

    /* issue the recursive loop */
    fssim_search_dir(strbuf, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
                     fssim_sum_allocated_clusters, (void*) &top_folder);

    top_folder.allocated_cluster_cnt +=
                ((top_folder.directory_entry_cnt * sizeof(FS_DOSDirEntry) - 1) / top_folder.size_of_cluster_unit + 1);

    if (Flag == FS_COUNT_IN_CLUSTER) {

        return top_folder.allocated_cluster_cnt;
    }
    return top_folder.allocated_cluster_cnt * top_folder.size_of_cluster_unit;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_LockFAT                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      Type   -   no use                                                */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_LockFAT(UINT Type)
{
    return FS_NO_ERROR;
}


/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetFirstCluster                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to identify file,                          */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle   -   the file that opened                            */
/*      Cluster      -   the identify                                    */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_GetFirstCluster(FS_HANDLE FileHandle, UINT * Cluster)
{
    FILETIME create_ft;

    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE && fssim_vfgen.link[FileHandle] == 0)

        return FS_INVALID_FILE_HANDLE;

    /* get file time */

    GetFileTime(fssim_file[FileHandle].handle, &create_ft, NULL, NULL);

    *Cluster = (UINT) create_ft.dwLowDateTime;
    // XXX Debug use
    // printf("creat time DWHIGH = %X , DWLOW = %X\n", create_ft.dwLowDateTime, create_ft.dwHighDateTime);

    return FS_NO_ERROR;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GenVirtualFileName                                            */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle    -   no use                                         */
/*      VFileNameBuf  -   no use                                         */
/*      BufLength     -   no use                                         */
/*      VFBeginOffset -   no use                                         */
/*      VFValidLength -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_ERROR_RESERVED                                                */
/*      VFileNameBuf                                                     */
/*                                                                       */
/*************************************************************************/
int FS_GenVirtualFileName(FS_HANDLE FileHandle, WCHAR * VFileNameBuf, UINT BufLength,
                                UINT VFBeginOffset, UINT VFValidLength)
{
    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    /* verify the parameters , access , and segment */

    if ((fssim_vfgen.link[FileHandle] != 0 ) /* virtual file handle */  ||
        (fssim_file[FileHandle].DirEntry.Attributes & FS_ATTR_DIR) /* folder */ ||
        (fssim_file[FileHandle].DirEntry.FileSize <= VFBeginOffset) ||
        (fssim_file[FileHandle].DirEntry.FileSize <  VFBeginOffset+VFValidLength))

        return FS_PARAM_ERROR;
    
    if ((fssim_file[FileHandle].flags & (FS_READ_ONLY | FS_OPEN_SHARED)) != (FS_READ_ONLY | FS_OPEN_SHARED))

        return FS_ACCESS_DENIED;

    /* Register Virtual Filename and Fill the VFileNameBuf */

    if (BufLength < FS_GenVFN_SIZE)

        return FS_STRING_BUFFER_TOO_SMALL;

    __try {

        WCHAR *ptr; 
        int vf_table_id;
        int ws_gen_len = FSSIM_VFN_SIZE_IN_WCHAR;
        const TCHAR hex_digits[] = L"0123456789ABCDEF";

        /* FS_GenVFN_SIZE = 92 bytes, fssim_vfname_prefix = \\.\FMapF\ */

        ASSERT( ((FS_GenVFN_SIZE % sizeof(TCHAR)) == 0) &&
                (FS_GenVFN_SIZE > 2 * wcslen(fssim_vfname_prefix)) );

        /* Virtual Filename Table solt registeration and enlarge if needed */

        fssim_take_mutex(fssim_mutex);

        vf_table_id = fssim_vfgen.usage_size++;

        if (fssim_vfgen.usage_size == fssim_vfgen.allocat_size){

            fssim_vfgen.allocat_size = fssim_vfgen.allocat_size * 2;
            fssim_vfgen.data = (FSSIM_VIRTUAL_FILENAME_T *)
                realloc( (void*)fssim_vfgen.data, fssim_vfgen.allocat_size * sizeof(FSSIM_VIRTUAL_FILENAME_T) );

        }

        fssim_vfgen.data[vf_table_id].vf_size = VFValidLength;
        fssim_vfgen.data[vf_table_id].vf_offset = VFBeginOffset;
        fssim_vfgen.data[vf_table_id].vf_gen_fh_unique = fssim_file[FileHandle].unique;

        /* Virtual Filename generation on Virtual Filename Table */

        ptr = fssim_vfgen.data[ vf_table_id ].name_once; 

        wcsncpy( ptr, fssim_vfname_prefix, wcslen(fssim_vfname_prefix) );
        ws_gen_len -= wcslen(fssim_vfname_prefix);
        ptr += wcslen(fssim_vfname_prefix);

        for ( ; ws_gen_len>1; ws_gen_len--, ptr++) {
            
            *ptr = hex_digits[ rand() & 0x0f ];

        }

        *ptr = 0;

        wcscpy( VFileNameBuf, fssim_vfgen.data[vf_table_id].name_once); /* include NULL tail */

        fssim_give_mutex(fssim_mutex);

    }
    __finally {

    }

   return FS_NO_ERROR;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_SetDirCache                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle    -   no use                                         */
/*      NewValuee     -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_SetDirCache(FS_HANDLE FileHandle, UINT NewValue)
{
    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    /* do nothing */
    return FS_NO_ERROR;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetDirCache                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle    -   no use                                         */
/*      CurrValue     -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_DIRCACHE_EXPIRED                                              */
/*                                                                       */
/*************************************************************************/
int FS_GetDirCache(FS_HANDLE FileHandle, UINT *CurrValue)
{
    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    /* do nothing */
    return FS_DIRCACHE_EXPIRED;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_ExpireDirCache                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      FileHandle    -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_ExpireDirCache(FS_HANDLE FileHandle)
{
    /* verify file handle */

    if (FileHandle > FSSIM_MAX_FILE || FileHandle <= 0)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].state != STATE_INUSE)

        return FS_INVALID_FILE_HANDLE;

    else if (fssim_file[FileHandle].handle == INVALID_HANDLE_VALUE)

        return FS_INVALID_FILE_HANDLE;

    /* do nothing */
    return FS_NO_ERROR;
}
/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_OTPRead                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      devtype       -   no use                                         */
/*      Offset        -   no use                                         */
/*      BufferPtr     -   no use                                         */
/*      Length        -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_UNSUPPORTED_DEVICE                                            */
/*      FS_UNSUPPORTED_DRIVER_FUNCTION                                   */
/*                                                                       */
/*************************************************************************/
int FS_OTPRead(int devtype, UINT Offset, void * BufferPtr, kal_uint32 Length)
{
    /* verify dev type */
    if (devtype >= FS_DEVICE_TYPE_MAX_VALUE || devtype <= 0)
        return FS_UNSUPPORTED_DEVICE;

    /* do nothing */
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_OTPWrite                                                      */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      devtype       -   no use                                         */
/*      Offset        -   no use                                         */
/*      BufferPtr     -   no use                                         */
/*      Length        -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_UNSUPPORTED_DEVICE                                            */
/*      FS_UNSUPPORTED_DRIVER_FUNCTION                                   */
/*                                                                       */
/*************************************************************************/
int FS_OTPWrite(int devtype, UINT Offset, void * BufferPtr, kal_uint32 Length)
{
    /* verify dev type */
    if (devtype >= FS_DEVICE_TYPE_MAX_VALUE || devtype <= 0)
        return FS_UNSUPPORTED_DEVICE;

    /* do nothing */
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_OTPLock                                                       */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      devtype       -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_UNSUPPORTED_DEVICE                                            */
/*      FS_UNSUPPORTED_DRIVER_FUNCTION                                   */
/*                                                                       */
/*************************************************************************/
int FS_OTPLock(int devtype)
{
    /* verify dev type */
    if (devtype >= FS_DEVICE_TYPE_MAX_VALUE || devtype <= 0)
        return FS_UNSUPPORTED_DEVICE;

    /* do nothing */
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_OTPQueryLength                                                */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      devtype       -   no use                                         */
/*      Offset        -   no use                                         */
/*      BufferPtr     -   no use                                         */
/*      Length        -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_UNSUPPORTED_DEVICE                                            */
/*      FS_UNSUPPORTED_DRIVER_FUNCTION                                   */
/*                                                                       */
/*************************************************************************/
int FS_OTPQueryLength(int devtype, UINT *Length)
{
    /* verify dev type */
    if (devtype >= FS_DEVICE_TYPE_MAX_VALUE || devtype <= 0)
        return FS_UNSUPPORTED_DEVICE;

    /* do nothing */
    return FS_UNSUPPORTED_DRIVER_FUNCTION;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_SweepDevice                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      devtype       -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_UNSUPPORTED_DEVICE                                            */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_SweepDevice(const int devtype)
{
    /* verify dev type */
    if (devtype >= FS_DEVICE_TYPE_MAX_VALUE || devtype <= 0)
        return FS_UNSUPPORTED_DEVICE;

    /* do nothing */
    return FS_NO_ERROR;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_RecoverDevice                                                 */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      devtype       -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_UNSUPPORTED_DEVICE                                            */
/*      FS_NO_ERROR                                                      */
/*                                                                       */
/*************************************************************************/
int FS_RecoverDevice(const int devtype)
{
    /* verify dev type */
    if (devtype >= FS_DEVICE_TYPE_MAX_VALUE || devtype <= 0)
        return FS_UNSUPPORTED_DEVICE;

    /* do nothing */
    return FS_NO_ERROR;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_ConfigExtDevice                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is not supported.                                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      Action        -   no use                                         */
/*      DrvFuncs      -   no use                                         */
/*      Slots         -   no use                                         */
/*      SlotIdArray   -   no use                                         */
/*      SlotsConfiged -   no use                                         */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      FS_UNSUPPORTED_DEVICE                                            */
/*                                                                       */
/*************************************************************************/
int FS_ConfigExtDevice(int Action, FS_Driver *DrvFuncs, int Slots, void **SlotIdArray, int *SlotsConfiged)
{  
    if ((DrvFuncs == NULL) || (SlotIdArray == NULL) || (Slots < 1))
    {
        return FS_PARAM_ERROR;
    }

    *SlotsConfiged = 0;

    /* do nothing */
    return FS_UNSUPPORTED_DEVICE;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_CountUsedFH                                                   */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to query number of file handles that       */
/*      occupied by current task/any task OR                             */
/*      available/configured                                             */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      flag:  FS_FH_COUNT_CONFIGURED,                                   */
/*             FS_FH_COUNT_USED,                                         */
/*             FS_FH_COUNT_AVAILABLE,                                    */
/*             FS_FH_COUNT_CURRENT_TASK                                  */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Number of file handles                                           */
/*                                                                       */
/*************************************************************************/
int FS_CountUsedFH(int flag)
{
    int i;
    int Result = 0;

    switch (flag) {
        case FS_FH_COUNT_CONFIGURED:
            Result = FSSIM_MAX_FILE;
            break;

        case FS_FH_COUNT_USED:
        case FS_FH_COUNT_AVAILABLE:
            fssim_take_mutex(fssim_mutex); /* { critical section */
            for (i = 1; i <= FSSIM_MAX_FILE; i++) {
                if (fssim_file[i].state == STATE_INUSE) Result++;
            }
            fssim_give_mutex(fssim_mutex); /* } critical section */

            if (flag == FS_FH_COUNT_AVAILABLE) {
                Result = FSSIM_MAX_FILE - Result;
            }
            break;

        case FS_FH_COUNT_CURRENT_TASK: 
            fssim_take_mutex(fssim_mutex); /* { critical section */
            for (i = 1; i <= FSSIM_MAX_FILE; i++) {
                if (fssim_file[i].state == STATE_INUSE
                 && fssim_file[i].taskid == fssim_get_task_self_id())
                    Result++;
            }
            fssim_give_mutex(fssim_mutex); /* } critical section */
            break;
    }

    return Result;
}

/*************************************************************************/
/*                                                                       */
/* FUNCTION                                                              */
/*                                                                       */
/*      FS_GetDevPartitions                                              */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This function is used to get the device status.                  */
/*                                                                       */
/* INPUTS                                                                */
/*                                                                       */
/*      QueryTarget-   the index number get from FS_GetDrive             */
/*                  OR the type enum get from FS_GetDevType              */
/*                                                                       */
/* OUTPUTS                                                               */
/*                                                                       */
/*      Number of partitions on the disk                                 */
/*                                                                       */
/*************************************************************************/
int FS_GetDevPartitions(UINT QueryTarget)
{
    unsigned int offset, i;
    int Result;

    if ((char)QueryTarget >= 'c' && (char)QueryTarget <= 'z') {

        /* the drive letter is lowercase */

        QueryTarget -= ('c' - 'C');
    }
    
    if (QueryTarget >= FS_DEVICE_TYPE_MAX_VALUE) {
        /* QueryTarget  should be a driveIdx */

        offset = (char)QueryTarget - (char)FSSIM_SYSTEM_DRIVE;

        if (offset >= FSSIM_MAX_DRIVE) {
            /* drive number exceeds the maximum */

            return FS_PARAM_ERROR;
        }

        /* Align 'offset' to device offset */
        offset = fssim_drvinfo[offset].dev;
    }
    else {
        /* QueryTarget  should be a deviceType */
        offset = QueryTarget;
    }

    for ( Result = 0, i = 0 ; i < FSSIM_MAX_DRIVE ; i++)
    {
        if (fssim_drvinfo[i].dev == offset)
            Result++;
    }

    return Result;
}
#undef UNICODE

