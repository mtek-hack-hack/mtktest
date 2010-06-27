
/* MTK MMS Application Complie Option */
#define MMS_SEND_REQ_CACHE_SUPPORT       0
#define MMS_CHECK_DUPLICATE_NOTIFICATION 1
#define MMS_COMPOSER_SUPPORT             0 
#define MMS_TEMPLATES_DEMO_SUPPORT       1 

#define MMS_GET_STR_ID(strId)       MSF_WIDGET_STRING_GET_PREDEFINED(strId)
#define MMS_SYS_FOLDER "/mms_sys/"


void	setMmscVersion(const char *curPLMN);
void	MsgIdToHexStr(char *out, unsigned int MsgID);
void	mmsHandleErrors(int result);
void	setMmscVersion(const char *curPLMN);
void	writeRoamingStatusForMMS(MSF_INT32 simId, MSF_INT32 isRoaming);
void	mmsHandleErrors(int result);
void	handleNewMessage(MmsMsgId msgId);
void	handleDownloadMessage(MmsMsgId msgId, MSF_UINT32 size); //Jo, add size
void	MsgIdToHexStr(char *out, unsigned int MsgID);
void	setMMSCVersionByEngineerMode(int mode);
MSF_BOOL   IsReachMEAMaxNumofMsg(MSF_UINT32 MEA_MAX_NO_OF_MSG);
MSF_BOOL   loadMmsDataToBuffer(MSF_UINT8 modId, MmsMsgId msgId,char suffix,char **buffer, int *bufSize);//For loading delivery report,read report and notification file
MSF_INT32  getMMSVersion(MSF_UINT8 modId, MmsMsgId msgId); //Only for M-RETRIEVE.CONF 
void set10RrAllStringRes(void);
void mmsUpdateIndicator(void);

extern	void wap_task_sleep(int milliseconds);
extern  void freeMmsGetHeader( MSF_UINT8 modId, MmsGetHeader *mHeader);
extern  MSF_BOOL parseEncodedStringValue( MSF_UINT8 modId, unsigned char *buf, MSF_UINT32 size, MSF_UINT32 *lengthOfString, MmsEncodedText *eText);   
extern  MSF_BOOL parseFromAddress( MSF_UINT8 modId, unsigned char *headerData, const MSF_UINT32 headerSize, MmsAddress *from); 
#ifdef __MMS_DUAL_SIM_SUPPORT__
extern void mmsa_update_sim_status( MSF_UINT8 sim_status, MSF_UINT8 sim_setting_mode);
MSF_BOOL mmsa_get_sim_status( MmsSimCardEnum simId);
#endif
#if MMS_CHECK_DUPLICATE_NOTIFICATION
void checkDuplicateMsg(unsigned long chkMsgID,int chkMsgType);
#endif

#if MMS_SEND_REQ_CACHE_SUPPORT 
#define MAX_NO_OF_SR 4
#define MEA_FOLDER "/mea/"
#define MEA_SR_FILE "/mea/srCache.db\x0"
int addMessageIdToDB(void *p);
char *searchSubject(char* serverMsgId);
#endif

#ifdef MMS_FILE_PROTECT_SUPPORT
#define MMS_SUFFIX_CHKSUM 'c'

MmsResult genChkSumFile(MmsMsgId msgId);
void      delChkSumFile(MmsMsgId msgId);
MSF_BOOL  getMmsMsgSubAddr(MSF_UINT8 modId,MmsMsgId msgId, char** subject, char** address,int maxBufSize);
MSF_BOOL  isValidMmsMSg(MmsMsgId msgId);


typedef struct
{
	MSF_UINT32 info_chksum; 		
	MSF_UINT32 msg_chksum;	
	MSF_UINT16 subjectLen;
	MSF_UINT16 addressLen;
	MSF_UINT8* subject;	
	MSF_UINT8* address;		
}mmsCacheInfo;

#define MMS_MIN_CHECKSUM_FILE_SIZE 12 /* info_chksum + msg_chksum + subjectLen + addressLen */
#endif

char *MmsGetSubjectFromSerMsgId(char* serverMsgId);

