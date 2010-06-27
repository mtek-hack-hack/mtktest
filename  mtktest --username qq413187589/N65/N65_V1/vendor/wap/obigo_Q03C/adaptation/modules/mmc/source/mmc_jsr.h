#define MMC_MAX_JSR_APP_ID_NUM 5
#define MMC_MAX_JSR_APP_ID_LENGTH 100
/* This value must be smaller than WAP_CUSTOM_CFG_MAX_NBR_MMS_MSG in custom_wap_config.h */
#define MMC_MAX_JSR_MSGS_NUM 10

#define MMC_JSR_MSG "jsr.s"
/* A file keeps mms folder status */
#define MMC_INFO_FILE   MMS_FOLDER MMC_INFO
#define MMC_JSR_MSG_FILE   MMS_FOLDER MMC_JSR_MSG
#define MMC_JSR_MEDIA_OBJECT "mmc_jsr.mo"
#define MMC_JSR_MEDIA_OBJECT_FILE MMS_FOLDER MMC_JSR_MEDIA_OBJECT
#define MMC_JSR_INDEX "mmc_jsr.cn"
#define MMC_JSR_INDEX_TMP "mmc_jsr.tp"
#define MMC_JSR_INDEX_FILE MMS_SYS_FOLDER MMC_JSR_INDEX
#define MMC_JSR_INDEX_FILE_TMP MMS_SYS_FOLDER MMC_JSR_INDEX_TMP

typedef struct mmc_jsr_msg_info_st
{
    MSF_UINT32 msgId;
    MSF_BOOL isChecked; /* When Java checkes this msg, the flag becomes TRUE. 0:FALSE, 1:TRUE */
    struct mmc_jsr_msg_info_st *next;
    struct mmc_jsr_msg_info_st *prev;
} mmc_jsr_msg_info;

typedef struct mmc_jsr_appid_object_list_st
{
    MSF_INT8 *appid;
    mmc_jsr_msg_info *msgs;
    struct mmc_jsr_appid_object_list_st *prev;
    struct mmc_jsr_appid_object_list_st *next;
} mmc_jsr_appid_object_list_struct;

typedef struct
{
    MSF_UINT32 checksum;
    mmc_jsr_appid_object_list_struct *jsr_mms_info;
} mmc_jsr_index_struct;

typedef struct
{
    char *appId;
    module_type ind_module;
    sap_type ind_sap_id;
} mmc_jsr_appid_info_struct;

extern MSF_UINT32 mmcGenRecvJSRMsgRsp(
                    MSF_INT8 *appId,
                    wap_mmc_recv_appmms_rsp_struct *response,
                    MmcResult *result,
                    MSF_UINT8 **buffer,
                    MSF_UINT16 *buffer_size);
extern MSF_BOOL mmcRemoveMsgIdFromJSRIndex(MSF_UINT32 msgId);
extern MSF_BOOL mmcGenRecvJSRMsgBodyPartRsp(
                    MSF_UINT32 msgId,
                    MSF_UINT32 bdy_no,
                    wap_mmc_read_appmms_msg_part_rsp_struct *response);
extern MmcResult mmcCfgAppId(
                    MSF_UINT8 *app_id_str,
                    MSF_UINT8 app_id_strlen,
                    MSF_BOOL isRemove,
                    module_type ind_module,
                    sap_type sap_id);
extern MmcResult mmcWriteMessageBodyPart(char *filename, const MmsBodyParams *bdyParams, kal_wchar *content_filepath);
extern MSF_BOOL mmcAddrListToMms(MSF_UINT8 addrType, MSF_INT8 *address, MmsAddressList **mmsAddr);
extern void mmcFreeMmsAddressList(MmsAddressList *addrList);
extern MmcResult mmcWriteMessageHeader(
                    char *filename,
                    const MmsSetHeader *header,
                    MmsVersion version,
                    MSF_UINT32 no_body);
extern MSF_BOOL mmcCheckAppIdMsgs(MSF_INT8 *app_id_str, MSF_BOOL isOnlyNew);
extern MSF_BOOL mmcGetMmsMsgHeader(MSF_UINT32 msgId, MmsGetHeader *header);
extern MSF_BOOL mmcWriteJSRIndex(void);
extern MSF_BOOL mmcIsJSRMsg(MSF_UINT32 msgId);
extern MSF_UINT32 mmcGenCheckSum(MSF_UINT8 *data, MSF_UINT32 datalen);
extern void mmcRestoreJSRIndex(void);

extern MmsSetHeader *mmcCreateMessageHeader(
                        MSF_BOOL isSmil,
                        MSF_UINT8 priority,
                        MmsAddressList *to_list,
                        MmsAddressList *cc_list,
                        MmsAddressList *bcc_list,
                        MSF_UINT32 delivery_time,
                        MSF_INT8 *subject,
                        MmsCharset subject_charset,
                        MSF_INT8 *start_cnt_id,
                        MSF_INT8 *appId,
                        MSF_INT8 *reply_appId);

extern MmsBodyParams *mmcCreateBodyParams(
                        MmsCharset charset,
                        const unsigned char *content_type,
                        const unsigned char *content_id,
                        const unsigned char *content_location);

