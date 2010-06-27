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

/* !\file mauime.c
 *  \brief UI for the message editor.
 */

/* MSF */
#include "msf_wid.h"
#include "msf_int.h"
#include "msf_def.h"
#include "msf_log.h"
#include "msf_lib.h"
#include "msf_mem.h"
#include "msf_core.h"

/* MMS */
#include "mms_def.h"

/* MEA */
#include "mea_def.h"
#include "mea_env.h"
#include "mea_cfg.h"
#include "mea_rc.h"

#include "matypes.h"
#include "mamem.h"
#include "maintsig.h"
#include "mauicmn.h"
#include "mase.h"
#include "mamr.h"
#include "mame.h"
#include "mauimenu.h"
#include "mauime.h"
#include "mase.h"
#include "maconf.h"
#include "mauisig.h"
#include "mauidia.h"
#include "maaddr.h"
#include "mapbh.h"
#ifdef WAP_SUPPORT
#include "mauiform.h"
#include "macore.h" //For startup mode
#include "maslh.h"
/* CTK */
#include "widget_extension.h"
#endif /* WAP_SUPPORT */

/******************************************************************************
 * Constants
 *****************************************************************************/
/* Size and placement for the To gadget */
#define MEA_ME_GADGET_SPACING           40
#define MEA_ME_GADGET_WIDTH             MEA_GADGET_DEF_WIDTH
#define MEA_ME_GADGET_HEIGHT            30

/******************************************************************************
 * Data-types
 *****************************************************************************/
#ifdef WAP_SUPPORT
typedef enum
{
    MEA_ME_PROP_VIEW_TO,
    MEA_ME_PROP_VIEW_CC,
    MEA_ME_PROP_VIEW_BCC,
    MEA_ME_PROP_VIEW_SUBJECT,
    MEA_ME_PROP_VIEW_COUNT_FOR_FORWARD,
    MEA_ME_PROP_VIEW_EDIT_CONT_TITLE = MEA_ME_PROP_VIEW_COUNT_FOR_FORWARD,
    MEA_ME_PROP_VIEW_EDIT_CONT,
    MEA_ME_PROP_VIEW_COUNT
}MeaMePropViewItem;
#endif /* WAP_SUPPORT */

/*! \struct MeaMePropView
 *  MM property view */
typedef struct
{
    /* Form */
    MsfWindowHandle formHandle;
#ifndef WAP_SUPPORT
    /* Gadgets */
    MsfGadgetHandle toGadgetHandle;
    MsfGadgetHandle ccGadgetHandle;
    MsfGadgetHandle bccGadgetHandle;
    MsfGadgetHandle subjectGadgetHandle;
    MsfGadgetHandle optionsGadgetHandle;
    MsfGadgetHandle contentGadgetHandle;
    MsfGadgetHandle sendGadgetHandle;
#endif /* WAP_SUPPORT */
}MeaMePropView;

/*! \struct MeaMeAddrInput
 *
 */
typedef struct
{
    MsfWindowHandle winHandle;
#ifdef MEA_CFG_USE_EXT_PB
    MsfGadgetHandle phoneBookHandle;
#endif 
    MsfGadgetHandle textInputHandle;
    MeaMeProperty   type;
    int             editIndex;
}MeaMeAddrInputView;

/*! \struct MeaMeAddrListView
 *
 */
typedef struct
{
    MsfWindowHandle winHandle;
    MeaMeProperty   type;
    MeaAddrItem     *items;
#ifdef WAP_SUPPORT
    MsfActionHandle backActHandle;
#endif /* WAP_SUPPORT */
}MeaMeAddrListView;

/******************************************************************************
 * Constants
 *****************************************************************************/
#ifndef WAP_SUPPORT
static const MsfSize gadgetSize = {MEA_ME_GADGET_HEIGHT, MEA_ME_GADGET_WIDTH};
#endif /* ~WAP_SUPPORT */

/******************************************************************************
 * Internal data-structures for the GUI.
 *****************************************************************************/
static MeaMePropView        meaMePropView;
static MeaMeAddrInputView   meaMeAddrInputView;
static MeaMeAddrListView    meaMeAddrListView;
static MSF_BOOL             meaNumberValidFlag;
#ifdef WAP_SUPPORT
/******************************************************************************
 * Static variables 
 *****************************************************************************/
static MeaMeProperty propType=MEA_ME_NONE;
//static MSF_BOOL editContentIsChanged = FALSE;
static char *strSlide = NULL;
static char *strSlides = NULL;
#endif /* WAP_SUPPORT */
/******************************************************************************
 * Prototypes
 *****************************************************************************/

static void navMenuSignalConverter(MeaNavAction actionType);
#ifdef WAP_SUPPORT
static MSF_BOOL meaMeCreateAddrListEmptyDoneView(MeaMeProperty type);
#else
static void handlePropBackAction(MsfWindowHandle winHandle);
#endif /* WAP_SUPPORT */
static char *createRecipStr(MeaAddrItem *items);

/******************************************************************************
 * Function implementation
 *****************************************************************************/

/*!
 * \brief Init function.
 *****************************************************************************/
void meaMeUiInit()
{
    /* Initiate data-structures */
    memset(&meaMePropView, 0, sizeof(MeaMePropView));
    memset(&meaMeAddrInputView, 0, sizeof(MeaMeAddrInputView));
    memset(&meaMeAddrListView, 0, sizeof(MeaMeAddrListView));
}

#ifdef WAP_SUPPORT
/*! \brief Creates a string from a #MeaAddrItem.
 *
 * \param item The current item
 * \return A string handle or 0.
 *****************************************************************************/
static MsfStringHandle addrItemToStrHandle(const MeaAddrItem *item)
{
    char *str;

    str = (NULL != item->name) ? item->name: item->address;
#ifdef WAP_SUPPORT
	if (str==NULL)
		return 0;
#endif /* WAP_SUPPORT */
    return MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, str, MsfUtf8, 
        (int)(strlen(str) + 1), 0);
}

MSF_BOOL meaMeUpdateAddrListViewForAdd(const MeaAddrItem *items)
{
    int i;
    MsfStringHandle strHandle;
    if (meaAddrItemCount(items) > 0)
    {
        if (0 != meaMeAddrListView.winHandle)
        {
            /* Delete old items */
            meaMeAddrListView.items = (MeaAddrItem *)items;
            /* Update edited item */
            for(i = 0; NULL != items->next; i++, items = items->next)
            {}
            if (0 == (strHandle = addrItemToStrHandle(items)))
                    return FALSE;
            if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaMeAddrListView.winHandle,
                    (int)i, strHandle, 0, meaGetListNumImage(i), 0, 
                    i==MSF_WIDGET_CHOICE_SIZE(meaMeAddrListView.winHandle)-1?FALSE:TRUE))
            {
                (void)MSF_WIDGET_RELEASE(strHandle);
                return FALSE;
            }
            MSF_WIDGET_CHOICE_SET_ELEM_STATE (meaMeAddrListView.winHandle, 
                i, MSF_CHOICE_ELEMENT_FOCUSED);

            (void)MSF_WIDGET_RELEASE(strHandle);
        }
    }
    else
    {
        MeaMeProperty type=meaMeAddrListView.type;
        meaMeDeleteAddrListView();
        //change to empty screen
        meaMeCreateAddrListEmptyDoneView(type);
    }
    return TRUE;
}

/*! \brief
 * \param items The current list
 *****************************************************************************/
MSF_BOOL meaMeUpdateAddrListViewForEdit(const MeaAddrItem *items, unsigned int ind)
{
    unsigned int i;
    MsfStringHandle strHandle;
    if (meaAddrItemCount(items) > 0)
    {
        if (0 != meaMeAddrListView.winHandle)
        {
            /* Delete old items */
            meaMeAddrListView.items = (MeaAddrItem *)items;
            /* Update edited item */
            for(i = 0; i<ind && NULL != items; i++, items = items->next)
            {}
            if (0 == (strHandle = addrItemToStrHandle(items)))
                    return FALSE;
            if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaMeAddrListView.winHandle,
                    (int)i, strHandle, 0, meaGetListNumImage(i), 0, FALSE))
            {
                (void)MSF_WIDGET_RELEASE(strHandle);
                return FALSE;
            }
            (void)MSF_WIDGET_RELEASE(strHandle);
        }
    }
    else
    {
        MeaMeProperty type=meaMeAddrListView.type;
        meaMeDeleteAddrListView();
        //change to empty screen
        meaMeCreateAddrListEmptyDoneView(type);
    }
    return TRUE;
}


/*!
 * \brief Back action handler for message prop inline view.
 *****************************************************************************/
static void handlePropInlineBackAction(ctk_screen_handle scrid)
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
        MAUIME_C67F304346753CD139BC955A73F979B5, "(%s) (%d) Back action received", __FILE__, __LINE__));
    CTK_UNUSED(scrid);
    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
    widget_send_update_event_to_wap();	 // TODO: remove it later

}

static void meaMePropViewDone(ctk_screen_handle scrid)
{
	//MsfWindowHandle h = HDIa_widgetCtkGetWindow(scrid);
	//int			fail_index = -1;
	// CTK
	ctk_layout_handle			layout_id =ctk_screen_get_layout(scrid);
	ctk_inline_item_type_enum	item_type;
	ctk_inline_result_union		item_value;
	char *str;
	int len;
    
	ctk_inline_get_result(layout_id, MEA_ME_PROP_VIEW_SUBJECT,&item_type, &item_value);
#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
    ASSERT(item_type == CTK_INLINE_ITEM_TYPE_UTF8_EDITOR);
#else  /*__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__*/
    ASSERT(item_type == CTK_INLINE_ITEM_TYPE_EDITOR);
#endif /*__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__*/
	if (item_value.input_buffer /* && strlen(item_value.input_buffer)>0 */)
	{
		len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)item_value.input_buffer);
		str = MEA_ALLOC(len+1);
		widget_ucs2_to_utf8_string((kal_uint8 *) str, len+1, (kal_uint8 *)item_value.input_buffer);
		if(!meaMeSubjectUpdate(str))  //str will be freed if updated it
        {
            return;
        }      
	}

	(void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_NAV_ACTIVATE);
	widget_send_update_event_to_wap();	
}

static void meaMeEditTo(void)
{
	propType = MEA_ME_TO;
	meaDisplayInlineProperty(propType);
}

static void meaMeEditCc(void)
{
	propType = MEA_ME_CC;
	meaDisplayInlineProperty(propType);
}

static void meaMeEditBcc(void)
{
	propType = MEA_ME_BCC;
	meaDisplayInlineProperty(propType);
}

static void meaMeEditContent(void)
{
	ctk_layout_handle			layout_id = 
		ctk_screen_get_layout(HDIa_widgetCtkGetScreenHandle(meaMePropView.formHandle));
	ctk_inline_item_type_enum	item_type;
	ctk_inline_result_union		item_value;
	//char *str;
	//int len;
    
	ctk_inline_get_result(layout_id, MEA_ME_PROP_VIEW_SUBJECT,&item_type, &item_value);

#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
    ASSERT(item_type == CTK_INLINE_ITEM_TYPE_UTF8_EDITOR);
#else  /*__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__*/
    ASSERT(item_type == CTK_INLINE_ITEM_TYPE_EDITOR);
#endif /*__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__*/
	
    /*
	if (item_value.input_buffer && strlen(item_value.input_buffer)>0)
	{
		len = widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)item_value.input_buffer);
		str = MEA_ALLOC(len+1);
		widget_ucs2_to_utf8_string((kal_uint8 *) str, len+1, (kal_uint8 *)item_value.input_buffer);
		meaMeSubjectUpdate(str);
	}
	*/
	(void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_EDIT_CONTENT);
	widget_send_update_event_to_wap();
}

static void meaCreatePredefinedSlideString(void)
{
	char *str = (char*)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_SLIDE);
	int size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8 *)str)+1;
	strSlide = MEA_ALLOC(size);
	widget_ucs2_to_utf8_string((kal_uint8*)strSlide, size, (kal_uint8 *)str);
	str = (char*)HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_SLIDES);
	size = widget_ucs2_to_utf8_length_in_bytes((kal_uint8 *)str)+1;
	strSlides = MEA_ALLOC(size);
	widget_ucs2_to_utf8_string((kal_uint8*)strSlides, size, (kal_uint8 *)str);
}

MSF_BOOL meaMeUpdateEditContent(MeaSmilInfo *smilInfo, MeaPropItem *propItem, MeaMeStartupMode mode)
{
    MSF_UINT32 slideCount = 0, msgSize = 0, kb = 0;
	ctk_screen_handle scrId = 0;
	char *strEditContent = NULL;
    MSF_BOOL ret = TRUE;

	if (!meaMePropView.formHandle || mode == MEA_ME_STARTUP_FORWARD)
	{
        return TRUE;
	}

	if(smilInfo != NULL && propItem != NULL)
	{
        slideCount = meaGetSlideCount(smilInfo);
        if(slideCount == 0 && meaGetAttachmentList())
        {
            meaInsertSlide(smilInfo);
            slideCount = meaGetSlideCount(smilInfo);
        }
        msgSize = meaCalculateMsgSize(smilInfo, propItem);
        if ( msgSize > MEA_CFG_MESSAGE_SIZE_MAXIMUM )
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_MESSAGE_SIZE_MAXIMUM_REACHED), MEA_DIALOG_ERROR);
            ret = FALSE;
        }
/*        msgSize = (msgSize > MEA_CFG_MESSAGE_SIZE_MAXIMUM) ? MEA_CFG_MESSAGE_SIZE_MAXIMUM : msgSize;*/
        kb = (msgSize + (MEA_1_KB - 1)) / MEA_1_KB;
	}
	
	scrId = HDIa_widgetCtkGetScreenHandle(meaMePropView.formHandle);
	ASSERT(scrId);

	/* strEditContent: "20 Slides (300KB)" */
	MEA_CALLOC(strEditContent, 100);

    if (slideCount > 1)
    {
        sprintf(strEditContent, "%lu %s(%lu KB)", slideCount, strSlides, kb);
    }
    else if (slideCount ==1)
    {
        sprintf(strEditContent, "%lu %s (%lu KB)", slideCount, strSlide, kb);
    }
    else if (slideCount ==0 && MEA_STARTUP_MODE_NEW == meaGetStartupMode())
    {
        sprintf(strEditContent, "1 %s (%d KB)", strSlide, (int)((meaGetAttachmentSize() + (MEA_1_KB - 1)) / MEA_1_KB));
    }
    else
    {
        sprintf(strEditContent, "%lu %s", slideCount, strSlide);
    }

    ASSERT(strlen(strEditContent) <= 100);
	
	ctk_inline_update_display_only_data(ctk_screen_get_layout(scrId), 
			MEA_ME_PROP_VIEW_EDIT_CONT, (U8*) strEditContent, KAL_TRUE);
	MEA_FREE(strEditContent);

    return ret;
}

static MSF_BOOL meaMeCreateAddrListEmptyDoneView(MeaMeProperty type)
{
    if (0 == (meaMeAddrListView.backActHandle= MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA, //Option Jo
        MEA_GET_STR_ID(MEA_STR_ID_DONE), MsfBack, 0, MSF_ACTION_PROPERTY_ENABLED)))
    {
        return FALSE;
    }
    meaMeAddrListView.type  = type;
    meaMeAddrListView.items = NULL;

    if (0 == (meaMeAddrListView.winHandle = MSF_WIDGET_MENU_CREATE(
            MSF_MODID_MEA, MsfImplicitChoice, NULL, meaMeAddrListView.backActHandle, NULL,
            MSF_CHOICE_ELEMENT_STRING_1, 0, 0)))
    {
        (void)MSF_WIDGET_RELEASE(meaMeAddrListView.backActHandle);
        return FALSE;
    }
    if (!meaRegisterAction(meaMeAddrListView.winHandle, meaMeAddrListView.backActHandle, 
        NULL, MEA_ME_FSM, MEA_SIG_ME_ADDR_LIST_DEACTIVATE))
    {
        return FALSE;
    }
    if (!meaCreateAction(meaMeAddrListView.winHandle, MsfSelect, NULL, 
        MEA_ME_FSM, MEA_SIG_ME_ADDR_LIST_MENU_ACTIVATE, MEA_STR_ID_OPTIONS))
    {
        return FALSE;
    }
    /* Insert the <Empty> item */
    if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaMeAddrListView.winHandle,
        0, MEA_GET_STR_ID(MEA_STR_ID_EMPTY_LIST), 0, 0, 0, TRUE))
    {
        (void)MSF_WIDGET_RELEASE(MEA_GET_STR_ID(MEA_STR_ID_EMPTY_LIST));
        return FALSE;
    }
    
    /* Set the title */
    (void)meaSetTitle(meaMeAddrListView.winHandle, 
        MEA_GET_STR_ID(MEA_STR_ID_RECIPIENTS), 0);

    return meaDisplayWindow(meaMeAddrListView.winHandle, meaGetPosLeftTop());
}


void meaMeAddAddrList(MeaAddrType type, char* name, char *addr)
{
	MeaAddrItem *item=NULL;
	
    item = MEA_ALLOC(sizeof(MeaAddrItem));
    memset(item, 0, sizeof(MeaAddrItem));
    item->addrType = type;

    if (NULL !=addr)
    {
    	item->address = MEA_ALLOC(strlen(addr) + 1);
    	strcpy(item->address, addr);    	
    }
    if ((NULL != name))
    {
        item->name = MEA_ALLOC(strlen(name) + 1);
        strcpy(item->name, name);
    }
    (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ADD_RECEPIENTS, 
        meaMeAddrListView.type, item);
    if (!meaMeAddrListView.winHandle)
        meaMeCreateAddrListView(meaMeAddrListView.type, item); 
	
    /* Set the title */
    MSF_WIDGET_SET_TITLE(meaMeAddrListView.backActHandle, 
        MEA_GET_STR_ID(MEA_STR_ID_DONE));

    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, 
        MEA_SIG_ME_ADDR_LIST_MENU_DEACTIVATE);
}

static MSF_BOOL meaMeHandleAddrEdit(char *addr, unsigned int notUsed, 
    void *notUsed2, unsigned int selectedIndex)
{
    MeaAddrItem *item=NULL;
    MeaAddrType addrType;
    char * name = NULL;
    if (NULL == addr || (strlen(addr) == 0))
    {
        return TRUE;
    }

    if (MEA_ADDR_TYPE_NONE == (addrType = meaGetAddrType(addr)))
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_RECIP_ADDRESS), MEA_DIALOG_ERROR);
    }
    else 
    {
        if (MEA_ADDR_TYPE_PLMN == addrType)
        {
            name = meaLookupNameFromPHB(addr);
        }

        /* Add item */
        if (!meaAddrItemInsert(&item, name, addrType, addr))
        {
            MEA_FREE(addr);
            MEA_FREE(name);
            return FALSE;
        }
        MEA_FREE(addr);
        MEA_FREE(name);

        (void)MEA_SIGNAL_SENDTO_UUP(MEA_ME_FSM, MEA_SIG_ME_CHANGE_RECEPIENT, 
            meaMeAddrListView.type, selectedIndex, item);
    }
    /* Set the title */
    MSF_WIDGET_SET_TITLE(meaMeAddrListView.backActHandle, MEA_GET_STR_ID(MEA_STR_ID_DONE));
    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_ADDR_LIST_MENU_DEACTIVATE);

    return TRUE;
}

static MSF_BOOL meaMeHandleAddrAdd(char *addr, unsigned int notUsed, 
    void *notUsed2, unsigned int noUsed3)
{
    MeaAddrItem *item=NULL;
    MeaAddrType addrType;
    char *name = NULL;

    if (NULL == addr || (strlen(addr) == 0))
    {
        return TRUE;
    }

    if (MEA_ADDR_TYPE_NONE == (addrType = meaGetAddrType(addr)))
    {
        (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_RECIP_ADDRESS), MEA_DIALOG_ERROR);
    }
    else 
    {
        if (MEA_ADDR_TYPE_PLMN == addrType)
        {
            name = meaLookupNameFromPHB(addr);
        }

        /* Add item */
        if (!meaAddrItemInsert(&item, name, addrType, addr))
        {
            MEA_FREE(addr);
            MEA_FREE(name);
            return FALSE;
        }
        MEA_FREE(addr);
        MEA_FREE(name);
        (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ADD_RECEPIENTS, meaMeAddrListView.type, item);
    }
    if (!meaMeAddrListView.winHandle)
    {
        meaMeCreateAddrListView(meaMeAddrListView.type, item);
    }

    /* Set the title */
    MSF_WIDGET_SET_TITLE(meaMeAddrListView.backActHandle, MEA_GET_STR_ID(MEA_STR_ID_DONE));
    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_ADDR_LIST_MENU_DEACTIVATE);
    
	return TRUE;
}
#else
/*!
 * \brief Back action handler for message prop view.
 *****************************************************************************/
static void handlePropBackAction(MsfWindowHandle winHandle)
{
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
        MAUIME_02E6476476DB584AD3A2F60201989A63, "(%s) (%d) Back action received 0x(%x)", __FILE__, __LINE__, 
        winHandle));
    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_DEACTIVATE);
}

/*!
 * \brief Creates a text input gadget.
 *
 * \param win The handle of destination window for the new text input gadget.
 * \param gadget A pointer to a gadget handle, the created gadget handle is
 *               written here.
 * \param pos   The position of the text input gadget.
 * \param newSize The size of the created gadget.
 * \return      TRUE if the gadget was created successfully, otherwise FALSE.
 *****************************************************************************/
static MSF_BOOL createInputGadget(MsfWindowHandle win, MsfGadgetHandle *gadget, 
    MsfPosition *pos)
{
    /* Create gadget */
    if (0 == (*gadget = MSF_WIDGET_STRING_GADGET_CREATE(MSF_MODID_MEA, 
        meaGetEmptyStringHandle(), (MsfSize*)&gadgetSize, TRUE, 
        MSF_GADGET_PROPERTY_FOCUS, 0)))
    {
        return FALSE;
    }
    /* Bind gadget to form */
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(win, *gadget, pos, 0))
    {
        return FALSE;
    }
    return TRUE;
}

/*!
 * \brief Handles ok action for the property form.
 *
 * \param winHandle The handle of the window that generated the action.
 *****************************************************************************/
static void handlePropOk(MsfWindowHandle winHandle)
{
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
        MAUIME_A5CDD3C8377F91F3ECB578D1E98887B7, "(%s) (%d) Ok actions received 0x%x\n", __FILE__, __LINE__, winHandle));
    if (MSF_WIDGET_HAS_FOCUS(meaMePropView.toGadgetHandle))
    {
        (void)MEA_SIGNAL_SENDTO_U(MEA_ME_FSM, MEA_SIG_ME_EDIT_PROPERTY, 
            MEA_ME_TO);
    }
    else if(MSF_WIDGET_HAS_FOCUS(meaMePropView.ccGadgetHandle))
    {
        (void)MEA_SIGNAL_SENDTO_U(MEA_ME_FSM, MEA_SIG_ME_EDIT_PROPERTY, 
            MEA_ME_CC);
    }
    else if(MSF_WIDGET_HAS_FOCUS(meaMePropView.bccGadgetHandle))
    {
        (void)MEA_SIGNAL_SENDTO_U(MEA_ME_FSM, MEA_SIG_ME_EDIT_PROPERTY, 
            MEA_ME_BCC);
    }    
    else if(MSF_WIDGET_HAS_FOCUS(meaMePropView.subjectGadgetHandle))
    {
        (void)MEA_SIGNAL_SENDTO_U(MEA_ME_FSM, MEA_SIG_ME_EDIT_PROPERTY, 
            MEA_ME_SUBJECT);
    }
    else if(MSF_WIDGET_HAS_FOCUS(meaMePropView.optionsGadgetHandle))
    {
        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_EDIT_PROPERTIES);
    }
    else if(MSF_WIDGET_HAS_FOCUS(meaMePropView.contentGadgetHandle))
    {
        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_PROP_NEXT);
    }
    else if (MSF_WIDGET_HAS_FOCUS(meaMePropView.sendGadgetHandle))
    {
        (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_SEND, MEA_ME_FSM, 
            MEA_SIG_ME_PROP_SEND_DONE);
    }
    else
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
            MAUIME_772AC1B88C94109F2B1ED4622D357646, "(%s) (%d) No valid focus for message properties!\n", __FILE__, 
            __LINE__));
    }
}
#endif /* ~WAP_SUPPORT */


/*!
 * \brief Creates the MM property edit view.
 *
 * \param propItem The current message properties.
 * \param mode Current start up mode for ME.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaMeCreatePropView(MeaPropItem *propItem, 
    MeaMeStartupMode mode)
{
#ifdef WAP_SUPPORT
	char *str;
	ctk_screen_handle				scrid;
	ctk_layout_handle				layoutid;
	ctk_inline_create_struct		layout_create;
	
	ctk_inline_item_caption_copy_struct		caption_create;
	ctk_inline_item_display_only_copy_struct	display_create;

#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
    ctk_inline_item_utf8_editor_copy_struct	editor_create;
#else  /*__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__*/
    ctk_inline_item_editor_copy_struct	editor_create;
#endif /*__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__*/
    

    if (0 != meaMePropView.formHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIME_6E67DAC0518A11AA1C28A7BED8074302, "(%s) (%d) The property view instance is busy!\n", __FILE__, 
            __LINE__));
        return FALSE;
    }

    memset(&meaMePropView, 0, sizeof(MeaMePropView));
	// Create CTK screen
	scrid = widget_ctk_screen_create();
	
	// set key
	ctk_screen_add_inline_Done_UA(scrid, NULL, meaMePropViewDone, KAL_TRUE);
	
	CTK_INIT_STRUCT(layout_create);
	layout_create.in_num_items = ((mode == MEA_ME_STARTUP_FORWARD) ? 
		MEA_ME_PROP_VIEW_COUNT_FOR_FORWARD : MEA_ME_PROP_VIEW_COUNT);
	layout_create.in_img_title = MEA_IMG_TITLE_NORMAL;
	layout_create.in_str_title = (ctk_string_id)MEA_STR_ID_ME_TITLE;
	layout_create.in_cancel_fp = handlePropInlineBackAction;
	//layout_create.in_disable_done = KAL_TRUE;

	layoutid = ctk_inline_create(HDIa_widgetCtkGetApp(), &layout_create);
#ifdef WAP_SUPPORT
		ctk_inline_set_modified(layoutid);
#endif

    {
    	int a = meaRemoveInvalidAddr(&propItem->to);
        int b = meaRemoveInvalidAddr(&propItem->cc);
        int c = meaRemoveInvalidAddr(&propItem->bcc);
        meaNumberValidFlag = (!a || !b || !c);
    }
	// To 
	str = createRecipStr(propItem->to);

	CTK_INIT_STRUCT(display_create);
	display_create.text = (U8*)str;
	display_create.is_UTF8 = KAL_TRUE;
	display_create.edit_fp = meaMeEditTo;
	display_create.edit_strid = MEA_STR_ID_EDIT;
	ctk_inline_set_item_copy(layoutid, MEA_ME_PROP_VIEW_TO, 
	    (U16)MEA_IMG_EDITOR_TO, MEA_STR_ID_TO, CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY, &display_create);

	MEA_FREE(str);

    ctk_inline_set_flag(layoutid, MEA_ME_PROP_VIEW_TO, CTK_INLINE_ITEM_FLAG_UNDERLINE);

	// Cc 
	str = createRecipStr(propItem->cc);

	CTK_INIT_STRUCT(display_create);
	display_create.text = (U8*)str;
	display_create.is_UTF8 = KAL_TRUE;
	display_create.edit_fp = meaMeEditCc;
	display_create.edit_strid = MEA_STR_ID_EDIT;
	ctk_inline_set_item_copy(layoutid, MEA_ME_PROP_VIEW_CC, 
		(U16)MEA_IMG_EDITOR_CC, MEA_STR_ID_CC, CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY, &display_create);
    
	MEA_FREE(str);

    ctk_inline_set_flag(layoutid, MEA_ME_PROP_VIEW_CC, CTK_INLINE_ITEM_FLAG_UNDERLINE);

	// Bcc
	str = createRecipStr(propItem->bcc);

	CTK_INIT_STRUCT(display_create);
	display_create.text = (U8*)str;
	display_create.is_UTF8 = KAL_TRUE;
	display_create.edit_fp = meaMeEditBcc;
	display_create.edit_strid = MEA_STR_ID_EDIT;
	ctk_inline_set_item_copy(layoutid, MEA_ME_PROP_VIEW_BCC, 
		 (U16)MEA_IMG_EDITOR_BCC, MEA_STR_ID_BCC, CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY, &display_create);
    
	MEA_FREE(str);

    ctk_inline_set_flag(layoutid, MEA_ME_PROP_VIEW_BCC, CTK_INLINE_ITEM_FLAG_UNDERLINE);

	/* Subject */
	CTK_INIT_STRUCT(editor_create); 
	editor_create.input_type = CTK_INPUT_TYPE_ALPHANUMERIC_SENTENCECASE;
	editor_create.max_len = MEA_MAX_SUBJECT_LENGTH;
	editor_create.default_text = (U8*) propItem->subject;
	editor_create.is_UTF8 = KAL_TRUE;
	editor_create.str_title = MEA_STR_ID_SUBJECT;
	editor_create.img_title = MEA_IMG_TITLE_NORMAL;
#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
	editor_create.edit_strid = MEA_STR_ID_EDIT;
#endif /*__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__*/
	editor_create.use_input_method_menu = KAL_TRUE;
	ctk_inline_set_item_copy(layoutid, MEA_ME_PROP_VIEW_SUBJECT, (U16)MEA_IMG_EDITOR_SUBJECT, 
        MEA_STR_ID_SUBJECT, 
#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__
        CTK_INLINE_ITEM_TYPE_UTF8_EDITOR, 
#else   /*__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__*/
        CTK_INLINE_ITEM_TYPE_EDITOR, 
#endif  /*__MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__*/
        &editor_create);
	
	ctk_inline_set_flag(layoutid, MEA_ME_PROP_VIEW_SUBJECT, CTK_INLINE_ITEM_FLAG_UNDERLINE);

    // Content 
    meaCreatePredefinedSlideString();
    if (mode != MEA_ME_STARTUP_FORWARD)
    {
        unsigned int slideCount =meaMeGetSlideCount();
        MSF_UINT32 msgSize = meaMeCalculateMsgSize();
        MSF_UINT32 kb;
        kb = (int)((msgSize + (MEA_1_KB - 1)) / MEA_1_KB);
        CTK_INIT_STRUCT(caption_create);
        caption_create.title = (ctk_string_id)MEA_STR_ID_EDIT_CONTENT;
        ctk_inline_set_item_copy(layoutid, MEA_ME_PROP_VIEW_EDIT_CONT_TITLE, 
            (U16) (MEA_IMG_EDITOR_CONTENT), MEA_STR_ID_EDIT_CONTENT, CTK_INLINE_ITEM_TYPE_CAPTION, &caption_create);

        CTK_INIT_STRUCT(display_create);
        if (strlen(strSlides)>strlen(strSlide))
        {
            str = MEA_ALLOC((MSF_UINT32)(strlen("xx ") + strlen(strSlides) + strlen("(300KB)")+1));
        }
        else
        {
            str = MEA_ALLOC((MSF_UINT32)(strlen("xx ") + strlen(strSlide) + strlen("(300KB)")+1));
        }

        if (slideCount > 1)
            sprintf(str, "%d %s(%lu KB)", slideCount, strSlides, kb);
        else if (slideCount ==1)
            sprintf(str, "%d %s (%lu KB)", slideCount, strSlide, kb);
        else if (slideCount ==0 && MEA_STARTUP_MODE_NEW == meaGetStartupMode())
            sprintf(str, "1 %s (%d KB)", strSlide, (meaGetAttachmentSize() + (MEA_1_KB - 1)) / MEA_1_KB);
        else
            sprintf(str, "%d %s", slideCount, strSlide);
        display_create.text = (U8*)str;
		
       display_create.is_UTF8 = KAL_TRUE;
       display_create.edit_fp = meaMeEditContent;
       display_create.edit_strid = MEA_STR_ID_EDIT;
       ctk_inline_set_item_copy(layoutid, MEA_ME_PROP_VIEW_EDIT_CONT, 0, 
           MEA_STR_ID_EDIT_CONTENT, CTK_INLINE_ITEM_TYPE_DISPLAY_ONLY, &display_create);

        MEA_FREE(str);
    }

	ctk_screen_attach_layout(scrid, layoutid);
    // create form
    meaMePropView.formHandle = HDIa_widgetCtkCreate(MSF_MODID_MEA, scrid);
    meaAddWidgetList(meaMePropView.formHandle);
#else /* WAP_SUPPORT */
    MsfPosition pos = {0, 0};
    MsfSize size = {0, 0};
    char *str;

    if (0 != meaMePropView.formHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIME_6E67DAC0518A11AA1C28A7BED8074302, "(%s) (%d) The property view instance is busy!\n", __FILE__, 
            __LINE__));
        return FALSE;
    }

    memset(&meaMePropView, 0, sizeof(MeaMePropView));
    /* Create form*/
    meaMePropView.formHandle = MSF_WIDGET_FORM_CREATE(MSF_MODID_MEA, NULL, 
        MSF_WINDOW_PROPERTY_TITLE, 0);
    if (0 == meaMePropView.formHandle)
        return FALSE;

    /* Create actions */
    if (0 == meaCreateAction(meaMePropView.formHandle, MsfOk,
        handlePropOk, 0, 0, MEA_STR_ID_OK))
    {
        return FALSE;
    }
    if (0 == meaCreateAction(meaMePropView.formHandle, MsfBack, 
        handlePropBackAction, 0, 0, MEA_STR_ID_BACK))
    {
        return FALSE;
    }
    if (0 == meaCreateAction(meaMePropView.formHandle, MsfMenu, 
        NULL, MEA_ME_FSM, MEA_SIG_ME_NAV_ACTIVATE, MEA_STR_ID_MENU))
    {
        return FALSE;
    }

    {
    	int a = meaRemoveInvalidAddr(&propItem->to);
        int b = meaRemoveInvalidAddr(&propItem->cc);
        int c = meaRemoveInvalidAddr(&propItem->bcc);
        meaNumberValidFlag = (!a || !b || !c);        
    }

    /* Create gadgets */
    /* To */
    if (!createInputGadget(meaMePropView.formHandle, 
        &(meaMePropView.toGadgetHandle), &pos))
    {
        return FALSE;
    }
    /* To */
    str = createRecipStr(propItem->to);
    if (!meaSetStringGadgetValue(meaMePropView.toGadgetHandle, 
        MEA_GET_STR_ID(MEA_STR_ID_TO), str))
    {
        MEA_FREE(str);
        return FALSE;
    }
    MEA_FREE(str);
    meaCalculateStringGadgetSize(meaMePropView.formHandle, 
        meaMePropView.toGadgetHandle, MEA_GET_STR_ID(MEA_STR_ID_TO),
        &pos, (MsfSize*)&gadgetSize, &size, FALSE);
    MSF_WIDGET_SET_SIZE(meaMePropView.toGadgetHandle, &size);
    pos.y = (MSF_INT16)((int)pos.y + (int)size.height + 
        MEA_GADGET_DEF_PADDING);
    size.height = size.width = 0;

    /* Cc */
    if (!createInputGadget(meaMePropView.formHandle, 
        &(meaMePropView.ccGadgetHandle), &pos))
    {
        return FALSE;
    }
    str = createRecipStr(propItem->cc);
    if (!meaSetStringGadgetValue(meaMePropView.ccGadgetHandle,
        MEA_GET_STR_ID(MEA_STR_ID_CC), str))
    {
        MEA_FREE(str);
        return FALSE;
    }
    MEA_FREE(str);
    meaCalculateStringGadgetSize(meaMePropView.formHandle, 
        meaMePropView.ccGadgetHandle, MEA_GET_STR_ID(MEA_STR_ID_CC),
        &pos, (MsfSize*)&gadgetSize, &size, FALSE);
    MSF_WIDGET_SET_SIZE(meaMePropView.ccGadgetHandle, &size);
    pos.y = (MSF_INT16)((int)pos.y + (int)size.height + 
        MEA_GADGET_DEF_PADDING);
    size.height = size.width = 0;

    /* Bcc */
    if (!createInputGadget(meaMePropView.formHandle, 
        &(meaMePropView.bccGadgetHandle), &pos))
    {
        return FALSE;
    }
    str = createRecipStr(propItem->bcc);
    if (!meaSetStringGadgetValue(meaMePropView.bccGadgetHandle,
        MEA_GET_STR_ID(MEA_STR_ID_BCC), str))
    {
        MEA_FREE(str);
        return FALSE;
    }
    MEA_FREE(str);
    meaCalculateStringGadgetSize(meaMePropView.formHandle, 
        meaMePropView.bccGadgetHandle, MEA_GET_STR_ID(MEA_STR_ID_BCC),
        &pos, (MsfSize*)&gadgetSize, &size, FALSE);
    MSF_WIDGET_SET_SIZE(meaMePropView.bccGadgetHandle, &size);
    pos.y = (MSF_INT16)((int)pos.y + (int)size.height + 
        MEA_GADGET_DEF_PADDING);
    size.height = size.width = 0;

    /* Subject */
    if (!createInputGadget(meaMePropView.formHandle, 
        &(meaMePropView.subjectGadgetHandle), &pos))
    {
        return FALSE;
    }
    if (!meaSetStringGadgetValue(meaMePropView.subjectGadgetHandle, 
        MEA_GET_STR_ID(MEA_STR_ID_SUBJECT), propItem->subject))
    {
        return FALSE;
    }
    meaCalculateStringGadgetSize(meaMePropView.formHandle, 
        meaMePropView.subjectGadgetHandle, MEA_GET_STR_ID(MEA_STR_ID_SUBJECT),
        &pos, (MsfSize*)&gadgetSize, &size, FALSE);
    MSF_WIDGET_SET_SIZE(meaMePropView.subjectGadgetHandle, &size);
    pos.y = (MSF_INT16)((int)pos.y + (int)size.height + 
        MEA_GADGET_DEF_PADDING);
    
    /* Options */
    if (0 == (meaMePropView.optionsGadgetHandle = 
        MSF_WIDGET_STRING_GADGET_CREATE(MSF_MODID_MEA, 
        MEA_GET_STR_ID(MEA_STR_ID_OPTIONS), NULL, TRUE, 
        MSF_GADGET_PROPERTY_FOCUS, 0)))
    {
        return FALSE;
    }
    /* Bind gadget to form */
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaMePropView.formHandle, 
        meaMePropView.optionsGadgetHandle, &pos, 0))
    {
        return FALSE;
    }
    if (MSF_WIDGET_GET_SIZE(meaMePropView.optionsGadgetHandle, &size) < 0) 
    {
        return FALSE;
    }
    pos.y = (MSF_INT16)((int)pos.y + (int)size.height + 
        MEA_GADGET_DEF_PADDING);
    /* Content */
    if (mode == MEA_ME_STARTUP_FORWARD)
    {
        /* Send button */
        if (0 == (meaMePropView.sendGadgetHandle = 
            MSF_WIDGET_STRING_GADGET_CREATE(MSF_MODID_MEA, 
            MEA_GET_STR_ID(MEA_STR_ID_SEND), NULL, TRUE, 
            MSF_GADGET_PROPERTY_FOCUS, 0)))
        {
            return FALSE;
        }
        /* Bind gadget to form */
        if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaMePropView.formHandle, 
            meaMePropView.sendGadgetHandle, &pos, 0))
        {
            return FALSE;
        } 
    }
    else
    {
        /* Edit content in forward mode */
        if (0 == (meaMePropView.contentGadgetHandle = 
            MSF_WIDGET_STRING_GADGET_CREATE(MSF_MODID_MEA, 
            MEA_GET_STR_ID(MEA_STR_ID_EDIT_CONTENT), NULL, TRUE, 
            MSF_GADGET_PROPERTY_FOCUS, 0)))
        {
            return FALSE;
        }
        /* Bind gadget to form */
        if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaMePropView.formHandle, 
            meaMePropView.contentGadgetHandle, &pos, 0))
        {
            return FALSE;
        } 
    }
    /* Title */
    (void)meaSetTitle(meaMePropView.formHandle, 
        MEA_GET_STR_ID(MEA_STR_ID_ME_TITLE), 0);
#endif /* WAP_SUPPORT */
    /* Display form */
    meaDisplayWindow(meaMePropView.formHandle, meaGetPosLeftTop());
    HDIa_widgetExtPaintDirectly();
    return TRUE;
}

/*! 
 * \brief Creates a string representation of a collection of recipients 
 *
 * \param items The collection of recipients
 * \return The string representation ("4 recipients"/"Mr. Foo Bar")
 *****************************************************************************/
static char *createRecipStr(MeaAddrItem *items)
{
    char *str;
    char *newStr;
    unsigned int count;
    if (NULL != items)
    {
        if ((count = meaAddrItemCount(items)) > 1)
        {
            if (count > MEA_CFG_MAX_RECIPIENT_ADDRESSES)
                count = MEA_CFG_MAX_RECIPIENT_ADDRESSES;  
            if (NULL == (str = meaGetStringFromHandle(MEA_GET_STR_ID(
                MEA_STR_ID_NO_OF_RECIPIENTS))))
            {
                return NULL;
            }

            newStr = MEA_ALLOC(strlen(str) + 1 + 4);
#ifdef WAP_SUPPORT
            sprintf(newStr, "%d%s", count, str);
#else
            sprintf(newStr, " %d%s", count, str);
#endif /* WAP_SUPPORT */
            /*lint -e{774} */
            MEA_FREE(str);
            return newStr;
        }
        else
        {
            str = (NULL != items->name) ? items->name: items->address;
            newStr = MEA_ALLOC(strlen(str) + 1);
            strcpy(newStr, str);
            return newStr;
        }
    }
    return NULL;
}

/*!
 * \brief Sets property view values.
 *
 * \param propItem A reference to a MeaMePropItem.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaMeSetPropertyValues(const MeaPropItem *propItem)
{
    char *str;
    if (0 != meaMePropView.formHandle)
    {
#ifdef WAP_SUPPORT
        ctk_screen_handle	scrid;
        scrid = HDIa_widgetCtkGetScreenHandle(meaMePropView.formHandle);
        ASSERT(scrid);
        /* To */
        str = createRecipStr(propItem->to);
		// please use ctk_remote_execute_in_UA
        ctk_inline_update_display_only_data(ctk_screen_get_layout(scrid), MEA_ME_PROP_VIEW_TO, (U8*) str, KAL_TRUE);
		//ctk_screen_invoke_redraw(scrid);
        MEA_FREE(str);
        /* Cc */
        str = createRecipStr(propItem->cc);
        ctk_inline_update_display_only_data(ctk_screen_get_layout(scrid), MEA_ME_PROP_VIEW_CC, (U8*) str, KAL_TRUE);
        MEA_FREE(str);
        /* Bcc */
        str = createRecipStr(propItem->bcc);
        ctk_inline_update_display_only_data(ctk_screen_get_layout(scrid), MEA_ME_PROP_VIEW_BCC, (U8*) str, KAL_TRUE);
        MEA_FREE(str);
#else
        /* To */
        str = createRecipStr(propItem->to);
        if (!meaSetStringGadgetValue(meaMePropView.toGadgetHandle, 
            MEA_GET_STR_ID(MEA_STR_ID_TO), str))
        {
            MEA_FREE(str);
            return FALSE;
        }
        MEA_FREE(str);
        /* Cc */
        str = createRecipStr(propItem->cc);
        if (!meaSetStringGadgetValue(meaMePropView.ccGadgetHandle,
            MEA_GET_STR_ID(MEA_STR_ID_CC), str))
        {
            MEA_FREE(str);
            return FALSE;
        }
        MEA_FREE(str);
        /* Bcc */
        str = createRecipStr(propItem->bcc);
        if (!meaSetStringGadgetValue(meaMePropView.bccGadgetHandle,
            MEA_GET_STR_ID(MEA_STR_ID_BCC), str))
        {
            MEA_FREE(str);
            return FALSE;
        }
        MEA_FREE(str);
        /* Subject */
        if (!meaSetStringGadgetValue(meaMePropView.subjectGadgetHandle, 
            MEA_GET_STR_ID(MEA_STR_ID_SUBJECT), propItem->subject))
        {
            return FALSE;
        }
#endif /* WAP_SUPPORT */
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*!
 * \brief Deletes the message property view.
 *****************************************************************************/
void meaMeDeletePropView()
{
    /* Delete window and handles */
    if (0 == meaMePropView.formHandle)
        return;
    (void)meaDeleteWindow(meaMePropView.formHandle);
#ifdef WAP_SUPPORT
    //editContentIsChanged = FALSE;
    MEA_FREE(strSlide);
    strSlide = NULL;
    MEA_FREE(strSlides);
    strSlides = NULL;
#else
    /* Delete gadgets */
    if (0 != meaMePropView.bccGadgetHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMePropView.bccGadgetHandle);
    }
    if (0 != meaMePropView.ccGadgetHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMePropView.ccGadgetHandle);
    }
    if (0 != meaMePropView.subjectGadgetHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMePropView.subjectGadgetHandle);
    }
    if (0 != meaMePropView.toGadgetHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMePropView.toGadgetHandle);
    }
    if (0 != meaMePropView.optionsGadgetHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMePropView.optionsGadgetHandle);
    }
    if (0 != meaMePropView.sendGadgetHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMePropView.sendGadgetHandle);
    }
    if (0 != meaMePropView.contentGadgetHandle)
    {
        (void)MSF_WIDGET_RELEASE(meaMePropView.contentGadgetHandle);
    }    
#endif /* WAP_SUPPORT */
    /* Delete obsolete handles */
    memset(&meaMePropView, 0, sizeof(MeaMePropView));
}

/*!
 * \brief Signal converter for the navigation menu.
 * 
 * \param actionType The type of action, MEA_NAV_ACTION_BACK or 
 *  MEA_NAV_ACTION_OK.
 *****************************************************************************/

static void navMenuSignalConverter(MeaNavAction actionType)
{
    MeaNavMenuItem item;
    
    if (actionType == MEA_NAV_ACTION_OK)
    {
        item = meaGetNavMenuItemNew();
#ifdef WAP_SUPPORT
		if (item.visibilityCallBack!=NULL)
		    (item.visibilityCallBack)(item.entryId);
#endif /* WAP_SUPPORT */
        (void)MEA_SIGNAL_SENDTO(item.fsm, item.sig);
    } /* if */
#ifdef WAP_SUPPORT
    else //Back should clear the fsm and signal
    {
        meaMeClearNavMenuSignal();
    }
    /* remove navigation menu */
    if (item.sig != MEA_SIG_ME_EDIT_PROPERTIES)
#endif /* WAP_SUPPORT */
    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_NAV_DEACTIVATE);
}

/*!
 * \brief Creates a navigation menu for the message editor. Only called from 
 *        the property view!
 * 
 * \return TRUE if the menu was created successfully, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaMeCreateNavMenu(MeaNavMenuItem *items)
{
    unsigned int i;
    
    /* Create navigation menu */
    if (!meaCreateNavMenu(0, navMenuSignalConverter))
    {
        meaRemoveNavMenu();
        return FALSE;
    }

    /* Add menu items */
    for (i = 0; items[i].strId != 0; i++)
    {
        if (!meaAddNavMenuItemNew(&items[i]))
        {
            meaRemoveNavMenu();
            return FALSE;
        }
    } /* for */

    /* Show the menu */
    if (!meaShowNavMenu())
    {
        meaRemoveNavMenu();
        return FALSE;
    }

    return TRUE;
}

/*!
 * \brief Deletes the navigation menu for the message editor.
 * 
 *****************************************************************************/
void meaMeDeleteNavMenu()
{
    meaRemoveNavMenu();
}

#ifndef WAP_SUPPORT
/*! \brief Handles OK actions from the addr 
 *
 * \param winHandle The window that the actin originates from.
 *****************************************************************************/
static void handleAddrInputOk(MsfWindowHandle winHandle)
{
    char *addr;
    MeaAddrType addrType;
    MeaAddrItem *item = NULL;

    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_LOW, MSF_MODID_MEA, 
        MAUIME_62DA68BE6F5B433379CA10D20D1725ED, "(%s) (%d) Addr input view [Ok] action received 0x(%x)", 
        __FILE__, __LINE__, winHandle));

#ifdef MEA_CFG_USE_EXT_PB
    if ((0 != meaMeAddrInputView.phoneBookHandle ) && 
        MSF_WIDGET_HAS_FOCUS(meaMeAddrInputView.phoneBookHandle))
    {
        /* Launch phone book */
        meaPbhLaunchPb((MSF_UINT16)meaMeAddrInputView.type);
        //PHB Jo 030806 mark this if not delete addr input window
        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_ADDR_INPUT_DEACTIVATE);
    }
    else 
#endif
    if ((0 != meaMeAddrInputView.textInputHandle) && 
        MSF_WIDGET_HAS_FOCUS(meaMeAddrInputView.textInputHandle))
    {
        if (NULL == (addr = 
            meaGetTextFromGadget(meaMeAddrInputView.textInputHandle)))
	    //ToDo: check numeric/e-mail format
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_ADDRESS),
                MEA_DIALOG_ERROR);
            return;
        }
        /* Verify entry */
        if (MEA_ADDR_TYPE_NONE == (addrType = meaGetAddrType(addr)))
        {
            (void)meaShowDialog(MEA_GET_STR_ID(MEA_STR_ID_INVALID_RECIP_ADDRESS), 
                MEA_DIALOG_ERROR);
            return;
        }
        /* Add item */
        if (!meaAddrItemInsert(&item, NULL, addrType, addr))
        {
            /*lint -e{774} */
            MEA_FREE(addr);
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_ADDR_INPUT_DEACTIVATE);
            return;
        }
        /*lint -e{774} */
        MEA_FREE(addr);
        /* */
        if (meaMeAddrInputView.editIndex == 0)
        {
            (void)MEA_SIGNAL_SENDTO_UP(MEA_ME_FSM, MEA_SIG_ME_ADD_RECEPIENTS, 
                meaMeAddrInputView.type, item);
        }
        else
        {
            (void)MEA_SIGNAL_SENDTO_UUP(MEA_ME_FSM, MEA_SIG_ME_CHANGE_RECEPIENT, 
                meaMeAddrInputView.type, 
                (unsigned)meaMeAddrInputView.editIndex - 1, item);
        }

        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_ADDR_INPUT_DEACTIVATE);
    }
}

/*! \brief Creates an address field input
 *
 * \param type The address field, #MEA_ME_TO, MEA_ME_CC or #MEA_ME_BCC.
 * \param item The item to display or NULL if it is a new item.
 * \param The index of the item to edit or 0 if it is a new item.
 *****************************************************************************/
MSF_BOOL meaMeCreateAddrInputView(MeaMeProperty type, const MeaAddrItem *item, 
    unsigned int editIndex)
{
    MsfPosition pos = {0, 0};
    MsfSize newSize = {0, 0};
    MsfStringHandle strHandle;
    unsigned int i;

    if (0 != meaMeAddrInputView.winHandle)
    {
        MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
            MAUIME_69F9AB7685FF1FE30B41E589C4750336, "(%s) (%d) The address list view instance is busy!\n", __FILE__, 
            __LINE__));
        return FALSE;
    }

    memset(&meaMeAddrInputView, 0, sizeof(MeaMeAddrInputView));
    meaMeAddrInputView.type = type;
    meaMeAddrInputView.editIndex = (int)editIndex;
    /* Create form*/
    if (0 == (meaMeAddrInputView.winHandle = MSF_WIDGET_FORM_CREATE(
        MSF_MODID_MEA, NULL, MSF_WINDOW_PROPERTY_TITLE, 0)))
    {
        return FALSE;
    }

    /* Create actions */
    if (0 == meaCreateAction(meaMeAddrInputView.winHandle, MsfOk, 
        handleAddrInputOk, 0, 0, MEA_STR_ID_OK))
    {
        return FALSE;
    }
    if (0 == meaCreateAction(meaMeAddrInputView.winHandle, MsfBack, 
        NULL, MEA_ME_FSM, MEA_SIG_ME_ADDR_INPUT_DEACTIVATE, MEA_STR_ID_BACK))
    {
        return FALSE;
    }
    /* String gadget to display in the input*/
    strHandle = 0;
    if ((editIndex != 0) && (NULL != item))
    {
        for(i = 0; (i != (editIndex - 1)) && (NULL != item); i++, 
            item = item->next)
            ;
        if ((NULL != item) && (item->address))
        {
            if (0 == (strHandle = MSF_WIDGET_STRING_CREATE(MSF_MODID_MEA, 
                item->address, MsfUtf8, (int)strlen(item->address) + 1, 
                0)))
            {
                return FALSE;
            }
        }
    }
    /* Create gadgets */
    /* Address input */
    if (0 == (meaMeAddrInputView.textInputHandle = 
        MSF_WIDGET_TEXT_INPUT_CREATE(MSF_MODID_MEA, 
        meaGetEmptyStringHandle(), strHandle, MsfText, 
        MEA_ME_MAX_ADDRESS_SIZE, TRUE, NULL, MSF_GADGET_PROPERTY_FOCUS, 0)))
    {
        if (0 != strHandle)
        {
            (void)MSF_WIDGET_RELEASE(strHandle);
        }
        return FALSE;
    }
    meaCalculateStringGadgetSize(meaMeAddrInputView.winHandle,
        meaMeAddrInputView.textInputHandle, strHandle, &pos, 
        (MsfSize*)&gadgetSize, &newSize, FALSE);    
    if (0 != strHandle)
    {
        /* Don't need it anymore */
        (void)MSF_WIDGET_RELEASE(strHandle);
    }
    (void)MSF_WIDGET_SET_SIZE(meaMeAddrInputView.textInputHandle, &newSize);
    
    /* Bind gadget to form */
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaMeAddrInputView.winHandle, 
        meaMeAddrInputView.textInputHandle, &pos, 0))
    {
        (void)MSF_WIDGET_RELEASE(meaMeAddrInputView.textInputHandle);
        return FALSE;
    } 

#ifdef MEA_CFG_USE_EXT_PB
    /* Launch phone book */
    pos.y += MEA_ME_GADGET_SPACING;

    if (0 == (meaMeAddrInputView.phoneBookHandle  = 
        MSF_WIDGET_STRING_GADGET_CREATE(MSF_MODID_MEA, 
        MEA_GET_STR_ID(MEA_STR_ID_PHONE_BOOK), NULL, TRUE, 
        MSF_GADGET_PROPERTY_FOCUS, 0)))
    {
        return FALSE;
    }
    /* Bind gadget to form */
    if (0 > MSF_WIDGET_WINDOW_ADD_GADGET(meaMeAddrInputView.winHandle, 
        meaMeAddrInputView.phoneBookHandle, &pos, 0))
    {
        return FALSE;
    } 
#endif
    /* Title */
    switch(type)
    {
    case MEA_ME_TO:
        (void)meaSetTitle(meaMeAddrInputView.winHandle, 
            MEA_GET_STR_ID(MEA_STR_ID_TO), 0);
        break;
    case MEA_ME_CC:
        (void)meaSetTitle(meaMeAddrInputView.winHandle, 
            MEA_GET_STR_ID(MEA_STR_ID_CC), 0);
        break;
    case MEA_ME_BCC:
    (void)meaSetTitle(meaMeAddrInputView.winHandle, 
            MEA_GET_STR_ID(MEA_STR_ID_BCC), 0);
        break;
    }

    /* Display form */
    return meaDisplayWindow(meaMeAddrInputView.winHandle, meaGetPosLeftTop());
}
#endif /* ~WAP_SUPPORT */

/*! \brief
 *
 * \param items The current list
 *****************************************************************************/
MSF_BOOL meaMeUpdateAddrListView(const MeaAddrItem *items)
{
    unsigned int i;
    MsfStringHandle strHandle;
    if (meaAddrItemCount(items) > 0)
    {
        if (0 != meaMeAddrListView.winHandle)
        {
            /* Delete old items */
#ifdef WAP_SUPPORT
	        meaMeAddrListView.items = (MeaAddrItem *)items;
            while(MSF_WIDGET_CHOICE_SIZE(meaMeAddrListView.winHandle) > 0)
                (void)MSF_WIDGET_CHOICE_REMOVE_ELEMENT(
                    meaMeAddrListView.winHandle, 0); //change 1(include Add reciep) to 0
#else
            while(MSF_WIDGET_CHOICE_SIZE(meaMeAddrListView.winHandle) > 1)
            {
                (void)MSF_WIDGET_CHOICE_REMOVE_ELEMENT(
                    meaMeAddrListView.winHandle, 1);
            }
#endif /* WAP_SUPPORT */
            /* Add items to the list */
            for(i = 1; NULL != items; i++, items = items->next)
            {
                if (0 == (strHandle = addrItemToStrHandle(items)))
                {
                    return FALSE;
                }
#ifdef WAP_SUPPORT
                if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaMeAddrListView.winHandle,
                    (int)i, strHandle, 0, meaGetListNumImage(i-1), 0, TRUE))
#else
                if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaMeAddrListView.winHandle,
                    (int)i, strHandle, 0, 0, 0, TRUE))
#endif /* WAP_SUPPORT */
                {
                    (void)MSF_WIDGET_RELEASE(strHandle);
                    return FALSE;
                }
                (void)MSF_WIDGET_RELEASE(strHandle);
            }
        }
    }
    else
    {
#ifdef WAP_SUPPORT
	    MeaMeProperty type=meaMeAddrListView.type;
#endif /* WAP_SUPPORT */
        meaMeDeleteAddrListView();
#ifdef WAP_SUPPORT
		//change to empty screen
		meaMeCreateAddrListEmptyDoneView(type);
#endif /* WAP_SUPPORT */
    }
    return TRUE;
}

/*! \brief Deletes the address input view
 *
 *****************************************************************************/
void meaMeDeleteAddrInputView(void)
{
    if (0 != meaMeAddrInputView.winHandle)
    {
        (void)meaDeleteWindow(meaMeAddrInputView.winHandle);
#ifdef MEA_CFG_USE_EXT_PB
        if (0 != meaMeAddrInputView.phoneBookHandle)
        {
            (void)MSF_WIDGET_RELEASE(meaMeAddrInputView.phoneBookHandle);
        }
#endif
        if (0 != meaMeAddrInputView.textInputHandle)
        {
            (void)MSF_WIDGET_RELEASE(meaMeAddrInputView.textInputHandle);
        }
        memset(&meaMeAddrInputView, 0, sizeof(MeaMeAddrInputView));
    }
}

#ifndef WAP_SUPPORT
/*! \brief Handles the event where the End User pressed [Ok] in address list
 *         view.
 *
 * \param winHandle
 *****************************************************************************/
static void handleAddrListOk(MsfWindowHandle winHandle)
{
    int editIndex;
    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA, 
        MAUIME_6E5991CCE1E874015B6F678D998837F4, "(%s) (%d) Ok action received in address list view.\n", __FILE__, 
        __LINE__, winHandle));

    if ((editIndex = meaGetSelectedChoiceIndex(meaMeAddrListView.winHandle)) 
        >= 0)
    {
        (void)meaMeCreateAddrInputView(meaMeAddrListView.type, 
            meaMeAddrListView.items, (unsigned)editIndex);
    }
    (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_ADDR_LIST_DEACTIVATE);
}
#endif /* ~WAP_SUPPORT */

/*! \brief Displays a list of addresses.
 *
 * \param type The address field to change.
 * \param items A list of items to display.
 * \return TRUE if successful, otherwise FALSE.
 *****************************************************************************/
MSF_BOOL meaMeCreateAddrListView(MeaMeProperty type, MeaAddrItem *items)
{
#ifdef WAP_SUPPORT
    if (0 == (meaMeAddrListView.backActHandle= MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA, //Option Jo
        MEA_GET_STR_ID(MEA_STR_ID_BACK), MsfBack, 0, MSF_ACTION_PROPERTY_ENABLED)))
#else
    MsfActionHandle selectAction;

    if (0 == (selectAction = MSF_WIDGET_ACTION_CREATE(MSF_MODID_MEA, 
        MEA_GET_STR_ID(MEA_STR_ID_EDIT), MsfSelect, 0, MSF_ACTION_PROPERTY_ENABLED)))
#endif /* WAP_SUPPORT */
    {
        return FALSE;
    }
    meaMeAddrListView.type  = type;
    meaMeAddrListView.items = items;

#ifdef WAP_SUPPORT
    if (0 == (meaMeAddrListView.winHandle = MSF_WIDGET_MENU_CREATE(
            MSF_MODID_MEA, MsfImplicitChoice, NULL, meaMeAddrListView.backActHandle, NULL,
            MSF_CHOICE_ELEMENT_STRING_1, 0, 0)))
    {
        (void)MSF_WIDGET_RELEASE(meaMeAddrListView.backActHandle);
        return FALSE;
    }
    if (!meaRegisterAction(meaMeAddrListView.winHandle, meaMeAddrListView.backActHandle, 
        NULL, MEA_ME_FSM, MEA_SIG_ME_ADDR_LIST_DEACTIVATE))
    {
        return FALSE;
    }
    if (!meaCreateAction(meaMeAddrListView.winHandle, MsfSelect, NULL, 
        MEA_ME_FSM, MEA_SIG_ME_ADDR_LIST_MENU_ACTIVATE, MEA_STR_ID_OPTIONS))
    {
        return FALSE;
    }
#else
    if (0 == (meaMeAddrListView.winHandle = MSF_WIDGET_MENU_CREATE(
            MSF_MODID_MEA, MsfImplicitChoice, NULL, selectAction, NULL,
            MSF_CHOICE_ELEMENT_STRING_1, 0, 0)))
    {
        (void)MSF_WIDGET_RELEASE(selectAction);
        return FALSE;
    }
    if (!meaRegisterAction(meaMeAddrListView.winHandle, selectAction, 
        handleAddrListOk, 0, 0))
    {
        return FALSE;
    }
    if (!meaCreateAction(meaMeAddrListView.winHandle, MsfBack, NULL, 
        MEA_ME_FSM, MEA_SIG_ME_ADDR_LIST_DEACTIVATE, MEA_STR_ID_BACK))
    {
        return FALSE;
    }
    //Jo 20031203 remove MsfMenu action and Add recipients item
    if (!meaCreateAction(meaMeAddrListView.winHandle, MsfMenu, NULL, 
        MEA_ME_FSM, MEA_SIG_ME_ADDR_LIST_MENU_ACTIVATE, 0))
    {
        return FALSE;
    }
    /* The "add recipients item" */
    if (0 > MSF_WIDGET_CHOICE_SET_ELEMENT(meaMeAddrListView.winHandle,
        0, MEA_GET_STR_ID(MEA_STR_ID_ADD_RECIPIENT_QUEST), 0, 0, 0, TRUE))
    {
        return FALSE;
    }
#endif /* WAP_SUPPORT */
    /* Insert the other items */
    if (!meaMeUpdateAddrListView(items))
    {
        return FALSE;
    }
    /* Set the title */
    (void)meaSetTitle(meaMeAddrListView.winHandle, 
        MEA_GET_STR_ID(MEA_STR_ID_RECIPIENTS), 0);

    return meaDisplayWindow(meaMeAddrListView.winHandle, meaGetPosLeftTop());
}

/*! \brief
 *
 *****************************************************************************/
void meaMeDeleteAddrListView(void)
{
    if (0 != meaMeAddrListView.winHandle)
    {
        (void)meaDeleteWindow(meaMeAddrListView.winHandle);
        meaMeAddrListView.winHandle = 0;
#ifdef WAP_SUPPORT
        meaMeAddrListView.items = NULL;
#endif /* WAP_SUPPORT */
    }
}

/*! \brief Action-handler for the address list navigation menu.
 *
 * \param action The type of action that was generated.
 *****************************************************************************/
static void addrListNavMenuHandler(MeaNavAction action)
{
    if (MEA_NAV_ACTION_OK == action)
    {
        if (MEA_ME_ADDR_LIST_DELETE == meaGetNavMenuItem())
        {
            /* Delete the current item */
#ifdef WAP_SUPPORT
            (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_DELETE_ADDR_ITEM,
                meaMeAddrListView.type, 
                (unsigned)(meaGetSelectedChoiceIndex(
                meaMeAddrListView.winHandle)));
            /* Set the title */
            MSF_WIDGET_SET_TITLE(meaMeAddrListView.backActHandle, 
               MEA_GET_STR_ID(MEA_STR_ID_DONE));
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, 
                MEA_SIG_ME_ADDR_LIST_MENU_DEACTIVATE);
#else
            (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_DELETE_ADDR_ITEM,
                meaMeAddrListView.type, 
                (unsigned)(meaGetSelectedChoiceIndex(
                meaMeAddrListView.winHandle) - 1));
#endif /* WAP_SUPPORT */
        }
#ifdef WAP_SUPPORT
        else if (MEA_ME_ADDR_LIST_ADD_NUMBER== meaGetNavMenuItem())
        {
            MeaInputItem item;
            memset(&item, 0, sizeof(MeaInputItem));
            item.text           = NULL;
            item.maxTextSize    = MEA_ME_MAX_ADDRESS_SIZE;
            item.type           = MEA_TEXT_INPUT;
            item.textType = MsfPhoneNumber;
            item.callback       = meaMeHandleAddrAdd;

            meaMeAddrListView.type = propType;

            /* Display the input form */
            if (!meaCreateInputForm(&item, MEA_GET_STR_ID(MEA_STR_ID_ADD_NUMBER)))
                return;
        }
        else if (MEA_ME_ADDR_LIST_ADD_EMAIL== meaGetNavMenuItem())
        {
            MeaInputItem item;
            memset(&item, 0, sizeof(MeaInputItem));
            item.text           = NULL;
            item.maxTextSize    = MEA_ME_MAX_EMAIL_ADDRESS_SIZE;
            item.type           = MEA_TEXT_INPUT;
            item.textType = MsfEmailAddress;
            item.callback       = meaMeHandleAddrAdd;

            meaMeAddrListView.type = propType;

            /* Display the input form */
            if (!meaCreateInputForm(&item, MEA_GET_STR_ID(MEA_STR_ID_ADD_EMAIL)))
                return;
        }
		else if (MEA_ME_ADDR_LIST_EDIT== meaGetNavMenuItem())
        {
            MeaInputItem item;
            /* String to display in the full editor*/
            int editIndex =meaGetSelectedChoiceIndex(meaMeAddrListView.winHandle);
            MeaAddrItem *addrItem = meaMeAddrListView.items;
            if (editIndex == -1)
				return;
            if ((editIndex > 0) && (NULL != addrItem))
            {
				int i;
                for(i = 0; (i != editIndex ) && (NULL != addrItem); i++, 
                    addrItem = addrItem->next)
                    ;
             }
        
            memset(&item, 0, sizeof(MeaInputItem));
            item.text           = addrItem->address;
            item.uintValue= (unsigned int)editIndex;
            item.maxTextSize    = MEA_ME_MAX_ADDRESS_SIZE;
            item.type           = MEA_TEXT_INPUT;
            if (addrItem->addrType == MEA_ADDR_TYPE_PLMN)
            {
                item.maxTextSize    = MEA_ME_MAX_ADDRESS_SIZE;
                item.type           = MEA_TEXT_INPUT;
                item.textType = MsfPhoneNumber;
            }
            else
            {
                item.maxTextSize    = MEA_ME_MAX_EMAIL_ADDRESS_SIZE;
                item.type           = MEA_TEXT_INPUT;
                item.textType = MsfEmailAddress;//MsfEmailAddress;
            }
            item.callback       = meaMeHandleAddrEdit;
            /* Display the input form */
            if (!meaCreateInputForm(&item, MEA_GET_STR_ID(MEA_STR_ID_EDIT)))
                return;
        }
		
        //Jo 20031202 Delete All
		else if (MEA_ME_ADDR_LIST_DELETE_ALL== meaGetNavMenuItem())
        {
            /* Delete all items */
            (void)MEA_SIGNAL_SENDTO_UU(MEA_ME_FSM, MEA_SIG_ME_DELETE_ADDR_ITEM,
                meaMeAddrListView.type, 
                (unsigned long)-1); //use -1 as delete all flag
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, 
                MEA_SIG_ME_ADDR_LIST_MENU_DEACTIVATE);
        }
#else
        else if (MEA_ME_ADDR_LIST_BACK == meaGetNavMenuItem())
        {
            /* Deactivate all */
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, 
                MEA_SIG_ME_ADDR_LIST_DEACTIVATE);
            (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, 
                MEA_SIG_ME_ADDR_LIST_MENU_DEACTIVATE);
        }
#endif /* WAP_SUPPORT */
    }
    else if (MEA_NAV_ACTION_BACK == action)
    {
        (void)MEA_SIGNAL_SENDTO(MEA_ME_FSM, MEA_SIG_ME_ADDR_LIST_MENU_DEACTIVATE);
    }
}

/*! \brief Creates a navigation menu for the address list view
 *
 *****************************************************************************/
MSF_BOOL meaMeCreateAddrListMenu(void)
{
#ifdef WAP_SUPPORT
	unsigned int addrCount = meaAddrItemCount(meaMeAddrListView.items);
    if (!meaCreateNavMenu(MEA_GET_STR_ID(MEA_STR_ID_OPTIONS), addrListNavMenuHandler))
        return FALSE;
    else if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_NUMBER), 
          MEA_ME_ADDR_LIST_ADD_NUMBER))
        return FALSE;
    else if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_ADD_EMAIL), 
          MEA_ME_ADDR_LIST_ADD_EMAIL))
        return FALSE;
	if (addrCount>0)
    {
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_EDIT), 
              MEA_ME_ADDR_LIST_EDIT))
            return FALSE;
    
        if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE), 
              MEA_ME_ADDR_LIST_DELETE))
            return FALSE;
        HDIa_widgetExtChoiceSetElemFlag(meaGetNavMenuHandle(), 
            MEA_ME_ADDR_LIST_DELETE, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);        
    }
    if (addrCount>1)
    {
    	if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE_ALL), 
              MEA_ME_ADDR_LIST_DELETE_ALL))
        	return FALSE;
        HDIa_widgetExtChoiceSetElemFlag(meaGetNavMenuHandle(), 
            MEA_ME_ADDR_LIST_DELETE_ALL, WIDGET_EXT_CHOICE_ELEM_NO_RIGHT_ARROW);        
    }
    if (!meaShowNavMenu())
#else
    if (!meaCreateNavMenu(meaGetEmptyStringHandle(), addrListNavMenuHandler))
    {
        return FALSE;
    }
    else if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_DELETE), 
        MEA_ME_ADDR_LIST_DELETE))
    {
        return FALSE;
    }
    else if (!meaAddNavMenuItem(MEA_GET_STR_ID(MEA_STR_ID_BACK), 
        MEA_ME_ADDR_LIST_BACK))
    {
        return FALSE;
    }
    else if (!meaShowNavMenu())
#endif /* WAP_SUPPORT */
    {
        return FALSE;
    }
    return TRUE;
}

/*! \brief Deletes the navigation menu for the address list view
 *
 *****************************************************************************/
void meaMeDeleteAddrListMenu(void)
{
    meaRemoveNavMenu();
}

/*!
 * \brief Returns 
 * \return TRUE if the property view is active
 *****************************************************************************/
MSF_BOOL meaUiMeIsPropertyViewActive(void)
{
    return (0 != meaMePropView.formHandle);
} /* meaUiMeIsPropertyViewActive */

/*!
 * \brief Returns 
 * \return TRUE if there is an invalid number removed
*****************************************************************************/
MSF_BOOL meaMeGetNumberValidFlag(void)
{
    return meaNumberValidFlag;
} /*meaMeGetNumberValidFlag*/

