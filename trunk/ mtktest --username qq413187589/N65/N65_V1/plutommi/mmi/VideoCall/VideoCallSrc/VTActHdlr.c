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
 *  VTActHdlr.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  MMI VT action handler file
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_VIDEO_TELEPHONY__
#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"
#include "DateTimeGprot.h"
#include "csmcc_common_enums.h"

#include "CallStructureManagementProtEx.h"
#include "CommonStubsProtEx.h"
#include "CallManagementStructEx.h"

#include "UCMGProt.h"
#include "UCMCallProt.h"
#include "UCMResDef.h"

#include "VTGProt.h"
#include "VTProt.h"
#include "VTResDef.h"

/* 
 * Global Function
 */
extern MakeCallEx(PS8 strNumber, BOOL pre_check, U8 call_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_ucm_act_req
 * DESCRIPTION
 *  function which is called by UCM
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_ucm_act_req(U8 op_code, void *act_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op_code)
    {
    	case MMI_UCM_DIAL:
        {
			S8 dial_number[MAX_NUMBER];
            
            SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_DIAL);
    
            memset(dial_number, 0, MAX_NUMBER);
            mmi_asc_to_ucs2((PS8) dial_number, (PS8)((mmi_ucm_dial_req_struct*) act_struct)->num_uri);
        	mmi_vt_make_video_call((PS8)dial_number);
        }
        break;

        case MMI_UCM_ACCEPT:
        {
            SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_ACCEPT);
			mmi_gsm_accept(act_struct);
        }
        break;

        case MMI_UCM_END_SINGLE:
        {
            SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_END_SINGLE);
			mmi_gsm_end_single(act_struct);
        }
        break;

        case MMI_UCM_FORCE_RELEASE:
        {
            SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_FORCE_RELEASE);
			mmi_gsm_force_release(act_struct);
        }
		break;

        case MMI_UCM_AUTO_REJECT:
        {
            SetUCMOperationState(MMI_GSM_UCM_NORMAL, MMI_GSM_UCM_AUTO_REJECT);
			mmi_gsm_auto_reject(act_struct);
        }
		break;
			
    	default:
        {
            MMI_ASSERT(0);
        }
        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vt_make_video_call
 * DESCRIPTION
 *  Make video call
 *  This function is exported to UCM
 * PARAMETERS
 *  strNumber       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vt_make_video_call(S8 *strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GetExitScrnID() == SCR_ID_VT_INCALL) || (IsScreenPresent(SCR_ID_VT_INCALL)))
    {
        /* camera status should be set before entering vt incall screen */
    }
    else
    {
        if (g_vt_p->setting.dial_mode == MMI_VT_DIAL_MODE_STOP_CAMERA)
        {
            mmi_vt_set_camera_status(MMI_FALSE);
        }
        else
        {
            mmi_vt_set_camera_status(MMI_TRUE);
        }
    }
    
    mmi_ucs2ncpy((S8*)g_vt_p->mo_info.dial_pad_buffer, (S8*)strNumber, MMI_UCM_MAX_NUM_URI_LEN);    
    MakeCallEx(strNumber, FALSE, CSMCC_VIDEO_CALL);
}
#endif /* __MMI_VIDEO_TELEPHONY__ */

