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
 *   mdi_datatype.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Audio interfce header file
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MDI_INCLUDE
#define MDI_INCLUDE

#ifndef _MMI_DATA_TYPE_H
#error "Please include MMIDataType.h"
#endif 

/***************************************************************************** 
* Define
*****************************************************************************/
/* MDI_DEVICE_TYPE */
#define MDI_DEVICE_AUDIO      0x0001
#define MDI_DEVICE_CAMER      0x0002
#define MDI_DEVICE_VIDEO      0x0004
#define MDI_DEVICE_ALL        0x0007

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef U16 MDI_DEVICE_TYPE;

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* 
 * This function is used for multiple tasks to get owner shipof multimedia device,
 * such as audio, camera and video, etc.
 * The previous action on this device will be forced to terminate.
 */
extern void mdi_switch_device_ownership(module_type mod_id, MDI_DEVICE_TYPE device);
extern module_type mdi_get_device_ownership(MDI_DEVICE_TYPE device);
extern BOOL mdi_check_device_ownership(void);


/* get blt data for video camera display - internal by MDI modules */
extern void mdi_calc_blt_para(
                gdi_handle disp_layer_handle, 
                U16 lcd_rotate, 
                gdi_handle lcd_handle,   
                MMI_BOOL is_tvout,
                mdi_blt_para_struct *blt_data_p);

/* message dispatcher, for other task to use MDI library, add to its message handler */
extern MMI_BOOL mdi_message_dispatcher(void *ilm_ptr);


#endif /* MDI_INCLUDE */ 

