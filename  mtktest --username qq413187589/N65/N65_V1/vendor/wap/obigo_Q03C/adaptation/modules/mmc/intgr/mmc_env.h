

#define IDLE 0
#define BUSY 1
#define MMC_INFO "info.db"

#define MMC_FLAG_WAIT_CREATE_MSG_REPLY 0x01
#define MMC_FLAG_WAIT_CREATE_MSG_DONE_REPLY  0x02
#define MMC_FLAG_WAIT_GET_FOLDER_CONTENT_REPLY  0x04
#define MMC_FLAG_WAIT_SEND_MSG_REPLY   0x08
#define MMC_FLAG_WAIT_CANCEL_SEND_MSG_REPLY  0x10
#define MMC_FLAG_ABORT  0x20

#define MMC_CNTX mmsContext_p

/* The state of MMC module: MMC_IDEL, MMC_READ_FOLDER, MMC_UPLOAD_MSG, MMC_DELETE_MSG */
typedef enum
{
    MMC_IDLE,
    MMC_READ_FOLDER,
    MMC_CREATE_MSG,
    MMC_UPLOAD_MSG,
    MMC_DELETE_MSG,
    MMC_PROCESS_JSR_SND_MSG_HDR,
    MMC_PROCESS_JSR_SND_MSG_BDY,
    MMC_RECV_JSR_MSG_HDR,
    MMC_RECV_JSR_MSG_BDY
} MmcState;

typedef enum
{
    MMC_OP_IDLE,
    MMC_OP_SEND_MSG,
    MMC_OP_RECV_MSG,
    MMC_OP_ABORT_SENDING_MSG,
    MMC_OP_ABORT_RECVONG_MSG,
    MMC_OP_UPLOAD_MSG,
    MMC_OP_DELETE_MSG,
    MMC_OP_CHECK_MSG,
    MMC_OP_READ_FOLDER,
    MMC_OP_CFG_APP_ID
} MmcOperations;

/* ! \enum MmsResult Result values sent from the MMC to l4c. */
typedef enum
{
    MMC_RESULT_OK,
    MMC_RESULT_BUSY,
    MMC_RESULT_INSUFFICIENT_MEMORY,
    MMC_RESULT_INSUFFICIENT_PERSISTENT_STORAGE,
    MMC_RESULT_INVALID_MESSAGE,
    MMC_RESULT_INVALID_MESSAGE_BODY,
    MMC_RESULT_MESSAGE_ID_NOT_FOUND,
    MMC_RESULT_FILE_OPERATION_ERROR,
    MMC_RESULT_INVALID_FOLDER,
    MMC_RESULT_ACCESS_DENY,
    MMC_RESULT_INVALID_PARAMETER,
    MMC_RESULT_EXCEED_MAX_MSGS,
    MMC_RESULT_ERROR,
    MMC_RESULT_MMS_NO_READY,
    MMC_RESULT_NO_MSG_FOR_JAVA,
    MMC_RESULT_ERROR_APPID_EXIST,
    MMC_RESULT_ERROR_APPID_NOT_FOUND,
    MMC_RESULT_ERROR_APPID_TOO_LARGE,
    MMC_RESULT_ERROR_APPID_FULL,
    MMC_RESULT_ERROR_FAIL_TO_GEN_MMS_HDR,
    MMC_RESULT_ERROR_FAIL_TO_WR_MMS_HDR,
    MMC_RESULT_ERROR_MSG_CORRUPTED,
    MMC_RESULT_ERROR_SEND_CANCEL_BY_SYSTEM,
    MMC_RESULT_ERROR_MESSAGE_TOO_LARGE
} MmcResult;

typedef enum
{
    MMC_BASIC = 1,
    MMC_FULL
} MmcRetrievalMode;

typedef enum
{
    MMC_NO_FOLDER = 0x00,                   /* !< Folder not assiged, only for internal usage. */
    MMC_INBOX = 0x01,                       /* !< Incoming messages */
    MMC_OUTBOX = 0x02,                      /* !< Outgoing messages */
    MMC_SENT = 0x04,                        /* !< Successfully sent messages */
    MMC_DRAFTS = 0x08,                      /* !< Messages during work */
    MMC_NOTIFY = 0x10,                      /* !< Notifications */
    MMC_HIDDEN = 0x20,                      /* !< Hidden notifications (immediate) */
    MMC_TEMPLATES = 0x40,                   /* !< Template folder */
    MMC_USER_DEFINED_FOLDER_OFFSET = 0x80,  /* !< The offset for user defined folders  */
    MMC_JSR = 0x100,                        /* !< The offset for user defined folders  */
    MMC_ALL_FOLDERS = 0xFFFF                /* !< Use this value to make a request to all folders */
} MmcFolderType;

typedef enum
{
    MMC_SUFFIX_TEMPLATE = 't',
    MMC_SUFFIX_SEND_REQ = 's',
    MMC_SUFFIX_MSG = 'm',
    MMC_SUFFIX_NOTIFICATION = 'n',
    MMC_SUFFIX_READREPORT = 'r',
    MMC_SUFFIX_DELIVERYREPORT = 'd'
} MmcFileType;

typedef struct
{
    MSF_UINT32 numOfMsg;
    MSF_UINT32 numOUnreadMsg;
    MSF_UINT8 mmsHomeDirectory[100];    /* Encoded by ASCII */
    MSF_UINT8 infoFilePath[100];        /* Encoded by ASCII */
} MmcFolderInfo;

typedef struct
{
    MSF_UINT32 msgId;
    MSF_UINT32 offset;      /* the starting byte of mms message data */
    MSF_UINT32 size;
    MSF_UINT32 date;
    MSF_UINT8 filename[40]; /* Encoded by ASCII and ended by NULL terminator */
    MSF_UINT8 address[40];
    MSF_UINT8 subject[40];
} MmcMessageInfo;

typedef struct
{
    module_type mod_id;
    sap_type sap_id;
    MSF_UINT8 op;
    MSF_UINT8 state;
    MSF_UINT32 msgId;
    MSF_UINT8 curr_bdy_no;
    MSF_UINT8 bdy_no;
    MSF_UINT8 retrievalMode;
    MSF_UINT32 flag;
    char msg_filepath[100];
} MmcContext;

extern void MMCc_start(void);
extern int MMCc_wantsToRun(void);
extern void MMCc_run(void);
extern void *mmcMemAlloc(MSF_UINT32 size);

/* !
 * \brief This function is called by the system in emergency situations.
 *
 *****************************************************************************/
extern void MMCc_kill(void);

/* !
 * \brief Used to emergency stop the SMIL Service in case of no available memory
 *
 * ONLY FOR SLS SERVICE INTERNAL USAGE.
 *****************************************************************************/
extern void mmc_exception_handler(void);

extern void wap_mmc_read_folder_status_req_ind_hldr(
                module_type mod_id,
                sap_type sap_id,
                wap_mmc_read_folder_status_req_ind_struct *Message);
extern void wap_mmc_upload_msg_req_ind_hldr(
                module_type mod_id,
                sap_type sap_id,
                wap_mmc_upload_msg_req_ind_struct *Message);
extern void wap_mmc_delete_msg_req_ind_hldr(
                module_type mod_id,
                sap_type sap_id,
                wap_mmc_delete_msg_req_ind_struct *Message);
extern void setMeaUsedMsgId(unsigned long msgId);
extern MSF_BOOL isMmsReplyForMMC(MSF_UINT16 signal, MSF_UINT32 param);

#define MMC_MEM_FREE(p) MSF_MEM_FREE(MSF_MODID_MMC,p)
#define MMC_MEM_ALLOC(x) mmcMemAlloc(x)

#define MMC_CHECK_FLAG(x) (MMC_CNTX->flag & x)
#define MMC_SET_FLAG(x) MMC_CNTX->flag |=x
#define MMC_UNSET_FLAG(x) MMC_CNTX->flag &=~x

extern void wap_mmc_handle_send_appmms_req(
                module_type mod_id,
                sap_type sap_id,
                wap_mmc_send_appmms_req_struct *message,
                MSF_UINT8 *buffer,
                MSF_UINT16 buffer_size);
extern void wap_mmc_reply_send_appmms_rsp(module_type mod_id, sap_type sap_id, MmcResult result);
extern void wap_mmc_handle_recv_appmms_req(module_type mod_id, sap_type sap_id, MSF_INT8 *appId);
extern void wap_mmc_handle_post_appmms_msg_part_res(
                module_type mod_id,
                sap_type sap_id,
                wap_mmc_post_appmms_msg_part_res_struct *message);
extern void wap_mmc_reply_recv_appmms_rsp(
                module_type mod_id,
                sap_type sap_id,
                const wap_mmc_recv_appmms_rsp_struct *response,
                MSF_UINT8 *buffer,
                MSF_UINT16 buffer_size);
extern void wap_mmc_handle_read_appmms_msg_part_req(module_type mod_id, sap_type sap_id);
extern void wap_mmc_reply_read_appmms_msg_part_rsp(
                module_type mod_id,
                sap_type sap_id,
                wap_mmc_read_appmms_msg_part_rsp_struct *response);
extern void wap_mmc_handle_check_appmms_coming_req(
                module_type mod_id,
                sap_type sap_id,
                wap_mmc_check_appmms_coming_req_struct *message);
extern void wap_mmc_reply_check_appmms_coming_rsp(module_type mod_id, sap_type sap_id, MSF_BOOL result);
extern void wap_mmc_handle_abort_appmms_req(module_type mod_id, sap_type sap_id);
extern void wap_mmc_reply_abort_appmms_rsp(module_type mod_id, sap_type sap_id, kal_uint8 result);
extern void wap_mmc_handle_cfg_appmms_appid_req(
                module_type mod_id,
                sap_type sap_id,
                wap_mmc_cfg_appmms_appid_req_struct *message);
extern void wap_mmc_handle_get_mms_prof_req(module_type mod_id, sap_type sap_id, kal_uint32 prof_id);
extern void wap_mmc_reply_cfg_appmms_appid_rsp(module_type mod_id, sap_type sap_id, MmcResult result);

