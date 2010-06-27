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

/* !\file maslh.c
 * Logic for SMIL slide handling. 
 */

/* MSF */
#include "msf_mem.h"
#include "msf_lib.h"
#include "msf_log.h"
#include "msf_core.h"

/* MMS */
#include "mms_def.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA*/
#include "mea_def.h"
#ifdef WAP_SUPPORT
#include "mea_cfg.h"
#include "matypes.h"
#else
#include "matypes.h"
#include "mea_cfg.h"
#endif /* WAP_SUPPORT */
#include "maslh.h"
#include "mamem.h"
#include "mamoh.h"
#include "maintsig.h"
#include "mautils.h"
#include "mauicmn.h"
#include "maconf.h"
#ifdef WAP_SUPPORT
#include "mamr.h"    //for meaSetMoIsFound
#include "mase.h"   //for meaGetAttachmentSize
#include "msf_wid.h"
#endif /* WAP_SUPPORT */
#ifdef __DRM_SUPPORT__
#include "widget_extension.h" //for HDI_FileNameTranslate, wapadp.h
#include "fs_type.h"       //for drm_def.h
#include "../../drm/include/drm_def.h"
#include "../../drm/include/drm_main.h"
#endif /* __DRM_SUPPORT__ */

#ifdef MMS_SLIM_MEM
extern MSF_UINT32 meaGetCurrentAfiHandle(void);
extern void meaCleanAfiHandle(void);
#endif

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Prototypes
 *****************************************************************************/
static MSF_BOOL createSlsObject(const MeaObjInfo *objInfo, 
    SlsMediaObject **currentObj);
static void setRegions(const MeaSmilInfo *smilInfo, SlsRegion *textRegion, 
    SlsRegion *imageRegion);
static void initObjInfo(MeaObjInfo *objInfo, MeaMoDataItem *item,MSF_UINT32 textColour);
static void freeSlsMediaObject(SlsMediaObject **object);
static MeaObjInfo *findObjectInSlide(const MeaSmilSlide *sSlide, 
    MeaMediaGroupType objType, unsigned int *index);
static MSF_BOOL findEmptyObjectSlot(const MeaSmilSlide *slide, 
    unsigned int *index);
static MSF_BOOL insertByOrder(MeaSmilInfo *sInfo, MeaSmilSlide *sSlide, 
    MeaMoDataItem *item);
static MSF_UINT32 calculateAddrSize(MeaAddrItem *addr);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Creates an instance for creation of a multimedia message
 *
 * \param smilInfo Where to put the new instance.
 * \return TRUE on successful creation, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaCreateSmilInstance(MeaSmilInfo **smilInfo)
{
    if (NULL == *smilInfo)
    {
        *smilInfo = MEA_ALLOC(sizeof(MeaSmilInfo));
        memset(*smilInfo, 0, sizeof(MeaSmilInfo));
        (*smilInfo)->bgColor = SLS_COLOR_NOT_USED;  /* Do not use any default color*/
        (*smilInfo)->fgColorDefault =MEA_CFG_DEFAULT_SMIL_TEXT_COLOR;
        
    }
    else
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MASLH_A12A2B8AAC628BB2C898085D39C2618F, "(%s) (%d) SLH instance is busy!\n", __FILE__, __LINE__));
        return FALSE;
    }
    return TRUE;
}

/*! 
 * \brief De-allocates a SMIL creation instance.
 *
 * \param smilInfo The current instance.
 *****************************************************************************/
void meaCleanupSmilInstance(MeaSmilInfo **smilInfo)
{
    if (NULL != *smilInfo)
    {
        meaDeleteAllSlides(*smilInfo);
        /*
         *	Optimize deallocates objects not referenced by any SMIL slides, i.e. 
         *  removes all media objects in the case of multipart/mixed.
         */
        meaOptimizeMoList(*smilInfo);
        /* Remove the SMIL presentation */
        MEA_FREE(*smilInfo);
        *smilInfo = NULL;
    }
}

/*!
 * \brief Get the total number of slides.
 * 
 * \param smilInfo The current instance.
 * \return The total number of slides.
 *****************************************************************************/
unsigned int meaGetSlideCount(const MeaSmilInfo *smilInfo)
{
    if (NULL != smilInfo)
    {
        return smilInfo->noOfSlides;
    }
    return 0;
}

/*!
 * \brief Deletes all slides
 *
 * \param smilInfo The current SMIl presentation.
 *****************************************************************************/
void meaDeleteAllSlides(MeaSmilInfo *smilInfo)
{
    /* Delete all slides */
    while (meaDeleteSlide(smilInfo))
    {
    }

    smilInfo->slides        = (struct MeaSmilSlideSt *)NULL;
    smilInfo->currentSlide  = (struct MeaSmilSlideSt *)NULL;
    smilInfo->noOfSlides    = 0;
} /* deleteAllSlides */

#ifdef WAP_SUPPORT
/*!
 * \brief Deletes all empty slides
 * \param smilInfo All slides.
 * \return TRUE on ok or FALSE on error
 *****************************************************************************/
MSF_BOOL meaDeleteAllEmptySlides(MeaSmilInfo *smilInfo)
{
    MeaSmilSlide *delSlide;
    MeaSmilSlide *prev;
    MeaSmilSlide *current;
    MeaSmilSlide *theSlide = NULL;
    if (!smilInfo)
        return FALSE;

    theSlide = smilInfo->slides;
    if (!theSlide)
        return FALSE;
    
    while (theSlide->next)
    {
        if (!theSlide->objects[0])
        {
            delSlide = theSlide;
            prev = NULL;
            current = smilInfo->slides;
            /* Find the current item and its predecessor */
            while (delSlide != current)
            {
                prev = current;
                current = current->next;
            }
       
            /* Set new active slide */
            if (NULL != prev)
            {
                if (smilInfo->currentSlide ==delSlide)
                    smilInfo->currentSlide = prev;
                prev->next = delSlide->next;
            }
            else if (NULL != delSlide->next)
            {
                if (smilInfo->currentSlide ==delSlide)
                    smilInfo->currentSlide = delSlide->next;
                if (smilInfo->slides == delSlide)
                {
                    smilInfo->slides = delSlide->next;
                }
            }
            else
            {
                smilInfo->currentSlide = NULL;
                smilInfo->slides = NULL;
            }
            smilInfo->noOfSlides--;
            /* Free the slide */
            MEA_FREE(delSlide);
        }
        theSlide = theSlide->next;
    }
    if (!theSlide->objects[0])
    {
            delSlide = theSlide;
            prev = NULL;
            current = smilInfo->slides;
            while (delSlide != current)
            {
                prev = current;
                current = current->next;
            }
            if (NULL != prev)
            {
                if (smilInfo->currentSlide ==delSlide)
                    smilInfo->currentSlide = prev;
                prev->next = delSlide->next;
            }
            else if (NULL != delSlide->next)
            {
                if (smilInfo->currentSlide ==delSlide)
                    smilInfo->currentSlide = delSlide->next;
                if (smilInfo->slides == delSlide)
                    smilInfo->slides = delSlide->next;
            }
            else
            {
                smilInfo->currentSlide = NULL;
                smilInfo->slides = NULL;
            }
            smilInfo->noOfSlides--;
            MEA_FREE(delSlide);
    }
    return TRUE;
} /* meaDeleteAllEmptySlides */

MSF_BOOL meaIsObjectInSlide(MeaMoDataItem *item, MeaSmilSlide *slide)
{
    int i;

    if(item == NULL || slide == NULL)
        return FALSE;
    
    for (i=0; i<MEA_MAX_SMIL_OBJS; i++)
    {
        if (!slide->objects[i])
            return FALSE;
        if (slide->objects[i]->object == item)
            return TRUE;
    }
    return FALSE;
}

MeaMediaGroupType meaGetLayoutOrder(const MeaSmilInfo *sInfo)
{
    MeaSmilSlide *currentSlide = NULL;
    MeaObjInfo *textObj = NULL;
    MeaObjInfo *imageObj = NULL;
    MeaObjInfo *videoObj = NULL;
    unsigned int i = 0, ii = 0;

    for (currentSlide = sInfo->slides; currentSlide != NULL; currentSlide = currentSlide->next)
    {
        textObj = findObjectInSlide(currentSlide, MEA_MEDIA_GROUP_TEXT, &i);
        imageObj = findObjectInSlide(currentSlide, MEA_MEDIA_GROUP_IMAGE, &ii);
        if(imageObj == NULL)
            videoObj = findObjectInSlide(currentSlide, MEA_MEDIA_GROUP_VIDEO, &ii);
        	
        if ((NULL != textObj) && (NULL != imageObj))
        {
            if(i < ii)
            	return MEA_MEDIA_GROUP_TEXT;
            else if(i > ii)
            	return MEA_MEDIA_GROUP_IMAGE;
        }
        else if ((NULL != textObj) && (NULL != videoObj))
        {
            if(i < ii)
            	return MEA_MEDIA_GROUP_TEXT;
            else if(i > ii)
            	return MEA_MEDIA_GROUP_VIDEO;
        }
    }

    return MEA_MEDIA_GROUP_NONE;
}
#endif /* WAP_SUPPORT */

/*!
 * \brief Deletes a slide
 *
 * \param smilInfo All slides.
 * \return TRUE on ok or FALSE on error
 *****************************************************************************/
MSF_BOOL meaDeleteSlide(MeaSmilInfo *smilInfo)
{
    MeaSmilSlide *delSlide;
    MeaSmilSlide *prev;
    MeaSmilSlide *current;
    unsigned int i;

    delSlide = smilInfo->currentSlide;
    /* Check that the "current" slide exists */
    if ((NULL != smilInfo->currentSlide) && (smilInfo->slides != NULL))
    {
        /* Free all data that is associated with the slide */
        for (i = 0; i < MEA_MAX_SMIL_OBJS; i++)
        {
            if ((NULL != delSlide->objects[i]) && 
                (NULL != delSlide->objects[i]->object))
            {
                /* Delete the object data */
                meaDeleteMo(&(smilInfo->mediaObjects), smilInfo->slides, 
                    delSlide->objects[i]->object);
                MEA_FREE(delSlide->objects[i]);
                delSlide->objects[i] = NULL;
            }
        }
        prev = NULL;
        current = smilInfo->slides;
        /* Find the current item and its predecessor */
        while (delSlide != current)
        {
            prev = current;
            current = current->next;
        }
       
        /* Set new active slide */
        if (NULL != prev)
        {
            smilInfo->currentSlide = prev;
            prev->next = delSlide->next;
        }
        else if (NULL != delSlide->next)
        {
            smilInfo->currentSlide = delSlide->next;
            if (smilInfo->slides == delSlide)
            {
                smilInfo->slides = smilInfo->currentSlide;
            }
        }
        else
        {
            smilInfo->currentSlide = NULL;
            smilInfo->slides = NULL;
        }
        smilInfo->noOfSlides--;
        /* Free the slide */
        MEA_FREE(delSlide);
        return TRUE;
    }
    return FALSE;
} /* meaDeleteSlide */

/*!
 * \brief Gets the currently active slide.
 *
 * \param smilInfo The current multimedia presentation.
 * \return The current slide
 *****************************************************************************/
MeaSmilSlide *meaGetCurrentSlide(const MeaSmilInfo *smilInfo)
{
    return smilInfo->currentSlide;
} /* meaGetCurrentSlide */

/*!
 * \brief Gets the duration for the current slide.
 *
 * \param smilInfo The current multimedia presentation.
 * \return  The duration in milliseconds.
 *****************************************************************************/
unsigned int meaGetDuration(const MeaSmilInfo *smilInfo)
{
    if (NULL != smilInfo->currentSlide)
    {
        return (unsigned int)smilInfo->currentSlide->duration;
    }
    return MEA_CFG_DEFAULT_DURATION;    
}

/*!
 * \brief Gets the pointer to the first slide
 * \param smilInfo The current multimedia presentation.
 * \return Pointer to the first slide or NULL.
 *****************************************************************************/
MeaSmilSlide *meaGetFirstSlide(const MeaSmilInfo *smilInfo)
{
    return smilInfo->slides;
} /* meaGetFirstSlide */

/*!
 * \brief Gets the next slide
 * \param smilInfo The current multimedia presentation.
 * \return The next slide
 *****************************************************************************/
MeaSmilSlide *meaGetNextSlide(MeaSmilInfo *smilInfo)
{
    if (NULL != smilInfo->currentSlide->next)
    {
        smilInfo->currentSlide = smilInfo->currentSlide->next;
        return smilInfo->currentSlide;
    }
    else
    {
#ifdef WAP_SUPPORT
        return NULL;
#else
        return smilInfo->currentSlide;
#endif /* WAP_SUPPORT */
    } /* if */
} /* meaGetNextSlide */

/*!
 * \brief Gets the previous slide
 * \param smilInfo The current multimedia presentation.
 * \return The previous slide or NULL.
 *****************************************************************************/
MeaSmilSlide *meaGetPreviousSlide(MeaSmilInfo *smilInfo)
{
    MeaSmilSlide *current;
    current = smilInfo->slides;
    
    while((NULL != current) && (current->next != smilInfo->currentSlide))
    {
        current = current->next;
    } /* while */

    if (current == NULL)
    {
        return NULL;
    } 
    else if (current->next == smilInfo->currentSlide)
    {
        smilInfo->currentSlide = current;
        return current;
    }
    else
    {
        return current;
    } /* if */
} /* meaGetPreviousSlide */

/*!
 * \brief Retrieves the index of the current slide
 * \param smilInfo The current SMIL presentation.
 * \param slide The slide to find the index of.
 * \return The index of the slide counting from 0.
 *****************************************************************************/
unsigned int meaGetSlideIndex(const MeaSmilInfo *smilInfo, 
    const MeaSmilSlide *slide)
{
    MeaSmilSlide *current = smilInfo->slides;
    unsigned int index = 0;
    while ((NULL != current) && (current != slide))
    {
        current = current->next;
        index ++;
    } /* while */
    return index;
} /* meaGetSlideIndex */

/*!
 * \brief Adds a new slide to the list of slides after the current one,
 *          and updates the current-pointer and slide count.
 * \param smilInfo The current SMIL presentation.
 * \return The new slide, or NULL.
 *****************************************************************************/
MeaSmilSlide *meaInsertSlide(MeaSmilInfo *smilInfo)
{
    MeaSmilSlide *newSlide = NULL;
    
    newSlide = (MeaSmilSlide*)MEA_ALLOC(sizeof(MeaSmilSlide));
	if (newSlide == NULL)
    {
        return NULL;
    }
    memset(newSlide, 0, sizeof(MeaSmilSlide));
#ifdef WIDGET_ADVANCED_SMIL_EDITOR    
    HDIa_widgetExtSmilEditorChangeSlide(KAL_TRUE);
#endif /*WIDGET_ADVANCED_SMIL_EDITOR*/    
    if (NULL != smilInfo->currentSlide)
    {
        newSlide->next = smilInfo->currentSlide->next;
        smilInfo->currentSlide->next = newSlide;
    }
    else
    {
        smilInfo->slides = newSlide;
        newSlide->next = NULL;
    }
    smilInfo->noOfSlides++;
    smilInfo->currentSlide = newSlide;
    /* Set the default duration */
    meaSetDuration(smilInfo, (unsigned)meaGetConfig()->slideDuration * 1000);
    return newSlide;
} /* meaInsertSlide */

#ifdef WAP_SUPPORT
/*!
 * \brief Adds a new slide to the list of slides before the current one,
 *          and updates the current-pointer and slide count.
 * \param smilInfo The current SMIL presentation.
 * \return The new slide, or NULL.
 *****************************************************************************/
MeaSmilSlide *meaInsertSlideBefore(MeaSmilInfo *smilInfo)
{
    MeaSmilSlide *newSlide = NULL;
    
    newSlide = (MeaSmilSlide*)MEA_ALLOC(sizeof(MeaSmilSlide));
    if (newSlide == NULL)
    {
        return NULL;
    }
    memset(newSlide, 0, sizeof(MeaSmilSlide));
#ifdef WIDGET_ADVANCED_SMIL_EDITOR
    HDIa_widgetExtSmilEditorChangeSlide(KAL_TRUE);
#endif /*WIDGET_ADVANCED_SMIL_EDITOR*/
    if (NULL != smilInfo->currentSlide)
    {
        if (smilInfo->currentSlide == smilInfo->slides)
        {
            newSlide->next = smilInfo->slides;
            smilInfo->slides = newSlide;
        }
        else
        {
            MeaSmilSlide *prev = NULL;
            for (prev = smilInfo->slides; prev->next != smilInfo->currentSlide; prev = prev->next);    

            prev->next = newSlide;
            newSlide->next = smilInfo->currentSlide;
        }
    }
    else
    {
        smilInfo->slides = newSlide;
        newSlide->next = NULL;
    }
    smilInfo->noOfSlides++;
    smilInfo->currentSlide = newSlide;
    /* Set the default duration */
    meaSetDuration(smilInfo, (unsigned)meaGetConfig()->slideDuration * 1000);
    return newSlide;
} /* meaInsertSlide */
#endif

/*!
 * \brief Sets the duration for the current slide.
 *
 * \param smilInfo The current multimedia presentation.
 * \param duration The new duration in milliseconds.
 *****************************************************************************/
void meaSetDuration(const MeaSmilInfo *smilInfo, unsigned int duration)
{
    if (NULL != smilInfo->currentSlide)
    {
        if(duration > MEA_CFG_MAX_DURATION * 1000)
        {
            smilInfo->currentSlide->duration = MEA_CFG_MAX_DURATION * 1000;
        }
        else
        {
            smilInfo->currentSlide->duration = duration;
        }
    }
}

/* ! Sets the default values for a #MeaobjInfo structure.
 *
 * \param objInfo The structure to init.
 * \param item The #MeamoDataItem that is attached to the slide
 *****************************************************************************/
static void initObjInfo(MeaObjInfo *objInfo, MeaMoDataItem *item,MSF_UINT32 textColour)
{
    memset(objInfo, 0, sizeof(MeaObjInfo));
    objInfo->textColor = textColour;
    objInfo->object    = item;
}

/*!
 * \brief Sets a media object for the current slide.
 * 
 * \param smilInfo The current instance.
 * \param objType The type of media object to set, see #MeaMediaType.
 * \param buffer The media content to set.
 * \param bufferSize The size of the content to add.
 * \param name The unique name of the content.
 *****************************************************************************/
#ifdef __DRM_SUPPORT__ 
MeaMoDataItem *meaSetSlideMo(MeaSmilInfo *smilInfo, MeaMediaType type, MeaMediaType drmType,
    MmsContentType *mmsType, unsigned char *buffer, unsigned int bufferSize, char *name, MSF_UINT32 resHandle)
#else
MeaMoDataItem *meaSetSlideMo(MeaSmilInfo *smilInfo, MeaMediaType type, 
    MmsContentType *mmsType, unsigned char *buffer, unsigned int bufferSize, char *name, MSF_UINT32 resHandle)
#endif
{
    MeaMoDataItem *item;
    MeaSmilSlide *sSlide;

    /* get current slide */
    if (NULL == (sSlide = meaGetCurrentSlide(smilInfo)))
    {
        return NULL;
    }
    item = NULL;
    /* Check if the item already exists. If exists, use an existing one*/
    if ((NULL != (item = meaFindMo(smilInfo->mediaObjects, name))) && !meaIsObjectInSlide(item, sSlide))
    {
        /* If the item already exists the data needs to be deallocated */
        MEA_FREE(buffer);
        MEA_FREE(name);
        meaSetMoIsFound();
        
        if (NULL != mmsType)
            meaFreeMmsContentType(mmsType);
    }
    else
    {
#ifdef __DRM_SUPPORT__
        item = meaAddMo(&(smilInfo->mediaObjects), buffer, bufferSize, type, drmType, mmsType, name,0, resHandle);
#else
        item = meaAddMo(&(smilInfo->mediaObjects), buffer, bufferSize, type, mmsType, name,0, resHandle);
#endif
    }
    
    if (NULL == item)
    {
        return NULL;
    }
    
    /* Find the slot */
    if (insertByOrder(smilInfo, sSlide, item))
    {
        return item;
    }
    return NULL;
}

/*! Gets information about a an object referenced by the current slide
 *
 * \param sInfo The current presentation.
 * \param type The type of object to find
 * \param objInfo The resulting object is placed here.
 * \return TRUE if a object of the correct type was found otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaGetObjInfo(const MeaSmilInfo *sInfo, MeaMediaGroupType objType, 
    MeaObjInfo **objInfo)
{
    unsigned int i;
    MeaSmilSlide *sSlide = meaGetCurrentSlide(sInfo);
    if (NULL == sSlide)
    {
        return FALSE;
    }
    *objInfo = findObjectInSlide(sSlide, objType, &i);
    return (NULL != *objInfo) ? TRUE: FALSE;
}

/*!
 * \brief Get the current media object.
 * 
 * \param smilInfo The current instance.
 * \param objType The type of object to return.
 * \return A reference to the item or NULL.
 *****************************************************************************/
MeaMoDataItem *meaGetMo(const MeaSmilInfo *smilInfo, MeaMediaGroupType objType)
{
    MeaSmilSlide *sSlide = meaGetCurrentSlide(smilInfo);
    MeaObjInfo *objInfo;
    unsigned int i;
    /* Check the current slide */
    if (NULL != sSlide)
    {
        /* Find the media object */
        if (NULL != (objInfo = findObjectInSlide(sSlide, objType, &i)))
        {
            return objInfo->object;
        }
    }
    return NULL;
}

/*! \brief Calculates the size of a list of addresses.
 *
 * \param addr The list of addresses.
 * \return The size in bytes.
 *****************************************************************************/
static MSF_UINT32 calculateAddrSize(MeaAddrItem *addr)
{
    MSF_UINT32 size = 0, i = 1;
    if(addr == NULL)
    {
        return 0;
    }    	
	while (NULL != addr && i <= MEA_CFG_MAX_RECIPIENT_ADDRESSES) 
	{
		size += (NULL != addr->address) ? (msf_cmmn_utf8_strlen(addr->address) + 1) : 0;
  		size += (NULL != addr->name)    ? (msf_cmmn_utf8_strlen(addr->name)    + 1) : 0;
#ifdef WAP_SUPPORT
		size = size + msf_cmmn_utf8_strlen("/TYPE=XXXXX") + 2; //encoding length
#endif /* WAP_SUPPORT */
        addr = addr->next;
        i++;
	} /* while */
    return size;
}
MSF_UINT8 meaLenUintvar(MSF_UINT32 n)
{
    if (n < 0x80)
    {
        return 1;
    }
    else if (n < 0x4000)
    {
        return 2;
    }
    else if (n < 0x200000)
    {
        return 3;
    }
    else if (n < 0x10000000)
    {
        return 4;
    }
    else
    {
        return 5;
    } 
} 
MSF_UINT8 meaLenValueLength(MSF_UINT32 n)
{
    MSF_UINT8 size = 0;
    if(n > 30)
    {
        size += meaLenUintvar(n);
        size++;  /* Length-quote */
    }
    else
    {
        size = 1;
    }

    return size;
} 

MSF_UINT32 meaMultiPartHeaderSize(char *filename)
{
    MSF_UINT32 hd_size = 0, ct_size = 0;
    const char *mime = NULL;
    MmsKnownMediaType type = MMS_VALUE_AS_STRING;
    MSF_BOOL is_smil = KAL_FALSE;

    ASSERT(filename != NULL);

    filename = msf_cmmn_strdup(MSF_MODID_MEA, filename);
    meaExtractFileName(filename);
    
    mime = (char *)meaFileName2MimeType(filename);
    if(mime != NULL)
        is_smil = (strcmp(MMS_MEDIA_TYPE_STRING_SMIL, mime) == 0);
    
    /* ContentType */
    /* Media-type */
    if((type = meaMime2MmsMediaType(mime)) != MMS_VALUE_AS_STRING)
    {
        ct_size += 1;  /* value */
    }
    else
    {
        ct_size += (msf_cmmn_utf8_strlen(mime) + 1);  /* string */
    }

    /* Parameter Charset */
    if(type == MMS_TYPE_TEXT_PLAIN || is_smil)
    {
        ct_size += 2;  /* 0x81 0x?? */
    }

    /* Parameter Name */
    ct_size += (msf_cmmn_utf8_strlen(filename) + 2);  /* 0x85 + [name] + '\0'*/

    /* Value-length */
    ct_size += meaLenValueLength(ct_size);
    hd_size += ct_size;

    /* Content Location: 0x8e + [name] + '\0'*/
    hd_size += (msf_cmmn_utf8_strlen(filename) + 2);
    
    /* Content ID: 0xc0 + '"' + '<' + [name] + '>' + '\0'*/
    if (is_smil)
    {
        hd_size += (msf_cmmn_utf8_strlen((char *)MEA_SMIL_CONTENT_ID)+ 5 );
    }
    else
    {
        hd_size += (msf_cmmn_utf8_strlen(filename) + 5);
    }

    /* HeadersLen */
    hd_size += meaLenUintvar(hd_size);

    MEA_FREE(filename);
    return hd_size;
}

MSF_UINT32 meaHeaderSize(const MeaPropItem *propItem)
{
    MSF_UINT32 size = 0, tmp_size = 0;
    MeaAddrItem *addr = NULL;

    /* X-Mms-Message-Type ~ From*/
    size = 2 + 12 + 2 + 3;

    /* To */
    addr = propItem->to;
    size += calculateAddrSize(addr);
 
    /* Cc */
    addr = propItem->cc;
    size += calculateAddrSize(addr);
    
    /* Bcc */
    addr = propItem->bcc;
    size += calculateAddrSize(addr);

    /* Subject */
    if(propItem->subject != NULL)
    {
        size += msf_cmmn_utf8_strlen(propItem->subject)+1;
    }

    /* X-Mms-Expiry */
    switch (propItem->expiryTime)
    {
    case MEA_EXPIRY_1_HOUR:
        size += 6;  /* 88 [Value-Length:04] 81 [Short-length:02] XX XX */
    case MEA_EXPIRY_12_HOURS:
        size += 6;
    case MEA_EXPIRY_1_DAY:
        size += 7;  /* 88 [Value-Length:05] 81 [Short-length:03] XX XX XX */
    case MEA_EXPIRY_1_WEEK:
        size += 7;
    case MEA_EXPIRY_MAX:
    default:
        break;
    }


    /* X-Mms-Priority ~ X-Mms-Read-Report */
    size += (2 + 2 + 2);

    /* Content-type */
    tmp_size = 5 + msf_cmmn_utf8_strlen(MMS_MEDIA_TYPE_STRING_SMIL)  + msf_cmmn_utf8_strlen((char *)MEA_SMIL_CONTENT_ID) +  strlen("<>");
    size +=  (1 + meaLenUintvar(tmp_size) + tmp_size);

    return size;
}
/*!
 * \brief Calculate the approximate size of the message.
 *
 * \param The current instance.
 * \param The current message properties.
 * \return The approximate size of the message.
 *****************************************************************************/
MSF_UINT32 meaCalculateMsgSize(const MeaSmilInfo *smilInfo, 
    const MeaPropItem *propItem)
{
    unsigned int msgSize = 0;
    MeaMoDataItem *moItem;
    MeaSmilSlide *sSlide;
    unsigned int i;

    /* Message header */
    /* Static data estimation */
    msgSize += meaHeaderSize(propItem);
    /*multipart header*/
    msgSize += meaMultiPartHeaderSize((char *)MEA_SMIL_FILE_NAME);
    
    /* Body parts */
#ifdef WAP_SUPPORT
    if (!smilInfo)
        return 0;  //ToDo forward doesn't have smilInfo
    else
#endif /* WAP_SUPPORT */    
    moItem = smilInfo->mediaObjects;
    msgSize += meaLenUintvar(meaGetMoCount(moItem)+ 1);  /* add SMIL part */
    while (NULL != moItem)
    {
        /* Body part */
        msgSize += moItem->size + meaMultiPartHeaderSize(moItem->name);
        msgSize += meaLenUintvar(moItem->size);        
        moItem = moItem->next;
    }
    /* The SMIL presentation */
    msgSize += MEA_SMIL_SIZE;
    sSlide = smilInfo->slides;
    while (NULL != sSlide)
    {
        /* Add the size of each par  */
        msgSize += MEA_SMIL_PAR_SIZE;
        for (i = 0; i < MEA_MAX_SMIL_OBJS; i++)
        {
            if (NULL != sSlide->objects[i])
            {
                int file_len, is_ascii = meaCheckCharacterIsAllEnglish(sSlide->objects[i]->object->name);
                char *object_fname;
#ifdef AU_DECODE
                if(sSlide->objects[i]->object->content.type >= MEA_MEDIA_TYPE_AMR &&
                   sSlide->objects[i]->object->content.type <= MEA_MEDIA_TYPE_BASIC )
                {
                    msgSize += MEA_AUDIO_SMIL_SRC_REG_SIZE;                
                }
                else
#endif /*AU_DECODE*/                	
                /* text src="??" region="??" */
	                msgSize += MEA_SMIL_SRC_REG_SIZE;

                /* add file length*/
                if(is_ascii)
                {
                    file_len = msf_cmmn_utf8_strlen(sSlide->objects[i]->object->name)+1;
                    MEA_CALLOC(object_fname, file_len);

                    msf_cmmn_strcpy_lc(object_fname, sSlide->objects[i]->object->name);
                    meaExtractFileName(object_fname);
                    msgSize += strlen(object_fname) + 1;
                    MEA_FREE(object_fname);
                }
                else
                    msgSize += MEA_SMIL_NONASCII_FNAME_SIZE;

                /* add text parameter */
                if(sSlide->objects[i]->object->content.type == MEA_MEDIA_TYPE_TEXT_PLAIN)
                    msgSize += MEA_SMIL_TXT_PARAM_SIZE;
                    
            }
            else
            {
                break;
            }
        }
        sSlide = sSlide->next;
    }
#ifdef WAP_SUPPORT
    msgSize += meaGetAttachmentSize();
#endif /* WAP_SUPPORT */
    /* return the approximate size of the message */
    return msgSize;
}

/*!
 * \brief Deletes a media object from the current slide.
 * 
 * \param The current SMIL presentation
 * \param The object type to delete.
 * \return TRUE if a media object was deleted, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaDeleteSlideMo(MeaSmilInfo *smilInfo, MeaMediaGroupType objType)
{
    unsigned int i;
    unsigned int ii;
    MeaSmilSlide *slide;
    MeaObjInfo *objInfo = NULL;
    if (NULL == (slide = meaGetCurrentSlide(smilInfo)))
    {
        return FALSE;
    }
    /* Get object according to the object type */
    if (NULL == (objInfo = findObjectInSlide(slide, objType, &i)))
    {
        return FALSE;
    }
    /* Delete the object from the list of objects */
    meaDeleteMo(&(smilInfo->mediaObjects), smilInfo->slides, 
        objInfo->object);
    /* Reorder the list of current objects */
    for (ii = i = 0; i < MEA_MAX_SMIL_OBJS; i++)
    {
        if (objInfo != slide->objects[i])
        {
            slide->objects[ii] = slide->objects[i];
            ++ii;
        }
    }
    /* The last entry must be set to NULL */
    slide->objects[MEA_MAX_SMIL_OBJS - 1] = NULL;
    /*lint -e{774} */
    MEA_FREE(objInfo);
    objInfo = NULL;

    return TRUE;
}

/*! \brief Removes all media-objects that does not have any reference in the
 *         Slide list.
 *
 * \param smilInfo A reference to the current SMIL presentation.
 *****************************************************************************/
void meaOptimizeMoList(MeaSmilInfo *smilInfo)
{
    MeaSmilSlide  *slide;
    MeaMoDataItem *mo;
    MeaMoDataItem *tmpMo;
    unsigned int i;
    MSF_BOOL refFound;
    if (NULL != smilInfo)
    {
        /* Go through all media objects */
        mo = smilInfo->mediaObjects;
        while (NULL != mo)
        {
            /* Check that the current media object has a reference */
            slide = smilInfo->slides;
            refFound = FALSE;
            while((NULL != slide) && !refFound)
            {
                for (i = 0; i < MEA_MAX_SMIL_OBJS; i++)
                {
                    if (NULL != slide->objects[i])
                    {
                        if (slide->objects[i]->object == mo)
                        {
                            refFound = TRUE;
                            break;
                        }
                    }
                    else if (NULL == slide->objects[i])
                    {
                        break;
                    }
                }
                slide = slide->next;
            }
            /* Save the pointer if the object needs to be removed */
            tmpMo = mo;
            /* Check next object */
            mo = mo->next;
            /* Check if any reference has been found */
            if (!refFound)
            {
                /* Delete the object since it has no reference */
                meaDeleteMo(&(smilInfo->mediaObjects), smilInfo->slides, 
                    tmpMo);
            }
        }
    }
}

/*!
 * \brief Create a SLS object.
 *
 * \param objInfo The current media onject.
 * \param currentObj Where to put the new object.
 *
 * \return TRUE if successful, otherwise FALSE
 *****************************************************************************/
static MSF_BOOL createSlsObject(const MeaObjInfo *objInfo, 
    SlsMediaObject **currentObj)
{
    int size;
    const char *regionType;
    SlsMediaObject *obj = NULL;

    /* Sanity check */
    if ((NULL == objInfo->object) || (NULL == objInfo->object->savename))
    {
        *currentObj = NULL;
    }
    else
    {
        /* MO */
        MEA_CALLOC(obj, sizeof(SlsMediaObject));
        /* src */
        size = (signed)strlen(objInfo->object->savename) + 1;
        obj->src = MEA_ALLOC((unsigned)size);
        strcpy(obj->src, (char*)objInfo->object->savename);
        
        /* region */
        regionType = NULL;
        switch(meaMediaType2ObjType(objInfo->object->content.type))
        {
        case MEA_MEDIA_GROUP_TEXT:
            regionType = MEA_TEXT_REGION;
            obj->color = objInfo->textColor;
            break;
        case MEA_MEDIA_GROUP_IMAGE:
        case MEA_MEDIA_GROUP_VIDEO:
            regionType = MEA_IMAGE_REGION;
            break;
        case MEA_MEDIA_GROUP_AUDIO:
            break;
#ifdef __DRM_SUPPORT__
        case MEA_MEDIA_GROUP_DRM:
        {
            switch (meaMediaType2ObjType(
                        meaDrm2MediaType((char*)objInfo->object->name)))
            {
                case MEA_MEDIA_GROUP_TEXT:
                    regionType = MEA_TEXT_REGION;
                    obj->color = objInfo->textColor;
                break;
                case MEA_MEDIA_GROUP_IMAGE:
                case MEA_MEDIA_GROUP_VIDEO:
                    regionType = MEA_IMAGE_REGION;
                break;
            }
            break;
        }
#endif /* __DRM_SUPPORT__ */
        case MEA_MEDIA_GROUP_NONE:
            return FALSE;
        }
        /* Begin and end time */
        obj->beginT = objInfo->begin;
        obj->endT = objInfo->end;
        /* Check if any region needs to be set */
        if (NULL != regionType)
        {
            size = (signed)strlen(regionType) + 1;
            obj->region = MEA_ALLOC((unsigned)size);
            strcpy(obj->region, regionType);
        }
        else
        {
            obj->region = NULL;
        }
        
        /* type */
        obj->type = meaConvertMediaTypeToSls(objInfo->object->content.type);
    } /* if */
    *currentObj = obj;
    return TRUE;
}

/*!
 * \brief Creates the text part of a SMIL presentation.
 *
 * \param smilInfo The current SMIL presentation
 * \param buffer The SMIL text part or NULL.
 * \param size The size of the SMIL part
 *
 * \return TRUE if the SMIL was created successfully, otherwsie FALSE.
 *****************************************************************************/
MSF_BOOL meaCreateSmil(MeaSmilInfo *smilInfo, char **buffer, 
    unsigned int *size)
{
    int status =    TRUE;
    MeaSmilSlide    *old;
    char            *smilBuffer = NULL;

    SlsRootLayout rootLayout;
    SlsRegion   textRegion;
    SlsRegion   imageRegion;
    MsfSize     displaySize;
    SlsCreateSmilHandle handle = NULL;

    SlsMediaObject  *textObject;
    SlsMediaObject  *imageObject;
    SlsMediaObject  *audioObject;
    SlsMediaObject  *videoObject;
    
    MeaObjInfo      *objInfo;
    
    *buffer = NULL;
    *size = 0;
    /* Set the layout */
    meaGetDisplaySize(&displaySize);
    rootLayout.cx.type  = SLS_ABS;
    rootLayout.cx.value = (MSF_UINT16)displaySize.width;
    rootLayout.cy.type  = SLS_ABS;
    rootLayout.cy.value = (MSF_UINT16)displaySize.height;
    rootLayout.bgColor  = smilInfo->bgColor;

    /* Set regions */
    setRegions(smilInfo, &textRegion, &imageRegion);
    /* Create the SMIL presentation */
    if (SLS_RESULT_OK != SLSlib_createSmil(MSF_MODID_MEA, &handle, 
        &rootLayout))
    {
        return FALSE;
    }
    else if (SLS_RESULT_OK != SLSlib_createRegion(MSF_MODID_MEA, &handle,
        &imageRegion, MEA_IMAGE_REGION))
    {
        (void)SLSlib_cancelCreateSmil(MSF_MODID_MEA, &handle);
        return FALSE;
    }
    else if (SLS_RESULT_OK != SLSlib_createRegion(MSF_MODID_MEA, &handle,
        &textRegion, MEA_TEXT_REGION))
    {
        (void)SLSlib_cancelCreateSmil(MSF_MODID_MEA, &handle);
        return FALSE;
    }

    old = smilInfo->currentSlide;
    /* Get the first slide */
    smilInfo->currentSlide = meaGetFirstSlide(smilInfo);
    
    /* Go through all slides */
    while ((NULL != smilInfo->currentSlide) && (status))
    {
        /* Text */
        textObject = NULL;
        if (meaGetObjInfo(smilInfo, MEA_MEDIA_GROUP_TEXT, &objInfo))
        {
            if (!createSlsObject(objInfo, &textObject))
            {
                status = FALSE;
            }
        }
        /* Image */
        imageObject = NULL;
        if (meaGetObjInfo(smilInfo, MEA_MEDIA_GROUP_IMAGE, &objInfo))
        {
            if (!createSlsObject(objInfo, &imageObject))
            {
                status = FALSE;
            }
        }
        /* Audio */
        audioObject = NULL;
        if (meaGetObjInfo(smilInfo, MEA_MEDIA_GROUP_AUDIO, &objInfo))
        {
            if (!createSlsObject(objInfo, &audioObject))
            {
                status = FALSE;
            }
        }

        /* Video */
        videoObject = NULL;
        if (meaGetObjInfo(smilInfo, MEA_MEDIA_GROUP_VIDEO, &objInfo))
        {
            if (!createSlsObject(objInfo, &videoObject))
            {
                status = FALSE;
            }
        }

        /* Check that the slide is valid, i.e., that objects exists in the 
           slide */
#ifndef WAP_SUPPORT	/* MTK support empty slide */
        if ((NULL != textObject) || (NULL != audioObject) || (NULL != imageObject))
        {
#endif	/* WAP_SUPPORT */
            /* Create the slide */
            if (status && (SLS_RESULT_OK != SLSlib_createSlide(MSF_MODID_MEA, 
                &handle, (signed)smilInfo->currentSlide->duration, textObject, 
                imageObject, videoObject, audioObject)))
            {
                (void)SLSlib_cancelCreateSmil(MSF_MODID_MEA, &handle);
                status = FALSE;
            } /*  */
#ifndef WAP_SUPPORT
        }
#endif	/* WAP_SUPPORT */

        /* Free Text object */
        if (textObject != NULL)
        {
            freeSlsMediaObject(&textObject);
        } /* if */
        /* Free Image object */
        if (imageObject != NULL)
        {
           freeSlsMediaObject(&imageObject);
        }
        /* Free Audio object */
        if (audioObject != NULL)
        {
           freeSlsMediaObject(&audioObject);
        }

        /* Free Video object */
        if (videoObject != NULL)
        {
           freeSlsMediaObject(&videoObject);
        }
        smilInfo->currentSlide = smilInfo->currentSlide->next;
    } /* while */
    smilInfo->currentSlide = old;
    if (status)
    {
        if (SLS_RESULT_OK != SLSlib_generateSmil(MSF_MODID_MEA, &handle, 
            (char **)&smilBuffer))
        {
            (void)SLSlib_cancelCreateSmil(MSF_MODID_MEA, &handle);
            status = FALSE;
        } /* if */
    } /* if */
    
    if (!status)
    {
        return FALSE;
    } /* if */
    *buffer = smilBuffer;
    *size   = strlen(smilBuffer);
    return TRUE;
} /* createSmil */

/*!
 * \brief Sets text and image regions for one slide
 * \param smilInfo The current SMIL presentation.
 * \param textRegion Where to set text region
 * \param imageRegion Where to set image region
 *****************************************************************************/
static void setRegions(const MeaSmilInfo *smilInfo, SlsRegion *textRegion, 
    SlsRegion *imageRegion)
{
    MeaSmilSlide *sSlide;
    unsigned int tIndex;
    unsigned int iIndex;

    /* Common region settings */
    /* Text type */
    textRegion->position.cx.value   = 0;
    textRegion->size.cx.value       = 100; 
    textRegion->position.cx.type    = SLS_REL;
    textRegion->position.cy.type    = SLS_REL;
    textRegion->size.cx.type        = SLS_REL;
    textRegion->size.cy.type        = SLS_REL;
    textRegion->fit = SLS_ATTR_SCROLL;
    
    /* image type */
    imageRegion->position.cx.value  = 0;
    imageRegion->size.cx.value      = 100;
    imageRegion->position.cx.type   = SLS_REL;
    imageRegion->position.cy.type   = SLS_REL;
    imageRegion->size.cx.type       = SLS_REL;
    imageRegion->size.cy.type       = SLS_REL;
    imageRegion->fit = SLS_ATTR_MEET;

    /* Check for multiple regions */
    for (sSlide = meaGetFirstSlide(smilInfo); sSlide != NULL; sSlide = sSlide->next)
    {
        /* Check if any slides has reference to both image and text */
        if (findObjectInSlide(sSlide, MEA_MEDIA_GROUP_TEXT, &tIndex) && 
        	(findObjectInSlide(sSlide, MEA_MEDIA_GROUP_IMAGE, &iIndex) || findObjectInSlide(sSlide, MEA_MEDIA_GROUP_VIDEO, &iIndex)))
        {
            if (tIndex < iIndex)
            {
                /* Text on top, image at the bottom */
                textRegion->position.cy.value   = 0;
                textRegion->size.cy.value       = 50;
                imageRegion->position.cy.value  = 50;
                imageRegion->size.cy.value      = 50;
            }
            else
            {
                /* Image on top, text at the bottom */
                textRegion->position.cy.value   = 50;
                textRegion->size.cy.value       = 50;
                imageRegion->position.cy.value  = 0;
                imageRegion->size.cy.value      = 50;
            }
            return;
        }
    }
    /* Only one text or image region is displayed on each slide*/
    textRegion->position.cy.value   = 0;
    textRegion->size.cy.value       = 100;
    imageRegion->position.cy.value  = 0;
    imageRegion->size.cy.value      = 100;
} /* setRegions */

/*! \brief Check whether the there are enough information to create/display a SMIL
 *         presentation.
 *
 * \param sInfo The current presentation.
 * \return TRUE if this SMIL presentation can be played, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaIsSmilValid(const MeaSmilInfo *sInfo)
{
    if (NULL != sInfo)
    {
        /* Check that slides and objects exists */
#ifdef WAP_SUPPORT		/* we allow empty slide */
        if (NULL == sInfo->slides)
#else
        if ((NULL == sInfo->slides) || (NULL == sInfo->mediaObjects))
#endif
        {
            return FALSE;
        }
#ifndef WAP_SUPPORT		/* we allow empty slide */
        /* Check that at least one object is present */
        if (NULL == sInfo->slides->objects[0])
        {
            return FALSE;
        }
#endif
        /* This is a valid presentation */
        return TRUE;
    }
    return FALSE;
}

/*!
 * \brief Free a SlsMediaObject
 *
 * \param object The media object to free
 *****************************************************************************/
static void freeSlsMediaObject(SlsMediaObject **object)
{
    MEA_FREE((*object)->region);
    MEA_FREE((*object)->src);
    MEA_FREE(*object);
    *object = NULL;
} /* freeSlsMediaObject */

/*! \brief Gets information about what types of objects that are present on the
 *         current slide.
 *
 * \param sInfo The current presentation.
 * \return A bit-array defining what types of objects that are present on the 
 *         slide. See #MeaMediaGroupType
 *****************************************************************************/
MeaMediaGroupType meaGetSlideObjectDef(const MeaSmilInfo *sInfo)
{
    MeaSmilSlide *sSlide = meaGetCurrentSlide(sInfo);
    MeaMediaGroupType gType = MEA_MEDIA_GROUP_NONE;
    unsigned int i;

    if (NULL != sSlide)
    {
        for (i = 0; i < MEA_MAX_SMIL_OBJS; i++)
        {
            if (NULL == sSlide->objects[i])
            {
                break;
            }
            else
            {
#ifdef __DRM_SUPPORT__
                if (sSlide->objects[i]->object->content.type == MEA_MEDIA_TYPE_DRM_CONTENT)
                //if (sSlide->objects[i]->object->content.type == MEA_MEDIA_TYPE_DRM_MESSAGE)
                {
                    gType |= meaMediaType2ObjType(
                        meaDrm2MediaType((char*)sSlide->objects[i]->object->name));
                }
                else
#endif /* __DRM_SUPPORT__ */
                gType |= meaMediaType2ObjType(
                    sSlide->objects[i]->object->content.type);
            }
        }
    }
    return gType;
}

/*! \brief Inserts a media object into the slide data-structure according to
 *         the order that objects have been inserted previously
 *	
 * \param sInfo The current SMIL presentation 
 * \param sSlide The current slide.
 * \param  item The new media object to insert.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL insertByOrder(MeaSmilInfo *sInfo, MeaSmilSlide *sSlide, 
    MeaMoDataItem *item)
{
    MeaMediaGroupType objType = MEA_MEDIA_GROUP_NONE;
    unsigned int i = 0, ii = 0;
    MeaSmilSlide *currentSlide = NULL;
    MeaObjInfo *textObj = NULL;
    MeaObjInfo *imageObj = NULL;
    MeaObjInfo *videoObj = NULL;
    unsigned int emptySlot = 0;
    MeaObjInfo *objInfo = NULL;

    /* Check if the object type already exists in the current slide */
#ifdef __DRM_SUPPORT__
    if (item->content.type == MEA_MEDIA_TYPE_DRM_CONTENT)
    //if (item->content.type == MEA_MEDIA_TYPE_DRM_MESSAGE)
    {
        objType = meaMediaType2ObjType(meaDrm2MediaType((char*)item->name));
    }
    else
#endif /* __DRM_SUPPORT__ */
    objType = meaMediaType2ObjType(item->content.type);

    if (NULL != (objInfo = findObjectInSlide(sSlide, objType, &i)))
    {
        /* Replace the old object */
        /* No deletion only change the item  reference
        meaDeleteMo(&(sInfo->mediaObjects), sInfo->slides, objInfo->object); */

        /* Set the new object but keep begin/end/color and so on */
        objInfo->object = item;
        return TRUE;
    }

    /* Check if the object can be inserted without checking other slides */
    textObj = findObjectInSlide(sSlide, MEA_MEDIA_GROUP_TEXT, &i);
    imageObj = findObjectInSlide(sSlide, MEA_MEDIA_GROUP_IMAGE, &ii);
    if(imageObj == NULL)
        videoObj = findObjectInSlide(sSlide, MEA_MEDIA_GROUP_VIDEO, &ii);
	
    if ((objType == MEA_MEDIA_GROUP_AUDIO) || 
        ((NULL == textObj) && (MEA_MEDIA_GROUP_IMAGE == objType ||MEA_MEDIA_GROUP_VIDEO == objType)) ||
        ((NULL == imageObj && NULL == videoObj) && (MEA_MEDIA_GROUP_TEXT == objType)))
    {
        if (!findEmptyObjectSlot(sSlide, &emptySlot))
        {
            return FALSE;
        }
        /* Set the new object */
        MEA_CALLOC(objInfo, sizeof(MeaObjInfo));
        initObjInfo(objInfo, item,sInfo->fgColorDefault);
        sSlide->objects[emptySlot] = objInfo;
        return TRUE;
    }

    /* A new item needs to be added to the list, check other slides so that text and image are inserted in the same order */
    for (currentSlide = sInfo->slides; currentSlide != NULL; currentSlide = currentSlide->next)
    {
        if ((NULL != (textObj = findObjectInSlide(currentSlide, MEA_MEDIA_GROUP_TEXT, &i))) && 
            ((NULL != (imageObj = findObjectInSlide(currentSlide, MEA_MEDIA_GROUP_IMAGE, &ii))) ||
            (NULL != (videoObj = findObjectInSlide(currentSlide, MEA_MEDIA_GROUP_VIDEO, &ii)))))
        {
            /* This slide has one image and on text object, use this order: ii is for the new object */
            if (MEA_MEDIA_GROUP_TEXT == objType)
            {
                MEA_SWAP(i, ii);  /* Swap i and ii */
            }

            if (i < ii)  /* Append new object */
            {
                if (!findEmptyObjectSlot(sSlide, &emptySlot))
                {
                    return FALSE;
                }
                MEA_CALLOC(objInfo, sizeof(MeaObjInfo));
                initObjInfo(objInfo, item,sInfo->fgColorDefault);
                sSlide->objects[emptySlot] = objInfo;
            }
            else  /* Insert new object to proper position: Replace with new and append old */
            {
                if(objType == MEA_MEDIA_GROUP_TEXT)
                {
                    if (NULL == findObjectInSlide(sSlide, MEA_MEDIA_GROUP_IMAGE, &i) && NULL == findObjectInSlide(sSlide, MEA_MEDIA_GROUP_VIDEO, &i))
                    {
                        return FALSE;
                    }
                }
                else
                {
                    if (NULL == findObjectInSlide(sSlide, MEA_MEDIA_GROUP_TEXT, &i))
                    {
                        return FALSE;
                    }
                }

                if (!findEmptyObjectSlot(sSlide, &emptySlot))
                {
                    return FALSE;
                }
                /* Append old */
                sSlide->objects[emptySlot] = sSlide->objects[i];
                MEA_CALLOC(objInfo, sizeof(MeaObjInfo));
                initObjInfo(objInfo, item,sInfo->fgColorDefault);
                /* Replace */
                sSlide->objects[i] = objInfo;
            }
            return TRUE;
        }
    }
    /* It does not matter where the object is inserted, insert at the end */
    if (!findEmptyObjectSlot(sSlide, &emptySlot))
    {
        return FALSE;
    }
    /* Set the new object */
    MEA_CALLOC(objInfo, sizeof(MeaObjInfo));
    initObjInfo(objInfo, item,sInfo->fgColorDefault);
    sSlide->objects[emptySlot] = objInfo;
    return TRUE;
}

/*! \brief Finds a specific media object in a slide.
 *	
 * \param sSlide  The slide to check to find the specified object in.
 * \param objType The type of object to look for.
 * \param index   The index of the object.
 * \return A reference to the media object or NULL.
 *****************************************************************************/
static MeaObjInfo *findObjectInSlide(const MeaSmilSlide *sSlide, 
    MeaMediaGroupType objType, unsigned int *index)
{
    unsigned int i;
    for (i = 0; i < MEA_MAX_SMIL_OBJS; i++)
    {
#ifdef __DRM_SUPPORT__
        if ((NULL != sSlide->objects[i]) && 
            ((sSlide->objects[i]->object->content.type == MEA_MEDIA_TYPE_DRM_CONTENT) && 
            //((sSlide->objects[i]->object->content.type == MEA_MEDIA_TYPE_DRM_MESSAGE) && 
            (objType == meaMediaType2ObjType(meaDrm2MediaType((char*)sSlide->objects[i]->object->name)))))
        {
            *index = i;
            return sSlide->objects[i];
        }
#endif /* __DRM_SUPPORT__ */
        if ((NULL != sSlide->objects[i]) && (objType == 
            meaMediaType2ObjType(sSlide->objects[i]->object->content.type)))
        {
            *index = i;
            return sSlide->objects[i];
        }
    }
    return NULL;
}

/*! \brief Finds the first empty position to insert a media object
 *	
 * \param slide The current slide.
 * \param index The index of the empty slot is returned here.
 * \return TRUE if an empty slot was found, otherwise FASLE.
 *****************************************************************************/
static MSF_BOOL findEmptyObjectSlot(const MeaSmilSlide *slide, 
    unsigned int *index)
{
    unsigned int i;
    for (i = 0; i < MEA_MAX_SMIL_OBJS; i++)
    {
        if (NULL == slide->objects[i])
        {
            *index = i;
            return TRUE;
        }
    }
    return FALSE;
}

