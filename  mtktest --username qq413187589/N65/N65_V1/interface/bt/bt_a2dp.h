#ifndef _BT_A2DP_H_
#define _BT_A2DP_H_

// activate
void bt_a2dp_send_activate_req( module_type src_mod_id, kal_uint8 local_role );
void bt_a2dp_send_activate_cnf( module_type dst_mod_id, kal_uint16 result );

// deactivate
void bt_a2dp_send_deactivate_req( module_type src_mod_id );
void bt_a2dp_send_deactivate_cnf( module_type dst_mod_id, kal_uint16 result );

// connect
void bt_a2dp_send_signal_connect_req( module_type src_mod_id, bt_device_addr_struct* device_addr, kal_uint8 local_role );
void bt_a2dp_send_signal_connect_cnf( module_type dst_mod_id, kal_uint16 connect_id, kal_uint16 result, bt_device_addr_struct* device_addr );
void bt_a2dp_send_signal_connect_ind( module_type dst_mod_id, kal_uint16 connect_id, bt_device_addr_struct* device_addr );

// disconnect
void bt_a2dp_send_signal_disconnect_req( module_type src_mod_id, kal_uint16 connect_id );
void bt_a2dp_send_signal_disconnect_cnf( module_type dst_mod_id, kal_uint16 connect_id, kal_uint16 result );
void bt_a2dp_send_signal_disconnect_ind( module_type dst_mod_id, kal_uint16 connect_id );

// discover
void bt_a2dp_send_sep_discover_req( module_type src_mod_id, kal_uint16 connect_id );
void bt_a2dp_send_sep_discover_cnf( module_type dst_mod_id, kal_uint16 connect_id, kal_uint16 result, kal_uint8 sep_num, bt_sep_info_struct* sep_list );
void bt_a2dp_send_sep_discover_ind( module_type dst_mod_id, kal_uint16 connect_id );
void bt_a2dp_send_sep_discover_res( module_type src_mod_id, kal_uint16 connect_id, kal_uint16 result, kal_uint8 sep_num, bt_sep_info_struct* sep_list );

// get capabilities
void bt_a2dp_send_capabilities_get_req( module_type src_mod_id, kal_uint16 connect_id, kal_uint8 acp_seid );
void bt_a2dp_send_capabilities_get_cnf( module_type dst_mod_id, kal_uint16 connect_id, kal_uint16 result, kal_uint8 audio_cap_num, bt_a2dp_audio_cap_struct* audio_cap_list );
void bt_a2dp_send_capabilities_get_ind( module_type dst_mod_id, kal_uint16 connect_id, kal_uint8 acp_seid );
void bt_a2dp_send_capabilities_get_res( module_type src_mod_id, kal_uint16 connect_id, kal_uint16 result, kal_uint8 audio_cap_num, bt_a2dp_audio_cap_struct* audio_cap_list );

// set configuration
void bt_a2dp_send_stream_config_req( module_type src_mod_id, kal_uint16 connect_id, kal_uint8 acp_seid, kal_uint8 int_seid, bt_a2dp_audio_cap_struct* audio_cap );
void bt_a2dp_send_stream_config_cnf( module_type dst_mod_id, kal_uint16 connect_id, kal_uint16 result, kal_uint8 stream_handle );
void bt_a2dp_send_stream_config_ind( module_type dst_mod_id, kal_uint16 connect_id, kal_uint8 acp_seid, kal_uint8 int_seid, kal_uint8 stream_handle, bt_a2dp_audio_cap_struct* audio_cap );
void bt_a2dp_send_stream_config_res( module_type src_mod_id, kal_uint16 result, kal_uint8 stream_handle );

// reconfigure
void bt_a2dp_send_stream_reconfig_req( module_type src_mod_id, kal_uint8 stream_handle, bt_a2dp_audio_cap_struct* audio_cap );
void bt_a2dp_send_stream_reconfig_cnf( module_type dst_mod_id, kal_uint16 result, kal_uint8 stream_handle );
void bt_a2dp_send_stream_reconfig_ind( module_type dst_mod_id, kal_uint8 stream_handle, bt_a2dp_audio_cap_struct* audio_cap );
void bt_a2dp_send_stream_reconfig_res( module_type src_mod_id, kal_uint16 result, kal_uint8 stream_handle );

// open
void bt_a2dp_send_stream_open_req( module_type src_mod_id, kal_uint8 stream_handle );
void bt_a2dp_send_stream_open_cnf( module_type dst_mod_id, kal_uint16 result, kal_uint8 stream_handle );
void bt_a2dp_send_stream_open_ind( module_type dst_mod_id, kal_uint8 stream_handle );
void bt_a2dp_send_stream_open_res( module_type src_mod_id, kal_uint16 result, kal_uint8 stream_handle );

// start
void bt_a2dp_send_stream_start_req( module_type src_mod_id, kal_uint8 stream_handle );
void bt_a2dp_send_stream_start_cnf( module_type dst_mod_id, kal_uint16 result, kal_uint8 stream_handle );
void bt_a2dp_send_stream_start_ind( module_type dst_mod_id, kal_uint8 stream_handle );
void bt_a2dp_send_stream_start_res( module_type src_mod_id, kal_uint16 result, kal_uint8 stream_handle );

// pause
void bt_a2dp_send_stream_pause_req( module_type src_mod_id, kal_uint8 stream_handle );
void bt_a2dp_send_stream_pause_cnf( module_type dst_mod_id, kal_uint16 result, kal_uint8 stream_handle );
void bt_a2dp_send_stream_pause_ind( module_type dst_mod_id, kal_uint8 stream_handle );
void bt_a2dp_send_stream_pause_res( module_type src_mod_id, kal_uint16 result, kal_uint8 stream_handle );

// qos
void bt_a2dp_send_stream_qos_ind( module_type dst_mod_id, kal_uint8 stream_handle, kal_uint8 qos );

// send data
void bt_a2dp_send_stream_data_send_req( module_type src_mod_id, kal_uint8 stream_handle, A2DP_codec_struct* codec );

// close
void bt_a2dp_send_stream_close_req( module_type src_mod_id, kal_uint8 stream_handle );
void bt_a2dp_send_stream_close_cnf( module_type src_mod_id, kal_uint16 result, kal_uint8 stream_handle );
void bt_a2dp_send_stream_close_ind( module_type dst_mod_id, kal_uint8 stream_handle );
void bt_a2dp_send_stream_close_res( module_type src_mod_id, kal_uint16 result, kal_uint8 stream_handle );

// abort
void bt_a2dp_send_stream_abort_req( module_type src_mod_id, kal_uint8 stream_handle );
void bt_a2dp_send_stream_abort_cnf( module_type dst_mod_id, kal_uint8 stream_handle );
void bt_a2dp_send_stream_abort_ind( module_type dst_mod_id, kal_uint8 stream_handle );
void bt_a2dp_send_stream_abort_res( module_type src_mod_id, kal_uint8 stream_handle );

/* utilities */
kal_bool bt_a2dp_validate_audio_cap(bt_a2dp_audio_cap_struct *audio_cap);
kal_bool bt_a2dp_match_audio_capabilities( bt_a2dp_audio_cap_struct *audio_cap, bt_a2dp_audio_cap_struct *audio_cfg, kal_uint16 *result );

#endif
