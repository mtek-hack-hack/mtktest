/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *  mdi_swflash.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access SWFlash related functions.
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
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_SWFLASH__)

/*****************************************************************************
 * Include Files                                                                
 *****************************************************************************/
#ifndef __MTK_TARGET__
#include <windows.h>    /* for soc_api.h */
#endif 

#include "stdC.h"
#include "L4Dr1.h"
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "Frameworkstruct.h"
#include "fat_fs.h"
#include "lcd_if.h"             /* lcd interface */
#include "gdi_include.h"        /* include data type */
#include "lcd_sw_rnd.h"
#include "gui.h"
#include "QueueGprot.h"         /* message handling */
#include "med_api.h"            /* media task */
#include "med_main.h"
#include "med_struct.h"
#include "mdi_datatype.h"
#include "mdi_swflash.h"
#include "med_smalloc.h"        /* MMI Shall not inc this: Paul plz help check */

#include "ProfileGprots.h"

#include "Cimdepends.h"
#include "Cimlib.h"

#include "rtfiles.h"
#include "soc_api.h"
#include "app2soc_struct.h"
#include "FileMgr.h"
#include "DebugInitDef.h"
#include "FileManagerGprot.h"
#include "kal_trace.h"          /* Debug Info */
#include "DebugInitDef.h"       /* Debug Info */
#include "mmi_trc.h"            /* Debug Info */
#include "fs_type.h"
/* NVRAM */
#include "NVRAMProt.h"
#include "NVRAMType.h"
#include "IdleAppDef.h"
#include "SWFlashProt.h"
#include "mdi_audio.h"
/*****************************************************************************
 * Local variable                                                     
 *****************************************************************************/
mdi_swflash_info_struct wgui_swflash_info;
mdi_swflash_context_struct g_mdi_swflash_cntx;
mdi_swflash_context_struct *mdi_swflash_p = &g_mdi_swflash_cntx;

#ifdef SWFLASH_CHAOTEX
/*****************************************************************************
 * Local function                                                     
 *****************************************************************************/
static void mdi_swflash_dl_socket_ind_handler(void *msg_ptr);
static void mdi_swflash_pl_audio_ind_handler(void *msg_ptr);

/*****************************************************************************
 * Macro
 *****************************************************************************/
extern void mmi_swflash_option_play_played(void);
extern void mmi_swflash_option_play_paused(void);
extern void mmi_swflash_option_play_stopped(void);
extern void mmi_swflash_option_play_resumed(void);

extern void cim_trace1(char* p, int p1);
extern void cim_trace2(char* p, int p1, int p2);
extern void cim_trace3(char* p, int p1, int p2, int p3);
extern void cim_trace4(char* p, int p1, int p2, int p3, int p4);

#define SWFLASH_DBG_PRINT1(p,p1) cim_trace1(p,p1)
#define SWFLASH_DBG_PRINT2(p,p1,p2) cim_trace2(p,p1,p2)
#define SWFLASH_DBG_PRINT3(p,p1,p2,p3) cim_trace3(p,p1,p2,p3)
#define SWFLASH_DBG_PRINT4(p,p1,p2,p3,p4) cim_trace3(p,p1,p2,p3,p4)


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_write_file
 * DESCRIPTION
 *  write file
 * PARAMETERS
 *  file_name       :file full name         
 *  pData           data buffer pointer to be written         
 *  nSize           buffer size        
 * RETURNS          write result
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_write_file(UI_character_type *file_name, char *pData, int nSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;
    FS_HANDLE fd = -1;
    int nWritten = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_WRITEFILE);

    if ((fd = FS_Open(file_name, FS_READ_WRITE | FS_CREATE_ALWAYS)) < 0)
    {
        return MDI_RES_SWFLASH_ERR_OPEN_FILE;
    }

    if ((ret = FS_Write(fd, (void*)pData, nSize, (U32*)&nWritten)) != RTF_NO_ERROR)
    {
        FS_Close(fd);
        return MDI_RES_SWFLASH_ERR_WRITE_FILE;
    }

    if (nSize != nWritten)
    {
        FS_Close(fd);
        return MDI_RES_SWFLASH_ERR_WRITE_FILE_PARTIAL;
    }

    FS_Close(fd);

    return MDI_RES_SWFLASH_SUCCEED; /* Success */
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_open_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        file full name        
 *  playmode        play mode        
 *  info            the info of swflash works
 * RETURNS          open result
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_open_file(const S8 *filename, U32 playmode, mdi_swflash_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;
    char *pData = NULL;
    int nSize = -1;
    int nRead = -1;
    int cimret = 0;
    unsigned short *cim_string = NULL;
  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_OPENFILE);

    mdi_swflash_p->fd = -1;
    /* If a swflash content is alredy opened, popup a message to indicate it */
    if (mdi_swflash_p->state != MDI_SWFLASH_PL_STATE_NULL)
    {
        return MDI_RES_SWFLASH_BUSY;
    }

    if ((mdi_swflash_p->fd = FS_Open((const WCHAR*)filename, FS_READ_ONLY)) < 0)
    {
        return MDI_RES_SWFLASH_ERR_OPEN_FILE;
    }

    if ((ret = FS_GetFileSize(mdi_swflash_p->fd, (U32*) & nSize)) != RTF_NO_ERROR)
    {
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        return MDI_RES_SWFLASH_ERR_GET_FILE_SIZE;
    }

    if (nSize <= 0 || nSize > MAX_SWFLASH_FILE_DATA_BUFFER_SIZE)
    {
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        return MDI_RES_SWFLASH_ERR_WRONG_FILE_SIZE;
    }

    /* alloc buffer */
    media_get_ext_buffer(MOD_MMI, (void **)&pData, nSize);

    /* mem allocate shall not failed */
    MMI_ASSERT(pData != NULL);

    ret = FS_Read(mdi_swflash_p->fd, pData, nSize, (U32*) & nRead);

    /* fs read error 1 */
    if (ret < 0)
    {
        /* free buffer */
        media_free_ext_buffer(MOD_MMI, (void **)&pData);
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        return MDI_RES_SWFLASH_ERR_READ_FILE;
    }

    /* fs read error 2 */
    if (nSize != nRead)
    {
        /* free buffer */
        media_free_ext_buffer(MOD_MMI, (void **)&pData);
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        return MDI_RES_SWFLASH_ERR_READ_FILE_PARTIAL;
    }

    /* Create HCIMFILE instance */
    cim_adm_malloc();
    mdi_swflash_p->file_handle = CimCreateHandle(pData, nSize);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_CREATEHANDLE, (int)pData, nSize,
               (int)mdi_swflash_p->file_handle);
    /* free buffer */
    media_free_ext_buffer(MOD_MMI, (void **)&pData);

    if (mdi_swflash_p->file_handle == NULL)

    {
        cim_adm_free();
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        return MDI_RES_SWFLASH_ERR_CREATE_HCIMFILE;
    }

    /* Get string attributes */
    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_titlenode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->title, (PS8) cim_string);
    }
    else
    {
        info->title[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_filenamenode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->filename, (PS8) cim_string);
    }
    else
    {
        info->filename[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_authornode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->author, (PS8) cim_string);
    }
    else
    {
        info->author[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_companynode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->company, (PS8) cim_string);
    }
    else
    {
        info->company[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_datenode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->date, (PS8) cim_string);
    }
    else
    {
        info->date[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_timenode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->time, (PS8) cim_string);
    }
    else
    {
        info->time[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_preinstallnode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->preinstall, (PS8) cim_string);
    }
    else
    {
        info->preinstall[0] = 0;
    }

    /* Get int attributes */
    cimret = CimGetRecInt(mdi_swflash_p->file_handle, (unsigned short *)_curlennode, (int *)&info->curlen);
    if (cimret != 1)
    {
        info->curlen = -1;
    }

    cimret = CimGetRecInt(mdi_swflash_p->file_handle, (unsigned short *)_sizenode, (int *)&info->size);
    if (cimret != 1)
    {
        info->size = -1;
    }

    cimret = CimGetRecInt(mdi_swflash_p->file_handle, (unsigned short *)_categorynode, (int *)&info->category);
    if (cimret != 1)
    {
        info->category = -1;
    }

    /* create cim_handle */
    if (info->curlen == info->size)
    {
        /* Open CIM instance, and remember to close it by Cim2Close) */
        ASSERT(mdi_swflash_p->cim_handle == NULL);
        mdi_swflash_p->error = 0;
        if (cim_get_audiohandle() != NULL)
        {
            cim_trace1("audio handle = 0x%x in open_file", (int)cim_get_audiohandle());
            cim_reset_audiohandle();
        }

        mdi_swflash_p->playmode = playmode;
        if (IsSilentModeActivated() || IsMeetingModeActivated())
        {
            mdi_swflash_p->cim_handle = Cim2Open(mdi_swflash_p->file_handle, (void *)NULL, playmode | CIM_UNPLAYSOUND, &mdi_swflash_p->error);
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_2OPEN, (int)mdi_swflash_p->cim_handle,
                       playmode | CIM_UNPLAYSOUND, mdi_swflash_p->error, mdi_swflash_p->cim_handle);
        }
        else
        {
            mdi_swflash_p->cim_handle = Cim2Open(mdi_swflash_p->file_handle, (void *)NULL, playmode, &mdi_swflash_p->error);
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_2OPEN, (int)mdi_swflash_p->cim_handle, playmode,
                       mdi_swflash_p->error, mdi_swflash_p->cim_handle);
        }

        if (mdi_swflash_p->cim_handle == NULL)
        {
            CimFreeHandle(mdi_swflash_p->file_handle);
            SWFLASH_DBG_PRINT1("free file handle3.9, HFILE=[0x%x]", (int)mdi_swflash_p->file_handle);
            mdi_swflash_p->file_handle = NULL;
            cim_adm_free();
            FS_Close(mdi_swflash_p->fd);
            mdi_swflash_p->fd = -1;
            return (MDI_RES_SWFLASH_ERR_CREATE_CIM - mdi_swflash_p->error);
        }
        else
        {
            int width = 0;
            int height = 0;

            Cim2GetSize(mdi_swflash_p->cim_handle, (int*)&width, (int*)&height);
            info->width = width;
            info->height = height;

            return MDI_RES_SWFLASH_SUCCEED;
        }
    }
    else
    {
        CimFreeHandle(mdi_swflash_p->file_handle);
        SWFLASH_DBG_PRINT1("free file handle4, HFILE=[0x%x]", (int)mdi_swflash_p->file_handle);
        mdi_swflash_p->file_handle = NULL;
        cim_adm_free();
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        return MDI_RES_SWFLASH_PARTIAL_CMP;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_close_file
 * DESCRIPTION
 *  close file and release resource
 * PARAMETERS
 *  void
 * RETURNS   close result
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_close_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_CLOSEFILE);

    mdi_swflash_p->swflash_layer_handle = 0;
    mdi_swflash_p->cim_buffer = NULL;
    mdi_swflash_p->layer_width = 0;
    mdi_swflash_p->layer_height = 0;

    /* free cim handle */
    if (mdi_swflash_p->cim_handle != NULL)
    {
        ret = Cim2Close(mdi_swflash_p->cim_handle);
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_2CLOSE, (int)mdi_swflash_p->cim_handle);
        
        if (ret == 0) /* fail */
        {

            mdi_swflash_stop_download_file();
         //   kal_prompt_trace(MOD_MMI, "cimtoclose fail");
            FS_Close(mdi_swflash_p->fd);
            mdi_swflash_p->fd = -1;
            return MDI_RES_SWFLASH_CLOSE_FAIL;

        }
        else
        {
            mdi_swflash_p->cim_handle = NULL;

            /* free file handle */
            if (mdi_swflash_p->file_handle != NULL)
            {
                CimFreeHandle(mdi_swflash_p->file_handle);
                SWFLASH_DBG_PRINT1("free file handle5, HFILE=[0x%x]", (int)mdi_swflash_p->file_handle);
                mdi_swflash_p->file_handle = NULL;
                mdi_swflash_stop_download_file();
                 FS_Close(mdi_swflash_p->fd);
                 mdi_swflash_p->fd = -1;
                return MDI_RES_SWFLASH_SUCCEED;
            }
            else
            {
                mdi_swflash_stop_download_file();
                FS_Close(mdi_swflash_p->fd);
                mdi_swflash_p->fd = -1;
                return MDI_RES_SWFLASH_CLOSE_FAIL;
            }
        }
    }
    else
    {
        return MDI_RES_SWFLASH_CIM_NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_open_id
 * DESCRIPTION
 *  open works by resource id
 * PARAMETERS
 *  id              resource id       
 *  playmode        play mode        
 *  info            works info
 * RETURNS          open result
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_open_id(U16 id, U32 playmode, mdi_swflash_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *pData = NULL;
    int nSize = -1;
    int cimret = 0;
    unsigned short *cim_string = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_OPENID);

    /* If a swflash content is alredy opened, popup a message to indicate it */
    if (mdi_swflash_p->state != MDI_SWFLASH_PL_STATE_NULL)
        return MDI_RES_SWFLASH_BUSY;

    pData = GetImage(id);
    if (pData == NULL)
    {
        return MDI_RES_SWFLASH_ERR_FAILED;
    }

    nSize = ((*(pData + 5) + *(pData + 4) * 256) +  *(pData + 3)) * 256 + *(pData + 2);
    cim_adm_malloc();
    /* Create HCIMFILE instance */
    mdi_swflash_p->file_handle = CimCreateHandle(pData + 8, nSize);
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_CREATEHANDLE, (int)(pData + 8), nSize,
               (int)mdi_swflash_p->file_handle);
    SWFLASH_DBG_PRINT3(
        "create file handle4, data=[0x%x], size=%d => HFILE=[0x%x]",
        (int)pData,
        nSize,
        (int)mdi_swflash_p->file_handle);

    if (mdi_swflash_p->file_handle == NULL)

    {
        cim_adm_free();
        return MDI_RES_SWFLASH_ERR_CREATE_HCIMFILE;
    }

    /* Get string attributes */
    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_titlenode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->title, (PS8) cim_string);
    }
    else
    {
        info->title[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_filenamenode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->filename, (PS8) cim_string);
    }
    else
    {
        info->filename[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_authornode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->author, (PS8) cim_string);
    }
    else
    {
        info->author[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_companynode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->company, (PS8) cim_string);
    }
    else
    {
        info->company[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_datenode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->date, (PS8) cim_string);
    }
    else
    {
        info->date[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_timenode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->time, (PS8) cim_string);
    }
    else
    {
        info->time[0] = 0;
    }

    cimret = CimGetRecString(mdi_swflash_p->file_handle, (unsigned short *)_preinstallnode, (unsigned short **)&cim_string);
    if (cimret == 1 && cim_string != NULL)
    {
        mmi_ucs2cpy((PS8) info->preinstall, (PS8) cim_string);
    }
    else
    {
        info->preinstall[0] = 0;
    }

    /* Get int attributes */
    cimret = CimGetRecInt(mdi_swflash_p->file_handle, (unsigned short *)_curlennode, (int *)&info->curlen);
    if (cimret != 1)
    {
        info->curlen = -1;
    }

    cimret = CimGetRecInt(mdi_swflash_p->file_handle, (unsigned short *)_sizenode, (int *)&info->size);
    if (cimret != 1)
    {
        info->size = -1;
    }

    cimret = CimGetRecInt(mdi_swflash_p->file_handle, (unsigned short *)_categorynode, (int *)&info->category);
    if (cimret != 1)
    {
        info->category = -1;
    }

    /* Open CIM instance, and remember to close it by Cim2Close) */
    ASSERT(mdi_swflash_p->cim_handle == NULL);
    mdi_swflash_p->error = 0;
    if (cim_get_audiohandle() != NULL)
    {
        cim_trace1("audio handle = 0x%x in open_id", (int)cim_get_audiohandle());
        cim_reset_audiohandle();
    }

    mdi_swflash_p->playmode = playmode;

    if (IsSilentModeActivated() || IsMeetingModeActivated())
    {
        mdi_swflash_p->cim_handle = Cim2Open(mdi_swflash_p->file_handle, (void *)NULL, playmode | CIM_UNPLAYSOUND, &mdi_swflash_p->error);
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_2OPEN, (int)mdi_swflash_p->cim_handle,
                   playmode | CIM_UNPLAYSOUND, mdi_swflash_p->error, mdi_swflash_p->cim_handle);
    }
    else
    {
        mdi_swflash_p->cim_handle = Cim2Open(mdi_swflash_p->file_handle, (void *)NULL, playmode, &mdi_swflash_p->error);
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_2OPEN, (int)mdi_swflash_p->cim_handle, playmode,
                   mdi_swflash_p->error, mdi_swflash_p->cim_handle);
    }

    if (mdi_swflash_p->cim_handle == NULL)
    {

        CimFreeHandle(mdi_swflash_p->file_handle);
        SWFLASH_DBG_PRINT1("free file handle4, HFILE=[0x%x]", (int)mdi_swflash_p->file_handle);
        mdi_swflash_p->file_handle = NULL;
        cim_adm_free();
        return (MDI_RES_SWFLASH_ERR_CREATE_CIM - mdi_swflash_p->error);
    }
    else
    {
        int width = 0;
        int height = 0;

        Cim2GetSize(mdi_swflash_p->cim_handle, (int*)&width, (int*)&height);
        info->width = width;
        info->height = height;
        return MDI_RES_SWFLASH_SUCCEED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_close_id
 * DESCRIPTION
 *  close resource id
 * PARAMETERS
 *  void
 * RETURNS close result
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_close_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_CLOSEID);

    mdi_swflash_p->swflash_layer_handle = 0;
    mdi_swflash_p->cim_buffer = NULL;
    mdi_swflash_p->layer_width = 0;
    mdi_swflash_p->layer_height = 0;

    /* free cim handle */
    if (mdi_swflash_p->cim_handle != NULL)
    {
        ret = Cim2Close(mdi_swflash_p->cim_handle);
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_2CLOSE, (int)mdi_swflash_p->cim_handle);
        
        if (ret == 0) /* fail */
        {
            mdi_swflash_stop_download_file();

            return MDI_RES_SWFLASH_CLOSE_FAIL;
        }
        else
        {
            mdi_swflash_p->cim_handle = NULL;

            /* free file handle */
            if (mdi_swflash_p->file_handle != NULL)
            {
                CimFreeHandle(mdi_swflash_p->file_handle);
                SWFLASH_DBG_PRINT1("free file handle7, HFILE=[0x%x]", (int)mdi_swflash_p->file_handle);
                mdi_swflash_p->file_handle = NULL;
                mdi_swflash_stop_download_file();
                return MDI_RES_SWFLASH_SUCCEED;
            }
            else
            {
                mdi_swflash_stop_download_file();
                return MDI_RES_SWFLASH_CLOSE_FAIL;
            }
        }
    }
    else
    {
        return MDI_RES_SWFLASH_CIM_NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_play
 * DESCRIPTION
 *  the function of play
 * PARAMETERS
 *  layer_handle                play layer handle      
 *  repeat_count                repeat count        
 *  audio_path                  audio path        
 *  play_result_callback        call back for play result        
 *  is_interaction_on(?)        is_interaction_on        
 *  is_visual_on(?)             is_visual_on        
 *  is_audio_on(?)              is_audio_on        
 *  is_vibrate_on(?)            is_vibrate_on       
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_play(
            gdi_handle layer_handle,
            U16 repeat_count,
            U8 audio_path,
            void (*play_result_callback) (MDI_RESULT))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;
    S32 width, height;
    U8 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_PLAY);

    mdi_swflash_p->swflash_layer_handle = layer_handle;
    cim_set_play_layer(layer_handle);
    cim_set_audio_end(MMI_FALSE);

    gdi_layer_push_and_set_active(mdi_swflash_p->swflash_layer_handle);
    gdi_layer_get_buffer_ptr(&mdi_swflash_p->cim_buffer);
    gdi_layer_get_dimension(&width, &height);
    mdi_swflash_p->layer_width = width;
    mdi_swflash_p->layer_height = height;
   // mdi_swflash_p->bpp = (gdi_layer_get_bit_per_pixel() >> 3);
	mdi_swflash_p->bpp=2;
    gdi_layer_pop_and_restore_active();

    ret = Cim2SetBuffer(
            mdi_swflash_p->cim_handle,
                        mdi_swflash_p->layer_width,
                        mdi_swflash_p->layer_height,
                        mdi_swflash_p->layer_width * mdi_swflash_p->bpp,    /* pitch in byte */
                        mdi_swflash_p->bpp * 8,                   /* bit per pixel */
                        (void *)mdi_swflash_p->cim_buffer);

    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_2SETBUFFER, (int)mdi_swflash_p->cim_handle, mdi_swflash_p->layer_width, mdi_swflash_p->layer_height, mdi_swflash_p->layer_width * mdi_swflash_p->bpp,    /* pitch in byte */
        mdi_swflash_p->bpp * 8,                   /* bit per pixel */
        (int*)mdi_swflash_p->cim_buffer);

    if (ret == 0)
    {
        return MDI_RES_SWFLASH_ERR_SET_CIM_BUFFER;
    }

    if (mdi_swflash_p->cim_handle != NULL)
    {
        SetProtocolEventHandler(mdi_swflash_pl_audio_ind_handler, MSG_ID_MDI_SWFLASH_PL_AUDIO_IND);

        ret = Cim2Play(mdi_swflash_p->cim_handle);
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_2PLAY, (int)mdi_swflash_p->cim_handle);

        if (ret == 0) /* fail */
        {
            return MDI_RES_SWFLASH_PLAY_FAIL;
        }
        else
        {
            if (audio_path == 0xFF)
            {
                g_first_frame = 1;
            }

            if ((mdi_swflash_p->playmode == CIM_PLAYERMODE)
                && (cim_get_audiohandle() == NULL)
                && (mdi_swflash_p->fromplayer == MMI_TRUE)
                && (audio_path!=0xFF))
            {
                mmi_swflash_option_play_played();
            }

        /*block mmi task temporately,waitting for decode complete*/
           for(count=0;count<15;count++)
                {
                    if((Cim2HandleEvent(mdi_swflash_p->cim_handle, CIMM_TIMER, 0, 0))==1)
                    {
                    mdi_swflash_update_frame();
	                break;
                    }
                }
            
            return MDI_RES_SWFLASH_SUCCEED;
        }
    }
    else
    {
        return MDI_RES_SWFLASH_CIM_NULL;
    }

    return MDI_RES_SWFLASH_ERR_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_stop
 * DESCRIPTION
 *  the function of stop
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_STOP);

    if (mdi_swflash_p->cim_handle != NULL)
    {
        ret = Cim2Stop(mdi_swflash_p->cim_handle);
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_2STOP, (int)mdi_swflash_p->cim_handle);

        if (ret == 0) /* fail */
        {
            return MDI_RES_SWFLASH_STOP_FAIL;

        }
        else
        {
            if ((mdi_swflash_p->playmode == CIM_PLAYERMODE)
                && (cim_get_audiohandle() == NULL) && (mdi_swflash_p->fromplayer == MMI_TRUE))
            {
                mmi_swflash_option_play_stopped();
            }

            return MDI_RES_SWFLASH_SUCCEED;
        }
    }
    else
    {
        return MDI_RES_SWFLASH_CIM_NULL;
    }

    return MDI_RES_SWFLASH_ERR_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_pause
 * DESCRIPTION
 *  the function of pause
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_PAUSE);

    if (mdi_swflash_p->cim_handle != NULL)
    {
        ret = Cim2Pause(mdi_swflash_p->cim_handle);
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_2PAUSE, (int)mdi_swflash_p->cim_handle);

        if (ret == 0) /* fail */
        {
            return MDI_RES_SWFLASH_PAUSE_FAIL;
        }
        else
        {
            if ((mdi_swflash_p->playmode == CIM_PLAYERMODE)
                && (cim_get_audiohandle() == NULL) && (mdi_swflash_p->fromplayer == MMI_TRUE))
            {
                mmi_swflash_option_play_paused();
            }

            return MDI_RES_SWFLASH_SUCCEED;
        }
    }
    else
    {
        return MDI_RES_SWFLASH_CIM_NULL;
    }

    return MDI_RES_SWFLASH_ERR_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_resume
 * DESCRIPTION
 *  the function of resume
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_RESUME);

    if (mdi_swflash_p->cim_handle != NULL)
    {
        ret = Cim2Resume(mdi_swflash_p->cim_handle);
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_2RESUME, (int)mdi_swflash_p->cim_handle);

        if (ret == 0) /* fail */
        {
            return MDI_RES_SWFLASH_RESUME_FAIL;
        }
        else
        {
            if ((mdi_swflash_p->playmode == CIM_PLAYERMODE)
                && (cim_get_audiohandle() == NULL) && (mdi_swflash_p->fromplayer == MMI_TRUE))
            {
                mmi_swflash_option_play_resumed();
            }

            return MDI_RES_SWFLASH_SUCCEED;
        }
    }
    else
    {
        return MDI_RES_SWFLASH_CIM_NULL;
    }

    return MDI_RES_SWFLASH_ERR_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_enable_audio
 * DESCRIPTION
 * enable_audio
 * PARAMETERS
 *  void
 * RETURNS function result
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_enable_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_ENABLE_AUDIO);

    mdi_swflash_p->is_audio_on = TRUE;

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_disable_audio
 * DESCRIPTION
 * disable_audio 
 * PARAMETERS
 *  void
 * RETURNS
 *  function result
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_disable_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_DISABLE_AUDIO);

    mdi_swflash_p->is_audio_on = FALSE;

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_enable_vibrate
 * DESCRIPTION
 *  enable_vibrate
 * PARAMETERS
 *  void
 * RETURNS
 *  function result
 *****************************************************************************/
MDI_RESULT mdi_swflash_enable_vibrate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_ENABLE_VIBRATE);

    mdi_swflash_p->is_vibrate_on = TRUE;

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_disable_vibrate
 * DESCRIPTION
 *  disable_vibrate
 * PARAMETERS
 *  void
 * RETURNS
 *  function result
 *****************************************************************************/
MDI_RESULT mdi_swflash_disable_vibrate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_DISABLE_VIBRATE);

    mdi_swflash_p->is_vibrate_on = FALSE;

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_enable_interaction
 * DESCRIPTION
 *  enable_interaction
 * PARAMETERS
 *  void
 * RETURNS
 *  function result
 *****************************************************************************/
MDI_RESULT mdi_swflash_enable_interaction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_ENABLE_INTERACT);

    mdi_swflash_p->is_interact_on = TRUE;

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_disable_interaction
 * DESCRIPTION
 *  disable_interaction
 * PARAMETERS
 *  void
 * RETURNS
 *  function result
 *****************************************************************************/
MDI_RESULT mdi_swflash_disable_interaction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_DISABLE_INTERACT);

    mdi_swflash_p->is_interact_on = FALSE;

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_check_download_file
 * DESCRIPTION
 *  start download the swflash file from server
 * PARAMETERS
 *  descriptor_filename     [IN]        Cmp filename (descriptor for how to dl)
 *  total_len               [OUT]       Total size
 *  current_len             [OUT]       Current downloaded size
 *  category                [?]         the category of works
 * RETURNS
 *  Check download result
 * RETURN VALUE LIST
 *  MDI_RES_SWFLASH_SUCCEED              succeed
 *  MDI_RES_SWFLASH_ERR_FILE_ERROR       file access error
 *  MDI_RES_SWFLASH_ERR_ENGINE_ERROR     engine error
 *****************************************************************************/
MDI_RESULT mdi_swflash_check_download_file(
            U16 *descriptor_filename,
            U32 *total_len,
            U32 *current_len,
            U32 *category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 file_size;
    U32 read_size;
    S32 fs_ret;
    S32 cim_ret;
    PS8 filedata_buf_p = NULL;
    HCIMFILE hFile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_CHECK_DOWNLAOD_FILE);
    
    MMI_ASSERT(descriptor_filename != NULL);

    /* init category */
    *category = 0;

    /* open file */
    file_handle = FS_Open((U16*) descriptor_filename, FS_READ_ONLY);

    if (file_handle >= 0)
    {
        /* read from memory */
        FS_GetFileSize(file_handle, &file_size);

        if (file_size > MAX_SWFLASH_FILE_DATA_BUFFER_SIZE)
        {
            /* file size too big */
            FS_Close(file_handle);
            return MDI_RES_SWFLASH_ERR_FILE_ERROR;
        }

        /* alloc buffer */
        media_get_ext_buffer(MOD_MMI, (void **)&filedata_buf_p, file_size);

        /* mem allocate shall not failed */
        MMI_ASSERT(filedata_buf_p != NULL);

        fs_ret = FS_Read(file_handle, (U16*) filedata_buf_p, file_size, &read_size);
        FS_Close(file_handle);

        /* fs read error 1 */
        if (fs_ret < 0)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);
            filedata_buf_p = NULL;
            return MDI_RES_SWFLASH_ERR_FILE_ERROR;
        }

        /* fs read error 2 */
        if (file_size != read_size)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);
            filedata_buf_p = NULL;
            return MDI_RES_SWFLASH_ERR_READ_FILE_PARTIAL;
        }

        /* create cim file handle */
        cim_adm_malloc();
        hFile = CimCreateHandle(filedata_buf_p, file_size);
        /* MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_CIM_CREATE_HANDLE_RESULT, mdi_swflash_p->dl_file_handle); */
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_CREATEHANDLE, (int)filedata_buf_p, file_size, (int)hFile);
        SWFLASH_DBG_PRINT3(
            "create file handle5, data=[0x%x], size=%d => HFILE=[0x%x]",
            (int)filedata_buf_p,
            file_size,
            (int)hFile);

        /* free buffer */
        media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);
        filedata_buf_p = NULL;

        if (hFile == NULL)
        {
            /* create cim file handle error */
            cim_adm_free();
            return MDI_RES_SWFLASH_ERR_ENGINE_ERROR;
        }
    }
    else
    {
        /* open file error */
        return MDI_RES_SWFLASH_ERR_FILE_ERROR;
    }

    /* get total length */
    cim_ret = CimGetRecInt(hFile, (unsigned short *)_sizenode, (int *)total_len);
    if ((cim_ret != 1)||((*total_len) > MAX_SWFLASH_FILE_DATA_BUFFER_SIZE))
    {
        CimFreeHandle(hFile);
        hFile = NULL;
        cim_adm_free();
        return MDI_RES_SWFLASH_ERR_ENGINE_ERROR;
    }

    /* get current length */
    cim_ret = CimGetRecInt(hFile, (unsigned short *)_curlennode, (int *)current_len);
    if ((cim_ret != 1)||((*current_len) > MAX_SWFLASH_FILE_DATA_BUFFER_SIZE))
    {
        CimFreeHandle(hFile);
        hFile = NULL;
        cim_adm_free();
        return MDI_RES_SWFLASH_ERR_ENGINE_ERROR;
    }

    /* get category */
    cim_ret = CimGetRecInt(hFile, (unsigned short *)_categorynode, (int *)category);
    if (cim_ret != 1)
    {
        CimFreeHandle(hFile);
        hFile = NULL;
        cim_adm_free();
        return MDI_RES_SWFLASH_ERR_ENGINE_ERROR;
    }

    /* free handle */
    CimFreeHandle(hFile);
    SWFLASH_DBG_PRINT1("free file handle8, HFILE=[0x%x]", (int)hFile);
    hFile = NULL;
    cim_adm_free();
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_FREEHANDLE, (int)hFile);

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_start_download_file
 * DESCRIPTION
 *  start download the swflash file from server
 * PARAMETERS
 *  descriptor_filename     [IN]        Cmp filename (descriptor for how to dl)
 *  save_filename           [IN]        Result cmp filename
 *  nwk_accound_id          [IN]        Network account id
 *  result_callback         [IN]        Callback function for dl result
 *  progress_callback       [IN]        Callback function for progress report (downloaded:total)
 * RETURNS
 *  Start download result
 * RETURN VALUE LIST
 *  MDI_RES_SWFLASH_SUCCEED              succeed
 *  MDI_RES_SWFLASH_ERR_FILE_ERROR       file access error
 *  MDI_RES_SWFLASH_ERR_ENGINE_ERROR     engine error
 *  MDI_RES_SWFLASH_ERR_NETWORK_ERROR    network error
 *****************************************************************************/
MDI_RESULT mdi_swflash_start_download_file(
            S8 *descriptor_filename,
            S8 *save_filename,
            S32 nwk_accound_id,
            mdi_swflash_dl_result_callback result_callback,
            mdi_swflash_dl_progress_callback progress_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 file_size;
    U32 read_size;
    S32 fs_ret;
    S32 str_len;
    PS8 filedata_buf_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_START_DOWNLAOD_FILE);
    
    MMI_ASSERT(result_callback != NULL);
    MMI_ASSERT(progress_callback != NULL);
    MMI_ASSERT(save_filename != NULL);
    MMI_ASSERT(descriptor_filename != NULL);
    MMI_ASSERT(mdi_swflash_p->savename_buf_p == NULL);
    MMI_ASSERT(mdi_swflash_p->session_handle == 0);

    /* register socket handler from swflash_socket callback */
    SetProtocolEventHandler(mdi_swflash_dl_socket_ind_handler, MSG_ID_MDI_SWFLASH_DL_SOCKET_IND);

    mdi_swflash_p->dl_result_callback = result_callback;
    mdi_swflash_p->dl_progress_callback = progress_callback;

    /* pass nwk id and seq num to cimdep */
    cim_dl_soc_set_para(nwk_accound_id, mdi_swflash_p->seq_num);

    /* alloc buffer */
    media_get_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->savename_buf_p, FMGR_PATH_BUFFER_SIZE);

    /* mem allocate shall not failed */
    MMI_ASSERT(mdi_swflash_p->savename_buf_p != NULL);

    /* store save filename */
    mmi_ucs2cpy(mdi_swflash_p->savename_buf_p, save_filename);
    str_len = mmi_ucs2strlen(mdi_swflash_p->savename_buf_p);
    MMI_ASSERT(str_len <= FMGR_PATH_CHAR_COUNT);
    
    /* open file */
    file_handle = FS_Open((U16*) descriptor_filename, FS_READ_ONLY);

    if (file_handle >= 0)
    {
        /* read from memory */
        FS_GetFileSize(file_handle, &file_size);

        if (file_size > MAX_SWFLASH_FILE_DATA_BUFFER_SIZE)
        {
            /* file size too big */
            FS_Close(file_handle);
            media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->savename_buf_p);
            mdi_swflash_p->savename_buf_p = NULL;
            return MDI_RES_SWFLASH_ERR_FILE_ERROR;
        }

        /* alloc buffer */
        media_get_ext_buffer(MOD_MMI, (void **)&filedata_buf_p, file_size);

        /* mem allocate shall not failed */
        MMI_ASSERT(filedata_buf_p != NULL);

        fs_ret = FS_Read(file_handle, (U16*) filedata_buf_p, file_size, &read_size);
        FS_Close(file_handle);

        /* fs read error 1 */
        if (fs_ret < 0)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);
            media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->savename_buf_p);
            mdi_swflash_p->savename_buf_p = NULL;
            return MDI_RES_SWFLASH_ERR_FILE_ERROR;
        }

        /* fs read error 2 */
        if (file_size != read_size)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);
            media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->savename_buf_p);
            mdi_swflash_p->savename_buf_p = NULL;
            return MDI_RES_SWFLASH_ERR_READ_FILE_PARTIAL;
        }

        /* create cim file handle */
        cim_adm_malloc();
        mdi_swflash_p->dl_file_handle = CimCreateHandle(filedata_buf_p, file_size);

        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_CIM_CREATEHANDLE, (int)filedata_buf_p, file_size,
                   (int)mdi_swflash_p->dl_file_handle);
        SWFLASH_DBG_PRINT3(
            "create file handle6, data=[0x%x], size=%d => HFILE=[0x%x]",
            (int)filedata_buf_p,
            file_size,
            (int)mdi_swflash_p->dl_file_handle);

        /* free buffer */
        media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);

        if (mdi_swflash_p->dl_file_handle == NULL)
        {
            /* create cim file handle error */
            media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->savename_buf_p);
            mdi_swflash_p->savename_buf_p = NULL;
            cim_adm_free();
            return MDI_RES_SWFLASH_ERR_ENGINE_ERROR;
        }
    }
    else
    {
        /* open file error */
        media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->savename_buf_p);
        mdi_swflash_p->savename_buf_p = NULL;
        return MDI_RES_SWFLASH_ERR_FILE_ERROR;
    }

    /* create Session */
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_CIM_SE_CREATE_RESULT, mdi_swflash_p->session_handle);    
    mdi_swflash_p->session_handle = CimSECreate(mdi_swflash_p->dl_file_handle);

    if (mdi_swflash_p->session_handle == NULL)
    {
        /* create session failed */
        media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->savename_buf_p);
        mdi_swflash_p->savename_buf_p = NULL;
        CimFreeHandle(mdi_swflash_p->dl_file_handle);
        mdi_swflash_p->dl_file_handle = NULL;
        cim_adm_free();
        return MDI_RES_SWFLASH_ERR_NETWORK_ERROR;
    }

    mdi_swflash_p->dl_state = MDI_SWFLASH_DL_STATE_CONNTECTING;

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_stop_download_file
 * DESCRIPTION
 *  stop download
 * PARAMETERS
 *  void
 * RETURNS
 *  Stop result
 * RETURN VALUE LIST
 *  MDI_RES_SWFLASH_SUCCEED      succeed
 *****************************************************************************/
MDI_RESULT mdi_swflash_stop_download_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_STOP_DOWNLOAD_FILE);
    
    if (mdi_swflash_p->savename_buf_p != NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->savename_buf_p);
        mdi_swflash_p->savename_buf_p = NULL;        
    }

    /* free file handle and close socket session */
    if (mdi_swflash_p->dl_file_handle != NULL)
    {
        CimFreeHandle(mdi_swflash_p->dl_file_handle);
        SWFLASH_DBG_PRINT1("free file handle9, HFILE=[0x%x]", (int)mdi_swflash_p->dl_file_handle);
        mdi_swflash_p->dl_file_handle = NULL;
    }

    if (mdi_swflash_p->session_handle != NULL)
    {
        CimSEDestroy(mdi_swflash_p->session_handle);
        mdi_swflash_p->session_handle = NULL;        
    }

    /* increase seq num, this is used to avoid re-entry problem */
    mdi_swflash_p->seq_num++;
    cim_adm_free();
    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_dl_socket_ind_handler
 * DESCRIPTION
 *  socket indication handler
 * PARAMETERS
 *  msg_ptr     [IN]        Message data
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_swflash_dl_socket_ind_handler(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cim_dl_soc_ind_msg_struct *ind_msg;
    FS_HANDLE file_handle;
    S32 data_size;
    U32 write_size;
    S32 fs_ret;
    S8 *cim_data_p;
    U8 filefullname[FMGR_MAX_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#define MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE()                                \
do {                                                                        \
    media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->savename_buf_p); \
    mdi_swflash_p->savename_buf_p = NULL;                                    \
    CimFreeHandle(mdi_swflash_p->dl_file_handle);                            \
    SWFLASH_DBG_PRINT1("free file handle10, HFILE=[0x%x]", (int)mdi_swflash_p->dl_file_handle); \
    mdi_swflash_p->dl_file_handle = NULL;                                    \
    CimSEDestroy(mdi_swflash_p->session_handle);                             \
    mdi_swflash_p->session_handle = NULL;                                    \
} while(0);
    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_HDLR);

#ifdef SWFLASH_SOC_DEBUG    
    /* sleep some time for tst to send log */
    kal_sleep_task(300);
#endif /* SWFLASH_SOC_DEBUG */
    
    ind_msg = (cim_dl_soc_ind_msg_struct*) msg_ptr;

    if (ind_msg->seq_num != mdi_swflash_p->seq_num)
    {
        /* 
         * seq_num not matched, this message is expired, 
         * someone may already called stop function 
        */
        return;
    }

    switch (ind_msg->notify_event)
    {
            /* download finish / download state */
        case CIM_DL_SOC_NOTIFY_DL_COMPLETE:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_COMPLETE);

            /* read data from cim engine, write to file */
            CimGetFileData(mdi_swflash_p->dl_file_handle, (void**)&cim_data_p, &data_size);

            /* check if memory exceed valid size - memory corrupt */
            MMI_ASSERT(data_size <= MAX_SWFLASH_FILE_DATA_BUFFER_SIZE);

            file_handle = FS_Open((U16*) mdi_swflash_p->savename_buf_p, FS_READ_WRITE | FS_CREATE_ALWAYS);
            /* XXX */
            if (file_handle > 0)
            {
                /* open file ok */
                fs_ret = FS_Write(file_handle, (void*)cim_data_p, data_size, &write_size);
                FS_Close(file_handle);
                 
                if (fs_ret == FS_DISK_FULL)
                {
                    /* disk full */
                    MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();                    
                    mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_DISK_FULL);
                    return;
                }   
                else if (fs_ret < 0)
                {
                    /* other fs write error */
                    MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();                    
                    mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_FILE_ERROR);
                    return;
                }
                else if (fs_ret == FS_WRITE_PROTECTION)
                {
                    /* write protection */
                    MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();                
                    mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_DISK_WRITE_PROTECT);
                    return;            
                }
            }
            else
            {
                /* other fs write error */
                MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();                
                mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_FILE_ERROR);
                return;
            }

            /* file save compilete */
            MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();            
            mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_DL_COMPLETE);
            break;

        case CIM_DL_SOC_NOTIFY_DL_STATUS:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_STATUS);        

            /* XXX save cim data */

            /* read data from cim engine, write to file */
            CimGetFileData(mdi_swflash_p->dl_file_handle, (void **)&cim_data_p, &data_size);

            /* check if memory exceed valid size - memory corrupt */
            MMI_ASSERT(data_size <= MAX_SWFLASH_FILE_DATA_BUFFER_SIZE);

            mmi_ucs2cpy((PS8) filefullname, (PS8) mdi_swflash_p->savename_buf_p);

            file_handle = FS_Open((U16*) filefullname, FS_READ_WRITE | FS_CREATE_ALWAYS);

            if (file_handle > 0)
            {
                /* open file ok */
                fs_ret = FS_Write(file_handle, (void*)cim_data_p, data_size, &write_size);
                FS_Close(file_handle);
            }
            else
            {
                MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();
                mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_FILE_ERROR);
                return;
            }
            /* call callback to update UI */
            mdi_swflash_p->dl_progress_callback(ind_msg->current_dl_size, ind_msg->total_dl_size);
            break;

            /* Success case, need to notify engine */
        case CIM_DL_SOC_NOTIFY_CONNECT_OK:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_CONNET_OK);
            CimSEHandleEvent(mdi_swflash_p->session_handle, SEM_CONNECT_OK, 0, 0);
            break;

        case CIM_DL_SOC_NOTIFY_SEND_OK:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_SEND_OK);
            CimSEHandleEvent(mdi_swflash_p->session_handle, SEM_SEND_OK, 0, 0);
            break;

        case CIM_DL_SOC_NOTIFY_RECV_OK:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_RECV_OK);
            CimSEHandleEvent(mdi_swflash_p->session_handle, SEM_RECV_OK, 0, 0);
            break;

        case CIM_DL_SOC_NOTIFY_DNS_OK:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_DNS_OK);
            CimSEHandleEvent(mdi_swflash_p->session_handle, SEM_DNS_OK, 0, 0);
            break;

            /* Failed case, need to notify engine */
        case CIM_DL_SOC_NOTIFY_CONNECT_FAILED:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_CONNECT_FAIL);
            CimSEHandleEvent(mdi_swflash_p->session_handle, SEM_CONNECT_FAIL, 0, 0);
            MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();
            mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_NETWORK_ERROR);
            break;

        case CIM_DL_SOC_NOTIFY_SEND_FAILED:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_SEND_FAIL);
            CimSEHandleEvent(mdi_swflash_p->session_handle, SEM_SEND_FAIL, 0, 0);
            MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();
            mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_NETWORK_ERROR);
            break;

        case CIM_DL_SOC_NOTIFY_RECV_FAILED:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_RECV_FAIL);
            CimSEHandleEvent(mdi_swflash_p->session_handle, SEM_RECV_FAIL, 0, 0);
            MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();
            mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_NETWORK_ERROR);
            break;

        case CIM_DL_SOC_NOTIFY_DNS_FAILED:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_DNS_FAIL);
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
        #endif /* 0 */ 
            CimSEHandleEvent(mdi_swflash_p->session_handle, SEM_DNS_FAIL, 0, 0);
            MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();
            mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_NETWORK_ERROR);
            break;

            /* Failed case, need to notify caller */
        case CIM_DL_SOC_NOTIFY_FILE_ERROR:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_FILE_ERROR);
            MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();
            mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_FILE_ERROR);
            break;

        case CIM_DL_SOC_NOTIFY_DISK_FULL:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_DISK_FULL);
            MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();
            mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_DISK_FULL);
            break;

        case CIM_DL_SOC_NOTIFY_SOCKET_ERROR:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_SOCKET_ERROR);           
            MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();            
            mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_SOCKET_ERROR);
            break;

        case CIM_DL_SOC_NOTIFY_SERVER_ERROR:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_SERVER_ERROR);  
            MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();           
            mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_SERVER_ERROR);
            break;

        case CIM_DL_SOC_NOTIFY_HTTP_FAILED:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_HTTP_FAIL);           
            MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();            
            mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_HTTP_FAILED);
            break;

        case CIM_DL_SOC_NOTIFY_UNKNOWN:
            MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_DL_SOCKET_IND_UNKNOWN);           
            MDI_SWFLASH_FREE_SOCKET_DL_RESOURCE();            
            mdi_swflash_p->dl_result_callback(MDI_SWFLASH_SOC_NOTIFY_UNKNOWN);
            break;

        default:
            MMI_ASSERT(0);
            
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_pl_audio_ind_handler
 * DESCRIPTION
 *  audio indication handler
 * PARAMETERS
 *  msg_ptr     [IN]        Message data
 * RETURNS
 *  void
 *****************************************************************************/
static void mdi_swflash_pl_audio_ind_handler(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cim_pl_aud_ind_msg_struct *ind_msg;
    int ret = 0;
    long haudio;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_INFO, MMI_SWFLASH_MDI_CIM_PL_AUD_IND_HDLR);

    ind_msg = (cim_pl_aud_ind_msg_struct*) msg_ptr;
    haudio = (long)cim_get_audiohandle();

    SWFLASH_DBG_PRINT1("SOUND EVENT = %d", ind_msg->notify_event);

    switch (ind_msg->notify_event)
    {
        case CIM_PL_AUD_NOTIFY_OPEN:
            ret = Cim2HandleEvent(
                    mdi_swflash_p->cim_handle,
                    CIMM_ESNOTIFY,
                    haudio,
                CIMES_OPRES_SUCCESSFUL | (unsigned int)CIMES_OPSTATE_OPEN << 16);
            break;
        case CIM_PL_AUD_NOTIFY_PLAY:
            if ((mdi_swflash_p->playmode == CIM_PLAYERMODE) && (mdi_swflash_p->fromplayer == MMI_TRUE))
            {   
            mmi_swflash_option_play_played();
            }
            break;
        case CIM_PL_AUD_NOTIFY_PAUSE:
            ret = Cim2HandleEvent(
                    mdi_swflash_p->cim_handle,
                    CIMM_ESNOTIFY,
                    haudio,
                CIMES_OPRES_SUCCESSFUL | (unsigned int)CIMES_OPSTATE_PAUSE << 16);

            if ((mdi_swflash_p->playmode == CIM_PLAYERMODE) && (mdi_swflash_p->fromplayer == MMI_TRUE))
            {
            mmi_swflash_option_play_paused();
            }
            break;
        case CIM_PL_AUD_NOTIFY_RESUME:
            ret = Cim2HandleEvent(
                    mdi_swflash_p->cim_handle,
                    CIMM_ESNOTIFY,
                    haudio,
                CIMES_OPRES_SUCCESSFUL | (unsigned int)CIMES_OPSTATE_RESUME << 16);

            if ((mdi_swflash_p->playmode == CIM_PLAYERMODE) && (mdi_swflash_p->fromplayer == MMI_TRUE))
            {
            mmi_swflash_option_play_resumed();
            }
            break;
        case CIM_PL_AUD_NOTIFY_REPLAY:
            ret = Cim2HandleEvent(
                    mdi_swflash_p->cim_handle,
                    CIMM_ESNOTIFY,
                    haudio,
                CIMES_OPRES_SUCCESSFUL | (unsigned int)CIMES_OPSTATE_PLAY << 16);
            break;
        case CIM_PL_AUD_NOTIFY_STOP:
            if ((mdi_swflash_p->playmode == CIM_PLAYERMODE) && (mdi_swflash_p->fromplayer == MMI_TRUE))
            {
               if(cim_check_audio_end()==MMI_TRUE)
               {
                 Cim2Stop(mdi_swflash_p->cim_handle);
                 cim_set_audio_end(MMI_FALSE);
               }
            mmi_swflash_option_play_stopped();
            }
            break;
        case CIM_PL_AUD_NOTIFY_CLOSE:
            break;
        case CIM_PL_AUD_NOTIFY_FAIL:
            ret = Cim2HandleEvent(mdi_swflash_p->cim_handle, CIMM_ESNOTIFY, (long)0, CIMES_OPRES_FAILURE);
            break;
        default:
            ASSERT(0);
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_update_frame
 * DESCRIPTION
 *  blt the decoded result to lcd
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_update_frame(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int src_offset_x = 0;
    int src_offset_y = 0;
    int src_width = 0;
    int src_height = 0;
    int layer_offset_x = 0;
    int layer_offset_y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_UPDATEFRAME);

    /* SWFLASH_DBG_PRINT1("[chaotex] layer_handle = %x", (int)mdi_swflash_p->swflash_layer_handle); */

    if (mdi_swflash_p->swflash_layer_handle != NULL)
    {
        Cim2GetUpdateRect(mdi_swflash_p->cim_handle, &src_offset_x, &src_offset_y, &src_width, &src_height);
//      SWFLASH_DBG_PRINT3("[chaotex] src_offset_x = %d, src_width = %d, src_height = %d", src_offset_x, src_width, src_height);
        gdi_layer_push_and_set_active(mdi_swflash_p->swflash_layer_handle);
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
        gdi_layer_blt_previous(
            layer_offset_x + src_offset_x - 1,
                                layer_offset_y + src_offset_y - 1,
                                layer_offset_x + src_width + src_offset_x - 1,
                                layer_offset_y + src_height + src_offset_y - 1);
        gdi_layer_pop_and_restore_active();

        if (g_first_frame == 1)
        {
            mdi_swflash_stop();
            g_first_frame = 0;
        }

    }
    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_key_down_event
 * DESCRIPTION
 *  transfer key_down_event to cim engine
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_key_down_event(kal_uint16 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long cim_key = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* XXX */
    //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_UPDATEFRAME);

    switch (key)
    {
        case KEY_0:
            cim_key = CIM_KEY_ENTER;
            break;
        case KEY_1:
            cim_key = CIM_KEY_1;
            break;
        case KEY_2:
            cim_key = CIM_KEY_2;
            break;
        case KEY_3:
            cim_key = CIM_KEY_3;
            break;
        case KEY_4:
            cim_key = CIM_KEY_4;
            break;
        case KEY_5:
            cim_key = CIM_KEY_5;
            break;
        case KEY_6:
            cim_key = CIM_KEY_6;
            break;
        case KEY_7:
            cim_key = CIM_KEY_7;
            break;
        case KEY_8:
            cim_key = CIM_KEY_8;
            break;
        case KEY_9:
            cim_key = CIM_KEY_9;
            break;
        case KEY_STAR:
            cim_key = CIM_KEY_ASTERISK;
            break;
        case KEY_POUND:
            cim_key = CIM_KEY_SHARP;
            break;
        case KEY_UP_ARROW:
            cim_key = CIM_KEY_UP;
            break;
        case KEY_DOWN_ARROW:
            cim_key = CIM_KEY_DOWN;
            break;
        case KEY_LEFT_ARROW:
            cim_key = CIM_KEY_LEFT;
            break;
        case KEY_RIGHT_ARROW:
            cim_key = CIM_KEY_RIGHT;
            break;
        case KEY_ENTER:
            cim_key = CIM_KEY_ENTER;
            break;
        case KEY_BACK:
            cim_key = CIM_KEY_BACKSPACE;
            break;
        case KEY_SEND:
            cim_key = CIM_KEY_TAB;
            break;
        default:
            ASSERT(0);
            break;
    }

    Cim2HandleEvent(mdi_swflash_p->cim_handle, CIMM_KEYDOWN, cim_key, 0);

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_key_up_event
 * DESCRIPTION
 *  transfer key_up_event to cim engine
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_key_up_event(kal_uint16 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long cim_key = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* XXX */
    /* MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_UPDATEFRAME); */

    switch (key)
    {
        case KEY_0:
            cim_key = CIM_KEY_ENTER;
            break;
        case KEY_1:
            cim_key = CIM_KEY_1;
            break;
        case KEY_2:
            cim_key = CIM_KEY_2;
            break;
        case KEY_3:
            cim_key = CIM_KEY_3;
            break;
        case KEY_4:
            cim_key = CIM_KEY_4;
            break;
        case KEY_5:
            cim_key = CIM_KEY_5;
            break;
        case KEY_6:
            cim_key = CIM_KEY_6;
            break;
        case KEY_7:
            cim_key = CIM_KEY_7;
            break;
        case KEY_8:
            cim_key = CIM_KEY_8;
            break;
        case KEY_9:
            cim_key = CIM_KEY_9;
            break;
        case KEY_STAR:
            cim_key = CIM_KEY_ASTERISK;
            break;
        case KEY_POUND:
            cim_key = CIM_KEY_SHARP;
            break;
        case KEY_UP_ARROW:
            cim_key = CIM_KEY_UP;
            break;
        case KEY_DOWN_ARROW:
            cim_key = CIM_KEY_DOWN;
            break;
        case KEY_LEFT_ARROW:
            cim_key = CIM_KEY_LEFT;
            break;
        case KEY_RIGHT_ARROW:
            cim_key = CIM_KEY_RIGHT;
            break;
        case KEY_ENTER:
            cim_key = CIM_KEY_ENTER;
            break;
        case KEY_BACK:
            cim_key = CIM_KEY_BACKSPACE;
            break;
        case KEY_SEND:
            cim_key = CIM_KEY_TAB;
            break;
        default:
            ASSERT(0);
            break;
    }

    Cim2HandleEvent(mdi_swflash_p->cim_handle, CIMM_KEYUP, cim_key, 0);

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_pen_down_event
 * DESCRIPTION
 *  transfer pen_down_event to cim engine
 * PARAMETERS
 *  x       [IN]coordinate        
 *  y       [IN]coordinate        
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_pen_down_event(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cim2HandleEvent(mdi_swflash_p->cim_handle, CIMM_MOUSEDOWN, (long)x, (long)y);

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_pen_up_event
 * DESCRIPTION
 *  transfer pen_up_event to cim engine
 * PARAMETERS
 *  x       [IN]coordinate        
 *  y       [IN]coordinate        
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_pen_up_event(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cim2HandleEvent(mdi_swflash_p->cim_handle, CIMM_MOUSEUP, (long)x, (long)y);

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_pen_move_event
 * DESCRIPTION
 *  transfer pen move event to cim engine
 * PARAMETERS
 *  x       [IN]coordinate        
 *  y       [IN]coordinate        
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_pen_move_event(S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Cim2HandleEvent(mdi_swflash_p->cim_handle, CIMM_MOUSEMOVE, (long)x, (long)y);

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_get_cimhandle
 * DESCRIPTION
 *  get cim handle
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
HCIM mdi_swflash_get_cimhandle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_swflash_p->cim_handle;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_set_is_from_player
 * DESCRIPTION
 *  set from player flag
 * PARAMETERS
 *  from_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_swflash_set_is_from_player(MMI_BOOL from_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_swflash_p->fromplayer = from_player;
    cim_set_from_player(from_player);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_free_text_layer
 * DESCRIPTION
 *  free text layer
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/

void mdi_swflash_free_text_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cim_get_text_layer() != GDI_LAYER_EMPTY_HANDLE)
    {
        cim_free_text_layer();
    }
}

#endif /* defined(SWFLASH_CHAOTEX) */ 

#ifdef SWFLASH_NEOMTEL

#include "SWflashDef.h"
#include "s3w_common.h"
#include "s3w_adapter.h"
#include "s3w_interface.h"

/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_init
 * DESCRIPTION
 *  init values
 * PARAMETERS
 *  void
 * RETURNS          void
 *  
 *****************************************************************************/

void mdi_swflash_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_swflash_p->instance = NULL;
    mdi_swflash_p->decipher_buffer = NULL;
    
    mdi_swflash_p->swflash_layer_handle = 0;
    mdi_swflash_p->decode_buffer = NULL;
    mdi_swflash_p->layer_width = 0;
    mdi_swflash_p->layer_height = 0;
    mdi_swflash_p->fd = -1 ;
    mdi_swflash_p->is_first_frame = MMI_FALSE;
    mdi_swflash_p->is_loop= MMI_FALSE;
    mdi_swflash_p->is_fromplayer= MMI_FALSE;
    mdi_swflash_p->post_blt = NULL;
    mdi_swflash_p->pre_blt = NULL;
    mdi_swflash_p->back_buffer = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_set_imei
 * DESCRIPTION
 *  
 * PARAMETERS
 *  imei            imei number
 * RETURNS          void
 *  
 *****************************************************************************/

void mdi_swflash_set_imei(S8 *imei)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy(mdi_swflash_p->imei, imei);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_malloc_mem
 * DESCRIPTION
 * malloc_mem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_swflash_malloc_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_swflash_p->mem_ptr== NULL)
    {
        media_get_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->mem_ptr, MMI_SWFLASH_MEM_BUFFER_SIZE);
        MMI_ASSERT(mdi_swflash_p->mem_ptr != NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_free_mem
 * DESCRIPTION
 * free_mem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_swflash_free_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_swflash_p->mem_ptr!= NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->mem_ptr);
        mdi_swflash_p->mem_ptr = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_open_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        file full name        
 *  playmode        play mode        
 *  info            the info of swflash works
 * RETURNS          open result
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_open_file(const S8 *filename, U32 playmode, mdi_swflash_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;
    int nSize = 0;
    int outsize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_OPENFILE);
    kal_prompt_trace(MOD_MMI,"playmode =%x",playmode);
    mdi_swflash_p->fd = -1;
    /* If a swflash content is already opened, popup a message to indicate it */
    if (mdi_swflash_p->state != MDI_SWFLASH_PL_STATE_NULL)
    {
        return MDI_RES_SWFLASH_BUSY;
    }

    if ((mdi_swflash_p->fd = FS_Open((const WCHAR*)filename, FS_READ_ONLY)) < 0)
    {
        return MDI_RES_SWFLASH_ERR_OPEN_FILE;
    }

    if ((ret = FS_GetFileSize(mdi_swflash_p->fd, (U32*)& nSize)) != RTF_NO_ERROR)
    {
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        return MDI_RES_SWFLASH_ERR_OPEN_FILE;
    }

    if (nSize <= 0 || nSize > MMI_SWFLASH_MAX_FILE_DATA_BUFFER_SIZE)
    {
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        return MDI_RES_SWFLASH_ERR_GET_FILE_SIZE;
    }

    /* decipher */
    /* alloc buffer */
    media_get_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->decipher_buffer, nSize);
    MMI_ASSERT(mdi_swflash_p->decipher_buffer != NULL);
    
    ret= mmi_swflash_vis_decipher(mdi_swflash_p->fd, (const S8 *)filename, nSize, mdi_swflash_p->decipher_buffer,&wgui_swflash_info.type, &outsize);
    MMI_TRACE(MMI_TRACE_G8_MEDIA,MMI_SWFLASH_APP_DECIPHER,ret);

    
    if(ret == MMI_TRUE)
    {
        mdi_swflash_p->size = outsize;
        mdi_swflash_malloc_mem();
        mdi_swflash_p->playmode = playmode;
        wgui_swflash_info.width = LCD_WIDTH;
        wgui_swflash_info.height= LCD_WIDTH;
        return MDI_RES_SWFLASH_SUCCEED;
    }
    else
    {
        if(mdi_swflash_p->decipher_buffer != NULL)
        {    
            media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->decipher_buffer);
            mdi_swflash_p->decipher_buffer = NULL;
        }
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd=-1;
        return MDI_RES_SWFLASH_ERR_FAILED    ;               
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_close_file
 * DESCRIPTION
 *  close file and release resource
 * PARAMETERS
 *  void
 * RETURNS   close result
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_close_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_CLOSEFILE);
    
    mdi_swflash_p->swflash_layer_handle = 0;
    mdi_swflash_p->decode_buffer = NULL;
    mdi_swflash_p->layer_width = 0;
    mdi_swflash_p->layer_height = 0;

    /*stop loop and stop updating screen*/
    mdi_swflash_p->is_loop = MMI_FALSE;
    s3wa_cancel_timer(mdi_swflash_p,(void *)&(mdi_swflash_p->playmode));
    
    /* free handle */
	mdi_swflash_register_blt_callback(NULL,NULL);
    if(mdi_swflash_p->decipher_buffer != NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->decipher_buffer);
        mdi_swflash_p->decipher_buffer = NULL;
    }
 
    if(mdi_swflash_p->back_buffer!= NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->back_buffer);
        mdi_swflash_p->back_buffer = NULL;
    }
    if (mdi_swflash_p->fd != -1)
    {
        FS_Close(mdi_swflash_p->fd);
        mdi_swflash_p->fd = -1;
        mdi_swflash_free_mem();
        return MDI_RES_SWFLASH_SUCCEED;
    }
    else
    {
        mdi_swflash_free_mem();
        return MDI_RES_SWFLASH_ERR_FAILED;
     }
    
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_open_id
 * DESCRIPTION
 *  open works by resource id
 * PARAMETERS
 *  id              resource id       
 *  playmode        play mode        
 *  info            works info
 * RETURNS          open result
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_open_id(U16 id, U32 playmode, mdi_swflash_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pData = NULL;
    U32 nSize = 0;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_OPENID);

    /* If a swflash content is alredy opened, popup a message to indicate it */
    if (mdi_swflash_p->state != MDI_SWFLASH_PL_STATE_NULL)
        return MDI_RES_SWFLASH_BUSY;

    pData = (U8*)GetImage(id);
    if (pData == NULL)
    {
        return MDI_RES_SWFLASH_ERR_FAILED;
    }

    nSize = *(pData + 4) * 256*256 +  *(pData + 3) * 256 + *(pData + 2);
  	
	/* alloc buffer */
    media_get_ext_buffer(MOD_MMI, (void **)&(mdi_swflash_p->decipher_buffer), nSize);
    MMI_ASSERT(mdi_swflash_p->decipher_buffer != NULL);

    memcpy(mdi_swflash_p->decipher_buffer, pData+8, nSize);
    
    mdi_swflash_malloc_mem();
    mdi_swflash_p->size = nSize;
    mdi_swflash_p->playmode = playmode;
    wgui_swflash_info.width = LCD_WIDTH;
    wgui_swflash_info.height= LCD_WIDTH;
    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_close_id
 * DESCRIPTION
 *  close resource id
 * PARAMETERS
 *  void
 * RETURNS close result
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_close_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_CLOSEID);

    mdi_swflash_p->swflash_layer_handle = 0;
    mdi_swflash_p->layer_width = 0;
    mdi_swflash_p->layer_height = 0;
    mdi_swflash_p->size = 0;
    mdi_swflash_p->playmode = 0;
    wgui_swflash_info.width = 0;
    wgui_swflash_info.height= 0;

    if(mdi_swflash_p->decipher_buffer != NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->decipher_buffer);
        mdi_swflash_p->decipher_buffer = NULL;
    }

    if(mdi_swflash_p->back_buffer!= NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->back_buffer);
        mdi_swflash_p->back_buffer = NULL;
    }
    mdi_swflash_free_mem();
    mdi_swflash_register_blt_callback(NULL,NULL);
    return MDI_RES_SWFLASH_SUCCEED;
          
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_on_end
 * DESCRIPTION
 *  callback for play end
 * PARAMETERS
 *  void
 * RETURNS          void
 *  
 *****************************************************************************/

void mdi_swflash_on_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_RELEASE,mdi_swflash_p->instance); 
    if (mdi_swflash_p->instance!= NULL)
    {
        s3wi_release(mdi_swflash_p->instance);
        MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_APP_RELEASE, (int)mdi_swflash_p->instance);
        mdi_swflash_p->instance= NULL;
    }   
    if(mdi_swflash_p->is_loop == MMI_TRUE)
    {
        mdi_swflash_play(mdi_swflash_p->swflash_layer_handle, 0, MDI_DEVICE_SPEAKER_BOTH, NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_set_is_from_player
 * DESCRIPTION
 *  set from player flag
 * PARAMETERS
 *  from_player     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mdi_swflash_set_is_from_player(MMI_BOOL from_player)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_swflash_p->is_fromplayer = from_player;
}

/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS          MDI_RESULT
 *  
 *****************************************************************************/

MDI_RESULT mdi_swflash_play(
            gdi_handle layer_handle,
            U16 repeat_count,
            U8 audio_path,
            void (*play_result_callback) (MDI_RESULT))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned char ret = 0;
    S32 width, height,offsetx,offsety;
    s3w_data_info data_info;
    U8 count =0;
    
    U32 buffer_size = 0;
    U8 bpp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_PLAY);
    
    MMI_ASSERT(layer_handle != NULL);
    if(repeat_count == 0)
    {
        mdi_swflash_p->is_loop=MMI_TRUE;   
        mdi_swflash_p->is_fromplayer =MMI_FALSE;
    }
    else
    {
        mdi_swflash_p->is_loop=MMI_FALSE;
    }
    mdi_swflash_p->swflash_layer_handle = layer_handle;
    mdi_swflash_p->play_result = play_result_callback;
    mdi_swflash_p->is_ready_update = MMI_FALSE;
    bpp=2;

    gdi_layer_push_and_set_active(mdi_swflash_p->swflash_layer_handle);
    gdi_layer_get_buffer_ptr(&mdi_swflash_p->decode_buffer);
    gdi_layer_get_dimension(&width, &height);
    gdi_layer_get_position(&offsetx,&offsety);
    mdi_swflash_p->layer_width = width;
    mdi_swflash_p->layer_height = height;
    mdi_swflash_p->layer_offsetx = offsetx;
    mdi_swflash_p->layer_offsety = offsety;
    gdi_layer_clear_background(GDI_COLOR_WHITE);

    buffer_size = mdi_swflash_p->layer_width*mdi_swflash_p->layer_height*bpp;
    gdi_layer_pop_and_restore_active();

   /*player init*/
    s3wi_memory_init((char *)mdi_swflash_p->mem_ptr, MMI_SWFLASH_MEM_BUFFER_SIZE);
    data_info.data_type = S3W_DATA_MEMORY;
    data_info.file_type = S3W_CONTENTS_FILE;
    data_info.file_url[0] = 0x00;
    data_info.stream = mdi_swflash_p->decipher_buffer;
    data_info.stream_size = mdi_swflash_p->size;
    data_info.stream_self_free = 0;

    ret=s3h_isValidFile(NULL, &data_info);
	if(ret !=1)
	{
        return MDI_RES_SWFLASH_ERR_LOAD;
	}  
    
	if(mdi_swflash_p->back_buffer == NULL)
    {
        media_get_ext_buffer(MOD_MMI, (void **)&mdi_swflash_p->back_buffer, buffer_size);
        MMI_ASSERT(mdi_swflash_p->back_buffer != NULL);
    }
    mdi_swflash_p->instance = s3wi_create(mdi_swflash_p, NULL, 
                              MMI_SWFLASH_MEM_BUFFER_SIZE*0.8, MMI_SWFLASH_PERFORMANCE);
    if(mdi_swflash_p->instance == NULL)
    {
        return MDI_RES_SWFLASH_ERR_CREATE_INSTANCE;
    }

    
    ret=s3wi_load(mdi_swflash_p->instance, &data_info, S3W_DATA_MEMORY,
                  TRUE, FALSE);/*default: do not loop and play back ground sound*/
    if(ret == 0)
    {
        s3wi_release( mdi_swflash_p->instance);
        mdi_swflash_p->instance = NULL;
        return MDI_RES_SWFLASH_ERR_LOAD;
    }
    
    /*sound control*/
    if ((IsSilentModeActivated()==MMI_TRUE||IsMeetingModeActivated() ==MMI_TRUE)
    	  && (mdi_swflash_p->playmode == VIS_PLAYER))
    {
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
    }

    if(mdi_swflash_p->playmode == VIS_PLAYER)
    {
        mdi_audio_set_headset_mode_output_path(audio_path);
    }

    if(mdi_swflash_p->playmode == VIS_PLAYER)
    {
        s3wi_sound_on(mdi_swflash_p->instance);
    }
    else
    {
        s3wi_sound_off(mdi_swflash_p->instance);
    }
    /*begin to play*/
    s3wi_play(mdi_swflash_p->instance);

    /*if it is the reenter after interruptted,then just one frame and no sound*/
    if (audio_path == 0xFF)
    {
        mdi_swflash_p->is_first_frame= MMI_TRUE;
        s3wi_sound_off(mdi_swflash_p->instance);
    }
    /*wait till the decode screen is ready*/
    for(count=0;count<10;count++)/*try 10 times ,avoid to block MMI tash too long*/
    {
        if(mdi_swflash_p->is_ready_update == MMI_FALSE)
        {
            ret=s3wi_process(mdi_swflash_p->instance, (void *)&(mdi_swflash_p->playmode));
            kal_prompt_trace(MOD_MMI,"count =%d,ret=%d",count,ret);
        }
        else
        {
            break;
        }
    }    
    return MDI_RES_SWFLASH_SUCCEED;
     
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_stop
 * DESCRIPTION
 *  play stop
 * PARAMETERS
 *  void
 * RETURNS          MDI_RESULT
 *  
 *****************************************************************************/

MDI_RESULT mdi_swflash_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_STOP);
    if(mdi_swflash_p->instance != NULL)
    {
        mdi_swflash_p->is_loop = MMI_FALSE;
        s3wi_stop(mdi_swflash_p->instance);
        return MDI_RES_SWFLASH_SUCCEED;
    }
    else
    {
        return MDI_RES_SWFLASH_ERR_FAILED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_pause
 * DESCRIPTION
 *  play pause
 * PARAMETERS
 *  void
 * RETURNS          MDI_RESULT
 *  
 *****************************************************************************/

MDI_RESULT mdi_swflash_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_PAUSE);
    if(mdi_swflash_p->instance != NULL)
    {
        ret=s3wi_pause(mdi_swflash_p->instance);
        if(ret==1)
        {
            return MDI_RES_SWFLASH_SUCCEED;
        }
        else
        {
            return MDI_RES_SWFLASH_ERR_FAILED;
        }
    }
    else
    {
        return MDI_RES_SWFLASH_ERR_FAILED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_resume
 * DESCRIPTION
 *  swflash resume
 * PARAMETERS
 *  void
 * RETURNS          MDI_RESULT
 *  
 *****************************************************************************/

MDI_RESULT mdi_swflash_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_RESUME);
    if(mdi_swflash_p->instance != NULL)
    {
        ret=s3wi_resume(mdi_swflash_p->instance);
        
        if(ret==1)
        {
            return MDI_RES_SWFLASH_SUCCEED;
        }
        else
        {
            return MDI_RES_SWFLASH_ERR_FAILED;
        }
    }
    else
    {
        return MDI_RES_SWFLASH_ERR_FAILED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_check_download_file
 * DESCRIPTION
 *  start download the swflash file from server
 * PARAMETERS
 *  descriptor_filename     [IN]        Cmp filename (descriptor for how to dl)
 *  total_len               [OUT]       Total size
 *  current_len             [OUT]       Current downloaded size
 *  category                [?]         the category of works
 * RETURNS
 *  Check download result
 * RETURN VALUE LIST
 *  MDI_RES_SWFLASH_SUCCEED              succeed
 *  MDI_RES_SWFLASH_ERR_FILE_ERROR       file access error
 *  MDI_RES_SWFLASH_ERR_ENGINE_ERROR     engine error
 *****************************************************************************/
MDI_RESULT mdi_swflash_check_download_file(
            U16 *descriptor_filename,
            U32 *total_len,
            U32 *current_len,
            U32 *category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 file_size;
    U32 read_size;
    S32 fs_ret;
    PS8 filedata_buf_p = NULL;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_G8_MEDIA, MDI_SWFLASH_CHECK_DOWNLAOD_FILE);
    
    MMI_ASSERT(descriptor_filename != NULL);

    /* init category */
    *category = 0;

    /* open file */
    file_handle = FS_Open((U16*) descriptor_filename, FS_READ_ONLY);

    if (file_handle >= 0)
    {
        /* read from memory */
        FS_GetFileSize(file_handle, &file_size);

        if ((file_size > MMI_SWFLASH_MAX_FILE_DATA_BUFFER_SIZE)||
			(file_size <=0))
        {
            /* file size too big */
            FS_Close(file_handle);
            return MDI_RES_SWFLASH_ERR_FILE_ERROR;
        }

        /* alloc buffer */
        media_get_ext_buffer(MOD_MMI, (void **)&filedata_buf_p, file_size);

        /* mem allocate shall not failed */
        MMI_ASSERT(filedata_buf_p != NULL);

        fs_ret = FS_Read(file_handle, (U16*) filedata_buf_p, file_size, &read_size);
        FS_Close(file_handle);

        /* fs read error 1 */
        if (fs_ret < 0)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);
            filedata_buf_p = NULL;
            return MDI_RES_SWFLASH_ERR_FILE_ERROR;
        }

        /* fs read error 2 */
        if (file_size != read_size)
        {
            /* free buffer */
            media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);
            filedata_buf_p = NULL;
            return MDI_RES_SWFLASH_ERR_READ_FILE_PARTIAL;
        }
        
          /* free buffer */
        media_free_ext_buffer(MOD_MMI, (void **)&filedata_buf_p);
        filedata_buf_p = NULL;

        *total_len=read_size;
        *current_len = read_size;
        return MDI_RES_SWFLASH_SUCCEED;
    }
    else
    {
        /* open file error */
        return MDI_RES_SWFLASH_ERR_FILE_ERROR;
    }

  
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_key_down_event
 * DESCRIPTION
 *  transfer key_down_event to cim engine
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_key_down_event(kal_uint16 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long vis_key = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* XXX */
    //MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_UPDATEFRAME);

    switch (key)
    {
        case KEY_0:
            vis_key = SIS3_KEY_0;
            break;
        case KEY_1:
            vis_key = SIS3_KEY_1;
            break;
        case KEY_2:
            vis_key = SIS3_KEY_2;
            break;
        case KEY_3:
            vis_key = SIS3_KEY_3;
            break;
        case KEY_4:
            vis_key = SIS3_KEY_4;
            break;
        case KEY_5:
            vis_key = SIS3_KEY_5;
            break;
        case KEY_6:
            vis_key = SIS3_KEY_6;
            break;
        case KEY_7:
            vis_key = SIS3_KEY_7;
            break;
        case KEY_8:
            vis_key = SIS3_KEY_8;
            break;
        case KEY_9:
            vis_key = SIS3_KEY_9;
            break;
        case KEY_STAR:
            vis_key = SIS3_KEY_ASTERISK;
            break;
        case KEY_POUND:
            vis_key = SIS3_KEY_POUND;
            break;
        case KEY_UP_ARROW:
            vis_key = SIS3_KEY_UP;
            break;
        case KEY_DOWN_ARROW:
            vis_key = SIS3_KEY_DOWN;
            break;
        case KEY_LEFT_ARROW:
            vis_key = SIS3_KEY_LEFT;
            break;
        case KEY_RIGHT_ARROW:
            vis_key = SIS3_KEY_RIGHT;
            break;
        case KEY_ENTER:
            vis_key = SIS3_KEY_SELECT;
            break;
        case KEY_SEND:
            vis_key = SIS3_KEY_SEND;
            break;
        default:
            ASSERT(0);
            break;
    }

    s3wi_key_down(mdi_swflash_p->instance, vis_key);
	s3wi_key_pressed(mdi_swflash_p->instance, vis_key);
    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_key_up_event
 * DESCRIPTION
 *  transfer key_up_event to cim engine
 * PARAMETERS
 *  key     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MDI_RESULT mdi_swflash_key_up_event(kal_uint16 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long vis_key = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* XXX */
    /* MMI_TRACE(MMI_TRACE_G8_MEDIA, MMI_SWFLASH_MDI_CIM_UPDATEFRAME); */

    switch (key)
    {
     case KEY_0:
            vis_key = SIS3_KEY_0;
            break;
        case KEY_1:
            vis_key = SIS3_KEY_1;
            break;
        case KEY_2:
            vis_key = SIS3_KEY_2;
            break;
        case KEY_3:
            vis_key = SIS3_KEY_3;
            break;
        case KEY_4:
            vis_key = SIS3_KEY_4;
            break;
        case KEY_5:
            vis_key = SIS3_KEY_5;
            break;
        case KEY_6:
            vis_key = SIS3_KEY_6;
            break;
        case KEY_7:
            vis_key = SIS3_KEY_7;
            break;
        case KEY_8:
            vis_key = SIS3_KEY_8;
            break;
        case KEY_9:
            vis_key = SIS3_KEY_9;
            break;
        case KEY_STAR:
            vis_key = SIS3_KEY_ASTERISK;
            break;
        case KEY_POUND:
            vis_key = SIS3_KEY_POUND;
            break;
        case KEY_UP_ARROW:
            vis_key = SIS3_KEY_UP;
            break;
        case KEY_DOWN_ARROW:
            vis_key = SIS3_KEY_DOWN;
            break;
        case KEY_LEFT_ARROW:
            vis_key = SIS3_KEY_LEFT;
            break;
        case KEY_RIGHT_ARROW:
            vis_key = SIS3_KEY_RIGHT;
            break;
        case KEY_ENTER:
            vis_key = SIS3_KEY_MENU;
            break;
        case KEY_SEND:
            vis_key = SIS3_KEY_SEND;
            break;
        default:
            ASSERT(0);
            break;
    }

    s3wi_key_released(mdi_swflash_p->instance, vis_key);

    return MDI_RES_SWFLASH_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_register_blt_callback
 * DESCRIPTION
 *  register the pre and post draw function
 * PARAMETERS
 *  void
 * RETURNS          void
 *  
 *****************************************************************************/
 void mdi_swflash_register_blt_callback(
        void (*per_blt_callback)(S32 offset_x, S32 offset_y, S32 width, S32 height), 
        void (*post_blt_callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mdi_swflash_p->pre_blt= per_blt_callback;
    mdi_swflash_p->post_blt= post_blt_callback;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swflash_transform_info
 * DESCRIPTION
 *  store the attribute of works to screen string buffer 
 * PARAMETERS
 *  str        [in] print string pointer
 * RETURNS
 *  MDI_RESULT whether transform succeed
 *****************************************************************************/
MDI_RESULT mdi_swflash_transform_info(S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret = -1;
    unsigned char* cpname=NULL;
    s3w_data_info data_info;
    s3_char_set_type charset;
    S8 swflash_size[10];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    /*player init*/
    
    s3wi_memory_init((char *)mdi_swflash_p->mem_ptr, MMI_SWFLASH_MEM_BUFFER_SIZE);
  
    data_info.data_type = S3W_DATA_MEMORY;
    data_info.file_type = S3W_CONTENTS_FILE;
    data_info.file_url[0] = 0x00;
    data_info.stream = mdi_swflash_p->decipher_buffer;
    data_info.stream_size = mdi_swflash_p->size;
    data_info.stream_self_free = 0;
    
    ret=s3h_isValidFile(NULL, &data_info);
	if(ret !=1)
	{
        return MDI_RES_SWFLASH_ERR_LOAD;
	}  
    
    mdi_swflash_p->instance = s3wi_create(mdi_swflash_p, NULL, 
                               MMI_SWFLASH_MEM_BUFFER_SIZE*0.8, MMI_SWFLASH_PERFORMANCE);
    if(mdi_swflash_p->instance == NULL)
    {
        return MDI_RES_SWFLASH_ERR_CREATE_INSTANCE;
    }

      
    ret=s3wi_load(mdi_swflash_p->instance, &data_info, S3W_DATA_MEMORY,
                  TRUE, FALSE);
    if(ret == 0)
    {
        return MDI_RES_SWFLASH_ERR_LOAD;
    }

    /*get cp name:only load success, then s3wi_extract_cpcode can run*/
    ret = s3wi_extract_cpcode(mdi_swflash_p->instance, NULL,NULL);
    if(ret != 0)
    {  
        media_get_ext_buffer(MOD_MMI, (void **)&(cpname), sizeof(unsigned char)*ret+2);
		memset(cpname,0,sizeof(unsigned char)*ret+2);
        s3wi_extract_cpcode(mdi_swflash_p->instance, cpname,&charset);
        mmi_ucs2cpy(wgui_swflash_info.company, (S8*)cpname);
    }
   
    /*fill in other info*/
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_TITLE));
    if(wgui_swflash_info.title != NULL)
    {
        mmi_ucs2cat(str, (PS8) L" ");
        mmi_ucs2cat(str, (PS8) wgui_swflash_info.title);
    }
    
    mmi_ucs2cat(str, (PS8) L"\n");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY));

    switch (wgui_swflash_info.type)
    {
     
        case MMI_SWFLASH_TYPE_ANIMATION:
            mmi_ucs2cat(str, (PS8) L" ");
            mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_ANIMATION));
            break;
        case MMI_SWFLASH_TYPE_GAME:
            mmi_ucs2cat(str, (PS8) L" ");
            mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_CRAZYGAME));
            break;
     
        case MMI_SWFLASH_TYPE_KALAOK:
            mmi_ucs2cat(str, (PS8) L" ");
            mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_KARAOK));
            break;
      
        case MMI_SWFLASH_TYPE_MTV:
            mmi_ucs2cat(str, (PS8) L" ");
            mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_MOVIECLIP));
            break;
        default:
            mmi_ucs2cat(str, (PS8) L" ");
            mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_CATEGORY_UNKNOWN));
            break;
    }

    mmi_ucs2cat(str, (PS8) L"\n");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_SIZE));

    mmi_ucs2cat(str, (PS8) L" ");
    sprintf(swflash_size, "%u", wgui_swflash_info.size);
    mmi_asc_to_ucs2((PS8) & str[mmi_ucs2strlen((PS8) str) << 1],(PS8) swflash_size);
    mmi_ucs2cat(str, (PS8) L" ");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_BYTE));
    
    mmi_ucs2cat(str, (PS8) L"\n");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_DATE));

    if (wgui_swflash_info.date != NULL)
    {
        mmi_ucs2cat(str, (PS8) L" ");
        mmi_ucs2cat(str, (PS8) wgui_swflash_info.date);
    }

    mmi_ucs2cat(str, (PS8) L"\n");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_TIME));

    if (wgui_swflash_info.time != NULL)
    {
        mmi_ucs2cat(str, (PS8) L" ");
        mmi_ucs2cat(str, (PS8) wgui_swflash_info.time);
    }

    mmi_ucs2cat(str, (PS8) L"\n");
    mmi_ucs2cat(str, (PS8) GetString(STR_ID_SWFLASH_INFO_COMPANY));

    if (wgui_swflash_info.company != NULL)
    {
        mmi_ucs2cat(str, (PS8) L" ");
        mmi_ucs2cat(str, (PS8) wgui_swflash_info.company);
    }
    
    mmi_ucs2cat(str, (PS8) L"\0");

    if(cpname != NULL)
    {
         media_free_ext_buffer(MOD_MMI, (void **)&(cpname));
    }

    s3wi_unload(mdi_swflash_p->instance);
    s3wi_release(mdi_swflash_p->instance);
    mdi_swflash_p->instance = NULL;
    return MDI_RES_SWFLASH_SUCCEED;
}

#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_pen_down_event
 * DESCRIPTION
 *  transfer pen_down_event to vis engine
 * PARAMETERS
 *  pos       [IN]coordinate        
 * RETURNS
 *  wether need to dealed by app,if no need ,just return MMI_FALSE to dealed by category 
 *****************************************************************************/
MMI_BOOL mdi_swflash_pen_down_event(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    if(pos.y <= (mdi_swflash_p->layer_height+mdi_swflash_p->layer_offsety))
    {
   	    s3wi_on_mouse_event(mdi_swflash_p->instance, SIS3_MOUSE_BUTTON_DN, pos.x, pos.y);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_pen_up_event
 * DESCRIPTION
 *  transfer pen_down_event to vis engine
 * PARAMETERS
 *  pos       [IN]coordinate        
 * RETURNS
 *  wether need to dealed by app,if no need ,just return MMI_FALSE to dealed by category 
 *****************************************************************************/
MMI_BOOL mdi_swflash_pen_up_event(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pos.y <= (mdi_swflash_p->layer_height+mdi_swflash_p->layer_offsety))
    {
   	    s3wi_on_mouse_event(mdi_swflash_p->instance, SIS3_MOUSE_BUTTON_UP, pos.x, pos.y);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mdi_swflash_pen_move_event
 * DESCRIPTION
 *  transfer pen_down_event to vis engine
 * PARAMETERS
 *  pos       [IN]coordinate        
 * RETURNS
 *  wether need to dealed by app,if no need ,just return MMI_FALSE to dealed by category 
 *  
 *****************************************************************************/
MMI_BOOL mdi_swflash_pen_move_event(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pos.y <= (mdi_swflash_p->layer_height+mdi_swflash_p->layer_offsety))
    {
   	    s3wi_on_mouse_event(mdi_swflash_p->instance, SIS3_MOUSE_BUTTON_UP_MOVE, pos.x, pos.y);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
    

}
#endif

#endif /*SWFLASH_NEOMTEL*/
#endif /* defined(__MMI_SWFLASH__) */ 

