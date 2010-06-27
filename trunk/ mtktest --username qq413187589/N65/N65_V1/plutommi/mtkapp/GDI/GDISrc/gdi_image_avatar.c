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
 *  gdi_image_avatar.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GDI avatar related.
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

#ifdef GDI_USING_AVATAR

#include "kal_release.h"
#include "ScrMemMgrGprot.h"
#include "ucs2prot.h"
#include "med_api.h"


#include "CustDataRes.h"

#include "gdi_image_m3d.h"

#include "AvatarResDef.h"
#include "AvatarGprot.h"

st_m3d_world *m3d_world_avatar_head;
st_m3d_world *m3d_world_avatar_hair;
st_m3d_world *m3d_world_avatar_body;
st_m3d_camera * m3d_world_avatar_camera;

extern st_m3d_world *m3d_world;
extern int sprintf(char *, const char *, ...);
void _m3d_Graphics3D_release_texobj(st_m3d_image2d* image);
extern GDI_RESULT gdi_image_set_m3d_clip(S32 x, S32 y, S32 w, S32 h);

void gdi_image_m3d_avatar_get_all_var(void** c,void** world, void** head,void** hair,void** body)
{
    *world = (void*)m3d_world;
    *c = (void*)m3d_world_avatar_camera;
    *head = (void*)m3d_world_avatar_head;
    *hair = (void*)m3d_world_avatar_hair;
    *body = (void*)m3d_world_avatar_body;    
}


/*****************************************************************************
 * FUNCTION
 *  gdi_image_m3d_avatar_get_pos_info_handler
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
GDI_RESULT gdi_image_m3d_avatar_get_pos_info_handler(
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
    GDI_RESULT ret;
    PU8 src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    src = (U8*)GetImage((U16) (data_ptr[8]) | (U16)((U16) data_ptr[9] << 8));
    img_size =    
    (S32) (src[2]) | (S32) ((S32) src[3] << 8) | (S32) ((S32) src[4] << 16) | (S32) ((S32) src[5] <<24);
    src = src + 8; 

    ret =   gdi_image_m3d_get_pos_info_handler(
            flag,
            src,
            img_size,
            quick_mode,
            total_pos,
            pos_type);

    return ret;
}


static GDI_RESULT gdi_image_m3d_load_accessory( PU8 resource_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    STFSAL stFSAL;
    st_m3d_parser stM3DParser;
    FSAL_Status eFSALStatus;
    int eM3DParserStatus = 0;
    U8* M3D_src;
    S32 size;

    
    M3D_src = resource_ptr;
        size =    
        (S32) (M3D_src[2]) | (S32) ((S32) M3D_src[3] << 8) | (S32) ((S32) M3D_src[4] << 16) | (S32) ((S32) M3D_src[5] <<24);
    M3D_src = M3D_src+8;


    memset(&stM3DParser, 0, sizeof(st_m3d_parser));

    FSAL_Direct_SetRamFileSize(&stFSAL, size);
    eFSALStatus = FSAL_Open(&stFSAL, (void*)M3D_src, FSAL_ROMFILE);

    if (eFSALStatus != FSAL_OK)
    {
        return GDI_FAILED;
    }

    FSAL_SetBuffer(&stFSAL, FSAL_BUFFER_SIZE, gdi_image_m3d_pbFSALBuffer);

    eM3DParserStatus = M3D_Parse(&stM3DParser, &stFSAL);

    if (eM3DParserStatus)
    {
        FSAL_Close(&stFSAL);
        if (M3D_ERROR_MEMORY_NOTAVAILABLE == eM3DParserStatus)
        {
            return GDI_IMAGE_ERR_IMAGE_TOO_LARGE;
        }
        else
        {
            return GDI_FAILED;
        }
    }

    FSAL_Close(&stFSAL);
    return GDI_SUCCEED;


}


static void gdi_image_m3d_avatar_apply_setting(S16 serial_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 headid,hairid,bodyid,dressid;
    U16 eyeid,lipid,faceid,browid,decorationid;
    S16 sl_eye,sl_brow,sl_lip,sl_decoration;
    GDI_HANDLE image_buffer_handle;
    float tx,ty,tz;
   	st_m3d_node *node;
    st_m3d_node *node2;
    st_m3d_group *parent;
    st_m3d_appearance* app;
    st_m3d_texture2d* t2d;
    st_m3d_image2d * i2d;
    S8 buf_filename[50];
    FS_HANDLE file_handle;
    U32 written;
    S8 UCS2_buffer[50*2];
    S32 offset_x, offset_y, resized_width, resized_height;
    S32 img_width,img_height;    
    mmi_avatar_avatar_struct m3d_world_avatar_cntx;
    gdi_handle old_abm_src_layer_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (serial_number == 0)
    {
        eyeid = 0;
        faceid = 0;
        browid = 0;
        lipid = 0;
        decorationid = 0;
        dressid = 0;
        headid = 0;
        hairid = 0;
        bodyid = 0;
        dressid = 0;
        sl_eye = 0;
        sl_brow = 0;
        sl_lip = 0;
        sl_decoration = 0;

        m3d_world_avatar_cntx.offset_eye_x = 0;    
        m3d_world_avatar_cntx.offset_eye_y = 0;    
        m3d_world_avatar_cntx.offset_brow_x = 0;    
        m3d_world_avatar_cntx.offset_brow_y = 0;    
        m3d_world_avatar_cntx.offset_decoration_y = 0;    
        m3d_world_avatar_cntx.offset_lip_y = 0;    
    }
    else
    {
        sprintf((PS8) buf_filename, "Z:\\@avatar\\%d.atr",serial_number);

        mmi_asc_to_ucs2((PS8) UCS2_buffer, (PS8) buf_filename);

        file_handle = FS_Open((U16*) UCS2_buffer, FS_CREATE | FS_READ_WRITE);

        if (file_handle > 0)
        {
            FS_Read(file_handle, 
                        (void*)&m3d_world_avatar_cntx,
                        sizeof(mmi_avatar_avatar_struct) , 
                        (U32*) & written);
            FS_Close(file_handle);
        }

        eyeid = m3d_world_avatar_cntx.selected_eye;
        faceid = m3d_world_avatar_cntx.selected_face;
        browid = m3d_world_avatar_cntx.selected_brow;
        lipid = m3d_world_avatar_cntx.selected_lip;
        decorationid = m3d_world_avatar_cntx.selected_decoration;
        dressid = m3d_world_avatar_cntx.selected_dress;
        headid = m3d_world_avatar_cntx.selected_head;
        hairid = m3d_world_avatar_cntx.selected_hair;
        bodyid = m3d_world_avatar_cntx.selected_body;
        dressid = m3d_world_avatar_cntx.selected_dress;

        sl_eye = m3d_world_avatar_cntx.s_level_eye;
        sl_brow = m3d_world_avatar_cntx.s_level_brow;
        sl_lip = m3d_world_avatar_cntx.s_level_lip;
        sl_decoration = m3d_world_avatar_cntx.s_level_decoration;
    }
    /* Head */
    {
        node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,201);
        node2 = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world_avatar_head,201+headid);
        parent = (st_m3d_group*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
                    2);

        tx = ((st_m3d_transformable *)node)->_translation[0];
	    ty = ((st_m3d_transformable *)node)->_translation[1];
    	tz = ((st_m3d_transformable *)node)->_translation[2];


        M3D_Transformable_setTranslation((st_m3d_transformable *)node2, tx,ty,tz);


        INC_REF(node);
        INC_REF(node2);                    
        M3D_Group_removeChild(parent,node);
        M3D_Group_addChild((st_m3d_group*)m3d_world_avatar_head,node);
        M3D_Group_removeChild((st_m3d_group*)m3d_world_avatar_head,node2);
        M3D_Group_addChild(parent,node2);
    }

    /* Hair */
    {
        node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,101);
        node2 = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world_avatar_hair,101+hairid);
        parent = (st_m3d_group*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
            1);

        tx = ((st_m3d_transformable *)node)->_translation[0];
	    ty = ((st_m3d_transformable *)node)->_translation[1];
    	tz = ((st_m3d_transformable *)node)->_translation[2];


        M3D_Transformable_setTranslation((st_m3d_transformable *)node2, tx,ty,tz);


        INC_REF(node);
        INC_REF(node2);                    
        M3D_Group_removeChild(parent,node);
        M3D_Group_addChild((st_m3d_group*)m3d_world_avatar_hair,node);
        M3D_Group_removeChild((st_m3d_group*)m3d_world_avatar_hair,node2);
        M3D_Group_addChild(parent,node2);
    }

    /* Body */
    if (bodyid != 0)
    {
        node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,301);
        node2 = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world_avatar_body,301+bodyid);
        parent = (st_m3d_group*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
            3);

        tx = ((st_m3d_transformable *)node)->_translation[0];
	    ty = ((st_m3d_transformable *)node)->_translation[1];
    	tz = ((st_m3d_transformable *)node)->_translation[2];


        M3D_Transformable_setTranslation((st_m3d_transformable *)node2, tx,ty,tz);


        INC_REF(node);
        INC_REF(node2);                    
        M3D_Group_removeChild(parent,node);
        M3D_Group_addChild((st_m3d_group*)m3d_world_avatar_body,node);
        M3D_Group_removeChild((st_m3d_group*)m3d_world_avatar_body,node2);
        M3D_Group_addChild(parent,node2);
    }

    /*********************************** 
    * Body Texture 
    ************************************/
    node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
        401);
    app = M3D_Mesh_getAppearance((st_m3d_mesh *)node,0);
    t2d = app->textures[0];
    i2d = t2d->image;

    gdi_layer_create_using_outside_memory(
        0,
        0,
        64,
        64,
        &image_buffer_handle,
        (PU8) i2d->pixels,
        64*64*2);

    gdi_layer_push_and_set_active(image_buffer_handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);    
    gdi_image_draw_id(0,0,IMG_ID_AVATAR_M_DRESS_1 + dressid);
    gdi_layer_pop_and_restore_active();
            
    /* IMPORTANT!, must call _m3d_Graphics3D_release_texobj to let DRV free cache of image buffer */
    _m3d_Graphics3D_release_texobj(i2d);

    if (image_buffer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(image_buffer_handle);
        image_buffer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

    /*********************************** 
    * Back Facial Texture 
    ************************************/
    node = (st_m3d_node*) M3D_Object3D_find((st_m3d_object3d*)m3d_world,
        201+headid);

    app = M3D_Mesh_getAppearance((st_m3d_mesh *)node,0);
    if (app != NULL)
    {
        t2d = app->textures[0];
        i2d = t2d->image;

        gdi_layer_create_using_outside_memory(
            0,
            0,
            128,
            128,
            &image_buffer_handle,
            (PU8) i2d->pixels,
            128*128*2);

        gdi_layer_push_and_set_active(image_buffer_handle);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);    

        gdi_image_draw_id(0,0,IMG_ID_AVATAR_M_FACE_1 + faceid);
        gdi_layer_pop_and_restore_active();

        if (image_buffer_handle != GDI_LAYER_EMPTY_HANDLE)
        {
            gdi_layer_free(image_buffer_handle);
            image_buffer_handle = GDI_LAYER_EMPTY_HANDLE;
        }
    }
	else
    {
        /* there should be app 0 */
        ASSERT(0);
    }


    /*********************************** 
    * Facial Texture 
    ************************************/
    app = M3D_Mesh_getAppearance((st_m3d_mesh *)node,1);
    t2d = app->textures[0];
    i2d = t2d->image;

    gdi_layer_create_using_outside_memory(
        0,
        0,
        128,
        128,
        &image_buffer_handle,
        (PU8) i2d->pixels,
        128*128*2);

    old_abm_src_layer_handle = gdi_image_abm_set_source_layer(image_buffer_handle);

    gdi_layer_push_and_set_active(image_buffer_handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);    

    gdi_image_draw_id(0,0,IMG_ID_AVATAR_M_FACE_1 + faceid);

    {
        U16 sid = IMG_ID_AVATAR_M_L_BROWS_1_3 + sl_brow;
        gdi_image_draw_id(MMI_AVATAR_L_BROW_OFFSET_X+m3d_world_avatar_cntx.offset_brow_x*5,MMI_AVATAR_L_BROW_OFFSET_Y+m3d_world_avatar_cntx.offset_brow_y*5,sid + browid*5);
        sid = IMG_ID_AVATAR_M_R_BROWS_1_3 + sl_brow;
        gdi_image_draw_id(MMI_AVATAR_R_BROW_OFFSET_X-m3d_world_avatar_cntx.offset_brow_x*5,MMI_AVATAR_R_BROW_OFFSET_Y+m3d_world_avatar_cntx.offset_brow_y*5,sid + browid*5);
    }

    {
        U16 eid = IMG_ID_AVATAR_M_L_EYE_1_3 + sl_eye;
        gdi_image_draw_id(MMI_AVATAR_L_EYE_OFFSET_X+m3d_world_avatar_cntx.offset_eye_x*5,MMI_AVATAR_L_EYE_OFFSET_Y+m3d_world_avatar_cntx.offset_eye_y*5,eid+ eyeid*5);
        eid = IMG_ID_AVATAR_M_R_EYE_1_3 + sl_eye;
        gdi_image_draw_id(MMI_AVATAR_R_EYE_OFFSET_X-m3d_world_avatar_cntx.offset_eye_x*5,MMI_AVATAR_R_EYE_OFFSET_Y+m3d_world_avatar_cntx.offset_eye_y*5,eid+ eyeid*5);
    }

    {   
        U16 lid = IMG_ID_AVATAR_M_LIP_1_3 + sl_lip;
        gdi_image_draw_id(MMI_AVATAR_LIP_OFFSET_X,MMI_AVATAR_LIP_OFFSET_Y+m3d_world_avatar_cntx.offset_lip_y*5,lid + lipid*5);
    }

    if (decorationid>0)
    {
        if (sl_decoration == 0)    
            gdi_image_draw_id(MMI_AVATAR_DECORATION_OFFSET_X,MMI_AVATAR_DECORATION_OFFSET_Y+m3d_world_avatar_cntx.offset_decoration_y*5,IMG_ID_AVATAR_M_DECORATION_1 + decorationid);
        else
        {
            gdi_image_get_dimension_id(IMG_ID_AVATAR_M_DECORATION_1 + decorationid,&img_width,&img_height);
            resized_width = (img_width * (10+sl_decoration))/10;
            resized_height = (img_height * (10+sl_decoration))/10;
            offset_x = (img_width - resized_width)/2;
            offset_y = (img_height - resized_height)/2;
            gdi_image_draw_resized_id(
                offset_x + MMI_AVATAR_DECORATION_OFFSET_X,
                offset_y + MMI_AVATAR_DECORATION_OFFSET_Y+m3d_world_avatar_cntx.offset_decoration_y*5,
                resized_width,
                resized_height,
                IMG_ID_AVATAR_M_DECORATION_1 + decorationid);        
        }
    }

    gdi_image_abm_set_source_layer(old_abm_src_layer_handle);
    gdi_layer_pop_and_restore_active();
            
    /* IMPORTANT!, must call _m3d_Graphics3D_release_texobj to let DRV free cache of image buffer */
    _m3d_Graphics3D_release_texobj(i2d);

    if (image_buffer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(image_buffer_handle);
        image_buffer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

}

static GDI_RESULT gdi_image_m3d_load_avatar(U8 *M3D_src, U32 size)
{
    PU8 src;
    U16 serial_number;
    serial_number = (U16) (M3D_src[10]) | (U16)((U16) M3D_src[11] << 8);   
    
    src = (U8*)GetImage(((U16) (M3D_src[8]) | (U16)((U16) M3D_src[9] << 8)));
    size =    
    (S32) (src[2]) | (S32) ((S32) src[3] << 8) | (S32) ((S32) src[4] << 16) | (S32) ((S32) src[5] <<24);

    src = src + 8;           


    /* load accessory first*/
    if (GDI_SUCCEED==gdi_image_m3d_load_accessory((PU8)GetImage(IMG_ID_AVATAR_M3D_HEAD)))
        m3d_world_avatar_head = m3d_world;
    else
        return GDI_FAILED;
             
    if (GDI_SUCCEED==gdi_image_m3d_load_accessory((PU8)GetImage(IMG_ID_AVATAR_M3D_HAIR)))
        m3d_world_avatar_hair = m3d_world;
    else
        return GDI_FAILED;

    if (GDI_SUCCEED==gdi_image_m3d_load_accessory((PU8)GetImage(IMG_ID_AVATAR_M3D_BODY)))
        m3d_world_avatar_body = m3d_world;
    else
        return GDI_FAILED;
    /* load m3d avatar */

    if (GDI_SUCCEED!=gdi_image_m3d_load(src,size,FALSE,TRUE,TRUE))
        return GDI_FAILED;

    /* apply setting */
    gdi_image_m3d_avatar_apply_setting(serial_number);
    return GDI_SUCCEED;
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
GDI_RESULT gdi_image_avatar_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_ENTER_CRITICAL_SECTION(gdi_image_avatar_close)
    while (gdi_image_m3d_rendering);

    if (m3d_world_avatar_head != NULL)
    {
        M3D_World_finalize(m3d_world_avatar_head);
        m3d_world_avatar_head = NULL;
    }

    if (m3d_world_avatar_hair != NULL)
    {
        M3D_World_finalize(m3d_world_avatar_hair);
        m3d_world_avatar_hair = NULL;
    }

    if (m3d_world_avatar_body != NULL)
    {
        M3D_World_finalize(m3d_world_avatar_body);
        m3d_world_avatar_body = NULL;
    }

    GDI_RETURN(GDI_SUCCEED);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_avatar_close)
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
GDI_RESULT gdi_image_m3d_avatar_draw_before_handler(
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

    if (MMI_TRUE == gdi_image_m3d_drawing)
    {
        GDI_RETURN(GDI_IMAGE_ERR_RESOURCE_NOT_AVAILABLE);
    }

    {
        PU8 src;

        src = (U8*)GetImage(((U16) (data_ptr[8]) | (U16)((U16) data_ptr[9] << 8)));
        img_size =    
        (S32) (src[2]) | (S32) ((S32) src[3] << 8) | (S32) ((S32) src[4] << 16) | (S32) ((S32) src[5] <<24);
        src = src + 8;           
        if (0 == w && 0 == h)
            gdi_image_m3d_get_dimension_handler(flag, src, img_size, &w, &h);
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

    result = gdi_image_m3d_load_avatar(data_ptr, img_size);

    if (result)
    {
        GDI_RETURN(result);
    }
    else
    {
      	st_m3d_node *node;       

       /**************************************************************
        * set Camera to avatar_cntx_p->m3d_camera 
        **************************************************************/
        node = m3d_world->group.children->list_head;
        while (node != NULL)
        {
            if (node->transformable.object3d.object_type == M3D_CAMERA)
            {
                float tmpf = (float)w/h;
                m3d_world_avatar_camera = (st_m3d_camera*)node;

                M3D_Camera_setPerspective(m3d_world_avatar_camera, 39.27,tmpf,1,1000);
            }
            else if (node->transformable.object3d.object_type == M3D_GROUP)
            {
                st_m3d_transform* tr;
                st_m3d_light* light;

                /**************************************************************
                 * Initialize Light
                 **************************************************************/
                light = M3D_Light_new();
                M3D_Light_setMode(light , M3D_LIGHT_AMBIENT);
                M3D_Light_setAttenuation(light , 0.001f, 0.1f, 0.0f);
                M3D_Light_setColor(light , 0xffffffff);
                M3D_Light_setIntensity(light , 1.0f);
    	        tr = M3D_Transform_new();
	            M3D_Transform_postTranslate(tr, -5.0f, -5.0f, 6.0f);
    	        M3D_Graphics3D_resetLights();
    	        M3D_Graphics3D_addLight(light, tr);
    	        M3D_Group_addChild((st_m3d_group*)m3d_world, (st_m3d_node*)light);
            }
            node = node->children_next;
        }
        gdi_image_m3d_drawing = MMI_TRUE;
    }
    GDI_RETURN(result);
    GDI_EXIT_CRITICAL_SECTION(gdi_image_m3d_draw_before_handler)
}

#endif /* defined(GDI_USING_M3D) */ 


