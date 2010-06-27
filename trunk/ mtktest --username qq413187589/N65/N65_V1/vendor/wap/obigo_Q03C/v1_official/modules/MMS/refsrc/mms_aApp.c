/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	mms_aApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for new MMS features 
 *   (ex: buffer send request, handle duplicate notification ,..).
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_release.h" 
#include "kal_non_specific_general_types.h"

#include "msf_cfg.h"    
#include "msf_log.h"    
#include "msf_mem.h"
#include "msf_wid.h"
#include "msf_file.h"
#include "msm_env.h"    

#include "mms_def.h"
#include "mms_cfg.h"
#include "mms_if.h"   
#include "mms_env.h" //Jo
#include "msig.h"
#include "mcpdu.h"
#include "mlpdup.h"
#include "mconfig.h"
#include "fldmgr.h"
#include "mmem.h"
#include "mms_aApp.h"

#include "mea_def.h" //Jo
#include "mea_rc.h"
#include "matypes.h"

#include "bra_if.h"

#include "wapadp.h"
#include "wapdef.h"
#include "wap.h"
#include "widget_extension.h"
#include "wap_ps_struct.h"

#ifndef __MTK_TARGET__
#include <stdio.h>
#include <stdlib.h>
extern MSF_UINT32 msf_mem_allocated_bytes(MSF_UINT8 modId);
#endif

extern MeaConfig * meaGetConfig(void); //Jo

typedef struct {
    char fileName[MMS_FILE_LEN];
    MSF_UINT32 msgId;
    MSF_UINT32 size; 
	char suffix;
} mmsFileInFolder;


typedef struct{
	MSF_BOOL used;
	MSF_UINT32  msgId;	
	MSF_UINT32	checksum1;	
	MSF_UINT32	checksum2;	
}MmsMessageFileInfo;


typedef struct 
{	 
	 MSF_UINT32 checkSum;	 
     MmsMessageFileInfo msg[1];    
 
}MmsMessageFileList;

#define SET_HIGH_BIT(a)  (unsigned char)((a) | (unsigned char)0x80)

#if MMS_TEMPLATES_DEMO_SUPPORT
#include "resource_audio.h"
#define mmsBufSize  1000

extern const kal_uint8 *HDIa_widgetExtImageGetPredefinedBuffer(MSF_UINT32 resId, int *length, MsfImageFormat *type);
extern char *generateMmsTransactionId( MSF_UINT8 modId, unsigned long *length);
extern int widget_ucs2_to_utf8_length_in_bytes(const unsigned char* raw);
extern int widget_ucs2_to_utf8_string(unsigned char *dest,int dest_size, const unsigned char* src);
extern MSF_UINT8 getMmsTemplateNum(void);
extern MmsTemplateInfo mmsTemplates[];

typedef enum
{
    MMS_IMAGE,
    MMS_AUDIO,
    MMS_TEXT    
} MmsMediaType; 
#endif

	 

/*************** Extern Functions ***************************************************/
extern unsigned short CMAllowInterrupt(void);
extern int MSF_moduleIsRunning(MSF_UINT8 modId);
//extern int HDIa_widgetExtShowPopup(MSF_UINT8 modId, MsfStringHandle dialogText, MsfDialogType type, int timeout);
extern int MSF_WIDGET_DEVICE_GET_PROPERTIES(MsfDeviceProperties* theDeviceProperties);
extern void widget_send_update_event_to_wap(void);
extern MSF_BOOL isMMSBusy(void);
#ifdef __MMS_DUAL_SIM_SUPPORT__
extern MSF_BOOL IsMasterSIMBusy(void);
extern MSF_BOOL IsSlaveSIMBusy(void);
#endif /*__MMS_DUAL_SIM_SUPPORT__*/

extern void MMSa_resetProgressStatus(void);
#ifdef JPG_ENCODE
extern void meaCleanupResizedFiles(void);
#endif

/*************** General Functions ***************************************************/
MSF_UINT32       fileName2MsgId(char *fName);
static int              atox(char *str); 
static mmsFileInFolder  *folderFiles;      
static int			    noOfFiles;						
static MSF_BOOL         TurnOnEngineerMode=FALSE; 
MSF_UINT32              ROAMING_STATUS=0; // For writing roaming status to registry 
#ifdef __MMS_DUAL_SIM_SUPPORT__
MSF_UINT32              SLAVE_SIM_ROAMING_STATUS = 0; // For writing roaming status to registry 
#endif

/*************** For handling duplicate received messages ****************************/
#if MMS_CHECK_DUPLICATE_NOTIFICATION
static MSF_BOOL         getMMSFolderInfo(void);
static void             fileName2Suffix(char *fName, char *suffix);
static char             fullName[MMS_PATH_LEN + 2];                
static char*            getFilePath(const char *fName, char *pathBuf); 
static MSF_BOOL         cmpMsgConetent(MmsMsgId NewMsgID, MmsMsgId OldMsgID, 
									   MmsMessageType chkMsgType, void* data);
static MSF_BOOL         readHeader(int fileHandle, char* buff, int buffsize);
static MSF_INT32        getIndexFromFolderFiles(MmsMsgId chkMsgID,MmsFileType suffix);
static char*            getHeaderItem(MmsMsgId chkMsgID, MmsFileType suffix,MmsHeaderTag wantHeaderTag);
#endif


/**************** For buffering send request mechanism *******************************/
/**************** For adding checksum protection mechanism for Mms message files******/
#ifdef MMS_FILE_PROTECT_SUPPORT
static MSF_BOOL getCheckSumFromMessageFile(char* fileName,MmsMsgId msgId,MSF_UINT32* checksum,MSF_BOOL isLargeMsg);
static void setSubAddr(char** output_str,MSF_UINT16* output_str_len, char *input_str,int maxBufSize);
#endif
#ifdef MMS_SUPPORT
#ifdef MMS_FILE_PROTECT_SUPPORT
static MSF_BOOL isValidMmsIndexFile(void);
#endif /*MMS_FILE_PROTECT_SUPPORT*/
#endif /*MMS_SUPPORT*/
#ifdef __MMS_CACHE_PUSH__
MSF_UINT32 mmsGetCachedPushNum(void);
#endif

MSF_BOOL MMS_FILE_OPEN_BLOCK_FLAG=FALSE; 

#ifdef __MMS_DUAL_SIM_SUPPORT__
static MSF_BOOL status_sim_master = FALSE;
static MSF_BOOL status_sim_slave = FALSE;
#endif
/************************************************************************************************
*
*
*
*                                      General Functions
*
*
*
************************************************************************************************/
/************************************************************************
* FUNCTION                                                            
*	updateRoamingStatusToMMS
*
* DESCRIPTION                                                           
* 	Write the roaimg status into the registry.
* CALLS  
*                           
* PARAMETERS
*	none
* RETURNS
*	None
* GLOBALS AFFECTED
* 	MSF Registry MMS_REG_KEY_NETWORK_STATUS_ROAMING
*************************************************************************/
//The function must be called in BRA_start()
void updateRoamingStatusToMMS(MSF_INT32 simId)
{
    void* reg_handle = NULL;
    MmsRegistryEntry* MmsRegistryRoamingEntry = NULL;
    char *key_str = MMS_REG_KEY_NETWORK_STATUS_ROAMING;
    int key_value = ROAMING_STATUS;

#ifdef __MMS_DUAL_SIM_SUPPORT__
    if (simId == MMS_SIM_CARD_SLAVE)
    {
        key_str = MMS_REG_KEY_SLAVE_SIM_NETWORK_STATUS_ROAMING;
        key_value = SLAVE_SIM_ROAMING_STATUS;
    }
#endif

    MSF_LOG_MSG_ARGS((
        MSF_LOG_DETAIL_MEDIUM,
        MSF_MODID_MMS,
        MMS_AAPP_6B0186307DE10634B3AB30B4C186C2BE, "Write the current roaming status %d of sim %d into MSF registery \n",
        key_value,
        simId));

    reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_MMS);
    if(reg_handle)
    {
        MSF_REGISTRY_SET_PATH (reg_handle, (char*)MMS_REG_PATH_NETWORK_STATUS);
        MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, (char*)key_str, key_value);
        MSF_REGISTRY_SET_COMMIT (reg_handle);                
    }
    else
    {
        return;
    }
    if(MSF_moduleIsRunning(MSF_MODID_MMS))
    {
        MmsRegistryRoamingEntry=MMS_CALLOC(sizeof(MmsRegistryEntry));		
        if(MmsRegistryRoamingEntry)
        {
            MmsRegistryRoamingEntry->path=MMS_CALLOC(strlen((char*)MMS_REG_PATH_NETWORK_STATUS)+1);			
            if(MmsRegistryRoamingEntry->path)
            {
                strcpy(MmsRegistryRoamingEntry->path,(char*)MMS_REG_PATH_NETWORK_STATUS);
            }
            else
            {
                return;
            } 			
            MmsRegistryRoamingEntry->key=MMS_CALLOC(strlen((char*)key_str)+1);			
            if(MmsRegistryRoamingEntry->key)
            {
                strcpy(MmsRegistryRoamingEntry->key,(char*)key_str);
            }
            else
            {
                return;
            }
			
            MmsRegistryRoamingEntry->type = MSF_REGISTRY_TYPE_INT;
            MmsRegistryRoamingEntry->value_i = key_value;
            MmsRegistryRoamingEntry->next = NULL;
            MmsRegistryRoamingEntry->value_bv = NULL;
            MmsRegistryRoamingEntry->value_bv_length = 0;
            M_SIGNAL_SENDTO_P(M_FSM_CORE_CONFIG, (int)MMS_SIG_CORE_REG_RESPONSE, 
                MmsRegistryRoamingEntry);
        }
    }	
    widget_send_update_event_to_wap();
}
/************************************************************************
* FUNCTION                                                            
*	writeRoamingStatusForMMS
*
* DESCRIPTION                                                           
* 	Write the roaimg status into the registry.
* CALLS  
*                           
* PARAMETERS
*	isRoaming
* RETURNS
*	None
* GLOBALS AFFECTED
* 	ROAMING_STATUS and MSF Registry MMS_REG_KEY_NETWORK_STATUS_ROAMING
*************************************************************************/
void writeRoamingStatusForMMS(MSF_INT32 simId, MSF_INT32 isRoaming)
{   	

    switch(simId)
    {
        case MMS_SIM_CARD_MASTER:
            if(ROAMING_STATUS == isRoaming)
            {
                return;	
            }
            else
            {
                ROAMING_STATUS = isRoaming;
            }
            break;
#ifdef __MMS_DUAL_SIM_SUPPORT__
        case MMS_SIM_CARD_SLAVE:
            if(SLAVE_SIM_ROAMING_STATUS == isRoaming)
            {
                return;	
            }
            else
            {
                SLAVE_SIM_ROAMING_STATUS = isRoaming;
            }
            break;
#endif
        default:
            ASSERT(0);
            break;
    }
    if(MSF_moduleIsRunning(MSF_MODID_MSM))
    {
        updateRoamingStatusToMMS(simId);
    }		
}

/************************************************************************
* FUNCTION                                                            
*	setMmscVersion
*
* DESCRIPTION                                                           
* 	Set MMS Proxy-Relay Version based on operator's PLMN.
*  	If curPLMN="VER10" or "VER11", this function just sets it without checking PLMN database.
* CALLS  
*                           
* PARAMETERS
*	curPLMN
* RETURNS
*	None
* GLOBALS AFFECTED
* 	MSF Registry MMS_REG_KEY_PROXY_RELAY_VERSION
*************************************************************************/
void setMmscVersion(const char *curPLMN)
{
	void* reg_handle=NULL;	   
    	MSF_INT32 version=MMS_VERSION_11;
	MmsRegistryEntry *MmsRegistryMMSCVersionEntry=NULL;

	if(TurnOnEngineerMode)
    	{
		return;
	}

//micha0422 begin
	if(curPLMN)
    	{
		if(strncmp(curPLMN,"VER10",5)==0) //For internal use
		{
		version=MMS_VERSION_10;
		}
		else if(strncmp(curPLMN,"VER11",5)==0) //For internal use
        	{
			version=MMS_VERSION_11;
		}
		else if(strncmp(curPLMN,"VER12",5)==0) //For internal use
        	{
			version=MMS_VERSION_12;
		}		
		else if(strncmp(curPLMN,"46601",5)==0) //FarEasTone Telecommunications
        	{
			version=MMS_VERSION_10;
		}
	}
//micha0422 end
    
	if(MSF_moduleIsRunning(MSF_MODID_MMS))
	{
		if(cfgGetInt(MMS_CFG_PROXY_RELAY_VERSION)==version)
		{
			return;					
		}
	}

    		
	reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_MMS);
	if(reg_handle)
	{		
		MSF_REGISTRY_SET_PATH(reg_handle, (char *)MMS_REG_PATH_COM_MMSC);
		MSF_REGISTRY_SET_ADD_KEY_INT(reg_handle, (char *)MMS_REG_KEY_PROXY_RELAY_VERSION, version);				
		MSF_REGISTRY_SET_COMMIT(reg_handle);
		MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,MMS_AAPP_DEB25CC3746ECF34A2E65BEB048E7A9A, "%s(%d):Change the MMSC version to %d. \n", __FILE__, __LINE__, version));   	
	}
	
	if(MSF_moduleIsRunning(MSF_MODID_MMS))
	{
		MmsRegistryMMSCVersionEntry=MMS_CALLOC(sizeof(MmsRegistryEntry));		
		if(MmsRegistryMMSCVersionEntry)
		{
			MmsRegistryMMSCVersionEntry->path=MMS_CALLOC(strlen((char*)MMS_REG_PATH_COM_MMSC)+1);			
			if(MmsRegistryMMSCVersionEntry->path)
			{
				strcpy(MmsRegistryMMSCVersionEntry->path,(char*)MMS_REG_PATH_COM_MMSC);
			}
			else
			{
				return;
			}						
			MmsRegistryMMSCVersionEntry->key=MMS_CALLOC(strlen((char*)MMS_REG_KEY_PROXY_RELAY_VERSION)+1);			
			if(MmsRegistryMMSCVersionEntry->key)
			{
				strcpy(MmsRegistryMMSCVersionEntry->key,(char*)MMS_REG_KEY_PROXY_RELAY_VERSION);
			}
			else
			{
				return;
			}							
			MmsRegistryMMSCVersionEntry->type=MSF_REGISTRY_TYPE_INT;
			MmsRegistryMMSCVersionEntry->value_i=version;
			MmsRegistryMMSCVersionEntry->next=NULL;
			MmsRegistryMMSCVersionEntry->value_bv=NULL;
			MmsRegistryMMSCVersionEntry->value_bv_length=0;
			M_SIGNAL_SENDTO_P(M_FSM_CORE_CONFIG, (int)MMS_SIG_CORE_REG_RESPONSE, 
                           MmsRegistryMMSCVersionEntry);		
		}
	}
	widget_send_update_event_to_wap();
}   

/************************************************************************
* FUNCTION                                                            
*	setMMSCVersionByEngineerMode
*
* DESCRIPTION                                                           
*	Support to modify MMS version by engineer mode
*
* CALLS  
*                           
* PARAMETERS
*	EM_MMS_VERSION_DEFAULT (Accoring to different operators,
*		it dynamically switches between 1.0 and 1.1),
*	EM_MMS_VERSION_10,
*	EM_MMS_VERSION_11
* RETURNS
*	None
* GLOBALS AFFECTED
* 	MSF Registry MMS_REG_KEY_PROXY_RELAY_VERSION
*************************************************************************/
void setMMSCVersionByEngineerMode(int mode)
{
	switch(mode)
	{
		case EM_MMS_VERSION_DEFAULT: //Default
			TurnOnEngineerMode=FALSE;
		    switch(wap_custom_get_mms_version())
            {
            case 0:
            case 1:
                setMmscVersion("VER10");
                break;
            case 2:
                setMmscVersion("VER11");
                break;
            case 3:
            case 4:
            default:
                setMmscVersion("VER12");
                break;
            }
			break;

		case EM_MMS_VERSION_10: //MMS_VERSION_10
			TurnOnEngineerMode=FALSE;
			setMmscVersion("VER10");
			TurnOnEngineerMode=TRUE;
			break;
     	case EM_MMS_VERSION_11: //MMS_VERSION_11
			TurnOnEngineerMode=FALSE;
			setMmscVersion("VER11");
			TurnOnEngineerMode=TRUE;
			break;			
       	case EM_MMS_VERSION_12: //MMS_VERSION_12
			TurnOnEngineerMode=FALSE;
			setMmscVersion("VER12");
			TurnOnEngineerMode=TRUE;
			break;				
	}
}


/************************************************************************
* FUNCTION                                                            
*	loadMmsDataToBuffer(MSF_UINT8 modId, MmsMsgId msgId,char suffix,char **buffer, int *bufSize)
*
* DESCRIPTION                                                           
*	Load data of a mms file into memory. 
*	Note that the size of mms file msut be lower than MMS_MAX_CHUNK_SIZE.
*
* CALLS  
*                           
* PARAMETERS
*	MSF_UINT8 modId, MmsMsgId msgId,char suffix,char **buffer, int *bufSize
* RETURNS
*	TRUE or FALSE
* GLOBALS AFFECTED
* 	Write buffer address and buffer size to buffer and bufSize if file read operation works
*************************************************************************/
MSF_BOOL loadMmsDataToBuffer(MSF_UINT8 modId, MmsMsgId msgId,char suffix,char **buffer, int *bufSize)
{
	char filepath[MMS_PATH_LEN + 2];
	int openMode=HDI_FILE_SET_RDONLY; 
   	int fileHandle=-1;
    	int fileSize=0;
       
	/* Create a full file path */
    	memset(filepath,0x00,MMS_PATH_LEN + 2);
	sprintf(filepath,"%s%lx.%c",MMS_FOLDER,msgId,suffix);

	fileHandle = HDIa_fileOpen( modId,filepath,openMode, 0);
	if(fileHandle>=0)
	{
		if((fileSize=MSF_FILE_GETSIZE(filepath))>=MMS_MAX_CHUNK_SIZE)
		{
			fileSize=MMS_MAX_CHUNK_SIZE;
		}        
		if(fileSize<=0||(*buffer=(char *)MSF_MEM_ALLOC(modId,fileSize))==NULL)
		{
			MSF_FILE_CLOSE(fileHandle);
			return FALSE;
		}
        	else if(fileSize!=(MSF_INT32)MSF_FILE_READ(fileHandle,*buffer,fileSize))
		{
			MSF_MEM_FREE(modId,*buffer);
			*buffer=NULL;
			MSF_FILE_CLOSE(fileHandle);
			return FALSE;
		}
              	MSF_FILE_CLOSE(fileHandle);
	}
	*bufSize=fileSize;
	return TRUE;
	
}
/************************************************************************
* FUNCTION                                                            
*	getMMSVersion(MSF_UINT8 modId, MmsMsgId msgId)
*
* DESCRIPTION                                                           
*	check if the mms version of a received mms message is v1.1 or v1.0.
*
* CALLS  
*                           
* PARAMETERS
*	MSF_UINT8 modId, MmsMsgId msgId
* RETURNS
*	MMS_VERSION_10 or MMS_VERSION_11
* GLOBALS AFFECTED
* 	None
*************************************************************************/
MSF_INT32 getMMSVersion(MSF_UINT8 modId, MmsMsgId msgId)
{
	char *buffer=NULL;
	int   bufSize=0;
	MmsHeaderValue  headerValue;
	MmsVersion version=MMS_VERSION_11;

	if(MSF_moduleIsRunning(MSF_MODID_MMS))
	{
		if(cfgGetInt(MMS_CFG_PROXY_RELAY_VERSION)==MMS_VERSION_10)
    		{
			return MMS_VERSION_10;					
		}
	}
	loadMmsDataToBuffer(modId,msgId,'m',&buffer,&bufSize);	
	if(buffer)
    	{
		if (mmsPduGet((unsigned char*)buffer, bufSize, X_MMS_VERSION, &headerValue))
		{
			version = (MmsVersion)headerValue.version;
		}
		MSF_MEM_FREE(modId,buffer);
		buffer=NULL;	
	}
	return version;	
}
/************************************************************************
* FUNCTION                                                            
*	getCheckSum
*
* DESCRIPTION                                                           
*	Calculate the checksum value from a specified memory.
*
* CALLS  
*                           
* PARAMETERS
*	void *data,int datalen, MSF_UINT32 divisor
* RETURNS
*	None
* GLOBALS AFFECTED
* 	None
*************************************************************************/
#ifdef MMS_SUPPORT
#ifdef MMS_FILE_PROTECT_SUPPORT
static MSF_UINT32 getCheckSum(void *data,int datalen, MSF_UINT32 divisor)
{
	int i;
	MSF_UINT32 sum=0;
	unsigned char *startpos;
	startpos=(unsigned char *)data;
	for(i=0;i<datalen;i++){
		sum+=*startpos;
		startpos++;
	}
	return sum%divisor;
} 
#endif /*MMS_FILE_PROTECT_SUPPORT*/
#endif /*MMS_SUPPORT*/
/************************************************************************
* FUNCTION                                                            
*	fileName2MsgId
*
* DESCRIPTION                                                           
*  This local function is used to extract the MSF_UINT32 msgId from a file name (ex:1a.s).
*
* CALLS  
*   checkDuplicateMsg                      
* PARAMETERS
*	*fname
* RETURNS
*	MSF_UINT32 msgId
* GLOBALS AFFECTED
*   None
*************************************************************************/
MSF_UINT32 fileName2MsgId(char *fName)
{
  char *dot; 
  char tmpFileName[MMS_FILE_LEN]; 

  dot = strchr (fName,'.' );
  if (dot != NULL)
  {
      strncpy(tmpFileName, fName, (unsigned int)dot - (unsigned int)fName);
      tmpFileName[(int)dot - (int)fName] = '\0';
  
      return (MSF_UINT32)atox(tmpFileName);
  }
  else
  {
      return 0;
  } 
} 

/************************************************************************
* FUNCTION                                                                                                                   
*	atox
*
* DESCRIPTION                                                           
*  This local function is used to transfer a hexadecimal string to integer.
*
* CALLS  
*   fileName2MsgId                       
* PARAMETERS
*	*str
* RETURNS
*	None
* GLOBALS AFFECTED
*   None
*************************************************************************/
static int atox(char *str)        
{
    int num = 0;   
    int neg = 0;     

    while (*str == '-') 
    {
        str++;
        neg = !neg;
    } 
 
    while (*str != '\0') 
    {
        if ( (*str < '0') && (*str > 'f') && ((*str >= 'a') && (*str <= '9')))                     
        {
            break;
        } 
                 
        if (*str <= '9')
        {
            num = (16 * num) + (*str - '0');
        }
        else
        {
            num = (16 * num) + (*str - 87);
        }
        str++;
    } 
 
    return (neg ? -num : num);
} 
/************************************************************************
* FUNCTION                                                            
*	sReachMEAMaxNumofMsg(MSF_UINT32 MEA_MAX_NO_OF_MSG)
*
* DESCRIPTION                                                           
*	Check if the current number of mms message in MMS folder is reached to the threshold value 
*
* CALLS  
*                           
* PARAMETERS
*	MSF_UINT32 meaNoMaxMSG
* RETURNS
*	TRUE or FALSE
* GLOBALS AFFECTED
* 	None
*************************************************************************/
MSF_BOOL IsReachMEAMaxNumofMsg(MSF_UINT32 meaNoMaxMSG)
{
	MSF_UINT32 NoOfMsg;
	NoOfMsg=MMS_MAX_NO_OF_MSG-fldrGetNoOfFreeMsg();
	
	if(NoOfMsg>=meaNoMaxMSG)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}	
}

/************************************************************************
* FUNCTION                                                            
*	mmsHandleErrors(int result)
*
* DESCRIPTION                                                           
*	Handle mms error when MEA isn't available
*
* CALLS  
*                           
* PARAMETERS
*	int result
* RETURNS
*	None
* GLOBALS AFFECTED
* 	None
*************************************************************************/
void mmsHandleErrors(int result)
{
	if(!CMAllowInterrupt())
	{
		return;
	}
    	switch(result)
    	{	
        case MMS_RESULT_MAX_RETRIEVAL_SIZE_EXCEEDED:
            HDIa_widgetExtRegisterSystemMsg(MSF_MODID_MMS, MEA_STR_ID_MMS, 
                MEA_STR_ID_RETR_SIZE_EXCEEDED);
            break;
		/* Max number of stored message reached. */ 
		case MMS_RESULT_TOO_MANY_MSG:
		default:
		    MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MEA,
			    MMS_AAPP_46004D12B4BC0FD8886C7B22F543EEAE, "(%s) (%d) Unhandled MMS Service result\n", __FILE__, __LINE__));
			break;
    	}
}
/************************************************************************
* FUNCTION                                                            
*	handleNewMessage
*
* DESCRIPTION                                                           
*  This function is used to inform the MEA module of new mms message.
*  The MEA module will display the confirmation screen and ask you if reading 
*  the MMS message.
* CALLS  
*   void MMSa_newMessage                        
* PARAMETERS
*	MsgID
* RETURNS
*	None
* GLOBALS AFFECTED
*   None
*************************************************************************/
void handleNewMessage(MmsMsgId msgId)
{
    if( /* CMAllowInterrupt()&& */ !MSF_moduleIsRunning(MSF_MODID_MEA))	
    {
	char meaViewCmd[23];
	memset(meaViewCmd,0x00,23);
	sprintf(meaViewCmd,"%s%lx\n","-mode view -m ",msgId);	
		MSMc_startModule(MSF_MODID_MEA,meaViewCmd);
    }
}

/************************************************************************
* FUNCTION                                                            
*	handleDownloadMessage
*
* DESCRIPTION                                                           
*  This function is used to inform the MEA module of new mms notification.
*  The MEA module will display the download screen and ask you if it shall 
*  be downloaded.
* CALLS  
*   void MMSa_newMessage                        
* PARAMETERS
*	MsgID
* RETURNS
*	None
* GLOBALS AFFECTED
*   None
*************************************************************************/
void handleDownloadMessage(MmsMsgId msgId,MSF_UINT32 size)
{
	if(/*CMAllowInterrupt()&& */ !MSF_moduleIsRunning(MSF_MODID_MEA))
	{
		char meaViewCmd[37];
		memset(meaViewCmd,0x00,37);
		sprintf(meaViewCmd,"%s%lx%s%ld\n","-mode download -m ",msgId," -size ",size);	
		MSMc_startModule(MSF_MODID_MEA,meaViewCmd);
	}
}

#if !defined(__MTK_TARGET__)||MMS_CHECK_DUPLICATE_NOTIFICATION
/************************************************************************
* FUNCTION                                                            
*	fileName2Suffix
*
* DESCRIPTION                                                           
*  This local function is used to extract the suffix from a file name (ex:1a.s).
*
* CALLS  
*   checkDuplicateMsg                      
* PARAMETERS
*	*fname, *suffix
* RETURNS
*	None
* GLOBALS AFFECTED
*   It store the result to suffix.
*************************************************************************/
static void fileName2Suffix(char *fName, char *suffix)
{
  char *dot;
  dot=strchr (fName,'.');
  if (dot != NULL)
  {
      strncpy(suffix, dot+1, 1); 
      
  }
} 
static MSF_BOOL getMMSFolderInfo()
{   
   int i=0,j=0;
   int type = 0;
   int size = 0;
   int dirHandle=-1;   
   folderFiles=NULL;
   noOfFiles=0;
   
   if(folderFiles)
   {
	   MMS_FREE(folderFiles);   
   }
   noOfFiles =  MSF_FILE_GETSIZE_DIR (MMS_FOLDER);
   if(noOfFiles<=0)
	   return FALSE;
   folderFiles = (mmsFileInFolder*)MMS_CALLOC(sizeof(mmsFileInFolder) *
        (unsigned int)noOfFiles);
   
   if(!folderFiles)
   {
	   return FALSE;
   }
   j=0;

	//filter the messages "mms.cn", "mms.bak" and "mms.cn"  GH_Comment 031201
    for (i = 0; i < noOfFiles; i++)
    {
        if ( (MSF_FILE_READ_DIR_SEQ(MMS_FOLDER, i, folderFiles[j].fileName,
            MMS_FILE_LEN, &type, &size, &dirHandle) == MSF_FILE_OK) &&
            (msf_cmmn_strcmp_nc(folderFiles[j].fileName, MMS_MMT) != 0) && 
            (msf_cmmn_strcmp_nc(folderFiles[j].fileName, MMS_MMTBACK) != 0) &&
            (msf_cmmn_strcmp_nc(folderFiles[j].fileName, MMS_MMTTMP) != 0))
        {
            folderFiles[j].size=size;
			j++;   
        } 
    }
    MSF_FILE_READ_DIR_SEQ_CLOSE(&dirHandle);
    noOfFiles = j; 

	for (i = 0; i < noOfFiles; i++)
    {
        folderFiles[i].msgId = fileName2MsgId(folderFiles[i].fileName);   
        fileName2Suffix(folderFiles[i].fileName, &folderFiles[i].suffix);
        
    } 
	return TRUE;
}
#endif

#if MMS_CHECK_DUPLICATE_NOTIFICATION
static char* getFilePath(const char *fName, char *pathBuf) 
{
    strcpy(pathBuf, MMS_FOLDER); 
    strcat(pathBuf + strlen(MMS_FOLDER), fName);
    return pathBuf;
} 
/************************************************************************
* FUNCTION                                                            
*	checkDuplicateMsg
*
* DESCRIPTION                                                           
*  This function will check if the specific mms message has duplicate mms messages in the MMS folder. 
*  It finds them and deletes them.
* CALLS  
*   MMSa_newMessage                       
* PARAMETERS
*	MmsMsgId, MmsMessageType
* RETURNS
*	None
* GLOBALS AFFECTED
*   It deletes all duplicate mms messages.
*************************************************************************/
void checkDuplicateMsg(unsigned long chkMsgID,int chkMsgType){
   
   int i;
   char *mkey=NULL;

   
    if(!getMMSFolderInfo())
		return;

	
	switch (chkMsgType)
	{		 
		case MMS_SUFFIX_NOTIFICATION:
			{	//Check Key is X_MMS_CONTENT_LOCATION		
				mkey=getHeaderItem(chkMsgID,MMS_SUFFIX_NOTIFICATION,X_MMS_CONTENT_LOCATION);								
				if(mkey==NULL)
				{								
   
						MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
                		MMS_AAPP_5C1D8A97437B1F7A0E7B6C2D5A06BF81, "%s(%d): Can't retrieve the matching key.\n",
						__FILE__, __LINE__));  																
				}
				break;
			}
		}


	if(mkey!=NULL)
	{
		for (i = 0; i < noOfFiles; i++)
		{
			if((folderFiles[i].suffix==chkMsgType)&&(chkMsgID!=folderFiles[i].msgId))
			{
				if(cmpMsgConetent(chkMsgID,folderFiles[i].msgId,chkMsgType,mkey))
				{				
	
				}
			}
		}
	}

	MMS_FREE(folderFiles);
	if(mkey!=NULL)
		MMS_FREE(mkey);
	
}

/************************************************************************
* FUNCTION                                                            
*	readHeader
*
* DESCRIPTION                                                           
*  This local function is used to read data from the mms fils including notify, read and delivery report.
*
* CALLS  
*   getHeaderItem                      
* PARAMETERS
*	filehandle, buff, buffSize
* RETURNS
*	None
* GLOBALS AFFECTED
*   None
*************************************************************************/
static MSF_BOOL readHeader(int fileHandle, char* buff, int buffsize){
	
	int size=buffsize;
	int ret;
	int position=0;
	for (;;){
		if (size <= 0) // We have read everything that we should 
		{       		          			
			return TRUE;
		}
		ret = MSF_FILE_READ( fileHandle, buff, size);
        switch (ret){
			
			case 0 :
			case MSF_FILE_ERROR_EOF :		          		    	
			case MSF_FILE_ERROR_ACCESS :
				MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
        		MMS_AAPP_E92995BC353D6D26B6BBD3A731CEBB77, "%s(%d): Read returned %d\n", __FILE__, __LINE__, ret));		  		        		
			case MSF_FILE_ERROR_DELAYED :                	  			
		    default :
        		if (ret < 0){
        			MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
                	MMS_AAPP_D4FD45BD4DCDB884139BD7371682204F, "%s(%d): Unhandled file error %d\n",
		            __FILE__, __LINE__, ret));           
        		} 					        		  			
				position += ret;
		        size -= ret;
		        break;	
		 }	      			 
     }
return FALSE;
}


/*************************************************************************
* FUNCTION                                                            
*	getIndexFromFolderFiles
*
* DESCRIPTION                                                           
*  This function is used to get the index of folderFiles for the specific msgId.
*
* CALLS  
*   getHeaderItem                       
* PARAMETERS
*	MmsMsgId
* RETURNS
*	Index
* GLOBALS AFFECTED
*   None
*************************************************************************/
static MSF_INT32 getIndexFromFolderFiles(MmsMsgId chkMsgID,MmsFileType suffix){
	int i;
	for(i=0;i<noOfFiles;i++)
	{
		if((folderFiles[i].msgId==chkMsgID)&&(folderFiles[i].suffix==suffix))
			return i;
	}
	return -1;
} 



/*************************************************************************
* FUNCTION                                                            
*	getHeaderItem
*
* DESCRIPTION                                                           
*  This function is used to get the specific header field from the one mms file.
*
* CALLS  
*   cmpMsgConetent, checkDuplicateMsg                        
* PARAMETERS
*	
* RETURNS
*	
* GLOBALS AFFECTED
*   
*************************************************************************/
static char* getHeaderItem(MmsMsgId chkMsgID, MmsFileType suffix, MmsHeaderTag wantHeaderTag){

    	int fileHandle;
	int openMode;
	MSF_UINT32 length;
	int startposition;
    	int index=getIndexFromFolderFiles(chkMsgID,suffix);
	char* buff;
	char *output=NULL;
	MmsHeaderValue cntLocation;	

	if(index>=0){
		startposition=0;
		length=folderFiles[index].size;
		buff = MMS_CALLOC(folderFiles[index].size);
		if(buff!=NULL){
			openMode=MSF_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING;
			fileHandle = MSF_FILE_OPEN( MSF_MODID_MMS,
			    		getFilePath(folderFiles[index].fileName,fullName), 
						openMode, 0);								
            memset(fullName,0x00,MMS_PATH_LEN+2);
		
			if(fileHandle>0){
				if(readHeader(fileHandle,buff,length))
				{	
					switch(wantHeaderTag)
					{					
						case X_MMS_CONTENT_LOCATION:
							{							
								if (!mmsPduGet( buff, length, X_MMS_CONTENT_LOCATION, &cntLocation))
								{
								MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
								MMS_AAPP_0989B2588E970425072E7857CCD7BBE4, "%s(%d): No X_MMS_CONTENT_LOCATION tag\n", __FILE__, __LINE__));
									output=NULL;
									break;
								}							
								if((char*)cntLocation.contentLocation)
								{
									output=MMS_CALLOC(strlen((char *)cntLocation.contentLocation)+1);
									if(output)
										strcpy(output,(char*)cntLocation.contentLocation);
				
							}							
							break;
						}
					}									
				}
				else
				{
					MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
					MMS_AAPP_22C20C13184E88D196C49E7BE046B4BF, "%s(%d): read header from the file with msgid %d.\n",
					__FILE__, __LINE__,chkMsgID));  			

				}
				MMS_FREE(buff);
				MSF_FILE_CLOSE(fileHandle);
			}
			else
			{
        			MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
                	MMS_AAPP_4163F0935B312129EC07018507DAED6B, "%s(%d): Can't open the file.\n",
		            __FILE__, __LINE__));  			
			} 
		}else
		{
        			MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
                	MMS_AAPP_699FA1845FC3A97E7DB10AADF1C9C486, "%s(%d): Can't allocate the memory to read header from mms file.\n",
		            __FILE__, __LINE__));  			
		}
	}
	return output;
}

/*************************************************************************
* FUNCTION                                                            
*	cmpMsgConetent
*
* DESCRIPTION                                                           
*  This function is used to check if two mms messages are duplicate.
*  If so, it deletes the old mms message and keeps the latest one.
*
* CALLS  
*   cmpMsgConetent, checkDuplicateMsg                        
* PARAMETERS
*	MsgId_A, MsgId_B, MmsMessageType, 
* RETURNS
*	TRUE or FALSE
* GLOBALS AFFECTED
*	None
*   
*************************************************************************/
static MSF_BOOL cmpMsgConetent(MmsMsgId NewMsgID, MmsMsgId OldMsgID, MmsMessageType chkMsgType, void* data){
    
    char *oldCntLocate=NULL;
    MSF_BOOL ret=FALSE;
    
	switch(chkMsgType)
	{

		case MMS_SUFFIX_NOTIFICATION:
			{			
	        
				oldCntLocate=getHeaderItem(OldMsgID,MMS_SUFFIX_NOTIFICATION,X_MMS_CONTENT_LOCATION);
				if((data!=NULL)&&(oldCntLocate!=NULL))
				{            
					if(msf_cmmn_strcmp_nc((char*)data, oldCntLocate)==0)
					{
						//delete the new M-Notification.ind message file
						fldrMgrDeleteMessage(NewMsgID); 
						ret=TRUE;						
					}
					MMS_FREE(oldCntLocate);
				}			
			}
			break;          								
		}								
	return ret;
}
#endif



/*************************************************************************************************
*
*                           MMS File Protection Mechanism                 
* 
*
*
**************************************************************************************************/
#ifdef MMS_FILE_PROTECT_SUPPORT
#include "mmsl_if.h"
#include "mltypes.h"
#include "mlfetch.h"       
#include "mutils.h"       

typedef struct 
{
    MSF_INT32 checkSum;             
    MSF_UINT32 nextFreeMsgId;        
    MmsMessageFolderInfo msg[1];    
	
} Mmtlist;

/*************************************************************************
* FUNCTION                                                            
*	getCheckSumFromMessageFile(char* fileName,MmsMsgId msgId,MSF_UINT32* checksum,MSF_BOOL isLargeMsg)
*
* DESCRIPTION                                                           
*  This function is used to get checksum from a specified mms message.
*
*
* CALLS  
*   cmpMsgConetent, checkDuplicateMsg                        
* PARAMETERS
*	char* fileName,MmsMsgId msgId,MSF_UINT32* checksum,MSF_BOOL isLargeMsg 
* RETURNS
*	TRUE or FALSE
* GLOBALS AFFECTED
*	None
*   
*************************************************************************/
static MSF_BOOL getCheckSumFromMessageFile(char* fileName,MmsMsgId msgId,MSF_UINT32* checksum,MSF_BOOL isLargeMsg)
{
	MSF_INT32  filehandle=-1;	
	MSF_INT32  totalFileSize=-1;
	MSF_UINT32 currLen=0;
	MSF_INT32  readSize=0;
	MSF_UINT32 sum=0;
	MSF_INT8*  buffer=NULL;
        MSF_INT8*  infoBuffer=NULL;
	MSF_BOOL   result=FALSE;
	
	/* LargeMsg means MMS_SUFFIX_TEMPLATE, MMS_SUFFIX_SEND_REQ and MMS_SUFFIX_MSG 
	*  The size of these messages may be huge. Thus we don't protect all data.
	*  We just protect the mms header and each body header of mms message.		  
	*  Because these headers are more important than body data, such as image data
	*/
    	if(isLargeMsg)
	{
		MmsMessage virtualMsgHandle;
		
		char infoFilePath[100];
		int i,j;
		MSF_INT32 bytesInfoBuf=0;
		MSF_UINT32 noObjects=0;
		MSF_UINT32 filepos=0;
		MSF_INT32 bytesLeft=-1;
		MSF_UINT32 maxEntrySize=0;

		memset(infoFilePath,0x00,100);
		sprintf(infoFilePath,"%s%lx.i",MMS_FOLDER,msgId);
		bytesInfoBuf=MSF_FILE_GETSIZE(infoFilePath);
		totalFileSize=MSF_FILE_GETSIZE(fileName);
		/* Check if mms message size and its information file size are valid */
		if(totalFileSize<=0||bytesInfoBuf<=0||(infoBuffer=(MSF_INT8 *)MMS_CALLOC(bytesInfoBuf))==NULL)			
		{
			return FALSE;		
		}			
		/* Read data of information file into infoBuffer*/
		filehandle=MSF_FILE_OPEN(MSF_MODID_MMS,infoFilePath,MSF_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING,0);
		if(filehandle<0||(MSF_FILE_READ(filehandle,infoBuffer,bytesInfoBuf)!=bytesInfoBuf))
		{
			MMS_FREE(infoBuffer);
			return FALSE;	
		}		
		MSF_FILE_CLOSE(filehandle);
		virtualMsgHandle.infoHandle.buffer=(MSF_UINT8*)infoBuffer;
		virtualMsgHandle.infoHandle.bufferSize=bytesInfoBuf;
		/* Find the max header size and allocate the memory*/
		noObjects=getNumberOfParts(&virtualMsgHandle);
		maxEntrySize=getMaxEntrySize(&virtualMsgHandle);
		i=getEntrySize(0,&virtualMsgHandle);
		if(maxEntrySize<i)
			maxEntrySize=i;
		if((maxEntrySize>MMS_MAX_CHUNK_SIZE) ||maxEntrySize==0||((buffer=(MSF_INT8 *)MMS_CALLOC(maxEntrySize))==NULL))
		{
			MMS_FREE(infoBuffer);
			return FALSE;	
		}		
		filehandle=-1;
		if((filehandle=MSF_FILE_OPEN(MSF_MODID_MMS,fileName,MSF_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING,0))<0)
		{
			MMS_FREE(infoBuffer);
			MMS_FREE(buffer);
			*checksum=0;
			return FALSE;
		}
		result=TRUE;
		/* Read the data of each header to buffer and calculate its checksum*/
		for(i=0;i<=noObjects;i++)
		{
			filepos=getEntryStart(i,&virtualMsgHandle);
			bytesLeft=getEntrySize(i,&virtualMsgHandle);
			if(filepos+bytesLeft>totalFileSize)						
			{
				result=FALSE;
				break;
			}
			memset(buffer,0x00,maxEntrySize);
			MSF_FILE_SEEK(filehandle, filepos, MSF_FILE_SEEK_SET);
			if(MSF_FILE_READ(filehandle,buffer,bytesLeft)!=bytesLeft)			
			{
				result=FALSE;
				break;						
			}
			for(j=0;j<bytesLeft;j++)			
				*checksum+=*(buffer+j);			
		}			
		MMS_FREE(infoBuffer);
		MMS_FREE(buffer);
		MSF_FILE_CLOSE(filehandle);
		if(!result)
			*checksum=0;
		return result;		
	}
	else
	{
		/* NonLargeMsg means MMS_SUFFIX_IMMEDIATE,MMS_SUFFIX_NOTIFICATION,MMS_SUFFIX_READREPORT
		*  and MMS_SUFFIX_DELIVERYREPORT. The size of these messages are small. 
		*  For efficiency, we calculate the cjecksum using all data of mms message.		
		*/	
		totalFileSize=MSF_FILE_GETSIZE(fileName);
		filehandle=MSF_FILE_OPEN(MSF_MODID_MMS,fileName,MSF_FILE_SET_RDONLY| HDI_FILE_SET_CUSTOM_BLOCKING,0);				        
		if(filehandle<0||totalFileSize<=0)
		{											
			return FALSE;
		}
		else
		{
			buffer=NULL;
			(totalFileSize>MMS_MAX_CHUNK_SIZE) ? (buffer=MMS_ALLOC(MMS_MAX_CHUNK_SIZE))
				: (buffer=MMS_ALLOC(totalFileSize));
		
			if(!buffer)
			{
				MSF_FILE_CLOSE(filehandle);
				return FALSE;
			}
					
			while(currLen<totalFileSize)
			{
				readSize=0;				
				if((totalFileSize-currLen)>MMS_MAX_CHUNK_SIZE)
				{
					readSize=MMS_MAX_CHUNK_SIZE;
				}
				else
				{
					readSize=totalFileSize-currLen;
				}	 
				if(MSF_FILE_READ(filehandle,buffer,readSize)!=readSize)
				{					
					MMS_FREE(buffer);
					MSF_FILE_CLOSE(filehandle);
					return FALSE;
				}
				else
				{
					int i; 
					for(i=0;i<readSize;i++)
						sum+=*(buffer+i);
				}
        		       currLen+=readSize; 				
			}
		}
		MMS_FREE(buffer);
		MSF_FILE_CLOSE(filehandle);
		*checksum=sum;
		return TRUE;
	} 
} 
#ifdef MMS_SUPPORT
#ifdef MMS_FILE_PROTECT_SUPPORT
static MSF_BOOL isValidMmsIndexFile()
{
	int i;
	int bytesInBuffer=0;	
	int fileHandle=-1;
	Mmtlist *buffer;
	char filepath[100];
	
	bytesInBuffer = (sizeof(Mmtlist) + (sizeof(MmsMessageFolderInfo)* MMS_MAX_NO_OF_MSG)); 
    	buffer = (Mmtlist*)MSF_MEM_ALLOC(MSF_MODID_MSM,bytesInBuffer);
			
	for(i=0;i<3;i++)
	{
		fileHandle=-1;
		memset(filepath,0x00,100);
		if(i==0)	
			sprintf(filepath,"%s",MMS_MMT_FILE);		
		else if(i==1)	
			sprintf(filepath,"%s",MMS_MMT_TMP_FILE);
		else
			sprintf(filepath,"%s",MMS_MMT_BACKUP_FILE);

		if(MSF_FILE_GETSIZE(filepath)==bytesInBuffer)
		{					
			fileHandle=MSF_FILE_OPEN(MSF_MODID_MSM,filepath,HDI_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING,0);
			if(fileHandle>0 && MSF_FILE_READ(fileHandle,buffer,bytesInBuffer)==bytesInBuffer)
			{
				if(buffer->checkSum==getCheckSum((unsigned char*)&buffer->nextFreeMsgId,bytesInBuffer-sizeof(MSF_INT32),256))
				{
					MSF_MEM_FREE(MSF_MODID_MSM,buffer);
					MSF_FILE_CLOSE(fileHandle);	
					return TRUE;
				}
			}
			if(fileHandle>0)
				MSF_FILE_CLOSE(fileHandle);				
		}
	}
	MSF_MEM_FREE(MSF_MODID_MSM,buffer);
	if(fileHandle>0)
		MSF_FILE_CLOSE(fileHandle);				

	return FALSE;	
}
#endif /*MMS_FILE_PROTECT_SUPPORT*/
#endif /*MMS_SUPPORT*/
MmsResult translateFileError(int fileError)
{
    MmsResult ret = MMS_RESULT_ERROR;
	
    switch (fileError)
	{
    case MSF_FILE_OK :
        ret = MMS_RESULT_OK;
        break;
    case MSF_FILE_ERROR_ACCESS : 
        ret = MMS_RESULT_ERROR;
        break;
    case MSF_FILE_ERROR_DELAYED :
        ret = MMS_RESULT_DELAYED;
        break;
    case MSF_FILE_ERROR_PATH :
        ret = MMS_RESULT_FILE_NOT_FOUND;
        break;
    case MSF_FILE_ERROR_INVALID : 
        ret = MMS_RESULT_ERROR;
        break;
    case MSF_FILE_ERROR_SIZE :
        ret = MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
        break;
    case MSF_FILE_ERROR_FULL :
        ret = MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
        break;
    case MSF_FILE_ERROR_EOF :
        ret = MMS_RESULT_EOF;
        break;
    default :
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, 
            MMS_AAPP_F04A54693E8FD2C3774261A6897AE790, "%s(%d): Unknown fileError %d\n", __FILE__, __LINE__,
            fileError));
        break;
			}
	
    return ret;
		}


MmsResult genChkSumFile(MmsMsgId msgId)
{
	mmsCacheInfo msgInfo;
	char filepath[100];
	MmsFileType fileType;

	/* For parsing of subject and address of mms message */
	MmsAddress     fromAddress;	
	MmsMsgHandle msgHandle=NULL;
    	MmsTransactionHandle transaction=NULL;
    	MmsGetHeader header;
    	MmsResult ret = MMS_RESULT_ERROR;
    	MmsNotification notiheader;
    	MmsHeaderValue headerValue;
    	MmsEncodedText enSubject;
	MSF_BOOL freeHeader=FALSE;
    	MSF_BOOL freeBuffer=FALSE;
    	char *addr=NULL;
    	char *buffer=NULL;
    	int  bufSize=0;        
	enSubject.charset=MMS_UNKNOWN_CHARSET;
	enSubject.text=NULL;        
	fromAddress.address=NULL;
	fromAddress.addrType=MMS_UNSUPPORTED;	
	fromAddress.name.text=NULL;	
	memset(&msgInfo,0x00,sizeof(mmsCacheInfo));

	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_05984558FD66ADF9F7B33E0C0BF4DFF6, "Start to generate a chksum file with msgId:%x.%c\n",msgId,'c'));
	fileType=fldrGetFileSuffix(msgId);

	if(fileType==MMS_SUFFIX_ERROR)
	{
		return MMS_RESULT_ERROR;
	}
	/* Generate the checksum of mms message information file, ex:".i" */
	if(fileType==MMS_SUFFIX_MSG||fileType==MMS_SUFFIX_SEND_REQ||fileType==MMS_SUFFIX_TEMPLATE)
	{
		memset(filepath,0x00,100);
		sprintf(filepath,"%s%lx.%c",MMS_FOLDER,msgId,'i'); 
		if(!getCheckSumFromMessageFile(filepath,msgId,&msgInfo.info_chksum,FALSE))
		{
			MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_B7E686B2DC0075F5898779CB6A8134A0, "Fail to gen *.i chksum"));
			return MMS_RESULT_ERROR;
		}		
	}

	/* Generate the checksum of mms message file, ex: ".m", ".s", ".n",".q",".d" */
	fileType=fldrGetFileSuffix(msgId);
	if(fileType==MMS_SUFFIX_DELIVERYREPORT||fileType==MMS_SUFFIX_READREPORT||
		fileType==MMS_SUFFIX_NOTIFICATION||fileType==MMS_SUFFIX_IMMEDIATE)
	{
		memset(filepath,0x00,100);
		sprintf(filepath,"%s%lx.%c",MMS_FOLDER,msgId,fileType); 	
		if(!getCheckSumFromMessageFile(filepath,msgId,&msgInfo.msg_chksum,FALSE))
		{
			MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_2E2DB89646CC2774B560D48D89C6C43B, "Fail to gen msg chksum"));
			return MMS_RESULT_ERROR;
		}
	}
	else
	{
		memset(filepath,0x00,100);
		sprintf(filepath,"%s%lx.%c",MMS_FOLDER,msgId,fileType); 	
		if(!getCheckSumFromMessageFile(filepath,msgId,&msgInfo.msg_chksum,TRUE))
		{
			MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_2E2DB89646CC2774B560D48D89C6C43B, "Fail to gen msg chksum"));
			return MMS_RESULT_ERROR;
		}
	}


	/* Parse the subject and address from mms message */	
    	switch(fileType)
	{			
		case MMS_SUFFIX_DELIVERYREPORT:				
		case MMS_SUFFIX_READREPORT:
			loadMmsDataToBuffer(MSF_MODID_MMS,msgId,(MSF_UINT8)fileType,&buffer,&bufSize);        
			if(!buffer)
				break;					
			freeBuffer=TRUE;		
			if (mmsPduGet( buffer, bufSize, MMS_SUBJECT, &headerValue))
			{
				MSF_UINT32 notUsed = 0;
				int size=0;
				size = (MSF_UINT32)((unsigned char *)buffer - (unsigned char *)headerValue.subject) + 
					bufSize;
				if (parseEncodedStringValue(MSF_MODID_MMS, headerValue.subject, size, &notUsed, 
					&enSubject) != FALSE)
        			{
					setSubAddr((char **)&msgInfo.subject,&msgInfo.subjectLen, enSubject.text,250);
				}
			}
			if (parseFromAddress( MSF_MODID_MMS, (unsigned char *)buffer, bufSize, 
				&fromAddress) != FALSE)
			{
				setSubAddr((char **)&msgInfo.address,&msgInfo.addressLen, fromAddress.address,250);	
				freeMmsAddress(MSF_MODID_MMS,&fromAddress);
			}
			break;
	
		case MMS_SUFFIX_SEND_REQ:
		case MMS_SUFFIX_TEMPLATE:
		case MMS_SUFFIX_MSG:
		case MMS_SUFFIX_NOTIFICATION:
		case MMS_SUFFIX_IMMEDIATE:
			memset(&header,0x00,sizeof(MmsGetHeader));
			memset(&notiheader,0x00,sizeof(notiheader));
			MMS_FILE_OPEN_BLOCK_FLAG=TRUE;
			if(MMSlib_messageOpen(MSF_MODID_MMS,msgId,fileType, &msgHandle)!=MMS_RESULT_OK)
			{
				MMS_FILE_OPEN_BLOCK_FLAG=FALSE;
				if(msgHandle)
				{
					MMSlib_messageClose(MSF_MODID_MMS,&msgHandle);
					msgHandle=NULL;
				}
				break;
			}
			else if(MMSlib_transactionOpen(MSF_MODID_MMS,&transaction)!=MMS_RESULT_OK)
			{
				MMS_FILE_OPEN_BLOCK_FLAG=FALSE;
				if(msgHandle)
				{
					MMSlib_messageClose(MSF_MODID_MMS,&msgHandle);
					msgHandle=NULL;
				}
				if(transaction)
				{
					MMSlib_transactionClose(MSF_MODID_MMS,&transaction);
					transaction=NULL;
				}			
				break;
			}
			MMS_FILE_OPEN_BLOCK_FLAG=FALSE;
			if(fileType==MMS_SUFFIX_NOTIFICATION||fileType==MMS_SUFFIX_IMMEDIATE)
			{
				if((ret=MMSlib_getNotification(MSF_MODID_MMS, &notiheader, &msgHandle, &transaction))==MMS_RESULT_OK)        			
					freeHeader=TRUE;
			}
			else
			{
				if((ret=MMSlib_getMessageHeader(MSF_MODID_MMS, &header, &msgHandle, &transaction))==MMS_RESULT_OK)        			
					freeHeader=TRUE;
			}
			if(msgHandle)
			{
				MMSlib_messageClose(MSF_MODID_MMS,&msgHandle);
			}
			if(transaction)
			{
				MMSlib_transactionClose(MSF_MODID_MMS,&transaction);
			}
			msgHandle = NULL;
			transaction = NULL;
			if(freeHeader && header.subject.text)
			{
				setSubAddr((char **)&msgInfo.subject,&msgInfo.subjectLen,header.subject.text,250);
			}
			if(freeHeader && notiheader.subject.text)
			{
				setSubAddr((char **)&msgInfo.subject,&msgInfo.subjectLen,notiheader.subject.text,250);				
			}
			/* hint = from */
			if(fileType != MMS_SUFFIX_SEND_REQ && fileType!=MMS_SUFFIX_TEMPLATE)
			{
				if(fileType==MMS_SUFFIX_NOTIFICATION||fileType==MMS_SUFFIX_IMMEDIATE)
				{
					setSubAddr((char **)&msgInfo.address,&msgInfo.addressLen,notiheader.from.address,250);						
				}
				else
				{				
					setSubAddr((char **)&msgInfo.address,&msgInfo.addressLen,header.from.address,250);											
				}			
			}		
			else
			{		
				if(header.to)
				{
					addr=header.to->current.address;
				}
				else if(header.cc)
				{
					addr=header.cc->current.address;
				}     
				else if(header.bcc)
				{
					addr=header.bcc->current.address;
				}
				if(addr)
				{
					setSubAddr((char **)&msgInfo.address,&msgInfo.addressLen,addr,250);											
				}  			
			}
			if(freeHeader)
			{	
				if(fileType==MMS_SUFFIX_NOTIFICATION||fileType==MMS_SUFFIX_IMMEDIATE)
					freeMmsNotification( MSF_MODID_MMS,&notiheader);
				else
					freeMmsGetHeader(MSF_MODID_MMS,&header);
			}
			if(freeBuffer)
				MSF_MEM_FREE(MSF_MODID_MMS,buffer);		
	}
	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_204FFF3F6F26D8595745C1AAE4C38559, "Generate msg msgId:%x information, subject:%s\n",msgId,msgInfo.subject));

	/* Write checksum, subject and address to file. */	
	if ( MSF_FILE_GETSIZE_DIR( MMS_SYS_FOLDER) == MSF_FILE_ERROR_PATH)
	{
        	MSF_FILE_MKDIR(MMS_SYS_FOLDER);
    	}   
	memset(filepath,0x00,100);
	sprintf(filepath,"%s%lx.%c",MMS_SYS_FOLDER,msgId,MMS_SUFFIX_CHKSUM);
	MSF_FILE_REMOVE(filepath);
	{
		int fileHandle=-1;
		fileHandle=MSF_FILE_OPEN(MSF_MODID_MMS,filepath,HDI_FILE_SET_WRONLY|HDI_FILE_SET_CREATE| HDI_FILE_SET_CUSTOM_BLOCKING,(12+msgInfo.subjectLen+msgInfo.addressLen));
		if(fileHandle<0)
		{
			if(msgInfo.subjectLen>0)
			{
				MSF_MEM_FREE(MSF_MODID_MMS,msgInfo.subject);
			}
			if(msgInfo.addressLen>0)
			{
				MSF_MEM_FREE(MSF_MODID_MMS,msgInfo.address);
			}
			return translateFileError(fileHandle);
		}
		else
		{
			char errflag=0;
			if((MSF_FILE_WRITE(fileHandle,&msgInfo,MMS_MIN_CHECKSUM_FILE_SIZE)!=MMS_MIN_CHECKSUM_FILE_SIZE)||
			   ((msgInfo.subjectLen>0)&&(MSF_FILE_WRITE(fileHandle,msgInfo.subject,msgInfo.subjectLen)!=msgInfo.subjectLen))||
			   ((msgInfo.addressLen>0)&&(MSF_FILE_WRITE(fileHandle,msgInfo.address,msgInfo.addressLen)!=msgInfo.addressLen)))
			{
				MSF_FILE_CLOSE(fileHandle);
				errflag=1;	
			}
			MSF_FILE_CLOSE(fileHandle);
			if(msgInfo.subjectLen>0)
			{
				MSF_MEM_FREE(MSF_MODID_MMS,msgInfo.subject);
			}
			if(msgInfo.addressLen>0)
			{
				MSF_MEM_FREE(MSF_MODID_MMS,msgInfo.address);
			}
			if(errflag==1)
			{
				MSF_FILE_REMOVE(filepath);
				return MMS_RESULT_FILE_WRITE_ERROR;
			}
			MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_8734F91BCBA200E79357FCFCDD4FFFA9, "Generate msg msgId:%x chksum file.\n",msgId));
		}
	}				
	return MMS_RESULT_OK;
}

static MSF_BOOL getChkSumFilesInfo()
{
	int i=0,j=0;
	int type = 0;
	int size = 0;   
	int dirHandle=-1;
	folderFiles=NULL;
	noOfFiles=0;

	if(MSF_FILE_GETSIZE_DIR(MMS_SYS_FOLDER) == MSF_FILE_ERROR_PATH)     
    		MSF_FILE_MKDIR( MMS_SYS_FOLDER);
	if(folderFiles)	
		MMS_FREE(folderFiles);	
	noOfFiles =  MSF_FILE_GETSIZE_DIR (MMS_SYS_FOLDER);
	if(noOfFiles<=0)
		return FALSE;
	folderFiles = (mmsFileInFolder*)MMS_CALLOC(sizeof(mmsFileInFolder) * (unsigned int)noOfFiles);

	if(!folderFiles)	
		return FALSE;
	j=0;
   for (i = 0; i < noOfFiles; i++)
   {
     	if ((MSF_FILE_READ_DIR_SEQ(MMS_SYS_FOLDER, i, folderFiles[j].fileName,
           		MMS_FILE_LEN, &type, &size,&dirHandle) == MSF_FILE_OK) &&
           		(msf_cmmn_strcmp_nc(folderFiles[j].fileName, "indicator") != 0)&&
           		(msf_cmmn_strcmp_nc(folderFiles[j].fileName, "mms.cn") != 0)&&
           		(msf_cmmn_strcmp_nc(folderFiles[j].fileName, "mms.bk") != 0)&&
           		(msf_cmmn_strcmp_nc(folderFiles[j].fileName, "mms.tp") != 0)&&
           		(msf_cmmn_strcmp_nc(folderFiles[j].fileName, "mmc_jsr.cn") != 0)&&
           		(msf_cmmn_strcmp_nc(folderFiles[j].fileName, "index.tmp") != 0) &&
           		(msf_cmmn_strcmp_nc(folderFiles[j].fileName, "mms_cache_push.txt") != 0) &&
           		type == HDI_FILE_DIRTYPE)
     	{        
			j++;   
		}
	}
    	MSF_FILE_READ_DIR_SEQ_CLOSE(&dirHandle);
    	noOfFiles = j; 	
	for (i = 0; i < noOfFiles; i++)    
        	folderFiles[i].msgId = fileName2MsgId(folderFiles[i].fileName);                       
	return TRUE;
	
}

/*************************************************************
 FUNCTION                                                            
	syncChkSumFile

 DESCRIPTION                                                           
   Remove unnecessary checksum files.
	
 PARAMETERS
	Non

 RETURNS
   None

 GLOBALS AFFECTED
   All unnecessary checksum files are removed.
**************************************************************/
void syncChkSumFile()
{
	int i;
	char filepath[100];
	noOfFiles=0;
	MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MMS, MMS_AAPP_7D3096812F7CD2F9A1EA4B8674252BDC, "Start to sync chksum files and MMS folder.\n"));
	if(getChkSumFilesInfo())
	{
		for (i = 0; i < noOfFiles; i++)    
		{
			if(!checkMsgId(folderFiles[i].msgId))
			{
				memset(filepath,0x00,100);
				sprintf(filepath,"%s%s",MMS_SYS_FOLDER,folderFiles[i].fileName);
				MSF_FILE_REMOVE(filepath);
				MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_AEAC874A696A0D61FF055DD2CE79539B, "Remove unnecessary chksum file: %s\n",folderFiles[i].fileName));
			}
		}
		MMS_FREE(folderFiles);
		folderFiles=NULL;
		noOfFiles=0;	
	}
	MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MMS, MMS_AAPP_3BA5EAAA3691D373A07B735964330C22, "Finish to sync chksum files and MMS folder.\n"));
}
static void setSubAddr(char** output_str,MSF_UINT16* output_str_len, char *input_str, int MaxBufLen)
{		
	MSF_UINT16 len=0;
	if(input_str)
	{
		*output_str=NULL;
		if(strlen(input_str)<MaxBufLen-1)
		{
			len=strlen(input_str)+1;			
		}
		else
		{		
			len=MaxBufLen;
		}
		*output_str=MSF_MEM_ALLOC(MSF_MODID_MMS,len);
		if(*output_str)
		{
			memset(*output_str,0x00,len);
			memcpy(*output_str,input_str,len-1);
			*output_str_len=len;
		}
		else
		{
			*output_str_len=0;
		}
	}
}



void delChkSumFile(MmsMsgId msgId)
{
	char filepath[100];	
	memset(filepath,0x00,100);
	sprintf(filepath,"%s%lx.%c",MMS_SYS_FOLDER,msgId,MMS_SUFFIX_CHKSUM);
	MSF_FILE_REMOVE(filepath);
	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_5AA82A0D9D71CAA6FC93F944667A0654, "Remove unnecessary chksum file: %x.%c\n",msgId,MMS_SUFFIX_CHKSUM));
}

	
MSF_BOOL getMmsMsgSubAddr(MSF_UINT8 modId,MmsMsgId msgId, char** subject, char** address,int MaxBufSize)
{	
	char filepath[100];	
	int fileHandle=-1;
	MSF_UINT16 subjectLen=0;
	MSF_UINT16 addressLen=0;
	MmsFileType fileType;
	*subject=NULL;
	*address=NULL;
		
	fileType=fldrGetFileSuffix(msgId);
		
	memset(filepath,0x00,100);
	sprintf(filepath,"%s%lx.%c",MMS_SYS_FOLDER,msgId,MMS_SUFFIX_CHKSUM);
	fileHandle=MSF_FILE_OPEN(modId,filepath,HDI_FILE_SET_RDONLY| HDI_FILE_SET_CUSTOM_BLOCKING,0);
	if(fileHandle<0)
	{
		if(fileHandle==MSF_FILE_ERROR_PATH)
		{
			/* Automatically generate checksum file of mms immediate notification and mms templates*/
			if(fileType==MMS_SUFFIX_IMMEDIATE|| fileType==MMS_SUFFIX_TEMPLATE)
			{
				if(fileType==MMS_SUFFIX_TEMPLATE)
				{
					MSF_FILE_REMOVE("\\mms_sys\\chkbuf.tmp");
				}
				if(genChkSumFile(msgId)!=MMS_RESULT_OK)
				{
					return FALSE;
				}
				else
				{
					fileHandle=MSF_FILE_OPEN(modId,filepath,HDI_FILE_SET_RDONLY| HDI_FILE_SET_CUSTOM_BLOCKING,0);
					if(fileHandle<0)
						return FALSE;
				}
			}
		}	
	}	
	if(MSF_FILE_GETSIZE(filepath)<MMS_MIN_CHECKSUM_FILE_SIZE)
	{
		/* Chksum file corrupts  */
		MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_F32A91A261F6DB5CE83B1A8A18372F1E, "The chksum file is corrupted: %x.%c\n",msgId,MMS_SUFFIX_CHKSUM));
		if(fileHandle>=0)
			MSF_FILE_CLOSE(fileHandle);
		return FALSE;
		
	}
	
	MSF_FILE_SEEK(fileHandle, 8, MSF_FILE_SEEK_SET);
	MSF_FILE_READ(fileHandle,&subjectLen,2);
	MSF_FILE_READ(fileHandle,&addressLen,2);
	
	if((subjectLen+addressLen+MMS_MIN_CHECKSUM_FILE_SIZE)!=MSF_FILE_GETSIZE(filepath))
	{
		/* Chksum file corrupts  */
        	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_3FB7875DB1B8B59B51687A66A5F4228F, "%s(%d): The chksum file is corrupted: %x.%c\n",__FILE__,__LINE__,msgId,MMS_SUFFIX_CHKSUM));
        	MSF_FILE_CLOSE(fileHandle);
		return FALSE;
	}
	
	if(subjectLen>0)
	{
		if(subjectLen>MaxBufSize)
			subjectLen=MaxBufSize;
		*subject=MSF_MEM_ALLOC(modId,subjectLen);
		if(!*subject)
		{
			MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_B5048D3ADC1AA78E6E8CB24DF63BC30B, "%s(%d): The memory is exhausted. MsgId:%x, Need Size: %d\n",__FILE__,__LINE__,msgId,subjectLen));
			MSF_FILE_CLOSE(fileHandle);
			return FALSE;
		}
		memset(*subject,0x00,subjectLen);
		if(MSF_FILE_READ(fileHandle,*subject,subjectLen)!=subjectLen)
		{
			ASSERT(0);
		}
	}
	
	if(addressLen>0)
	{
		if(addressLen>MaxBufSize)
			addressLen=MaxBufSize;
		*address=MSF_MEM_ALLOC(modId,addressLen);
		if(!*address)
		{					
			MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_B5048D3ADC1AA78E6E8CB24DF63BC30B, "%s(%d): The memory is exhausted. MsgId:%x, Need Size: %d\n",__FILE__,__LINE__,msgId,addressLen));
			MSF_FILE_CLOSE(fileHandle);
			return FALSE;
		}
		memset(*address,0x00,addressLen);
		if(MSF_FILE_READ(fileHandle,*address,addressLen)!=addressLen)
		{
			ASSERT(0);
		}
	}
	
	MSF_FILE_CLOSE(fileHandle);
	return TRUE;
}

MSF_BOOL  isValidMmsMSg(MmsMsgId msgId)
{
	char filepath[100];	
	int fileHandle=-1;
	MmsFileType fileType;
	MSF_UINT32 info_chksum; 		
	MSF_UINT32 msg_chksum;	
	MSF_UINT32 info_chksum_from_file=0; 		
	MSF_UINT32 msg_chksum_from_file=0;	
	MSF_BOOL isValidMsg=FALSE;
	fileType=fldrGetFileSuffix(msgId);

	memset(filepath,0x00,100);
	sprintf(filepath,"%s%lx.%c",MMS_SYS_FOLDER,msgId,MMS_SUFFIX_CHKSUM);
	fileHandle=MSF_FILE_OPEN(MSF_MODID_MMS,filepath,HDI_FILE_SET_RDONLY| HDI_FILE_SET_CUSTOM_BLOCKING,0);
	if(fileHandle<0 || MSF_FILE_GETSIZE(filepath)<MMS_MIN_CHECKSUM_FILE_SIZE)
	{
		/* Add message log here */
		MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_34ABB2D45C8EA485AC46138846F90E64, "%s(%d): The chksum file is corrupted: %x.%c, file_size:%d\n",__FILE__,__LINE__,msgId,MMS_SUFFIX_CHKSUM,MSF_FILE_GETSIZE(filepath)));
		MSF_FILE_REMOVE(filepath);
		if(fileHandle>=0)
		{
			MSF_FILE_CLOSE(fileHandle);
		}
			
		return FALSE;
	}
	MSF_FILE_READ(fileHandle,&info_chksum,4);
	MSF_FILE_READ(fileHandle,&msg_chksum,4);
	MSF_FILE_CLOSE(fileHandle);

	/* Check the chksum of information file */
	if(fileType==MMS_SUFFIX_SEND_REQ|| fileType==MMS_SUFFIX_TEMPLATE||fileType==MMS_SUFFIX_MSG)
	{
		memset(filepath,0x00,100);
		sprintf(filepath,"%s%lx.%c",MMS_FOLDER,msgId,'i'); 
		isValidMsg=getCheckSumFromMessageFile(filepath,msgId,&info_chksum_from_file,FALSE);
		if(!isValidMsg||info_chksum!=info_chksum_from_file)
		{
			MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_0AB6C7D3097F08C8195D15E73AF1DD7F, "%s(%d): The information file is corrupted: %x.%c\n",__FILE__,__LINE__,msgId,'i'));
			return FALSE;
		}
	}

	/* Generate the checksum of mms message file, ex: ".m", ".s", ".n",".q",".d" */	
	if(fileType==MMS_SUFFIX_DELIVERYREPORT||fileType==MMS_SUFFIX_READREPORT||
		fileType==MMS_SUFFIX_NOTIFICATION||fileType==MMS_SUFFIX_IMMEDIATE)
	{
		memset(filepath,0x00,100);
		sprintf(filepath,"%s%lx.%c",MMS_FOLDER,msgId,fileType); 	
		isValidMsg=getCheckSumFromMessageFile(filepath,msgId,&msg_chksum_from_file,FALSE);
	}
	else
	{
	memset(filepath,0x00,100);
	sprintf(filepath,"%s%lx.%c",MMS_FOLDER,msgId,fileType); 	
		isValidMsg=getCheckSumFromMessageFile(filepath,msgId,&msg_chksum_from_file,TRUE);
	}
	if(!isValidMsg||msg_chksum!=msg_chksum_from_file)
	{
		MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_74DDADE51F0B19F3BF1C6B73EA0C96CC, "%s(%d): The mms message file is corrupted: %x.%c\n",__FILE__,__LINE__,msgId,fileType));
		return FALSE;
	}
	else
	{
		MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_A00CD2BB18C4E3B196CE34F07660C6CA, "%s(%d): The mms message is valid: %x.%c\n",__FILE__,__LINE__,msgId,MMS_SUFFIX_CHKSUM));
		return TRUE;
	}
	
}
#endif



/*****************************************************************************************
*                  
*
*                        Send Request Cache Mechanism 
*
*   (This scheme can provide the corresponding subject of the receivied delivery report)
*
*
*****************************************************************************************/
#define WAP_MMS_MAX_CACHE_SEND_REQ_NUM 10
#define WAP_MMS_MAX_CACHE_SEND_REQ_FILE_PATH "\\mms_sys\\cache_push.txt"
#define WAP_MMS_MAX_CACHED_SERVER_MSGID_LEN 80
#define WAP_MMS_MAX_CACHED_SUBJECT_LEN 80

typedef struct{
    MSF_UINT32 date;
	char serverMsgId[WAP_MMS_MAX_CACHED_SERVER_MSGID_LEN];
	char subject[WAP_MMS_MAX_CACHED_SUBJECT_LEN];
}MmsSendReqInfo;

MmsSendReqInfo *g_MmsSendReqInfo_list_p = NULL;

static MmsSendReqInfo* mmsRestoreSerMsgIdFromFile()
{
    MSF_INT32 fileHandle = -1;
    MSF_UINT32 bufLen = WAP_MMS_MAX_CACHE_SEND_REQ_NUM*(sizeof(MmsSendReqInfo));

    g_MmsSendReqInfo_list_p = (MmsSendReqInfo*)MMS_ALLOC(bufLen);
    if (g_MmsSendReqInfo_list_p == NULL)
    {
        return NULL;
    }
    memset((char*)g_MmsSendReqInfo_list_p, 0x00, bufLen);
    
    if (MSF_FILE_GETSIZE(WAP_MMS_MAX_CACHE_SEND_REQ_FILE_PATH) != bufLen)
    {
        return g_MmsSendReqInfo_list_p;
    }
    else
    {
        fileHandle = MSF_FILE_OPEN( MSF_MODID_MMS, WAP_MMS_MAX_CACHE_SEND_REQ_FILE_PATH,MSF_FILE_SET_RDONLY, 0);
        if (fileHandle >= 0)
        {
            if (MSF_FILE_READ(fileHandle,(char*)g_MmsSendReqInfo_list_p,bufLen) == bufLen)
            {
                MSF_FILE_CLOSE(fileHandle);
                return g_MmsSendReqInfo_list_p;
            }
            else
            {
                memset((char*)g_MmsSendReqInfo_list_p, 0x00, bufLen);
                MSF_FILE_CLOSE(fileHandle);                
                return g_MmsSendReqInfo_list_p;
            }
        }
        return g_MmsSendReqInfo_list_p;        
    }
}

static void mmsWriteSerMsgIdToFile()
{
    MSF_INT32 fileHandle = -1;
    MSF_UINT32 bufLen = WAP_MMS_MAX_CACHE_SEND_REQ_NUM*(sizeof(MmsSendReqInfo));

    if (g_MmsSendReqInfo_list_p == NULL)
    {
        return;
    }
    MSF_FILE_REMOVE(WAP_MMS_MAX_CACHE_SEND_REQ_FILE_PATH);

    fileHandle = MSF_FILE_OPEN( MSF_MODID_MMS, WAP_MMS_MAX_CACHE_SEND_REQ_FILE_PATH,MSF_FILE_SET_WRONLY|MSF_FILE_SET_CREATE, 0);
    if (fileHandle >= 0)
    {
        if (MSF_FILE_WRITE(fileHandle,(char*)g_MmsSendReqInfo_list_p,bufLen) != bufLen)
        {
            MSF_FILE_CLOSE(fileHandle); 
            MSF_FILE_REMOVE(WAP_MMS_MAX_CACHE_SEND_REQ_FILE_PATH);
        }
        else
        {
            MSF_FILE_CLOSE(fileHandle); 
        }            
    }
}
/************************************************************************
* FUNCTION                                                            
*	mmsAddServerMsgIdToDB
*
* DESCRIPTION                                                           
*	It is used to cache server message id of m-send.conf and corresponding subject              
* PARAMETERS
*   serMsgId
*   subject
* RETURNS
*   NONE
* GLOBALS AFFECTED
* 	None
*************************************************************************/  
void mmsAddServerMsgIdToDB(char *serMsgId, char *subject)
{		
    MSF_UINT32 i = 0;
    MSF_UINT32 candidate = 0;
    MSF_UINT32 min_date = 0xFFFFFFFF;

    if (serMsgId == NULL || subject == NULL)
    {
        return;
    }
    if (g_MmsSendReqInfo_list_p == NULL)
    {
        g_MmsSendReqInfo_list_p = mmsRestoreSerMsgIdFromFile();
    }    
    for (i = 0; i < WAP_MMS_MAX_CACHE_SEND_REQ_NUM; i++)
    {
        if (g_MmsSendReqInfo_list_p[i].date < min_date)
        {
            /*Choose oldest msg entry*/
            candidate = i;
            min_date = g_MmsSendReqInfo_list_p[i].date;
        }
    }    
    memset(&g_MmsSendReqInfo_list_p[candidate], 0x00, sizeof(MmsSendReqInfo));
    if (strlen(serMsgId) >= WAP_MMS_MAX_CACHED_SERVER_MSGID_LEN)
    {
        strncpy(g_MmsSendReqInfo_list_p[candidate].serverMsgId, serMsgId, WAP_MMS_MAX_CACHED_SERVER_MSGID_LEN - 1);
    }
    else
    {
        strcpy(g_MmsSendReqInfo_list_p[candidate].serverMsgId, serMsgId);
    }
    if (strlen(serMsgId) >= WAP_MMS_MAX_CACHED_SUBJECT_LEN)
    {
        strncpy(g_MmsSendReqInfo_list_p[candidate].subject, subject, WAP_MMS_MAX_CACHED_SUBJECT_LEN - 1);
    }
    else
    {
        strcpy(g_MmsSendReqInfo_list_p[candidate].subject, subject);
    }
    g_MmsSendReqInfo_list_p[candidate].date = MSF_TIME_GET_CURRENT();
    mmsWriteSerMsgIdToFile();
}

/************************************************************************
* FUNCTION                                                            
*	MmsGetSubjectFromSerMsgId
*
* DESCRIPTION                                                           
*	It is used to find subject corresponding to the server message id of m-send.conf
* PARAMETERS
*   serMsgId
* RETURNS
*   char *subject
* GLOBALS AFFECTED
* 	None
*************************************************************************/ 
char *MmsGetSubjectFromSerMsgId(char* serverMsgId)
{
    MSF_UINT32 i = 0;

    if (g_MmsSendReqInfo_list_p == NULL)
    {
        g_MmsSendReqInfo_list_p = mmsRestoreSerMsgIdFromFile();
    }

    for (i = 0; i < WAP_MMS_MAX_CACHE_SEND_REQ_NUM; i++)
    {
        if (g_MmsSendReqInfo_list_p[i].date > 0)
        {
            if(strncmp(g_MmsSendReqInfo_list_p[i].serverMsgId,
                serverMsgId,
                strlen(g_MmsSendReqInfo_list_p[i].serverMsgId)) == 0)
            {
                return g_MmsSendReqInfo_list_p[i].subject;
            }
        }
    }
    return NULL;
}




#ifndef __MTK_TARGET__
void dumpAllMmsFilesToWIN32Folder()
{
	int i=0;
	int fileHandle=-1;
	char *buff=NULL;
	char fn[100];
	char *path="d:\\mms_win32\\";
	FILE* fp=NULL;
	getMMSFolderInfo();
    
    for(i=0;i<noOfFiles;i++)
	{
		buff=NULL;
		fp=NULL;
		buff = (char *)malloc(folderFiles[i].size);
		if(buff!=NULL)
		{			
			memset(fn,0x00,100);
			sprintf(fn,"%s%s",MMS_FOLDER,folderFiles[i].fileName);
			fileHandle = MSF_FILE_OPEN( MSF_MODID_MMS,fn,MSF_FILE_SET_RDONLY, 0);										   
			if(fileHandle>=0)
			{
				if(MSF_FILE_READ(fileHandle,buff,folderFiles[i].size)==(MSF_INT32)folderFiles[i].size)
				{
					memset(fn,0x00,100);
					sprintf(fn, "%s%s",path,folderFiles[i].fileName);	
					remove(fn);
					fp=fopen(fn,"wb");
					fseek(fp,0,SEEK_SET);
					fwrite(buff,folderFiles[i].size,1,fp);
					fclose(fp);				
				}
			}
			MSF_FILE_CLOSE(fileHandle);
			free((void *)buff);
		}
	}      
	if(folderFiles)
	{
		MMS_FREE(folderFiles);
		folderFiles=NULL;
	}
		

}
#endif



#if MMS_TEMPLATES_DEMO_SUPPORT

long image_read_length(unsigned char *image)
{
	int rvalue = 0;
	
	if(image==NULL) 
		return (0);
	else
	{	rvalue|=(long)(image[2]);
		rvalue|=(long)((long)image[3]<<8);
		rvalue|=(long)((long)image[4]<<16);
		rvalue|=(long)((long)image[5]<<24);
		return((long)rvalue);
	}
}



int generateSMIL(unsigned char *strBuffer, MSF_BOOL isForEmptyMms)
{
	MsfDeviceProperties deviceProperties;
    /* Predefined Mms header */
	const unsigned char mmsHeader[]={//32
		0x84,0x1D,0xB3,0x89,0x61,0x70,0x70,0x6C,0x69,0x63,0x61,0x74,0x69,0x6F,0x6E,
        0x2F,0x73,0x6D,0x69,0x6C,0x00,0x8A,0x3C,0x73,0x2E,0x73,0x6D,0x69,0x6C,0x3E,
		0x00,0x01
	};
#ifdef MMS_USE_NAME_PARMS
	/* Predefined SMIL header */
	const unsigned char SMIL_Header[]={//47
		0x1B, 0x61, 0x70, 0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x2F, 0x73, 0x6D,
		0x69, 0x6C, 0x00, 0x85, 0x73, 0x2E, 0x73, 0x6D, 0x69, 0x6C, 0x00, 0x81, 0xEA, 0x8E, 0x73, 
		0x2E, 0x73, 0x6D, 0x69, 0x6C, 0x00, 0xC0, 0x22, 0x3C, 0x73, 0x2E, 0x73, 0x6D, 0x69, 0x6C, 
		0x3E, 0x00
	};
#else
	/* Predefined SMIL header */
	const unsigned char SMIL_Header[]={//47
		0x1B, 0x61, 0x70, 0x70, 0x6C, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6F, 0x6E, 0x2F, 0x73, 0x6D,
		0x69, 0x6C, 0x00, 0x86, 0x73, 0x2E, 0x73, 0x6D, 0x69, 0x6C, 0x00, 0x81, 0xEA, 0x8E, 0x73, 
		0x2E, 0x73, 0x6D, 0x69, 0x6C, 0x00, 0xC0, 0x22, 0x3C, 0x73, 0x2E, 0x73, 0x6D, 0x69, 0x6C, 
		0x3E, 0x00
	};     
#endif   
	const unsigned char SMIL_BODY1[]="<smil><head><layout><root-layout width=\"\0";
	const unsigned char SMIL_BODY2[]="\" height=\"\0";
	const unsigned char SMIL_BODY3[]="\"/><region id=\"Image\" width=\"100%\" height=\"50%\" left=\"0%\" top=\"50%\" /><region id=\"Text\" width=\"100%\" height=\"50%\" left=\"0%\" top=\"0%\" /></layout></head><body><par dur=\"9000ms\"><text src=\"ed9b3401.txt\" region=\"Text\" ><param name=\"foregroundcolor\" value=\"#000000\" /></text><img src=\"cid:1.gif\" region=\"Image\" /><audio src=\"cid:2.mid\" /></par></body></smil>\0";			
	const unsigned char SMIL_BODY4[]="\"/><region id=\"Text\" width=\"100%\" height=\"100%\"/></layout></head><body><par dur=\"\0";
	const unsigned char SMIL_BODY5[] = "000ms\"></par></body></smil>\0";
	unsigned char header_data_len[2]={0x83,0x17};
	int smilLen=457;
	int bytesInBuffer=0;
	
	if(isForEmptyMms)
	{	
		smilLen-=212;
		header_data_len[0]=0x81;
		if (meaGetConfig()->slideDuration >= 10)
		{
			smilLen++;
			header_data_len[1]=0x24;
			WAP_DBG_ASSERT(meaGetConfig()->slideDuration < 100);
		}
		else
		{
			header_data_len[1]=0x23;
		}
	}
	
	
	
	memset(strBuffer,0x00,mmsBufSize);	

	MSF_WIDGET_DEVICE_GET_PROPERTIES(&deviceProperties);  
	
	if(deviceProperties.displaySize.width>100)
    {
		header_data_len[1]+=1;
		smilLen+=1;
	}
	if(deviceProperties.displaySize.height>100)
    {
		header_data_len[1]+=1;
		smilLen+=1;
	}
	if(isForEmptyMms)
	{
		memcpy(strBuffer,mmsHeader,32);
		bytesInBuffer+=32;	
	}
	
	sprintf((char *)strBuffer+bytesInBuffer,"%c%c%c",0x2F,header_data_len[0],header_data_len[1]);
	bytesInBuffer+=3;
	memcpy(strBuffer+bytesInBuffer,SMIL_Header,47);
	bytesInBuffer+=47;
	if(!isForEmptyMms)
	{
		sprintf((char *)strBuffer+bytesInBuffer,"%s%d%s%d%s",SMIL_BODY1,deviceProperties.displaySize.width,SMIL_BODY2,deviceProperties.displaySize.height,SMIL_BODY3);
	}
	else
	{
		sprintf((char *)strBuffer+bytesInBuffer,"%s%d%s%d%s%d%s",SMIL_BODY1,deviceProperties.displaySize.width,SMIL_BODY2,deviceProperties.displaySize.height,SMIL_BODY4,meaGetConfig()->slideDuration, SMIL_BODY5);
	}
	return smilLen;
}

int generateMmsHeader(unsigned char *mediaBuf,unsigned short resId,char *subject)
{
	unsigned long transactionIdLen=0;
	char *trId=NULL;
	char *Ptr;
	char utf_used=0;
	char quote_used=0;
	int byetsInBuffer=0;
	unsigned char *mediaPtr;	
	unsigned char uintvar[7];
	int mediaSize=0;

	const unsigned char mmsHeader[]={//32
		0x84,0x1D,0xB3,0x89,0x61,0x70,0x70,0x6C,0x69,0x63,0x61,0x74,0x69,0x6F,0x6E,
        0x2F,0x73,0x6D,0x69,0x6C,0x00,0x8A,0x3C,0x73,0x2E,0x73,0x6D,0x69,0x6C,0x3E,
		0x00,0x04
	};
	
	Ptr=NULL;
	mediaPtr=NULL;
	memset(uintvar,0x00,7);
	memset(mediaBuf,0x00,mmsBufSize);		

	trId=generateMmsTransactionId( MSF_MODID_MSM,&transactionIdLen);
	Ptr=GetString(resId);
	if(!Ptr) return -1;
	mediaSize=widget_ucs2_length((kal_uint8*)Ptr)*2;
	mediaPtr=MSF_MEM_ALLOC(MSF_MODID_MSM,mediaSize+2);
	memset(mediaPtr,0x00,mediaSize+2);
	memcpy(mediaPtr,Ptr,mediaSize+1);
	mediaSize=widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)mediaPtr);
	Ptr = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM,mediaSize+1);
	widget_ucs2_to_utf8_string((kal_uint8*)Ptr,mediaSize+1,(kal_uint8*)mediaPtr);
	MSF_MEM_FREE(MSF_MODID_MSM,mediaPtr);
    	sprintf((char *)mediaBuf,"%c%c%c%c%c%s%c%c",0x8C,0x80,0x8D,0x90,0x98,trId,0x00,0x96);
	byetsInBuffer+=(6+transactionIdLen);
    	MSF_MEM_FREE(MSF_MODID_MSM,trId); 

	{
		int i;
		int j=strlen(Ptr);
		for(i=0;i<j;i++)
	        {
			if((unsigned short)*(Ptr+i)>0x7F)
	            {
				utf_used=1;
				if(i==0)
				{
					quote_used=1;
				}
				break;
        	    }
	        }
		if(utf_used)
		{
			if(quote_used)
			{
				memset(uintvar,0x00,7);
				cnvUint32ToValueLength(mediaSize+3,uintvar,7);
				sprintf((char *)mediaBuf+byetsInBuffer,"%s%c%c",uintvar,0xEA,0x7F);
				byetsInBuffer+=(strlen((char *)uintvar)+2);
			}
			else
			{
				memset(uintvar,0x00,7);
				cnvUint32ToValueLength(mediaSize+2,uintvar,7);
				sprintf((char *)mediaBuf+byetsInBuffer,"%s%c",uintvar,0xEA);
				byetsInBuffer+=(strlen((char *)uintvar)+1);
			}

		}
	}

	memcpy(mediaBuf+byetsInBuffer,Ptr,mediaSize+1);
	byetsInBuffer+=(mediaSize+1);
	memcpy(mediaBuf+byetsInBuffer,mmsHeader,32);
	byetsInBuffer+=32;	
	return byetsInBuffer;			
}

int generateMediaHeader(unsigned char *mediaBuf,MmsMediaType mediaType, unsigned short resId)
{
#ifdef MMS_USE_NAME_PARMS
	/* Predefined image header */
	const unsigned char image_header[]={//24 : header length
		0x85,0x31,0x2E,0x67,0x69,0x66,0x00,0x8E,0x31,0x2E,0x67,0x69,0x66,0x00,0xC0,0x22,0x3C,
		0x31,0x2E,0x67,0x69,0x66,0x3E,0x00
	};
	/* Predefined audio header */
	const unsigned char audio_header[]={//35 : header length
		0x12,0x61,0x75,0x64,0x69,0x6F,0x2F,0x6D,0x69,0x64,0x69,0x00,0x85,0x32,0x2E,0x6D,0x69,
		0x64,0x00,0x8E,0x32,0x2E,0x6D,0x69,0x64,0x00,0xC0,0x22,0x3C,0x32,0x2E,0x6D,0x69,0x64,
		0x3E,0x00
	};
	/* Predefined text header */
	const unsigned char text_header[]={//48  : header length (ed9b3401.txt)
		0x11,0x83,0x81,0xEA,0x85,0x65,0x64,0x39,0x62,0x33,0x34,0x30,0x31,0x2E,0x74,0x78,0x74,0x00,
		0x8E,0x65,0x64,0x39,0x62,0x33,0x34,0x30,0x31,0x2E,0x74,0x78,0x74,0x00,
		0xC0,0x22,0x3C,0x65,0x64,0x39,0x62,0x33,0x34,0x30,0x31,0x2E,0x74,0x78,0x74,0x3E,0x00
	};
#else
	/* Predefined image header */
	const unsigned char image_header[]={//24 : header length
		0x86,0x31,0x2E,0x67,0x69,0x66,0x00,0x8E,0x31,0x2E,0x67,0x69,0x66,0x00,0xC0,0x22,0x3C,
		0x31,0x2E,0x67,0x69,0x66,0x3E,0x00
	};
	/* Predefined audio header */
	const unsigned char audio_header[]={//35 : header length
		0x12,0x61,0x75,0x64,0x69,0x6F,0x2F,0x6D,0x69,0x64,0x69,0x00,0x86,0x32,0x2E,0x6D,0x69,
		0x64,,0x00,0x8E,0x32,0x2E,0x6D,0x69,0x64,0x00,0xC0,0x22,0x3C,0x32,0x2E,0x6D,0x69,0x64,
		0x3E,0x00
	};
	/* Predefined audio header */
	const unsigned char text_header[]={//36  : header length
		0x0D,0x83,0x81,0xEA,0x86,0x74,0x65,0x78,0x74,0x2E,0x74,0x78,0x74,0x00,0x8E,0x74,0x65,
		0x78,0x74,0x2E,0x74,0x78,0x74,0x00,0xC0,0x22,0x3C,0x74,0x65,0x78,0x74,0x2E,0x74,0x78,
		0x74,0x3E,0x00
	};
#endif

	
	char *Ptr;
	int length;
	MsfImageFormat type;
	unsigned char *mediaPtr;	
	unsigned char uintvar[6];
	int mediaSize=0;

	Ptr=NULL;
	mediaPtr=NULL;
	memset(uintvar,0x00,6);
	memset(mediaBuf,0x00,mmsBufSize);	

	switch(mediaType)
	{
		case MMS_TEXT:
			{				
				Ptr=GetString(resId);
				if(!Ptr) return -1;
				mediaSize=widget_ucs2_length((kal_uint8*)Ptr)*2;
				mediaPtr=MSF_MEM_ALLOC(MSF_MODID_MSM,mediaSize+2);
				memset(mediaPtr,0x00,mediaSize+2);
				memcpy(mediaPtr,Ptr,mediaSize+1);
				mediaSize=widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)mediaPtr);
				Ptr = (char*)MSF_MEM_ALLOC(MSF_MODID_MSM,mediaSize+1);
				widget_ucs2_to_utf8_string((kal_uint8*)Ptr,mediaSize+1,(kal_uint8*)mediaPtr);
				MSF_MEM_FREE(MSF_MODID_MSM,mediaPtr);
                mediaPtr = mediaBuf;
                *mediaPtr++ = 0x31;
                mediaPtr = cnvUint32ToUintvar(mediaSize, mediaPtr, mmsBufSize - (mediaPtr - mediaBuf));
                memcpy(mediaPtr,text_header,0x31);
				sprintf((char *)mediaPtr + 0x31, "%s", Ptr);
				MSF_MEM_FREE(MSF_MODID_MSM,Ptr);
                return ((mediaPtr - mediaBuf) + mediaSize + 0x31);
			}
		case MMS_IMAGE:
			{
				Ptr=(char*)HDIa_widgetExtImageGetPredefinedBuffer(resId,&length,&type);
				if(!Ptr) 
					return -1;
				switch(type)
				{
					case MsfGif: //Only support gif image
                        mediaPtr = mediaBuf;
                        *mediaPtr++ = 0x1A;
                        mediaPtr = cnvUint32ToUintvar(length, mediaPtr, mmsBufSize - (mediaPtr - mediaBuf));
                        *mediaPtr++ = 0x08;
                        *mediaPtr++ = 0x9D;
                        memcpy(mediaPtr,image_header,24);
                        return ((mediaPtr - mediaBuf) + 24);
					default:
						return -1;
				}
			}
		case MMS_AUDIO://Only support midi audio
            mediaPtr = mediaBuf;
            *mediaPtr++ = 0x24;
            mediaPtr = cnvUint32ToUintvar(resource_mms_sounds[resId].len, mediaPtr, mmsBufSize - (mediaPtr - mediaBuf));
            memcpy(mediaPtr, audio_header, 36);
            return ((mediaPtr - mediaBuf) + 36);
	}
	return -1;
}

/*************************************************************
 FUNCTION                                                            
	copyMmsTemplates

 DESCRIPTION                                                           
   The function is used to create default Mms templates.
   The function shall work at the first startup.

 PARAMETERS
	MSF_BOOL factoryRestore. If the factoryRestore equals to TRUE, 
	the mms templates will be writen even it isn't first startup.

 RETURNS
   TRUE or FALSE	

 GLOBALS AFFECTED
   The default mms templates may be generated.
**************************************************************/
extern int HDIa_fileCheckDirExist(const char *dirName);
static void copyMmsTemplates(MSF_BOOL factoryRestore)
{
#ifdef MMS_SUPPORT

	int msgId_Base=1;
	unsigned char Buffer[mmsBufSize];
	char filePath[80];
	char *mediaPtr=NULL;
	MsfImageFormat type;
	int len=0;	
	int fileHandle=-1;
	int wrSuccess=TRUE;
	int i=0;
	long imageSize=0;
	MSF_BOOL shallBeInsert=FALSE;		
	int writeResult=0;
	int noWrMmsTemplate=0;
	int noMmsTemplate = 0;
	createFolder();
#ifdef MMS_FILE_PROTECT_SUPPORT
	if (HDIa_fileCheckDirExist(MMS_SYS_FOLDER) == 0)
	{
		MSF_FILE_MKDIR(MMS_SYS_FOLDER);		
	}	
	if(!isValidMmsIndexFile())
	{
		msm_remove_files_under_dir(MMS_SYS_FOLDER);
		msm_remove_files_under_dir(MMS_FOLDER);
	}
#endif
#ifndef __MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES__
	noMmsTemplate = getMmsTemplateNum();
	for(i=msgId_Base;i<(msgId_Base+noMmsTemplate);i++)
	{
		//Write Procedure
		memset(filePath,0x00,80);
		sprintf(filePath,"%s%x.t",MMS_FOLDER,i);			
		if(MSF_FILE_GETSIZE(filePath)<=0)
		{
			shallBeInsert=TRUE;
			factoryRestore=TRUE;
			break;
		}
	}

    if(shallBeInsert || factoryRestore)
	{		
		for(i=0;i<noMmsTemplate;i++)
		{
			//Write Procedure
			memset(filePath,0x00,80);
			sprintf(filePath,"%s%x.t",MMS_FOLDER,msgId_Base++);			
			MSF_FILE_REMOVE(filePath);
			fileHandle=-1;
			wrSuccess=TRUE;
			mediaPtr=NULL;
			fileHandle=MSF_FILE_OPEN(MSF_MODID_MSM,filePath,HDI_FILE_SET_WRONLY|HDI_FILE_SET_CREATE| HDI_FILE_SET_CUSTOM_BLOCKING,0);
#ifdef MMS_FILE_PROTECT_SUPPORT
			/* Delete unused checksum file */
			memset(filePath,0x00,80);
			sprintf(filePath,"%s%x.c",MMS_SYS_FOLDER,(msgId_Base-1));
			MSF_FILE_REMOVE(filePath);
			/* Restore mms template file path */
			memset(filePath,0x00,80);
			sprintf(filePath,"%s%x.t",MMS_FOLDER,(msgId_Base-1));
#endif		
			if(fileHandle>=0)
			{
				if((len=generateMmsHeader(Buffer,mmsTemplates[i].strId,NULL))>0)
				{
					writeResult=0;
					if((writeResult=MSF_FILE_WRITE(fileHandle,Buffer,len))!=len)
					{
						wrSuccess=FALSE;
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,MMS_AAPP_408369950038557C5232ED615D409029, "%s(%d): Fails to create message header of %d th mms templates, writeResult:%d, bytesToWrite:%d\n",	__FILE__, __LINE__,i,writeResult,len));   
					}
				}
				else
				{
					wrSuccess=FALSE;
				}	
				len=-1;
				if(((len=generateMediaHeader(Buffer,MMS_IMAGE,mmsTemplates[i].imageId))>0)&&wrSuccess)
				{
					writeResult=0;
					if((writeResult=MSF_FILE_WRITE(fileHandle,Buffer,len))!=len)
					{			
						wrSuccess=FALSE;
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,MMS_AAPP_C5D779318E1FC9EDCC7BB460A13D1CBD, "%s(%d): Fails to create image header of %d th mms templates, writeResult:%d, bytesToWrite:%d\n",	__FILE__, __LINE__,i,writeResult,len));   
					}
					else
					{
						int length=0;
						imageSize=-1;
						mediaPtr=NULL;
						
						mediaPtr=(char*)HDIa_widgetExtImageGetPredefinedBuffer(mmsTemplates[i].imageId, &length, &type);
						if(mediaPtr)
							imageSize=length;
						if(imageSize>0)
						{
							writeResult=0;
							
							writeResult=MSF_FILE_WRITE(fileHandle,mediaPtr,imageSize);
							if(writeResult!=imageSize)
							{
								MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,MMS_AAPP_1CBBA43961E36E0A07B839088148BCA7, "%s(%d): Fails to create image data of %d th mms templates, writeResult:%d, bytesToWrite:%d\n",__FILE__, __LINE__,i,writeResult,len));
								wrSuccess=FALSE;
							}
							mediaPtr=NULL;
						}	
					}
				}
				else
				{
					wrSuccess=FALSE;
				}
				len=-1;
				if(((len=generateMediaHeader(Buffer,MMS_AUDIO,mmsTemplates[i].audioId))>0)&&wrSuccess)
				{	
					writeResult=0;
					if((writeResult=MSF_FILE_WRITE(fileHandle,Buffer,len))!=len)
					{			
						wrSuccess=FALSE;
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,MMS_AAPP_77D2CE9AD2F5826D2EB2C024FAE2BBD8, "%s(%d): Fails to create audio header of %d th mms templates, writeResult:%d, bytesToWrite:%d\n",__FILE__, __LINE__,i,writeResult,len));   
					}
					else
					{
						if(resource_mms_sounds[mmsTemplates[i].audioId].len>0)
						{
							writeResult=0;
							if((writeResult=MSF_FILE_WRITE(fileHandle,(char *)resource_mms_sounds[mmsTemplates[i].audioId].data,resource_mms_sounds[mmsTemplates[i].audioId].len))!=resource_mms_sounds[mmsTemplates[i].audioId].len)
							{
								wrSuccess=FALSE;
								MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,MMS_AAPP_069A6987C0E22D763DE2D52110C79FA6, "%s(%d): Fails to create audio date of %d th mms templates, writeResult:%d, bytesToWrite:%d\n",__FILE__, __LINE__,i,writeResult,len));   
							}					
						}
						else
						{
							wrSuccess=FALSE;
						}
					}
				}
				else
				{
					wrSuccess=FALSE;
				}
				len=-1;
				if(((len=generateMediaHeader(Buffer,MMS_TEXT,mmsTemplates[i].strId))>0)&&wrSuccess)
				{
					writeResult=0;
					if((writeResult=MSF_FILE_WRITE(fileHandle,Buffer,len))!=len)
					{
						wrSuccess=FALSE;
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,MMS_AAPP_C7E33FCD983E5FECB9EC89903F71E82B, "%s(%d): Fails to create text header of %d th mms templates, writeResult:%d, bytesToWrite:%d\n",__FILE__, __LINE__,i,writeResult,len));   
					}	
				}
				else
				{
					wrSuccess=FALSE;
				}
				len=-1;
				if(((len=generateSMIL(Buffer,FALSE))>0)&&wrSuccess)
				{	
					writeResult=0;
					if((writeResult=MSF_FILE_WRITE(fileHandle,Buffer,len))!=len)
					{
						wrSuccess=FALSE;
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,MMS_AAPP_267F954B9F1645E67D41F5AED80ABD4A, "%s(%d): Fails to create SMIL part of %d th mms templates, writeResult:%d, bytesToWrite:%d\n",__FILE__, __LINE__,i,writeResult,len));   
					}
				}
				else
				{
					wrSuccess=FALSE;
				}
				MSF_FILE_CLOSE(fileHandle);
				if(!wrSuccess)
				{
					MSF_FILE_REMOVE(filePath);
				}else
				{
					noWrMmsTemplate+=1;
				}
			}	
			else
			{
				MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,MMS_AAPP_16E57952F0E0FD667BCF7EEBEAC89DA0, "%s(%d): Fails to open file %d th mms templates, opeResult:%d\n",__FILE__, __LINE__,i,fileHandle));   
			}
		}	
	}
#else /* CFG_MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES*/

#define MMS_FORMAT_TEST_FILE    "mmstest.ftt"
#define MMS_FORMAT_TEST_FOLDER    "mmstest/"

    /* Format test folder name*/
    filePath[0] = 0;
	sprintf(filePath,"%s%s",MMS_FOLDER,MMS_FORMAT_TEST_FOLDER);
    
    /* Test format test folder*/
    if (HDIa_fileCheckDirExist(filePath) == 0)
	{
		MSF_FILE_MKDIR(filePath);		
	}

    /* Format test file name*/
    filePath[0] = 0;
	sprintf(filePath,"%s%s%s",MMS_FOLDER, MMS_FORMAT_TEST_FOLDER, MMS_FORMAT_TEST_FILE);
    

    /* Test format test file*/
    fileHandle = -1;
    fileHandle = MSF_FILE_OPEN(MSF_MODID_MSM, filePath, HDI_FILE_SET_RDONLY,0);

    if (fileHandle < 0) /* No test file, mms formated*/
    {
        shallBeInsert=TRUE;
        factoryRestore=TRUE;

        /* Create format test file*/
        fileHandle = MSF_FILE_OPEN(MSF_MODID_MSM, filePath, 
            HDI_FILE_SET_WRONLY|HDI_FILE_SET_CREATE|HDI_FILE_SET_CUSTOM_BLOCKING,0);
        if (fileHandle >= 0)
        {
            MSF_FILE_CLOSE(fileHandle);
            fileHandle = -1;
        }
    }
    else
    {
        MSF_FILE_CLOSE(fileHandle);
        fileHandle = -1;
    }

#endif /* CFG_MMI_OBIGO_Q03C_MMS_USER_DEFINED_TEMPLATES*/

	if(factoryRestore)
	{
		MSF_FILE_REMOVE(MMS_MMT_BACKUP_FILE);
		MSF_FILE_REMOVE(MMS_MMT_TMP_FILE);
		MSF_FILE_REMOVE(MMS_MMT_FILE);
	}	
#ifdef MMS_FILE_PROTECT_SUPPORT
	/* Reserve checksum space for mms templates */
	if(noWrMmsTemplate>0)
	{
		fileHandle=-1;	
		fileHandle=MSF_FILE_OPEN(MSF_MODID_MMS,"\\mms_sys\\chkbuf.tmp",HDI_FILE_SET_WRONLY|HDI_FILE_SET_CREATE| HDI_FILE_SET_CUSTOM_BLOCKING,(250*noWrMmsTemplate));
		if(fileHandle>=0)
		{
			MSF_FILE_CLOSE(fileHandle);
		}
	}
#endif
#endif /*MMS_SUPPORT*/
}
#endif 

extern MSF_BOOL meaCheckCharacterIsAllEnglish(const char *str);
extern long mmsWapGetTransactionId(void);
/*************************************************************
 FUNCTION                                                            
	addAttachmentToMmsMessage

 DESCRIPTION                                                           
   Add attachements to an mms message. 
   The function is only used in meaCreateMessageFSM().
   The number of attachments must be smaller than 60.

 PARAMETERS
	MSF_UINT8 modId,MmsMsgId msgId,MSF_UINT8 objectNum,
	attachmentObjectList *attachObjectList

 RETURNS
   TRUE or FALSE	

 GLOBALS AFFECTED
   The existing mms message will be modified.
**************************************************************/
MSF_BOOL addAttachmentToMmsMessage(MSF_UINT8 modId,MmsMsgId msgId,MSF_UINT32 numOfBodyPosition, MSF_UINT8 objectNum,attachmentObjectList *attachObjectList)
{
	MSF_UINT8 msgFilePath[40];
	MSF_UINT8 uintvar[6];
	MSF_UINT8* buffer;
	MSF_UINT8 bodyNum;
	MmsFileType suffix;
	int msgFileHandle=-1;
	int objectFileHandle=-1;
	int headerLen=-1;
	int dataLen=-1;
	int bytesInBuffer=0;
	int bytesLeftToRead=0;
	MSF_UINT8* tmp_uintvar=NULL;

	attachmentObjectList *objectList;

	if(numOfBodyPosition==0)
    	{
		MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,MMS_AAPP_F5824B9F26424070A68FD1BD7EBE06FA, "%s(%d): The message file is corrupted. It can't insert attachment. \n", __FILE__, __LINE__));   
		return FALSE;
	}
	objectList=attachObjectList;
	suffix=fldrGetFileSuffix(msgId);
	sprintf((char *)msgFilePath,"%s%lx.%c",MMS_FOLDER,msgId,suffix);
	

	if((msgFileHandle=MSF_FILE_OPEN(modId,(char*)msgFilePath,HDI_FILE_SET_RDWR|HDI_FILE_SET_CUSTOM_BLOCKING,0))<=0)	
    	{    
		return FALSE;
	}
	else if((buffer=MSF_MEM_ALLOC(modId,512))==NULL)
	{
		MSF_FILE_CLOSE(msgFileHandle);
		return FALSE;
	}
	
	
	MSF_FILE_SEEK (msgFileHandle, numOfBodyPosition, HDI_FILE_SEEK_SET);
	MSF_FILE_READ(msgFileHandle,&bodyNum,1);	
	bodyNum+=objectNum;

	if(bodyNum>127)
	{
		MSF_FILE_CLOSE(msgFileHandle);
		MSF_MEM_FREE(modId,buffer);
		return FALSE;
	}	
	MSF_FILE_SEEK (msgFileHandle, numOfBodyPosition, HDI_FILE_SEEK_SET);
	MSF_FILE_WRITE(msgFileHandle,&bodyNum,1);
	MSF_FILE_SEEK (msgFileHandle, 0, HDI_FILE_SEEK_END);
	
	while(objectList)
	{
		headerLen=-1;
		dataLen=-1;
		bytesInBuffer=0;
		memset(buffer,0x00,512);		
		memset(uintvar,0x00,6);
		bytesLeftToRead=0;
		
		if(objectList->filepath)
    		{
			if(objectList->filepath[0]!='/'&& objectList->filepath[0]!='\\')
			{				
				MSF_LOG_MSG_OFF(( MSF_LOG_DETAIL_HIGH, MSF_MODID_MMS,MMS_AAPP_E447448497FCCBEC5B0EE8052473FEE3, "%s(%d):wrong filepath:%s \n", __FILE__, __LINE__,objectList->filepath));   
			}
			else
			{
				bytesLeftToRead=MSF_FILE_GETSIZE((char *)objectList->filepath);	
			}
		}		
		if(bytesLeftToRead<=0)
		{
		
		}
		else
		{		
			char * objectFileName = NULL;
			char * objectCntLocation = NULL;
			MSF_BOOL shallBeTransform = !(meaCheckCharacterIsAllEnglish((char *)objectList->filename));
			if(shallBeTransform)
			{
				objectFileName = MSF_MEM_ALLOC(MSF_MODID_MMS, 40);
				memset(objectFileName,0x00,40);								
				if (objectFileName)
				{
					sprintf((char *)objectFileName, "%lx%s", (long)(mmsWapGetTransactionId()),strrchr((char *)objectList->filename,'.'));					
				}
				//MSF_MEM_FREE(MSF_MODID_MMS, objectList->filename);
				//objectList->filename = (MSF_UINT8 *)MSF_MEM_ALLOC(MSF_MODID_MMS, strlen(objectFileName)+1);
				//if(objectList->filename)
				//	strcpy((char *)objectList->filename, objectFileName);
			}
			else
			{
				objectFileName = MSF_MEM_ALLOC(MSF_MODID_MMS, strlen((char *)objectList->filename)+1);
				if (objectFileName)
				{
					strcpy(objectFileName, (char *)objectList->filename);
				}
			}
			/*create virtual content location*/
			objectCntLocation = MSF_MEM_ALLOC(MSF_MODID_MMS, strlen(objectFileName)+1);
			memset(objectCntLocation,0x00,strlen(objectFileName)+1);
            strcpy(objectCntLocation, objectFileName);

			// handele body header length
			headerLen=strlen((char *)objectFileName)+2*strlen(objectCntLocation)+9; /*80=40x2, Two content location*/
			if(objectList->mimetype_mode==0)
			{
				int i=0;
				tmp_uintvar=uintvar;
				i=strlen((char *)objectFileName)+3;
				memset(uintvar,0x00,6);
				//cnvUint32ToUintvar(i,uintvar,5);	
				tmp_uintvar=cnvUint32ToValueLength(i,uintvar,6);
				headerLen=headerLen+1+tmp_uintvar-uintvar;
			}
			else
			{
				int i=0;
				tmp_uintvar=uintvar;
				i=strlen((char *)objectList->mimetype_svalue)+strlen((char *)objectFileName)+3;
				memset(uintvar,0x00,6);				
				//cnvUint32ToUintvar(i,uintvar,5);	
				tmp_uintvar=cnvUint32ToValueLength(i,uintvar,6);
				headerLen=headerLen+1+tmp_uintvar-uintvar+strlen((char *)objectList->mimetype_svalue);
			}
			// handle header length	
			tmp_uintvar=uintvar;
			memset(uintvar,0x00,6);
			tmp_uintvar=cnvUint32ToUintvar(headerLen,uintvar,5);			
			memcpy((char *)buffer,(char *)uintvar,tmp_uintvar-uintvar);
			bytesInBuffer+=(tmp_uintvar-uintvar);

			// handle data length	
			memset(uintvar,0x00,6);
			tmp_uintvar=uintvar;			
			tmp_uintvar=cnvUint32ToUintvar(MSF_FILE_GETSIZE((char *)objectList->filepath),uintvar,5);			
			memcpy((char *)(buffer+bytesInBuffer),(char *)uintvar,tmp_uintvar-uintvar);
			bytesInBuffer+=(tmp_uintvar-uintvar);

		    //handle mime_type
			if(objectList->mimetype_mode==0)
			{
				int i=0;
				objectList->mimetype_cvalue=SET_HIGH_BIT(objectList->mimetype_cvalue);
				i=strlen((char *)objectFileName)+3;
				tmp_uintvar=uintvar;
				memset(uintvar,0x00,6);				
				tmp_uintvar=cnvUint32ToValueLength(i,uintvar,6);			
				memcpy((char *)(buffer+bytesInBuffer),(char *)uintvar,tmp_uintvar-uintvar);
				bytesInBuffer+=(tmp_uintvar-uintvar);

				sprintf((char *)buffer+bytesInBuffer,"%c",objectList->mimetype_cvalue);
				bytesInBuffer+=1;
			}
			else
			{
				int i=0;
				i=strlen((char *)objectList->mimetype_svalue)+strlen((char *)objectFileName)+3;
				tmp_uintvar=uintvar;
				memset(uintvar,0x00,6);				
				tmp_uintvar=cnvUint32ToValueLength(i,uintvar,6);			
				memcpy((char *)(buffer+bytesInBuffer),(char *)uintvar,tmp_uintvar-uintvar);
				bytesInBuffer+=(tmp_uintvar-uintvar);
				sprintf((char *)buffer+bytesInBuffer,"%s",(char *)objectList->mimetype_svalue);
				bytesInBuffer=bytesInBuffer+1+strlen((char *)objectList->mimetype_svalue);
			}
#ifdef MMS_USE_NAME_PARMS
			sprintf((char *)buffer+bytesInBuffer,"%c%s",0x85,(char *)objectFileName);
#else
			sprintf((char *)buffer+bytesInBuffer,"%c%s",0x86,(char *)objectFileName);
#endif
			bytesInBuffer=bytesInBuffer+2+strlen((char *)objectFileName);
			//handle 0x86
			sprintf((char *)buffer+bytesInBuffer,"%c%s",0x8E,(char *)objectCntLocation);
			bytesInBuffer=bytesInBuffer+2+strlen((char *)objectCntLocation);
			//handle 0x8E
			sprintf((char *)buffer+bytesInBuffer,"%c%c%c",0xC0,0x22,0x3C);
			bytesInBuffer+=3;
			//handle 0xCO 0x22 0x3E
			sprintf((char *)buffer+bytesInBuffer,"%s%c",(char *)objectCntLocation,0x3E);
			bytesInBuffer=bytesInBuffer+strlen((char *)objectCntLocation)+2;

			if(MSF_FILE_WRITE(msgFileHandle,buffer,bytesInBuffer)!=bytesInBuffer)
			{
				MSF_FILE_CLOSE(msgFileHandle);
				MSF_MEM_FREE(modId,buffer);
				return FALSE;		
			}
		
			if((objectFileHandle=MSF_FILE_OPEN(modId,(char *)objectList->filepath,HDI_FILE_SET_RDONLY|HDI_FILE_SET_CUSTOM_BLOCKING,0))<=0)
			{
				MSF_FILE_CLOSE(msgFileHandle);
				MSF_MEM_FREE(modId,buffer);
				return FALSE;
			}
		
			while(bytesLeftToRead>512)
			{
				if((MSF_FILE_READ(objectFileHandle,buffer,512)!=512)||(MSF_FILE_WRITE(msgFileHandle,buffer,512)!=512))
				{
					MSF_FILE_CLOSE(msgFileHandle);
					MSF_FILE_CLOSE(objectFileHandle);
					MSF_MEM_FREE(modId,buffer);
					return FALSE;
				}
				bytesLeftToRead-=512;
			}
			if(bytesLeftToRead>0)
			{
				if((MSF_FILE_READ(objectFileHandle,buffer,bytesLeftToRead)!=bytesLeftToRead)||(MSF_FILE_WRITE(msgFileHandle,buffer,bytesLeftToRead)!=bytesLeftToRead))
				{
					MSF_FILE_CLOSE(msgFileHandle);
					MSF_FILE_CLOSE(objectFileHandle);
					MSF_MEM_FREE(modId,buffer);
					return FALSE;
				}
			}
			MSF_FILE_CLOSE(objectFileHandle);
		}
		objectList=objectList->next;
	}
	MSF_FILE_CLOSE(msgFileHandle);
	MSF_MEM_FREE(modId,buffer);
	return TRUE;
}

static void set10RrStringRes(unsigned short resId, char *key)
{

	MmsRegistryEntry *MmsRegistryMmsRREntries=NULL;
	char *Ptr=NULL;
    unsigned char *mediaPtr=NULL;		
	int mediaSize=0;

	Ptr=GetString(resId);
	if(!Ptr) 
		return;
	/*Transform UCS2 string to UTF8 */
	mediaSize=widget_ucs2_length((kal_uint8*)Ptr)*2;
	mediaPtr=MSF_MEM_ALLOC(MSF_MODID_MMS,mediaSize+2);
	memset(mediaPtr,0x00,mediaSize+2);
	memcpy(mediaPtr,Ptr,mediaSize+1);
	mediaSize=widget_ucs2_to_utf8_length_in_bytes((kal_uint8*)mediaPtr);
	Ptr = (char*)MSF_MEM_ALLOC(MSF_MODID_MMS,mediaSize+1);
	widget_ucs2_to_utf8_string((kal_uint8*)Ptr,mediaSize+1,(kal_uint8*)mediaPtr);
	MSF_MEM_FREE(MSF_MODID_MMS,mediaPtr);

    if(MSF_moduleIsRunning(MSF_MODID_MMS))
	{
		MmsRegistryMmsRREntries=MMS_CALLOC(sizeof(MmsRegistryEntry));		
		if(MmsRegistryMmsRREntries)
		{
			MmsRegistryMmsRREntries->path=MMS_CALLOC(strlen((char*)MMS_REG_PATH_REPORT_TEXT)+1);			
			if(MmsRegistryMmsRREntries->path)
			{
				strcpy(MmsRegistryMmsRREntries->path,(char*)MMS_REG_PATH_REPORT_TEXT);
			}
			else
			{
				ASSERT(0);
			}						
			MmsRegistryMmsRREntries->key=MMS_CALLOC(strlen((char*)key)+1);			
			if(MmsRegistryMmsRREntries->key)
			{
				strcpy(MmsRegistryMmsRREntries->key,(char*)key);
			}
			else
			{
				ASSERT(0);
			}							
			MmsRegistryMmsRREntries->type=MSF_REGISTRY_TYPE_STR;
			MmsRegistryMmsRREntries->value_i=0;
			MmsRegistryMmsRREntries->next=NULL;
			MmsRegistryMmsRREntries->value_bv=(unsigned char*)Ptr;
			MmsRegistryMmsRREntries->value_bv_length=strlen(Ptr)+1;
			M_SIGNAL_SENDTO_P(M_FSM_CORE_CONFIG, (int)MMS_SIG_CORE_REG_RESPONSE, 
                           MmsRegistryMmsRREntries);		
		}
	}
}

/*************************************************************
 FUNCTION                                                            
	set10RrAllStringRes

 DESCRIPTION                                                           
   Update string resource to mms v1.0  read report
   
 PARAMETERS
	None
 RETURNS
   None	

 GLOBALS AFFECTED
   Some items in mms cfgIntValues array are updated.
**************************************************************/
void set10RrAllStringRes()
{
	set10RrStringRes(MMS_STR_ID_RR_TEXT_YOUR_MSG,MMS_REG_KEY_TEXT_YOUR_MSG);
	set10RrStringRes(MMS_STR_ID_RR_TEXT_FROM,MMS_REG_KEY_TEXT_FROM);
	set10RrStringRes(MMS_STR_ID_RR_TEXT_TO,MMS_REG_KEY_TEXT_TO);
	set10RrStringRes(MMS_STR_ID_RR_TEXT_MSGID,MMS_REG_KEY_TEXT_MSGID);
	set10RrStringRes(MMS_STR_ID_RR_TEXT_READ,MMS_REG_KEY_TEXT_READ);
	set10RrStringRes(MMS_STR_ID_RR_TEXT_SENT,MMS_REG_KEY_TEXT_SENT);	
	set10RrStringRes(MMS_STR_ID_RR_TEXT_WAS_READ,MMS_REG_KEY_TEXT_WAS_READ);
	set10RrStringRes(MMS_STR_ID_RR_TEXT_SUBJECT,MMS_REG_KEY_TEXT_SUBJECT);	
	widget_send_update_event_to_wap();
}

/*************************************************************
 FUNCTION                                                            
	mmsCusCfgInit

 DESCRIPTION                                                           
   To write default value to registry
   
 PARAMETERS
	None
 RETURNS
   None	

 GLOBALS AFFECTED
   The existing registry will be modified.
**************************************************************/
static void mmsCusCfgInit()
{
    	void *reg_handle=NULL;
    	
	reg_handle = MSF_REGISTRY_SET_INIT (MSF_MODID_MMS);
	if(reg_handle)
	{
		MSF_REGISTRY_SET_PATH (reg_handle, (char*)MMS_REG_PATH_ADDRESS);
		MSF_REGISTRY_SET_ADD_KEY_INT (reg_handle, (char*)MMS_REG_KEY_FROM_ADDRESS_INSERT_TYPE,MMS_FROM_INSERT_ADDRESS);
		MSF_REGISTRY_SET_COMMIT (reg_handle);
		MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS,MMS_AAPP_15DF79E1AF8347C2D478ED17EEF56B1B, "%s(%d): Set the mms from address type to insert.\n", __FILE__, __LINE__));   
	}
	updateRoamingStatusToMMS(MMS_SIM_CARD_MASTER);
#ifdef __MMS_DUAL_SIM_SUPPORT__
	updateRoamingStatusToMMS(MMS_SIM_CARD_SLAVE);
#endif
}

/*************************************************************
 FUNCTION                                                            
	mmsUpdateIndicator

 DESCRIPTION                                                           
   To set indicator icon
   
 PARAMETERS
	None
 RETURNS
   None	

 GLOBALS AFFECTED
**************************************************************/
void mmsUpdateIndicator()
{
    MSF_UINT16 nMsgs = 0, nUnreadMsgs = 0, dummy = 0, flag = 0;
    MmsFolderType folder = MMS_ALL_FOLDERS;
#ifdef __MMS_DUAL_SIM_SUPPORT__
    MSF_UINT16 nMsgSimMaster = 0, nMsgSimSlave = 0, nUnreadMsgSimMaster = 0, nUnreadMsgSimSlave = 0;

    MSF_UINT8  sim_status = wap_get_sim_status();
    MSF_UINT8  setting_mode = wap_get_sim_setting_mode();

#endif /*__MMS_DUAL_SIM_SUPPORT__*/
    folder &= ~MMS_HIDDEN;
    fldrMgrGetNumberOfMessages(folder, &nMsgs, &dummy);
    fldrMgrGetNumberOfMessages(MMS_INBOX | MMS_NOTIFY, &dummy, &nUnreadMsgs);

#ifdef __MMS_DUAL_SIM_SUPPORT__
    fldrMgrGetNumberOfMessagesExt(MMS_INBOX | MMS_NOTIFY, &nMsgSimMaster, \
                                  &nUnreadMsgSimMaster, &nMsgSimSlave, \
                                  &nUnreadMsgSimSlave, &dummy, &nUnreadMsgs);
#endif /*__MMS_DUAL_SIM_SUPPORT__*/


#ifdef __MMS_DUAL_SIM_SUPPORT__
    if(IsMasterSIMBusy())
    {
        flag = flag | MMS_STATUS_SIM_1_BUSY;        
    }
    if(IsSlaveSIMBusy())
    {
        flag = flag | MMS_STATUS_SIM_2_BUSY;
    }
#else /*__MMS_DUAL_SIM_SUPPORT__*/
    if(isMMSBusy())
    {
        flag = flag | MMS_STATUS_BUSY;
    }
#endif /*__MMS_DUAL_SIM_SUPPORT__*/


    if(nMsgs >= (MMS_MAX_NO_OF_MSG -1))
    {

        flag = flag | MMS_STATUS_FULL;
    }

    if (nUnreadMsgs > 0)
    {
#ifdef __MMS_DUAL_SIM_SUPPORT__
        if(nUnreadMsgSimMaster > 0)
        {
            flag = flag | MMS_STATUS_SIM_1_NEW_MESSAGE;
        }
        if(nUnreadMsgSimSlave > 0)
        {
            flag = flag | MMS_STATUS_SIM_2_NEW_MESSAGE;
        }
#else
        flag = flag | MMS_STATUS_NEW_MESSAGE;
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
    }

    mms_set_indicator(flag);
}

#ifdef __MMS_CACHE_PUSH__

#define MMS_CACHE_PUSH_FOLDER "\\mms_sys\\cache_push"
#define MMS_CACHE_PUSH_SYS_FILE "\\mms_sys\\cache_push\\index.txt"

typedef struct
{
    MSF_UINT32 MmsNextPushId;
    MSF_UINT32 MmsNoOfCachedPush;
}MMS_CACHE_PUSH_INFO_struct;

MMS_CACHE_PUSH_INFO_struct g_MmsCachePushInfo ={0};
void mmsUpdateCachePushInfo(MMS_CACHE_PUSH_INFO_struct *info);


/************************************************************************
* FUNCTION                                                            
*	mmsRestoreCachePushInfo(void)
*
* DESCRIPTION                                                           
*	It is used to restore cache push information from MMS_CACHE_PUSH_SYS_FILE
*
* CALLS  
*                           
* PARAMETERS
*    None
* RETURNS
* GLOBALS AFFECTED
* 	g_MmsCachePushInfo
*************************************************************************/
void mmsRestoreCachePushInfo()
{
    int filehandle = -1;			
    int result = -1;
    int openMode = MSF_FILE_SET_RDONLY;	

	filehandle = MSF_FILE_OPEN( MSF_MODID_MMS, MMS_CACHE_PUSH_SYS_FILE, openMode, 0);
    if(filehandle >= 0)
	{
        result = MSF_FILE_READ(filehandle,(char *)&g_MmsCachePushInfo, sizeof(MMS_CACHE_PUSH_INFO_struct));		
    	if(result != sizeof(MMS_CACHE_PUSH_INFO_struct))
	    {
            MSF_FILE_CLOSE(filehandle);
            msm_remove_files_under_dir(MMS_CACHE_PUSH_FOLDER);
            g_MmsCachePushInfo.MmsNextPushId = 1;
            g_MmsCachePushInfo.MmsNoOfCachedPush = 0;
            mmsUpdateCachePushInfo(&g_MmsCachePushInfo);
    	}
        else
        {
            MSF_FILE_CLOSE(filehandle);
        }
	}
    else
    {        
        if (filehandle == MSF_FILE_ERROR_PATH)
        {
            MSF_FILE_MKDIR(MMS_CACHE_PUSH_FOLDER);
        }
        msm_remove_files_under_dir(MMS_CACHE_PUSH_FOLDER);
        g_MmsCachePushInfo.MmsNextPushId = 1;
        g_MmsCachePushInfo.MmsNoOfCachedPush = 0;
        mmsUpdateCachePushInfo(&g_MmsCachePushInfo);
    }
}

/************************************************************************
* FUNCTION                                                            
*	mmsUpdateCachePushInfo(void)
*
* DESCRIPTION                                                           
*	It is used to update cache push information to MMS_CACHE_PUSH_SYS_FILE
*
* CALLS  
*                           
* PARAMETERS
*   info
* RETURNS
* GLOBALS AFFECTED
* 	g_MmsCachePushInfo
*************************************************************************/
void mmsUpdateCachePushInfo(MMS_CACHE_PUSH_INFO_struct *info)
{   
	int filehandle = -1;
    int result = -1;
	int openMode = MSF_FILE_SET_WRONLY | MSF_FILE_SET_CREATE;	

    ASSERT(info);
	filehandle = MSF_FILE_OPEN( MSF_MODID_MMS, MMS_CACHE_PUSH_SYS_FILE, openMode, 0);
	if(filehandle >= 0)
	{
        result = MSF_FILE_WRITE(filehandle,(char *)info, sizeof(MMS_CACHE_PUSH_INFO_struct));				
		MSF_FILE_CLOSE(filehandle);
		if(result != sizeof(MMS_CACHE_PUSH_INFO_struct))
		{
            MSF_FILE_REMOVE(MMS_CACHE_PUSH_SYS_FILE);
		}		
	}
}

/************************************************************************
* FUNCTION                                                            
*	mmsGetCachedPushNum(void)
*
* DESCRIPTION                                                           
*	It is used to get the number of cached push
*
* CALLS  
* RETURNS
*   number of cached push
* GLOBALS AFFECTED
*************************************************************************/
MSF_UINT32 mmsGetCachedPushNum(void)
{
    return g_MmsCachePushInfo.MmsNoOfCachedPush;
}

#endif /* __MMS_CACHE_PUSH__ */
 
/************************************************************************
* FUNCTION                                                            
*	mmsWritePushToCache(void)
*
* DESCRIPTION                                                           
*	It is used to write received push message to file. 
* CALLS  
*                           
* PARAMETERS
*   data    Push content
*   dataLen The length of push content
* RETURNS
* GLOBALS AFFECTED
* 	g_MmsCachePushInfo
*************************************************************************/
void mmsWritePushToCache(
#ifdef __MMS_DUAL_SIM_SUPPORT__
        MSF_UINT32 simId,
#endif
        MSF_UINT8 *data,
        MSF_UINT32 dataLen)
{
#ifdef __MMS_CACHE_PUSH__
    int filehandle = -1;
    int result = -1;
    int openMode = MSF_FILE_SET_WRONLY | MSF_FILE_SET_CREATE;
    char *filename = NULL;
    
    filename = MMS_ALLOC(strlen(MMS_CACHE_PUSH_FOLDER) + 20);
    ASSERT(filename);
    if (g_MmsCachePushInfo.MmsNextPushId == 0)
    {
        mmsRestoreCachePushInfo();
    }
    if (g_MmsCachePushInfo.MmsNoOfCachedPush >= MMS_MAX_NO_CACHE_PUSH)
    {
        /* Drop oldest MMS push message*/
        sprintf((char*)filename, "%s\\%u.n",MMS_CACHE_PUSH_FOLDER, (unsigned int)(g_MmsCachePushInfo.MmsNextPushId - g_MmsCachePushInfo.MmsNoOfCachedPush ));
        MSF_FILE_REMOVE(filename);                        
        g_MmsCachePushInfo.MmsNoOfCachedPush--;
        mmsUpdateCachePushInfo(&g_MmsCachePushInfo);        
    }
    sprintf((char*)filename, "%s\\%u.n",MMS_CACHE_PUSH_FOLDER, (unsigned int)(g_MmsCachePushInfo.MmsNextPushId));    
    MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, "mmsWritePushToCache(%s)", filename));

    filehandle = MSF_FILE_OPEN( MSF_MODID_MMS, filename, openMode, 0);
    if(filehandle >= 0)
    {
#ifdef __MMS_DUAL_SIM_SUPPORT__
        result = MSF_FILE_WRITE(filehandle,(char *)&simId, 4);		
        if(result == 4)
        {
            result = MSF_FILE_WRITE(filehandle,(char *)data, dataLen);
            if(result != dataLen)
            {
                MSF_FILE_CLOSE(filehandle);
                MSF_FILE_REMOVE(filename);
            }
            else
            {
                MSF_FILE_CLOSE(filehandle);
            }
        }      
        else
        {
            MSF_FILE_CLOSE(filehandle);
            MSF_FILE_REMOVE(filename);
        }        
#else        
        result = MSF_FILE_WRITE(filehandle,(char *)data, dataLen);		
        if(result != dataLen)
        {
            MSF_FILE_CLOSE(filehandle);
            MSF_FILE_REMOVE(filename);
        }
        else
        {
            MSF_FILE_CLOSE(filehandle);
        }
#endif /*__MMS_DUAL_SIM_SUPPORT__*/
        g_MmsCachePushInfo.MmsNextPushId++;
        g_MmsCachePushInfo.MmsNoOfCachedPush++;
        mmsUpdateCachePushInfo(&g_MmsCachePushInfo);
    }
    mmsUpdateIndicator();
#endif /* __MMS_CACHE_PUSH__ */
}

/************************************************************************
* FUNCTION                                                            
*	mmsGetOnePushFromCache(void)
*
* DESCRIPTION                                                           
*	It is used to get one push from file if it exists
*
* CALLS  
*                           
* PARAMETERS
*   data    Push content
*   dataLen The length of push content
* RETURNS
* GLOBALS AFFECTED
* 	TRUE or FALSE
*************************************************************************/
#ifdef __MMS_DUAL_SIM_SUPPORT__
MSF_BOOL mmsGetOnePushFromCache(
            MSF_UINT8 **data,
            MSF_UINT32 *dataLen,
            MSF_UINT32 *simId)
#else
MSF_BOOL mmsGetOnePushFromCache(
            MSF_UINT8 **data,
            MSF_UINT32 *dataLen)            
#endif
{
#ifdef __MMS_CACHE_PUSH__
    int type;
    int size;
    int i = 0;
    int result = -1;
    char filename[20] = {0};

    if (g_MmsCachePushInfo.MmsNextPushId == 0)
    {
        mmsRestoreCachePushInfo();
    }
    if (g_MmsCachePushInfo.MmsNoOfCachedPush == 0)
    {
        return FALSE;
    }
    while (MSF_FILE_READ_DIR(MMS_CACHE_PUSH_FOLDER, i, filename, 20, &type, &size) == MSF_FILE_OK)
    {
        if (strstr(filename,".n"))
        {
            int filehandle;         
            int openMode = MSF_FILE_SET_RDONLY; 
            char *filepath = NULL;
            filepath = MMS_ALLOC(512);
            ASSERT(filepath);

            *dataLen = size;
            *data = MMS_ALLOC(size);
            ASSERT(*data);

            sprintf((char*)filepath, "%s\\%s", MMS_CACHE_PUSH_FOLDER, filename);
            MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, "mmsGetOnePushFromCache(%s)", filepath));
            filehandle = MSF_FILE_OPEN( MSF_MODID_MMS, filepath, openMode, 0);
            if(filehandle >= 0)
            {
#ifdef __MMS_DUAL_SIM_SUPPORT__
                result = MSF_FILE_READ(filehandle,(char *)simId, 4);                
                if (size >= 4)
                {
                    size -= 4;
                    *dataLen = size;
                }
#endif
                result = MSF_FILE_READ(filehandle,(char *)*data, size);		
                MSF_FILE_CLOSE(filehandle);
                MSF_FILE_REMOVE(filepath);
              	g_MmsCachePushInfo.MmsNoOfCachedPush--;
               	mmsUpdateCachePushInfo(&g_MmsCachePushInfo);
                if(result == size)
                {
                    return TRUE;
                }
                else
                {
                    MMS_FREE(*data);
                    *data = NULL;
                    size = 0;
                    MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, "drop one cached mms push"));
                }
            }   
            else
            {
                ASSERT(0);
            }
        }
        i++; 
    }  
#endif /* __MMS_CACHE_PUSH__ */    
    return FALSE;
}

/************************************************************************
* FUNCTION                                                            
*	mmsGetFreeSpace(void)
*
* DESCRIPTION                                                           
*	It is used to get disk free size for MMS storage
*
* PARAMETERS
* RETURNS
*   Free size in bytes
* GLOBALS AFFECTED
*************************************************************************/
MSF_UINT32 mmsGetFreeSpace(void)
{
    return (MSF_UINT32)msm_get_disk_free_space(WAP_STORAGE_MMS);
}

/*************************************************************
 FUNCTION                                                            
	MMSa_start

 DESCRIPTION                                                           
   To start MMS adaptor layer
   
 PARAMETERS
	None
 RETURNS
   None	

 GLOBALS AFFECTED
**************************************************************/
void MMSa_start()
{
  MMSa_resetProgressStatus();
  copyMmsTemplates(FALSE);
  mmsCusCfgInit();
#ifdef __MMS_CACHE_PUSH__
  mmsRestoreCachePushInfo();
#endif
#ifdef JPG_ENCODE
  /* Do not wait til directoryCleanup() in Fldmgr.c, cuz resized filename may cause buffer overflow in it */
  meaCleanupResizedFiles();  
#endif
}

/************************************************************************
* FUNCTION                                                            
*  mmsa_get_max_mms_get_retry_num
* DESCRIPTION                                                           
*  This function is to get customized retry time except for CSD case.
* PARAMETERS
*  void
* RETURNS
*  void
*************************************************************************/
int mmsa_get_max_mms_get_retry_num(void)
{
#ifdef __MMS_DUAL_SIM_SUPPORT__
    int retry = ((HDIa_networkAccountGetBearer(mmsWapGetCurrentAccountId()) == HDI_SOCKET_BEARER_GSM_CSD) ?
        0 : wap_custom_get_max_mms_get_retry_nums());
#else
    int retry = ((HDIa_networkAccountGetBearer(cfgGetInt(MMS_CFG_NETWORK_ACCOUNT)) == HDI_SOCKET_BEARER_GSM_CSD) ?
        0 : wap_custom_get_max_mms_get_retry_nums());
#endif
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_93D532AA37A1CA00F898E5C2475FA8E6, "mmsa_get_max_mms_get_retry_num() = %d", retry));
    return retry;
}

/************************************************************************
* FUNCTION                                                            
*  mmsa_get_max_mms_post_pdu_retry_num
* DESCRIPTION                                                           
*  This function is to get customized retry time except for CSD case.
* PARAMETERS
*  void
* RETURNS
*  void
*************************************************************************/
int mmsa_get_max_mms_post_pdu_retry_num(void)
{
#ifdef __MMS_DUAL_SIM_SUPPORT__
    int retry = ((HDIa_networkAccountGetBearer(mmsWapGetCurrentAccountId()) == HDI_SOCKET_BEARER_GSM_CSD) ?
        0 : wap_custom_get_max_mms_post_pdu_retry_nums());
#else
    int retry = ((HDIa_networkAccountGetBearer(cfgGetInt(MMS_CFG_NETWORK_ACCOUNT)) == HDI_SOCKET_BEARER_GSM_CSD) ?
        0 : wap_custom_get_max_mms_post_pdu_retry_nums());
#endif
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_E4ADD0BEFDF7883106E54A9DFB13D298, "wap_custom_get_max_mms_post_pdu_retry_nums() = %d", retry));
    return retry;
}

/************************************************************************
* FUNCTION                                                            
*  mmsa_get_max_mms_post_msg_retry_num
* DESCRIPTION                                                           
*  This function is to get customized retry time except for CSD case.
* PARAMETERS
*  void
* RETURNS
*  void
*************************************************************************/
int mmsa_get_max_mms_post_msg_retry_num(void)
{
#ifdef __MMS_DUAL_SIM_SUPPORT__
    int retry = ((HDIa_networkAccountGetBearer(mmsWapGetCurrentAccountId()) == HDI_SOCKET_BEARER_GSM_CSD) ?
        0 : wap_custom_get_max_mms_post_msg_retry_nums());
#else
    int retry = ((HDIa_networkAccountGetBearer(cfgGetInt(MMS_CFG_NETWORK_ACCOUNT)) == HDI_SOCKET_BEARER_GSM_CSD) ?
        0 : wap_custom_get_max_mms_post_msg_retry_nums());
#endif
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMS, MMS_AAPP_E4ADD0BEFDF7883106E54A9DFB13D298, "wap_custom_get_max_mms_post_pdu_retry_nums() = %d", retry));
    return retry;
}


#ifdef __MMS_DUAL_SIM_SUPPORT__
void mmsa_update_sim_status( MSF_UINT8 sim_status, MSF_UINT8 sim_setting_mode)
{
    MSF_BOOL show_imm_notif_sim_master = FALSE;
    MSF_BOOL show_imm_notif_sim_slave = FALSE;

    status_sim_master = FALSE;
    status_sim_slave = FALSE;
    
    if (sim_status == WAP_SIM_ID_SIM1 && 
        (sim_setting_mode == WAP_SIM_ID_SIM1 ||
         sim_setting_mode == WAP_SIM_ID_DUAL_SIM))
    {
        /*SIM 1 is valied*/
        status_sim_master = TRUE;        
    }
    else if (sim_status == WAP_SIM_ID_SIM2 && 
             (sim_setting_mode == WAP_SIM_ID_SIM2 ||
              sim_setting_mode == WAP_SIM_ID_DUAL_SIM))
    {
        /*SIM 2 is valid*/
        status_sim_slave = TRUE;        
    }
    else if (sim_status == WAP_SIM_ID_DUAL_SIM)
    {
        if (sim_setting_mode == WAP_SIM_ID_SIM1)
        {
            /*SIM 1 is valied*/
            status_sim_master = TRUE;
        }
        else if (sim_setting_mode == WAP_SIM_ID_SIM2)
        {
            /*SIM 2 is valied*/
            status_sim_slave = TRUE;            
        }
        else if (sim_setting_mode == WAP_SIM_ID_DUAL_SIM)
        {
            /*Both of SIM1 and SIM2 are valied*/
            status_sim_master = TRUE;
            status_sim_slave = TRUE;
        }
        else
        {
            status_sim_master = FALSE;
            status_sim_slave = FALSE;
        }
    }
    else
    {
        status_sim_master = FALSE;
        status_sim_slave = FALSE;
    }
    MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM,
        MSF_MODID_MMS,
        "Update Sim Status, Sim1:%d,Sim2:%d", 
        status_sim_master, 
        status_sim_slave));

    if (status_sim_master == FALSE)
    {
        show_imm_notif_sim_master = TRUE;
    }
    if (status_sim_slave == FALSE)
    {
        show_imm_notif_sim_slave = TRUE;
    }    
} /* MMSlib_updateSimStatus */

MSF_BOOL mmsa_get_sim_status( MmsSimCardEnum simId)
{
    switch(simId)
    {
        case MMS_SIM_CARD_MASTER:
            return status_sim_master;
        case MMS_SIM_CARD_SLAVE:
            return status_sim_slave;
        default:
            ASSERT(0);
            break;
    }
} /* MMSlib_getSimStatus */
#endif /*__MMS_DUAL_SIM_SUPPORT__*/