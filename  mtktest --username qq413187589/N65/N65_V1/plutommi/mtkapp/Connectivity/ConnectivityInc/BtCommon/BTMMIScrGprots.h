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
 * BTMMIScrGprots.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file of btmmiscr.c
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
#ifndef __BT_MMI_SCR_GPROTS_H__
#define __BT_MMI_SCR_GPROTS_H__

/***************************************************************************** 
* Extern Global Function Pointer
*****************************************************************************/
extern PS8(*mmi_bt_ucs2_str_utility) (S8 *str_dest, const S8 *str_src);

/***************************************************************************** 
* Enum
*****************************************************************************/
typedef enum
{
    MMI_BT_SERVER_ROLE,
    MMI_BT_CLIENT_ROLE
} MMI_BT_PROFILE_ROLE;

/***************************************************************************** 
* Definitions
*****************************************************************************/
/* class of device bit mask */
/* Major Service Mask		*/
#define MMI_BT_POSTIONING_MAJOR_SERVICE_MASK							(0x010000)
#define MMI_BT_NETWORKING_MAJOR_SERVICE_MASK							(0x020000)
#define MMI_BT_RENDERING_MAJOR_SERVICE_MASK							    (0x040000)
#define MMI_BT_CAPTURING_MAJOR_SERVICE_MASK							    (0x080000)
#define MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK						(0x100000)
#define MMI_BT_AUDIO_MAJOR_SERVICE_MASK								    (0x200000)
#define MMI_BT_TELEPHONY_MAJOR_SERVICE_MASK							    (0x400000)
#define MMI_BT_INFORMATION_MAJOR_SERVICE_MASK							(0x800000)

/* Major Device Mask		*/
#define MMI_BT_MISCELLANEOUS_MAJOR_DEVICE_MASK							(0x000000)
#define MMI_BT_COMPUTER_MAJOR_DEVICE_MASK								(0x000100)
#define MMI_BT_PHONE_MAJOR_DEVICE_MASK									(0x000200)
#define MMI_BT_LAN_MAJOR_DEVICE_MASK									(0x000300)
#define MMI_BT_AV_MAJOR_DEVICE_MASK									    (0x000400)
#define MMI_BT_PERIPHERAL_MAJOR_DEVICE_MASK							    (0x000500)
#define MMI_BT_IMAGING_MAJOR_DEVICE_MASK							    (0x000600)
#define MMI_BT_UNCLASSIFIED_MAJOR_DEVICE_MASK							(0x001F00)

/* Minor Device	Mask under computer major class	*/													
#define MMI_BT_DESKTOP_WORKSTATION_MINOR_DEVICE_MASK					(0x000004)
#define MMI_BT_SERVER_CLASS_COMPUTER_MINOR_DEVICE_MASK					(0x000008)
#define MMI_BT_LAPTOP_MINOR_DEVICE_MASK								    (0x00000C)
#define MMI_BT_HANDHELP_PC_PDA_MINOR_DEVICE_MASK						(0x000010)
#define MMI_BT_PALM_SIZED_PC_PDA_MINOR_DEVICE_MASK						(0x000014)
#define	MMI_BT_UNCLASSIFIED_COMPUTER_MINOR_DEVICE_MASK					(0x000000)

/* Minor Device	Mask under phone major class	*/
#define MMI_BT_CELLULAR_MINOR_DEVICE_MASK								(0x000004)
#define MMI_BT_CORDLESS_MINOR_DEVICE_MASK								(0x000008)
#define MMI_BT_SMART_PHONE_MINOR_DEVICE_MASK							(0x00000C)
#define MMI_BT_WIRED_MODEM_OR_VOICE_GATEWAY_MINOR_DEVICE_MASK			(0x000010)	
#define	MMI_BT_UNCLASSIFIED_PHONE_MINOR_DEVICE_MASK					    (0x000000)

/* Minor Device	Mask under audio/video major class	*/
#define	MMI_BT_UNCATEGORISED_AV_MINOR_DEVICE_MASK						(0x000000)
#define MMI_BT_WEARABLE_HEADSET_AV_MINOR_DEVICE_CLASS					(0x000004)
#define MMI_BT_HANDSFREE_AV_MINOR_DEVICE_CLASS							(0x000008)
#define MMI_BT_MICROPHONE_AV_MINOR_DEVICE_CLASS						    (0x000010)
#define MMI_BT_LOUDSPEAKER_AV_MINOR_DEVICE_CLASS						(0x000014)
#define MMI_BT_HEADPHONES_AV_MINOR_DEVICE_CLASS						    (0x000018)
#define MMI_BT_PORTABLE_AUDIO_AV_MINOR_DEVICE_CLASS					    (0x00001C)
#define MMI_BT_CAR_AUDIO_AV_MINOR_DEVICE_CLASS							(0x000020)
#define MMI_BT_SETTOP_BOX_AV_MINOR_DEVICE_CLASS						    (0x000024)
#define MMI_BT_HIFI_AUDIO_AV_MINOR_DEVICE_CLASS						    (0x000028)
#define MMI_BT_VCR_AV_MINOR_DEVICE_CLASS								(0x00002C)
#define MMI_BT_VIDEO_CAMERA_AV_MINOR_DEVICE_CLASS						(0x000030)
#define MMI_BT_CAMCORDER_AV_MINOR_DEVICE_CLASS							(0x000034)
#define MMI_BT_VIDEO_MONITOR_AV_MINOR_DEVICE_CLASS						(0x000038)
#define MMI_BT_VIDEO_DISPLAY_AND_LOUDSPEAKER_AV_MINOR_DEVICE_CLASS		(0x00003C)
#define MMI_BT_VIDEO_CONFERENCING_AV_MINOR_DEVICE_CLASS				    (0x000040)
#define MMI_BT_GAME_TOY_AV_MINOR_DEVICE_CLASS							(0x000048)

/* Minor Device	Mask under LAN major class	*/
#define MMI_BT_FULLY_AVAILABLE_MINOR_DEVICE_MASK						(0x000000) 
#define MMI_BT_ONE_TO_SEVENTEEN_PERCENT_MINOR_DEVICE_MASK				(0x000020)
#define MMI_BT_SEVENTEEN_TO_THIRTYTHREE_PERCENT_MINOR_DEVICE_MASK		(0x000040)
#define MMI_BT_THIRTYTHREE_TO_FIFTY_PERCENT_MINOR_DEVICE_MASK			(0x000060)
#define MMI_BT_FIFTY_TO_SIXTYSEVEN_PERCENT_MINOR_DEVICE_MASK			(0x000080)
#define MMI_BT_SIXTYSEVEN_TO_EIGHTYTHREE_PERCENT_MINOR_DEVICE_MASK		(0x0000A0)
#define MMI_BT_EIGHTYTHREE_TO_NINETYNINE_PERCENT_MINOR_DEVICE_MASK		(0x0000C0)
#define MMI_BT_NO_SERVICE_AVAILABLE_MINOR_DEVICE_MASK					(0x0000E0)
#define	MMI_BT_UNCLASSIFIED_LAN_MINOR_DEVICE_MASK						(0x000000)

/* Minor Device Mask under Peripheral major Class (Keyboard/pointing device filed) */
#define MMI_BT_JOYSTICK_PERIPHERALS_MINOR_DEVICE_CLASS					(0x000004)
#define MMI_BT_GAMEPAD_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS			    (0x000008)
#define MMI_BT_REMOTE_CONTRO_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS		(0x00000C)
#define MMI_BT_SENSING_DEVICE_PERIPHERAL_MINOR_DEVICE_CLASS			    (0x000010)
#define MMI_BT_DIGITIZER_TABLET_PERIPHERAL_MINOR_DEVICE_CLASS			(0x000014)
#define MMI_BT_CARD_READER_PERIPHERAL_MINOR_DEVICE_CLASS				(0x000018)

/* Minor Device Mask under Imaging major Class (printing, scanner, caramera...) */
#define MMI_BT_DISPLAY_IMAGING_MINOR_DEVICE_CLASS						(0x000010)
#define MMI_BT_CAMERA_IMAGING_MINOR_DEVICE_CLASS					    (0x000020)
#define MMI_BT_SCANNER_IMAGING_MINOR_DEVICE_CLASS						(0x000040)
#define MMI_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS						(0x000080)

/* Bluetooth Profile Service UUID */
#define MMI_BT_SPP_PROFILE_UUID                 (0x1101 )
#define MMI_BT_LAP_PROFILE_UUID                 (0x1102 )
#define MMI_BT_DUN_PROFILE_UUID                 (0x1103 )
#define MMI_BT_OBEX_IR_MC_SYNC_SERVICE_UUID     (0x1104 )
#define MMI_BT_OBEX_OBJECT_PUSH_SERVICE_UUID    (0x1105 )
#define MMI_BT_OBEX_FILE_TRANSFER_UUID          (0x1106 )
#define MMI_BT_HS_PROFILE_UUID                  (0x1108 )
#define MMI_BT_CTP_PROFILE_UUID                 (0x1109 )
#define MMI_BT_AUDIO_SOURCE_UUID                (0x110A )
#define MMI_BT_AUDIO_SINK_UUID                  (0x110B )
#define MMI_BT_AV_REMOTE_CONTROL_TARGET_UUID    (0x110C )
#define MMI_BT_ADVANCED_AUDIO_PROFILE_UUID      (0x110D )
#define MMI_BT_AV_REMOTE_CONTROL_UUID           (0x110E )
#define MMI_BT_ICP_PROFILE_UUID                 (0x1110 )
#define MMI_BT_FAX_PROFILE_UUID                 (0x1111 )
#define MMI_BT_HEADSET_AG_SERVICE_UUID          (0x1112 )
#define MMI_BT_PAN_PANU_PROFILE_UUID            (0x1115 )
#define MMI_BT_PAN_NAP_PROFILE_UUID             (0x1116 )
#define MMI_BT_PAN_GN_PROFILE_UUID              (0x1117 )
#define MMI_BT_DIRECT_PRINTING                  (0x1118 )
#define MMI_BT_OBEX_IMAGING_UUID                (0x111A )
#define MMI_BT_OBEX_IMAGING_RESPONDER_UUID      (0x111B )
#define MMI_BT_HF_PROFILE_UUID                  (0x111E )
#define MMI_BT_HFG_PROFILE_UUID                 (0x111F )
#define MMI_BT_BASIC_PRINTING                   (0x1122 )
#define MMI_BT_HID_PROFILE_UUID                 (0x1124 )
#define MMI_BT_SIM_ACCESS_PROFILE_UUID          (0x112D )
#define MMI_BT_OBEX_PBA_PROFILE_UUID            (0x1401 )
#define MMI_BT_OBEX_BPPS_PROFILE_UUID           (0x1118 )
#define MMI_BT_MAX_PROFILE_UUID                 (0xffff )
/* if add new profile UUID, pls also update profile_str_id_map */

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void mmi_bt_init(void);
extern MMI_BOOL mmi_bt_ps_stack_and_hw_init(MMI_BOOL flight_mode, MMI_BOOL sim_inserted);
extern void mmi_bt_reset_hw_on(void);
extern void mmi_bt_reset_hw_off(void);
extern void mmi_bt_host_device_power_off_pre_process(void);

extern MMI_BOOL mmi_bt_is_incall_aud_swap2bt(void);
extern MMI_BOOL mmi_bt_is_aud2hf(void);
extern MMI_BOOL mmi_bt_is_hs_connected(void);
extern MMI_BOOL mmi_bt_is_hf_car_kit_connected(void);
extern MMI_BOOL mmi_bt_is_hfp_audio_link_connected(void);
extern MMI_BOOL mmi_bt_is_a2dp_connected(void);
extern MMI_BOOL mmi_bt_is_profile_connected(U32 conn_type);
extern MMI_BOOL mmi_bt_is_hw_ready(MMI_BOOL is_popup);
extern MMI_BOOL mmi_bt_is_doing_far_end_loopback_test(void);
extern MMI_BOOL mmi_bt_is_power_on(MMI_BOOL);
extern MMI_BOOL mmi_bt_is_simap_server_activate(void);
extern MMI_BOOL mmi_bt_is_device_paired(U32 lap, U8 uap, U16 nap);
/* Configure Default Headset */
extern MMI_BOOL mmi_bt_is_default_hs_existed(void);

/*********************************************
* bluetooth status icon control 
**********************************************/
extern void mmi_bt_status_icon_start_blinking(U32 profile_id, MMI_BT_PROFILE_ROLE profile_role);
extern void mmi_bt_status_icon_stop_blinking(U32 profile_id, MMI_BT_PROFILE_ROLE profile_role);
/*********************************************
* sco link related apis for hsp and hfp
**********************************************/
extern MMI_BOOL mmi_bt_turn_on_speech_req(MMI_BOOL speech_on);
extern U8 mmi_bt_switch_voice_path_incall(MMI_BOOL is_on);
extern void mmi_bt_set_headset_speaker_volume(S32 ui_volume_level);
extern void mmi_bt_hfp_sco_link_connect_req(void);
extern void mmi_bt_hfp_sco_link_disconnect_req(void);
/* Configure Default Headset */
extern void mmi_bt_connect_last_headset(void);
/*********************************************
* for specific device inquiry
**********************************************/
extern void mmi_bt_entry_a2dp_device_select_screen(void);
extern void mmi_bt_entry_obex_device_select_screen(void);
extern void mmi_bt_entry_remote_control_device_select_screen(void);
extern void mmi_bt_entry_printer_device_select_screen(void);
extern void mmi_bt_entry_cod_device_with_service_select_screen(
				U32 cod_bit_mask, 
				U32 service_id, 
				void *func_ptr);


/*********************************************
* get bluetooth related information 
**********************************************/
extern S32 mmi_bt_get_active_signal_connection_id(U32 profile_uuid);
extern void mmi_bt_get_device_name(U32 lap, U8 uap, U16 nap, U8 max_name_len, U8 *name_p);
extern void mmi_bt_get_selected_specfic_device_info(void *dev_p);
/* Configure Default Headset */
extern U8* mmi_bt_get_default_headset_device_name(void);
/*********************************************
* panic callback 
**********************************************/
extern void mmi_bt_panic_ind_pre_process(void);
extern void mmi_bt_panic_ind_post_process(void);
/*********************************************
* for PCM far end loopback test 
**********************************************/
extern void mmi_bt_sco_far_end_loopback_test(
                U32 lap,
                U8 uap,
                U16 nap,
                U8 *pin_code /* ascii encoding */ ,
                U8 size_of_pin);
extern void mmi_bt_sco_far_end_loopback_cancel_test(void);
/*********************************************
* misc 
*********************************************/
extern MMI_BOOL mmi_bt_reject_passkey_ind(void);
extern void mmi_bt_profile_callback_before_release_connection(
                U32 lap,
                U8 uap,
                U16 nap,
                U32 profile_id,
                U32 connection_id);
extern void mmi_bt_pwroff(void);                    /* dummy function for handphone solution */
extern MMI_BOOL mmi_bt_start_hf_ring_req(void);     /* dummy function for handphone solution */
extern MMI_BOOL mmi_bt_stop_hf_ring_req(void);      /* dummy function for handphone solution */
extern void mmi_bt_popup_operation_not_allowed(void);
extern void mmi_bt_popup_prohibited_by_simap(void);
extern void mmi_bt_enable_pts_test(void);
extern void mmi_bt_disable_pts_test(void);
extern void mmi_bt_mask_scr_extended_flag(U32 flag);
extern void mmi_bt_unmask_scr_extended_flag(U32 flag);
extern void mmi_bt_register_power_on_callback(void (*power_on_cb_func_ptr) (void));

#endif /* __BT_MMI_SCR_GPROTS_H__ */ 

