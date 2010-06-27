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
 *  gdi_lfs.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI Lazy FS API
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
 
#include "gdi_internal.h"
#include "gdi_lfs.h"
#include "drm_gprot.h"
#include "ucs2prot.h"

int gdi_lfs_handle;

#ifdef GDI_USING_LFS
static gdi_lfs_struct gdi_lfs;

void gdi_lfs_initialize(void)
{
    gdi_lfs_handle = (int) ((void*)&gdi_lfs);
    gdi_lfs_init((gdi_lfs_struct*) gdi_lfs_handle);
}
__inline int _gdi_lfs_real_open(gdi_lfs_struct *H)
{
    if(H->handle==NULL)
    {
        H->handle = DRM_open_file(H->filename,H->file_flag,DRM_PERMISSION_DISPLAY);
        if(H->handle<0)
            H->is_valid_file = MMI_FALSE;
        else
            H->is_valid_file = MMI_TRUE;
    }
    return (int)H->handle;
}
__inline int _gdi_lfs_load_cache(gdi_lfs_struct *H)
{
    int result = FS_NO_ERROR;
    
    if(!H->handle) result = _gdi_lfs_real_open(H);
    if(result>=0)       result = DRM_seek_file(H->handle, H->file_pos,0);
    if(result>=0)
    {
        result = DRM_read_file(H->handle,H->cache,GDI_LFS_CACHE_SIZE,&H->cache_size);
        H->cache_pos = H->file_pos;
    }
    return result;
}


void gdi_lfs_init(gdi_lfs_struct *H)
{
    memset(H,0,sizeof(*H));
    H->file_size = (U32)-1;
}

int gdi_lfs_open(int handle,U16* filename,U32 flag,U8 permission)
{
    int result = FS_NO_ERROR;
    gdi_lfs_struct *H = (gdi_lfs_struct *) handle;
    GDI_ASSERT( (flag&FS_READ_ONLY)!=0); // only lazy in read-only mode
        
    if(mmi_ucs2cmp((const S8 *) H->filename,(const S8 *)filename)==0) // the same as cache
    {
        // do nothing
    }
    else // remember file information
    {
        memcpy((void*)H->filename,(U8*)filename,FS_MAX_PATH); // copy the filename
        H->file_permission = permission;
        H->file_flag = flag;
        result = _gdi_lfs_real_open(H);
        H->cache_size = 0;// clear cache data
    }
    H->file_pos  = 0;

    return result;
}

int gdi_lfs_file_size(int handle,U32 *size)
{
    int result = FS_NO_ERROR;
    gdi_lfs_struct *H = (gdi_lfs_struct *) handle;
    if(H->file_size!=(U32)-1)
    {
        // do nothing
    }
    else // try to fetch file size
    {
        result = _gdi_lfs_real_open(H);
        if(result >=0) result = DRM_file_size(H->handle, &H->file_size);
    }
    *size = (U32) H->file_size;
    return result;
}


int gdi_lfs_seek(int handle,int offset, int whence)
{
    int result = FS_NO_ERROR;
    gdi_lfs_struct *H = (gdi_lfs_struct *) handle;
    switch(whence)
    {
    case 0: H->file_pos = offset; break; // begin
    case 1: H->file_pos +=offset; break; // current
    case 2: // end
        {
            U32 size;
            result = gdi_lfs_file_size(handle,&size);
            H->file_pos = size + offset;
            break;
        }
    }
    return H->file_pos;
}

int gdi_lfs_close(int handle)
{
    gdi_lfs_struct *H = (gdi_lfs_struct *) handle;
    int result = FS_NO_ERROR;
    if(H->handle)
    {
        result = DRM_close_file(H->handle);
        H->handle = 0;
    }
    return result;
}
int gdi_lfs_read(int handle,void * buffer, U32 size,U32 *length)
{
    gdi_lfs_struct *H = (gdi_lfs_struct *) handle;
    int result = FS_NO_ERROR;
    U8* dest = (U8*) buffer;

    *length = 0;
    while(size>0)
    {
        // is some data in cache ?
        if(H->cache_pos <= H->file_pos && H->file_pos< H->cache_pos + H->cache_size)
        {
            int len = size;

            if(H->file_pos + len > H->cache_pos + H->cache_size)
                len = H->cache_pos + H->cache_size - H->file_pos;
            
            memcpy(dest,&H->cache[H->file_pos - H->cache_pos],len);

            dest+=len;
            H->file_pos +=len;
            size -= len;
            *length +=len;
        }
        else
        {
            if((result = _gdi_lfs_load_cache(H))<0)
                break; // something wrong
            if(H->cache_size==0) // nothing is loaded
                break;
        }
    }
    return result;
}
#else

FS_HANDLE gdi_lfs;
void gdi_lfs_initialize(void)
{
    gdi_lfs_handle = (int) ((void*)&gdi_lfs);
}
int gdi_lfs_open(int handle,U16* filename,U32 flag,U8 permission)
{
    FS_HANDLE *H = (FS_HANDLE *) handle;
    *H = DRM_open_file(filename,flag,DRM_PERMISSION_DISPLAY);
    return (int)*H;
}

int gdi_lfs_file_size(int handle,U32 *size)
{
    FS_HANDLE H = *(FS_HANDLE *) handle;
    return DRM_file_size(H, size);
}

int gdi_lfs_seek(int handle,int offset, int whence)
{
    FS_HANDLE H = *(FS_HANDLE *) handle;
    return DRM_seek_file(H, offset,(U8)whence);
}
int gdi_lfs_close(int handle)
{
    FS_HANDLE H = *(FS_HANDLE *) handle;
    return DRM_close_file(H);
}
int gdi_lfs_read(int handle,void * buffer, U32 size,U32 *length)
{
    FS_HANDLE H = *(FS_HANDLE *) handle;
    return DRM_read_file(H,buffer,size,length);
}
#endif
