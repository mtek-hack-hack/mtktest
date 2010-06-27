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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * BTMMIOpp.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MTK bluetooth MMI OPP client/server
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_OPP_SUPPORT__
#if defined(__MMI_BT_MTK_SUPPORT__)

/*  Include: MMI header file */
#include "ProtocolEvents.h"
#include "CommonScreens.h"      /* DisplayPopup */
#include "SettingProfile.h"     /* ERROR_TONE */
#include "FileManagerGProt.h"
#include "ProfileGprots.h"      /* PlayRequestTone */
#include "Conversions.h"        /*mmi_chset_mixed_text_to_ucs2_str*/  
/* Trace Header Files */

#include "vObjects.h"


/* File Type Categories (sync with file manager) */
#include "FileMgr.h"

/* External Device Header Files */
#include "ExtDeviceDefs.h"

/* Applib MIME Header Files */
#include "app_mine.h"

/* BT manager Header Files */
#include "bluetooth_bm_struct.h"

/* OBEX stack Header Files */
#include "bluetooth_struct.h"

#include "BTMMICm.h"
#include "BTMMICmGprots.h"
#include "BTMMIScr.h"
#include "BTMMIScrGprots.h"
#include "OPPMMIGprots.h"
#include "BTMMIOpp.h"
#include "OPPMMIScr.h"
#include "BTMMIOppGprots.h"
#include "BTMMIObex.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif 

#include "BTMMIFtpScr.h"//sergeycao
#include "BTMMIFtp.h" //sergeycao
#define __BQB_PTS__

extern U8 PhnsetGetDefEncodingType(void);
extern pBOOL isInCall(void);
static MMI_BOOL mmi_bt_opp_passkey_hdler(mmi_bth_bt_addr bd_addr);
extern MMI_BOOL mmi_bt_ftp_check_folder_existed_external(U8* absolute_path);

/***************************************************************************** 
* External Variable
*****************************************************************************/

#ifdef MMI_ON_HARDWARE_P
extern fmgr_filter_struct fmgr_filter[];    /* file type/extension mapping table */
#endif 
extern S8 nPrintableStr[];                  /* for file name buffer */

/***************************************************************************** 
* Local Variable
*****************************************************************************/
MMI_OPP_CONTEX g_mmi_opp_cntx;
MMI_OPP_CONTEX *const g_mmi_opp_cntx_p = &g_mmi_opp_cntx;
MMI_BOOL opp_suppress_popup_flag = MMI_FALSE;
#ifdef __BQB_PTS__
local_para_struct *first_push_ind_ptr = NULL;
#endif
mmi_bth_bt_addr ops_bt_divice;
/* 
 * Init functions
 */
 
 
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_init_opc_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opp_init_oppc_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_CTX(opc_state) = MMI_OPC_IDLE;

    MMI_OPP_CTX(app_callback_fp) = NULL;
    MMI_OPP_CTX(h_snd) = (FS_HANDLE) NULL;

    MMI_OPP_CTX(oppc_goep_conn_id) = 0xff;
    MMI_OPP_CTX(oppc_goep_req_id) = 0xff;
    MMI_OPP_CTX(oppc_cm_conn_id) = 0xff;
    
    MMI_OPP_CTX(total_obj_len) = 0;
    MMI_OPP_CTX(remain_put_len) = 0;
    MMI_OPP_CTX(send_obex_pkt_size) = 0;
    /* Shall not reset to zero. Maybe screen is still (Reveived N files) */
    MMI_OPP_CTX(flag) = 0x00000000;

    /* get shared buffer for oppc*/
    MMI_OPP_CTX(oppc_push_buf)= (kal_uint8*)mmi_bt_obex_get_profile_shared_buffer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_init_opps_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opp_init_opps_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_CTX(ops_state) = MMI_OPS_IDLE;

    MMI_OPP_CTX(h_recv) = (FS_HANDLE) NULL;

    MMI_OPP_CTX(opps_goep_conn_id) = 0xff;
    MMI_OPP_CTX(opps_goep_req_id) = 0xff;
    MMI_OPP_CTX(opps_cm_conn_id) = 0xff;
    
    MMI_OPP_CTX(fcnt) = 0;
    MMI_OPP_CTX(cur_recv_file_cnt) = 0;
    MMI_OPP_CTX(disconnflag)=MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_init_cntx
 * DESCRIPTION
 *  This function is to initialize the mmi opp context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opp_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_CTX(req_id) = 0;
    mmi_opp_init_oppc_cntx();
    mmi_opp_init_opps_cntx();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_init_fs_recover
 * DESCRIPTION
 *  This function is to handle if create received folder fail.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS : NONE.(?)
 *  GLOBALS AFFECTED :(?)
 *****************************************************************************/
static void mmi_opp_init_fs_recover(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* After recover, shall create folder again */
    MMI_OPP_MAKE_RECV_PATH(nPrintableStr);
//sergeycao
//        mmi_ucs2cpy((PS8) nPrintableStr, (PS8) ftps_cntx_p->root_folder);
    ret = FS_CreateDir((kal_uint16*) nPrintableStr);

    if (ret == FS_NO_ERROR)
    {
        MMIOPP_RESET_FLAG(MMIOPP_MASK_FOLDER_ERR);
    }
    else
    {
        MMIOPP_SET_FLAG(MMIOPP_MASK_FOLDER_ERR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_init_received_folder
 * DESCRIPTION
 *  This function is to create received folder if not exist.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS : NONE.(?)
 *  GLOBALS AFFECTED :(?)
 *****************************************************************************/
static void mmi_opp_init_received_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_IN_USB_MS__
    if (USBMS_BOOT == stack_query_boot_mode())
    {
        MMI_OPP_LOG(MMI_BT_OPP_INIT_RECEIVED_FOLDER_USBMS_BOOT);
        return;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    MMI_OPP_MAKE_RECV_PATH(nPrintableStr);
//sergeycao
//        mmi_ucs2cpy((PS8) nPrintableStr, (PS8) ftps_cntx_p->root_folder);
    h = FS_Open((kal_uint16*) nPrintableStr, FS_READ_ONLY | FS_OPEN_DIR);
    MMI_OPP_LOG1(MMI_BT_OPP_INIT_RECEIVED_FOLDER_OPEN_DIR, h);
    if (h >= FS_NO_ERROR)
    {
        MMIOPP_RESET_FLAG(MMIOPP_MASK_FOLDER_ERR);
        /* Normal case ,Folder exist! */
        FS_Close(h);
    }
    else    /* Error handling */
    {
        /* First boot-up, File not exist */
        if (h == FS_PATH_NOT_FOUND || h == FS_FILE_NOT_FOUND)
        {
            ret = FS_CreateDir((kal_uint16*) nPrintableStr);

            MMI_OPP_LOG1(MMI_BT_OPP_INIT_RECEIVED_FOLDER_CREATE_DIR, ret);

            if (ret == FS_NO_ERROR)
            {
                MMIOPP_RESET_FLAG(MMIOPP_MASK_FOLDER_ERR);
            }
            else if (ret == FS_DISK_FULL)
            {
                /* Remove assert prevent from bother other modules */                
                MMIOPP_SET_FLAG(MMIOPP_MASK_DISK_FULL);
            }
            else if (ret == FS_ROOT_DIR_FULL)
            {
                MMIOPP_SET_FLAG(MMIOPP_MASK_ROOT_DIR_FULL);
            }
            else if (ret == FS_LOCK_MUTEX_FAIL || ret == FS_DEVICE_BUSY)
            {
                MMIOPP_SET_FLAG(MMIOPP_MASK_DEVICE_BUSY);
            }
            else
            {
                /* File system fatal error, has to do sanity check or format FS */
                if (MMIOPP_GET_FLAG(MMIOPP_MASK_FS_SANITY) == MMI_TRUE)
                {
                    mmi_opp_init_fs_recover();
                }
            }
        }
        else
        {
            /* File system fatal error, has to do sanity check or format FS */
            if (MMIOPP_GET_FLAG(MMIOPP_MASK_FS_SANITY) == MMI_TRUE)
            {
                mmi_opp_init_fs_recover();
            }
        }

    }   /* End of error handling */

    /* Only first boot up do FS sanity check */
    MMIOPP_RESET_FLAG(MMIOPP_MASK_FS_SANITY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_opp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_INIT);
    mmi_opp_init_cntx();
    mmi_opp_init_received_folder();
}


/* 
 * Static Lib functions
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_get_file_name_ext
 * DESCRIPTION
 *  This function is to abstract file name.
 * PARAMETERS
 *  pathfileName        [IN]        The input file path
 *  type                [IN]        Get file name or extension name
 * RETURNS
 *  void
 *****************************************************************************/
static S8 *mmi_opp_get_file_name_ext(S8 *pathfileName, MMI_OPP_GET_FILE_ENUM type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 NameLength = (U16) mmi_ucs2strlen(pathfileName);
    S16 *UniPathName = (S16*) pathfileName;
    U16 deter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case OPP_FILE_GET_NAME:
            deter = '\\';
            break;

        case OPP_FILE_GET_EXT:
            deter = '.';
            break;

        default:
            deter = '\\';
            break;
    }

    while (NameLength > 0)
    {
        NameLength--;
        if (memcmp(UniPathName + NameLength, &deter, 2) == 0)
        {
            break;
        }
    }
    return ((S8*) (UniPathName + NameLength + 1));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_get_file_mime_type
 * DESCRIPTION
 *  This function is to get MIME type of a file.
 * PARAMETERS
 *  pathfileName        [IN]        The input file path
 *  type                [IN]        Get file name or extension name
 * RETURNS
 *  void
 *****************************************************************************/
static S8 *mmi_opp_get_file_mime_type(U16 *pathfileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *mime_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mime_type = mime_get_file_type((kal_wchar*) pathfileName);

    if (mime_type == NULL)
    {
        /* OBEX allows to send a object without MIME */
        return NULL;
    }
	
    return (S8*) mime_type->mime_string;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_retrieve_obj_type
 * DESCRIPTION
 *  This function is to retrieve file type by file extension.
 *  
 *  PARAMETERS:
 *  obj_name        [?]     
 *  (S8 *obj_name) ( IN ) : UCS2, null terminated string(?)
 *  RETURNS:(?)
 *  FMGR_TYPE_XXX(?)
 *****************************************************************************/
static U32 mmi_opp_retrieve_obj_type(S8 *obj_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i, j;
    S8 *p;
    S8 ext_buf[5];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = mmi_opp_get_file_name_ext(obj_name, OPP_FILE_GET_EXT);
    if (!p)
    {
        return FMGR_TYPE_UNKNOW;
    }
    memset(ext_buf, 0, sizeof(ext_buf));
    mmi_ucs2_n_to_asc(ext_buf, p, 5 * ENCODING_LENGTH);

    /* make upper */
    for (j = 0; j < 5; j++)
    {
        if (ext_buf[j] != 0)
        {
            if (ext_buf[j] >= 'a')
            {
                ext_buf[j] -= 'a' - 'A';
            }
        }
    }

    for (i = 0; i < FMGR_MAX_FILTER_COUNT; i++)
    {
        if (strcmp((S8*) fmgr_filter[i].ext, (S8*) ext_buf) == 0)
        {
            return fmgr_filter[i].type;
        }
    }

    return FMGR_TYPE_UNKNOW;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_get_folder_name
 * DESCRIPTION
 *  This function is to retrieve folder name.
 *  
 *  PARAMETERS:
 *  RETURNS:(?)
 *****************************************************************************/
static void mmi_opp_get_folder_name()
{
    U16 folderlength = (U16) mmi_ucs2strlen((S8 *)MMI_OPP_RECV_OBJ_FILEPATH);
    S16* pName = NULL ;
 
    
    mmi_ucs2cpy((S8*)MMI_OPP_CTX(file_stored_folder_name),(S8*)MMI_OPP_RECV_OBJ_FILEPATH);
    pName  = (S16*)MMI_OPP_CTX(file_stored_folder_name);
    
    if(mmi_ucs2cmp((PS8) &pName[folderlength-1],(PS8) L"\\") == 0 || mmi_ucs2cmp((PS8) &pName[folderlength-1], (PS8)L"/")== 0)
    {
        pName[folderlength-1] = 0;
    }
    
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_notify_register_app
 * DESCRIPTION
 *  This function is to notify proper application after received object.
 *  
 *  PARAMETERS:
 *  path        [?]     
 *  (S8 *path) ( IN ) : UCS2, null terminated string(?)
 *  RETURNS:(?)
 *****************************************************************************/
static void mmi_opp_notify_register_app(U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 obj_type = mmi_opp_retrieve_obj_type(MMI_OPP_CTX(obj_name));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* It is application duty to play received tone */

    switch (obj_type)
    {
#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
        #ifdef __MMI_VCARD__
        case FMGR_TYPE_VCF:
        #endif
        #ifdef __MMI_VCALENDAR__
        case FMGR_TYPE_VCS:
        #endif
        #ifdef __MMI_VBOOKMARK__
        case FMGR_TYPE_URL:
        case FMGR_TYPE_VBM:
        #endif
            mmi_vobj_opp_receive_ind((void*)path, obj_type);
            break;
#endif /* defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__) */ 
        default:
            mmi_opp_obj_receive_ind((void*)path, (void*)MMI_OPP_CTX(obj_name));
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_disconnect_req
 * DESCRIPTION
 *  This function is to handle OPP client OBEX disconnect request
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opp_disconnect_req(U8 goep_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_disconnect_req_struct *goep_disconnect_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_disconnect_req = (goep_disconnect_req_struct*) construct_local_para(sizeof(goep_disconnect_req_struct), TD_CTRL);
    
    goep_disconnect_req->goep_conn_id = goep_conn_id;
    
    /* This request ID is only useful while aborting connecting request */
    goep_disconnect_req->req_id = MMI_OPP_CTX(oppc_goep_req_id);        

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_disconnect_req;
    ilm_ptr->msg_id         = MSG_ID_GOEP_DISCONNECT_REQ;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_disconnect_req
 * DESCRIPTION
 *  This function is to handle OPP client OBEX disconnect request
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opp_tpdisconnect_req(U8 goep_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_disconnect_req_struct *goep_disconnect_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_disconnect_req = (goep_disconnect_req_struct*) construct_local_para(sizeof(goep_disconnect_req_struct), TD_CTRL);
    
    goep_disconnect_req->goep_conn_id = goep_conn_id;
    
    /* This request ID is only useful while aborting connecting request */
    goep_disconnect_req->req_id = MMI_OPP_CTX(oppc_goep_req_id);        

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_disconnect_req;
    ilm_ptr->msg_id         = MSG_ID_GOEP_TPDISCONNECT_REQ;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_deal_abort_hdlr
 * DESCRIPTION
 *  This is common function to deal with abort when lowlayer has not been given response.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opp_deal_abort_hdlr(void)
{
    MMI_OPC_STATE_TRANS(MMI_OPC_DISCONNECTING);
    mmi_bt_opp_tpdisconnect_req(MMI_OPP_CTX(oppc_goep_conn_id));
    
    SetDelScrnIDCallbackHandler(SCR_OPP_ABORTING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_ABORTING);
    SetDelScrnIDCallbackHandler(SCR_OPP_SENDING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_SENDING);
}


/* 
 * Exported Lib functions
 */
 
 
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_retrieve_put_prog_percentage
 * DESCRIPTION
 *  This function is to retrieve the file put progress.
 * PARAMETERS
 *  void
 * RETURNS
 *  1 ~ 100  The percentage of put process.
 *****************************************************************************/
U8 mmi_opp_retrieve_put_prog_percentage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Total length of a object */

    if (MMI_OPP_CTX(total_obj_len) == 0)
    {
        return 0;
    }
    return (U8) (((double)(MMI_OPP_CTX(total_obj_len) - MMI_OPP_CTX(remain_put_len)) /
                  (double)MMI_OPP_CTX(total_obj_len)) * 100.0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_suppress_popup
 * DESCRIPTION
 *  This function allow the other application suppress OPP popup
 * PARAMETERS
 *  is_true
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_suppress_popup(MMI_BOOL is_true)
{


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    opp_suppress_popup_flag = is_true;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_set_recv_files_cnt
 * DESCRIPTION
 *  This function is to set received files count.
 *  
 *  PARAMETERS: U8 cnt
 *  cnt     [IN]        
 *  RETURNS: viod(?)
 *****************************************************************************/
void mmi_opp_set_recv_files_cnt(U8 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_CTX(recv_file_cnt) = cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_get_recv_files_cnt
 * DESCRIPTION
 *  This function is to get received files count.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
U8 mmi_opp_get_recv_files_cnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_OPP_CTX(recv_file_cnt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_is_sending
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
BOOL mmi_opp_is_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_OPC_CONNECTING == MMI_OPP_CTX(opc_state)) ||
        (MMI_OPC_CONNECTED == MMI_OPP_CTX(opc_state)) || (MMI_OPC_SENDING == MMI_OPP_CTX(opc_state)))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_is_receiving
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
BOOL mmi_opp_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_OPP_CTX(ops_state) >= MMI_OPS_ACCEPTED)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_is_aborting
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
BOOL mmi_opp_is_aborting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMI_OPC_ABORTING == MMI_OPP_CTX(opc_state)) || (MMI_OPC_DISCONNECTING == MMI_OPP_CTX(opc_state)))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/* 
 * OPP Server Out Event MMI -> OBEX
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_sdpdb_register_req
 * DESCRIPTION
 *  This function is to register OPP service SDP record
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_sdpdb_register_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    bt_sdpdb_register_req_struct *sdpdb_register_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    sdpdb_register_req = (bt_sdpdb_register_req_struct*) construct_local_para(sizeof(bt_sdpdb_register_req_struct), TD_CTRL);
    
    sdpdb_register_req->uuid = MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)sdpdb_register_req;
    ilm_ptr->msg_id         = MSG_ID_BT_SDPDB_REGISTER_REQ;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_obex_register_server_req
 * DESCRIPTION
 *  This function is to register OBEX server instance
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_obex_register_server_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_register_server_req_struct *goep_register_server_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_register_server_req = (goep_register_server_req_struct*) construct_local_para(sizeof(goep_register_server_req_struct), TD_CTRL);
    
    MMI_OPP_CTX(opps_goep_req_id) = MMI_OPP_CTX(req_id++);    
    goep_register_server_req->req_id = MMI_OPP_CTX(opps_goep_req_id);
    goep_register_server_req->uuid[0] = '\0';
    goep_register_server_req->uuid_len = 0;
    goep_register_server_req->tp_type = GOEP_TP_BT;
    goep_register_server_req->need_auth = KAL_FALSE;
    goep_register_server_req->buf_ptr = (kal_uint8*)MMI_OPP_CTX(opps_push_buf);
    goep_register_server_req->buf_size = OPPS_MAX_OBEX_PACKET_LENGTH;
    
    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_register_server_req;
    ilm_ptr->msg_id         = MSG_ID_GOEP_REGISTER_SERVER_REQ;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_obex_deregister_server_req
 * DESCRIPTION
 *  This function is to deactivate OPP server service
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_obex_deregister_server_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_deregister_server_req_struct *goep_deregister_server_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_deregister_server_req = (goep_deregister_server_req_struct*) construct_local_para(sizeof(goep_deregister_server_req_struct), TD_CTRL);
    
    goep_deregister_server_req->goep_conn_id = MMI_OPP_CTX(opps_goep_conn_id);

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_deregister_server_req;
    ilm_ptr->msg_id         = MSG_ID_GOEP_DEREGISTER_SERVER_REQ;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_sdpdb_deregister_req
 * DESCRIPTION
 *  This function is to deregister OPP SDP service record
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_sdpdb_deregister_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    bt_sdpdb_deregister_req_struct *bt_sdpdb_deregister_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    bt_sdpdb_deregister_req = (bt_sdpdb_deregister_req_struct*) construct_local_para(sizeof(bt_sdpdb_deregister_req_struct), TD_CTRL);
    
    bt_sdpdb_deregister_req->uuid = MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)bt_sdpdb_deregister_req;
    ilm_ptr->msg_id         = MSG_ID_BT_SDPDB_DEREGISTER_REQ;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_connect_res
 * DESCRIPTION
 *  This function is to handle OPP server OBEX connect response
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_connect_res(U8 goep_conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_connect_res_struct *goep_connect_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_connect_res = (goep_connect_res_struct*) construct_local_para(sizeof(goep_connect_res_struct), TD_CTRL);
    
    goep_connect_res->goep_conn_id = goep_conn_id;
    goep_connect_res->rsp_code = rsp_code;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_connect_res;
    ilm_ptr->msg_id         = MSG_ID_GOEP_CONNECT_RES;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_push_res
 * DESCRIPTION
 *  This function is to handle OPP server OBEX push response
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_push_res(U8 goep_conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_push_res_struct *goep_push_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_push_res = (goep_push_res_struct*) construct_local_para(sizeof(goep_push_res_struct), TD_CTRL);
    
    goep_push_res->goep_conn_id = goep_conn_id;
    goep_push_res->rsp_code = rsp_code;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_push_res;
    ilm_ptr->msg_id         = MSG_ID_GOEP_PUSH_RES;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_pull_res
 * DESCRIPTION
 *  This function is to handle OPP server OBEX pull response
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_pull_res(U8 opps_goep_conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_pull_res_struct *goep_pull_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_pull_res = (goep_pull_res_struct*) construct_local_para(sizeof(goep_pull_res_struct), TD_CTRL);
    
    goep_pull_res->goep_conn_id = (kal_uint8)opps_goep_conn_id;
    goep_pull_res->rsp_code = (kal_uint8)rsp_code;
    
    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_pull_res;
    ilm_ptr->msg_id         = MSG_ID_GOEP_PULL_RES;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)        
}
 

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_authorize_res
 * DESCRIPTION
 *  This function is to handle OPP server OBEX authorize response
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_authorize_res(U8 opps_goep_conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_authorize_res_struct *goep_authorize_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_authorize_res = (goep_authorize_res_struct*) construct_local_para(sizeof(goep_authorize_res_struct), TD_CTRL);
    
    goep_authorize_res->goep_conn_id = (kal_uint8)opps_goep_conn_id;
    goep_authorize_res->rsp_code = (kal_uint8)rsp_code;
    
    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_authorize_res;
    ilm_ptr->msg_id         = MSG_ID_GOEP_AUTHORIZE_RES;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)        
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_abort_res
 * DESCRIPTION
 *  This function is to handle OPP server OBEX abort response
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_abort_res(U8 goep_conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_abort_res_struct *goep_abort_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_abort_res = (goep_abort_res_struct*) construct_local_para(sizeof(goep_abort_res_struct), TD_CTRL);
    
    goep_abort_res->goep_conn_id = goep_conn_id;
    goep_abort_res->rsp_code = rsp_code;

    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_abort_res;
    ilm_ptr->msg_id         = MSG_ID_GOEP_ABORT_RES;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)
}    

/* 
 * OPP Server Event Handler OBEX -> MMI 
 */

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_sdpdb_register_cfn_handler
 * DESCRIPTION
 *  This function is event handler for OPP server SDP record register confirm (MSG_ID_BT_SDPDB_REGISTER_CFN)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opps_sdpdb_register_cfn_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_register_cnf_struct *sdpdb_register_cnf = (bt_sdpdb_register_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sdpdb_register_cnf->uuid != MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID)
    {
        MMI_OPP_ASSERT(0);
    }        

    /* the state shall be MMI_OPS_SDP_REGISTERING */
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_SDP_REGISTERING)
    {
        if (sdpdb_register_cnf->result == 0 /* successful */)
        {
            /* Invoke CM activate confirm callback */
            MMI_OPS_STATE_TRANS(MMI_OPS_ACTIVE);            
            mmi_bth_activate_cnf_hdler((U32) MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID);
        }
        else
        {
            MMI_OPP_ASSERT(0);
        }                        
    }
    else
    {
        MMI_OPP_ASSERT(0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_bt_sdpdb_deregister_cfn_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opps_bt_sdpdb_deregister_cfn_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_deregister_cnf_struct *bt_sdpdb_deregister_cnf = (bt_sdpdb_deregister_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_DEACTIVATING)
    {
        if (bt_sdpdb_deregister_cnf->uuid == MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID && bt_sdpdb_deregister_cnf->result == 0)
        {
            /* Send OPP deactivate request to OBEX */
            mmi_bt_opps_obex_deregister_server_req();
        }
        else
        {
            MMI_OPP_ASSERT(0);
        }               
    }
    else
    {
        MMI_OPP_ASSERT(0);
    }                
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_obex_register_server_rsp_handler
 * DESCRIPTION
 *  This function is event handler for OPP server OBEX server register rsp (MSG_ID_OBEX_REGISTER_SERVER_RSP)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_obex_register_server_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_register_server_rsp_struct *goep_register_server_rsp = (goep_register_server_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id if match */
    if (goep_register_server_rsp->req_id != MMI_OPP_CTX(opps_goep_req_id))
    {
        MMI_OPP_ASSERT(0);
    }          
    
    /* the state shall be MMI_OPS_SDP_REGISTERING */
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_OBEX_REGISTERING)
    {
        if (goep_register_server_rsp->rsp_code == GOEP_STATUS_SUCCESS)
        {
            /* OPP server activating successfully */
            MMI_OPS_STATE_TRANS(MMI_OPS_ACTIVE);
            MMI_OPP_CTX(opps_goep_conn_id) = goep_register_server_rsp->goep_conn_id;
            /* Register OPPS SDP service record */
            mmi_bt_opps_sdpdb_register_req();
            MMI_OPS_STATE_TRANS(MMI_OPS_SDP_REGISTERING);
        }
        else
        {
            /* OPP must server activating successfully, otherwise assert(0) */
            MMI_OPP_ASSERT(0);
        }                        
    }
    else
    {
        MMI_OPP_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_obex_deregister_server_rsp_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_obex_deregister_server_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_deregister_server_rsp_struct *goep_deregister_server_rsp = (goep_deregister_server_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_DEACTIVATING)
    {
        if (goep_deregister_server_rsp->goep_conn_id == MMI_OPP_CTX(opps_goep_conn_id))
        {
            /* invoke CM deactivate confirm callback */
            mmi_bth_deactivate_cnf_hdler((U32) MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID);
            mmi_opp_init_opps_cntx();
        }
        else
        {
            MMI_OPP_ASSERT(0);
        }            
    }
    else
    {
        MMI_OPP_ASSERT(0);
    }                
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_connect_ind_handler
 * DESCRIPTION
 *  This function is event handler for OBEX server connect indication (MSG_ID_BT_GOEP_CONNECT_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_connect_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_connect_ind_struct *goep_connect_ind = (goep_connect_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_CTX(bt_device.lap) = (U32)goep_connect_ind->bd_addr.lap;
	MMI_OPP_CTX(bt_device.uap) = (U8)goep_connect_ind->bd_addr.uap;
	MMI_OPP_CTX(bt_device.nap) = (U16)goep_connect_ind->bd_addr.nap;
    MMI_OPP_CTX(opps_goep_conn_id) = goep_connect_ind->goep_conn_id;
    MMI_OPP_CTX(opps_cm_conn_id) = goep_connect_ind->cm_conn_id;
    mmi_ucs2cpy((PS8) MMI_OPP_CTX(dev_name), (PS8) goep_connect_ind->dev_name);
    switch (MMI_OPP_CTX(ops_state))
    {
        case MMI_OPS_ACTIVE:
            MMI_OPS_STATE_TRANS(MMI_OPS_ACCEPTED);
            /* ESI: mmi_bth_connect_ind_hdler() */
            
            mmi_bt_opps_connect_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_STATUS_SUCCESS);
            MMIOPP_SET_FLAG(MMIOPP_MASK_MULTI_RECEIV);
            break;
        case MMI_OPS_DISCONNECTING: /* Fall through */
        case MMI_OPS_DEACTIVATING:
            /* Do Nothing */
            break;
        default:
            MMI_OPS_LOG_STATE_ERR();
            mmi_bt_opps_connect_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_INTERNAL_SERVER_ERR);
            break;
    }  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_disconnect_rsp_handler
 * DESCRIPTION
 *  This function is event handler for OBEX server disconnect response (MSG_ID_GOEP_DISCONNECT_RSP)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_disconnect_rsp_handler(U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_OPPS_DISC_CONN_RSP);
    StopTimer(BT_OPP_REQ_TIMER);

    if (MMI_OPP_CTX(h_recv))
    {
        FS_Close(MMI_OPP_CTX(h_recv));
        MMI_OPP_CTX(h_recv) = (FS_HANDLE) NULL;
    }
    
    if (rsp_code == GOEP_STATUS_SUCCESS) 
    {        
        /* Does it need to check error code, how about invoke mmi_bth_disconnect_cnf_hdler always ? */
        mmi_bth_disconnect_cnf_hdler(
            MMI_TRUE,
            MMI_OPP_CTX(bt_device).lap,
            MMI_OPP_CTX(bt_device).uap,
            MMI_OPP_CTX(bt_device).nap,
            MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID,
            MMI_OPP_CTX(opps_cm_conn_id));
    }            
        
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_DEACTIVATING)
    {
        /* Deregister SDP OPP service record first, then degister OBEX connection */
        mmi_bt_opps_sdpdb_deregister_req();
    }
    else
    {                
        MMI_OPS_STATE_TRANS(MMI_OPS_ACTIVE);                    
    }        
    
    mmi_opp_scr_data_stop_ind(MMI_BT_SERVER_ROLE);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_disconnect_ind_handler
 * DESCRIPTION
 *  This function is OPP server event handler for OBEX disconnect indication (MSG_ID_GOEP_DISCONNECT_IND)
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_disconnect_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_ind_struct *goep_disconnect_ind = (goep_disconnect_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_OPPS_DISC_CONN_IND);
    if (MMI_OPP_CTX(opps_goep_conn_id) != goep_disconnect_ind->goep_conn_id)
    {
        MMI_OPP_ASSERT(0);
    }        
    
    if (MMI_OPP_CTX(ops_state) > MMI_OPS_ACTIVE)
    {
        /* Clean up padding session (callback, file handler...etc)  */
        mmi_opp_ops_connection_terminated(MMI_OPP_ERR_USER);
    }
    else
    {
        MMI_OPS_LOG_STATE_ERR();
    }

}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_push_ind_write_error
 * DESCRIPTION
 *  This function is OPP server event handler for OBEX disconnect indication (MSG_ID_GOEP_DISCONNECT_IND)
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_push_ind_write_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *path_buf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_OPP_MAKE_RECV_FILENAME(path_buf, MMI_OPP_CTX(fcnt));
    FS_Delete((const WCHAR*)path_buf);
    OslMfree(path_buf);
    
    MMI_OPP_CTX(ops_state) = MMI_OPS_ACCEPTED;
    /* Send response to OBEX */
    mmi_bt_opps_push_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_INTERNAL_SERVER_ERR);

    if (MMIOPP_GET_FLAG(MMIOPP_MASK_WRITE_FILE_FAIL) == MMI_TRUE)
    {
        /* Notify Write File Fail Screen */
        DisplayPopup(
            (PU8) GetString(STR_OPP_WRITE_FILE_FAIL),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else if (MMIOPP_GET_FLAG(MMIOPP_MASK_ROOT_DIR_FULL) == MMI_TRUE)
    {
        /* Notify Root Directory full Screen */
        DisplayPopup(
            (PU8) GetString(STR_OPP_RECV_ROOT_DIR_FULL),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else if (MMIOPP_GET_FLAG(MMIOPP_MASK_DEVICE_BUSY) == MMI_TRUE)
    {
        DisplayPopup(
            (PU8) GetString(GetFileSystemErrorString(FS_DEVICE_BUSY)),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    else
    {
        /* Notify Disk full Screen */
        DisplayPopup(
            (PU8) GetString(STR_OPP_RECV_DISK_FULL),
            IMG_GLOBAL_ERROR,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
    }
    MMIOPP_RESET_FLAG(MMIOPP_MASK_WRITE_FILE_FAIL);
    MMIOPP_RESET_FLAG(MMIOPP_MASK_ROOT_DIR_FULL);
    MMIOPP_RESET_FLAG(MMIOPP_MASK_DISK_FULL);
    MMIOPP_RESET_FLAG(MMIOPP_MASK_DEVICE_BUSY);
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_first_push_ind_handler
 * DESCRIPTION
 *  This function is OPP server event handler for first push object indication (MSG_ID_GOEP_PUSH_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_first_push_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 fcnt;
    FS_HANDLE h;
    S8 *path_buf;
    int i;
    goep_push_ind_struct *goep_push_ind = (goep_push_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_OPPS_FIRST_PUSH_IND);

    mmi_opp_get_folder_name();
    if ((MMI_OPP_CTX(ops_state) == MMI_OPS_DISCONNECTING) || (MMI_OPP_CTX(ops_state) == MMI_OPS_DEACTIVATING))
    {
        /* Do Nothing */
        return;
    }

    if (MMI_OPP_CTX(ops_state) != MMI_OPS_ACCEPTED)
    {
        /* Wrong OPS state */
        MMI_OPS_LOG_STATE_ERR();
        mmi_bt_opps_push_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_INTERNAL_SERVER_ERR);
        return;
    }
    
    MMI_OPS_STATE_TRANS(MMI_OPS_RECEIVING);

    /* Save object name to context */
    memset(MMI_OPP_CTX(obj_name), 0, sizeof(MMI_OPP_CTX(obj_name)));
    if (mmi_ucs2strlen((const S8*)goep_push_ind->obj_name) * 2 > (sizeof(MMI_OPP_CTX(obj_name)) - 2))
    {
        int name_length = mmi_ucs2strlen((const S8*)goep_push_ind->obj_name) * 2;

        for (i = 0; i < sizeof(MMI_OPP_CTX(obj_name)); i += 2)
        {
            MMI_OPP_CTX(obj_name)[i] = goep_push_ind->obj_name[i + name_length - (sizeof(MMI_OPP_CTX(obj_name)) - 2) + 1];
            MMI_OPP_CTX(obj_name)[i + 1] = goep_push_ind->obj_name[i + name_length - (sizeof(MMI_OPP_CTX(obj_name)) - 2)];
        }
        MMI_OPP_CTX(obj_name)[0] = 0x7E;
        MMI_OPP_CTX(obj_name)[1] = 0;
        MMI_OPP_CTX(obj_name)[sizeof(MMI_OPP_CTX(obj_name)) - 2] = 0;
        MMI_OPP_CTX(obj_name)[sizeof(MMI_OPP_CTX(obj_name)) - 1] = 0;
    }
    else
    {
        for (i = 0; i < sizeof(MMI_OPP_CTX(obj_name)); i += 2)
        {
            MMI_OPP_CTX(obj_name)[i] = goep_push_ind->obj_name[i + 1];
            MMI_OPP_CTX(obj_name)[i + 1] = goep_push_ind->obj_name[i];
        }
    }

    /* Check default folder again */
    {
        mmi_opp_init_received_folder();

        /* if after reinit, folder still get problem, return fail */
        if (MMIOPP_GET_FLAG(MMIOPP_MASK_DISK_FULL) == MMI_TRUE)
        {
            mmi_bt_opps_push_ind_write_error();
            return;
        }
        else if (MMIOPP_GET_FLAG(MMIOPP_MASK_ROOT_DIR_FULL) == MMI_TRUE)
        {
            mmi_bt_opps_push_ind_write_error();
            return;
        }
        else if (MMIOPP_GET_FLAG(MMIOPP_MASK_DEVICE_BUSY) == MMI_TRUE)
        {
            mmi_bt_opps_push_ind_write_error();
            return;
        }
    }

    /* Set path and file name, check file exist */
    fcnt = 0;
    path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
    MMI_OPP_ASSERT(path_buf != NULL);

    while (fcnt < 0xFF)
    {
        MMI_OPP_MAKE_RECV_FILENAME(path_buf, fcnt);
        h = FS_Open((kal_uint16*) path_buf, FS_READ_ONLY);
        if (h >= 0)
        {
            FS_Close(h);
            fcnt++;
        }
        else
        {
            break;
        }
    }

    /* Create file */
    MMI_OPP_CTX(fcnt) = fcnt;
    h = FS_Open((kal_uint16*) path_buf, (FS_READ_WRITE | FS_CREATE_ALWAYS));
    OslMfree(path_buf);

    MMI_OPP_LOG1(MMI_BT_OPP_OPPS_FIRST_PUSH_IND_FS_OPEN, h);

    if (h < 0)
    {
        /* File open error. Error handling */
        if (h == FS_DISK_FULL)
        {
            MMIOPP_SET_FLAG(MMIOPP_MASK_DISK_FULL);
        }
        else if (h == FS_ROOT_DIR_FULL)
        {
            MMIOPP_SET_FLAG(MMIOPP_MASK_ROOT_DIR_FULL);
        }
        else if (h == FS_LOCK_MUTEX_FAIL || h == FS_DEVICE_BUSY)
        {
            MMIOPP_SET_FLAG(MMIOPP_MASK_DEVICE_BUSY);
        }
        else
        {
            MMIOPP_SET_FLAG(MMIOPP_MASK_WRITE_FILE_FAIL);
        }
        mmi_bt_opps_push_ind_write_error();
        return;
    }
    else
    {
        MMI_OPP_CTX(h_recv) = h;
    }

    MMI_OPP_LOG2(MMI_BT_OPP_OPPS_FIRST_PUSH_IND_FRAG_LEN, goep_push_ind->frag_len, goep_push_ind->total_obj_len);

    /* Write object context to file */
    if (goep_push_ind->frag_len > 0)
    {
        U32 len_written;
        S16 ret;

        if (MMI_OPP_CTX(h_recv))
        {
            ret = FS_Write(MMI_OPP_CTX(h_recv), goep_push_ind->frag_ptr, goep_push_ind->frag_len, (kal_uint32*) & len_written);

            MMI_OPP_LOG1(MMI_BT_OPP_OPPS_FIRST_PUSH_IND_FS_WRITE, ret);

            if (ret < 0)
            {
                FS_Close(MMI_OPP_CTX(h_recv));
                MMI_OPP_CTX(h_recv) = 0;
                if (ret == FS_DISK_FULL)
                {
                    MMIOPP_SET_FLAG(MMIOPP_MASK_DISK_FULL);
                }
                else if (ret == FS_ROOT_DIR_FULL)
                {
                    MMIOPP_SET_FLAG(MMIOPP_MASK_ROOT_DIR_FULL);
                }
                else if (ret == FS_LOCK_MUTEX_FAIL || ret == FS_DEVICE_BUSY)
                {
                    MMIOPP_SET_FLAG(MMIOPP_MASK_DEVICE_BUSY);
                }
                else
                {
                    MMIOPP_SET_FLAG(MMIOPP_MASK_WRITE_FILE_FAIL);
                }
                mmi_bt_opps_push_ind_write_error();
                return;
            }
        }
    }

    /* It is first packet and also final packet, Receive Finished !! */
    if (goep_push_ind->pkt_type == GOEP_SINGLE_PKT)
    {
        U8 *path_buf;

        MMI_OPP_CTX(ops_state) = MMI_OPS_ACCEPTED;

        /* close file */
        if (MMI_OPP_CTX(h_recv) >= 0)
        {
            FS_Close(MMI_OPP_CTX(h_recv));
            MMI_OPP_CTX(h_recv) = 0;
        }

        /* nofify register appications */
        path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
        MMI_OPP_ASSERT(path_buf != NULL);

        MMI_OPP_MAKE_RECV_FILENAME(path_buf, MMI_OPP_CTX(fcnt));

        mmi_opp_notify_register_app((U16*) path_buf);

        OslMfree(path_buf);
        mmi_bt_opps_push_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_STATUS_SUCCESS);
    }
    else
    {
        /* need clarify */
        mmi_bt_opps_push_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_STATUS_SUCCESS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_next_push_ind_handler
 * DESCRIPTION
 *  This function is event handler for continuous next push object indication (MSG_ID_GOEP_PUSH_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_next_push_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_push_ind_struct *goep_push_ind = (goep_push_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_OPPS_NEXT_PUSH_IND);
    if ((MMI_OPP_CTX(ops_state) == MMI_OPS_DISCONNECTING) || (MMI_OPP_CTX(ops_state) == MMI_OPS_DEACTIVATING))
    {
        /* Do Nothing */
        return;
    }

    if (MMI_OPP_CTX(ops_state) != MMI_OPS_RECEIVING)
    {
        /* Wrong OPS state */
        MMI_OPS_LOG_STATE_ERR();
        mmi_bt_opps_push_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_INTERNAL_SERVER_ERR);
        return;
    }

    MMI_OPP_LOG1(MMI_BT_OPP_OPPS_NEXT_PUSH_IND_FS_HDLE, MMI_OPP_CTX(h_recv));
    MMI_OPP_LOG2(MMI_BT_OPP_OPPS_NEXT_PUSH_IND_FRAG_LEN, goep_push_ind->frag_len, goep_push_ind->total_obj_len);

    /* Write object context to file */
    if (goep_push_ind->frag_len > 0)
    {
        U32 len_written;
        S16 ret;

        if (MMI_OPP_CTX(h_recv))
        {
            ret = FS_Write(
                    MMI_OPP_CTX(h_recv),
                    goep_push_ind->frag_ptr,
                    goep_push_ind->frag_len,
                    (kal_uint32*) & len_written);

            MMI_OPP_LOG1(MMI_BT_OPP_OPPS_NEXT_PUSH_IND_FS_WRITE, ret);

            if (ret < 0)
            {
                FS_Close(MMI_OPP_CTX(h_recv));
                MMI_OPP_CTX(h_recv) = 0;
                if (ret == FS_DISK_FULL)
                {
                    MMIOPP_SET_FLAG(MMIOPP_MASK_DISK_FULL);
                }
                else if (ret == FS_ROOT_DIR_FULL)
                {
                    MMIOPP_SET_FLAG(MMIOPP_MASK_ROOT_DIR_FULL);
                }
                else if (ret == FS_LOCK_MUTEX_FAIL || ret == FS_DEVICE_BUSY)
                {
                    MMIOPP_SET_FLAG(MMIOPP_MASK_DEVICE_BUSY);
                }
                else
                {
                    MMIOPP_SET_FLAG(MMIOPP_MASK_WRITE_FILE_FAIL);
                }
                mmi_bt_opps_push_ind_write_error();
                return;
            }
        }
    }

    /* Final packet, Receive Finished !! */
    if (goep_push_ind->pkt_type == GOEP_FINAL_PKT)
    {
        U8 *path_buf;

        MMI_OPP_CTX(ops_state) = MMI_OPS_ACCEPTED;

        /* close file */
        if (MMI_OPP_CTX(h_recv))
        {
            FS_Close(MMI_OPP_CTX(h_recv));
            MMI_OPP_CTX(h_recv) = 0;
        }

        /* nofify register appications */
        path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
        MMI_OPP_ASSERT(path_buf != NULL);

        MMI_OPP_MAKE_RECV_FILENAME(path_buf, MMI_OPP_CTX(fcnt));

        mmi_opp_notify_register_app((U16*) path_buf);

        OslMfree(path_buf);
        mmi_bt_opps_push_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_STATUS_SUCCESS);
    }
    else
    {
        /* need clarify */
        mmi_bt_opps_push_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_STATUS_SUCCESS);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_notify_cm_conn_ind
 * DESCRIPTION
 *  This function is OPP server event handler for push object indication (MSG_ID_GOEP_PUSH_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opp_notify_cm_conn_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     mmi_bth_connect_ind_hdler(
                MMI_OPP_CTX(bt_device).lap,
                MMI_OPP_CTX(bt_device).uap,
                MMI_OPP_CTX(bt_device).nap,
                MMI_OPP_CTX(dev_name),
                MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID,
                MMI_OPP_CTX(opps_cm_conn_id));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_push_ind_handler
 * DESCRIPTION
 *  This function is OPP server event handler for push object indication (MSG_ID_GOEP_PUSH_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_push_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_push_ind_struct *goep_push_ind = (goep_push_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (goep_push_ind->put_type != GOEP_PUT_NORMAL && goep_push_ind->put_type != GOEP_CREATEEMPTY)
    {
        /* Wrong put type, need clarify */
        mmi_bt_opps_push_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_STATUS_NOT_SUPPORTED);
        DisplayPopup(
            (PU8) GetString(STR_OPP_UNKNOWN_FILE_TYPE),
            IMG_GLOBAL_UNFINISHED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
        return;
    }        

    if (goep_push_ind->pkt_type == GOEP_FIRST_PKT || goep_push_ind->pkt_type == GOEP_SINGLE_PKT)
    {
#ifdef __BQB_PTS__
        /* hold first push indication wait user confirm */    
        if (MMIOPP_GET_FLAG(MMIOPP_MASK_MULTI_RECEIV) == MMI_TRUE)
        {
            first_push_ind_ptr = (local_para_struct*)msg;
            hold_local_para(first_push_ind_ptr);

            mmi_opp_entry_recv_confirm_scr();
            MMIOPP_RESET_FLAG(MMIOPP_MASK_MULTI_RECEIV);
            playRequestedTone(WARNING_TONE);
        }
        else
        {
            mmi_bt_opps_first_push_ind_handler(msg);
        }
#else
        mmi_bt_opps_first_push_ind_handler(msg);
#endif
    }
    else if (goep_push_ind->pkt_type == GOEP_NORMAL_PKT || goep_push_ind->pkt_type == GOEP_FINAL_PKT)
    {
        mmi_bt_opps_next_push_ind_handler(msg);
    }                                
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_abort_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_opps_abort_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_OPPS_ABORT_IND);
    
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_RECEIVING)
    {
        /* close file */
        if (MMI_OPP_CTX(h_recv))
        {
            U8 *path_buf;
        
            FS_Close(MMI_OPP_CTX(h_recv));
            MMI_OPP_CTX(h_recv) = (FS_HANDLE) NULL;
           
            path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
            MMI_OPP_MAKE_RECV_FILENAME(path_buf, MMI_OPP_CTX(fcnt));
            FS_Delete((const WCHAR*)path_buf);
            OslMfree(path_buf);
            
        }
        MMI_OPP_CTX(ops_state) = MMI_OPS_ACCEPTED;
    }
    /* send abort res to opp client */
    mmi_bt_opps_abort_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_STATUS_SUCCESS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_pull_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opps_pull_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* do not support pull indication */
    mmi_bt_opps_pull_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_INTERNAL_SERVER_ERR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_authorize_ind_hdler
 * DESCRIPTION
 *  This function is to handle authorize indication from OBEX stack
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opps_authorize_ind_hdler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_authorize_ind_struct *goep_authorize_ind = (goep_authorize_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (goep_authorize_ind->uuid_len != 0 || goep_authorize_ind->uuid[0] != '\0')
    {
        MMI_OPP_ASSERT(0);
    }                

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        MMI_OPP_LOG(MMI_BT_OPP_OPPS_AUTH_IND_USB_MODE);
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        mmi_bt_opps_authorize_res(goep_authorize_ind->goep_conn_id, GOEP_SERVICE_UNAVAILABLE);    /* profile reject it */
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    if (MMI_OPP_CTX(ops_state) == MMI_OPS_ACTIVE)
    {
        MMI_OPP_CTX(bt_device.lap) = (U32)goep_authorize_ind->bd_addr.lap;
		MMI_OPP_CTX(bt_device.uap) = (U32)goep_authorize_ind->bd_addr.uap;
		MMI_OPP_CTX(bt_device.nap) = (U32)goep_authorize_ind->bd_addr.nap;
        MMI_OPP_CTX(opps_goep_conn_id) = goep_authorize_ind->goep_conn_id;
#ifdef __BQB_PTS__
        /* accept without query user */
        mmi_bt_opps_authorize_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_STATUS_SUCCESS);    /* profile accept it */
#else
        MMI_OPS_STATE_TRANS(MMI_OPS_ACCEPTING);
        mmi_bt_opps_receive_first_push_ind();
        playRequestedTone(WARNING_TONE);
#endif
    }
    else
    {
        mmi_bt_opps_authorize_res(goep_authorize_ind->goep_conn_id, GOEP_SERVICE_UNAVAILABLE);    /* profile reject it */
        /* Wrong OPS state */
        MMI_OPS_LOG_STATE_ERR();
    }
}

/* 
 * OPP Client Out Event MMI -> OBEX
 */
 
 
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_oppc_connect_req
 * DESCRIPTION
 *  This function is to handle OPP client OBEX connect request
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_oppc_connect_req(U16 opp_client_max_packet_len, mmi_bth_bt_addr dest_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_connect_req_struct *goep_connect_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_connect_req = (goep_connect_req_struct*) construct_local_para(sizeof(goep_connect_req_struct), TD_CTRL);
    
    goep_connect_req->uuid[0] = '\0';
    goep_connect_req->uuid_len = 0;
    MMI_OPP_CTX(oppc_goep_req_id) = MMI_OPP_CTX(req_id++);
    goep_connect_req->req_id = MMI_OPP_CTX(oppc_goep_req_id);
    goep_connect_req->bd_addr.lap = (U32)dest_addr.lap;
    goep_connect_req->bd_addr.uap = (U8)dest_addr.uap;
	goep_connect_req->bd_addr.nap = (U16)dest_addr.nap;
    /*goep_connect_req->mru*/
    goep_connect_req->tp_type = GOEP_TP_BT;
    goep_connect_req->buf_ptr = (kal_uint8*)(MMI_OPP_CTX(oppc_push_buf));
    goep_connect_req->buf_size = opp_client_max_packet_len;
    goep_connect_req->auth_use = KAL_FALSE;
    goep_connect_req->passwd_len = 0;
    goep_connect_req->realm_len = 0;
    
    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_connect_req;
    ilm_ptr->msg_id         = MSG_ID_GOEP_CONNECT_REQ;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)        
}
	

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_oppc_abort_req
 * DESCRIPTION
 *  This function is to handle OPP client OBEX abort put request
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_oppc_abort_req(U8 goep_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_abort_req_struct *goep_abort_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_abort_req = (goep_abort_req_struct*) construct_local_para(sizeof(goep_abort_req_struct), TD_CTRL);
    
    goep_abort_req->goep_conn_id = goep_conn_id;
    
    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_abort_req;
    ilm_ptr->msg_id         = MSG_ID_GOEP_ABORT_REQ;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_oppc_push_req
 * DESCRIPTION
 *  This function is to handle OPP client OBEX push request
 * PARAMETERS
 *  sc_authorise_ind_p      [?]             
 *  a(?)                    [IN/OUT]        First variable, used as returns
 *  b(?)                    [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_oppc_push_req(U8 goep_conn_id, goep_pkt_type_enum pkt_type, U32 total_obj_len, PS8 obj_name, PS8 obj_mime, U32 *frag_ptr, U16 frag_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    goep_push_req_struct *goep_push_req;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = NULL;
    goep_push_req = (goep_push_req_struct*) construct_local_para(sizeof(goep_push_req_struct), TD_CTRL);
    
    goep_push_req->goep_conn_id = goep_conn_id;
    goep_push_req->pkt_type = pkt_type;
    goep_push_req->put_type = GOEP_PUT_NORMAL;
    memcpy(goep_push_req->obj_mime_type, obj_mime, GOEP_MAX_MIME_TYPE);
    for (i = 0; i < GOEP_MAX_OBJ_NAME; i++)
    {
        goep_push_req->obj_name[i] = obj_name[i+1];
        goep_push_req->obj_name[i+1] = obj_name[i];
        i++;
    }
    goep_push_req->total_obj_len = total_obj_len;
    goep_push_req->frag_ptr = (kal_uint8*)frag_ptr;
    goep_push_req->frag_len = frag_len;
    
    /* compose ILM */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*)goep_push_req;
    ilm_ptr->msg_id         = MSG_ID_GOEP_PUSH_REQ;
    ilm_ptr->peer_buff_ptr  = NULL;
    SEND_ILM(MOD_MMI, MOD_BT, BT_APP_SAP, ilm_ptr)        
}


/* 
 * OPP Server Event Handler OBEX -> MMI 
 */


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_oppc_connect_rsp_handler
 * DESCRIPTION
 *  This function is event handler for OBEX connect response (MSG_ID_BT_GOEP_CONNECT_RSP)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_oppc_connect_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_connect_rsp_struct *goep_connect_rsp = (goep_connect_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check request id if match */
    if (goep_connect_rsp->req_id != MMI_OPP_CTX(oppc_goep_req_id))
    {
        
    }        
    
    if (goep_connect_rsp->rsp_code == GOEP_STATUS_SUCCESS)
    {
        /* Connection is established successfully  */
        switch (MMI_OPP_CTX(opc_state))
        {
            case MMI_OPC_CONNECTING:
            {
                /* The connection is establish for sending object */
                MMI_OPP_CTX(opc_state) = MMI_OPC_CONNECTED;
                MMI_OPP_CTX(oppc_goep_conn_id) = goep_connect_rsp->goep_conn_id;
                MMI_OPP_CTX(oppc_cm_conn_id) = goep_connect_rsp->cm_conn_id;

                /* Store the max acceptable obex packet size */
                if (goep_connect_rsp->peer_mru != 0)
                {
                    MMI_OPP_CTX(send_obex_pkt_size) = (goep_connect_rsp->peer_mru < OPPC_MAX_OBEX_PACKET_LENGTH ? goep_connect_rsp->peer_mru:OPPC_MAX_OBEX_PACKET_LENGTH);
                }
                else
                {
                    MMI_OPP_CTX(send_obex_pkt_size) = OPPC_MAX_OBEX_PACKET_LENGTH;
                }
                MMI_OPP_LOG1(MMI_BT_OPP_OPPC_MAX_PACKET_SIZE, MMI_OPP_CTX(send_obex_pkt_size));
                /* send first push header when connect confirm */
                mmi_bt_oppc_push_req(MMI_OPP_CTX(oppc_goep_conn_id), GOEP_FIRST_PKT, MMI_OPP_CTX(total_obj_len), MMI_OPP_CTX(sending_obj_name), MMI_OPP_CTX(sending_obj_mime), NULL, 0);
                MMI_OPP_CTX(opc_state) = MMI_OPC_SENDING;
                MMIOPP_RESET_FLAG(MMIOPP_MASK_ICON_BLOCK);
                /* Notify MMI Screen */
                break;
            }
            case MMI_OPC_ABORTING:
                /* store the connection id for disconnect response connection id check */
                MMI_OPP_CTX(oppc_goep_conn_id) = goep_connect_rsp->goep_conn_id;
                MMI_OPP_CTX(oppc_cm_conn_id) = goep_connect_rsp->cm_conn_id;
                /* disconnect the established connecttion */                
                mmi_bt_opp_disconnect_req(goep_connect_rsp->goep_conn_id);
                MMI_OPC_STATE_TRANS(MMI_OPC_DISCONNECTING);
                break;
            case MMI_OPC_DISCONNECTING:
            case MMI_OPC_TPDISCONNECTING:
                /* race condition, just ignore */
                MMI_OPP_CTX(oppc_goep_conn_id) = goep_connect_rsp->goep_conn_id;
                break;                                
            default:
                MMI_OPC_LOG_STATE_ERR();
                MMI_OPP_ASSERT(0);
                break;
        }
    }
    else
    {   
        /* Notify MMI Screen */
        if ( goep_connect_rsp->rsp_code == GOEP_STATUS_SCO_REJECT)
        {
            /* sco link support for MT6601 */
            mmi_bt_popup_operation_not_allowed();
        }        
        else if ( goep_connect_rsp->rsp_code == GOEP_STATUS_BUSY )
        {
            mmi_opp_notify_recv_err(MMI_OPP_NFY_CONNECTION_BUSY);
        }
        /* Connection establish fail */
        mmi_opp_opc_connection_terminated(MMI_OPP_ERR_REJECT);
    }
	/* to cover aborting but receive connect confirm */
    SetDelScrnIDCallbackHandler(SCR_OPP_ABORTING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_ABORTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_oppc_disconnect_rsp_handler
 * DESCRIPTION
 *  This function is event handler for OBEX client disconnect response (MSG_ID_GOEP_DISCONNECT_RSP)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_oppc_disconnect_rsp_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_OPPC_DISC_CONN_RSP);
    StopTimer(BT_OPP_REQ_TIMER);

    /* Deal with terminated a connection */
    if (MMI_OPP_CTX(opc_state) == MMI_OPC_DISCONNECTING)
    {
        mmi_opp_opc_connection_terminated(MMI_OPP_ERR_SUCCESS);
    }
    else if (MMI_OPP_CTX(opc_state) == MMI_OPC_IDLE)
    {
        /* already receive disconnection indication, it is race condition, just ignore the response */
        return;
    }
    else
    {
        MMI_OPP_ASSERT(0);
    }
            
    SetDelScrnIDCallbackHandler(SCR_OPP_ABORTING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_ABORTING);
    SetDelScrnIDCallbackHandler(SCR_OPP_SENDING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_SENDING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_oppc_disconnect_ind_handler
 * DESCRIPTION
 *  This function is event handler for OBEX client disconnect indication (MSG_ID_GOEP_DISCONNECT_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_oppc_disconnect_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_OPPC_DISC_CONN_IND);
    StopTimer(BT_OPP_REQ_TIMER);

    /* Deal with terminated a connection */
    switch (MMI_OPP_CTX(opc_state))
    {
        case MMI_OPC_ABORTING:
            StopTimer(BT_OPP_ABORT_REQ_TIMER);
        case MMI_OPC_DISCONNECTING:
        mmi_opp_opc_connection_terminated(MMI_OPP_ERR_SUCCESS);
            break;
        case MMI_OPC_IDLE:
            /* To avoid BT_RESET case, just discard it */
            break;
        default:
        mmi_opp_opc_connection_terminated(MMI_OPP_ERR_DISCONNECT);
            break;
    }
            
    SetDelScrnIDCallbackHandler(SCR_OPP_ABORTING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_ABORTING);
    SetDelScrnIDCallbackHandler(SCR_OPP_SENDING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_SENDING);

    ops_bt_divice.nap = 0;
    ops_bt_divice.uap = 0;
    ops_bt_divice.lap = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_oppc_push_rsp_handler
 * DESCRIPTION
 *  This function is event handler for OBEX push response
 *  (MSG_ID_GOEP_PUSH_RSP)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_oppc_push_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_push_rsp_struct *goep_push_rsp = (goep_push_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_OPP_CTX(oppc_goep_conn_id) != goep_push_rsp->goep_conn_id)
    {
       // MMI_OPP_ASSERT(0);
       return;
    }

    if (MMI_OPP_CTX(opc_state) == MMI_OPC_ABORTING)
    {
        /* send abort request because user already abort */
        //mmi_bt_oppc_abort_req(MMI_OPP_CTX(oppc_goep_conn_id));
        return;
    }
    else if (MMI_OPP_CTX(opc_state) != MMI_OPC_SENDING || goep_push_rsp->rsp_code != GOEP_STATUS_SUCCESS)
    {
        if (MMI_OPP_CTX(opc_state) !=MMI_OPC_DISCONNECTING)
        {
        mmi_bt_opp_disconnect_req(goep_push_rsp->goep_conn_id);
        }
        
        return;
    }      
    /*only the first push_rsp, start icon blocking*/
    if (MMIOPP_GET_FLAG(MMIOPP_MASK_ICON_BLOCK) == MMI_FALSE)
    {
        mmi_opp_scr_data_transfer_ind(MMI_BT_CLIENT_ROLE);
        MMIOPP_SET_FLAG(MMIOPP_MASK_ICON_BLOCK);
    }

    if (MMI_OPP_CTX(remain_put_len) > 0)
    {
        PU8 buf_p = NULL;

        /* From File */
        U32 read_len = 0;
        U16 send_len = 0;
        S32 errno;

        MMI_OPP_LOG2(MMI_BT_OPP_OPPC_PUSH_RSP_REMAIN_LEN, MMI_OPP_CTX(send_obex_pkt_size), MMI_OPP_CTX(remain_put_len));

        send_len = MMI_OPP_CTX(send_obex_pkt_size);
        
        /* Pending data */
        if (MMI_OPP_CTX(remain_put_len) > send_len)
        {
            /* Remain data is more than one packet */
            /* construct buffers for push object request */

            buf_p = (PU8)MMI_OPP_CTX(oppc_push_buf);

            if (MMI_OPP_CTX(h_snd) != 0)
            {
                errno = FS_Read(MMI_OPP_CTX(h_snd), buf_p, send_len, &read_len);

                MMI_OPP_LOG1(MMI_BT_OPP_OPPC_PUSH_RSP_FS_READ, errno);

                /* Read error! Could be removable device */
                if (errno < 0 || read_len != send_len)
                {
                    //MMI_OPC_STATE_TRANS(MMI_OPC_ABORTING);
                    mmi_bt_opp_disconnect_req(MMI_OPP_CTX(oppc_goep_conn_id));  
                    return;
                }
            }
            else
            {
                MMI_OPC_STATE_TRANS(MMI_OPC_ABORTING);
                mmi_bt_oppc_abort_req(MMI_OPP_CTX(oppc_goep_conn_id));
                return;
            }
            /* send continuous push request for obj data */
            mmi_bt_oppc_push_req(MMI_OPP_CTX(oppc_goep_conn_id), GOEP_NORMAL_PKT, MMI_OPP_CTX(total_obj_len), MMI_OPP_CTX(sending_obj_name), MMI_OPP_CTX(sending_obj_mime), (U32*)buf_p, send_len);
            MMI_OPP_CTX(remain_put_len) -= send_len;
        }
        else
        {
            /* Last packet */
            /* Construct buffers for push object request */
            buf_p = (PU8)MMI_OPP_CTX(oppc_push_buf);

            if (MMI_OPP_CTX(h_snd) != 0)
            {
                errno = FS_Read(MMI_OPP_CTX(h_snd), buf_p, MMI_OPP_CTX(remain_put_len), &read_len);

                MMI_OPP_LOG1(MMI_BT_OPP_OPPC_PUSH_RSP_FS_READ, errno);

                /* Read error! */
                if (errno < 0 || read_len != MMI_OPP_CTX(remain_put_len))
                {
                    //MMI_OPC_STATE_TRANS(MMI_OPC_ABORTING);
                    mmi_bt_opp_disconnect_req(MMI_OPP_CTX(oppc_goep_conn_id));
                    return;
                }
            }
            else
            {
                MMI_OPC_STATE_TRANS(MMI_OPC_ABORTING);
                mmi_bt_oppc_abort_req(MMI_OPP_CTX(oppc_goep_conn_id));
                return;
            }
            /* send last push request for obj data */
            mmi_bt_oppc_push_req(MMI_OPP_CTX(oppc_goep_conn_id), GOEP_FINAL_PKT, MMI_OPP_CTX(total_obj_len), (PS8)MMI_OPP_CTX(sending_obj_name), (PS8)MMI_OPP_CTX(sending_obj_mime), (U32*)buf_p, (U16)MMI_OPP_CTX(remain_put_len));
            MMI_OPP_CTX(remain_put_len) = 0;
        }
    }
    else
    {
        /* No remain data, Finish PUT by disconnect OBEX connection */
        MMI_OPC_STATE_TRANS(MMI_OPC_DISCONNECTING);
        mmi_bt_opp_disconnect_req(goep_push_rsp->goep_conn_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_oppc_abort_ind_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_oppc_abort_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_abort_ind_struct *goep_abort_ind = (goep_abort_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_OPP_LOG(MMI_BT_OPP_OPPC_ABORT_IND);
    if (MMI_OPP_CTX(opc_state) == MMI_OPC_SENDING || MMI_OPP_CTX(opc_state) == MMI_OPC_ABORTING)
    {
        MMI_OPC_STATE_TRANS(MMI_OPC_DISCONNECTING);
        mmi_bt_opp_disconnect_req(goep_abort_ind->goep_conn_id);
    }                        
    else 
    {
        MMI_OPP_ASSERT(0);
    }        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_oppc_abort_rsp_handler
 * DESCRIPTION
 *  This function is event handler for OBEX abort response (MSG_ID_GOEP_ABORT_RSP)
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_oppc_abort_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_abort_rsp_struct *goep_abort_rsp = (goep_abort_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (goep_abort_rsp->goep_conn_id != MMI_OPP_CTX(oppc_goep_conn_id))
    {
        /* do nothing because disconnect indication may already be received */
    }   
    
    if (MMI_OPP_CTX(opc_state) == MMI_OPC_ABORTING)
    {
        MMI_OPC_STATE_TRANS(MMI_OPC_DISCONNECTING);
        mmi_bt_opp_disconnect_req(goep_abort_rsp->goep_conn_id);
        StopTimer(BT_OPP_ABORT_REQ_TIMER);
    }        
    else if (MMI_OPP_CTX(opc_state) == MMI_OPC_DISCONNECTING)
    {
        /* already receive abort indication, it is race condition, do nothing */
    }        
    else
    {
        /* do nothing because disconnect indication may already be received */
    }              
}


/* 
 * OPP Client/Server Common Event Handler OBEX -> MMI 
 */
 
 
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_disconnect_rsp_handler
 * DESCRIPTION
 *  This function is event handler for OBEX disconnect response (MSG_ID_GOEP_DISCONNECT_RSP)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_disconnect_rsp_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_rsp_struct *goep_disconnect_rsp = (goep_disconnect_rsp_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_OPP_CTX(opc_state) == MMI_OPC_DISCONNECTING && goep_disconnect_rsp->goep_conn_id == MMI_OPP_CTX(oppc_goep_conn_id))
    {
        mmi_bt_oppc_disconnect_rsp_handler();
    }
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_DISCONNECTING && goep_disconnect_rsp->goep_conn_id == MMI_OPP_CTX(opps_goep_conn_id))
    {
        mmi_bt_opps_disconnect_rsp_handler(goep_disconnect_rsp->rsp_code);
    }     
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_disconnect_ind_handler
 * DESCRIPTION
 *  This function is event handler for OBEX disconnect indication (MSG_ID_GOEP_DISCONNECT_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_disconnect_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_disconnect_ind_struct *goep_disconnect_ind = (goep_disconnect_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (goep_disconnect_ind->goep_conn_id == MMI_OPP_CTX(oppc_goep_conn_id))
    {
        mmi_bt_oppc_disconnect_ind_handler(msg);
    }
    else if (goep_disconnect_ind->goep_conn_id == MMI_OPP_CTX(opps_goep_conn_id))
    {
        mmi_bt_opps_disconnect_ind_handler(msg);
    }
    else if((MMI_OPP_CTX(opc_state) == MMI_OPC_IDLE) && (MMI_OPP_CTX(ops_state) == MMI_OPS_IDLE ))
    {
    }
    else
    {
        MMI_OPP_ASSERT(0);
    }                
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_abort_ind_handler
 * DESCRIPTION
 *  This function is event handler for OBEX abort indication (MSG_ID_GOEP_ABORT_IND)
 * PARAMETERS
 *  msg         [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_abort_ind_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    goep_abort_ind_struct *goep_abort_ind = (goep_abort_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (goep_abort_ind->uuid_len != 0 || goep_abort_ind->uuid[0] != '\0')
    {
        MMI_OPP_ASSERT(0);
    }        
    
    if (goep_abort_ind->goep_conn_id == MMI_OPP_CTX(oppc_goep_conn_id))
    {
        mmi_bt_oppc_abort_ind_handler(msg);
    }
    else if (goep_abort_ind->goep_conn_id == MMI_OPP_CTX(opps_goep_conn_id))
    {
        mmi_bt_opps_abort_ind_handler(msg);
    }
    else
    {
        MMI_OPP_ASSERT(0);
    }                
}    


/* 
 * Exported Service functions
 */
 
 
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_activate
 * DESCRIPTION
 *  This function is to activate OPS module
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opps_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_OPPS_ACTIVATE);
    MMI_OPP_LOG_STATE();

    if (MMI_OPP_CTX(ops_state) != MMI_OPS_IDLE)
    {
        return;
    }

    /* Register OBEX server instance first, then register SDP service record first */
    mmi_bt_opps_obex_register_server_req();
    MMI_OPS_STATE_TRANS(MMI_OPS_OBEX_REGISTERING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_deactivate
 * DESCRIPTION
 *  This function is to deactivate object push profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opps_deactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_OPPS_ACTIVATE);
    MMI_OPP_LOG_STATE();

    switch (MMI_OPP_CTX(ops_state))
    {
        case MMI_OPS_IDLE:
        case MMI_OPS_DEACTIVATING:                    
            /* nothing to do */
            return;
        case MMI_OPS_SDP_REGISTERING:
        case MMI_OPS_OBEX_REGISTERING:
            /* it must not happen, because CM guarantee no deactivation happen while activating */
            MMI_OPP_ASSERT(0);
            break;
        case MMI_OPS_ACTIVE:
        case MMI_OPS_ACCEPTING:
            /* deregister SDP directly, because no connection yet */
            MMI_OPS_STATE_TRANS(MMI_OPS_DEACTIVATING);
            mmi_bt_opps_sdpdb_deregister_req();
            break;
        case MMI_OPS_ACCEPTED:
            /* disconnect OBEX connection */
            MMI_OPS_STATE_TRANS(MMI_OPS_DEACTIVATING);
            /* Send OPP disconnect request to OBEX */
            mmi_bt_opp_disconnect_req(MMI_OPP_CTX(opps_goep_conn_id));            
            break;
        case MMI_OPS_RECEIVING:
            /* need to abort ? because we already receive disconnect indication before CM invoke mmi_bt_opps_deactivate  */
            MMI_OPP_ASSERT(0);
            break;
        case MMI_OPS_ABORTING:
            /* Impossible, because there is UI for OPPS aborting */
            MMI_OPP_ASSERT(0);
            break;
        case MMI_OPS_DISCONNECTING:
            /* wait disconnect response */            
            break;
        default:
            MMI_OPP_ASSERT(0);
            break;
    }                            
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_send_file_obj
 * DESCRIPTION
 *  This function is to send file object.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_send_file_obj(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h;
    U32 len;
    S8 *filename_p;
    S8 *mimetype_p;
    mmi_bt_dev_struct bt_dev_p;
    mmi_bth_bt_addr a;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_SEND_FILE_OBJ);
    MMI_OPP_LOG_STATE();

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported(MMI_OPP_CTX(fwd_file_path)))
        {
            MMI_OPP_LOG(MMI_BT_OPP_SEND_FILE_OBJ_USB_MODE);
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    /* Change MMI OPC state */
    switch (MMI_OPP_CTX(opc_state))
    {
        case MMI_OPC_IDLE:
            MMI_OPC_STATE_TRANS(MMI_OPC_CONNECTING);
            break;

        default:    /* Incorrect state */
            /* Incorrect state, callback and return error */
            (*(MMI_OPP_CTX(app_callback_fp))) (NULL, MMI_OPP_ERR_SENDING);
            MMI_OPC_LOG_STATE_ERR();
    }

    h = FS_Open((U16*) MMI_OPP_CTX(fwd_file_path), FS_READ_ONLY);
    MMI_OPP_LOG1(MMI_BT_OPP_SEND_FILE_OBJ_FS_OPEN, h);

    /* File open error, return to application */
    if (h < 0)
    {
        mmi_opp_opc_connection_terminated(MMI_OPP_ERR_BAD_FILE);
        return;
    }

    /* Store the file handler */
    MMI_OPP_CTX(h_snd) = h;

    /* Store the object length (file size) */
    FS_GetFileSize(MMI_OPP_CTX(h_snd), &len);
    MMI_OPP_CTX(total_obj_len) = len;
    MMI_OPP_CTX(remain_put_len) = len;

    /* Get object name */
    memset(MMI_OPP_CTX(sending_obj_name), 0, sizeof(MMI_OPP_CTX(sending_obj_name)));
    filename_p = mmi_opp_get_file_name_ext(MMI_OPP_CTX(fwd_file_path), OPP_FILE_GET_NAME);
    if (filename_p)
    {
        if (MMIOPP_GET_FLAG(MMIOPP_MASK_SHORT_NAME))
        {           
            mmi_chset_mixed_text_to_ucs2_str(
            (U8*) MMI_OPP_CTX(sending_obj_name),
            OPP_MAX_OBJ_NAME_LENGTH,
            (U8*) filename_p,
            PhnsetGetDefEncodingType());

            MMIOPP_RESET_FLAG(MMIOPP_MASK_SHORT_NAME);
         }
        else
        {
        if (mmi_ucs2strlen((S8*) filename_p) * 2 > (sizeof(MMI_OPP_CTX(sending_obj_name)) - 2))
        {
            memcpy(
                MMI_OPP_CTX(sending_obj_name),
                filename_p + (mmi_ucs2strlen((S8*) filename_p) * 2) - (sizeof(MMI_OPP_CTX(sending_obj_name)) - 2),
                sizeof(MMI_OPP_CTX(sending_obj_name)) - 2);
        }
        else
        {
            memcpy(MMI_OPP_CTX(sending_obj_name), filename_p, sizeof(MMI_OPP_CTX(sending_obj_name)) - 2);
        }
	   
        }
    }
    else
    {
        kal_wsprintf((U16*) MMI_OPP_CTX(sending_obj_name), "%s", MMI_OPP_SND_DEFAULT_OBJNAME);
    }
    
    /* Get object mime */
    memset(MMI_OPP_CTX(sending_obj_mime), 0, sizeof(MMI_OPP_CTX(sending_obj_mime)));
    mimetype_p = mmi_opp_get_file_mime_type((U16*)MMI_OPP_CTX(sending_obj_name));

    if (mimetype_p != NULL)
    {
	    if (strlen((const char*)mimetype_p) > OPP_MAX_OBJ_MIME_LENGTH)
        {
            MMI_OPP_ASSERT(0);
        }
	    memcpy(MMI_OPP_CTX(sending_obj_mime), mimetype_p, strlen((const char*)mimetype_p));

        kal_prompt_trace(MOD_MMI, "mmi_opp_send_file_obj mime type (%s)", mimetype_p);
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "mmi_opp_send_file_obj mime type (empty)");
    }

#if 0 /* legacy inquery */
/* under construction !*/
/* under construction !*/
#else
    /* new device inquery with my devices */
    mmi_bt_get_selected_specfic_device_info((void *)&bt_dev_p);
#endif

    a.nap = bt_dev_p.bd_addr.nap;
    a.uap = bt_dev_p.bd_addr.uap;
    a.lap = bt_dev_p.bd_addr.lap;
    
    ops_bt_divice.nap = bt_dev_p.bd_addr.nap;
    ops_bt_divice.uap = bt_dev_p.bd_addr.uap;
    ops_bt_divice.lap = bt_dev_p.bd_addr.lap;
    
    mmi_bt_oppc_connect_req((U16) OPPC_MAX_OBEX_PACKET_LENGTH, a);
    mmi_opp_entry_fmgr_fwd();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_snd_disconnect
 * DESCRIPTION
 *  This is common function to disconnect
 * PARAMETERS
 *  void
 *  cause(?)        [IN]        The cause to disconnect current session
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_snd_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_opp_disconnect_req(MMI_OPP_CTX(oppc_goep_conn_id));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_snd_abort
 * DESCRIPTION
 *  This is common function to abort sending object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_snd_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_OPP_LOG(MMI_BT_OPP_OPP_SND_ABORT);
    MMI_OPP_LOG_STATE();

    mmi_opp_entry_abort_fwd();
    MMIOPP_SET_FLAG(MMIOPP_MASK_ABORT_PRESS);

    mmi_bth_reg_pairing_permission(MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID, (void *)mmi_bt_opp_passkey_hdler);

    if (MMI_OPP_CTX(opc_state) == MMI_OPC_SENDING)
    {
         /* send abort request because user already abort */
        mmi_bt_oppc_abort_req(MMI_OPP_CTX(oppc_goep_conn_id));
        MMI_OPC_STATE_TRANS(MMI_OPC_ABORTING);   
        StartTimer(BT_OPP_ABORT_REQ_TIMER, OPPC_PROG_UPD_DUR, mmi_bt_opp_deal_abort_hdlr);
    }
    else if (MMI_OPP_CTX(opc_state) == MMI_OPC_CONNECTING)
    {
        /* disconnect the unestablished connecttion with 0xff goep conn id*/
        /* set oppc_goep_conn_id = 0xff for disconnect indication/response goep_conn_id check */
        MMI_OPP_CTX(oppc_goep_conn_id) = 0xff; 
        mmi_bt_opp_disconnect_req(0xff);
        MMI_OPC_STATE_TRANS(MMI_OPC_DISCONNECTING);
    }        
    else
    {        
        mmi_bt_oppc_abort_req(MMI_OPP_CTX(oppc_goep_conn_id));
        MMI_OPC_STATE_TRANS(MMI_OPC_ABORTING);        
    }

    SetDelScrnIDCallbackHandler(SCR_OPP_SENDING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_SENDING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opps_disconnect_client
 * DESCRIPTION
 *  This function is to disconnect the OPS connection
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opps_disconnect_client(mmi_bth_bt_addr bd_addr, U32 g_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG1(MMI_BT_OPP_OPPS_DISC_CLIENT, g_conn_id);
    MMI_OPP_LOG_STATE();
    MMI_OPS_STATE_TRANS(MMI_OPS_DISCONNECTING);
    MMI_OPP_CTX(disconnflag)=MMI_TRUE;
    /* Send OPP disconnect request to OBEX */
    mmi_bt_opp_disconnect_req(MMI_OPP_CTX(opps_goep_conn_id));
    mmi_opp_scr_data_stop_ind(MMI_BT_SERVER_ROLE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_opp_ops_connection_terminated
 * DESCRIPTION
 *  This is common function to deal with ops disconnect
 * PARAMETERS
 *  cause       [IN]        The cause for connection terminated
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_ops_connection_terminated(U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG1(MMI_BT_OPP_OPPS_CONN_TERM, cause);
    MMI_OPP_LOG_STATE();

    if (MMI_OPP_CTX(h_recv))
    {
        U8 *path_buf;
        
        FS_Close(MMI_OPP_CTX(h_recv));
        MMI_OPP_CTX(h_recv) = (FS_HANDLE) NULL;
       
        path_buf = OslMalloc(FMGR_MAX_PATH_LEN * ENCODING_LENGTH);
        MMI_OPP_MAKE_RECV_FILENAME(path_buf, MMI_OPP_CTX(fcnt));
        FS_Delete((const WCHAR*)path_buf);
        OslMfree(path_buf);
    }

    if(MMI_OPP_CTX(disconnflag)==MMI_FALSE)
    {
    mmi_bth_disconnect_ind_hdler(
        MMI_OPP_CTX(bt_device.lap),
        MMI_OPP_CTX(bt_device.uap),
        MMI_OPP_CTX(bt_device.nap),
        MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID,
        MMI_OPP_CTX(opps_cm_conn_id));
        
        /* Notify MMI Screen */
        mmi_opp_scr_data_stop_ind(MMI_BT_SERVER_ROLE);
    }
    else
    {
        mmi_bth_disconnect_cnf_hdler(
            MMI_TRUE,
            MMI_OPP_CTX(bt_device).lap,
            MMI_OPP_CTX(bt_device).uap,
            MMI_OPP_CTX(bt_device).nap,
            MMI_BTH_OBEX_OBJECT_PUSH_SERVICE_UUID,
            MMI_OPP_CTX(opps_cm_conn_id));
    }

    if (MMI_OPP_CTX(cur_recv_file_cnt) > 0)
    {
        mmi_opp_scr_recv_obj_ind();
    }

    SetDelScrnIDCallbackHandler(SCR_OPP_NOTY_RECV_ACCEPT, (HistoryDelCBPtr)NULL);
    if (GetActiveScreenId() == SCR_OPP_NOTY_RECV_ACCEPT)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_OPP_NOTY_RECV_ACCEPT);
    }

    /* reset OPPS connection related context */
    MMI_OPP_CTX(h_recv) = (FS_HANDLE) NULL;
    MMI_OPP_CTX(opps_goep_req_id) = 0xff;    
    MMI_OPP_CTX(opps_cm_conn_id) = 0xff;       
    MMI_OPP_CTX(fcnt) = 0;
    MMI_OPP_CTX(cur_recv_file_cnt) = 0;
    MMI_OPP_CTX(disconnflag) = MMI_FALSE;

    MMI_OPS_STATE_TRANS(MMI_OPS_ACTIVE);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_opc_connection_terminated
 * DESCRIPTION
 *  This is common function to deal with opc disconnect
 * PARAMETERS
 *  cause       [IN]        The cause for connection terminated
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_opc_connection_terminated(U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_scr_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG1(MMI_BT_OPP_OPPC_CONN_TERM, cause);
    MMI_OPP_LOG_STATE();

    if (MMI_OPP_CTX(h_snd))
    {
        FS_Close(MMI_OPP_CTX(h_snd));
        MMI_OPP_CTX(h_snd) = (FS_HANDLE) NULL;
    }

    /*when user press end key or plug in usb,it only display "Disconnecting",can not popup "unfinished"*/
    if (MMI_OPP_CTX(opc_state) == MMI_OPC_TPDISCONNECTING || MMIOPP_GET_FLAG(MMIOPP_MASK_ABORT_PRESS))
    {
        MMI_OPP_CTX(app_callback_fp) = NULL;
        MMIOPP_RESET_FLAG(MMIOPP_MASK_ABORT_PRESS);
    }
    /* mmi_bt_opp_exe_endkey_hdlr() this function position will infect the history position of  disconnecting screen  */
    if (MMIOPP_GET_FLAG(MMIOPP_MASK_EMDKEY_PRESS) && !isInCall())
    {
        //mmi_bt_opp_exe_endkey_hdlr();
        DisplayIdleScreen();
    }
    MMIOPP_RESET_FLAG(MMIOPP_MASK_EMDKEY_PRESS); 
       
    /* Execute application callback function if any */
    if (MMI_OPP_CTX(app_callback_fp))
    {
        (*(MMI_OPP_CTX(app_callback_fp))) (NULL, cause);
        MMI_OPP_CTX(app_callback_fp) = NULL;
    }
    SetDelScrnIDCallbackHandler(SCR_OPP_SENDING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_SENDING);
    SetDelScrnIDCallbackHandler(SCR_OPP_ABORTING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_ABORTING);
    SetDelScrnIDCallbackHandler(SCR_OPP_DISCONNECTING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_DISCONNECTING);

    cur_scr_id = GetActiveScreenId();
    switch (cur_scr_id)
    {
        case SCR_OPP_ABORTING:
        case SCR_OPP_DISCONNECTING:
        GoBackHistory();
        default:
            break;
    }

    if (MMI_OPP_CTX(opc_state) == MMI_OPC_CONNECTING)
    {
        mmi_bt_reject_passkey_ind();
    }
    switch (MMI_OPP_CTX(opc_state))
    {
        case MMI_OPC_IDLE:
        case MMI_OPC_CONNECTING:
        case MMI_OPC_CONNECTED:
        case MMI_OPC_SENDING:
        case MMI_OPC_ABORTING:
        case MMI_OPC_DISCONNECTING:
        case MMI_OPC_TPDISCONNECTING:
            MMI_OPP_CTX(oppc_goep_conn_id) = 0xff;
            MMI_OPP_CTX(oppc_cm_conn_id) = 0xff;
            MMI_OPC_STATE_TRANS(MMI_OPC_IDLE);
            break;

        default:
            MMI_OPC_LOG_STATE_ERR();
            break;
    }

    mmi_opp_scr_data_stop_ind(MMI_BT_CLIENT_ROLE);
    mmi_bt_close();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_accept_file_recv
 * DESCRIPTION
 *  This function is to accept receving file object.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_accept_file_recv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_ACCEPT_FILE_RECV);
    MMI_OPP_LOG_STATE();

    /*when user accept, notify cm connection has been setted up*/
    mmi_bt_opp_notify_cm_conn_ind();

    SetDelScrnIDCallbackHandler(SCR_OPP_NOTY_RECV_ACCEPT, (HistoryDelCBPtr) NULL);
    GoBackHistory();
#ifdef __BQB_PTS__
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_ACCEPTED)
    {
        /* Notify MMI Screen */
        mmi_opp_scr_data_transfer_ind(MMI_BT_SERVER_ROLE);    	
        mmi_bt_opps_first_push_ind_handler((void*)first_push_ind_ptr);
        free_local_para(first_push_ind_ptr);
        first_push_ind_ptr = NULL;
    }
#else
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_ACCEPTING)
    {
        MMI_OPS_STATE_TRANS(MMI_OPS_ACTIVE);
        /* Send success connect response to OBEX task */
        mmi_bt_opps_authorize_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_STATUS_SUCCESS);    /* profile accept it */
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_reject_file_recv
 * DESCRIPTION
 *  This function is to reject receving file object.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_reject_file_recv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_REJECT_FILE_RECV);
    MMI_OPP_LOG_STATE();

    SetDelScrnIDCallbackHandler(SCR_OPP_NOTY_RECV_ACCEPT, (HistoryDelCBPtr) NULL);
    if (GetActiveScreenId() == SCR_OPP_NOTY_RECV_ACCEPT)
    {
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_OPP_NOTY_RECV_ACCEPT);
    }
#ifdef __BQB_PTS__    
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_ACCEPTED)
    {
        /* User reject */
        mmi_bt_opps_push_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_NOT_ACCEPTABLE);
        free_local_para(first_push_ind_ptr);
        first_push_ind_ptr = NULL;
    }
#else
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_ACCEPTING)
    {
        MMI_OPS_STATE_TRANS(MMI_OPS_ACTIVE);
        /* User reject */
        mmi_bt_opps_authorize_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_FORBIDDEN);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_confirm_del_cb
 * DESCRIPTION
 *  This function is to reject the connect when confirm screen is deleted
 * PARAMETERS
 *  p           [?]             
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_opp_confirm_del_cb(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_BT_OPP_CONFIRM_DEL_CB);
    MMI_OPP_LOG_STATE();

#ifdef __BQB_PTS__
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_ACCEPTED)
    {
        mmi_bt_opps_push_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_NOT_ACCEPTABLE);
        free_local_para(first_push_ind_ptr);
        first_push_ind_ptr = NULL;        
    }
#else
    if (MMI_OPP_CTX(ops_state) == MMI_OPS_ACCEPTING)
    {
        /* Send success connect response to OBEX task */
        MMI_OPS_STATE_TRANS(MMI_OPS_ACTIVE);
        mmi_bt_opps_authorize_res(MMI_OPP_CTX(opps_goep_conn_id), GOEP_FORBIDDEN);  /* profile reject it */
    }
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_discovery_device
 * DESCRIPTION
 *  This function is to find opp supported device
 * PARAMETERS
 *  path        [?]             
 *  fp          [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  void
 *****************************************************************************/
MMI_OPP_SND_ERR_TYPE mmi_opp_discovery_device(S8 *path, mmi_opp_sendobj_callback_fptr fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if the OPC channel is already used */
    MMI_OPP_LOG(MMI_BT_OPP_DISCOVERY_DEVICE);
    MMI_OPP_LOG_STATE();

    if (MMI_OPP_CTX(opc_state) > MMI_OPC_IDLE)
    {
        DisplayPopup(
            (U8*) GetString(STR_OPP_DEV_BUSY),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return MMI_OPP_ERR_SENDING;
    }

    /* file path is null, return to application */
    if (!path)
    {
        MMI_OPP_ASSERT(0);  /* assert! for easy debuging */
        mmi_opp_opc_connection_terminated(MMI_OPP_ERR_BAD_FILE);
        return MMI_OPP_ERR_BAD_FILE;
    }
    else
    {
        mmi_ucs2cpy(MMI_OPP_CTX(fwd_file_path), path);
    }
    /* First, store the callback functionif any */
    /* In case send fail, clean up function will be able to callback */
    MMI_OPP_CTX(app_callback_fp) = fp;

    return MMI_OPP_ERR_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_event_hdlr
 * DESCRIPTION
 *  This function is to handle OPP event from OBEX
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_event_hdlr(msg_type msg_id, void* msg)
{
    MMI_OPP_LOG_STATE();
    MMI_OPP_LOG3(MMI_BT_OPP_OPPS_CTX, MMI_OPP_CTX(opps_goep_req_id), MMI_OPP_CTX(opps_goep_conn_id), MMI_OPP_CTX(opps_cm_conn_id));
    MMI_OPP_LOG3(MMI_BT_OPP_OPPC_CTX, MMI_OPP_CTX(oppc_goep_req_id), MMI_OPP_CTX(oppc_goep_conn_id), MMI_OPP_CTX(oppc_cm_conn_id));

    switch(msg_id)
    {
        /* OPP client/server common event */
        case MSG_ID_GOEP_DISCONNECT_RSP:
            mmi_bt_opp_disconnect_rsp_handler(msg);
            break;        
        case MSG_ID_GOEP_DISCONNECT_IND:
            mmi_bt_opp_disconnect_ind_handler(msg);
            break;
        case MSG_ID_GOEP_ABORT_IND:
            mmi_bt_opp_abort_ind_handler(msg);
            break;
        
        /* OPP client specific event */
        case MSG_ID_GOEP_CONNECT_RSP:
            mmi_bt_oppc_connect_rsp_handler(msg);
            break;
        case MSG_ID_GOEP_PUSH_RSP:            
            mmi_bt_oppc_push_rsp_handler(msg);
            break;
        case MSG_ID_GOEP_ABORT_RSP:
            mmi_bt_oppc_abort_rsp_handler(msg);
            break;

        /* OPP server event */                                
        case MSG_ID_GOEP_REGISTER_SERVER_RSP:
            mmi_bt_opps_obex_register_server_rsp_handler(msg);
            break;
        case MSG_ID_GOEP_DEREGISTER_SERVER_RSP:
            mmi_bt_opps_obex_deregister_server_rsp_handler(msg);
            break;
        case MSG_ID_GOEP_CONNECT_IND:
            mmi_bt_opps_connect_ind_handler(msg);
            break;            
        case MSG_ID_GOEP_PUSH_IND:
            mmi_bt_opps_push_ind_handler(msg);
            break;
        case MSG_ID_GOEP_AUTHORIZE_IND:
            mmi_bt_opps_authorize_ind_hdler(msg);
            break;        
        case MSG_ID_GOEP_PULL_IND:
            mmi_bt_opps_pull_ind_handler(msg);
            break;
        default:
            mmi_bt_opp_tpdisconnect_req(MMI_OPP_CTX(opps_goep_conn_id));
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bth_opp_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMI_OPP_CTX(opc_state))
    {
        case MMI_OPC_CONNECTING:
        case MMI_OPC_CONNECTED:
        case MMI_OPC_SENDING:
        case MMI_OPC_ABORTING:
        case MMI_OPC_DISCONNECTING:
        case MMI_OPC_TPDISCONNECTING:    
            mmi_opp_opc_connection_terminated(MMI_OPP_ERR_DISCONNECT);
            break;
        default:
            break;            
    }
    
    switch (MMI_OPP_CTX(ops_state))
    {
        case MMI_OPS_ACCEPTING:
        case MMI_OPS_ACCEPTED:
        case MMI_OPS_RECEIVING:
        case MMI_OPS_ABORTING:
        case MMI_OPS_DISCONNECTING:
            mmi_opp_ops_connection_terminated(MMI_OPP_ERR_DISCONNECT);
            break;
        default:
            break;            
    }                   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_disconncting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
BOOL mmi_opp_disconncting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_OPC_DISCONNECTING== MMI_OPP_CTX(opc_state))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_end_key_press_hdler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_end_key_press_hdler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMIOPP_SET_FLAG(MMIOPP_MASK_EMDKEY_PRESS);
    
    /*when user press cancel, and then press end key or plug in usb,
      it only display "aborting"screen and back to idle */
    if (MMI_OPP_CTX(opc_state) !=MMI_OPC_DISCONNECTING && MMI_OPP_CTX(opc_state) !=MMI_OPC_ABORTING)
    {   
        mmi_opp_entry_disconnting();
    
        mmi_bt_opp_tpdisconnect_req(MMI_OPP_CTX(oppc_goep_conn_id));
        MMI_OPC_STATE_TRANS(MMI_OPC_TPDISCONNECTING);
    }
    
    SetDelScrnIDCallbackHandler(SCR_OPP_SENDING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_SENDING);
    SetDelScrnIDCallbackHandler(SCR_OPP_ABORTING, (HistoryDelCBPtr) NULL);
    DeleteScreenIfPresent(SCR_OPP_ABORTING);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_send_file_to_dev
 * DESCRIPTION
 *   send file to the specified dst dev
 * PARAMETERS
 *  file_name_with_path : file name with path
 *  callback_f: callback func
 *  dst_dev: dst dev
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_bt_opp_send_file_to_dev(
        S8 *file_name_with_path, 
        MMI_BOOL is_short, 
        void* callback_f,
        void *dst_dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if the OPC channel is already used */
    MMI_OPP_LOG_STATE();

    if (MMI_OPP_CTX(opc_state) > MMI_OPC_IDLE)
    {
        DisplayPopup(
            (U8*) GetString(STR_OPP_DEV_BUSY),
            IMG_GLOBAL_ERROR,
            MMI_FALSE,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) ERROR_TONE);
        return MMI_OPP_ERR_SENDING;
    }

    /* file path is null, return to application */
    if (!file_name_with_path)
    {
        MMI_OPP_ASSERT(0);  /* assert! for easy debuging */
        mmi_opp_opc_connection_terminated(MMI_OPP_ERR_BAD_FILE);
        return MMI_OPP_ERR_BAD_FILE;
    }
    else
    {
        mmi_ucs2cpy(MMI_OPP_CTX(fwd_file_path), file_name_with_path);
    }
    /* First, store the callback functionif any */
    /* In case send fail, clean up function will be able to callback */
    MMI_OPP_CTX(app_callback_fp) = (mmi_opp_sendobj_callback_fptr)callback_f;

    if (is_short)
    {
        MMIOPP_SET_FLAG(MMIOPP_MASK_SHORT_NAME);
    }
    /* send file */
    mmi_opp_send_file_obj();
    
    return MMI_OPP_ERR_SUCCESS;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_passkey_hdler
 * DESCRIPTION
 *  this function is used to control whether passkey screen popup, 
    if return true, it can enter passkey, otherwise not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_bt_opp_passkey_hdler(mmi_bth_bt_addr bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ( MMI_OPP_CTX(opc_state) == MMI_OPC_DISCONNECTING ||
             MMI_OPP_CTX(opc_state) == MMI_OPC_ABORTING)  
    {
        if ( ops_bt_divice.lap == bd_addr.lap &&
             ops_bt_divice.nap == bd_addr.nap &&
             ops_bt_divice.uap == bd_addr.uap)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}

#endif /* __MMI_BT_MTK_SUPPORT__ */
#endif /* __MMI_OPP_SUPPORT__ */ 

