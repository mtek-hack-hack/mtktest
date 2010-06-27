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
 *  gdi_image_m3d.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI M3D related.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(M3D_MMI_SUPPORT)
#include "m3d_object3d.h"
#include "m3d_parser.h"
#include "m3d_graphics3d.h"
#include "m3d_class.h"
#endif

#include "gdi_internal.h"
#include "drm_gprot.h"
#include "gd_primitive.h"
#if defined(GDI_USING_M3D)

#include "kal_release.h"
#include "ScrMemMgrGprot.h"
#include "ucs2prot.h"
#include "med_api.h"
#if defined(GL_PROFILER_ENABLED)
// #define GDI_IMAGE_M3D_PROFILE
#endif 

#ifdef GDI_USING_AVATAR
#include "AvatarResDef.h"
#include "AvatarGprot.h"
#endif

#ifdef __MMI_AVATAR__
#define M3D_POOL_SIZE (450*1024)
#else
#define M3D_POOL_SIZE (400*1024)
#endif

#if (GDI_MAIN_BASE_LAYER_FORMAT != GDI_COLOR_FORMAT_16)
    #define GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY
#endif
#if defined(GDI_IMAGE_M3D_PROFILE)
#include "gui.h"
#endif 
/* Context */
typedef enum
{
    M3D_MEM_SOURCE_SCR_SHARE,
    M3D_MEM_SOURCE_OUTSIDE_MEM,
    M3D_MEM_SOURCE_MEDIA_MEM,
    M3D_MEM_SOURCE_APP_SHARE,
    M3D_MEM_SOURCE_NONE
} gdi_image_m3d_mem_source_enum;

typedef struct
{
    /* ADM pool ID */
    KAL_ADM_ID mem_pool_id;
    /* Count of allocated chunks */
    S32 alloc_count;
    U8 *buf_ptr;
    U32 buf_size;
    gdi_image_m3d_mem_source_enum buf_src;
} gdi_image_m3d_mem_cntx_struct;

typedef struct
{
    U32 image_type;
    U32 image_width;
    U32 image_height;
    U32 image_data_size;
    U32 image_data_offset;
    U8 *data_ptr;
    U8 *decoded_img_ptr;
    U8 *layer_ptr;
    gdi_handle layer_handle;
    gdi_handle anim_handle;
    MMI_BOOL free_flag;
} gdi_image_m3d_oob_cntx_struct;

S32 gdi_image_m3d_start_time;
S32 gdi_image_m3d_end_time;
BOOL gdi_image_m3d_rendering = FALSE;
BOOL gdi_image_m3d_drawing = FALSE;
static BOOL gdi_image_m3d_loaded = FALSE;
static BOOL gdi_image_m3d_inited = FALSE;

#ifdef GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY
    gdi_handle gdi_image_m3d_output_layer_handle = GDI_NULL_HANDLE;
    U8* gdi_image_m3d_output_layer_ptr = NULL;
#endif
/* static st_m3d_world* gdi_image_m3d_world; */
extern st_m3d_graphics3d m3d_graphics3d;
extern st_m3d_world *m3d_world;

#ifdef GDI_USING_AVATAR
#define GDI_IMAGE_M3D_BUFFER_SIZE 450*1024
#else
#define GDI_IMAGE_M3D_BUFFER_SIZE 300*1024
#endif
U8 gdi_image_m3d_pbFSALBuffer[FSAL_BUFFER_SIZE];
U8 *gdi_image_m3d_buffer = NULL;
static gdi_image_m3d_mem_cntx_struct gdi_image_m3d_mem_cntx = 
{
    0,
    0,
    NULL,
    0,
    M3D_MEM_SOURCE_NONE
};
static gdi_image_m3d_oob_cntx_struct gdi_image_m3d_oob_cntx = 
{
    M3D_IMAGE_TYPE_NONE,
    0,
    0,
    0,
    0,
    NULL,
    NULL,
    NULL,
    GDI_NULL_HANDLE,
    GDI_NULL_HANDLE,
    MMI_FALSE
};
int gdi_m3d_clip[4];
U16 gdi_m3d_file_name[FS_GenVFN_SIZE+8];
FS_HANDLE gdi_m3d_file_handle = 0;

/* for OOB background handling */
/*
 * static U32 gdi_image_m3d_oob_image_type;                 /// image type of OOB background
 * static U32 gdi_image_m3d_oob_image_width;                /// image width of OOB background
 * static U32 gdi_image_m3d_oob_image_height;               /// image height of OOB background
 * static U32 gdi_image_m3d_oob_image_data_size;            /// size in byte of OOB data
 * static U32 gdi_image_m3d_oob_image_data_offset;          /// offset of OOB data in the given M3D file
 * 
 * static MMI_BOOL   gdi_image_m3d_oob_need_free_flag;           /// flag to keep whether the OOB_data_ptr should be free or not 
 * static U8 *gdi_image_m3d_oob_data_ptr = NULL;          /// OOB_data_ptr, may be allocated from media task or pointed to FSAL memory block
 * static U8 *gdi_image_m3d_oob_decoded_img_ptr = NULL;   /// OOB_decoded_img_ptr, currently not used...
 * static U8 *gdi_image_m3d_oob_layer_ptr = NULL;   /// OOB_resized_img_ptr, memory block to store the decoded and resized image
 * static gdi_handle gdi_image_m3d_oob_layer_handle = GDI_NULL_HANDLE;
 * static gdi_handle gdi_image_m3d_oob_anim_handle = GDI_NULL_HANDLE;
 */

/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_mem_init
 * DESCRIPTION
 *  To create memory pool for M3D parser. The default setting is used Screen Based Share Memory
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_SUCCEED when creating successfully GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE when there is no more memory buffer
 *****************************************************************************/
GDI_RESULT gdi_image_m3d_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
#endif
    if (M3D_MEM_SOURCE_NONE == gdi_image_m3d_mem_cntx.buf_src)
    {
        gdi_image_m3d_mem_cntx.buf_size = M3D_POOL_SIZE;
        media_get_ext_buffer(MOD_MMI, (void**)&(gdi_image_m3d_mem_cntx.buf_ptr), gdi_image_m3d_mem_cntx.buf_size);
        if( !gdi_image_m3d_mem_cntx.buf_ptr )
        {
            gdi_image_m3d_mem_cntx.buf_size = 0;
            return GDI_IMAGE_ERR_MEMORY_NOT_AVAILABLE;
        }
        gdi_image_m3d_mem_cntx.buf_src = M3D_MEM_SOURCE_MEDIA_MEM;
    }

    gdi_image_m3d_mem_cntx.mem_pool_id = kal_adm_create(
                                            gdi_image_m3d_mem_cntx.buf_ptr,
                                            gdi_image_m3d_mem_cntx.buf_size,
                                            NULL,
                                            KAL_FALSE);
    gdi_image_m3d_mem_cntx.alloc_count = 0;
    return GDI_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_mallc
 * DESCRIPTION
 *  To allocate the memory buffer for M3D Pareser
 * PARAMETERS
 *  size        [IN]        The size of the memory buffer
 * RETURNS
 *  NULL : There is no more space Others : The address of the allocated memory buffer
 *****************************************************************************/
void *gdi_image_m3d_mallc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = kal_adm_alloc(gdi_image_m3d_mem_cntx.mem_pool_id, size);
    gdi_image_m3d_mem_cntx.alloc_count++;
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_free
 * DESCRIPTION
 *  Free the allocated memory buffer
 * PARAMETERS
 *  ptr     [IN]     The address of the allocated memory buffer
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_m3d_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_free(gdi_image_m3d_mem_cntx.mem_pool_id, ptr);
    gdi_image_m3d_mem_cntx.alloc_count--;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_set_m3d_clip
 * DESCRIPTION
 *  To set the clipping region of the layer
 * PARAMETERS
 *  x       [IN]        The left-top x position of the clipping region
 *  y       [IN]        The lest-top y position of the clipping region
 *  w       [IN]        The width of the clipping region
 *  h       [IN]        The height of the clipping region
 * RETURNS
 *  GDI_SUCCEED when setting successfully
 *****************************************************************************/
GDI_RESULT gdi_image_set_m3d_clip(S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_set_m3d_clip)
    gdi_m3d_clip[0] = x;
    gdi_m3d_clip[1] = y;
    gdi_m3d_clip[2] = w;
    gdi_m3d_clip[3] = h;
    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_set_m3d_clip)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_init
 * DESCRIPTION
 *  Initialize M3D module for GDI use
 * PARAMETERS
 *  width       [IN]        The width of the active layer
 *  height      [IN]        The height of the active layer
 *  buf         [IN]        The buffer pointer of the active layer
 * RETURNS
 *  GDI_SUCCEED if initializing successfully
 *****************************************************************************/
GDI_RESULT gdi_image_m3d_init(S32 width, S32 height, void *buf)
{
    GDI_ENTER_CRITICAL_SECTION(gdi_image_m3d_init)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int clip[4];
    GDI_RESULT ret = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clip[0] = 0;
    clip[1] = 0;
    clip[2] = width;
    clip[3] = height;

    if (gdi_image_m3d_inited == FALSE)
    {
        ret = gdi_image_m3d_mem_init();
        if (!ret)
        {
            ret = M3D_Initialize(M3D_APP_MMI, gdi_image_m3d_mallc, gdi_image_m3d_free);

            if (ret == M3D_SUCCESS)
            {
                gdi_image_m3d_inited = TRUE;
            }
            else
            {
                ret = GDI_IMAGE_ERR_RESOURCE_NOT_AVAILABLE;
            }
        }
    }

    if (!ret || gdi_image_m3d_inited)
    {
        m3d_world = M3D_World_new();

        /* Create OpenGL Context */
        if (EGL_NO_CONTEXT == m3d_graphics3d.context)
        {
            ret = M3D_Graphics3D_createContext();
        }
        else
        {
            ret = GDI_FAILED;
        }
    }

    if (!ret)
    {
        /* Create window surface. */
        ret = M3D_Graphics3D_bindTarget(buf, width, height, clip, 0);
    }

    if (!ret)
    {
        ret = M3D_Graphics3D_setViewport(gdi_m3d_clip[0], gdi_m3d_clip[1], gdi_m3d_clip[2], gdi_m3d_clip[3]);
    }

    if (M3D_ERROR_MEMORY_NOTAVAILABLE == ret)
    {
        gdi_image_m3d_close();
        GDI_RETURN(GDI_IMAGE_ERR_IMAGE_TOO_LARGE);
    }
    else if (ret)
    {
        gdi_image_m3d_close();
        GDI_RETURN(GDI_FAILED);
    }
    else
    {
        GDI_RETURN(GDI_SUCCEED);
    }
    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_m3d_init)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_free_oob_memory
 * DESCRIPTION
 *  Free the resource used by OOB
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_image_m3d_free_oob_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GDI_NULL_HANDLE != gdi_image_m3d_oob_cntx.layer_handle)
    {
        gdi_layer_free(gdi_image_m3d_oob_cntx.layer_handle);
        gdi_image_m3d_oob_cntx.layer_handle = GDI_NULL_HANDLE;
    }
    if (gdi_image_m3d_oob_cntx.data_ptr && gdi_image_m3d_oob_cntx.free_flag)
    {
        /* In theis case, the OOB_data_ptr is allocated from the media task memory, thus we should free it. */
        media_free_ext_buffer(MOD_MMI, (void **)&gdi_image_m3d_oob_cntx.data_ptr);
        gdi_image_m3d_oob_cntx.data_ptr = NULL;
    }

    if (gdi_image_m3d_oob_cntx.decoded_img_ptr)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&gdi_image_m3d_oob_cntx.decoded_img_ptr);
        gdi_image_m3d_oob_cntx.decoded_img_ptr = NULL;
    }

    if (gdi_image_m3d_oob_cntx.layer_ptr)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&gdi_image_m3d_oob_cntx.layer_ptr);
        gdi_image_m3d_oob_cntx.layer_ptr = NULL;
    }
    if ((GDI_NULL_HANDLE != gdi_image_m3d_oob_cntx.layer_handle) ||
        (GDI_ERROR_HANDLE != gdi_image_m3d_oob_cntx.layer_handle))
    {
        gdi_anim_stop(gdi_image_m3d_oob_cntx.anim_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_close
 * DESCRIPTION
 *  Finalize the M3D module and release the resource used by M3D
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_SUCCEED if all things is OK
 *****************************************************************************/
GDI_RESULT gdi_image_m3d_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_m3d_close)
    while (gdi_image_m3d_rendering);

    if (gdi_image_m3d_loaded)
    {
        gdi_image_m3d_loaded = FALSE;

        M3D_World_finalize(m3d_world);
    }

    if (gdi_image_m3d_inited == TRUE)
    {
        M3D_Finalize(M3D_APP_MMI);
        gdi_image_m3d_inited = FALSE;
    }

    if (gdi_image_m3d_mem_cntx.alloc_count)
    {
        kal_adm_print_log(gdi_image_m3d_mem_cntx.mem_pool_id);
        gdi_image_m3d_mem_cntx.alloc_count = 0;
    }

    if (gdi_image_m3d_mem_cntx.mem_pool_id)
    {
        kal_adm_delete(gdi_image_m3d_mem_cntx.mem_pool_id);
        gdi_image_m3d_mem_cntx.mem_pool_id = 0;
    }

    if (gdi_image_m3d_mem_cntx.buf_ptr && (M3D_MEM_SOURCE_SCR_SHARE == gdi_image_m3d_mem_cntx.buf_src))
    {
        mmi_frm_scrmem_free((void*)gdi_image_m3d_mem_cntx.buf_ptr);
        gdi_image_m3d_mem_cntx.buf_ptr = NULL;
        gdi_image_m3d_mem_cntx.buf_src = M3D_MEM_SOURCE_NONE;
    }

    if (gdi_image_m3d_mem_cntx.buf_ptr && (M3D_MEM_SOURCE_MEDIA_MEM == gdi_image_m3d_mem_cntx.buf_src))
    {
        media_free_ext_buffer(MOD_MMI, (void**)&gdi_image_m3d_mem_cntx.buf_ptr);
        gdi_image_m3d_mem_cntx.buf_ptr = NULL;
        gdi_image_m3d_mem_cntx.buf_src = M3D_MEM_SOURCE_NONE;
    }

    gdi_image_m3d_free_oob_memory();

    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_m3d_close)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_oob_callback
 * DESCRIPTION
 *  Because GIF and PNG do not support resize function(bigger), we need to do some post-process after decoding
 * PARAMETERS
 *  result      [IN]        The decoding result. We only need to do the post-process when decoding successfully
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_m3d_oob_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT res = GDI_FAILED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result >= 0)
    {
    #ifdef GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY
        if (GDI_NULL_HANDLE != gdi_image_m3d_output_layer_handle)
        {
            gdi_layer_push_and_set_active(gdi_image_m3d_output_layer_handle);
        }
    #endif
    #if defined(GDI_USING_HW_RESIZER)
        res = gdi_resizer(
            (U8*) gdi_image_m3d_oob_cntx.layer_ptr,
            gdi_image_m3d_oob_cntx.image_width,
            gdi_image_m3d_oob_cntx.image_height,
            gdi_image_m3d_oob_cntx.image_width,
            (U8*) gdi_work_buffer,
            gdi_m3d_clip[2],
            gdi_m3d_clip[3],
            0,
            0,
            gdi_m3d_clip[2] - 1,
            gdi_m3d_clip[3] - 1);
        if (GDI_SUCCEED != res)
    #endif /* defined(GDI_USING_HW_RESIZER) */ 
        {
            gd_bitblt_func bitblt;

            bitblt = gd_resize_bitblt[gdi_act_layer->vcf];
            bitblt(
                (U8*) gdi_work_buffer,
                gdi_m3d_clip[2],
                gdi_m3d_clip[3],
                0,
                0,
                gdi_m3d_clip[2] - 1,
                gdi_m3d_clip[3] - 1,
                gdi_image_m3d_oob_cntx.layer_ptr,
                gdi_image_m3d_oob_cntx.image_width,
                gdi_image_m3d_oob_cntx.image_height,
                0,
                0,
                gdi_image_m3d_oob_cntx.image_width - 1,
                gdi_image_m3d_oob_cntx.image_height - 1,
                0,
                0,
                gdi_m3d_clip[2] - 1,
                gdi_m3d_clip[3] - 1,
                0x01ffffff,
                0x01ffffff);
        }
    #ifdef GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY
        if (GDI_NULL_HANDLE != gdi_image_m3d_output_layer_handle)
        {
            gdi_layer_pop_and_restore_active();
        }
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  M3D_src         [IN]        The data pointer or file name of M3D object
 *  size            [IN]        The size of the M3D object
 *  is_file         [IN]        The M3D object is from file or memory
 *  is_m3d_type     [IN]        Not Used Now
 *  handle_oob      [IN]        Need to handle OOB or not. Only for rendering
 * RETURNS
 *  GDI_SUCCEED if everything is OK GDI_IMAGE_ERR_IMAGE_TOO_LARGE if the memory is not enough to parse GDI_FAILED if not parsed successfully
 *****************************************************************************/
GDI_RESULT gdi_image_m3d_load(U8 *M3D_src, U32 size, BOOL is_file, BOOL is_m3d_type, BOOL handle_oob)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_m3d_load)
    STFSAL stFSAL;
    st_m3d_parser stM3DParser;
    FSAL_Status eFSALStatus;
    int eM3DParserStatus = 0;
    kal_int32 ret;

    if (gdi_image_m3d_loaded == TRUE)
    {
        gdi_image_m3d_close();
    }
    memset(&stM3DParser, 0, sizeof(st_m3d_parser));
    if (!is_file)
    {
        FSAL_Direct_SetRamFileSize(&stFSAL, size);
        eFSALStatus = FSAL_Open(&stFSAL, (void*)M3D_src, FSAL_ROMFILE);
    }
    else
    {
        eFSALStatus = FSAL_Open(&stFSAL, (void*)M3D_src, FSAL_READ);
    }

    if (eFSALStatus != FSAL_OK)
    {
        gdi_image_m3d_close();
        GDI_RETURN(GDI_FAILED);
    }

    FSAL_SetBuffer(&stFSAL, FSAL_BUFFER_SIZE, gdi_image_m3d_pbFSALBuffer);

    if (is_m3d_type)
    {
        eM3DParserStatus = M3D_Parse(&stM3DParser, &stFSAL);
    }
    else
    {
        GDI_ASSERT(0);
    }

    if (eM3DParserStatus)
    {
        FSAL_Close(&stFSAL);
        gdi_image_m3d_close();
        if (M3D_ERROR_MEMORY_NOTAVAILABLE == eM3DParserStatus)
        {
            GDI_RETURN(GDI_IMAGE_ERR_IMAGE_TOO_LARGE);
        }
        else
        {
            GDI_RETURN(GDI_FAILED);
        }
    }

    FSAL_Close(&stFSAL);
    if (handle_oob)
    {
        M3D_World_getOOBInfo(
            m3d_world,
            &gdi_image_m3d_oob_cntx.image_type,
            &gdi_image_m3d_oob_cntx.image_width,
            &gdi_image_m3d_oob_cntx.image_height,
            &gdi_image_m3d_oob_cntx.image_data_size,
            &gdi_image_m3d_oob_cntx.image_data_offset);
        if (gdi_image_m3d_oob_cntx.image_type != M3D_IMAGE_TYPE_NONE)
        {
            U8 image_identifier = GDI_IMAGE_TYPE_INVALID;
            if (M3D_IMAGE_TYPE_JPG == gdi_image_m3d_oob_cntx.image_type)
            {
                image_identifier = GDI_IMAGE_TYPE_JPG;
            }
            else if (M3D_IMAGE_TYPE_PNG == gdi_image_m3d_oob_cntx.image_type)
            {
                image_identifier = GDI_IMAGE_TYPE_PNG;
            }
            else if (M3D_IMAGE_TYPE_GIF == gdi_image_m3d_oob_cntx.image_type)
            {
                image_identifier = GDI_IMAGE_TYPE_GIF;
            }
            if (is_file)
            {
            	S32	fs_result;
                fs_result = FS_GenVirtualFileName( gdi_m3d_file_handle, (U16*)gdi_m3d_file_name, 
		                    (unsigned int)FS_GenVFN_SIZE, gdi_image_m3d_oob_cntx.image_data_offset, gdi_image_m3d_oob_cntx.image_data_size);
                if(fs_result < 0)
                {
                    //FSAL_Close(&stFSAL);
                    gdi_image_m3d_close();
                    GDI_RETURN(GDI_FAILED);
                }
            	mmi_ucs2cat((S8*)gdi_m3d_file_name,(const S8*)gdi_image_ext_name[image_identifier]);
                gdi_image_m3d_oob_cntx.free_flag = KAL_FALSE;
            }
            else
            {
                /* Set OOB data pointer. */
                gdi_image_m3d_oob_cntx.data_ptr = M3D_src + gdi_image_m3d_oob_cntx.image_data_offset;
                gdi_image_m3d_oob_cntx.free_flag = KAL_FALSE;
            }
            /* Inform M3D engine not to clear background since GDI will handle it. */
            M3D_World_clearBackgroundColor(m3d_world, M3D_FALSE);

            /* Decode the OOB image according to the image type. */
            /* In this sample code, we handle only JPEG OOB only. */
            switch (gdi_image_m3d_oob_cntx.image_type)
            {
                case M3D_IMAGE_TYPE_JPG:
                case M3D_IMAGE_TYPE_PNG:
                case M3D_IMAGE_TYPE_GIF:
                {
                    GDI_RESULT result;
                    U8 bytes_per_pixel_of_layer;
                    U8 color_format_of_layer;

                    #ifdef GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY
                    if (GDI_NULL_HANDLE != gdi_image_m3d_output_layer_handle)
                    {
                        gdi_layer_push_and_set_active(gdi_image_m3d_output_layer_handle);
                    }
                    #endif
                    bytes_per_pixel_of_layer = gdi_act_layer->bits_per_pixel >> 3;
                    color_format_of_layer = gdi_act_layer->vcf;
                    #ifdef GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY
                    if (GDI_NULL_HANDLE != gdi_image_m3d_output_layer_handle)
                    {
                        gdi_layer_pop_and_restore_active();
                    }
                    #endif
                    if ((M3D_IMAGE_TYPE_JPG == gdi_image_m3d_oob_cntx.image_type) ||
                        ((gdi_m3d_clip[2] <= gdi_image_m3d_oob_cntx.image_width) &&
                         (gdi_m3d_clip[3] <= gdi_image_m3d_oob_cntx.image_height)))
                    {
                        gdi_handle old_lcd_handle;
                        gdi_handle old_layer_handle;

                        media_get_ext_buffer(
                            MOD_MMI,
                            (void **)&gdi_image_m3d_oob_cntx.layer_ptr,
                            gdi_m3d_clip[2] * gdi_m3d_clip[3] * (bytes_per_pixel_of_layer));
                        if (!gdi_image_m3d_oob_cntx.layer_ptr)
                        {
                            //FSAL_Close(&stFSAL);
                            gdi_image_m3d_close();
                            GDI_RETURN(GDI_FAILED);
                        }

                        gdi_layer_create_cf_using_outside_memory(
                            color_format_of_layer,
                            0,
                            0,
                            gdi_m3d_clip[2],
                            gdi_m3d_clip[3],
                            &gdi_image_m3d_oob_cntx.layer_handle,
                            (kal_uint8*) gdi_image_m3d_oob_cntx.layer_ptr,
                            gdi_m3d_clip[2] * gdi_m3d_clip[3] * (bytes_per_pixel_of_layer));

                        gdi_lcd_get_active(&old_lcd_handle);
                        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

                        gdi_layer_get_active(&old_layer_handle);
                        gdi_layer_set_active(gdi_image_m3d_oob_cntx.layer_handle);
                        gdi_layer_clear(0);

                        gdi_anim_set_disable_blt();
                        if (!is_file)
                        {
                            result = gdi_anim_draw_mem_resized(
                                        0,
                                        0,
                                        gdi_m3d_clip[2],
                                        gdi_m3d_clip[3],
                                        (U8*) gdi_image_m3d_oob_cntx.data_ptr,
                                        image_identifier,
                                        gdi_image_m3d_oob_cntx.image_data_size,
                                        &gdi_image_m3d_oob_cntx.anim_handle);
                        }
                        else
                        {
                            result = gdi_anim_draw_file_resized(
                                        0,
                                        0,
                                        gdi_m3d_clip[2],
                                        gdi_m3d_clip[3],
                                        gdi_m3d_file_name,
                                        &gdi_image_m3d_oob_cntx.anim_handle
                                        );
                        }

                        gdi_layer_set_active(old_layer_handle);
                        gdi_lcd_set_active(old_lcd_handle);

                        if (result < 0)
                        {
                            //FSAL_Close(&stFSAL);
                            gdi_image_m3d_close();
                            GDI_RETURN(result);
                        }
                    }
                    else
                    {
                        gdi_handle old_lcd_handle;
                        gdi_handle old_layer_handle;

                        media_get_ext_buffer(
                            MOD_MMI,
                            (void **)&gdi_image_m3d_oob_cntx.layer_ptr,
                            gdi_image_m3d_oob_cntx.image_width * gdi_image_m3d_oob_cntx.image_height * (bytes_per_pixel_of_layer));
                        if (!gdi_image_m3d_oob_cntx.layer_ptr ||
                            gdi_m3d_clip[2] * gdi_m3d_clip[3] * (bytes_per_pixel_of_layer) >
                            gdi_work_buffer_size)
                        {
                            //FSAL_Close(&stFSAL);
                            gdi_image_m3d_close();
                            GDI_RETURN(GDI_FAILED);
                        }
                        gdi_layer_create_cf_using_outside_memory(
                            color_format_of_layer,
                            0,
                            0,
                            gdi_image_m3d_oob_cntx.image_width,
                            gdi_image_m3d_oob_cntx.image_height,
                            &gdi_image_m3d_oob_cntx.layer_handle,
                            (kal_uint8*) gdi_image_m3d_oob_cntx.layer_ptr,
                            gdi_image_m3d_oob_cntx.image_width * gdi_image_m3d_oob_cntx.image_height * (bytes_per_pixel_of_layer));

                        gdi_lcd_get_active(&old_lcd_handle);
                        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

                        gdi_layer_get_active(&old_layer_handle);
                        gdi_layer_set_active(gdi_image_m3d_oob_cntx.layer_handle);
                        gdi_layer_clear(0);

                        gdi_anim_set_blt_before_callback(gdi_image_m3d_oob_callback);
                        gdi_anim_set_disable_blt();
                        if (!is_file)
                        {
                            result = gdi_anim_draw_mem(
                                        0,
                                        0,
                                        (U8*) gdi_image_m3d_oob_cntx.data_ptr,
                                        image_identifier,
                                        gdi_image_m3d_oob_cntx.image_data_size,
                                        &gdi_image_m3d_oob_cntx.anim_handle);
                        }
                        else
                        {
                            result = gdi_anim_draw_file(
                                        0,
                                        0,
                                        gdi_m3d_file_name,
                                        &gdi_image_m3d_oob_cntx.anim_handle
                                        );
                        }
                        if (GDI_IMAGE_IS_STILL_IMAGE == result)
                        {
                            gdi_image_m3d_oob_callback(GDI_IMAGE_IS_STILL_IMAGE);
                        }

                        gdi_layer_set_active(old_layer_handle);
                        gdi_lcd_set_active(old_lcd_handle);

                        if (result < 0)
                        {
                            //FSAL_Close(&stFSAL);
                            gdi_image_m3d_close();
                            GDI_RETURN(result);
                        }
                    }
                }
                    break;

                default:
                    //FSAL_Close(&stFSAL);
                    gdi_image_m3d_close();
                    GDI_RETURN(GDI_FAILED);
            }
        }
        else
        {
            M3D_World_clearBackgroundColor(m3d_world, M3D_TRUE);
        }
    }

    //FSAL_Close(&stFSAL);

    ret = M3D_Object3D_GetAnimationDuration(
            (st_m3d_object3d*) m3d_world,
            &gdi_image_m3d_start_time,
            &gdi_image_m3d_end_time);
    gdi_image_m3d_loaded = TRUE;
    
    GDI_RETURN(GDI_SUCCEED);

    GDI_EXIT_CRITICAL_SECTION(gdi_image_m3d_load)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_render
 * DESCRIPTION
 *  Render the M3D object according to the time frame
 * PARAMETERS
 *  world_time      [IN]        The time frame to render
 * RETURNS
 *  GDI_SUCCEED if render successfully
 *****************************************************************************/
GDI_RESULT gdi_image_m3d_render(S32 world_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_m3d_render)
    int validity_interval = 0x7fffffff;
    int result;

    world_time = (S32) ((float)world_time * 4.8);

    while (gdi_image_m3d_rendering);
    if (gdi_image_m3d_loaded == FALSE)
    {
        GDI_RETURN(GDI_FAILED);
    }

#ifdef GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY
    if (GDI_NULL_HANDLE != gdi_image_m3d_output_layer_handle)
    {
        gdi_layer_push_and_set_active(gdi_image_m3d_output_layer_handle);
    }
#endif

    switch (gdi_image_m3d_oob_cntx.image_type)
    {
        case M3D_IMAGE_TYPE_NONE:
                gdi_draw_solid_rect(gdi_m3d_clip[0], gdi_m3d_clip[1],gdi_m3d_clip[2],gdi_m3d_clip[3], GDI_COLOR_WHITE);
            break;

        case M3D_IMAGE_TYPE_JPG:
        case M3D_IMAGE_TYPE_PNG:
        case M3D_IMAGE_TYPE_GIF:
        {
            U32 dest_stride = gdi_act_layer->width * (gdi_act_layer->bits_per_pixel >> 3);
            U32 src_stride = gdi_m3d_clip[2] * (gdi_act_layer->bits_per_pixel >> 3);
            U8 *src_ptr = gdi_image_m3d_oob_cntx.layer_ptr;
            U8 *dest_ptr;
            S32 i = (S32) gdi_m3d_clip[3];

            if ((M3D_IMAGE_TYPE_JPG == gdi_image_m3d_oob_cntx.image_type) ||
                ((gdi_m3d_clip[2] <= gdi_image_m3d_oob_cntx.image_width) &&
                 (gdi_m3d_clip[3] <= gdi_image_m3d_oob_cntx.image_height)))
            {
                src_ptr = gdi_image_m3d_oob_cntx.layer_ptr;
            }
            else
            {
                src_ptr = (U8*) gdi_work_buffer;
            }
            gdi_layer_get_buffer_ptr(&dest_ptr);
            dest_ptr += gdi_m3d_clip[1] * dest_stride + gdi_m3d_clip[0] * (gdi_act_layer->bits_per_pixel >> 3);
            while (--i >= 0)
            {
                memcpy(dest_ptr, src_ptr, src_stride);
                dest_ptr += dest_stride;
                src_ptr += src_stride;
            }
        }
            break;

        default:
            break;
    }
#ifdef GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY
    if (GDI_NULL_HANDLE != gdi_image_m3d_output_layer_handle)
    {
        gdi_layer_pop_and_restore_active();
    }
#endif

    gdi_image_m3d_rendering = 1;
    result = M3D_Graphics3D_setup_World((st_m3d_node*) m3d_world);
    if (result)
    {
        gdi_image_m3d_rendering = 0;
        GDI_RETURN(GDI_FAILED);
    }
    result = M3D_Object3D_animate((st_m3d_object3d*) m3d_world, world_time, &validity_interval);
    if (result)
    {
        gdi_image_m3d_rendering = 0;
        GDI_RETURN(GDI_FAILED);
    }
    result = M3D_Graphics3D_render_World(m3d_world);
    if (result)
    {
        gdi_image_m3d_rendering = 0;
        GDI_RETURN(GDI_FAILED);
    }
    gdi_image_m3d_rendering = 0;
    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_m3d_render)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_show_profile
 * DESCRIPTION
 *  Display the profile of M3D (FPS, pixels, triangles) on the screen. The information will display in the left-middle area
 * PARAMETERS
 *  x       [IN]        The left-top x position of the clipping region
 *  y       [IN]        The lest-top y position of the clipping region
 *  w       [IN]        The width of the clipping region
 *  h       [IN]        The height of the clipping region
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_image_m3d_show_profile(int x, int y, int w, int h)
{
#if defined(GDI_IMAGE_M3D_PROFILE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int str_w[3], str_h[3], clip_w, clip_h;
    char str_tmp[3][64];
    UI_character_type str_buf[64];
    color text_color = gui_color(255, 255, 255);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    y = y + (h >> 1);

    gui_set_text_color(text_color);
    gdi_layer_reset_clip();

    kal_sprintf(str_tmp[0], "Triangles: %u", glProfilerGetTriangleCount());
    mmi_asc_to_ucs2((char*)str_buf, str_tmp[0]);
    gui_measure_string((UI_string_type) str_buf, &str_w[0], &str_h[0]);

    kal_sprintf(str_tmp[1], "Pixels: %u", glProfilerGetPixelCount());
    mmi_asc_to_ucs2((char*)str_buf, str_tmp[1]);
    gui_measure_string((UI_string_type) str_buf, &str_w[1], &str_h[1]);

    if (0 == glProfilerGetDurationTick())
        kal_sprintf(str_tmp[2], "FPS: %.2f", 0.0);
    else
        kal_sprintf(str_tmp[2], "FPS: %.2f", 1000.0 / (float)glTickToMilliSecond(glProfilerGetDurationTick()));
    mmi_asc_to_ucs2((char*)str_buf, str_tmp[2]);
    gui_measure_string((UI_string_type) str_buf, &str_w[2], &str_h[2]);

    if (str_w[0] >= str_w[1] && str_w[0] >= str_w[2])
        clip_w = str_w[0] + 2;
    else if (str_w[1] >= str_w[0] && str_w[1] >= str_w[2])
        clip_w = str_w[1] + 2;
    else
        clip_w = str_w[2] + 2;
    clip_h = str_h[0] + str_h[1] + str_h[2] + 2;

    gdi_draw_solid_rect(x, y, x + clip_w - 1, y + clip_h - 1, GDI_COLOR_BLACK);

    gui_move_text_cursor(x + 1, y);
    mmi_asc_to_ucs2((char*)str_buf, str_tmp[0]);
    gui_print_text(str_buf);

    gui_move_text_cursor(x + 1, y + str_h[0] + 1);
    mmi_asc_to_ucs2((char*)str_buf, str_tmp[1]);
    gui_print_text(str_buf);

    gui_move_text_cursor(x + 1, y + str_h[0] + str_h[1] + 2);
    mmi_asc_to_ucs2((char*)str_buf, str_tmp[2]);
    gui_print_text(str_buf);
#endif /* defined(GDI_IMAGE_M3D_PROFILE) */ 
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_draw_before_handler
 * DESCRIPTION
 *  Initialize and allocate resource before drawing M3D object
 * PARAMETERS
 *  flag            [IN]        Image Codec Flag
 *  frame_pos       [IN]        The frame position to draw
 *  x               [IN]        The left-top x position of the drawing area
 *  y               [IN]        The left-top y position of the drawing area
 *  w               [IN]        The width of the drawing area
 *  h               [IN]        The height of the drawing area
 *  data_ptr        [IN]        The data pointer of the M3D object or its file name
 *  img_size        [IN]        The size of the M3D data
 * RETURNS
 *  GDI_SUCCEED if everything is OK
 *****************************************************************************/
GDI_RESULT gdi_image_m3d_draw_before_handler(
            U32 flag,
            U32 frame_pos,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U8 *data_ptr,
            U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_m3d_draw_before_handler)
    GDI_RESULT result = GDI_FAILED;
    MMI_BOOL is_file;

    if (MMI_TRUE == gdi_image_m3d_drawing)
    {
        GDI_RETURN(GDI_IMAGE_ERR_RESOURCE_NOT_AVAILABLE);
    }
    if (0 == w && 0 == h)
    {
        {
            gdi_image_m3d_get_dimension_handler(flag, data_ptr, img_size, &w, &h);
        }
    }
#ifdef GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY
    if (GDI_COLOR_FORMAT_16 != gdi_act_layer->vcf)
    {
        gdi_image_set_m3d_clip(0, 0, w, h);
        media_get_ext_buffer(
            MOD_MMI,
            (void **)&gdi_image_m3d_output_layer_ptr,
            w * h * (2));
        if (gdi_image_m3d_output_layer_ptr)
        {
            gdi_layer_create_cf_using_outside_memory(
                GDI_COLOR_FORMAT_16,
                0,
                0,
                w,
                h,
                &gdi_image_m3d_output_layer_handle,
                (kal_uint8*) gdi_image_m3d_output_layer_ptr,
                w * h * (2));
            result = gdi_image_m3d_init(w, h, (void*)gdi_image_m3d_output_layer_ptr);
        }
        else
        {
            result = GDI_FAILED;
        }
    }
    else
#endif
    {
        gdi_image_set_m3d_clip(x, y, w, h);
        result = gdi_image_m3d_init(gdi_act_layer->width, gdi_act_layer->height, (void*)gdi_act_layer->buf_ptr);
    }
    if (result)
    {
        GDI_RETURN(result);
    }
    if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
    {
        is_file = MMI_TRUE;
    }
    else
    {
        is_file = MMI_FALSE;
    }
    if (is_file)
    {
        gdi_m3d_file_handle = DRM_open_file((U16*) data_ptr, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED, DRM_PERMISSION_DISPLAY);
        if (gdi_m3d_file_handle < 0)
        {
            gdi_image_m3d_close();
            gdi_m3d_file_handle = 0;
            GDI_RETURN(GDI_FAILED);
        }
    }

    result = gdi_image_m3d_load(data_ptr, img_size, is_file, MMI_TRUE, MMI_TRUE);

    if (result)
    {
        GDI_RETURN(result);
    }
    else
    {
        gdi_image_m3d_drawing = MMI_TRUE;
    }
    GDI_RETURN(result);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_m3d_draw_before_handler)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_draw_handler
 * DESCRIPTION
 *  Drawing the M3D object by the frame_pos
 * PARAMETERS
 *  flag            [IN]        Image Codec Flag
 *  frame_pos       [IN]        The frame position to draw
 *  x               [IN]        The left-top x position of the drawing area
 *  y               [IN]        The left-top y position of the drawing area
 *  w               [IN]        The width of the drawing area
 *  h               [IN]        The height of the drawing area
 *  data_ptr        [IN]        The data pointer of the M3D object or its file name
 *  img_size        [IN]        The size of the M3D data
 * RETURNS
 *  GDI_SUCCEED if everything is OK
 *****************************************************************************/
GDI_RESULT gdi_image_m3d_draw_handler(U32 flag, U32 frame_pos, S32 x, S32 y, S32 w, S32 h, U8 *data_ptr, U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_m3d_draw_handler)
    GDI_RESULT result = GDI_FAILED;

    if (0 == w && 0 == h)
    {
        gdi_image_m3d_get_dimension_handler(flag, data_ptr, img_size, &w, &h);
    }
#if defined(GDI_IMAGE_M3D_PROFILE)
    glProfilerStartProfiler();
#endif 
    result = gdi_image_m3d_render(frame_pos);
#ifdef GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY
    if (gdi_image_m3d_output_layer_handle)
    {
        gdi_bitblt_internal(
            gdi_image_m3d_output_layer_ptr, w, 
			0, 0, 
			w, h,
			GDI_COLOR_FORMAT_16,
			gdi_act_layer->buf_ptr, gdi_act_layer->width,
			x, y,
			x, y, x + w - 1, y + h - 1,
			gdi_act_layer->vcf, gdi_act_layer->layer_size,
			FALSE,
			FALSE, 0,
			FALSE, 0,
			FALSE, 0,
			GDI_TRANSFORM_NONE,
			GDI_TRANSFORM_DIRECTION_LT);
    }
#endif /* defined(GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY) */ 
#if defined(GDI_IMAGE_M3D_PROFILE)
    glProfilerStopProfiler();
    gdi_image_m3d_show_profile(x, y, w, h);
    glProfilerResetProfiler();
#endif /* defined(GDI_IMAGE_M3D_PROFILE) */ 
    GDI_RETURN(result);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_m3d_draw_handler)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_draw_after_handler
 * DESCRIPTION
 *  Finalize the M3D module and release the resource after drawing M3D object
 * PARAMETERS
 *  flag            [IN]        Image Codec Flag
 *  frame_pos       [IN]        The frame position to draw
 *  x               [IN]        The left-top x position of the drawing area
 *  y               [IN]        The left-top y position of the drawing area
 *  w               [IN]        The width of the drawing area
 *  h               [IN]        The height of the drawing area
 *  data_ptr        [IN]        The data pointer of the M3D object or its file name
 *  img_size        [IN]        The size of the M3D data
 * RETURNS
 *  GDI_SUCCEED if everything is OK
 *****************************************************************************/
GDI_RESULT gdi_image_m3d_draw_after_handler(
            U32 flag,
            U32 frame_pos,
            S32 x,
            S32 y,
            S32 w,
            S32 h,
            U8 *data_ptr,
            U32 img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_m3d_draw_after_handler)
#ifdef GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY
    if (GDI_NULL_HANDLE != gdi_image_m3d_output_layer_handle)
    {
        gdi_layer_free(gdi_image_m3d_output_layer_handle);
        gdi_image_m3d_output_layer_handle = GDI_NULL_HANDLE;
    }
    if (gdi_image_m3d_output_layer_ptr)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&gdi_image_m3d_output_layer_ptr);
        gdi_image_m3d_output_layer_ptr = NULL;
    }
#endif /* defined(GDI_IMAGE_M3D_SUPPORT_COLOR_FORMAT_16_ONLY) */ 
    if (gdi_m3d_file_handle)
    {
        S32 result;
        result = DRM_close_file(gdi_m3d_file_handle);
        gdi_m3d_file_handle = 0;
        if (result)
        {
            GDI_DEBUG_ASSERT(0);
        }
    }
    if (MMI_TRUE == gdi_image_m3d_drawing)
    {
        gdi_image_m3d_drawing = MMI_FALSE;
        GDI_RETURN(gdi_image_m3d_close());
    }
    else
    {
        GDI_RETURN(GDI_FAILED);
    }
    GDI_EXIT_CRITICAL_SECTION(gdi_image_m3d_draw_after_handler)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_get_dimension_handler
 * DESCRIPTION
 *  Currently we return the width and height of the active layer because M3D could be resized to most size
 * PARAMETERS
 *  flag            [IN]        Image Codec Flag
 *  data_ptr        [IN]        The data pointer of the M3D object or its file name
 *  img_size        [IN]        The size of the M3D data
 *  width           [OUT]       The width of the M3D object to return
 *  height          [OUT]       The height of the M3D object to return
 * RETURNS
 *  GDI_SUCCEED if everything is OK
 *****************************************************************************/
GDI_RESULT gdi_image_m3d_get_dimension_handler(U32 flag, U8 *data_ptr, U32 img_size, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_m3d_get_dimension_handler)
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
#else /* 0 */ 
    *width = gdi_act_layer->width;
    *height = gdi_act_layer->height;
#endif /* 0 */ 
    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_m3d_get_dimension_handler)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_get_pos_info_handler
 * DESCRIPTION
 *  To get the frame information of the M3D object
 * PARAMETERS
 *  flag            [IN]        Image Codec Flag
 *  data_ptr        [IN]        The data pointer of the M3D object or its file name
 *  img_size        [IN]        The size of the M3D data
 *  quick_mode      [IN]        Not used for M3D object
 *  total_pos       [OUT]       The last time frame of the M3D object (ms)
 *  pos_type        [OUT]       It always set to GDI_ANIM_POS_TYPE_TIME if M3D object
 * RETURNS
 *  GDI_SUCCEED if everything is OK
 *****************************************************************************/
GDI_RESULT gdi_image_m3d_get_pos_info_handler(
            U32 flag,
            U8 *data_ptr,
            U32 img_size,
            BOOL quick_mode,
            S32 *total_pos,
            gdi_anim_pos_type_enum *pos_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_m3d_get_pos_info_handler)
    MMI_BOOL is_file;
    MMI_BOOL need_to_load = !gdi_image_m3d_loaded;
    GDI_RESULT result = GDI_FAILED;

    *pos_type = GDI_ANIM_POS_TYPE_TIME;
    if (need_to_load)
    {
        if (gdi_image_m3d_inited == FALSE)
        {
            result = gdi_image_m3d_mem_init();
            if (!result)
            {
                result = M3D_Initialize(M3D_APP_MMI, gdi_image_m3d_mallc, gdi_image_m3d_free);

                if (result == M3D_SUCCESS)
                {
                    gdi_image_m3d_inited = TRUE;
                }
                else
                {
                    gdi_image_m3d_close();
                    result = GDI_IMAGE_ERR_RESOURCE_NOT_AVAILABLE;
                }
            }
        }

        if (!result || gdi_image_m3d_inited)
        {
            m3d_world = M3D_World_new();
        }

        if (flag & GDI_IMAGE_CODEC_FLAG_IS_FILE)
        {
            is_file = MMI_TRUE;
        }
        else
        {
            is_file = MMI_FALSE;
        }

        if (!result)
        {
            result = gdi_image_m3d_load(data_ptr, img_size, is_file, MMI_TRUE, MMI_FALSE);
        }

        if (result)
        {
            GDI_RETURN(result);
        }
    }
    {
        S32 m3d_tick = gdi_image_m3d_end_time;

        *total_pos = (S32) ((float)m3d_tick * 10.0 / 48.0);
    }
    if (need_to_load)
    {
        gdi_image_m3d_close();
    }
    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_m3d_get_pos_info_handler)
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_is_m3d_file
 * DESCRIPTION
 *  Check the file is M3D type or not
 * PARAMETERS
 *  file_name       [IN]    The file name buffer
 * RETURNS
 *  TRUE if M3D type FALSE if not M3D type
 *****************************************************************************/
BOOL gdi_image_is_m3d_file(U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int f;
    U8 buf[12];
    U32 len;
    U32 result;
    const unsigned char GDI_M3D_FILE_IDENTIFIER[8] = 
    {
        0x89, 0x4D, 0x33, 0x44,
        0x0D, 0x0A, 0x1A, 0x0A
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    f = gdi_lfs_open(gdi_lfs_handle,(U16*) file_name, FS_READ_ONLY | FS_OPEN_NO_DIR | FS_OPEN_SHARED, 0);
    if (f < 0) return FALSE;
    f = gdi_lfs_handle;

    result = gdi_lfs_read(f, buf, 8, &len);

    gdi_lfs_close(f);

    if (result == FS_NO_ERROR)
        if (len == 8)
            if (memcmp(buf, GDI_M3D_FILE_IDENTIFIER, 8) == 0)
            {
                return TRUE;
            }
    return FALSE;
}

#endif /* defined(GDI_USING_M3D) */ 

