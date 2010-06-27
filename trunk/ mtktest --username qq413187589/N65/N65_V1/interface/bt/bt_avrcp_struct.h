
#ifndef __BT_AVRCP_STRUCT_H_
#define __BT_AVRCP_STRUCT_H_

#include "kal_release.h"      			/* Basic data type */

/* AVRCP device roles */
#define BT_AVRCP_TG		0
#define BT_AVRCP_CT		1
#define BT_AVRCP_MAX_CHANNEL   2 /* One Target and one Controller */
#define BT_AVRCP_ROLE_UNDEF		255

/* command/response types */
#define BT_AVRCP_CR_CONTROL				(0x00)
#define BT_AVRCP_CR_STATUS					(0x01)
#define BT_AVRCP_CR_SPECIFIC_INUIRY		(0x02)
#define BT_AVRCP_CR_NOTIFY					(0x03)
#define BT_AVRCP_CR_GENERAL_INQUIRY		(0x04)
#define BT_AVRCP_CR_ACCEPT					(0x09)
#define BT_AVRCP_CR_REJECT					(0x0A)
#define BT_AVRCP_CR_NOT_IMPLEMENT		(0x08)
#define BT_AVRCP_CR_STABLE					(0x0c)

/* sub_unit types */
#define BT_AVRCP_SUBUNIT_TYPE_UNIT_INFO		(0x1f)
#define BT_AVRCP_SUBUNIT_TYPE_SUBUNIT_INFO	(0x1f)
#define BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH	(0x09) /* Panel subunit */

/* sub_unit ID */
#define BT_AVRCP_SUBUNIT_ID_UNIT_INFO		(0x07)
#define BT_AVRCP_SUBUNIT_ID_SUBUNIT_INFO		(0x07)
#define BT_AVRCP_SUBUNIT_ID_PASS_THROUGH	(0x00)

/* opcodes */
#define BT_AVRCP_OP_UNIT_INFO			(0x30)
#define BT_AVRCP_OP_SUBUNIT_INFO			(0x31)
#define BT_AVRCP_OP_VENDOR				(0x00)
#define BT_AVRCP_OP_PASS_THROUGH			(0x7c)


#define BT_AVRCP_MAX_CMD_FRAME_SIZE     20
#define BT_AVRCP_MAX_IND_CMD_NUM        10      /* Maximum indication send to MMI if confirm not send back yet */

typedef struct
{
	kal_uint32 lap; 
	kal_uint8  uap; 
	kal_uint16 nap; // non-significant 32..47
} bt_avrcp_dev_addr_struct;


/* ===================================================== */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 chnl_num;
    kal_uint8 local_role;
} bt_avrcp_activate_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 chnl_num;	
    kal_uint16 result;
} bt_avrcp_activate_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 chnl_num;
} bt_avrcp_deactivate_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 chnl_num;
    kal_uint16 result;
} bt_avrcp_deactivate_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 chnl_num;
    kal_uint8 local_role;    
    bt_avrcp_dev_addr_struct device_addr;
} bt_avrcp_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 chnl_num;
    kal_uint8 connect_id;
    kal_uint16 result;
    bt_avrcp_dev_addr_struct device_addr;
} bt_avrcp_connect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 chnl_num;
    kal_uint8 connect_id;
    bt_avrcp_dev_addr_struct device_addr;
} bt_avrcp_connect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 chnl_num;    
    kal_bool accept_conn;
} bt_avrcp_connect_ind_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 chnl_num;
} bt_avrcp_disconnect_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 chnl_num;
    kal_uint8 connect_id;    
    kal_uint16 result;
} bt_avrcp_disconnect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 chnl_num;
    kal_uint8 connect_id;    
} bt_avrcp_disconnect_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   chnl_num;
    kal_uint8   seq_id;
    kal_uint8   c_type;
    kal_uint8   subunit_type;
    kal_uint8   subunit_id;
    kal_uint16  data_len;
    kal_uint8   frame_data[BT_AVRCP_MAX_CMD_FRAME_SIZE];
} bt_avrcp_cmd_frame_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint8   chnl_num;	
    kal_uint8   seq_id;
    kal_uint8   c_type;
    kal_uint8   subunit_type;
    kal_uint8   subunit_id;
    kal_uint16  data_len;
    kal_uint8   frame_data[BT_AVRCP_MAX_CMD_FRAME_SIZE];
} bt_avrcp_cmd_frame_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   chnl_num;	
    kal_uint8   seq_id;
    kal_uint8   c_type;
    kal_uint8   subunit_type;
    kal_uint8   subunit_id;
    kal_uint16  data_len;
    kal_uint16  profile_id;
    kal_uint8   frame_data[BT_AVRCP_MAX_CMD_FRAME_SIZE];
} bt_avrcp_cmd_frame_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint8   chnl_num;	
    kal_uint8   seq_id;
    kal_uint8   c_type;
    kal_uint8   subunit_type;
    kal_uint8   subunit_id;
    kal_uint16  data_len;
    kal_uint16  profile_id;	
    kal_uint8   frame_data[BT_AVRCP_MAX_CMD_FRAME_SIZE];
} bt_avrcp_cmd_frame_ind_res_struct;


/* AVRCP Error code*/
#define BT_AVRCP_RESULT_SUCCESS       0x1000
#define BT_AVRCP_RESULT_ERROR           0x1001
#define BT_AVRCP_RESULT_INVALID_ROLE   0x1002

#define BT_AVRCP_RESULT_TIMEOUT         0x1003
#define BT_AVRCP_RESULT_BAD_STATE     0x1004
#define BT_AVRCP_RESULT_BUSY               0x1005


#endif /* #ifndef __BT_AVRCP_STRUCT_H_ */

