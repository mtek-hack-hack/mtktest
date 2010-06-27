
#ifndef __BT_A2DP_STRUCT_H_
#define __BT_A2DP_STRUCT_H_

#include "kal_release.h"      			/* Basic data type */
#include "l1audio.h"

#define MAX_NUM_REMOTE_SEIDS 4
#define MAX_NUM_REMOTE_CAPABILITIES 4

#define MAX_NUM_LOCAL_SEIDS 1
#define MAX_NUM_LOCAL_CAPABILITIES 2

/* media_type */
#define BT_A2DP_MEDIA_AUDIO 		0
#define BT_A2DP_MEDIA_VIDEO 		1
#define BT_A2DP_MEDIA_MULTIMEDIA 	2
#define BT_A2DP_MEDIA_UNKNOWN 	0xff

/* sep_type */
#define BT_A2DP_SOURCE 	0
#define BT_A2DP_SINK 		1

/* codec_type */
#define BT_A2DP_SBC 		1
#define BT_A2DP_MP3 		2
#define BT_A2DP_AAC 		3
#define BT_A2DP_ATRAC 		4
#define BT_A2DP_NON_A2DP        5

typedef struct
{
	kal_uint32 lap; 
	kal_uint8  uap; 
	kal_uint16 nap; // non-significant 32..47
} bt_device_addr_struct;

typedef struct
{
	kal_bool in_use;
	kal_uint8 seid;
	kal_uint8 media_type;
	kal_uint8 sep_type;
} bt_sep_info_struct;

/* ===================================================== */

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 local_role;
} bt_a2dp_activate_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
} bt_a2dp_activate_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
} bt_a2dp_deactivate_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
} bt_a2dp_deactivate_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	bt_device_addr_struct device_addr;
	kal_uint8 local_role;
} bt_a2dp_signal_connect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	kal_uint16 result;
	bt_device_addr_struct device_addr;
} bt_a2dp_signal_connect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	bt_device_addr_struct device_addr;
} bt_a2dp_signal_connect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
} bt_a2dp_signal_disconnect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	kal_uint16 result;
} bt_a2dp_signal_disconnect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
} bt_a2dp_signal_disconnect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
} bt_a2dp_sep_discover_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	kal_uint16 result;
	kal_uint8 sep_num;
	bt_sep_info_struct sep_list[MAX_NUM_REMOTE_SEIDS];
} bt_a2dp_sep_discover_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
} bt_a2dp_sep_discover_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	kal_uint16 result;
	kal_uint8 sep_num;
	bt_sep_info_struct sep_list[MAX_NUM_LOCAL_SEIDS];
} bt_a2dp_sep_discover_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	kal_uint8 acp_seid;
} bt_a2dp_capabilities_get_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	kal_uint16 result;
	kal_uint8 audio_cap_num;
	bt_a2dp_audio_cap_struct audio_cap_list[MAX_NUM_REMOTE_CAPABILITIES];
} bt_a2dp_capabilities_get_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	kal_uint8 acp_seid;
} bt_a2dp_capabilities_get_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	kal_uint16 result;
	kal_uint8 audio_cap_num;
	bt_a2dp_audio_cap_struct audio_cap_list[MAX_NUM_LOCAL_CAPABILITIES];
} bt_a2dp_capabilities_get_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	kal_uint8 acp_seid;
	kal_uint8 int_seid;
	bt_a2dp_audio_cap_struct audio_cap;
} bt_a2dp_stream_config_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_config_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 connect_id;
	kal_uint8 acp_seid;
	kal_uint8 int_seid;
	kal_uint8 stream_handle;
	bt_a2dp_audio_cap_struct audio_cap;
} bt_a2dp_stream_config_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_config_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
	bt_a2dp_audio_cap_struct audio_cap;
} bt_a2dp_stream_reconfig_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_reconfig_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
	bt_a2dp_audio_cap_struct audio_cap;
} bt_a2dp_stream_reconfig_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_reconfig_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_open_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_open_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_open_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_open_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_start_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_start_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_start_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_start_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_pause_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_pause_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_pause_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_pause_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
	kal_uint8 qos;
} bt_a2dp_stream_qos_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
	A2DP_codec_struct* codec;
} bt_a2dp_stream_data_send_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_close_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_close_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_close_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 result;
	kal_uint8 stream_handle;
} bt_a2dp_stream_close_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_abort_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_abort_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_abort_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 stream_handle;
} bt_a2dp_stream_abort_res_struct;

typedef enum
{	
 	BT_A2DP_BAD_HEADER_FORMAT=0x1,

	BT_A2DP_BAD_LENGTH=0x11,
	BT_A2DP_BAD_ACP_SEID,
	BT_A2DP_SEP_IN_USE,	
	BT_A2DP_SEP_NOT_IN_USE,
	BT_A2DP_BAD_SERV_CATEGORY=0x17,
	BT_A2DP_BAD_PAYLOAD_FORMAT,
	BT_A2DP_NOT_SUPPORTED_COMMAND,
	BT_A2DP_INVALID_CAPABILITIES,

	BT_A2DP_BAD_RECOVERY_TYPE=0x22,
	BT_A2DP_BAD_MEDIA_TRANSPORT_FORMAT,
	BT_A2DP_BAD_RECOVERY_FORMAT=0x25,
	BT_A2DP_BAD_ROHC_FORMAT,
	BT_A2DP_BAD_CP_FORMAT,
	BT_A2DP_BAD_MULTIPLEXING_FORMAT,
	BT_A2DP_UNSUPPORTED_CONFIGURATION,
	
	BT_A2DP_BAD_STATE=0x31,
	
	/* improper settings of Codec Specific Information Elements, 
	   used in SetConfiguration and Reconfigure */
	BT_A2DP_INVALID_CODEC_TYPE=0xC1,
	BT_A2DP_NOT_SUPPORTED_CODEC_TYPE,
	BT_A2DP_INVALID_SAMPLING_FREQUENCY,
	BT_A2DP_NOT_SUPPORTED_SAMPLING_FREQUENCY,
	BT_A2DP_INVALID_CHANNEL_MODE,
	BT_A2DP_NOT_SUPPORTED_CHANNEL_MODE,
	BT_A2DP_INVALID_SUBBANDS,
	BT_A2DP_NOT_SUPPORTED_SUBBANDS,
	BT_A2DP_INVALID_ALLOCATION_METHOD,
	BT_A2DP_NOT_SUPPORTED_ALLOCATION_METHOD,
	BT_A2DP_INVALID_MINIMUM_BITPOOL_VALUE,
	BT_A2DP_NOT_SUPPORTED_MINIMUM_BITPOOL_VALUE,
	BT_A2DP_INVALID_MAXIMUM_BITPOOL_VALUE,
	BT_A2DP_NOT_SUPPORTED_MAXIMUM_BITPOOL_VALUE,
	BT_A2DP_INVALID_LAYER,
	BT_A2DP_NOT_SUPPORTED_LAYER,
	BT_A2DP_NOT_SUPPORTED_CRC,
	BT_A2DP_NOT_SUPPORTED_MPF,
	BT_A2DP_NOT_SUPPORTED_VBR,
	BT_A2DP_INVALID_BIT_RATE,
	BT_A2DP_NOT_SUPPORTED_BIT_RATE,
	BT_A2DP_INVALID_OBJECT_TYPE,
	BT_A2DP_NOT_SUPPORTED_OBJECT_TYPE,
	BT_A2DP_INVALID_CHANNELS,
	BT_A2DP_NOT_SUPPORTED_CHANNELS,
	BT_A2DP_INVALID_VERSION,
	BT_A2DP_NOT_SUPPORTED_VERSION,
	BT_A2DP_NOT_SUPPORTED_MAXIMUM_SUL,
	BT_A2DP_INVALID_BLOCK_LENGTH,
	
	BT_A2DP_INVALID_CP_TYPE=0xE0,
	BT_A2DP_INVALID_CP_FORMAT,
	/* internal result */
	BT_A2DP_RESULT_OK=0x0100,
	BT_A2DP_RESULT_TIMEOUT,
	BT_A2DP_RESULT_BAD_STATE,
	BT_A2DP_RESULT_FATAL_ERROR,
	BT_A2DP_RESULT_NO_CONNECTION,
	BT_A2DP_RESULT_SEP_IND_USE,
	BT_A2DP_RESULT_BAD_ACP_SEID,
	BT_A2DP_RESULT_PANIC
} BT_A2DP_RESULT_ENUM;

typedef enum
{
	BT_AUDIO_STREAM_RECONFIG_FAIL,
	BT_AUDIO_STREAM_START_FAIL,
	BT_AUDIO_STREAM_PAUSE_FAIL
} MED_BT_AUDIO_ERROR_CAUSE_ENUM;



#endif

