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
 * widget_test.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Test code of widget library (default disabled)
 * 
 * Author:
 * -------
 * -------
 *
 *==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Replace WIN32 with __MTK_TARGET__
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

/*
 * Expected test items:
 * * o MMI interaction (popup MMI window)
 * * o Out-of-Memory
 * * o Out-of-Memory when using CTK
 * * o encoding
 * * o stress test (e.g. pressing a key very fast)
 * * o boundary value (e.g. input length)
 * * o external queue size (e.g. reading a large image, it might write filesystem and cause blocking)
 * *
 * * Ideas:
 * * o Simple key macro (written as C array)
 * * o Write menu tree as array
 * *
 * * What we can not do here:
 * * o END key test
 * *
 */

#include "widget.h"

#ifdef WIDGET_UNIT_TEST

#include "MessagesResourceData.h"


/*****************************************************************************
 * FUNCTION
 *  widget_test_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MsfScreenHandle x_screen = 0;
    static MsfWindowHandle x_w = 0;
    static MsfActionHandle x_ok;
    static MsfActionHandle x_cancel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* We don't use editor for now, so we need to inject code to test it */
    if (x_w == 0)
    {
        MsfPosition pos = {0, 0};
        char *text = "This is a test";
        MsfStringHandle textStringHandle = HDIa_widgetStringCreate(
                                            MSF_MODID_WIDGET,
                                            text,
                                            MsfUtf8,
                                            (int)strlen(text) + 1,
                                            0);

        x_w = HDIa_widgetEditorCreate(
                MSF_MODID_WIDGET,
                HDIa_widgetStringGetPredefined(MEA_STR_ID_EMPTY_STRING),
                textStringHandle,
                MsfUrl,
                100,
                FALSE,
                NULL,
                MSF_WINDOW_PROPERTY_TITLE,
                0);

        x_screen = HDIa_widgetScreenCreate(MSF_MODID_WIDGET, 0, 0);

        x_ok = HDIa_widgetActionCreate(
                MSF_MODID_WIDGET,
                HDIa_widgetStringGetPredefined(BRA_STR_ID_OK),
                MsfSelect,
                1,
                0x8000);
        x_cancel = HDIa_widgetActionCreate(
                    MSF_MODID_WIDGET,
                    HDIa_widgetStringGetPredefined(BRA_STR_ID_CANCEL),
                    MsfBack,
                    1,
                    0x8000);

        HDIa_widgetAddAction(x_w, x_ok);
        HDIa_widgetAddAction(x_w, x_cancel);

        HDIa_widgetScreenAddWindow(x_screen, x_w, &pos, 0, 0);
    }
    HDIa_widgetSetInFocus(x_screen, TRUE);
}

extern MsfScreenHandle meaGetScreenHandle(void);

static MsfScreenHandle widget_test_screen;

static const MsfPosition posLeftTop = {0, 0};


/*****************************************************************************
 * FUNCTION
 *  widget_test_sound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_sound(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //      MsfSoundHandle  widget_snd;
    //      widget_snd = HDIa_widgetSoundCreate(MSF_MODID_WIDGET, (char *) widget_test_aud, MsfMidi, sizeof(widget_test_aud), KAL_FALSE);
    //      HDIa_widgetSoundPlay(widget_snd);
    //      widget_snd = HDIa_widgetSoundGetPredefined(11);
    //      HDIa_widgetSoundPlay(widget_snd);
    HDIa_widgetSoundPlayPredefined(MsfSound_1);
    HDIa_widgetExtShowPopup(MSF_MODID_MEA, 0, MsfInfo, 0);

}


/*****************************************************************************
 * FUNCTION
 *  widget_test_create_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_create_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (widget_test_screen == 0)
    {
        widget_test_screen = HDIa_widgetScreenCreate(MSF_MODID_WIDGET, 0, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_make_disk_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_make_disk_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    {
        /* TEST */
        char filename[128];
        int i = 0;
        int fd;

        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        for (;;)
        {
            sprintf(filename, "/public/%d.tmp", i++);
            fd = HDIa_fileOpen(MSF_MODID_MSM, filename, HDI_FILE_SET_CREATE | HDI_FILE_SET_RDWR, 1024 * 256);
            if (fd < 0)
            {
                break;
            }
            HDIa_fileClose(fd);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_widgetExtShowPopup(MSF_MODID_WIDGET, HDIa_widgetStringGetPredefined(MEA_STR_ID_DONE), MsfPromptSaveDone, 0);
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_popup2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_popup2(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_waiting_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_waiting_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* tmp run in MEA */
    MsfWindowHandle wnd = HDIa_widgetExtCreateWaitView(MSF_MODID_MEA, WIDGET_STR_ID_OPTION);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_widgetScreenAddWindow(meaGetScreenHandle(), wnd, (MsfPosition*) & posLeftTop, 0, 0);
    HDIa_widgetSetInFocus(meaGetScreenHandle(), TRUE);
    HDIa_widgetSetInFocus(wnd, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_progress_view_cancel_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_progress_view_cancel_hdlr(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfWindowHandle wnd = HDIa_widgetCtkGetWindow(scrid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_widgetRemove(meaGetScreenHandle(), wnd);
    HDIa_widgetRelease(wnd);
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_progress_view
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_progress_view(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* tmp run in MEA */
    ctk_screen_handle scrid;
    MsfWindowHandle wnd = HDIa_widgetExtCreateProgressView(MSF_MODID_MEA, STR_GLOBAL_OK, WAP_IMAGE_WAP_LOGO, KAL_FALSE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_widgetExtSetProgressPercentage(
        wnd,
        0,
        HDIa_widgetExtStringGetPredefinedUCS2buffer(MEA_STR_ID_READING_MSG),
        (kal_uint8*) L"25%");
    scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    ctk_screen_addRSK_UA(scrid, MEA_STR_ID_CANCEL, 0, NULL, widget_test_progress_view_cancel_hdlr, KAL_TRUE);

    HDIa_widgetScreenAddWindow(meaGetScreenHandle(), wnd, (MsfPosition*) & posLeftTop, 0, 0);
    HDIa_widgetSetInFocus(meaGetScreenHandle(), TRUE);
    HDIa_widgetSetInFocus(wnd, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_list_menu_ok_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrid       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_list_menu_ok_hdlr(ctk_screen_handle scrid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfWindowHandle wnd = HDIa_widgetCtkGetWindow(scrid);

#ifndef __MTK_TARGET__
    int index = HDIa_widgetExtListMenuGetHilighted(wnd);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    printf("highlight %d\n", index);
#endif /* __MTK_TARGET__ */ 

    HDIa_widgetRemove(meaGetScreenHandle(), wnd);
    HDIa_widgetRelease(wnd);
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_list_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_list_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ctk_string_id str_item_list[3] = {MEA_STR_ID_ADD_EMAIL, MEA_STR_ID_ADD_IMAGE, MEA_STR_ID_ADD_NUMBER};
    ctk_image_id img_item_list[3] = {WAP_IMAGE_SW_LIST_NB1, WAP_IMAGE_SW_LIST_NB2, WAP_IMAGE_SW_LIST_NB3};
    char *hint_list[3] = { "Hello", NULL, "Lala" };
    MsfWindowHandle wnd;
    ctk_screen_handle scrid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wnd = HDIa_widgetExtCreateListMenu(
            MSF_MODID_MEA,
            STR_GLOBAL_OK,
            0,
            3,
            str_item_list,
            img_item_list,
            (kal_uint8 **) hint_list,
            KAL_TRUE);

    scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    ctk_screen_addLSK_UA(scrid, MEA_STR_ID_OK, 0, NULL, widget_test_list_menu_ok_hdlr, KAL_TRUE);

    HDIa_widgetScreenAddWindow(meaGetScreenHandle(), wnd, (MsfPosition*) & posLeftTop, 0, 0);
    HDIa_widgetSetInFocus(meaGetScreenHandle(), TRUE);
    HDIa_widgetSetInFocus(wnd, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_form
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_form(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfWindowHandle wnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wnd = HDIa_widgetFormCreate(MSF_MODID_MEA, NULL, 0x8000, 0);
    HDIa_widgetExtFormSetSmilTotalTime(wnd, 30);
    HDIa_widgetExtFormSetSmilRemainTime(wnd, 5);

    HDIa_widgetScreenAddWindow(meaGetScreenHandle(), wnd, (MsfPosition*) & posLeftTop, 0, 0);
    HDIa_widgetSetInFocus(meaGetScreenHandle(), TRUE);
    HDIa_widgetSetInFocus(wnd, TRUE);

    HDIa_widgetExtFormSetArrowIndication(wnd, 1, 1, 1, 1);
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_fmgr_input_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathname        [IN]        
 *  arg             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_fmgr_input_done_hdlr(const char *pathname, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_system_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_system_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_widgetExtRegisterSystemMsg(MSF_MODID_MEA, MEA_STR_ID_MMS, MEA_STR_ID_PANIC);
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_fmgr_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_fmgr_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_widgetExtFmgrMediaInput("audio/midi ", widget_test_fmgr_input_done_hdlr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_write_OMA_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_write_OMA_content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //extern void MMS_write_OMA_content_to_download_path(void);
    //MMS_write_OMA_content_to_download_path();
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_message_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_message_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* tmp run in MEA */
    widget_string_pack_struct msg1, msg2;
    MsfWindowHandle wnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg1.type = WIDGET_STRING_PACK_ID;
    msg1._u.id = BRA_STR_ID_SAVING;
    msg2.type = WIDGET_STRING_PACK_UCS2;
    msg2._u.ucs2 = (kal_uint8*) L"testing ";

    wnd = HDIa_widgetExtCreateMessageInd(MSF_MODID_MEA, msg1, msg2, IMG_NEW_MESSAGE_NOTIFICATION_MSG);

    // scrid = HDIa_widgetCtkGetScreenHandle(wnd);
    // ctk_screen_addRSK_UA(scrid, MEA_STR_ID_CANCEL, 0, NULL, widget_test_progress_view_cancel_hdlr, KAL_TRUE);

    HDIa_widgetScreenAddWindow(meaGetScreenHandle(), wnd, (MsfPosition*) & posLeftTop, 0, 0);
    HDIa_widgetSetInFocus(meaGetScreenHandle(), TRUE);
    HDIa_widgetSetInFocus(wnd, TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_big5
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_big5(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char str_big5[] = "¤¤¤å´ú¸Õ";
    char buf[64], buf2[64];
    kal_int32 srcLen, dstLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srcLen = 8;
    dstLen = 64;
    HDIa_widgetExtBig5ToUTF8((const kal_uint8*)str_big5, &srcLen, (kal_uint8*) buf, &dstLen);
    srcLen = dstLen;
    dstLen = 64;
    HDIa_widgetExtUTF8ToBig5((const kal_uint8*)buf, &srcLen, (kal_uint8*) buf2, &dstLen);
    buf2[dstLen] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  widget_test_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    HDIa_widgetExtEnterDeleteAllScreenNoInterrupt();
    for (i = 0; i < 100000; i++)
    {
        HDIa_widgetExtGiveControlToMMI();
    }
    /* HDIa_widgetExtGoBackToWidgetScreen(); */
}

#include "gdi_image.h"


/*****************************************************************************
 * FUNCTION
 *  widget_test_gdi_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_test_gdi_image(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef GDI_UNIT_TEST
    gdi_unit_test_image_decoder(0);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  widget_start_unit_test
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_start_unit_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#endif /* WIDGET_UNIT_TEST */ 

#ifdef WIDGET_TEST_OUT_OF_MEMORY
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stack_msgs.h"
#include "app_buff_alloc.h"
#include "gv.h"
#include "tst_def.h"


/*****************************************************************************
 * FUNCTION
 *  widget_simulate_out_of_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void widget_simulate_out_of_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*
     * 2004.03.13 Setjmp() is  done in wap_task_main, but the key hander is invoked
     * * from MMI task. As a result, we cannot longjmp() here.
     */
    // TODO: This must be changed if key events are delivered from MMI task
    ilm_struct *ilm_ptr;
    tst_inject_string_struct *inject_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inject_str = (tst_inject_string_struct*) construct_local_para(sizeof(tst_inject_string_struct), TD_CTRL);
    inject_str->index = 9;
    inject_str->string[0] = inject_str->string[1] = 0;

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->msg_id = MSG_ID_TST_INJECT_STRING;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) inject_str;
    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}

#endif /* WIDGET_TEST_OUT_OF_MEMORY */ 

