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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

/* !\file mamoh.c
 *  \brief Media object handling.
 */

/* MSF */
#include "msf_mem.h"
#include "msf_lib.h"
#ifdef WAP_SUPPORT
#include "msf_file.h"	/* MSF_FILE_REMOVE */
#endif

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MMS */
#include "mms_def.h"

/* MEA*/
#ifndef WAP_SUPPORT //mea_def.h include in mea_cfg.h, too
#include "mea_def.h"
#endif /* WAP_SUPPORT */
#include "mea_cfg.h"
#include "matypes.h"
#include "mamem.h"
#include "mamoh.h"
#include "mautils.h"

#ifdef MMS_SLIM_MEM
#include "maintsig.h"  //for maph.h
#include "maph.h"      //for meaGetCurrentAfiHandle
//#include "mamcr.h"  //for meaMoInMemory
#include "msf_wid.h" //for widget release
#include "maasync.h"   //for meaAsyncOperationStop
#endif /* MMS_SLIM_MEM */

#ifdef JPG_ENCODE
#include "mautils.h"  /* meaIsResizedFile() */
#endif
/******************************************************************************
 * Prototypes
 *****************************************************************************/
static void meaFreeMoItem(MeaMoDataItem *mo);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Searches for a media object with a specific name.
 * 
 * \param mo The list of media objects.
 * \param name The name of the media object, usually its filename.
 * \return The media object or NULL if the object does not exist.
 *****************************************************************************/
MeaMoDataItem *meaFindMo(MeaMoDataItem *mo, const char *name)
{
    while(NULL != mo)
    {
        /* Check if the media object already exists */
        if ((NULL != mo->name) && (0 == strcmp(mo->name, name)))
        {
            return mo;
        }
        mo = mo->next;
    }
    return mo;
}

/*!
 * \brief Adds a media object to the list of media objects.
 * 
 * \param mediaObjects The list of media objects.
 * \param data The new media objects data.
 * \param dataSize The size of the data for the new media object.
 * \param mediaType The type of object to add, see #MeaMediaType.
 * \param name The name of the new object, usually its filename.
 * \return A reference to the media object or NULL.
 *****************************************************************************/
#ifdef __DRM_SUPPORT__
MeaMoDataItem *meaAddMo(MeaMoDataItem **mediaObjects, unsigned char *data, unsigned int dataSize, 
    MeaMediaType mediaType, MeaMediaType drmType, MmsContentType *mmsType, char *name, int bodyPartNumber, 
    MSF_UINT32 resHandle)
#else
MeaMoDataItem *meaAddMo(MeaMoDataItem **mediaObjects, unsigned char *data, unsigned int dataSize, 
    MeaMediaType mediaType, MmsContentType *mmsType, char *name, int bodyPartNumber, MSF_UINT32 resHandle)
#endif
{
    MeaMoDataItem *item;
    /* Check if the item already exists */
#ifndef WAP_SUPPORT
    if (NULL != (item = meaFindMo(*mediaObjects, name)))
    {
        /* If the item already exists the data needs to be deallocated */
        MEA_FREE(data);
        MEA_FREE(name);
        if (NULL != mmsType)
        {
            meaFreeMmsContentType(mmsType);
        }
        return item;
    }
#endif /* WAP_SUPPORT */

    /* Allocate new item */
    item = MEA_ALLOC(sizeof(MeaMoDataItem));
    /* Initiate data-structure */
    memset(item, 0, sizeof(MeaMoDataItem));
    item->data             = data;
    item->size             = dataSize;
    item->content.type     = mediaType;
    item->content.origType = mmsType;
#ifdef __DRM_SUPPORT__
    item->content.drmType  = drmType;
#endif
    item->name             = name;

    if(bodyPartNumber>0)
    {
        item->bpIndex=bodyPartNumber;
    }

    if (mediaType == MEA_MEDIA_TYPE_TEXT_PLAIN
#ifdef MEA_CFG_USER_TEMPLATE_SUPPORT
        || data
#endif
        )
    {
		item->acessType = meaMoInMemory; //meaDataInMemory
    }

    if (meaMediaType2ObjType(mediaType) == MEA_MEDIA_GROUP_IMAGE || meaMediaType2ObjType(mediaType) == MEA_MEDIA_GROUP_VIDEO
  #ifdef __DRM_SUPPORT__
        || meaMediaType2ObjType(mediaType) == MEA_MEDIA_GROUP_DRM
  #endif
        )
    {
        if (resHandle!=0)
        {
            item->reshandle = resHandle;
        }    
    }

    /* Check if any objects are present */
    if (NULL == *mediaObjects)
    {
        /* Set the first item to the current */
        *mediaObjects = item;
    }
    else
    {
        /* Insert the new item first in the list */
        item->next = *mediaObjects;
        *mediaObjects = item;
    }
    return item;
}

/*!
 * \brief De-allocates a media object.
 *
 * \param mo The media object to de-allocate.
 *****************************************************************************/
static void meaFreeMoItem(MeaMoDataItem *mo)
{
#ifdef MMS_SLIM_MEM
    if(mo->meaObjectReader)
    	meaAsyncOperationStop(&mo->meaObjectReader);
    if(mo->meaAsioReader)
    	meaAsyncOperationStop(&mo->meaAsioReader);
    if(mo->meaAsioWriter)
    	meaAsyncOperationStop(&mo->meaAsioWriter);
    if(mo->data)
	MEA_CFREE(mo->data);
    
    if (mo->savename)
    	MEA_CFREE(mo->savename);
    if(mo->reshandle!=0)
    {
    	MSF_WIDGET_RELEASE(mo->reshandle);
    	mo->reshandle=0;
    }

    if(mo->file)
    {
        if(mo->file->path)
            MEA_CFREE(mo->file->path);
        if(mo->file->filehandle)  /* For SD DRM, close after release resource */
        {
            MSF_FILE_CLOSE(mo->file->filehandle);
            mo->file->filehandle = 0;
        }
        MEA_CFREE(mo->file);
    }
#else
    MEA_FREE(mo->data);
#endif /* MMS_SLIM_MEM */
    if(mo->name)
  	{
        MEA_FREE(mo->name);
    }
    if (NULL != mo->content.origType)
    {
        meaFreeMmsContentType(mo->content.origType);
        MEA_FREE(mo->content.origType);
    }
    MEA_FREE(mo);
}

/*!
 * \brief Counts the number of references to a media object.
 * 
 * \param sSlide A list of SMIL slides.
 * \param mo The media object to find references for.
 * \return The numer of references to mo.
 *****************************************************************************/
int meaGetMoReferenceCount(const MeaSmilSlide *sSlide, const MeaMoDataItem *mo)
{
    int refCount = 0;
    unsigned int i;
    /* Check all slides */
    while(sSlide)
    {
        /* Are there any references */
        for (i = 0; i < MEA_MAX_SMIL_OBJS; ++i)
        {
            if ((NULL != sSlide->objects[i]) && 
                (mo == sSlide->objects[i]->object))
            {
                ++refCount;
                continue;
            }
        }
        sSlide = sSlide->next;
    }
    return refCount;
}

/*!
 * \brief Deletes a media object from the list of media objects.
 *
 * \param mediaObjects The list of media objects.
 * \param sSlide The list of slides.
 * \param mo The media object to delete.
 *****************************************************************************/
void meaDeleteMo(MeaMoDataItem **mediaObjects, const MeaSmilSlide *sSlide, 
    MeaMoDataItem *mo)
{
    MeaMoDataItem *item;
    MeaMoDataItem *prevItem;
    if ((NULL == (item = *mediaObjects)) || (NULL == mo))
    {
        return;
    }
    /* Check if more than one reference exists */
    if (meaGetMoReferenceCount(sSlide, mo) > 1)
    {
        return;
    }
    /* Delete the media object */
    if (*mediaObjects == mo)
    {
        /* Handle the first item */
        *mediaObjects = mo->next; 
    }
    else
    {
        item = *mediaObjects;
        prevItem = NULL;
        /* Find the current item and the previous item */
        while( (NULL != item) && (item != mo) )
        {
            prevItem = item;
            item = item->next;
        }
        /* Remove the item from the list */
        if (NULL == item)
        {
            return;
        }
        /*lint -e{794} */
        prevItem->next = item->next;
    }

#ifdef JPG_ENCODE
    if(meaIsResizedFile(mo->name))
    {
        MSF_FILE_REMOVE(mo->name);
    }
#endif
    meaFreeMoItem(mo);
}

/*!
 * \brief Get the total number of media objects.
 * 
 * \param mediaObjects A list of media objects.
 *****************************************************************************/
unsigned int meaGetMoCount(const MeaMoDataItem *mediaObjects)
{
    unsigned int count = 0;
    while (NULL != mediaObjects)
    {
        count++;
        mediaObjects = mediaObjects->next;
    }
    return count;
}

/* ! \brief Calculates the index of a media object
 *
 * \param mediaObjects The list of media objects
 * \param mo The media object o find the index of
 * \return The index of the object (counting from zero) or -1 if the object 
 *         does not exist.
 *****************************************************************************/
int meaGetMoIndex(const MeaMoDataItem *mediaObjects, const MeaMoDataItem *mo)
{
    int i = 0;
    while(NULL != mediaObjects)
    {
        if (mediaObjects == mo)
        {
            return i;
        }
        ++i;
        mediaObjects = mediaObjects->next;
    }
    return -1;
}


