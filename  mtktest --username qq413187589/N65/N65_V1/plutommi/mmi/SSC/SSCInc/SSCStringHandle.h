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
 * SSCStringHandle.h
 *
 * Project:
 * --------
 *   PlutoMMI
 *
 * Description:
 * ------------
 *   To handle the ssc string.
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

#ifndef __SSC_STRING_HANDLE_H__
#define __SSC_STRING_HANDLE_H__

/* micha1217 */
#include "MMI_features.h"
#include "SSCResDef.h"

extern void SSCStringParsing1(void);
extern pBOOL SSCStringParsing2(void);
extern pBOOL SSCStringParsing3(void);

#define MAX_IMEI_LEN 15
#define MAX_IMEISV_LEN  2
#define MAX_IMEISV_DISPLAY_LEN 32       /* including null-terminator */
#define MAX_SW_VER_LEN   30
#define MAX_SSC_STRING  30 * ENCODING_LENGTH    /* it means the maximun can not be more than 60/2(UCS2) word */

#define SSC_POP_UP_TIME    UI_POPUP_NOTIFYDURATION_TIME_2000

/* micha1129 */
#define SSC_AUTO "*#0000#"
#define SSC_SCHINESE "*#0086#"
#define SSC_TCHINESE "*#0886#"
#define SSC_ENGLISH     "*#0044#"
#define SSC_DEFAULT     "*#0044#"
#define SSC_SPANISH  "*#0034#"
#define SSC_DANISH   "*#0045#"
#define SSC_POLISH   "*#0048#"
#define SSC_THAI  "*#0066#"
#define SSC_FRENCH      "*#0033#"
#define SSC_GERMAN   "*#0049#"
#define SSC_ITALIAN  "*#0039#"
#define SSC_RUSSIAN  "*#0007#"
#define SSC_BULGARIAN   "*#0359#"
#define SSC_UKRAINIAN   "*#0380#"
#define SSC_PORTUGUESE  "*#0351#"
#define SSC_TURKISH  "*#0090#"
#define SSC_VIETNAMESE     "*#0084#"
#define SSC_INDONESIAN  "*#0062#"
#define SSC_CZECH "*#0420#"
#define SSC_MALAY "*#0060#"
#define SSC_NORWEGIAN   "*#0047#"
#define SSC_ARABIC "*#0966#"
#define SSC_PERSIAN "*#0098#"
#define SSC_URDU "*#0092#"
#define SSC_HINDI "*#0091#"
#define SSC_TAMIL "*#9144#"
#define SSC_BENGALI "*#9133#"
#if defined (__MMI_LANG_PUNJABI__)
#define SSC_PUNJABI "*#9172#"
#endif
#if defined (__MMI_LANG_TELUGU__)
#define SSC_TELUGU "*#9140#"
#endif
#define SSC_MARATHI  "*#9122#"
#define SSC_HEBREW "*#0972#"

#define SSC_FINNISH  "*#0358#"
#define SSC_HUNGARIAN   "*#0036#"
#define SSC_SLOVAK   "*#0421#"
#define SSC_DUTCH "*#0031#"
#define SSC_SWEDISH  "*#0046#"
#define SSC_CROATIAN "*#0385#"
#define SSC_ROMANIAN "*#0040#"
#define SSC_SLOVENIAN   "*#0386#"
#define SSC_GREEK "*#0030#"
#define MEM_CTRL_BUF_DBG    "*035670766*001*"
#define MEM_CTRL_BUF_QRY    "*#035670766*001#"

#define TASK_CTRL_BUF_DBG    "*035670766*002*"
#define TASK_CTRL_BUF_QRY    "*#035670766*002#"

#if defined(__MMI_A2DP_SUPPORT__)
#define SSC_BT_A2DP_TOGGLE_PTS_MODE "*#1234#"
#endif


/* temp for bluetooth poweron if define __BTMTK__ */
#define BT_POWER_ON "*#900#"
#define BT_POWER_OFF "*#901#"
/* for pts V2.1.0.4 */
/* cannot update indicators to remote bluetooth headset while HFP is connected */
/* indicators shall be retrieved by remote HF AT+CIND? */
/* so for pts V2.1.0.4, host will not udpate indicators while HFP is just connected */
#define BT_PTS_ON                       "*#902#"
#define BT_PTS_OFF                      "*#903#"

#define SSC_STRING_TIMEOUT    2000

extern char *release_verno(void);

/* micha1217 */
#ifdef __MMI_HW_VERSION__
extern char *release_hw_ver(void);
#endif 

extern void mmi_ssc_get_imei_rsp(void *);
extern U8 mmi_ssc_check_diff_password(PS8 ssc_head);
extern void mmi_ssc_sim_operation_handler(U8 *number);
extern MMI_BOOL mmi_ssc_is_sim_operation(U8 *number, U8 dcs);
extern void mmi_ssc_delete_sim_operation_screens(void);
extern void mmi_ssc_send_ss_parsing_req(S8 *sim_operation_string, U8 dest_mod_id);

#ifdef __MMI_DUAL_SIM_MASTER__
extern void mmi_ssc_request_pin1_status(void);
extern void mmi_ssc_request_pin2_status(void);
extern void mmi_ssc_entry_puk1(void);
extern void mmi_ssc_entry_puk2(void);
extern void mmi_ssc_change_sim2_pin1_password_rsp(void *);
extern void mmi_ssc_change_sim2_pin2_password_rsp(void *);
extern void mmi_ssc_verify_pin_rsp(void *);
#endif /* __MMI_DUAL_SIM_MASTER__ */

#endif /* __SSC_STRING_HANDLE_H__ */

