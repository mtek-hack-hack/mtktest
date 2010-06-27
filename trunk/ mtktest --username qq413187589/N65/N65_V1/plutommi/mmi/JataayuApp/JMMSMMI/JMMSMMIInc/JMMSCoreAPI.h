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
 * JMMSCoreAPI.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
#ifndef JMMS_CORE_APIS_H
#define JMMS_CORE_APIS_H

#include "ddlbase.h"
#include "jcerror.h"
#include "jcevent.h"
#include "jcutils.h"
#include "jdd_MMIdatatype.h"
#include "MessagingDataTypes.h"
#include "MessagingAPI.h"

#define mmi_jmms_jdi_msg_init(hmsg_p,callback_arg_p)                    \
               jdi_MsgInit (hmsg_p,callback_arg_p)

#define mmi_jmms_jdi_message_deinit(hMsg)                                \
               jdi_MsgDeInit (hMsg)

#define mmi_jmms_jdi_set_msg_type( hMsg, eMessageType)                     \
               jdi_MsgSetMessagingType (hMsg,   eMessageType)

#define mmi_jmms_jdi_get_msg_type( hMsg, eMessagingType)                \
               jdi_MsgGetMessagingType (hMsg,eMessagingType)

#define mmi_jmms_jdi_add_media(hMsg, pMediaInfo, ucPageIndex, pMediaID)       \
               jdi_MsgAddMedia (hMsg,pMediaInfo,ucPageIndex, pMediaID)

#define mmi_jmms_jdi_update_inline_text(hMsg, pTextBuffer, uiBufferLen,       \
                            ucPageIndex, uiMediaID)                           \
               jdi_MsgUpdateInlineText (hMsg,pTextBuffer,uiBufferLen,ucPageIndex,uiMediaID)

#define mmi_jmms_jdi_delete_media(hMsg, ucPageIndex, uiMediaID,  bIsAttachment)  \
               jdi_MsgDeleteMedia (hMsg,ucPageIndex,uiMediaID,bIsAttachment)

#define mmi_jmms_jdi_msg_compose(phMsg, eMessagingType, pEncapsulatedContent) \
               jdi_MsgCompose (phMsg,eMessagingType,pEncapsulatedContent)

#define mmi_jmms_jdi_get_media_list(hMsg, ucPageIndex, ppMediaInfo,           \
                               pMediaCount, bIsAttachment)                    \
               jdi_MsgGetMediaList (hMsg,ucPageIndex,ppMediaInfo,pMediaCount,bIsAttachment)

#define mmi_jmms_jdi_get_presentation_info(hMsg, ucPageIndex, uiMediaID,      \
                               pPresentationInfo)                             \
               jdi_MsgGetMediaPresentationInfo (hMsg,ucPageIndex,uiMediaID,pPresentationInfo)

#define  mmi_jmms_jdi_get_media_mime_info(hMsg,ucPageIndex,uiMediaID,pMimeInfo,bIsAttachment)   \
               jdi_MsgGetMediaMimeInfo (hMsg,ucPageIndex,uiMediaID,pMimeInfo,bIsAttachment)

#define  mmi_jmms_jdi_set_media_presentation_info(hMsg,ucPageIndex,uiMediaID,pPresentationInfo) \
               jdi_MsgSetMediaPresentationInfo (hMsg,ucPageIndex,uiMediaID,pPresentationInfo)

#define mmi_jmms_jdi_get_media_count(hMsg, ucPageIndex, pMediaCount,bIsAttachment)                    \
               jdi_MsgGetMediaCount (hMsg, ucPageIndex,pMediaCount,bIsAttachment)

#define mmi_jmms_jdi_set_creation_mode(hMsg, eCreationMode)                \
               jdi_MsgSetCreationMode (hMsg, eCreationMode)

#define mmi_jmms_jdi_get_creation_mode(hMsg, pCreationMode)                \
               jdi_MsgGetCreationMode (hMsg, pCreationMode)

#define mmi_jmms_jdi_set_content_class(hMsg, eContentClass)                \
               jdi_MsgSetContentClass (hMsg, eContentClass)

#define mmi_jmms_jdi_get_content_class(hMsg, pContentClass)                \
               jdi_MsgGetContentClass (hMsg, pContentClass)

#define mmi_jmms_jdi_set_msg_size(hMsg, uiMaxMsgSize)                   \
               jdi_MsgSetMaxSize (hMsg, uiMaxMsgSize)

#define mmi_jmms_jdi_get_max_size(hMsg, pMaxMsgSize)                    \
               jdi_MsgGetMaxSize (hMsg, pMaxMsgSize)

#define mmi_jmms_jdi_set_max_pages(hMsg, ucMaxPages)                    \
               jdi_MsgSetMaxPages (hMsg,ucMaxPages)

#define mmi_jmms_jdi_get_max_pages(hMsg, pMaxPages)                        \
               jdi_MsgGetMaxPages (hMsg, pMaxPages)

#define mmi_jmms_jdi_add_page(hMsg, ucPageIndex)                        \
               jdi_MsgAddPage (hMsg, ucPageIndex)

#define mmi_jmms_jdi_swap_page(hMsg, ucSrcPageIndex, ucTargetPageIndex);      \
               jdi_MsgSwapPage (hMsg, ucSrcPageIndex, ucTargetPageIndex)

#define mmi_jmms_jdi_move_page(hMsg, ucSrcIndex, ucDestIndex)              \
               jdi_MsgMovePage (hMsg, ucSrcIndex, ucDestIndex)

#define mmi_jmms_jdi_delete_page(hMsg, ucPageIndex)                        \
               jdi_MsgDeletePage (hMsg, ucPageIndex)

#define mmi_jmms_jdi_set_page_timer(hMsg, ucPageIndex, uiDuration)            \
               jdi_MsgSetPageTimer (hMsg,ucPageIndex,uiDuration)

#define mmi_jmms_jdi_get_page_timer(hMsg, ucPageIndex, pDuration)          \
               jdi_MsgGetPageTimer (hMsg,ucPageIndex,pDuration)

#define mmi_jmms_jdi_get_total_pages(hMsg,  pPageCount)                    \
               jdi_MsgGetTotalPages (hMsg, pPageCount)

#define mmi_jmms_jdi_get_current_page_index(hMsg,  pPageIndex)             \
               jdi_MsgGetCurrentPageIndex (hMsg,pPageIndex)

#define mmi_jmms_jdi_get_page_info(hMsg,  ucPageIndex, ppPageInfo)            \
               jdi_MsgGetPageInfo (hMsg, ucPageIndex,ppPageInfo)

#define mmi_jmms_jdi_set_media_timer(hMsg, ucPageIndex, uiMediaID, MediaTimer)   \
               jdi_MsgSetMediaTimer (hMsg,ucPageIndex,uiMediaID,MediaTimer)

#define mmi_jmms_jdi_get_media_timer(hMsg, ucPageIndex, uiMediaID, pMediaTimer)  \
               jdi_MsgGetMediaTimer(hMsg,ucPageIndex, uiMediaID, pMediaTimer)

#define mmi_jmms_jdi_get_size(hMsg, ucPageIndex, pSize)                    \
               jdi_MsgGetSize (hMsg,ucPageIndex,pSize)

#define mmi_jmms_jdi_set_presentation_type(hMsg, ePresentationType)           \
               jdi_MsgSetPresentationType (hMsg, ePresentationType)

#define mmi_jmms_jdi_get_presentation_type(hMsg, pPresentationType)           \
               jdi_MsgGetPresentationType (hMsg, pPresentationType)

#define mmi_jmms_jdi_set_smil_root_layout(hMsg, uiHeight, uiWidth, pBGColor)  \
               jdi_MsgSetSMILRootLayout (hMsg,uiHeight,uiWidth,pBGColor)

/* /// */

#define mmi_jmms_jdi_get_smil_root_layout(hMsg, pHeight, pWidth, ppBGColor)      \
               jdi_MsgGetSMILRootLayout(hMsg,pHeight,pWidth,ppBGColor)

#define mmi_jmms_jdi_add_smil_region_layout(hMsg, pRegionLayout)           \
               jdi_MsgAddSMILRegionLayout (hMsg, pRegionLayout)
#ifdef FIT_REGION_HANDLING_SUPPORT
#define mmi_jmms_jdi_smil_create_check(hMsg, pRegionLayout)          \
            jdi_SMILCreatecheck(hMsg, pRegionLayout)
#endif /* FIT_REGION_HANDLING_SUPPORT */ 
#define mmi_jmms_jdi_delete_smil_region_layout(hMsg, pRegionName)          \
               jdi_MsgDeleteSMILRegionLayout (hMsg,pRegionName)

#define mmi_jmms_jdi_get_smil_region_layout(hMsg, ppRegionLayout)          \
               jdi_MsgGetSMILRegionLayout (hMsg,ppRegionLayout)

#define mmi_jmms_jdi_msg_view(hMsg, pContent)                           \
               jdi_MsgView (hMsg, pContent)

#define mmi_jmms_jdi_msg_forward(hMsg, pContent,phNewMsgHandle)               \
               jdi_MsgForward (hMsg, pContent,phNewMsgHandle)

#define mmi_jmms_jdi_msg_reply(hMsg, pContent, bReplyAll, phNewMsgHandle)     \
               jdi_MsgReply (hMsg,pContent,bReplyAll,phNewMsgHandle)

#define mmi_jmms_jdi_view_event(hMsg, eEventType, pEventData)              \
               jdi_MsgViewHandleEvent (hMsg, eEventType,pEventData)

#define mmi_jmms_jdi_get_active_media_info(hMsg, pActiveMediaInfo)            \
               jdi_MsgGetActiveMediaInfo (hMsg,pActiveMediaInfo)

#define mmi_jmms_jdi_msg_register_callback(hMSg, eCallbackType, pCallbackFunction)\
               jdi_MsgRegisterCallbacks (hMSg, eCallbackType,pCallbackFunction)

/* ///// */
#define mmi_jmms_jdi_encapsulate_buffer(hMsg, pEncapsulatedContent)           \
               jdi_MsgGetEncapsulatedBuffer (hMsg, pEncapsulatedContent)

#define mmi_jmms_jdi_parse_msg_buffer(phMsg, pEncapsulatedContent,eMessagingType, bWithMedia)            \
               jdi_MsgParseEncapsulatedBuffer (phMsg,pEncapsulatedContent,eMessagingType,bWithMedia)

#define mmi_jmms_jdi_set_msg_headers(hMsg, pMsgHeaders)                    \
               jdi_MsgSetMessageHeaders (hMsg,pMsgHeaders)

#define mmi_jmms_jdi_get_msg_headers(hMsg, ppMsgHeaders)                   \
               jdi_MsgGetMessageHeaders (hMsg,ppMsgHeaders)

#define mmi_jmms_jdi_set_encoding_type(hMsg, eIsTextEncoding)                 \
               jdi_MsgSetEncodingType (hMsg,eIsTextEncoding)

#define mmi_jmms_jdi_store_init(phStore)                                \
               jdi_StoreInit (phStore)

#define mmi_jmms_jdi_get_folders(hStore, ppFolderList)                     \
               jdi_StoreGetFolders (hStore,ppFolderList)

#define mmi_jmms_jdi_create_folder(hStore, pFolderName, uhCategory)           \
               jdi_StoreCreateFolder (hStore, pFolderName,uhCategory)

#define mmi_jmms_jdi_rename_folder(hStore, pSrcFolderName, pDestFolderName, uhCategory)         \
               jdi_StoreRenameFolder (hStore, pSrcFolderName, pDestFolderName, uhCategory)

/* /// */
#define mmi_jmms_jdi_delete_folder(hStore, uhCategory)                        \
               jdi_StoreDeleteFolder (hStore,uhCategory)

#define mmi_jmms_jdi_set_active_folder(hStore, pFolderName)                \
               jdi_StoreSetActiveFolder (hStore,pFolderName)

#define mmi_jmms_jdi_get_active_folder(hStore, ppcFolder,   puhCategory)         \
               jdi_StoreGetActiveFolder (hStore,ppcFolder,puhCategory)

#define mmi_jmms_jdi_get_msg(hStore, uiMsgIndex, pMsgContent)                 \
               jdi_StoreGetMsgFromStore (hStore,uiMsgIndex,pMsgContent)

#define mmi_jmms_jdi_get_msg_list(hStore, ppMessageList, pRetrieveFilters)    \
               jdi_StoreGetMsgList (hStore, ppMessageList,pRetrieveFilters)

#define mmi_jmms_jdi_sort_msg_list(hStore, SortInfo)                       \
               jdi_StoreSortMsgList (hStore, SortInfo)

#define mmi_jmms_jdi_delete_msg(hStore, uiMsgIndex)                           \
               jdi_StoreDeleteMsg (hStore,uiMsgIndex)

#define mmi_jmms_jdi_move_msg(hStore, uiMessageIndex, pDestFolder, extra_bytes)               \
               jdi_StoreMoveMsg (hStore,uiMessageIndex,pDestFolder, extra_bytes)

#define mmi_jmms_jdi_update_msg(hStore, uiMsgIndex,   pMsgHeaders, pMsgContent, uiExtraBytes)     \
               jdi_StoreUpdateMsg (hStore,uiMsgIndex,pMsgHeaders,pMsgContent, uiExtraBytes)

#define mmi_jmms_jdi_update_msg_list(hStore, bflag)                           \
               jdi_StoreUpdateMsgList(hStore,bflag)

/* //// */
#define mmi_jmms_jdi_save_msg(hStore, pFolderName, uhCategory,pMsgHeaders,    \
                     pMsgContent, pMsgIndex ,uiExtraBytes)                    \
               jdi_StoreSaveMsg(hStore,pFolderName,uhCategory,pMsgHeaders,pMsgContent,pMsgIndex,uiExtraBytes)

#define mmi_jmms_jdi_delete_multiple_msgs(h_store, msg_index_Arr_p, msg_count)      \
               jdi_StoreDeleteMultipleMsgs (h_store, msg_index_Arr_p,msg_count)

#define mmi_jmms_jdi_add_rcv_filter(h_store, recv_filters_p)                  \
               jdi_StoreAddReceiveFilters (h_store, recv_filters_p)

#define mmi_jmms_jdi_store_get_rcv_filters(h_store, recv_filters_p)           \
               jdi_StoreGetReceiveFilters (h_store, recv_filters_p)

#define mmi_jmms_jdi_store_delete_folder(h_store)                          \
               jdi_StoreDeleteFilter (h_store)

#define mmi_jmms_jdi_store_set_active_folder(h_store, filter_name_p)          \
               jdi_StoreSetActiveFilter (h_store, filter_name_p)

#define mmi_jmms_jdi_store_get_active_folder(h_store, pp_filter_name)            \
               jdi_StoreGetActiveFilter (h_store,pp_filter_name)

#define mmi_jmms_jdi_store_dinit(h_store)                               \
               jdi_StoreDeinit (h_store)

#define mmi_jmms_jdi_store_restore(h_store)                                \
               jdi_StoreRestoreFolderInfo (h_store)

#define mmi_jmms_jdi_validate_filters(h_store, msg_headers_p)                 \
               jdi_MsgValidateFilters (h_store, msg_headers_p)
/* /// */

#define mmi_jmms_store_jdi_delete_all_msg(h_store)    \
               jdi_StoreDeleteAllMsgs (h_store)

#define mmi_jmms_store_jdi_sync_files(h_store)    \
               jdi_StoreSyncFiles (h_store)

#define mmi_jmms_jdi_msg_encapsulate_continue(hmsg)    \
               jdi_MsgEncapsulateContinue (hmsg)

#define mmi_jmms_jdi_msg_parse_continue(hmsg)    \
               jdi_MsgParseContinue (hmsg)

#define mmi_jmms_jdi_fit_content_class(hMsg, eContentClass)    \
               jdi_MsgFitToContentClass (hMsg, eContentClass)

#define mmi_jmms_jdi_update_extrabytes(hStore, uiMsgIndex, uiExtraBytes) \
                jdi_StoreUpdateUIExtraBytes(hStore, uiMsgIndex,  uiExtraBytes)
#define mmi_jmms_jdi_get_extrabytes(hStore, file, uiExtraBytes) \
                jdi_StoreGetUIExtraBytes(hStore, file,  uiExtraBytes)

#define  mmi_jmms_jdi_deinitview(hMsg) \
         jdi_DeInitView(hMsg)
#define mmi_jmms_jdi_preforwardheader(hMsg)  \
         jdi_PreForwardHeader(hMsg)
#define     mmi_jmms_jdi_preedit(hMsg) \
         jdi_preEdit(hMsg)

#define mmi_jmms_jdi_store_update_extra_byte_1(hStore, uiMsgIndex, uiExtraBytes)  \
        jdi_StoreUpdateUIExtra1Bytes(hStore, uiMsgIndex, uiExtraBytes)

#define mmi_jmms_jdi_store_get_extra_byte_1(hStore, uiMsgIndex, puiExtraBytes)  \
        jdi_StoreGetUIExtra1Bytes(hStore, uiMsgIndex, puiExtraBytes)

#define mmi_jmms_jdi_replace_media(hMsg, pMediaInfo, uiOldMediaID, ucPageIndex, pMediaID)       \
               jdi_MsgReplaceMedia (hMsg,pMediaInfo, uiOldMediaID, ucPageIndex, pMediaID)
#define mmi_jmms_jdi_store_get_extra_byte_open_mms(hStore, file_hamdle, puiExtraBytes)  \
        jdi_StoreGetUIExtra1BytesOpenMMS(hStore, file_hamdle, puiExtraBytes)
#define mmi_jmms_jdi_write_into_file(file_name_p, source_buffer_p, source_buffer_length)  \
        jdi_UtilsWriteIntoFile(file_name_p, source_buffer_p, source_buffer_length)

#ifdef LARGE_MMS_HANDLING
#define mmi_jmms_is_text_limit_exceed(hMsg,result)    \
      jdi_GetTextLimitStatus(hMsg,result)
#endif /* LARGE_MMS_HANDLING */ 
#ifdef META_HANDLING_SUPPORT
#define mmi_jmms_jdi_get_meta_info(hMsg,meta_info) \
      jdi_GetMetaInfo(hMsg,meta_info)
#define mmi_jmms_jdi_reset_smil_meta_info(hMsg) \
   jdi_ResetSMILMetaInfo(hMsg)
#endif /* META_HANDLING_SUPPORT */ 
#define mmi_jmms_is_media_resolution_in_content_class_limit(eContentClass, uiWidth, uiHeight)      \
        CheckMediaResolutionInContentClass( eContentClass, uiWidth, uiHeight)
#define mmi_jmms_max_allowable_mms_size_in_content_class_limit(eContentClass)    \
      MaxMmsSizeInContentClass(eContentClass)

#endif /* JMMS_CORE_APIS_H */ 

