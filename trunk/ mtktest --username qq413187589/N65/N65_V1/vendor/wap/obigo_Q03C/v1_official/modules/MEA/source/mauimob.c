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

/* !\file mauimob.c
 *  \brief Media object browser UI logic
 */

/* MSF */
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_wid.h"
#include "msf_mem.h"

/* MMS */
#include "mms_cfg.h"
#include "mms_def.h"

/* SLS */
#include "sls_cfg.h"
#include "sls_if.h"

/* MEA */
#include "mea_rc.h"
#include "mea_cfg.h"
#include "matypes.h"
#include "maintsig.h"
#include "mamem.h"
#include "mautils.h"
#include "mauicmn.h"
#include "mauisig.h"
#include "mamob.h"
#include "mtr.h"
#include "mauimob.h"
#ifdef WIDGET_SLIDING_SMIL_VBAR
#include "mtr_rend.h"
#endif

#ifdef WAP_SUPPORT
#include "mamv.h"   //for meaMMCGetCurrentActiveMsg
#endif /* WAP_SUPPORT */
#ifdef MMS_SLIM_MEM
#include "msig.h"     //for fldmgr.h
#include "fldmgr.h"   //for MMS_FOLDER
#include "mltypes.h"  //for MmsMessage
#include "mlfetch.h"  //for getDataStart
#include "maasync.h"  //for meaAsyncOperationStop
#endif /* MMS_SLIM_MEM */

#if defined(WAP_SUPPORT) || defined(__DRM_SUPPORT__)
#include "widget_extension.h" //for arrow key and disable broder
#include "msf_file.h"         //for MSF_FILE_SET_RDONLY
#include "msf_core.h"
#endif /* defined(WAP_SUPPORT) || defined(__DRM_SUPPORT__) */
#ifdef WIDGET_VIRTUAL_FILE_SUPPORT
#include "widget.h"		//for virtual file definition
#include "wapadp.h"	//for HDIa_fileGenVirtualFileName
#endif
#ifdef __DRM_SUPPORT__
#include "mauise.h"
#include "fs_type.h"       //for drm_def.h
#include "../../drm/include/drm_def.h" //for DRM_METHOD_FORWARD_LOCK
#include "../../drm/include/drm_gprot.h" 
#include "../../drm/include/drm_main.h"
#endif /* __DRM_SUPPORT__ */

/******************************************************************************
 * Data-structures
 *****************************************************************************/

#ifndef MMS_SLIM_MEM /* move this enum to mauimob.h*/
/*! \enum MeaUiMobEntryType
 * Identifies the menu entry as a media object or a special operation */
typedef enum
{
    MEA_MOB_SOP,                    /*!< Entry is special operation */
    MEA_MOB_MO                      /*!< Entry is media object */
}MeaUiMobEntryType;
#endif /* MMS_SLIM_MEM */

/*! \struct MeaUiMobSpecialOp
 * Data-structure for storing the table of menu selections for special 
   operations */
typedef struct
{
    MeaMobSpecialOp op;             /*!< special operation */
    MSF_UINT32 string;              /*!< predefined string id */
}MeaUiMobSpecialOp;


/*! \struct MeaUiMobEntry
 * Data-structure for storing widget/gadget info for each list entry
 */
typedef struct 
{
    MeaUiMobEntryType   type;           /*!< entry type: object or special op*/
    MeaMediaGroupType   mediaGroup;     /*!< for media objects: type of mo */
    MeaMobSpecialOp     op;             /*!< for special ops: op type */
    MSF_UINT32          widgetHandle;   /*!< widget handle */
    int                 mtrInstance;    /*!< mtr instance */
    MsfGadgetHandle     gadgetHandle;   /*!< gadget handle */
    MsfSize             size;           /*!< Size of gadget after addition */
}MeaUiMobEntry;

/*! \struct MeaUiMobWindow
 * Data-structure for storing widgets and gadgets
 */
typedef struct
{
    int noOfHandles;                /*!< number of handles on page */
    MeaUiMobEntry handles[MEA_MAX_NUMBER_OF_MO_ON_PAGE+MEA_MOB_SOP_COUNT]; /*!<
                                         list of widget/gadget handles */
    MsfWindowHandle winHandle;      /*!< the handle for the form */
    MsfSize displaySize;            /*!< the size of the display */

    MsfActionHandle actionOk;
    MsfActionHandle actionStop;
    MsfActionHandle actionBack;
    MsfSoundHandle audioHandle;
    MSF_BOOL isPlaying;    /* Video play status */
}MeaUiMobWindow;

#if defined(MEA_GET_MIXED_TEXT_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
typedef struct
{
    char* text;
    char* textBuffer;
    char* tPos;
    MsfStringHandle stringHandle;
    int textLen;
    int totalHeight;
    int onelineHeight;
    MsfSize maxSize;
    int index;
    int strPos;
    char* newStringStart;
    int tmpRN;
    char* rnPos;
    int lenOfRN;
    MSF_BOOL hasNormalChar;
}MeaUiMobGetTextHeightInstance;

static MeaUiMobGetTextHeightInstance *uiMobGetTextHeightInst = NULL;
#endif

/******************************************************************************
 * Constants
 *****************************************************************************/

static const MeaUiMobSpecialOp mobSpecialOps[] =
{
    /* Select next page */
    MEA_MOB_SOP_NEXT_PAGE, (MSF_UINT32)MEA_STR_ID_NEXT_SLIDE, 

    /* Select previous page */
    MEA_MOB_SOP_PREV_PAGE, (MSF_UINT32)MEA_STR_ID_PREVIOUS_SLIDE,

    /* Add media object */
    MEA_MOB_SOP_ADD_MO, (MSF_UINT32)MEA_STR_ID_ADD_MEDIA_OBJECT,

    /* End of list */
    MEA_MOB_SOP_NO_OP, 0
};

#define MEA_MOB_MO_DISTANCE     (2)     /*!< Object distance in pixels */
#define MEA_MOB_MARKER_SIZE     (8)    /*!< Selected object extra size */
#ifndef WAP_SUPPORT
#define MEA_MOB_MAX_MO_HEIGHT   (64)    /*!< Max height of a media object 
                                          before it is scaled */
#endif /* WAP_SUPPORT */
#define MEA_MOB_TEXT_HEIGHT     (16)    /*!< Height of text widget */
#define MEA_MOB_TEXTBOX_HEIGHT  (16)    /*!< Height of textbox widget */
#define MEA_MOB_OP_DISTANCE     (5)     /*!< The space between media objects 
                                             and special operations */

/******************************************************************************
 * Variables
 *****************************************************************************/

static MeaUiMobWindow *meaUiMobWindow = NULL;   /*!< Data related to the Mob window */
#ifndef __UNIFIED_MSG_SUPPORT__
static MsfWindowHandle meaUiMobTextView = 0;
#endif

/******************************************************************************
 * Prototypes
 *****************************************************************************/

#ifndef MMS_SLIM_MEM //remove static and move to .h
static void addWidget(MSF_UINT32 handle, int mtrInstance, 
    MeaUiMobEntryType type, MeaMediaGroupType group, MeaMobSpecialOp sop);
#endif /* ~MMS_SLIM_MEM */
static MSF_UINT32 *getWidgetHandle(int index);
static int *getWidgetInstance(int index);
static int getWidgetIndex(MeaMediaGroupType type, MSF_UINT32 handle, int inst);
static MsfGadgetHandle *getGadget(int index);
static MeaMediaGroupType *getMediaGroup(int index);
static MeaUiMobEntryType *getEntryType(int index);
static MeaMobSpecialOp *getSpecialOp(int index);
static void setGadget(int index, MsfGadgetHandle gadget);
static void rescale(MsfSize *size);
static MSF_BOOL meaUiMobCreateTextBox(const char *text);
static MSF_BOOL addImageGadget(int index, MsfSize *size, MsfPosition *pos,
    MSF_BOOL useNotif);
static MSF_BOOL addTextGadget(int index, MsfSize *size, MsfPosition *pos);
static void textBoxLostFocus(MsfWindowHandle winHandle);
static void textBoxKeyPressUp(MsfWindowHandle winHandle);
static void textBoxKeyPressDown(MsfWindowHandle winHandle);
static void textBoxGotFocus(MsfWindowHandle winHandle);
static MSF_BOOL addTextBoxGadget(int index, MsfSize *size, MsfPosition *pos);

#ifdef WIDGET_SLIDING_SMIL_VBAR
static MSF_INT16 centerXPos(const MsfSize *size, MSF_BOOL forText);
#else
static MSF_INT16 centerXPos(const MsfSize *size);
#endif

static void setWidgetSize(int i, MsfSize *size);
static MSF_BOOL meaUiMobAddGadgets(void);

#if defined(WIDGET_SLIDING_SMIL_VBAR) && defined(__MMI_TOUCH_SCREEN__)
static void meaScrollNotif(void);
#endif

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Add a widget handle to the list of widgets
 * \param handle    The handle of the widget
 * \param mtrInstance The instance for a mtr textbox
 * \param type      If handle is a media object or a special operation
 * \param group     Media group type (image/text etc), if type = MEA_MOB_MO
 * \param sop       Special operation, if type = MEA_MOB_SOP
 *****************************************************************************/
#ifndef MMS_SLIM_MEM
static 
#endif /* MMS_SLIM_MEM */
void addWidget(MSF_UINT32 handle, int mtrInstance, 
    MeaUiMobEntryType type, MeaMediaGroupType group, MeaMobSpecialOp sop)
{
    memset(&meaUiMobWindow->handles[meaUiMobWindow->noOfHandles], 0, sizeof(MeaUiMobEntry));
    meaUiMobWindow->handles[meaUiMobWindow->noOfHandles].type = type;
    switch (type)
    {
    case MEA_MOB_MO:
        {
            meaUiMobWindow->handles[meaUiMobWindow->noOfHandles].mediaGroup = group;
            if (MEA_MEDIA_GROUP_TEXT == group)
            {
                meaUiMobWindow->handles[meaUiMobWindow->noOfHandles].mtrInstance = mtrInstance;
            }
            else
            {
                meaUiMobWindow->handles[meaUiMobWindow->noOfHandles].widgetHandle = handle;
            }
            break;
        }
        
        case MEA_MOB_SOP:
        {
            meaUiMobWindow->handles[meaUiMobWindow->noOfHandles].widgetHandle = handle;
            meaUiMobWindow->handles[meaUiMobWindow->noOfHandles].op = sop;
            break;
        }
    }
    meaUiMobWindow->noOfHandles++;
}

/*!
 * \brief Get a widget handle in the list
 * \param index The position in list
 * \return The widget handle at this position
 *****************************************************************************/
static MSF_UINT32 *getWidgetHandle(int index)
{
    return &meaUiMobWindow->handles[index].widgetHandle;
} 

/*!
 * \brief Get an instance in the list
 * \param index The position in list
 * \return The instance at this position
 *****************************************************************************/
static int *getWidgetInstance(int index)
{
    return &meaUiMobWindow->handles[index].mtrInstance;
} 

/*!
 * \brief Returns selected link in a textbox, if a link in a textbox is 
 *        selected.
 * 
 * \param index The index of the widget to investigate for links
 * \return Link data or NULL if none found
 *****************************************************************************/
MtrLinkEntry *meaUiMobGetLink(int index)
{
    MtrLinkEntry *link;    

    if ((MEA_MEDIA_GROUP_TEXT == meaUiMobWindow->handles[index].mediaGroup) &&
        (mtrHasActiveLink(
        (int)meaUiMobWindow->handles[index].mtrInstance , &link)))
    {
        return link;
    }
    else
    {
        return NULL;
    } /* if */
} /* meaUiMobGetLink */


/*!
 * \brief Get a widget's position in the list
 * \param type   the type of widget
 * \param handle the handle to look for (for text/image widgets)
 * \param inst   the instance to look for (for mtr textboxes)
 * \return The position for the widget handle/mtr instance
 *****************************************************************************/
static int getWidgetIndex(MeaMediaGroupType type, MSF_UINT32 handle, int inst)
{
    int i;

    for (i = 0; i < meaUiMobWindow->noOfHandles; i++)
    {
        if (type == meaUiMobWindow->handles[i].mediaGroup)
        {
            if (type == MEA_MEDIA_GROUP_TEXT &&
                inst == meaUiMobWindow->handles[i].mtrInstance ||
                type != MEA_MEDIA_GROUP_TEXT &&
                handle == meaUiMobWindow->handles[i].widgetHandle)
            {
                return i;           
            } /* if */
        }
    } /* for */
    return -1;
}

/*!
 * \brief Get a gadget handle in the list
 * \param index The position in list
 * \return The gadget handle at this position
 *****************************************************************************/
static MsfGadgetHandle *getGadget(int index)
{
    return &meaUiMobWindow->handles[index].gadgetHandle;
}

/*!
 * \brief Get a media group type of a widget in the list
 * \param index The position in list
 * \return The media group type of the widget at this position
 *****************************************************************************/
static MeaMediaGroupType *getMediaGroup(int index)
{
    return &meaUiMobWindow->handles[index].mediaGroup;
}

/*!
 * \brief Get a entry type of a widget in the list
 * \param index The position in list
 * \return The entry type, i.e. media object or special operation
 *****************************************************************************/
static MeaUiMobEntryType *getEntryType(int index)
{
    return &meaUiMobWindow->handles[index].type;
}

/*!
 * \brief Get the special op of a widget in the list
 * \param index The position in list
 * \return The special operation of the widget at this position
 *****************************************************************************/
static MeaMobSpecialOp *getSpecialOp(int index)
{
    return &meaUiMobWindow->handles[index].op;
}

/*!
 * \brief Set gadget handle for a widget in the list
 * \param index  Position in list
 * \param gadget The gadget handle to set
*****************************************************************************/
static void setGadget(int index, MsfGadgetHandle gadget)
{
    meaUiMobWindow->handles[index].gadgetHandle = gadget;
}

/*!
 * \brief Rescale size to fit defined limitation
 * \param size In/out size data
 *****************************************************************************/
static void rescale(MsfSize *size)
{
    if (size->width + MEA_MOB_MARKER_SIZE > meaUiMobWindow->displaySize.width)
    {
        size->height = (MSF_INT16)((size->height * 
            (meaUiMobWindow->displaySize.width - MEA_MOB_MARKER_SIZE)) / size->width);
        size->width = (MSF_INT16)(meaUiMobWindow->displaySize.width - MEA_MOB_MARKER_SIZE);
    }
#ifdef WAP_SUPPORT
    if (size->height + MEA_MOB_MARKER_SIZE > meaUiMobWindow->displaySize.height)
    {
        size->width = (MSF_INT16)((size->width * 
            meaUiMobWindow->displaySize.height) / size->height);
        size->height = meaUiMobWindow->displaySize.height;
    }
#else
    if (size->height + MEA_MOB_MARKER_SIZE > MEA_MOB_MAX_MO_HEIGHT)
    {
        size->width = (MSF_INT16)((size->width * 
            MEA_MOB_MAX_MO_HEIGHT) / size->height);
        size->height = MEA_MOB_MAX_MO_HEIGHT;
    }
#endif /* WAP_SUPPORT */
}

#ifndef __UNIFIED_MSG_SUPPORT__
static void meaUiMobDeleteTextView(ctk_screen_handle scrId)
{
    if (meaUiMobTextView != 0)
    {
        meaDeleteWindow(meaUiMobTextView);
		meaUiMobTextView = 0;
    }
}

/*!
 * \brief Creates an CTK Text View and adds it to the list of widgets
 * \param text The text to display
 *****************************************************************************/
void meaUiMobCreateTextView(MeaMoDataItem * textMo)
{
    ctk_screen_handle scrId;
    kal_uint8 		*text;
    int				textSize = widget_utf8_to_ucs2_length_in_bytes(textMo->data);

    if (0 != meaUiMobTextView)
    {
        meaUiMobDeleteTextView(0);    
    }
	if (textMo->size > 24)
	{
        text = MEA_ALLOC(textSize + 2);
        widget_utf8_to_ucs2_string(text, textSize + 2, (kal_uint8*)textMo->data);
	}
	else
	{
	    textSize = textSize + 4;
        text = MEA_ALLOC(textSize + 2);
        widget_utf8_to_ucs2_string(text, textSize + 2, (kal_uint8*)"\n");
        text = widget_ucs2str_append_utf8(MSF_MODID_MEA, text, &textSize, 
			(kal_uint8*)textMo->data);
	}
	
    /* Create widow */
    meaUiMobTextView = HDIa_widgetExtCreateTextView(MSF_MODID_MEA, text, 
    									(MSF_UINT16)MEA_STR_ID_VIEW, 0);
	MEA_FREE(text);
    meaAddWidgetList(meaUiMobTextView);

    /* Set Key */
    scrId = HDIa_widgetCtkGetScreenHandle(meaUiMobTextView);
    ctk_screen_addRSK_UA(scrId, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, NULL, meaUiMobDeleteTextView, KAL_TRUE);
    ctk_screen_add_key_UA(scrId, KEY_LEFT_ARROW, NULL, meaUiMobDeleteTextView, KAL_TRUE);
	
    meaDisplayWindow(meaUiMobTextView, meaGetPosLeftTop());
}
#endif /* __UNIFIED_MSG_SUPPORT__ */
/*!
 * \brief Creates an MTR textbox widget and adds it to the list of widgets
 * 
 * \param text The text to display
 * \return TRUE on success, otherwise FALSE
 *****************************************************************************/
static MSF_BOOL meaUiMobCreateTextBox(const char *text)
{
    MsfStringHandle             sHandle;     
    MtrCreateRspData            *rspDdata;
    int                         num;
    int                         textLen = 0;
    MtrCreateTextBoxProperties  tProp = 
    {
        {0,0},                          /* size (set below) */
#ifdef WAP_SUPPORT
        MsfLeft,
#else
        MsfCenter,                      /* alignment */
#endif /* WAP_SUPPORT */
        {0xFF, 0xFF, 0xFF},             /* background white */
        {0},                            /* foreground black*/
        MTR_SCHEME_HTTP             | 
        MTR_SCHEME_HTTPS            | 
        MTR_SCHEME_WWW              | 
        MTR_SCHEME_MAIL             | 
        MTR_SCHEME_PHONE,               /* schemes to recognize */
        MTR_PROP_RENDER_LINKS       |
        MTR_PROP_USE_SCROLLBARS     |
        MTR_PROP_VERTICAL_RESIZE    |
        MTR_PROP_HORIZONTAL_RESIZE  /*|
        MTR_PROP_RETURN_LINKS*/         /* flags */
    };

#ifdef WIDGET_SLIDING_SMIL_VBAR
    tProp.size.width = (MSF_INT16)(meaUiMobWindow->displaySize.width - 
        MEA_MOB_MARKER_SIZE - MSF_CFG_SCROLLBAR_WIDTH);
#else /* WIDGET_SLIDING_SMIL_VBAR */
    tProp.size.width = (MSF_INT16)(meaUiMobWindow->displaySize.width - 
        MEA_MOB_MARKER_SIZE);
#endif /* WIDGET_SLIDING_SMIL_VBAR */

    /* Use half of the display size for a text part */
#ifdef WAP_SUPPORT
  #ifdef __MMI_TOUCH_SCREEN__
    /* Scroll arrow */
    {
        HDIa_widgetExtFormSetMOBStyle(meaUiMobWindow->winHandle);
        /*HDIa_widgetExtFormGetMOBSize(meaUiMobWindow->winHandle, 
            &meaUiMobWindow->displaySize);*/
    }

   /* tProp.size.height = (MSF_INT16)meaUiMobWindow->displaySize.height;*/
   tProp.size.height = (MSF_INT16)(meaUiMobWindow->displaySize.height -
        MEA_MOB_MARKER_SIZE);
  #else
    tProp.size.height = (MSF_INT16)(meaUiMobWindow->displaySize.height -
        MEA_MOB_MARKER_SIZE);
  #endif
#else
    tProp.size.height = (MSF_INT16)(meaUiMobWindow->displaySize.height/2); 
#endif /* WAP_SUPPORT */

    if (text)
    {
        textLen = strlen(text);
    }

    /* Create the text to display */
    if (NULL == text || textLen == 0)
    {
        /* The text part is empty, use a empty string instead */
#ifdef WAP_SUPPORT
        char *emptyText = msf_cmmn_strdup(MSF_MODID_MEA, " ");
		if (0 == (sHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
			emptyText, MsfUtf8, textLen + 1, 0)))
		{
			MEA_FREE(emptyText);
			return FALSE; 
		}
		MEA_FREE(emptyText);
    }
    else if (0 == (sHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
        text, MsfUtf8, textLen + 1, 0)))
#else
        text = "";
    }
    if (0 == (sHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
        text, MsfUtf8, textLen + 1, 0)))
#endif /* WAP_SUPPORT */
    {
        return FALSE; 
    }

    if (MSF_WIDGET_STRING_GET_LENGTH(sHandle, 0, MsfUtf8) <= 0) 
    {
        (void)MSF_WIDGET_RELEASE(sHandle);
        sHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, " ", MsfUtf8, strlen(" ") + 1, 0);
    }
    
    /* Create the textbox to display it in, add it to the list of widgets */
    if (MTR_RESULT_OK != mtrCreateTextBox(sHandle, &tProp, &rspDdata))
    {
        (void)MSF_WIDGET_RELEASE(sHandle);
        return FALSE;
    } /* if */

    /* save gadget handle, size, links */
    addWidget(0, rspDdata->instance, MEA_MOB_MO, MEA_MEDIA_GROUP_TEXT,
        MEA_MOB_SOP_NO_OP);
    num = getWidgetIndex(MEA_MEDIA_GROUP_TEXT, 0, rspDdata->instance);
    setGadget(num, rspDdata->gadgetHandle);
    meaUiMobWindow->handles[num].size = rspDdata->gadgetSize;
    meaUiMobWindow->handles[num].widgetHandle = sHandle;
    
    /* Free response data from MTR */
    mtrFreeMtrCreateRspData(&rspDdata);
    return TRUE;
} /* meaUiMobCreateTextBox */

#ifdef __DRM_SUPPORT__
  #ifdef MMS_SLIM_MEM
    #ifdef WIDGET_VIRTUAL_FILE_SUPPORT
MSF_BOOL generateDRMObject(MeaMoDataItem *object)
{
    MmsMsgId msgId = meaMMCGetCurrentActiveMsg();
    MeaMediaGroupType gType = MEA_MEDIA_GROUP_NONE;

    if(object->file->filehandle == 0)
    {
        object->file->filehandle = MSF_FILE_OPEN(MSF_MODID_MEA, object->file->path, MSF_FILE_SET_RDONLY, 0);
    }
    
    if (object->content.type == MEA_MEDIA_TYPE_DRM_MESSAGE)
    {
        object->reshandle = meaCreateDrmVirtualFileResource(MEA_MEDIA_TYPE_DRM_MESSAGE, 
            object->file->path, object->file->pos, object->file->size, msgId, object->file->filehandle, &object->content.drmType);
        MSF_FILE_CLOSE(object->file->filehandle);  /* the file handle is only for virtual file use, we can close it cuz widget has another one  */
        object->file->filehandle = 0;
    }
    else if (object->content.type == MEA_MEDIA_TYPE_DRM_CONTENT)
    {
        object->reshandle = meaCreateDrmVirtualFileResource(MEA_MEDIA_TYPE_DRM_CONTENT, 
            object->file->path, object->file->pos, object->file->size, msgId, object->file->filehandle, &object->content.drmType);
        /* cannot close file handle, cuz widget use MsfResourceDRMFile type */
    }

    gType = meaMediaType2ObjType(object->content.drmType);

    /* Show audio /brkoen icon immediately. No need to wait widget to create resource */
    if (object->reshandle != 0)
    {
        object->isWaitWidgetRead = 1;
        if(gType == MEA_MEDIA_GROUP_AUDIO)
        {
            addWidget(MEA_GET_IMG_ID(MEA_IMG_AUDIO), 0, MEA_MOB_MO, MEA_MEDIA_GROUP_AUDIO, MEA_MOB_SOP_NO_OP);
            meaUiMobWindow->audioHandle = object->reshandle;
        }
    }
    else
    {
        /* The image could not be created, display the "broken" icon instead */
        switch(gType)
        {
        case MEA_MEDIA_GROUP_IMAGE:
            addWidget(MEA_GET_IMG_ID(MEA_IMG_IMAGE_ERROR), 0, MEA_MOB_MO, MEA_MEDIA_GROUP_IMAGE, MEA_MOB_SOP_NO_OP);
            break;
        case MEA_MEDIA_GROUP_VIDEO:
            addWidget(MEA_GET_IMG_ID(MEA_IMG_VIDEO_ERROR), 0, MEA_MOB_MO, MEA_MEDIA_GROUP_IMAGE, MEA_MOB_SOP_NO_OP);
            break;
        case MEA_MEDIA_GROUP_AUDIO:
            addWidget(MEA_GET_IMG_ID(MEA_IMG_AUDIO_ERROR), 0, MEA_MOB_MO, MEA_MEDIA_GROUP_IMAGE, MEA_MOB_SOP_NO_OP);
            break;
        default:
            addWidget(MEA_GET_IMG_ID(MEA_IMG_BROKEN_IMAGE), 0, MEA_MOB_MO, MEA_MEDIA_GROUP_IMAGE, MEA_MOB_SOP_NO_OP);
            break;            
        }
    }
    
    return TRUE;
}
    #else /* WIDGET_VIRTUAL_FILE_SUPPORT */
  
static MSF_BOOL extractDrmObject(MeaMoDataItem *mo, char* tmpFileName)
{
    MSF_INT32 fileHandle;
    MmsMsgId currentMsgId = meaMMCGetCurrentActiveMsg();
   #ifdef __DRM_V01__
    if (mo->content.type == MEA_MEDIA_TYPE_DRM_MESSAGE)
        sprintf(tmpFileName, "%s%lx-%d.dm", MMS_DRM_FOLDER, currentMsgId, meaMobGetMoIndex(mo));
	else
   #else
        sprintf(tmpFileName, "%s%lx-%d.tmp", MMS_DCF_FOLDER, currentMsgId, meaMobGetMoIndex(mo));
   #endif /* ~__DRM_V01__ */
    fileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, tmpFileName, MSF_FILE_SET_RDONLY, 0);
    if (fileHandle >= 0)
    {
        MSF_FILE_CLOSE(fileHandle);
        mo->isWaitWidgetRead = 1;
        if (mo->savename)
		    MEA_CFREE(mo->savename);
	    MEA_CALLOC(mo->savename, strlen(tmpFileName)+1);
	    strcpy(mo->savename, tmpFileName);		
        (void)MEA_SIGNAL_SENDTO_I(MEA_MOB_FSM, MEA_SIG_MOB_COPY_DRM_FINISHED, FALSE);   
        return TRUE;
    }
    else
    {		
        memset(tmpFileName, 0x00, 100);
        if (mo->content.type == MEA_MEDIA_TYPE_DRM_MESSAGE)
            //sprintf(tmpFileName, "/DRM-%d.dm", meaMobGetMoIndex(mo));
            sprintf(tmpFileName, "%s%lx-%d.dm", MMS_DRM_FOLDER, currentMsgId, meaMobGetMoIndex(mo));
        else if (mo->content.type == MEA_MEDIA_TYPE_DRM_CONTENT)
            sprintf(tmpFileName, "%s%lx-%d.dcf", MMS_DCF_FOLDER, currentMsgId, meaMobGetMoIndex(mo));
		if (mo->meaAsioReader)
			meaAsyncOperationStop(&mo->meaAsioReader);
		if (mo->meaAsioWriter)
			meaAsyncOperationStop(&mo->meaAsioWriter);
		if (mo->data)
			MEA_CFREE(mo->data);
		if (mo->file)
		{
			if(mo->file->path)
				MEA_CFREE(mo->file->path);			
			MEA_CFREE(mo->file);
		}
		if (mo->savename)
			MEA_CFREE(mo->savename);

		MEA_CALLOC(mo->file, sizeof(MeaMoFileRef));
		if (!mo->file)
			return FALSE;
		MEA_CALLOC(mo->savename, strlen(tmpFileName)+1);
		if (!mo->savename)
		{
			MEA_CFREE(mo->file);
			return FALSE;
		}
		strcpy(mo->savename, tmpFileName);		
		if (getMixedMoInfo(mo, (int *)&mo->file->pos))
		{
		    mo->file->size = mo->size;
			MEA_CALLOC(mo->file->path, 100);
			sprintf(mo->file->path, "%s%lx.%c", MMS_FOLDER, currentMsgId, fldrGetFileSuffix(currentMsgId));
			if (meaCopyDrmMo(mo->savename, mo->file->path, mo, MEA_MOB_FSM, 
				MEA_SIG_MOB_READ_DRM_MO_RSP, MEA_SIG_MOB_WRITE_DRM_MO_RSP))
			{
				mo->isWaitWidgetRead = 1;
			}
			else
			{
			    MEA_CFREE(mo->file);
			    MEA_CFREE(mo->savename);
			    return FALSE;
			}
		}
		else
		{
			MEA_CFREE(mo->file);
			MEA_CFREE(mo->savename);
			return FALSE;
		}
    }
	return TRUE;
}
    #endif /* WIDGET_VIRTUAL_FILE_SUPPORT */
  #else
static MSF_BOOL extractDrmObject(const MeaMoDataItem *mo, char* tmpFileName)
{
    MSF_INT32  wFileHandle;
    unsigned char * externalFileName;
    MSF_INT32 fileHandle;
    MmsMsgId currentMsgId = meaMMCGetCurrentActiveMsg();
    int openMode = MSF_FILE_SET_WRONLY|MSF_FILE_SET_CREATE|HDI_FILE_SET_CUSTOM_BLOCKING;
    if (mo->content.type == MEA_MEDIA_TYPE_DRM_MESSAGE)
        //sprintf(tmpFileName, "/DRM-%d.dm", meaMobGetMoIndex(mo));
        sprintf(tmpFileName, "%s%lx-%d.dm", MMS_DRM_FOLDER, currentMsgId, meaMobGetMoIndex(mo));
    else if (mo->content.type == MEA_MEDIA_TYPE_DRM_CONTENT)
        sprintf(tmpFileName, "%s%lx-%d.dcf", MMS_DCF_FOLDER, currentMsgId, meaMobGetMoIndex(mo));
    fileHandle=MSF_FILE_OPEN(MSF_MODID_MEA, tmpFileName, MSF_FILE_SET_RDONLY, 0);
    if(fileHandle>=0)
    {
        MSF_FILE_CLOSE(fileHandle);
        return TRUE;
    }
    else
    {		
        wFileHandle = MSF_FILE_OPEN(MSF_MODID_MEA, tmpFileName, openMode, (MSF_INT32)mo->size);
        if (wFileHandle >= 0)
        {
            if (MSF_FILE_WRITE(wFileHandle, mo->data, (MSF_INT32)mo->size) != (MSF_INT32)mo->size)
            {
                //MEA_FREE(mo->data); //can't free constant
                //mo->data = NULL;
                MSF_FILE_CLOSE(wFileHandle);
                return FALSE;
            }
            MSF_FILE_CLOSE(wFileHandle);                               
        }
        externalFileName = HDI_FileNameTranslate(tmpFileName);
        if (mo->content.type == MEA_MEDIA_TYPE_DRM_MESSAGE)
        {
            DRM_process_file((kal_uint8*)"application/vnd.oma.drm.message", (kal_wchar*)externalFileName, TRUE);
        }
        else if (mo->content.type == MEA_MEDIA_TYPE_DRM_CONTENT)
        {
            //char mimeType[] = "application/vnd.oma.drm.content";
            DRM_process_file((kal_uint8*)"application/vnd.oma.drm.content", (kal_wchar*)externalFileName, TRUE);
        }
        else
        {
            HDI_FileNameFree(externalFileName);
            return FALSE;
        }
        HDI_FileNameFree(externalFileName);
    }
	return TRUE;
}
  #endif /* __MMS_SLIM_MEM */

MSF_BOOL displayDrm(MSF_INT32 fileHandle, MeaMediaType mediaType)
{
    switch (meaMediaType2ObjType(mediaType))
    {
        case MEA_MEDIA_GROUP_IMAGE:
        {
            MsfImageHandle imgHandle = createDrmImageHandle(fileHandle, mediaType);

            if (0 == imgHandle)
            {
                /* The image could not be created, display the "broken" icon instead */
                imgHandle = MEA_GET_IMG_ID(MEA_IMG_IMAGE_ERROR);
            }
            addWidget(imgHandle, 0, MEA_MOB_MO, MEA_MEDIA_GROUP_IMAGE, MEA_MOB_SOP_NO_OP);
            return TRUE;
        }
        case MEA_MEDIA_GROUP_AUDIO:
            addWidget(MEA_GET_IMG_ID(MEA_IMG_AUDIO), 0, MEA_MOB_MO, MEA_MEDIA_GROUP_AUDIO, MEA_MOB_SOP_NO_OP);
            return TRUE;
        case MEA_MEDIA_GROUP_TEXT:
            /* Verify the character set */
            break;
        default:
            return FALSE;
    }
    return TRUE;
}
#endif /* __DRM_SUPPORT__ */

/*!
 * \brief Start playing audio
 * \return
 *****************************************************************************/
void meaUiMobPlayAudio()
{
    if(meaUiMobWindow->audioHandle > 0)
        (void)HDIa_widgetSoundPlay(meaUiMobWindow->audioHandle);
}

/*!
 * \brief Start playing video
 * \return
 *****************************************************************************/
static void meaUiMobPlayVideo(MsfVideoHandle handle)
{
    if(handle > 0)
    {
        MSF_UINT32 duration = 0;
        MSF_WIDGET_EXT_ENABLE_VIDEO_PLAY(handle);
        duration = (MSF_UINT32) MSF_WIDGET_EXT_GET_VIDEO_DURATION_TIME(handle) / 100 ;  /* msec -> 0.1 sec */
        meaUiMobWindow->isPlaying = TRUE;
        MSF_TIMER_SET (MSF_MODID_MEA, MEA_MOB_TIMER_ID, duration);  /* Set timer so that we know when it ends */
        MSF_WIDGET_EXT_PLAY_VIDEO(handle);
    }
}

/*!
 * \brief Stop playing audio
 * \return
 *****************************************************************************/
void meaUiMobStopAudio()
{
    if(meaUiMobWindow->audioHandle > 0)
        (void)MSF_WIDGET_SOUND_STOP(meaUiMobWindow->audioHandle);
}

/*!
 * \brief Stop playing video
 * \return
 *****************************************************************************/
static void meaUiMobStopVideo(MsfVideoHandle handle)
{
    if(handle > 0)
    {
        MSF_TIMER_RESET(MSF_MODID_MEA, MEA_MOB_TIMER_ID);
        MSF_WIDGET_EXT_STOP_VIDEO(handle);
        meaUiMobWindow->isPlaying = FALSE;
    }
}

MSF_BOOL getMixedMoInfo(const MeaMoDataItem *mo, int *startPos)
{
	MmsMessage virtualMsgHandle;
	MSF_INT32 filehandle;
	static char filepath[100];
	MSF_INT8* infoBuffer;
	MSF_INT32 bytesInfoBuf=0;
	MSF_INT32 totalFileSize=0;
	MSF_BOOL result=FALSE;
	MmsMsgId msgId = meaMMCGetCurrentActiveMsg();

	memset(filepath,0x00,100);
	sprintf(filepath, "%s%lx.i", MMS_FOLDER, msgId);
	bytesInfoBuf=MSF_FILE_GETSIZE(filepath);
	
	/* Check if mms message size and its information file size are valid */
	if ( bytesInfoBuf<=0||(infoBuffer = (MSF_INT8 *)MEA_ALLOC(bytesInfoBuf)) == NULL)			
	{
		return FALSE;		
	}			
	/* Read data of information file into infoBuffer*/
	filehandle=MSF_FILE_OPEN(MSF_MODID_MMS,filepath,MSF_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING,0);
	if(filehandle<0||(MSF_FILE_READ(filehandle, infoBuffer, bytesInfoBuf) != bytesInfoBuf))
	{
		goto exit;
	}		
	MSF_FILE_CLOSE(filehandle);
	
	virtualMsgHandle.infoHandle.buffer = (MSF_UINT8*)infoBuffer;
	virtualMsgHandle.infoHandle.bufferSize = bytesInfoBuf;
	*startPos=getDataStart(mo->bpIndex,&virtualMsgHandle);
	//*datasize=getDataSize(mo->bpIndex,&virtualMsgHandle);

	memset(filepath,0x00,100);
	sprintf(filepath,"%s%lx.%c",MMS_FOLDER, msgId,fldrGetFileSuffix(msgId));
	totalFileSize=MSF_FILE_GETSIZE(filepath);
	
	if(totalFileSize<=0)
	{
		goto exit;
	}

	//if(*startpos+*datasize>totalFileSize)
	if (*startPos > totalFileSize)
	{
		goto exit;
	}
	result=TRUE;
exit:
		MEA_FREE(infoBuffer);
		if(filehandle>=0)
			MSF_FILE_CLOSE(filehandle);
		return result;
}

/*!
 * \brief Add text/image media object to page
 * \param mo   the media object to add 
 * \return TRUE on success
 *****************************************************************************/
MSF_BOOL meaUiMobAddWidget(MeaMoDataItem *mo)
{   
    MeaMediaGroupType gType = MEA_MEDIA_GROUP_NONE;

    if(mo == NULL)
    {
        return FALSE;
    }

    /* prevent list overrun */
    if (meaUiMobWindow->noOfHandles >= MEA_MAX_NUMBER_OF_MO_ON_PAGE+MEA_MOB_SOP_COUNT)
    {
        return FALSE;
    }

    if(mo->reshandle != 0) /* need to load resource everytime, cuz audio icon is created when resource is loaded */
    {
        MSF_WIDGET_RELEASE(mo->reshandle);
        mo->reshandle = 0;
    }

    gType = meaMediaType2ObjType(mo->content.type);
    switch (gType)
    {
    case MEA_MEDIA_GROUP_IMAGE:
    case MEA_MEDIA_GROUP_AUDIO:    /* Create two handles, one for audio, one for image icon */
    case MEA_MEDIA_GROUP_VIDEO:
        if (mo->size == 0)
        {
            switch (gType)
            {
            case MEA_MEDIA_GROUP_IMAGE:
                addWidget(MEA_GET_IMG_ID(MEA_IMG_IMAGE_ERROR), 0, MEA_MOB_MO, gType, MEA_MOB_SOP_NO_OP);
                return TRUE;
            case MEA_MEDIA_GROUP_AUDIO:
                addWidget(MEA_GET_IMG_ID(MEA_IMG_AUDIO_ERROR), 0, MEA_MOB_MO, gType, MEA_MOB_SOP_NO_OP);
                return TRUE;
            case MEA_MEDIA_GROUP_VIDEO:
                addWidget(MEA_GET_IMG_ID(MEA_IMG_VIDEO_ERROR), 0, MEA_MOB_MO, gType, MEA_MOB_SOP_NO_OP);
                return TRUE;
            }
        }

        HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);

        if (mo->reshandle == 0)
        {
            mo->reshandle = meaCreateVirtualFileResource(mo->content.type, mo->file->path, mo->file->pos, mo->file->size);
            if(mo->reshandle != 0)
            {
                if(gType == MEA_MEDIA_GROUP_AUDIO)
                {
                    meaUiMobWindow->audioHandle = mo->reshandle;
                }
                mo->isWaitWidgetRead=1;
                return TRUE;
            }
            else
            {
                switch (gType)
                {
                case MEA_MEDIA_GROUP_IMAGE:
                    addWidget(MEA_GET_IMG_ID(MEA_IMG_IMAGE_ERROR), 0, MEA_MOB_MO, gType, MEA_MOB_SOP_NO_OP);
                    return TRUE;
                case MEA_MEDIA_GROUP_AUDIO:
                    addWidget(MEA_GET_IMG_ID(MEA_IMG_AUDIO_ERROR), 0, MEA_MOB_MO, gType, MEA_MOB_SOP_NO_OP);
                    return TRUE;
                case MEA_MEDIA_GROUP_VIDEO:
                    addWidget(MEA_GET_IMG_ID(MEA_IMG_VIDEO_ERROR), 0, MEA_MOB_MO, gType, MEA_MOB_SOP_NO_OP);
                    return TRUE;
                }
            }
        }
        return TRUE;

    case MEA_MEDIA_GROUP_TEXT:
        {
#if defined(MEA_GET_MIXED_TEXT_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)

            int textLen = 0;
            char* text = (char *)mo->data;
            MSF_BOOL trunc = FALSE;

            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAUIMOB_64A30B656396543354E1A5FF33A561AB, "[TEXT HEIGHT] MEA_MEDIA_GROUP_TEXT\n"));
            
            if (text)
            {
                textLen = strlen(text);

                if (textLen == 0)
                {
                    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                        MAUIMOB_D894297AA051328737C9049E4F57D98B, "[TEXT HEIGHT] empty text, \n"));
                    meaUiMobSetTotalTextHeightValue();
                    return meaUiMobCreateTextBox(text);
                }
                else if (textLen > MEA_CFG_MIXED_TEXT_MAX_SIZE - 1)
                {
                    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                        MAUIMOB_AF06E9F116DC4ECD92E373BAEF94916A, "[TEXT HEIGHT] too long the string\n"));
                    textLen = MEA_CFG_MIXED_TEXT_MAX_SIZE - 1;             
                    *(text + textLen) = 0;
                    trunc = TRUE;
                }
            }
            else
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAUIMOB_14B63088D17380BD20CA2A210CEE6F66, "[TEXT HEIGHT] no text\n"));
                meaUiMobSetTotalTextHeightValue();
                return meaUiMobCreateTextBox(text);
            }

            HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);
            
            MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAUIMOB_D8806C61755D993BDF3E6FF4AECD5782, "[TEXT HEIGHT] send MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT\n"));
            
            mo->isWaitWidgetRead=1;

            (void)MEA_SIGNAL_SENDTO_I(MEA_MOB_FSM, 
                MEA_SIG_MOB_GET_TEXT_TOTAL_HEIGHT, trunc);
            
            return TRUE;

#else
            int textLen = 0;
            char* text = (char *)mo->data;

            if (text)
            {
                textLen = strlen(text);

                if (textLen > MEA_CFG_MIXED_TEXT_MAX_SIZE - 1)
                {
                    textLen = MEA_CFG_MIXED_TEXT_MAX_SIZE - 1;
                
                    *(text + textLen) = 0;
                }
            }
            return meaUiMobCreateTextBox(text);

#endif
        }       
#ifdef __DRM_SUPPORT__
    case MEA_MEDIA_GROUP_DRM:
    {
        static char fileName[100];
        memset(fileName, 0x00, 100);
        if (mo->size == 0)
        {
            addWidget(MEA_GET_IMG_ID(MEA_IMG_BROKEN_IMAGE), 0, MEA_MOB_MO, MEA_MEDIA_GROUP_IMAGE, MEA_MOB_SOP_NO_OP);
            return TRUE;
        }

        HDIa_widgetExtDisplayTransitionAnimation(KAL_TRUE);

  #ifdef WIDGET_VIRTUAL_FILE_SUPPORT
        if (mo->reshandle == 0)
        {
            return generateDRMObject(mo);
        }
        else
        {
            addWidget(mo->reshandle, 0, MEA_MOB_MO, MEA_MEDIA_GROUP_IMAGE, MEA_MOB_SOP_NO_OP);
            return TRUE;
        }
  #else
		if (mo->reshandle == 0)
		{
            if (extractDrmObject(mo, fileName))
            {
                mo->isWaitWidgetRead = 1;
				return TRUE;
            }
			else
			{
			    return FALSE;
			}
		}
		else
		{
            addWidget(mo->reshandle, 0, MEA_MOB_MO, MEA_MEDIA_GROUP_IMAGE, 
                MEA_MOB_SOP_NO_OP);
            return TRUE;
		}
  #endif
    }
#endif /* __DRM_SUPPORT__ */
    case MEA_MEDIA_GROUP_NONE:
    default:
        /* This is unknown data or an empty Multipart message. Don't show the "broken image" if it's empty, just an empty page */
        if (mo->size > 1)
        {
            addWidget(MEA_GET_IMG_ID(MEA_IMG_BROKEN_IMAGE), 0, MEA_MOB_MO, MEA_MEDIA_GROUP_IMAGE, MEA_MOB_SOP_NO_OP);
        }
        return TRUE;
    }
}

#if defined(MEA_GET_MIXED_TEXT_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)

MSF_BOOL meaUiMobAddTextWidget(MeaMoDataItem *mo)
{
    int textLen = 0;
    char* text = (char *)mo->data;

    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_488D1BADEA91BEE508CF93482358EB6E, "[TEXT HEIGHT] meaUiMobAddTextWidget\n"));
    
    if(mo == NULL)
    {
        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_113C053798D29CF80F3C6DD4A72AB47D, "[TEXT HEIGHT] no mo\n"));
        return FALSE;
    }
    
    if (text)
    {
        textLen = strlen(text);

        if (textLen > MEA_CFG_MIXED_TEXT_MAX_SIZE - 1)
        {
            textLen = MEA_CFG_MIXED_TEXT_MAX_SIZE - 1;
               
            *(text + textLen) = 0;
        }
    }
    return meaUiMobCreateTextBox(text);
}
#endif

/*!
 * \brief Add menu choice for a special operation to list
 * \param op  the special operation to add
 * \return TRUE on successful operation
 *****************************************************************************/
MSF_BOOL meaUiMobAddSpecialOp(MeaMobSpecialOp op)
{
    int i;
    char *str;
    MsfStringHandle handle; 

    /* find special op in table and create widget accordingly */
    for (i = 0; i < MEA_MOB_SOP_COUNT; i++)
    {
        if (mobSpecialOps[i].op == op)
        {
            if (NULL == (str = meaGetStringFromHandle(MEA_GET_STR_ID(
                mobSpecialOps[i].string))))
            {
                return FALSE;
            }

            handle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, str, MsfUtf8, 
                (int)strlen(str) + 1, 0);
            /*lint -e{774} */
            MEA_FREE(str);

            if (0 == handle)
            {
                return FALSE;
            }

            addWidget(handle, 0, MEA_MOB_SOP, MEA_MEDIA_GROUP_NONE,
                mobSpecialOps[i].op);
           
            return TRUE;
        }
    }

    /* none found */
    return FALSE;
}

/*!
 * \brief Create and add new image gadget
 * \param index Widget number in list
 * \param size  Struct containing size information
 * \param pos   Struct containing position information
 * \param useNotif Register notification changes for this gadget
 * \return TRUE on successful operation
 *****************************************************************************/
static MSF_BOOL addImageGadget(int index, MsfSize *size, MsfPosition *pos,
    MSF_BOOL useNotif)
{
    MsfGadgetHandle handle;

    if (NULL == size || NULL == pos)
    {
        return FALSE;
    }
    setWidgetSize(index, size);

#ifdef WIDGET_SLIDING_SMIL_VBAR
    pos->x = centerXPos(size, FALSE);
#else
    pos->x = centerXPos(size);
#endif

#ifdef WAP_SUPPORT
    pos->y = (meaUiMobWindow->displaySize.height - size->height)/2;
#endif /* WAP_SUPPORT */
    handle = MSF_WIDGET_IMAGE_GADGET_CREATE(MSF_MODID_MEA, 
        *getWidgetHandle(index), size, MsfImageZoomAutofit,
        (useNotif
        ? MSF_GADGET_PROPERTY_FOCUS | MSF_GADGET_PROPERTY_NOTIFY 
        : MSF_GADGET_PROPERTY_FOCUS) , 0);

    if (0 == handle)
    {
        return FALSE; 
    }       

    setGadget(index, handle);
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaUiMobWindow->winHandle, 
        *getGadget(index), pos, 0))
    {
        (void)MSF_WIDGET_RELEASE(handle);
        return FALSE;
    }

    /* Focus change action */
    if (0 == meaRegisterNotification(*getGadget(index),
        MsfNotifyLostFocus, NULL, MEA_MOB_FSM, MEA_SIG_MOB_FOCUS_ACTIVITY))
    {
        (void)MSF_WIDGET_REMOVE(meaUiMobWindow->winHandle, handle);
        (void)MSF_WIDGET_RELEASE(handle);
        return FALSE;
    }

    return TRUE;
}

/*!
 * \brief Create and add new text gadget
 * \param index Widget number in list
 * \param size  The size of the gadget that was created.
 * \param pos   Struct containing position information
 * \return TRUE on successful operation
 *****************************************************************************/
static MSF_BOOL addTextGadget(int index, MsfSize *size, MsfPosition *pos)
{   
    MsfGadgetHandle handle;
    MsfStringHandle strHandle;
#ifdef __MMI_TOUCH_SCREEN__
    /*MsfPosition beginPos;*/
#endif /* __MMI_TOUCH_SCREEN__ */
    if (NULL == size || NULL == pos)
    {
        return FALSE;
    }
    strHandle = *getWidgetHandle(index);
    (void)MSF_WIDGET_GET_SIZE(strHandle, size);

#ifdef WIDGET_SLIDING_SMIL_VBAR
    pos->x = centerXPos(size, TRUE);
#else
    pos->x = centerXPos(size);
#endif

#ifdef WAP_SUPPORT
    pos->y = (meaUiMobWindow->displaySize.height - size->height)/2;
  #ifdef __MMI_TOUCH_SCREEN__

    /*HDIa_widgetExtFormGetMOBPosition(meaUiMobWindow->winHandle, &beginPos);
    pos->x += beginPos.x;
	pos->y += beginPos.y;*/

  #endif
#endif /* WAP_SUPPORT */
    handle = MSF_WIDGET_STRING_GADGET_CREATE(MSF_MODID_MEA, 
        *getWidgetHandle(index), NULL, FALSE,
        MSF_GADGET_PROPERTY_FOCUS | MSF_GADGET_PROPERTY_SCROLLBARVER, 0);
    if (0 == handle)
    {
        return FALSE;
    }    
    
    setGadget(index, handle);

    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaUiMobWindow->winHandle,
        *getGadget(index), pos, 0))
    {
        (void)MSF_WIDGET_RELEASE(handle);
        return FALSE;
    }
    return TRUE;
}

/*!
 * \brief Callback received when a textbox looses focus 
 * 
 * \param winHandle the gadget handle of the textbox that lost focus
 *****************************************************************************/
static void textBoxLostFocus(MsfWindowHandle winHandle)
{
    (void)winHandle;
    if (meaUiMobWindow->noOfHandles > 1) 
    {
        /* We don't delete events if we are the only object on the page */
    (void)meaDeleteUserEvent(meaUiMobWindow->winHandle, MsfKey_Up   );
    (void)meaDeleteUserEvent(meaUiMobWindow->winHandle, MsfKey_Down );
    }
} /* textBoxLostFocus */

/*!
 * \brief Callback called when a navigation key is pressed and a textbox has 
 *        focus
 * \param winHandle the textbox
 *****************************************************************************/
static void textBoxKeyPressUp(MsfWindowHandle winHandle)
{
    MSF_BOOL lostFocus;
    int index;
    
    index = meaUiMobCheckFocus();

    if (index >= 0)
    {
        if (MTR_RESULT_OK != mtrRedraw(*getWidgetInstance(index), MsfKey_Up,
            &lostFocus) || lostFocus)
        {
            textBoxLostFocus(winHandle);
        } /* if */
    }
}

/*!
 * \brief Callback called when a navigation key is pressed and a textbox has 
 *        focus
 * \param winHandle the textbox
 *****************************************************************************/
static void textBoxKeyPressDown(MsfWindowHandle winHandle)
{
    MSF_BOOL lostFocus;
    int index;
    
    index = meaUiMobCheckFocus();

    if (index >= 0)
    {
        if (MTR_RESULT_OK != mtrRedraw(*getWidgetInstance(index), MsfKey_Down,
            &lostFocus) || lostFocus)
        {
            textBoxLostFocus(winHandle);
        } /* if */
    }
}

/*!
 * \brief Callback received when a textbox gets focus  
 * \param winHandle  the window handle in which the textbox got focus
 *****************************************************************************/
static void textBoxGotFocus(MsfWindowHandle winHandle)
{   
    (void)winHandle;

    /* Textbox has focus! Handle the events for the navigation keys. */
    (void)meaRegisterUserEvent(meaUiMobWindow->winHandle, MsfKey_Up, 
        textBoxKeyPressUp, 0, 0);
    (void)meaRegisterUserEvent(meaUiMobWindow->winHandle, MsfKey_Down,
        textBoxKeyPressDown, 0, 0);
} /* textBoxGotFocus */

/*!
 * \brief Add new textbox gadget
 * \param index Widget number in list
 * \param pos   Struct containing position information
 * \return TRUE on successful operation
 *****************************************************************************/
static MSF_BOOL addTextBoxGadget(int index, MsfSize *size, MsfPosition *pos)
{   
#ifdef WIDGET_SLIDING_SMIL_VBAR
    MsfPosition vBarPos;
    MsfGadgetHandle vBarHandle;
#endif  /* WIDGET_SLIDING_SMIL_VBAR*/

    /* Set the size */
    (void)MSF_WIDGET_GET_SIZE(meaUiMobWindow->handles[index].gadgetHandle, 
        size);

#ifdef WIDGET_SLIDING_SMIL_VBAR
    pos->x = centerXPos(size, TRUE);
#else
    pos->x = centerXPos(size);
#endif
    /* Gadget is already created, just add it to window */
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaUiMobWindow->winHandle, 
        meaUiMobWindow->handles[index].gadgetHandle, pos, 0))
    {
        return FALSE;
    }
    
#ifdef WIDGET_SLIDING_SMIL_VBAR

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAUIMOB_C3E53EACD21A759E8DD22197487D8FBB, "MEA MMV Scroll: In addTextBoxGadget, will add scroll bar widget\n"));
    vBarHandle = mtrGetVScrollBar();
    if (vBarHandle > 0) /* Add scroll bar*/
    {
        /* Get scroll bar position*/
        vBarPos.x = meaUiMobWindow->displaySize.width - MSF_CFG_SCROLLBAR_WIDTH;
        vBarPos.y = 0;
        HDIa_widgetWindowAddGadget(meaUiMobWindow->winHandle, 
            vBarHandle, &vBarPos, 0);

    #ifdef __MMI_TOUCH_SCREEN__
        HDIa_widgetExtFormRegisterMOBScrollNotification(meaUiMobWindow->winHandle,
            vBarHandle, meaScrollNotif);
    #endif
    }
    
#endif /* WIDGET_SLIDING_SMIL_VBAR*/

    /* Focus change actions */
    if (0 == meaRegisterNotification(*getGadget(index), MsfNotifyFocus, 
        textBoxGotFocus, 0, 0))
    {
        return FALSE;
    }

    return TRUE;
}

/*!
 * \brief Calculate X position to center object, based on size
 * \param size size of object 
 * \return The calculated x position
 *****************************************************************************/
#ifdef WIDGET_SLIDING_SMIL_VBAR
static MSF_INT16 centerXPos(const MsfSize *size, MSF_BOOL forText)
#else
static MSF_INT16 centerXPos(const MsfSize *size)
#endif
{
#ifdef WIDGET_SLIDING_SMIL_VBAR
    if (forText)
        return (MSF_INT16)((meaUiMobWindow->displaySize.width - size->width - MSF_CFG_SCROLLBAR_WIDTH)/2);
    else
        return (MSF_INT16)((meaUiMobWindow->displaySize.width - size->width)/2);
#else
    return (MSF_INT16)((meaUiMobWindow->displaySize.width - size->width)/2);
#endif /* WIDGET_SLIDING_SMIL_VBAR*/
}

/*!
 * \brief Set size for a widget, possibly with rescaling if too big 
 * \param i    The widget number in list
 * \param size Where to store size data
 *****************************************************************************/
static void setWidgetSize(int i, MsfSize *size)
{
    if ( MSF_WIDGET_GET_SIZE(*getWidgetHandle(i), size)< 0)
    {
        size->height = 2;
        size->width = 2;
        return; 
    }
    rescale(size);
}

/*!
 * \brief Create and add gadgets to form
 * \param The window struct to add gadgets to
 * \return TRUE on successful operation
 *****************************************************************************/
static MSF_BOOL meaUiMobAddGadgets(void)
{
    int             i;
    MsfPosition     pos = {0,0};
    MsfSize         size = {0,0};

    /* Show media objects first */
    for (i = 0 ; i < meaUiMobWindow->noOfHandles; i++)
    {
        MeaMediaGroupType groupType = *getMediaGroup(i);
        /* Add image gadgets for images/audio */
        if (MEA_MOB_MO == *getEntryType(i))
        {
            if (groupType == MEA_MEDIA_GROUP_IMAGE ||groupType == MEA_MEDIA_GROUP_VIDEO || groupType == MEA_MEDIA_GROUP_AUDIO)
            {
                if (!addImageGadget(i, &size, &pos, (MEA_MEDIA_GROUP_AUDIO == *getMediaGroup(i))))
                {
                    return FALSE;
                }
            }
            else if (groupType == MEA_MEDIA_GROUP_TEXT)
            {
                if (!addTextBoxGadget(i, &size, &pos))
                {
                    return FALSE;
                }
            }
            pos.y = (MSF_INT16)(pos.y + size.height + MEA_MOB_MO_DISTANCE); 
        }
    }
    
    /* Add distance between the objects and the special operations */
    if (pos.y != 0)
    {
        pos.y = (MSF_INT16)(pos.y + MEA_MOB_OP_DISTANCE);
    }
    /* Show special operations */
    for (i = 0 ; i < meaUiMobWindow->noOfHandles; i++)
    {
        if (MEA_MOB_SOP == *getEntryType(i))
        {
            if (!addTextGadget(i, &size, &pos))
            {
                return FALSE;
            }
            pos.y = (MSF_INT16)(pos.y + size.height + MEA_MOB_MO_DISTANCE);
        }
    }
    return TRUE;
}

/*!
 * \brief Create a form and set its size
 * \return TRUE upon success
 *****************************************************************************/
MSF_BOOL meaUiInitializeForm(void)
{
    MsfColor bgColor = {255, 255, 255};
    MsfStyleHandle style;

    if (0 == (style = MSF_WIDGET_STYLE_CREATE(MSF_MODID_MEA, NULL, 
        &bgColor, NULL, NULL, NULL, NULL, NULL)))
    {
        return FALSE;
    }

    /* Create form */
    if (0 == (meaUiMobWindow->winHandle = MSF_WIDGET_FORM_CREATE(MSF_MODID_MEA,
        NULL, MSF_GADGET_PROPERTY_NOTIFY, style)))
    {
        (void)MSF_WIDGET_RELEASE(style);
        return FALSE;
    }
    (void)MSF_WIDGET_RELEASE(style);

    HDIa_widgetExtFromSetMMSViewer(meaUiMobWindow->winHandle);
    (void)MSF_WIDGET_WINDOW_SPECIFIC_SIZE(meaUiMobWindow->winHandle, 
        &meaUiMobWindow->displaySize, 0);

    return TRUE;
} /* meaUiInitializeForm */

#ifdef WIDGET_SLIDING_SMIL_VBAR
MsfWindowHandle meaUiMobGetForm(void)
{
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAUIMOB_06EB6CAC24EDD096713BF906A192A36D, "MEA MMV Scroll: meaUiMobGetForm\n"));
    
    if (!meaUiMobWindow)
        return 0;

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAUIMOB_11E1738E6D89A6E56A3699829070F7E4, "MEA MMV Scroll: winHandle = %x\n", meaUiMobWindow->winHandle));
    
    return meaUiMobWindow->winHandle;
}

#ifdef __MMI_TOUCH_SCREEN__
void meaHandleScrollEvent(MsfNotificationType event)
{
    MSF_BOOL lostFocus;
    int index;

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_23266D83494633F1278FEA71D046B5AA, "MEA MMV Scroll: meaHandleScrollEvent\n"));
    
    index = meaUiMobCheckFocus();

    if (index >= 0)
    {
        if (MTR_RESULT_OK != mtrRedraw(*getWidgetInstance(index), event, 
            &lostFocus) || lostFocus)
        {
            textBoxLostFocus(meaUiMobGetForm());
        }
    }
}

static void meaScrollNotif(void)
{
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_DD3836006267421F0F59967D21E4E95F, "MEA MMV Scroll: meaScrollNotif\n"));
    (void)MEA_SIGNAL_SENDTO(MEA_MOB_FSM, MEA_SIG_MOB_EVENT_SCROLL);
}

#endif /* __MMI_TOUCH_SCREEN__*/
#endif /* WIDGET_SLIDING_SMIL_VBAR*/

static MeaMediaGroupType meaUiMobGetMediaGroup(void)
{
    if(MEA_MOB_MO == *getEntryType(0))
    	return *getMediaGroup(0);
    else
    	return MEA_MEDIA_GROUP_NONE;
}

/*!
 * \brief Create form
 * \param winTitle Preallocated window title
 * \return TRUE on successful operation
 *****************************************************************************/
MSF_BOOL meaUiMobFinalizeForm(MSF_UINT32 moIndex)
{
    MsfStringHandle titleHandle;
    int moCount = meaMobGetMoCount();
    char *str = NULL;
    MSF_BOOL disp_ret;

    str = MEA_ALLOC((MSF_UINT32)6);  /* XX/XX */
    ASSERT(str != NULL);
    sprintf(str, "%d%c%d", (int)moIndex+1, '/', ((moCount < 1)? 1: moCount));
    titleHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, str, MsfUtf8, (int)strlen(str) + 1, 0);

    /* Set title */
    if (!meaSetTitle(meaUiMobWindow->winHandle, titleHandle, 0))
    {
        return FALSE;
    }
   
    MSF_WIDGET_WINDOW_SET_PROPERTIES(meaUiMobWindow->winHandle,
		 		 MSF_WINDOW_PROPERTY_EXT_VOLUME_KEY | MSF_WINDOW_PROPERTY_TITLE);
    
    /* Gadgets */
    if (!meaUiMobAddGadgets())
    {
        return FALSE;
    }

    /* Ok action */
#ifndef __UNIFIED_MSG_SUPPORT__
    if (!meaMobCheckIsEmpty())
#endif
    {
        switch(meaUiMobGetMediaGroup())
        {
            case MEA_MEDIA_GROUP_AUDIO:
            case MEA_MEDIA_GROUP_IMAGE:
            case MEA_MEDIA_GROUP_TEXT:
            case MEA_MEDIA_GROUP_DRM:
                if (0 == (meaUiMobWindow->actionOk = 
                	meaCreateAction(meaUiMobWindow->winHandle, MsfSelect, NULL, MEA_MOB_FSM, MEA_SIG_MOB_OK_SELECTED, MEA_STR_ID_OPTIONS)))  /* Ok action */
                {
                    return FALSE;
                }
                break;
            case MEA_MEDIA_GROUP_VIDEO:
                if (0 == (meaUiMobWindow->actionStop =
                	meaCreateAction(meaUiMobWindow->winHandle, MsfBack, NULL, 
                  MEA_MOB_FSM, MEA_SIG_MOB_STOP_SELECTED, SMA_STR_ID_SLIDE_ACTION_STOP)))  /* Ok action */
                {
                    return FALSE;
                }
                meaUiMobPlayVideo(*getWidgetHandle(0));
                break;
            case MEA_MEDIA_GROUP_NONE:
                if (0 == (meaUiMobWindow->actionOk = 
                	meaCreateAction(meaUiMobWindow->winHandle, MsfSelect, NULL, MEA_MOB_FSM, MEA_SIG_MOB_OK_SELECTED, MEA_STR_ID_OPTIONS)))  /* Ok action */
                {
                    return FALSE;
                }
                break;
        }
    }
    
    /* Back action */
    if (meaUiMobWindow->actionStop == 0)
    {
        if (0 == (meaUiMobWindow->actionBack = 
        	meaCreateAction(meaUiMobWindow->winHandle, MsfBack, NULL, MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE, MEA_STR_ID_BACK)))
        {
            return FALSE;
        }
    }

    HDIa_widgetExtFormDisableGadgetBorder(meaUiMobWindow->winHandle, KAL_TRUE);

    if(moCount > 1)  /* Register left/right key */
    {
        MSF_BOOL left = FALSE, right = FALSE;

        /* Left / Right arrow indicator */
        if(moIndex == 0 && moCount > 1)
        {
            right = TRUE;
        }
        else if(moIndex + 1 >= moCount)
        {
            left = TRUE;
        }
        else
        {
            left = right = TRUE;
        }
        
        HDIa_widgetExtFormSetArrowIndication(meaUiMobWindow->winHandle, left, right, FALSE, FALSE);

        (void)meaRegisterUserEvent(meaUiMobWindow->winHandle, MsfKey_Left,  NULL, MEA_MOB_FSM, MEA_SIG_MOB_KEY_LEFT);
        (void)meaRegisterUserEvent(meaUiMobWindow->winHandle, MsfKey_Right, NULL, MEA_MOB_FSM, MEA_SIG_MOB_KEY_RIGHT);
    }

    disp_ret = meaDisplayWindow(meaUiMobWindow->winHandle, meaGetPosLeftTop());

#ifndef __UNIFIED_MSG_SUPPORT__
    if (!meaMobCheckIsEmpty())
#endif
    {
        if (meaUiMobGetMediaGroup() == MEA_MEDIA_GROUP_AUDIO)
        {
            meaUiMobPlayAudio();
        }
    }
    return disp_ret;
}

/*!
 * \brief Update form to play/stop video
 * \return
 *****************************************************************************/
void meaUiMobUpdateForm(MSF_BOOL isPlaying)
{
    MeaMediaGroupType gType = meaUiMobGetMediaGroup();

    /* LSK should be updated  no matter how */
    if(meaUiMobWindow->actionStop)
    {
        MSF_WIDGET_REMOVE(meaUiMobWindow->winHandle, meaUiMobWindow->actionStop);
        meaDeleteAction(meaUiMobWindow->actionStop);
        meaUiMobWindow->actionStop = 0;
    }

    if(meaUiMobWindow->actionOk)
    {
        MSF_WIDGET_REMOVE(meaUiMobWindow->winHandle, meaUiMobWindow->actionOk);
        meaDeleteAction(meaUiMobWindow->actionOk);
        meaUiMobWindow->actionOk = 0;
    }

    if (meaUiMobWindow->actionBack)
    {
        MSF_WIDGET_REMOVE(meaUiMobWindow->winHandle, meaUiMobWindow->actionBack);
        meaDeleteAction(meaUiMobWindow->actionBack);
        meaUiMobWindow->actionBack = 0;
    }

    if(isPlaying == FALSE)
    {
        if(gType == MEA_MEDIA_GROUP_VIDEO ||
           gType == MEA_MEDIA_GROUP_DRM)
        {
            meaUiMobStopVideo(*getWidgetHandle(0));
            MSF_WIDGET_EXT_DISABLE_VIDEO_PLAY(*getWidgetHandle(0));
        }
        
        meaUiMobWindow->actionOk = meaCreateAction(meaUiMobWindow->winHandle, MsfSelect, NULL, 
            MEA_MOB_FSM, MEA_SIG_MOB_OK_SELECTED, MEA_STR_ID_OPTIONS);  /* Ok action */
        meaUiMobWindow->actionBack = meaCreateAction(meaUiMobWindow->winHandle, MsfBack, NULL, 
            MEA_MOB_FSM, MEA_SIG_MOB_DEACTIVATE, MEA_STR_ID_BACK);
    }
    else
    {
        if(gType == MEA_MEDIA_GROUP_VIDEO ||
           gType == MEA_MEDIA_GROUP_DRM)
        {
            meaUiMobPlayVideo(*getWidgetHandle(0));
        }
        
        meaUiMobWindow->actionStop = meaCreateAction(meaUiMobWindow->winHandle, MsfBack, NULL, 
            MEA_MOB_FSM, MEA_SIG_MOB_STOP_SELECTED, SMA_STR_ID_SLIDE_ACTION_STOP);  /* Ok action */
    }

    (void)MSF_WIDGET_SET_IN_FOCUS(meaGetScreenHandle(), TRUE);
    (void)MSF_WIDGET_SET_IN_FOCUS(meaUiMobWindow->winHandle, TRUE);
}

/*!
 * \brief Check which widget is in focus
 * \return Index in list
 *****************************************************************************/
int meaUiMobCheckFocus(void)
{
    int i;

    for (i = 0; i < meaUiMobWindow->noOfHandles; i++)
    {
        if (MSF_WIDGET_HAS_FOCUS(*getGadget(i)))
        {
            return i;
        }
    }
    return -1;
}

/*!
 * \brief Return which special operation was selected
 * \return The operation or MEA_MOB_SOP_NO_OP if not special op was selected
 *****************************************************************************/
MeaMobSpecialOp meaUiMobGetSpecialOp(void)
{
    int i = meaUiMobCheckFocus();
    
    if (i < 0 || *getEntryType(i) != MEA_MOB_SOP)
    {
        return MEA_MOB_SOP_NO_OP;
    }

    return *getSpecialOp(i);    
}

extern void mtrClearCurrInst();
/*!
 * \brief Delete all widgets, gadgets, window
 *****************************************************************************/
void meaUiMobDeleteAll(void)
{
    int i;

    if (meaUiMobWindow->winHandle)
    {
        (void)meaDeleteUserEvent(meaUiMobWindow->winHandle, MsfKey_Left );
        (void)meaDeleteUserEvent(meaUiMobWindow->winHandle, MsfKey_Right);
        (void)meaDeleteUserEvent(meaUiMobWindow->winHandle, MsfKey_Up   );
        (void)meaDeleteUserEvent(meaUiMobWindow->winHandle, MsfKey_Down );
        HDIa_widgetExtFromClearMMSViewer(meaUiMobWindow->winHandle);

         /* Delete form and actions */
        (void)meaDeleteWindow(meaUiMobWindow->winHandle);
        meaUiMobWindow->winHandle = 0;
    }

    for (i = 0; i < meaUiMobWindow->noOfHandles; i++)
    {
        if (MEA_MOB_MO == meaUiMobWindow->handles[i].type)
        {
            if (MEA_MEDIA_GROUP_TEXT == meaUiMobWindow->handles[i].mediaGroup)    /* free MTR instance for text boxes */
            {
                (void)meaDeleteNotification(meaUiMobWindow->handles[i].gadgetHandle);
                meaUiMobWindow->handles[i].gadgetHandle = 0;
    
                /* takes care of both widget and gadget destruction */
                (void)mtrDeleteTextBox(meaUiMobWindow->handles[i].mtrInstance);
                meaUiMobWindow->handles[i].mtrInstance = 0;
            }
            else if(MEA_MEDIA_GROUP_AUDIO == meaUiMobWindow->handles[i].mediaGroup)  /* stop audio */
            {
                meaUiMobStopAudio();
            }
            else if(MEA_MEDIA_GROUP_VIDEO == meaUiMobWindow->handles[i].mediaGroup)  /* stop video */
            {
                if (meaUiMobWindow->isPlaying == TRUE)
                {
                    meaUiMobStopVideo(meaUiMobWindow->handles[i].widgetHandle);
                }
            }
        }

        /* free widget */
        if (meaUiMobWindow->handles[i].widgetHandle)
        {
            (void)MSF_WIDGET_RELEASE(meaUiMobWindow->handles[i].widgetHandle);
            meaUiMobWindow->handles[i].widgetHandle = 0;
        }

        if (meaUiMobWindow->audioHandle)
        {
            (void)MSF_WIDGET_RELEASE(meaUiMobWindow->audioHandle);
            meaUiMobWindow->audioHandle = 0;
        }

        /* free gadget */
        if (meaUiMobWindow->handles[i].gadgetHandle)
        {
            (void)MSF_WIDGET_RELEASE(meaUiMobWindow->handles[i].gadgetHandle);
            (void)meaDeleteNotification(meaUiMobWindow->handles[i].gadgetHandle);
            meaUiMobWindow->handles[i].gadgetHandle = 0;
        }
    }   
    meaUiMobWindow->noOfHandles = 0;
    meaUiMobWindow->actionBack = 0;
    meaUiMobWindow->actionOk = 0;
    meaUiMobWindow->actionStop = 0;
    meaUiMobWindow->audioHandle = 0;
    mtrClearCurrInst();

#ifdef WIDGET_SLIDING_SMIL_VBAR
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAUIMOB_292F1AF49FD588F56E83A221346A6D82, "MEA MMV Scroll: In meaUiMobDeleteAll, will delete scroll bar\n"));
    mtrDeleteVScrollBar();
#endif /* WIDGET_SLIDING_SMIL_VBAR*/
}

/*!
 * \brief Timer handler for video end
 *****************************************************************************/
void meaUiMobHandleTimer()
{
    meaUiMobUpdateForm(FALSE);
}

/*!
 * \brief Initialize the mob UI 
 *****************************************************************************/
void meaUiMobInit(void)
{
    MEA_CALLOC(meaUiMobWindow, sizeof(MeaUiMobWindow));
}

/*!
 * \brief Terminate the mob UI
 *****************************************************************************/
void meaUiMobTerminate(void)
{
    if (meaUiMobWindow != NULL)
    {
        meaUiMobDeleteAll();
        MEA_FREE(meaUiMobWindow);
        meaUiMobWindow = NULL;
    }
#if defined(MEA_GET_MIXED_TEXT_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)
    meaUiMobDeleteGetTextHeightInst();
#endif
}

#if defined(MEA_GET_MIXED_TEXT_HEIGHT) && defined(WIDGET_SLIDING_SMIL_VBAR)

#define MEA_UI_MOB_BASELINE_SIZE      (1)
#define QUANTUM_IN_TICKS              (KAL_TICKS_1_SEC /4)
#define IS_NEWLINE(c)                 ((c)==0x0A||(c)==0x0D)

extern void SetTotalTextHeightValue(int totalHeight);
extern char *mtrGetStringBufferFromHandle(MsfStringHandle strHandle);

MSF_BOOL  meaUiMobCreateGetTextHeightInst(const char* text)
{
    MsfFont font;
    int tmp;
    int fontHeight;

    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_C7539FDF0692931D6235E7F1BD4ABA0F, "[TEXT HEIGHT] meaUiMobCreateGetTextHeightInst\n"));
    
    if (!text || !meaUiMobWindow)
    {
        ASSERT(0);
        return FALSE;
    }

    MEA_CALLOC(uiMobGetTextHeightInst, sizeof(MeaUiMobGetTextHeightInstance));

    /* text area size*/
    uiMobGetTextHeightInst->maxSize.width = (MSF_INT16)(meaUiMobWindow->displaySize.width - 
        MEA_MOB_MARKER_SIZE - MSF_CFG_SCROLLBAR_WIDTH);

   #ifdef __MMI_TOUCH_SCREEN__
   uiMobGetTextHeightInst->maxSize.height = (MSF_INT16)(meaUiMobWindow->displaySize.height -
        MEA_MOB_MARKER_SIZE);
   #else
   uiMobGetTextHeightInst->maxSize.height = (MSF_INT16)(meaUiMobWindow->displaySize.height -
        MEA_MOB_MARKER_SIZE);
   #endif

    /* create string*/
    if (0 == (uiMobGetTextHeightInst->stringHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
        text, MsfUtf8, strlen(text) + 1, 0)))
    {
        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_CB08113948E51950CC53B4E588956FDE, "[TEXT HEIGHT] create string failed\n"));
        return FALSE;
    }

    /* get line height*/
    if (MSF_WIDGET_GET_FONT(uiMobGetTextHeightInst->stringHandle, &font) < 0) 
    {
        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_02DE5D9A5FB93248E8572F8AA5A3A7C6, "[TEXT HEIGHT] get font failed\n"));
        (void)MSF_WIDGET_RELEASE(uiMobGetTextHeightInst->stringHandle);
        uiMobGetTextHeightInst->stringHandle = 0;
        return FALSE;
    }

    /* text info*/
    uiMobGetTextHeightInst->text = mtrGetStringBufferFromHandle(uiMobGetTextHeightInst->stringHandle);
    /*uiMobGetTextHeightInst->textLen = strlen(uiMobGetTextHeightInst->text);*/
    
    /* string pos info*/
    uiMobGetTextHeightInst->strPos = 0;
    uiMobGetTextHeightInst->tPos = uiMobGetTextHeightInst->text;
    uiMobGetTextHeightInst->newStringStart = uiMobGetTextHeightInst->text;

    (void)MSF_WIDGET_RELEASE(uiMobGetTextHeightInst->stringHandle);
    uiMobGetTextHeightInst->stringHandle = 0;
    
    if (MSF_WIDGET_FONT_GET_VALUES(&font, &tmp, &fontHeight, &tmp) < 0)
    {
        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_07F13BEA124FC0AFA63C6DABE7031A83, "[TEXT HEIGHT] get font values failed\n"));
        
        return FALSE;
    }
    
    /*get one-line height*/
    uiMobGetTextHeightInst->onelineHeight = fontHeight + MEA_UI_MOB_BASELINE_SIZE;

    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_317CA9D026259AC9B99F2D57E2134C77, "[TEXT HEIGHT] inst ok\n"));
    
    return TRUE;
}

void meaUiMobDeleteGetTextHeightInst(void)
{
    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_5F57286B5B72A1E2E7A4543DB94AFB82, "[TEXT HEIGHT] meaUiMobDeleteGetTextHeightInst\n"));
    
    if (!uiMobGetTextHeightInst)
    {
        return;
    }

    if (uiMobGetTextHeightInst->text != NULL)
    {
        MEA_FREE(uiMobGetTextHeightInst->text);
    }
    
    if (uiMobGetTextHeightInst->stringHandle)
        (void)MSF_WIDGET_RELEASE(uiMobGetTextHeightInst->stringHandle);

    MEA_FREE(uiMobGetTextHeightInst);
    uiMobGetTextHeightInst = NULL;
}

static char* meaUiFindNewLine(char *strBuf, int *len)
{
    char *p = NULL;
    char *old = NULL;
    
    if (!strBuf)
        return NULL;

    *len = 0;
    p = strBuf;
    
    while(p && (*p != 0))
    {
        if (IS_NEWLINE(*p)) /* find it*/
        {
            *len = 1;

            /* Check if the next is also a new line*/
            if ((*(p + 1) != 0) && IS_NEWLINE(*(p + 1))) 
            {
                *len = 2;
            }
            return p;
        }

        old = p;
        p = msf_cmmn_utf8_str_incr(p, 1);
        /* Avoid infinite loops */
        p += (old == p ? 1 : 0); 
        while ((old < p) && (*old != 0))
        {
            old++;
        }
        if (*old == 0)
        {
            break;
        }
    } /* while(p)*/

    return NULL;
}

static int meaUiMobNewLineExists(int start, int chars, int *len, int *newIndex)
{
    char *p, *old;
    int i;
    p = &uiMobGetTextHeightInst->text[start];
    i = 0;
    while (p && *p && (i < chars)) 
    {
        if (p && IS_NEWLINE(*p)) 
        {
            *len = 1;
            p++;
            /*lint -e{774}*/
            if (p && IS_NEWLINE(*p)) 
            {
                *len = 2;
            }
            *newIndex = (p - &uiMobGetTextHeightInst->text[start] - 1) + start;
            return i;
        }
        old = p;
        p = msf_cmmn_utf8_str_incr(p, 1);
        ++i;
        /* Avoid infinite loops */
        p += (old == p ? 1 : 0);
    }
    *len = 0;
    *newIndex = start;
    return -1;
}

MSF_BOOL meaUiMobGetTextHeight(void)
{
    int lastIndex, visibleChars, tmp;
    kal_uint32 last_ticks, ticks;

    if (!uiMobGetTextHeightInst)
    {
        ASSERT(0);
        return TRUE;
    }

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                MAUIMOB_F0FF694171E2F1EAEFFB84811ED0B627, "!!!!!!!!!!!!!!!!!!!!![TEXT HEIGHT] meaMobGetTextHeight, index(%d)/total(%d)\n",
                uiMobGetTextHeightInst->index, uiMobGetTextHeightInst->textLen));

    kal_get_time(&last_ticks);

    do
    {
        kal_get_time(&ticks);
        if (ticks > last_ticks)
        {
            if (ticks - last_ticks > QUANTUM_IN_TICKS)
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAUIMOB_14F24D5E9140A3D7C5497B64318BDD42, "[TEXT HEIGHT] take too long the time, return FALSE here1\n"));
                return FALSE;
            }
        }
        else
        {
            last_ticks = ticks;
        }

        /* Create string handle at first*/
        if (uiMobGetTextHeightInst->stringHandle == 0)
        {
            uiMobGetTextHeightInst->rnPos = meaUiFindNewLine(uiMobGetTextHeightInst->newStringStart,
                &uiMobGetTextHeightInst->lenOfRN);

            if (!uiMobGetTextHeightInst->rnPos) /* No new line found*/
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAUIMOB_54360A559A49040809AB122413017673, "[TEXT HEIGHT] no new line found\n"));

                /* Create string handle by total texts left*/
                if (0 == (uiMobGetTextHeightInst->stringHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
                    uiMobGetTextHeightInst->newStringStart, MsfUtf8, 0, 0)))
                {
                    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                        MAUIMOB_CB08113948E51950CC53B4E588956FDE, "[TEXT HEIGHT] create string failed\n"));
                    return TRUE;
                }
                uiMobGetTextHeightInst->tmpRN = 0;
            }
            else /* Find a new line*/
            {
                MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                    MAUIMOB_65628A71114F1C827E121FD788D63481, "[TEXT HEIGHT] find a new line\n"));

                /* Starting by a new line*/
                if (uiMobGetTextHeightInst->rnPos == uiMobGetTextHeightInst->newStringStart)
                {
                    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                        MAUIMOB_A1EA423CEE5893889E0C5FA04B934F0F, "[TEXT HEIGHT] staring by a new line, hasNormalChar=%d\n", uiMobGetTextHeightInst->hasNormalChar));

                    /* Jump over new line*/
                    uiMobGetTextHeightInst->newStringStart += uiMobGetTextHeightInst->lenOfRN;
                    /* Jump to next string start*/
                    uiMobGetTextHeightInst->strPos = uiMobGetTextHeightInst->newStringStart - 
                        uiMobGetTextHeightInst->text;
                    uiMobGetTextHeightInst->tPos = uiMobGetTextHeightInst->newStringStart;
                
                    if (uiMobGetTextHeightInst->hasNormalChar)
                    {
                        if (IS_NEWLINE(*uiMobGetTextHeightInst->newStringStart))
                        {
                            uiMobGetTextHeightInst->totalHeight = (uiMobGetTextHeightInst->totalHeight + 
			                    uiMobGetTextHeightInst->onelineHeight);
                        }
                    }
                    else
                    {
                        uiMobGetTextHeightInst->totalHeight = (uiMobGetTextHeightInst->totalHeight + 
			                    uiMobGetTextHeightInst->onelineHeight);
                    }

                    continue;
                }

                uiMobGetTextHeightInst->tmpRN = *(uiMobGetTextHeightInst->rnPos + uiMobGetTextHeightInst->lenOfRN);
                *(uiMobGetTextHeightInst->rnPos + uiMobGetTextHeightInst->lenOfRN)= 0;
                uiMobGetTextHeightInst->hasNormalChar = TRUE;

                /* Create string handle by texts until new line*/
                if (0 == (uiMobGetTextHeightInst->stringHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
                    uiMobGetTextHeightInst->newStringStart, MsfUtf8, 0, 0)))
                {
                    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                        MAUIMOB_D828035B8C8582160523BD49980DE7C4, "[TEXT HEIGHT] create string failed2\n"));
                    return TRUE;
                }

                uiMobGetTextHeightInst->strPos = uiMobGetTextHeightInst->newStringStart - 
                    uiMobGetTextHeightInst->text;
                uiMobGetTextHeightInst->tPos = uiMobGetTextHeightInst->newStringStart;
            }

            uiMobGetTextHeightInst->textLen = MSF_WIDGET_STRING_GET_LENGTH(uiMobGetTextHeightInst->stringHandle, 0, MsfUtf8);
            uiMobGetTextHeightInst->index = 0; 
        }

        if (uiMobGetTextHeightInst->index < uiMobGetTextHeightInst->textLen)
        {
            do
            {
                kal_get_time(&ticks);
                if (ticks > last_ticks)
                {
                    if (ticks - last_ticks > QUANTUM_IN_TICKS)
                    {
                        MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                            MAUIMOB_2E49FB3E93D51BAA78E10F4BDE6FA41B, "[TEXT HEIGHT] take too long the time, return FALSE here\n"));
                        return FALSE;
                    }
                }
                else
                {
                    last_ticks = ticks;
                }

                lastIndex = uiMobGetTextHeightInst->index;
                uiMobGetTextHeightInst->totalHeight = (uiMobGetTextHeightInst->totalHeight+ uiMobGetTextHeightInst->onelineHeight);

                /* Check how many characters that can be displayed */
                if (MSF_WIDGET_STRING_GET_VISIBLE(uiMobGetTextHeightInst->stringHandle, 0, &uiMobGetTextHeightInst->maxSize, 
                    uiMobGetTextHeightInst->index, 1, &visibleChars, &tmp, &tmp) < 0)
                {
                    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                        MAUIMOB_BEB1067FC361961DA9DECBB4D2C467BA, "[TEXT HEIGHT] get visible failed\n"));
	                return FALSE;
                }
            
                /* Check for new-line characters */
                /*if (0 <= (nextIndex = meaUiMobNewLineExists(uiMobGetTextHeightInst->strPos, visibleChars, &tmp, 
                    &uiMobGetTextHeightInst->strPos))) 
                {
                    visibleChars = nextIndex;
                    uiMobGetTextHeightInst->index += visibleChars + tmp;
                    uiMobGetTextHeightInst->strPos += tmp;
                    continue;
                }
                else*/
                {
                    uiMobGetTextHeightInst->tPos = &uiMobGetTextHeightInst->text[uiMobGetTextHeightInst->strPos];
                    uiMobGetTextHeightInst->tPos = msf_cmmn_utf8_str_incr(uiMobGetTextHeightInst->tPos, visibleChars);
                    uiMobGetTextHeightInst->strPos = 
                        (uiMobGetTextHeightInst->tPos - &uiMobGetTextHeightInst->text[uiMobGetTextHeightInst->strPos]) + 
                        uiMobGetTextHeightInst->strPos;
                }
                /* Prevent infinite loops */
                if (!visibleChars) 
                {
                    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
                        MAUIMOB_5CD2D56A414E5882E967A16D69FB5358, "[TEXT HEIGHT] !visibleChars\n"));
                    break;
                }
                /* NOTE! If links are rendered much different than the text we need
                 * to take that extra size into account when calculating the size */
                uiMobGetTextHeightInst->index += visibleChars;
                if (IS_NEWLINE(*(uiMobGetTextHeightInst->tPos - 1)) && IS_NEWLINE(*(uiMobGetTextHeightInst->tPos)))
                {
                    break;
                }
                /* Iterate until all characters are visible */
            } while (uiMobGetTextHeightInst->index < uiMobGetTextHeightInst->textLen);
        }
        
        if (uiMobGetTextHeightInst->stringHandle)
        {
            (void)MSF_WIDGET_RELEASE(uiMobGetTextHeightInst->stringHandle);
            uiMobGetTextHeightInst->stringHandle = 0;
        }

        if (uiMobGetTextHeightInst->tmpRN != 0) /* Has new line*/
        {
            /* Add one line height for new line*/
            //uiMobGetTextHeightInst->totalHeight += uiMobGetTextHeightInst->onelineHeight;
            /* Set back rnPos value*/
            if (uiMobGetTextHeightInst->rnPos + uiMobGetTextHeightInst->lenOfRN)
            {
                *(uiMobGetTextHeightInst->rnPos + uiMobGetTextHeightInst->lenOfRN) = uiMobGetTextHeightInst->tmpRN;
            }
            /* Set new string start pos*/
            uiMobGetTextHeightInst->newStringStart = 
                uiMobGetTextHeightInst->rnPos + uiMobGetTextHeightInst->lenOfRN;

            if (IS_NEWLINE(*uiMobGetTextHeightInst->newStringStart))
            {
                uiMobGetTextHeightInst->totalHeight = (uiMobGetTextHeightInst->totalHeight + 
			        uiMobGetTextHeightInst->onelineHeight);
            }
        }
        else
        {
            break;
        }
    } while(*uiMobGetTextHeightInst->newStringStart != 0); /* do, will continue if there are more texts*/

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
        MAUIMOB_7F8F56060B6AAEC4E4D3C9338E93669E, "!!!!!!!!!!!!!!!!!!!!![TEXT HEIGHT] setTotalGadgetHeight End\n"));

    return TRUE;
}


void meaUiMobSetTotalTextHeightValue(void)
{
    MSF_LOG_MSG_NOARG(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_076B30F84531282F8D0E35E59CD7A0B3, "[TEXT HEIGHT] meaUiMobSetTotalTextHeightValue\n"));

    if (!uiMobGetTextHeightInst)
    {
        SetTotalTextHeightValue(-1);
        return;
    }
    
    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MEA, 
            MAUIMOB_8AA48D3547105328D6A24402512FB1F8, "[TEXT HEIGHT] totalHeight = %d\n", uiMobGetTextHeightInst->totalHeight));

    SetTotalTextHeightValue(uiMobGetTextHeightInst->totalHeight);
}

#endif

