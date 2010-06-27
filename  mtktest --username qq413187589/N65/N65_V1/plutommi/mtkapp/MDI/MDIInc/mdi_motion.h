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
 *  mdi_motion.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Motion sensor related interface header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MDI_MOTION_H_
#define _MDI_MOTION_H_

#ifdef __MMI_MOTION_APP__

/***************************************************************************** 
* Include
*****************************************************************************/

/***************************************************************************** 
* Define
*****************************************************************************/
#define MDI_RES_MOTION_SUCCEED                        0
#define MDI_RES_MOTION_ERR_FAILED                     -6000

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    MDI_MOTION_SENSITIVE_LOW,
    MDI_MOTION_SENSITIVE_NORMAL,
    MDI_MOTION_SENSITIVE_HIGH,

    NUM_OF_MDI_MOTION_SENSITIVE
} mdi_motion_sensitive_enum;

typedef void (*mdi_motion_shake_callback) (void);
typedef void (*mdi_motion_tile_callback) (S32 x, S32 y, S32 z);

/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/

/*****************************************************************************              
* Extern Global Function                                                                    
*****************************************************************************/
extern MDI_RESULT mdi_motion_init(void);
extern MDI_RESULT mdi_motion_power_on(void);
extern MDI_RESULT mdi_motion_power_off(void);

extern MDI_RESULT mdi_motion_start_listen_shake(U16 sensitive, mdi_motion_shake_callback shake_event_callback);

extern MDI_RESULT mdi_motion_start_listen_tile(
                    U16 sensitive,
                    S32 min_callback_time,
                    S32 max_callback_time,
                    mdi_motion_tile_callback tile_event_callback);

extern MDI_RESULT mdi_motion_stop_listen(void);

/* calibration */
extern MDI_RESULT mdi_motion_start_cali(void);
extern MDI_RESULT mdi_motion_confirm_cali(void);
extern MDI_RESULT mdi_motion_cancel_cali(void);
extern MDI_RESULT mdi_motion_save_cali_data(void);
extern MDI_RESULT mdi_motion_load_cali_data(void);

#endif /* __MMI_MOTION_APP__ */ 
#endif /* _MDI_MOTION_H_ */ 

