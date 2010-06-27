#ifdef __SF_APPLICATION_PLATFORM__ENABLE__

#include "MMI_features.h"
#include <SFApi.h>

#include "PixtelDataTypes.h"
//#include "SFGameSimuDef.h"

#include "gdi_datatype.h"
#include "lcd_sw_inc.h"
#include "wgui.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "historygprot.h"
#include "GlobalDefs.h"
#include "SettingProfile.h"
#include "Ucs2prot.h"
#include "fs_type.h"
#include "DebugInitDef.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "lcd_if.h"
#include "GameFramework.h"
#include "FileMgr.h"
#include "FileManagerDef.h"
#include "CommonScreens.h"
#include "FunAndGamesDefs.h"
#include "gdi_include.h"
#include "DataAccountGProt.h"
#include "gui.h"
#include "GlobalMenuItems.h"
#include "PixtelDataTypes.h"
#include "app_datetime.h"
#include "SMSApi.h"
#include "MessagesResourceData.h"
#include "MessagesMiscell.h"
#include "wgui_categories.h"
#include "SettingProfile.h"
#include "FileManagerGProt.h"

#include "wapadp.h"
#include "soc_api.h"
#include "app2soc_struct.h"

#include "SettingProfile.h"
#include "kal_trace.h"    
#include "wap_ps_struct.h"

#include "AlarmFrameworkProt.h"
#include "ProfileGprots.h"
#include "SimDetectionGprot.h"


//如果这个不存在则删除之，任何文件头都这样
//#include "VdoEdtDefs.h"


#ifndef MMI_ON_HARDWARE_P
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#endif

#include "NVRAMType.h"
#include "NVRAMProt.h"
#include "NVRAMEnum.h"
#include "app_datetime.h"

#include "med_global.h" 
#include "med_utility.h" 
#include "mdi_video.h" 

#include "sfapp_custom.h"
#include "sfapp_res.h"

#define dbg_cache0()    
//dbg_cache0_(__LINE__)

//void dbg_cache0_(int v);

extern void sf_dbgprintf(const UChar* msg,...);
extern int sf_strlen(const UChar*str);
extern UChar* sf_strcat(UChar*buf,const UChar* str);
extern void sf_strcpy(UChar*buf,const UChar*str);
extern int sf_strcmp(const UChar*str1,const UChar* str2);

extern UChar* sf_vfs_alloc_path_cache(SFSize_T sz);
extern void sf_vfs_free_path_cache(UChar* path);

extern int sf_vfs_repare_dir(const UChar* path);
extern void sf_vfs_path_get_dir(UString path,UChar* dir);





SFReason SFSystem_GetModNameByModId(SFModId modid,UString* name);
SFReason SFSystem_GetPathByModuleId(SFModId modid,UString* path);
static void SFSystem_DeleteAppConfig(SFModId modid);



typedef struct _SFAppPlatCustomItem
{
    const UI_character_type* iCaption;
    const UI_character_type* iLabel;
    void (* cbActive)(void);
    void * dummy;
} SFAppPlatCustomItem;

#if defined(__SF_APPLICATION_PLATFORM__INTEGRATE_OTHER_APPS__)

#ifdef __SF_MTK_APPLICATION_STOCK__ENABLE__
extern void SFStockEntry(void);
extern const UChar* SFStock_GetAppName(int lang);

  #define _A0   1
#else
  #define _A0   0
#endif 
#ifdef __SF_MTK_APPLICATION_MAJIANG__ENABLE__
extern const UChar* SFMajiang_GetAppName(int lang);
extern void SFMajiangEntry(void);

  #define _A1   1
#else
  #define _A1   0
#endif
#ifdef __SF_MTK_APPLICATION_RABBIT__ENABLE__
extern void SFRabbitEntry(void);
const UChar* SFRabbit_GetAppName(int lang);
  #define _A2   1
#else
  #define _A2   0
#endif

#ifdef __SF_MTK_APPLICATION_KNIGHT__ENABLE__
extern void SFKnightEntry(void);
const UChar* SFKnight_GetAppName(int lang);
  #define _A3   1
#else
  #define _A3   0
#endif


#if defined(__SF_MTK_APPLICATION_STOCK__ENABLE__) || defined(__SF_MTK_APPLICATION_MAJIANG__ENABLE__) || defined(__SF_MTK_APPLICATION_RABBIT__ENABLE__) || defined(__SF_MTK_APPLICATION_RABBIT__ENABLE__)
  #define SFCUST_APP_PLAT_EXT_ITEMS  (_A0+_A1+_A2+_A3)
#endif

#endif //__SF_APPLICATION_PLATFORM__INTEGRATE_OTHER_APPS__


#ifdef SFCUST_APP_PLAT_EXT_ITEMS
  #define __SFCUST_APP_PLAT_EXT_ITEMS   SFCUST_APP_PLAT_EXT_ITEMS
extern const SFAppPlatCustomItem* SFAppPlat_GetCustomItemList(void);

#else
  #define __SFCUST_APP_PLAT_EXT_ITEMS   0
#endif //SFCUST_APP_PLAT_EXT_ITEMS


extern UI_string_type sfap_get_text(int id);
extern int sf_sprintf(UChar* buf,const UChar *fmt,...);


extern const UChar g_SFAPManufactureString[];

static SFAppPlatformSysInfo s_psinfo[]=
{
    {
        g_SFAPManufactureString,
        ""
    }
};

//configurable words 
static SFAppPlatformSysInfo2 s_psinfo2[]=
{
    {
        SFCUST_WAP_ACCOUNT,
        SFCUST_NET_ACCOUNT
    }
};


#if 0
static void SFSystem_GetIMEIRsp(void* imei)
{
    mmi_nw_get_imei_rsp_struct*pimei=(mmi_nw_get_imei_rsp_struct*)imei;
    ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_IMEI_RSP);
    if(pimei->result)
    {
        memcpy(s_imei_ptr,pimei->imei,SF_IMEI_LENGTH);
        if(s_get_imei_reason)
            *s_get_imei_reason=SF_REASON_OK;
    }
    else
    {
        if(s_get_imei_reason)
            *s_get_imei_reason=SF_REASON_FAIL;
    }
}

void SFSystem_GetIMEI(char* pIMEI,SFReason* pReason)
{
#ifdef MMI_ON_HARDWARE_P
        MYQUEUE Message;
#endif
    ASSERT(pIMEI!=NULL);
    ASSERT(pReason!=NULL);
    
    *pReason=SF_REASON_BUSY;
    s_get_imei_reason=pReason;
    s_imei_ptr=pIMEI;
       
#ifdef MMI_ON_HARDWARE_P
    Message.oslMsgId = MSG_ID_MMI_NW_GET_IMEI_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr= NULL;
    Message.oslSrcId=MOD_MMI;
    Message.oslDestId=MOD_L4C;
    OslMsgSendExtQueue(&Message);
    SetProtocolEventHandler (SFSystem_GetIMEIRsp, MSG_ID_MMI_NW_GET_IMEI_RSP);
#else
        /* dammy IMEI code */
    *pReason=SF_REASON_OK;
    memset(pIMEI,0,SF_IMEI_LENGTH);
#endif    

}
#endif

const SFAppPlatformSysInfo* SFAppPlatformGetSysInfo(void)
{
    return s_psinfo;
}

const SFAppPlatformSysInfo2* SFAppPlatformGetSysInfo2(void)
{
    return s_psinfo2;
}


extern void SFOS32_SetLastError(int err);
extern int SFOS32_GetLastError(void);

static const char s_AppDirPath[]="Application\\";
extern UChar g_sfos32_loadapp_path[];
#define DEFAULT_APP_DRV MMI_PUBLIC_DRV

#ifdef SFCUST_SFAPP_PLAT_RT_MEM_SIZE
  #define SFAPP_PLAT_RT_MEM_SIZE      SFCUST_SFAPP_PLAT_RT_MEM_SIZE 
#else
  #define SFAPP_PLAT_RT_MEM_SIZE      800 
#endif
  
SFSize_T SFAppPlatform_GetPlatformMEM(void)
{
    return SFAPP_PLAT_RT_MEM_SIZE;
}


enum
{
    SFAPP_PARAM_NONE=0,
    SFAPP_PARAM_HEAP_SIZE=1,
    SFAPP_PARAM_ENABLE_KEY=2,
    SFAPP_PARAM_ENABLE_TOUCH=3,
    SFAPP_PARAM_ENABLE_KEYPAD=4,
    SFAPP_PARAM_FAST_SCREEN_UPDATE=5,
    SFAPP_PARAM_STATIC_HEAP=6
};

ISFApplication* SFOS32_LoadAppEntry(void);



#if 0
static BOOL SFOS32_GetDiskPath(PS8 drv_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (FS_NO_ERROR == FS_GetDevStatus(DEFAULT_APP_DRV ,FS_MOUNT_STATE_ENUM))
    {
        sprintf(buf, "%c:\\%s", (U8)DEFAULT_APP_DRV,s_AppDirPath);
        AnsiiToUnicodeString(drv_buf, buf);
        return TRUE;
    }
    else
    {
        U16 drv = (U16) MMI_PUBLIC_DRV;

        if (FS_NO_ERROR != FS_GetDevStatus(drv ,FS_MOUNT_STATE_ENUM))
            return FALSE;

        sprintf(buf, "%c:\\%s", (U8)drv,s_AppDirPath );
        AnsiiToUnicodeString(drv_buf, buf);
        return TRUE;
    }   
}


void SFOS32_RunAppEntry(void)
{
    FS_HANDLE hDir=-1;
    S8 path[128];
    if(SFOS32_GetDiskPath((PS8)path))
    {
        hDir=FS_Open((const WCHAR*)path,FS_OPEN_DIR|FS_READ_ONLY);
        if(hDir<0)
        {
            //try to create the dir
            FS_CreateDir((const WCHAR*)path);
            hDir=FS_Open((const WCHAR*)path,FS_OPEN_DIR|FS_READ_ONLY);
        }
    }
    
    if(hDir>=0)
    {
        FMGR_FILTER filter;
        FS_Close(hDir);
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET(&filter,FMGR_TYPE_APP);//select *.*
        
        mmi_fmgr_select_path_and_enter(APP_GAMES,FMGR_SELECT_FILE,filter,path,(PsExtFuncPtr)SFOS32_AppEntry);
    }
    else
    {
        DisplayPopup((PU8) GetString(FMGR_FS_PATH_NOT_FOUND_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
    }
}
#endif //0

/*
字符串格式:
LEN: UINT16 包含0结尾
CHARS: UCHAR[LEN]
*/
static BOOL _SkipString(FS_HANDLE hFile)
{
    UINT s=0,sz=0;
    if(FS_Read(hFile,&s,2,&sz)<0 
        || sz<2)
    {
        return FALSE;
    }
    if(FS_Seek(hFile,s*2,FS_FILE_CURRENT)<0)
        return FALSE;
    return TRUE;
}

static BOOL _ReadString(FS_HANDLE hFile,WCHAR* buf,int limit)
{
    UINT s=0,sz=0;
    if(!buf)
        return _SkipString(hFile);
    if(FS_Read(hFile,&s,2,&sz)<0 
        || sz<2)
    {
        return FALSE;
    }
    if(s>limit)
    {
        return FALSE;
    }
    if(FS_Read(hFile,buf,2*s,&sz)<0 
        || sz<2*s)
    {
        return FALSE;
    }
    return TRUE;
}

//仅仅用于独立app形式的应用
struct _AppDescExInfo;
typedef struct _AppDescExInfo AppDescExInfo;
struct _AppDescExInfo
{
    SFUint32 AppExInfoMagic;
    SFUint32 AppId[2];
    SFUint32 AppVersion;//A.B.C.D
    SFUint32 AppPlatformVersion;//目标平台Version
    SFUint32 AppAPIVersion;//目标API Version
    SFUint32 AppDisplaySize;//高位h，低位w，如果自适应则为0
    SFUint32 AppMem;//内存需求，单位k ，0表示不限
    SFUint32 AppFeature;//见SFAppPlatformFeatures，必须匹配才能执行
    SFUint32 AppDetailedFeatures;//count,below will be the ext feature list, not used in this version
};


static void _AppendHash(SFUint32 hash[2],const void* ptr,SFSize_T sz)
{
    const SFUint8* p=(const SFUint8*)ptr;
    SFUint64 v=((SFUint64)hash[0])|(((SFUint64)hash[1])<<32);
    while(sz>0)
    {
        v^=*p;
        v=(v<<3)|(v>>61);
        ++p;
        --sz;
    }
    hash[0]=(SFUint32)v;
    hash[1]=(SFUint32)(v>>32);
}

/*
信息被附加在了文件有效数据的尾部
先是4个字节的magic
然后是4个字符串，分别是
中文短名
中文描述
英文短名
英文描述
*/
BOOL SFOS32_GetApkDescEx(const WCHAR* path,int lang,WCHAR name[32],WCHAR desc[256],AppDescExInfo* info);

/**
 * @brief 获取文件信息
 * @param path - UNICODE 编码的路径
 * @param lang - 语言ID，0为英文，1为中文
 * @param name - 短的名字缓冲，最多32个UNICODE字符，含0结尾
 * @param desc - 长的名字缓冲，最多256个UNICODE字符，含0结尾
 * @return 成功与否，失败的话这应该不是一个有效的文件。 
 */
BOOL _SFOS32_GetAppDescEx(const WCHAR* path,int lang,WCHAR name[32],WCHAR desc[256],AppDescExInfo* info)
{
    FS_HANDLE hFile;
    unsigned char buf[4];
    unsigned int hdr[8];
    UINT sz;
    SFUint32 appid[2]={0,0};
    if(!path)
        return FALSE;
    

    hFile=FS_Open((const WCHAR*)path,FS_READ_ONLY);
    if(hFile<0)
        return FALSE;
    if(FS_Read(hFile,hdr,32,&sz)<0 
        || sz<32
        || (hdr[0]!=0x19414653 && hdr[0]!=0x19414654))
    {
        FS_Close(hFile);
        return FALSE;
    }
    if(hdr[0]==0x19414654)
    {
        if(FS_Read(hFile,&hdr[1],4,&sz)<0 
            || sz<4)
        {
            FS_Close(hFile);
            return FALSE;
        }
    }
    else
    {
        hdr[1]=0;
    }
    if(FS_Seek(hFile,hdr[1]+hdr[4]+hdr[5]+(hdr[7]<<2),FS_FILE_BEGIN)<0)
    {
        FS_Close(hFile);
        return FALSE;
    }
    if(FS_Read(hFile,buf,4,&sz)<0 
        || sz<4
        || buf[0]!=0x19
        || buf[1]!=0x82
        || buf[2]!=12
        || buf[3]!=19)
    {
        FS_Close(hFile);
        return FALSE;
    }
    if(info)
    {
        UChar desc[256];
        memset(desc,0,sizeof(desc));
        if(_ReadString(hFile,desc,32))
        {
            _AppendHash(appid,desc,32*sizeof(UChar));
            if(_ReadString(hFile,desc,256))
            {
                _AppendHash(appid,desc,256*sizeof(UChar));
                if(_ReadString(hFile,desc,32))
                {
                    _AppendHash(appid,desc,32*sizeof(UChar));
                    if(_ReadString(hFile,desc,256))
                    {
                        _AppendHash(appid,desc,256*sizeof(UChar));
                    }
                }
            }
        }
        appid[0]=appid[0]^appid[1];
        appid[1]=0xFFFFFFFF;
    }
    else
    {
        if(lang==1)//chinese 
        {
            if(!_ReadString(hFile,name,32)
                || !_ReadString(hFile,desc,256))
            {
                FS_Close(hFile);
                return FALSE;
            }
        }
        else
        {
            if(!_SkipString(hFile) 
                || !_SkipString(hFile))
            {
                FS_Close(hFile);
                return FALSE;
            }
            if(!_ReadString(hFile,name,32)
                || !_ReadString(hFile,desc,256))
            {
                FS_Close(hFile);
                return FALSE;
            }
        }
    }
    if(info)
    {
        //try to read the ext info
        sz=0;
        FS_Read(hFile,info,sizeof(AppDescExInfo),&sz);
        if(sz!=sizeof(AppDescExInfo))
        {
            memset(info,0,sizeof(AppDescExInfo));
            memcpy(info->AppId,appid,8);
        }

    }
    FS_Close(hFile);
    
    
    return TRUE;
}


BOOL SFOS32_GetAppManifestItem(const WCHAR* path,const char* item,void* buf,SFSize_T sz)
{
    //sf_dbgprintf(L"SFOS32_GetAppManifestItem %s %S %s",path,item,path+sf_strlen(path)-4);
    if(sf_stricmp(path+sf_strlen(path)-4,L".apk")==0)
    {
        //SFDEBUG("SFOS32_GetAppManifestItem 1");
        return SFOS32_GetApkManifestItem(path,item,buf,sz);
    }
    else
    {
        AppDescExInfo info;
        int lang=SFSystem_GetLanguageId();
        //SFDEBUG("SFOS32_GetAppManifestItem 2");
        if(strcmp(item,APK_MANIFEST__MOD_NAME)==0)
        {
            return _SFOS32_GetAppDescEx(path,lang,(WCHAR*)buf,NULL,NULL);
        }
        else if(strcmp(item,APK_MANIFEST__MOD_DESC)==0)
        {
            return _SFOS32_GetAppDescEx(path,lang,NULL,(WCHAR*)buf,NULL);
        }
        else if(strcmp(item,APK_MANIFEST__MOD_ID)==0)
        {
            if(! _SFOS32_GetAppDescEx(path,lang,NULL,NULL,&info))
                return FALSE;
            sf_memcpy(buf,info.AppId,sizeof(SFCLSID));
            return TRUE;
        }
        else
        {
            return FALSE;
        }
    }
}


#define SFAPP_PLAT_NAME_LEN 32
#ifdef SFCUST_SFAPP_PLAT_DEFAULT_DRV
 #define SFAPP_PLAT_DEFAULT_DRV  SFCUST_SFAPP_PLAT_DEFAULT_DRV
#else
 #define SFAPP_PLAT_DEFAULT_DRV  FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_DRIVE_V_NORMAL|FS_DRIVE_V_REMOVABLE)
#endif //SFCUST_APPPLAT_DEFAULT_DRV
#define SFAPP_PLAT_APP_FILTER   L"*.app"
#define SFAPP_PLAT_APP_LINK     sfap_get_text(SF_STR_ID_HOME_PAGE_URL)
#define SFAPP_PLAT_PATH_LEN 127


//__SFAPP_PLAT_FIRST_LIST_LINK__/__SFAPP_PLAT_LIST_LAST_LINK__
#ifndef __SFAPP_PLAT_LIST_LAST_LINK__
#define __SFAPP_PLAT_LIST_FIRST_LINK__
#else //__SFAPP_PLAT_LIST_FIRST_LINK__
#undef __SFAPP_PLAT_LIST_FIRST_LINK__
#endif

struct _SFModuleConfigData;

typedef struct _SFModuleConfigData SFModuleConfigData;
struct _SFModuleConfigData
{
    SFUint16 AppDataAccount;
};


typedef struct _SFAppPlatform
{
    //UChar iAppDirDrv;
    //U8 bDrvChanged;
    U8* iGuiBuffer;
    UChar** iNameList;
    UChar* iNamePool;
    SFInt16 nTotalItems; 
    SFInt16 iLang;
    UChar iTempText[FS_MAX_PATH];
    //UChar iAppPath[FS_MAX_PATH];
    UChar iAppName[SFAPP_PLAT_NAME_LEN];
    //UChar iSysPrivateDir[SFAPP_PLAT_PATH_LEN+1];//must not exceed 127 characters!, app private dir
    //UChar iAppDir[SFAPP_PLAT_PATH_LEN+1];//must not exceed 127 characters!,both the data dir and the config dir
    FS_DOSDirEntry iTempDosEntryInfo;
    //AppDescExInfo iExtInfo;
    SFCLSID iActiveCLSID;
    SFModuleConfigData iAppConf;
    //SFInt16 iListIter;
    SFInt16 iActiveItem;
    SFModId iActiveModId;
    SFInt16 iStorageIdx;
    UChar iStorageDrv;
    SFInt16 iOptionIdx;
    SFInt32 iDaAppSize;
    SFInt16 iLastDataAccount;
} SFAppPlatform;

static SFAppPlatform g_sfplat={NULL};//place it is zi

static const UChar s_SFAppPlatformDirPath[]=L":\\Application\\";
static const UChar s_SFAppPlatformConfigFile[]=L"sfplat.cfg";
static const UChar s_SFAppPlatformOSDir[]=L"sfos\\";
static const UChar s_SFAppPlatformAppDir[]=L"apps\\";
static const UChar s_SFAppPlatformAppDataDir[]=L"appdata\\";
static const UChar s_SFAppPlatformAppConfDir[]=L"appconf\\";//for system use 

static const UChar s_SFAppPlatformAppPrivBaseDir[]=L"private\\";
static const UChar s_SFAppPlatformAppPubDir[]=L"pub\\";
static const UChar s_SFAppPlatformAppTempDir[]=L"tmp\\";
static const UChar s_SFAppPlatformDataDir[]=L"data\\";


extern int SFSystem_InitSecureRecords(void);
void sf_vfs_prepare_drivers(void);

extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
extern PU8 subMenuDataPtrs[MAX_SUB_MENUS];

extern void* sf_system_malloc(unsigned int size);
extern void sf_system_free(void*ptr);

#ifndef SFAppPlat_Malloc
#define SFAppPlat_Malloc(size)    sf_system_malloc(size)
#endif //!SFAppPlat_Malloc

#ifndef SFAppPlat_Free
#define SFAppPlat_Free(p)         sf_system_free(p)
#endif //!SFAppPlat_Free



int SFAppPlatform_GetAppDataAccount(void)
{
    return g_sfplat.iAppConf.AppDataAccount;
}

static int SFAppPlatform_MakeOSConfigFile(UChar* path_dir);


void SFAppPlatform_SaveConfig(SFAppPlatform* self)
{
    FS_HANDLE hFile;
    //U32 sz=0;
    UChar path[FS_MAX_PATH];
    //if(!self->bDrvChanged)
    //    return;
    
    SFAppPlatform_MakeOSConfigFile(path);
    hFile=FS_Open(path,FS_READ_WRITE|FS_CREATE);
    
    if(hFile>=0)
    {
    //    FS_Write(hFile,&self->iAppDirDrv,sizeof(self->iAppDirDrv),&sz);
        FS_Close(hFile);
    }
    //self->bDrvChanged=0;
}




void SFAppPlatform_LoadConfig(SFAppPlatform* self)
{
    FS_HANDLE hFile;
    //U32 sz=0;
    UChar path[FS_MAX_PATH];

    SFAppPlatform_MakeOSConfigFile(path);
    hFile=FS_Open(path,FS_READ_ONLY);
    
    if(hFile>=0)
    {
        //ok
        
        //FS_Read(hFile,&self->iAppDirDrv,sizeof(self->iAppDirDrv),&sz);
        FS_Close(hFile);
    }
    //if(sz<sizeof(self->iAppDirDrv))
    //{
        //self->bDrvChanged=1;
        //self->iAppDirDrv=SFAPP_PLAT_DEFAULT_DRV;
    //    SFAppPlatform_SaveConfig(self);
    //}
    //self->bDrvChanged=0;
    
}



int SFSystem_GetAppDir(SFModId modid,UChar* path)
{
    UString mod_path;
    int r;
    if((r=SFSystem_GetPathByModuleId(modid,&mod_path))!=SFReasonOK)
    {
        *path=0;
        return r;
    }
    sf_vfs_path_get_dir(mod_path,path);
    return SFReasonOK;
}

//void SFAppPlatform_GetAppDirPathFilter(UChar* path)
//{
//    sf_sprintf(path,L"%c%s%s",g_sfplat.iAppDirDrv==0?SFAPP_PLAT_DEFAULT_DRV:g_sfplat.iAppDirDrv,s_SFAppPlatformDirPath,SFAPP_PLAT_APP_FILTER);
//}

struct _SFModIterator;
typedef struct _SFModIterator SFModIterator;
struct _SFModIterator
{
    void* iParam;
    UString iDir;
    SFInt16 iIter;
};

static const UChar* const s_app_filters[]=
{
    L"*.apk",
    L"*.app",
    NULL
};

extern UChar g_sf_local_drv;
extern UChar g_sf_card_drv;
extern UChar g_sf_sys_drv;


int SFModIterator_ListInDir(SFModIterator* iter,UString dir,int (*cbOnFile)(SFModIterator* iter,FS_DOSDirEntry* pinfo,UChar* fn))
{
    int i;
    FS_DOSDirEntry info;
    int hFind;
    int bFind=0;
    int r=0;
    
    UChar* filter=sf_vfs_alloc_path_cache(FS_MAX_PATH);
    UChar* fname=sf_vfs_alloc_path_cache(FS_MAX_PATH);

    iter->iDir=dir;
    
    for(i=0;!bFind && s_app_filters[i]!=SFNull;i++)
    {
        sf_sprintf(filter,L"%s%s",dir,s_app_filters[i]);
        //sf_dbgprintf(L"list %s",filter);
        hFind=FS_FindFirst(filter,0,0,&info,fname,256);
        if(hFind>=0)
        {
            int res=FS_NO_ERROR;
            while(res==FS_NO_ERROR)
            {
                if( (info.Attributes & (FS_ATTR_DIR|FS_ATTR_HIDDEN))==0)
                {
                    ++iter->iIter;
                    //add to list
                    if(cbOnFile)
                    {
                        int rr;
                        if((rr=(*cbOnFile)(iter,&info,fname))!=0)
                        {
                            bFind=1;
                            r=rr;
                            break;
                        }
                    }
                    
                }
                res=FS_FindNext(hFind,&info,fname,256);
                
            }
            FS_FindClose(hFind);
        }
    }
    sf_vfs_free_path_cache(filter);
    sf_vfs_free_path_cache(fname);
    return r;
}

int SFModIterator_ListAll(SFModIterator* iter,int (*cbOnFile)(SFModIterator* iter,FS_DOSDirEntry* pinfo,UChar* fn))
{
    UChar dir[32];
    int r;
    //search all the path
    if(g_sf_local_drv!=0 && g_sf_local_drv!=0xFF)
    {
        sf_sprintf(dir,L"%c%s",g_sf_local_drv,s_SFAppPlatformDirPath);
        if((r=SFModIterator_ListInDir(iter,dir,cbOnFile))>0)
            return r;
    }
    if(g_sf_card_drv!=0 && g_sf_card_drv!=0xFF)
    {
        sf_sprintf(dir,L"%c%s",g_sf_card_drv,s_SFAppPlatformDirPath);
        if((r=SFModIterator_ListInDir(iter,dir,cbOnFile))>0)
            return r;
    }
    return 0;
}


int SFAppPlatform_PrepareAppListSpace(SFAppPlatform* self)
{
    if(self->nTotalItems>MAX_SUB_MENUS)
    {
        int i;
        //alloc new data
        self->iNamePool=(UChar*)SFAppPlat_Malloc((sizeof(UChar)*SFAPP_PLAT_NAME_LEN+sizeof(UChar*)+8)*self->nTotalItems);
        if(!self->iNamePool)
        {
            //show only the first MAX_SUB_MENUS items
            self->nTotalItems=MAX_SUB_MENUS;
        }
        else
        {
            self->iNameList=(UChar**)(((char*)self->iNamePool)+sizeof(UChar*)*self->nTotalItems);
            for(i=0;i<self->nTotalItems;i++)
            {
                self->iNameList[i]=self->iNamePool+i*(SFAPP_PLAT_NAME_LEN+4);
            }
        }
    }
    if(!self->iNamePool)
    {
        //use subMenuDataPtrs
        self->iNameList=(UChar**)subMenuDataPtrs;
        self->iNamePool=NULL;
    }
    return 0;
}

static int CB_GenerateAppList(SFModIterator* iter,FS_DOSDirEntry* pinfo,UChar* fn)
{
    SFAppPlatform* self=(SFAppPlatform*)iter->iParam;
    UChar info[SFAPP_PLAT_NAME_LEN];
    //AppDescExInfo exinfo;
    SFCLSID clsid;
    int idx;
#ifdef __SFAPP_PLAT_LIST_FIRST_LINK__
    if(iter->iIter>=self->nTotalItems-__SFCUST_APP_PLAT_EXT_ITEMS)
        return -1;
    idx=iter->iIter+__SFCUST_APP_PLAT_EXT_ITEMS;
#else
    if(iter->iIter>=self->nTotalItems-__SFCUST_APP_PLAT_EXT_ITEMS)
        return -1;
    idx=iter->iIter-1+__SFCUST_APP_PLAT_EXT_ITEMS;
#endif

    sf_sprintf(self->iTempText,L"%s%s",iter->iDir,fn);

    
    if(!SFOS32_GetAppManifestItem(self->iTempText,APK_MANIFEST__MOD_ID,&clsid,8))
    {
        --iter->iIter;
        return 0;
    }
    if(!SFOS32_GetAppManifestItem(self->iTempText,APK_MANIFEST__MOD_NAME,info,32))
    {
        //sf_strncpy(self->iNameList[idx],fn);
        //sf_dbgprintf(iter->iDir);
        //sf_dbgprintf(fn);
        
        --iter->iIter;
        return 0;
    }
    
        
    //sf_dbgprintf(info);
    memcpy(self->iNameList[idx],info,sizeof(UChar)*(sf_strlen(info)+1));
    //sf_strcpy(self->iNameList[idx],info);
    //sf_dbgprintf(L"%s {%08x%08x}",self->iTempText,exinfo.AppId[1],exinfo.AppId[0]);
    
    memcpy(self->iNameList[idx]+SFAPP_PLAT_NAME_LEN,&clsid,8);
    return 0;
}

static int CB_GenerateAppListCount(SFModIterator* iter,FS_DOSDirEntry* pinfo,UChar* fn)
{
    SFAppPlatform* self=(SFAppPlatform*)iter->iParam;
    UChar info[SFAPP_PLAT_NAME_LEN];
    //AppDescExInfo exinfo;
    SFCLSID clsid;

    sf_sprintf(self->iTempText,L"%s%s",iter->iDir,fn);

    
    if(!SFOS32_GetAppManifestItem(self->iTempText,APK_MANIFEST__MOD_ID,&clsid,8))
    {
        --iter->iIter;
        return 0;
    }
    if(!SFOS32_GetAppManifestItem(self->iTempText,APK_MANIFEST__MOD_NAME,info,32))
    {
        //sf_strncpy(self->iNameList[idx],fn);
        //sf_dbgprintf(iter->iDir);
        //sf_dbgprintf(fn);
        
        --iter->iIter;
        return 0;
    }

    return 0;
}



int SFAppPlatform_GenerateAppList(SFAppPlatform* self)
{
    int i;
    SFReason r;
    SFModIterator it;
    it.iIter=0;
    it.iParam=self;
    self->nTotalItems=0;
    SFModIterator_ListAll(&it,&CB_GenerateAppListCount);

    self->nTotalItems=it.iIter+1+__SFCUST_APP_PLAT_EXT_ITEMS;//add one entry for  link 
    SFAppPlatform_PrepareAppListSpace(self);

#ifdef SFCUST_APP_PLAT_EXT_ITEMS
    //create the static list
    for(i=0;i<SFCUST_APP_PLAT_EXT_ITEMS;i++)
    {
        int idx;
        const SFAppPlatCustomItem* item;
#ifdef  __SFAPP_PLAT_LIST_FIRST_LINK__
        idx=i+1;
#else  //__SFAPP_PLAT_LIST_FIRST_LINK__
        idx=i;
#endif //__SFAPP_PLAT_LIST_FIRST_LINK__
        item=&(SFAppPlat_GetCustomItemList()[i]);

        sf_strcpy(self->iNameList[idx],item->iCaption);
    }
#endif //SFCUST_APP_PLAT_EXT_ITEMS
    //add the first/last link
#ifdef __SFAPP_PLAT_LIST_FIRST_LINK__
    sf_strcpy(self->iNameList[0],(const UChar*)sfap_get_text(SF_STR_ID_MORE_APPS));
#else //__SFAPP_PLAT_LIST_FIRST_LINK__
    sf_strcpy(self->iNameList[self->nTotalItems-1],(const UChar*)sfap_get_text(SF_STR_ID_MORE_APPS));
#endif //__SFAPP_PLAT_LIST_FIRST_LINK__

    it.iIter=0;
    it.iParam=self;

    dbg_cache0();
    
    r=SFModIterator_ListAll(&it,&CB_GenerateAppList);

    dbg_cache0();
    
    return r;
}

static void SFAppPlatform_OnLeave(SFAppPlatform* self)
{
    if(self->iNamePool)
    {
        //free the data
        SFAppPlat_Free(self->iNamePool);
        //
        self->iNamePool=NULL;
        self->iNameList=NULL;
    }
    SFAppPlatform_LoadConfig(self);
}


static void SFAppPlatform_Leave(void)
{
    //save
    //iActiveItem=
    SFAppPlatform_OnLeave(&g_sfplat);
}

#if 0
static int CB_GetAppPath(void* _self,FS_DOSDirEntry* pinfo,UChar* fn)
{
    SFAppPlatform* self=(SFAppPlatform*)_self;
#ifdef __SFAPP_PLAT_LIST_FIRST_LINK__
    if(self->iListIter==self->iActiveItem-__SFCUST_APP_PLAT_EXT_ITEMS)
#else
    if(self->iListIter==self->iActiveItem+1-__SFCUST_APP_PLAT_EXT_ITEMS)
#endif
    {
        //copy the name
        sf_sprintf(self->iAppPath,L"%c%s%s",self->iAppDirDrv==0?SFAPP_PLAT_DEFAULT_DRV:self->iAppDirDrv,s_SFAppPlatformDirPath,fn);
        sf_strcpy(g_sfos32_loadapp_path,self->iAppPath);
        //sf_sprintf(g_sfos32_loadapp_path,L"%c%s%s",self->iAppDirDrv==0?SFAPP_PLAT_DEFAULT_DRV:self->iAppDirDrv,s_SFAppPlatformDirPath,fn);
        return 1;
    }
    else if(self->iListIter>=self->nTotalItems-__SFCUST_APP_PLAT_EXT_ITEMS)
    {
        return -1;
    }
    return 0;
}

#endif //0

static void SFAppPlatform_SelectOptionIdx(S32 idx)
{
    g_sfplat.iOptionIdx=(SFInt16)idx;
}

static void SFSystem_DeleteAppConfig(SFModId mod);
extern int SFSystem_ClearSecureRecordInternal(SFUint64 id);
static void PMCacheInvalidateAll(void);

static void SFAppPlatform_OnDelete(void)
{
    UString path;
    if(SFSystem_GetPathByModuleId(g_sfplat.iActiveModId,&path)!=SFReasonOK)
        return;
    if(FS_Delete(path)==FS_NO_ERROR)
    {
        //try to delete the save file
        SFSystem_ClearSecureRecordInternal(g_sfplat.iActiveModId);
        SFSystem_DeleteAppConfig(g_sfplat.iActiveModId);
        PMCacheInvalidateAll();
        
        
        sf_sprintf(g_sfplat.iTempText,(UChar*)sfap_get_text(SF_STR_ID_FMT_APP_DELETED),g_sfplat.iAppName);
        DisplayPopup(
                (PU8) g_sfplat.iTempText,
                IMG_GLOBAL_DELETED,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) SUCCESS_TONE);
    }
    else
    {
        sf_sprintf(g_sfplat.iTempText,(UChar*)sfap_get_text(SF_STR_ID_FMT_APP_DELETE_FAIL),g_sfplat.iAppName);
        DisplayPopup(
                (PU8) g_sfplat.iTempText,
                IMG_GLOBAL_ERROR,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                (U8) ERROR_TONE);
    }
    DeleteNHistory(1);
}

static void SFAppPlatform_DisplayConfirm(const UChar*msg)
{
    //gdi_layer_lock_frame_buffer();
    DisplayConfirm(
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (UI_string_type)msg,
            IMG_GLOBAL_QUESTION,
            WARNING_TONE);
    //gdi_layer_unlock_frame_buffer();
    //dm_redraw_category_screen();
}

static void SFAppPlatform_PopupDeleteConfirm(void)
{
    //U8 *guiBuffer_p;
    //EntryNewScreen(ID_SCR_SFAPP+1, NULL, SFAppPlatform_PopupDeleteConfirm, NULL);
    //guiBuffer_p = GetCurrGuiBuffer(ID_SCR_SFAPP);
    sf_sprintf(g_sfplat.iTempText,(UChar*)sfap_get_text(SF_STR_ID_FMT_APP_DELETE_CONFIRM),g_sfplat.iAppName);
    SFAppPlatform_DisplayConfirm(g_sfplat.iTempText);
    
    SetLeftSoftkeyFunction(SFAppPlatform_OnDelete, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

extern UI_string_type MMI_title_string;

static void SFAppPlatform_SetTitle(const UChar*title)
{
    MMI_title_string=(UI_string_type)title;
}


static void SFAppPlatform_PopupHelpEntry(void)
{
    U8 *guiBuffer_p;
    EntryNewScreen(ID_SCR_SFAPP+2, NULL, SFAppPlatform_PopupHelpEntry, NULL);
    guiBuffer_p = GetCurrGuiBuffer(ID_SCR_SFAPP);
    gdi_layer_lock_frame_buffer();
    ShowCategory74Screen(STR_GLOBAL_OK,0,0,0,STR_GLOBAL_BACK,0,(U8*)sfap_get_text(SF_STR_ID_HELP_CONTENT),sf_strlen((UChar*)sfap_get_text(SF_STR_ID_HELP_CONTENT)),guiBuffer_p);

    SFAppPlatform_SetTitle(sfap_get_text(SF_STR_ID_HELP));
    
    gdi_layer_unlock_frame_buffer();
    dm_redraw_category_screen();

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

static const UChar* sf_vfs_path_get_name(const UChar* path)
{
    int len=sf_strlen(path);
    for(len=len-1;len>=0;len--)
    {
        if(path[len]=='/' || path[len]=='\\')
            break;
    }
    return path+len+1;
}

static SFModId s_mod_for_detail;
static SFModId s_mod_for_about;

static void SFAppPlatform_PopupAppDetailEntry(void)
{
    U8 *guiBuffer_p;
    FS_HANDLE hFile;
    UINT fsize=0;
    UString mod_path,mod_name;
    SFSystem_GetPathByModuleId(s_mod_for_detail,&mod_path);
    SFSystem_GetModNameByModId(s_mod_for_detail,&mod_name);
    hFile=FS_Open(mod_path,FS_READ_ONLY);
    if(hFile>=0)
    {
        FS_GetFileSize(hFile,&fsize);
        FS_Close(hFile);
    }
    sf_sprintf(g_sfplat.iTempText,
        (UChar*)sfap_get_text(SF_STR_ID_FILE_DETAILS_FMT),
        mod_name,
        sfap_get_text(mod_path[0]==FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)?SF_STR_ID_DRV_MEMORY_CARD:SF_STR_ID_DRV_PHONE),
        sf_vfs_path_get_name(mod_path),
        fsize/1024
        );
    EntryNewScreen(ID_SCR_SFAPP+3, NULL, SFAppPlatform_PopupAppDetailEntry, NULL);
    guiBuffer_p = GetCurrGuiBuffer(ID_SCR_SFAPP);
    gdi_layer_lock_frame_buffer();
    ShowCategory74Screen(STR_GLOBAL_OK,0,0,0,STR_GLOBAL_BACK,0,(U8*)g_sfplat.iTempText,sf_strlen(g_sfplat.iTempText),guiBuffer_p);

    SFAppPlatform_SetTitle(sfap_get_text(SF_STR_ID_FILE_DETAILS));
    
    gdi_layer_unlock_frame_buffer();
    dm_redraw_category_screen();

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

static void SFAppPlatform_PopupAppDetail(SFModId modid)
{
    s_mod_for_detail=modid;
    SFAppPlatform_PopupAppDetailEntry();
}

static void SFAppPlatform_PopupAppAboutEntry(void)
{
    U8 *guiBuffer_p;
    UString mod_path;
    if(SFSystem_GetPathByModuleId(s_mod_for_about,&mod_path)==SFReasonOK)
    {
        g_sfplat.iTempText[0]=0;
        SFOS32_GetAppManifestItem(mod_path,APK_MANIFEST__MOD_DESC,g_sfplat.iTempText,256);
        EntryNewScreen(ID_SCR_SFAPP+4, NULL, SFAppPlatform_PopupAppAboutEntry, NULL);
        guiBuffer_p = GetCurrGuiBuffer(ID_SCR_SFAPP);
        gdi_layer_lock_frame_buffer();
        ShowCategory74Screen(STR_GLOBAL_OK,0,0,0,STR_GLOBAL_BACK,0,(U8*)g_sfplat.iTempText,sf_strlen(g_sfplat.iTempText),guiBuffer_p);

        SFAppPlatform_SetTitle(sfap_get_text(SF_STR_ID_ABOUT));
        
        gdi_layer_unlock_frame_buffer();
        dm_redraw_category_screen();

        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    }
}
static void SFAppPlatform_PopupAppAbout(SFModId modid)
{
    s_mod_for_about=modid;
    SFAppPlatform_PopupAppAboutEntry();
}

int sf_vfs_dir_exists(const UChar*path);


static int DrvExists(int drv)
{
    UChar buf[12];
    sf_sprintf(buf,L"%c:\\",drv);
    return sf_vfs_dir_exists(buf);
}

static int SFAppPlatform_GetConfigDrive(void)
{
    int drive;
    drive='Z';
    if(drive<=0 || !DrvExists(drive))
    {
        drive = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_NO_ALT_DRIVE);
        if(drive<=0 || !DrvExists(drive))
        {
            sf_dbgprintf(L"a %c",drive);
            drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
            if(drive<=0 || !DrvExists(drive))
            {
                sf_dbgprintf(L"b %c",drive);
                drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
            }
        }
    }

    return drive;
}


#define SFOS_DIR_ATTR   (FS_ATTR_HIDDEN|FS_ATTR_SYSTEM)

int SFAppPlatform_GetOSDir(UChar* path_dir)
{
    int drv=SFAppPlatform_GetConfigDrive();
    if(drv>0)
    {
        //check dirs first
        const UChar* base_dir_fmt=(drv=='Z')?L"%c:\\@%s":L"%c:\\%s";
        sf_sprintf(path_dir,base_dir_fmt,drv,s_SFAppPlatformOSDir);
        sf_dbgprintf(L"dir1 %s",path_dir);
        if(!sf_vfs_dir_exists(path_dir))
        {
            FS_CreateDir(path_dir);
            if(!sf_vfs_dir_exists(path_dir))
            {
                SFDEBUG("failed to create os dir");
                return -1;
            }
            FS_SetAttributes(path_dir,SFOS_DIR_ATTR);
        }
        else
        {
            int attr=FS_GetAttributes(path_dir);
            if(attr>=0)
            {
                if((attr&SFOS_DIR_ATTR)!=SFOS_DIR_ATTR)
                {
                    FS_SetAttributes(path_dir,SFOS_DIR_ATTR);
                }
            }
        }
        
        return 0;
    }
    else
    {
        SFDEBUG("failed to get drv");
        return -1;
    }
}

static int SFAppPlatform_MakeOSConfigFile(UChar* path_dir)
{
    if(SFAppPlatform_GetOSDir(path_dir)==0)
    {
        sf_strcat(path_dir,s_SFAppPlatformConfigFile);
        return 0;
    }
    else
    {
        return -1;
    }
}


int SFAppPlatform_GetConfigDir(UChar* path_dir)
{
    if(SFAppPlatform_GetOSDir(path_dir)==0)
    {
        sf_strcat(path_dir,s_SFAppPlatformAppConfDir);
        sf_dbgprintf(L"dir2 %s",path_dir);
        if(!sf_vfs_dir_exists(path_dir))
        {
            FS_CreateDir(path_dir);
            if(!sf_vfs_dir_exists(path_dir))
                return -1;
        }
        return 0;
    }
    else
    {
        return -1;
    }
}



int SFSystem_PrepareAppDir(SFModId modid,UChar* path,const UChar* dir)
{
    UString mod_path;
    int r;
    dbg_cache0();
    if((r=SFSystem_GetPathByModuleId(modid,&mod_path))!=SFReasonOK)
    {
        SFDEBUG("SFSystem_PrepareAppDir: Not Found");
        return r;
    }
    dbg_cache0();
    sf_vfs_path_get_dir(mod_path,path);
    dbg_cache0();
    sf_strcat(path,dir);
    return sf_vfs_repare_dir(path);
}

void SFSystem_AppendConfigName(SFModId modid,UChar* path);

int SFSystem_GetAppPrivDir(SFModId modid,UChar* path)
{
    int r=SFSystem_PrepareAppDir(modid,path,s_SFAppPlatformAppPrivBaseDir);
    if(r<0)
    {
        return r;
    }
    SFSystem_AppendConfigName(modid,path);
    sf_strcat(path,L"\\");
    return sf_vfs_repare_dir(path);
}

int SFSystem_GetAppPubDir(SFModId modid,UChar* path)
{
    return SFSystem_PrepareAppDir(modid,path,s_SFAppPlatformAppPubDir);
}

int SFSystem_GetDataDir(SFModId modid,UChar* path)
{
    return SFSystem_PrepareAppDir(modid,path,s_SFAppPlatformDataDir);
}

int SFSystem_GetAppHomeDir(SFModId modid,UChar* path)
{
    return SFSystem_GetAppDir(modid,path);
}


int SFSystem_GetAppTempDir(SFModId modid,UChar* path)
{
    return SFSystem_PrepareAppDir(modid,path,s_SFAppPlatformAppTempDir);
}

void SFSystem_AppendConfigName(SFModId modid,UChar* path)
{
    /*
    if(g_sfplat.iExtInfo.AppExInfoMagic==0)
    {
        sf_strcat(path,L"l_");
    }
    */
    sf_sprintf(path+sf_strlen(path),L"%08x%08x",(int)(modid>>32),(int)modid);
}

int SFSystem_GetAppConfDir(SFModId modid,UChar* path)
{
    int r=SFSystem_PrepareAppDir(modid,path,s_SFAppPlatformAppConfDir);
    if(r!=0)
        return r;
    SFSystem_AppendConfigName(modid,path);
    sf_strcat(path,L"\\");
    return sf_vfs_repare_dir(path);
}


static void SFSystem_MakeAppConfFile(SFModId modid,UChar* path)
{
    if(SFSystem_GetAppConfDir(modid,path)!=0)
    {
        path[0]=0;
    }
    sf_strcat(path,L"config.cfg");
}

static void SFSystem_InitAppConfig(SFModuleConfigData* pconf)
{
    SFDEBUG("reset app config");
    pconf->AppDataAccount=g_sfplat.iLastDataAccount!=0?g_sfplat.iLastDataAccount:SFCUST_NET_ACCOUNT;
}

static void SFSystem_LoadAppConfig(SFModId modid,SFModuleConfigData* pconf)
{
    UChar* path;
    
    FS_HANDLE hFile;

    dbg_cache0();
    path=sf_vfs_alloc_path_cache(FS_MAX_PATH);
    dbg_cache0();
    //if(SFAppPlatform_GetConfigDir(path)!=0)
    //    return;
    SFSystem_MakeAppConfFile(modid,path);

    //sf_dbgprintf(L"load %s",path);

    hFile=FS_Open(path,FS_READ_ONLY);
    if(hFile>=0)
    {
        UINT sz;
        if(FS_Read(hFile,pconf,sizeof(SFModuleConfigData),&sz)<0 
            || sz!=sizeof(SFModuleConfigData))
        {
            //reset the config
            SFSystem_InitAppConfig(pconf);
        }
        FS_Close(hFile);
    }
    else
    {
        //reset the config
        SFSystem_InitAppConfig(pconf);
    }
    sf_vfs_free_path_cache(path);
}

static void SFSystem_DeleteAppConfig(SFModId modid)
{
    UChar* path=sf_vfs_alloc_path_cache(FS_MAX_PATH);
    int r;
    //FS_HANDLE hFile;
    //if(SFAppPlatform_GetConfigDir(path)!=0)
    //    return;
    SFSystem_MakeAppConfFile(modid,path);

    
    r=FS_Delete(path);

    sf_dbgprintf(L"delete (%d) %s",r,path);
    sf_vfs_free_path_cache(path);
}

static void SFSystem_SaveAppConfig(SFModId modid,SFModuleConfigData* pconf)
{
    UChar* path=sf_vfs_alloc_path_cache(FS_MAX_PATH);
    
    FS_HANDLE hFile;
    //if(SFAppPlatform_GetConfigDir(path)!=0)
    //    return;
    SFSystem_MakeAppConfFile(modid,path);

    //sf_dbgprintf(L"save %s",path);

    hFile=FS_Open(path,FS_READ_WRITE|FS_CREATE);
    if(hFile>=0)
    {
        UINT sz;
        if(FS_Write(hFile,pconf,sizeof(SFModuleConfigData),&sz)<0 
            || sz!=sizeof(SFModuleConfigData))
        {
            //reset the config
            //SFAppPlatform_InitAppConfig();
        }
        FS_Close(hFile);
    }
    sf_vfs_free_path_cache(path);
}

#if defined(MTK_07A) || defined(MTK_07B)
static void SFAppPlatform_OnAppDataAccount(U32 index)
#else
static void SFAppPlatform_OnAppDataAccount(U16 index)
#endif
{
    //save the config
    if(g_sfplat.iAppConf.AppDataAccount!=index)
    {
        g_sfplat.iAppConf.AppDataAccount=index;

        sf_dbgprintf(L"sel dacnt",index);

        SFSystem_SaveAppConfig(g_sfplat.iActiveModId,&g_sfplat.iAppConf);
    }
    g_sfplat.iLastDataAccount=index;
    GoBackHistory();
}

static void SFAppPlatform_OptionDoAction(void)
{
    SFDEBUG("SFAppPlatform_OptionDoAction");
    switch(g_sfplat.iOptionIdx)
    {
    case 0:
        //launch
        //DeleteNHistory(1);
        {
#ifdef __J2ME__
            if(jvm_is_pause_mode())
            {
                mmi_java_display_is_busy_for_pause_mode();
                return;
            }
#endif
            SFSystem_LaunchModule(g_sfplat.iActiveModId,SFNull,SF_LAUNCH_NORMAL);
        }
        //if(SFOS32_GetLastError()!=SFR_OK)
        
        break;
    case 1:
        //App About 
        SFAppPlatform_PopupAppAbout(g_sfplat.iActiveModId);
        break;
    case 2:
        //Detail 
        //format and show the info 
        SFAppPlatform_PopupAppDetail(g_sfplat.iActiveModId);
        break;
    case 3:
        //delete
        //confirm delete
        //DeleteNHistory(1);
        SFAppPlatform_PopupDeleteConfirm();
        break;
    case 4:
        //select the data account
        mmi_dtcnt_select_account_ext(SFAppPlatform_OnAppDataAccount, SERVICES_WAP_MENU_ID, DATA_ACCOUNT_BEARER_GPRS,g_sfplat.iAppConf.AppDataAccount);
        break;
    default:
        //back
        GoBackHistory();
        break;
    }
}

static void SFAppPlatform_AppOptionEntry(void)
{
    U8 *guiBuffer_p;
    U8* nStrItemList[6];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    EntryNewScreen(ID_SCR_SFAPP+5, NULL, SFAppPlatform_AppOptionEntry, NULL);

    guiBuffer_p = GetCurrGuiBuffer(ID_SCR_SFAPP);
    //菜单项
    nNumofItem = 6;

    nStrItemList[0]=(U8*)sfap_get_text(SF_STR_ID_RUN);
    nStrItemList[1]=(U8*)sfap_get_text(SF_STR_ID_APP_ABOUT);
    nStrItemList[2]=(U8*)sfap_get_text(SF_STR_ID_FILE_DETAILS);
    nStrItemList[3]=(U8*)sfap_get_text(SF_STR_ID_DELETE);
    nStrItemList[4]=(U8*)sfap_get_text(SF_STR_ID_SEL_DATAACCOUNT);
    nStrItemList[5]=(U8*)sfap_get_text(SF_STR_ID_BACK);
    

    //SetParentHandler(MENU_DOWNLOAD_SFAPP_STORAGE);

    RegisterHighlightHandler(SFAppPlatform_SelectOptionIdx);
    
    ShowCategory89Screen(
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        NULL,
        0,
        g_sfplat.iOptionIdx,
        NULL);

    //mmi_fmgr_sel_drv_and_enter(APP_EXTRA, SFAppPlatform_SetStorageSelection, (S8)g_sfplat.iStorageDrv);
    
    SetLeftSoftkeyFunction(SFAppPlatform_OptionDoAction, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    dbg_cache0();

    //SetKeyHandler(DisplayIdleScreen, KEY_END, KEY_EVENT_DOWN);
}

static void SFAppPlatform_AppOption(void)
{
    UString path;

    dbg_cache0();
    
    if(SFSystem_GetPathByModuleId(g_sfplat.iActiveModId,&path)==SFReasonOK)
    {
        //sf_dbgprintf(L"option of {%08x%08x} %s",(int)(g_sfplat.iActiveModId>>32),(int)g_sfplat.iActiveModId,path);
        if(SFOS32_GetAppManifestItem(path,APK_MANIFEST__MOD_NAME,&g_sfplat.iAppName,SFAPP_PLAT_NAME_LEN)!=0)
        {
            g_sfplat.iAppName[0]=0;
        }
        SFSystem_LoadAppConfig(g_sfplat.iActiveModId,&g_sfplat.iAppConf);

        dbg_cache0();

        g_sfplat.iOptionIdx=0;
        
        SFAppPlatform_AppOptionEntry();
    }
}


#if defined(__SF_APPLICATION_PLATFORM__INTEGRATE_OTHER_APPS__)
#ifdef SFCUST_APP_PLAT_EXT_ITEMS

static SFAppPlatCustomItem __app_list[SFCUST_APP_PLAT_EXT_ITEMS]={0};

const SFAppPlatCustomItem* SFAppPlat_GetCustomItemList(void)
{
    int idx=0;
#ifdef __SF_MTK_APPLICATION_MAJIANG__ENABLE__
    __app_list[idx].iCaption=SFMajiang_GetAppName(g_sfplat.iLang);
    __app_list[idx].iLabel=sfap_get_text(SF_STR_ID_RUN);
    __app_list[idx].cbActive=&SFMajiangEntry;
    ++idx;
#endif
#ifdef __SF_MTK_APPLICATION_RABBIT__ENABLE__
    __app_list[idx].iCaption=SFRabbit_GetAppName(g_sfplat.iLang);
    __app_list[idx].iLabel=sfap_get_text(SF_STR_ID_RUN);
    __app_list[idx].cbActive=&SFRabbitEntry;
    ++idx;
#endif
#ifdef __SF_MTK_APPLICATION_STOCK__ENABLE__
    __app_list[idx].iCaption=SFStock_GetAppName(g_sfplat.iLang);
    __app_list[idx].iLabel=sfap_get_text(SF_STR_ID_RUN);
    __app_list[idx].cbActive=&SFStockEntry;
    ++idx;
#endif
#ifdef __SF_MTK_APPLICATION_KNIGHT__ENABLE__
        __app_list[idx].iCaption=SFKnight_GetAppName(g_sfplat.iLang);
        __app_list[idx].iLabel=sfap_get_text(SF_STR_ID_RUN);
        __app_list[idx].cbActive=&SFKnightEntry;
        ++idx;
#endif

    return __app_list;
}

#endif //SFCUST_APP_PLAT_EXT_ITEMS
#endif //defined(__SF_APPLICATION_PLATFORM__INTEGRATE_OTHER_APPS__)

#if 0
#ifndef __SFAPP_PLAT_NO_SELECT_DRIVE__
    

void SFAppPlatform_SaveDriveSelection(S8 drive_letter)
{
    if(g_sfplat.iAppDirDrv != drive_letter)
    {
        g_sfplat.iAppDirDrv = drive_letter;
        g_sfplat.bDrvChanged=1;
        //kal_prompt_trace(MOD_NIL,"drv %c",drive_letter);
        SFAppPlatform_SaveConfig(&g_sfplat);
    }
}

void SFAppPlatform_SelectDrive(void)
{
    SFDEBUG("SFAppPlatform_SelectDrive");
    mmi_fmgr_sel_drv_and_enter(APP_EXTRA, SFAppPlatform_SaveDriveSelection, (S8)g_sfplat.iAppDirDrv);    
}

#endif //__SFAPP_PLAT_NO_SELECT_DRIVE__
#endif //0

const SFAppPlatformInfo* SFAppPlatformGetInfo(void);


#if defined(MT6223)
static const UChar* const s_plat_string=L"MT6223";
#elif defined(MT6223P)
static const UChar* const s_plat_string=L"MT6223P";
#elif defined(MT6225)
static const UChar* const s_plat_string=L"MT6225";
#elif defined(MT6226)
static const UChar* const s_plat_string=L"MT6226";
#elif defined(MT6227)
static const UChar* const s_plat_string=L"MT6227";
#elif defined(MT6228)
static const UChar* const s_plat_string=L"MT6228";
#elif defined(MT6229)
static const UChar* const s_plat_string=L"MT6229";
#else
static const UChar* const s_plat_string=L"MT_ANY";
#endif

const UChar* SFAppPlatform_GetPlatformHW(void)
{
    return s_plat_string;
}

static void SFAppPlatform_GetIMSIRsp(void* imsi)
{
    mmi_nw_get_imei_rsp_struct*pimsi=(mmi_nw_get_imei_rsp_struct*)imsi;
    char cimsi[17];
    UChar buf[160];
    ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_IMEI_RSP);
    if(pimsi->result)
    {
        memcpy(cimsi,pimsi->imei,16);
        cimsi[16]=0;
        sf_sprintf(buf,SFAPP_PLAT_APP_LINK,
            SFAppPlatformGetInfo()->iPlatformVersion,
            SFAppPlatformGetInfo()->iAPIVersion,
            s_plat_string,
            cimsi,
            LCD_WIDTH,LCD_HEIGHT,SFAPP_PLAT_RT_MEM_SIZE);
    }
    else
    {
        sf_sprintf(buf,SFAPP_PLAT_APP_LINK,
            SFAppPlatformGetInfo()->iPlatformVersion,
            SFAppPlatformGetInfo()->iAPIVersion,
            s_plat_string,
            "",
            LCD_WIDTH,LCD_HEIGHT,SFAPP_PLAT_RT_MEM_SIZE);
    }
    wap_start_browser(WAP_BROWSER_GOTO_URL,(const kal_uint8 *) buf);
}

static void SFAppPlatform_GoLink(void)
{
#ifdef MMI_ON_HARDWARE_P

    MYQUEUE Message;
#endif




    UChar buf[160];
    sf_sprintf(buf,SFAPP_PLAT_APP_LINK,
            SFAppPlatformGetInfo()->iPlatformVersion,
            SFAppPlatformGetInfo()->iAPIVersion,
            s_plat_string,
            "",
            LCD_WIDTH,LCD_HEIGHT,SFAPP_PLAT_RT_MEM_SIZE);
    if(!mmi_bootup_is_sim_valid())
    {
        wap_start_browser(WAP_BROWSER_GOTO_URL,(const kal_uint8 *) buf);
        return;
    }
    
#ifdef MMI_ON_HARDWARE_P

    SetProtocolEventHandler(SFAppPlatform_GetIMSIRsp, MSG_ID_MMI_NW_GET_IMEI_RSP);

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_NW_GET_IMEI_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#else   
            /* dammy IMEI code */
    wap_start_browser(WAP_BROWSER_GOTO_URL,(const kal_uint8 *) buf);
#endif 
    
}

void SFAppPlatform_OnItemChanged(SFAppPlatform* self,SFInt idx)
{
    self->iActiveItem=(SFInt16)idx;
    
#ifdef __SFAPP_PLAT_LIST_FIRST_LINK__
    if(idx==0)
#else
    if(idx==self->nTotalItems-1)
#endif
    {
        //link
        set_left_softkey_label(sfap_get_text(SF_STR_ID_GOTO_URL));
        SetLeftSoftkeyFunction(&SFAppPlatform_GoLink, KEY_EVENT_UP);
        SetKeyHandler(&SFAppPlatform_GoLink, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }

#ifdef SFCUST_APP_PLAT_EXT_ITEMS
 #ifdef __SFAPP_PLAT_LIST_FIRST_LINK__
    else if(idx<__SFCUST_APP_PLAT_EXT_ITEMS+1)
    {
        int aid=idx-1;
 #else //__SFAPP_PLAT_LIST_FIRST_LINK__
    else if(idx<__SFCUST_APP_PLAT_EXT_ITEMS)
    {
        int aid=idx;
 #endif //__SFAPP_PLAT_LIST_FIRST_LINK__
        const SFAppPlatCustomItem* item=&(SFAppPlat_GetCustomItemList()[aid]);
        //set_left_softkey_label(sfap_get_text(SF_STR_ID_SELECT));
        if(item && item->cbActive)
        {
            set_left_softkey_label((UI_string_type)item->iLabel);
            SetLeftSoftkeyFunction(item->cbActive, KEY_EVENT_UP);
            SetKeyHandler(item->cbActive, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }
        else
        {
            set_left_softkey_label(item?(UI_string_type)item->iLabel:(UI_string_type)L"");
            //SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
            SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }
    }
#endif //SFCUST_APP_PLAT_EXT_ITEMS
    else
    {
        set_left_softkey_label(sfap_get_text(SF_STR_ID_OPTIONS));
        SetLeftSoftkeyFunction(&SFAppPlatform_AppOption, KEY_EVENT_UP);
        SetKeyHandler(&SFAppPlatform_AppOption, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

        memcpy(&self->iActiveModId,self->iNameList[idx]+SFAPP_PLAT_NAME_LEN,8);

        //sf_dbgprintf(L"select {%08x%08x}",(int)(g_sfplat.iActiveModId>>32),(int)g_sfplat.iActiveModId);
        
        //memcpy(self->iAppName,self->iNameList[idx],SFAPP_PLAT_NAME_LEN);
        //reget
        
    }
    redraw_left_softkey();
    //dm_redraw_category_screen();

}

void SFAppPlatform_OnItemHighlight(S32 idx)
{
    SFAppPlatform_OnItemChanged(&g_sfplat,idx);
}

extern int SFSystem_GetLanguageId(void);
extern void SFAppPlatform_SelectLanguage(int id);
extern void sf_vfs_refresh_drivers(void);

#ifdef SFCUST_COMPACT_RAM
void SFAllocWorkMemory(void);
void SFFreeWorkMemory(void);
void SFWorkMemory_AddRef(void);
int SFWorkMemory_Release(void);
#endif //SFCUST_COMPACT_RAM

U8 SFAppPlatform_OnDeleteEntry(void)
{
#ifdef SFCUST_COMPACT_RAM
	SFWorkMemory_Release();
#endif //SFCUST_COMPACT_RAM
	return 0;
}

void SFAppPlatform_Entry2(void)
{
    //create the list
    sf_vfs_refresh_drivers();
    SFSystem_InitSecureRecords();
    //TODO: set language here
    g_sfplat.iLang=SFSystem_GetLanguageId();//chinese
    SFAppPlatform_SelectLanguage(g_sfplat.iLang);

    EntryNewScreen(ID_SCR_SFAPP,&SFAppPlatform_Leave,&SFAppPlatform_Entry2,SFNull);
    g_sfplat.iGuiBuffer=GetCurrGuiBuffer(ID_SCR_SFAPP);
   SetDelScrnIDCallbackHandler(ID_SCR_SFAPP, (HistoryDelCBPtr)SFAppPlatform_OnDeleteEntry);

    RegisterHighlightHandler(&SFAppPlatform_OnItemHighlight);
    SFAppPlatform_GenerateAppList(&g_sfplat);
    dbg_cache0();
    gdi_layer_lock_frame_buffer();
    ShowCategory89Screen(STR_GLOBAL_OPEN,0,STR_GLOBAL_OPEN,0,STR_GLOBAL_BACK,0,g_sfplat.nTotalItems,(U8 * *) g_sfplat.iNameList,NULL,0,g_sfplat.iActiveItem,g_sfplat.iGuiBuffer);
    //change the title
    SFAppPlatform_SetTitle((const UChar *)sfap_get_text(SF_STR_ID_SFAP_TITLE));
    gdi_layer_unlock_frame_buffer();
    dm_redraw_category_screen();

    SetRightSoftkeyFunction(&GoBackHistory, KEY_EVENT_UP);
    dbg_cache0();
}

void SFAppPlatform_Entry3(void)
{
    g_sfplat.iActiveItem=0;
    SFAppPlatform_Entry2();
}


#define SFMODID_SFAPP_PLATFORM_EX    SFMODID(0x905EB382,0x99CAF544)

int SFSystem_ModuleExists(SFModId mod);


void SFAppPlatform_Entry(void)
{
    SFReason r=SFReasonNotFound;
    g_sfplat.iActiveItem=0;
#ifdef SFCUST_COMPACT_RAM
    SFAllocWorkMemory();
#endif
    //check for the update module

    if(SFSystem_ModuleExists(SFMODID_SFAPP_PLATFORM_EX))
    {
        r=SFSystem_LaunchModule(SFMODID_SFAPP_PLATFORM_EX,SFNull,SF_LAUNCH_NORMAL);
    }
    
    if(r!=SFReasonOK)
    {
        SFAppPlatform_Entry2();
    }
}



#define MENU_DOWNLOAD_SFAPP_STORAGE MENU_DOWNLOAD_THEMES_STORAGE
#define MENU_STORAGE_SFAPP_PHONE    MENU_STORAGE_THEMES_PHONE
#define MENU_STORAGE_SFAPP_CARD    MENU_STORAGE_THEMES_CARD
    
void SFAppPlatform_SelectStorageType(S32 idx)
{
    //SFDEBUG("SFAppPlatform_SelectStorageType");
    g_sfplat.iStorageIdx=(SFInt16)idx;
    kal_prompt_trace(MOD_NIL,"SFAppPlatform_SelectStorageType %d",idx);
    if(g_sfplat.iStorageIdx==0)
    {
        g_sfplat.iStorageDrv=g_sf_local_drv;
    }
    else
    {
        g_sfplat.iStorageDrv=g_sf_card_drv;
    }
}

void SFAppPlatform_HideExtName(S8 *file_name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* find ext name - by finding "." */
    S32 str_len;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = pfnUnicodeStrlen(file_name_p);
    index = (str_len - 1) * ENCODING_LENGTH;

    while (index > 0)
    {
        if (pfnUnicodeStrncmp((PS8) & file_name_p[index], (PS8) L".", 1) == 0)
        {
            file_name_p[index] = '\0';
            file_name_p[index + 1] = '\0';
            break;
        }

        file_name_p[index] = '\0';
        file_name_p[index + 1] = '\0';
        index -= 2;
    }
}


void SFAppPlatform_CheckIfFileAlreadyExist(PS8 file_path, PS8 file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;
    U8 file_count = 0;
    S8 tempStr[6];
    S8 ucs2_dup_file_rename[12];
    U8 len;
    S8 file_ext_buf[(FMGR_MAX_EXT_LEN + 1) * ENCODING_LENGTH];
    S8 *file_ext_p;
    S8 temp_file_name[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_file_name, 0, (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
    pfnUnicodeStrncpy(temp_file_name, file_name, FMGR_MAX_FILE_LEN * ENCODING_LENGTH);

    while (file_count < 65535)
    {
        memset(hintData, 0, (FMGR_MAX_PATH_LEN + FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);
        pfnUnicodeStrncpy((PS8) hintData, file_path, FMGR_PATH_BUFFER_SIZE - ENCODING_LENGTH);
        pfnUnicodeStrncat((PS8) hintData, temp_file_name, (FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);
        file_count++;
        fd = FS_Open((WCHAR*) hintData, FS_READ_ONLY);
        if (fd >= 0)
        {
            FS_Close(fd);
            sprintf(tempStr, "%d", file_count);
            AnsiiToUnicodeString(ucs2_dup_file_rename, tempStr);

            memset(temp_file_name, 0, (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
            pfnUnicodeStrncpy(temp_file_name, file_name, FMGR_MAX_FILE_LEN * ENCODING_LENGTH);

            file_ext_p = (S8*) mmi_fmgr_extract_ext_file_name(temp_file_name);
            pfnUnicodeStrcpy(file_ext_buf, file_ext_p);
            SFAppPlatform_HideExtName(temp_file_name);

            len = FMGR_MAX_INPUT_FILE_LEN - pfnUnicodeStrlen(temp_file_name);

            if (len >= pfnUnicodeStrlen(ucs2_dup_file_rename))
            {
                pfnUnicodeStrcat(temp_file_name, ucs2_dup_file_rename);
            }
            else
            {
                memset(temp_file_name + (FMGR_MAX_INPUT_FILE_LEN - 6) * ENCODING_LENGTH, 0, 12);
                AnsiiToUnicodeString(tempStr, "~");
                pfnUnicodeStrcat(temp_file_name, tempStr);
                pfnUnicodeStrcat(temp_file_name, ucs2_dup_file_rename);
            }
            AnsiiToUnicodeString(tempStr, ".");
            pfnUnicodeStrcat(temp_file_name, tempStr);
            pfnUnicodeStrcat(temp_file_name, file_ext_buf);
        }
        else
        {
            pfnUnicodeStrcpy(file_name, temp_file_name);
            break;
        }
    }
}


PS8 SFAppPlatform_ParsePathExtractFileName(S8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = pfnUnicodeStrlen(path) * 2;
    i = length - 1;

    while (i > 0)
    {
        if (path[i - 1] == '\\' && path[i] == 0 && (i != length - ENCODING_LENGTH))
        {
            break;
        }
        i -= 2;
    }

    if (i < 0)
    {
        return NULL;
    }

    return &path[i + 1];
}

#ifdef __SFAPP_PLAT_LAUNCH_AFTER_DOWNLOAD__

void SFAppPlatform_OnLaunchAfterDownload(void)
{
    //GoBackHistory();
    
    SFOS32_AppEntry(g_sfplat.iTempText,0);
    DeleteNHistory(1);
}

#endif

void SFAppPlatform_SaveAppContent(S8 *filepath_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *temp_file_name_p;
    S8 temp_file_name[(FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH];
    int r;
    SFDEBUG("SFAppPlatform_SaveAppContent");
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_file_name_p = SFAppPlatform_ParsePathExtractFileName((S8*) g_sfplat.iTempText);
    pfnUnicodeStrncpy(temp_file_name, temp_file_name_p, (FMGR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
    SFAppPlatform_CheckIfFileAlreadyExist((S8*) filepath_p, (S8*) temp_file_name);
    pfnUnicodeStrcat((S8*) subMenuData, (S8*) temp_file_name);

    sf_dbgprintf(L"move from %s",g_sfplat.iTempText);
    sf_dbgprintf(L"from to",subMenuData);
    
    r=FS_Move(
        (const WCHAR*)g_sfplat.iTempText,
        (const WCHAR*)subMenuData,
        FS_MOVE_KILL | FS_MOVE_OVERWRITE,
        NULL, NULL, 0);
    sf_dbgprintf(L"mov result %d",r);
    sf_strcpy((WCHAR*)g_sfplat.iTempText,(const WCHAR*)subMenuData);
#ifdef __SFAPP_PLAT_LAUNCH_AFTER_DOWNLOAD__
    DisplayConfirm(
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        sfap_get_text(SF_STR_ID_LAUNCH_AFTER_DOWNLOAD_QUEST),
        IMG_GLOBAL_QUESTION,
        WARNING_TONE);

    DeleteScreenIfPresent(ID_SCR_SFAPP_DA);
    SetLeftSoftkeyFunction(SFAppPlatform_OnLaunchAfterDownload, KEY_EVENT_UP);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
#else
    
    if(r==FS_NO_ERROR)
    {
        DisplayPopup(
            (PU8) sfap_get_text(SF_STR_ID_SAVED),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);
        
    }
    else
    {
        DisplayPopup(
                        (PU8) sfap_get_text(SF_STR_ID_ERROR),//磁盘空间不足
                        IMG_GLOBAL_WARNING,
                        0,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);
    }
     DeleteScreenIfPresent(ID_SCR_SFAPP_DA);
    
    //DeleteNHistory(1);
    //DeleteScreenIfPresent(ID_SCR_SFAPP_DA);
    //GoBackHistory();
    //DisplayPopup(
    //    (PU8) sfap_get_text(SF_STR_ID_DOWNLOADED),
    //    IMG_GLOBAL_ACTIVATED,
    //    1,
    //    UI_POPUP_NOTIFYDURATION_TIME,
    //    (U8) SUCCESS_TONE);
    
#endif
}


void SFAppPlatform_SetStorageType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_RetDrv = g_sfplat.iStorageDrv;//FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
    U64 disk_free_space;
    U64 file_size;
    FS_DiskInfo disk_info;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    #if 0
    switch (g_sfplat.iStorageIdx)
    {
        case 0:
            fs_RetDrv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
            break;

        case 1:
            fs_RetDrv = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
            break;

        default:
            break;
    }
    #endif
    //fs_RetDrv=g_sfplat.iStorageDrv;

    
    

    if (fs_RetDrv > 0)
    {
        S8 buf[6];
        S32 create_result;

        file_size = 0;//(U64) (g_ta_da_context.da_file_size * 1024);
        file_handle = FS_Open((kal_uint16*) g_sfplat.iTempText, FS_READ_ONLY);
        if(file_handle>=0)
        {
            FS_GetFileSize(file_handle,(UINT *)&file_size);
            FS_Close(file_handle);
        }
        else
        {
            file_size = 0x7FFFFFFF;//fail
        }
        
                
        sprintf(buf, "%c", (U8) fs_RetDrv);
        memset(subMenuData, 0, (FMGR_MAX_PATH_LEN + FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);
        AnsiiToUnicodeString((S8*) subMenuData, (S8*) buf);

        pfnUnicodeStrcat((PS8) subMenuData, (PS8) L":\\");
        sf_dbgprintf(L"dir %s",subMenuData);

        file_handle = FS_Open((kal_uint16*) subMenuData, FS_OPEN_DIR | FS_READ_ONLY);

        if (file_handle >= 0)
        {
            FS_Close(file_handle);
            /* drive is avaiable */

            FS_GetDiskInfo((PU16) subMenuData, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

            disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;

            

            if (disk_free_space >= file_size)
            {

                sprintf(buf, "%c", (U8) fs_RetDrv);
                memset(subMenuData, 0, (FMGR_MAX_PATH_LEN + FMGR_MAX_FILE_LEN) * ENCODING_LENGTH);
                AnsiiToUnicodeString((S8*) subMenuData, (S8*) buf);
                
                pfnUnicodeStrcat((PS8) subMenuData, (PS8) s_SFAppPlatformDirPath);
                file_handle = FS_Open((kal_uint16*) subMenuData, FS_OPEN_DIR | FS_READ_ONLY);

                /* path already exist */
                if (file_handle >= 0)
                {
                    FS_Close(file_handle);
                    create_result = 0;
                }
                else
                {
                    create_result = FS_CreateDir((PU16) subMenuData);
                    SFDEBUG("create dir");
                }

                if (create_result == FS_WRITE_PROTECTION)
                {
                    DisplayPopup(
                        (PU8) sfap_get_text(SF_STR_ID_DISK_WRITE_PROTECTETION),//磁盘写保护
                        IMG_GLOBAL_WARNING,
                        0,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);
                }
                else if (create_result == FS_DISK_FULL)
                {
                    DisplayPopup(
                        (PU8) sfap_get_text(SF_STR_ID_DISK_FULL),//磁盘空间不足
                        IMG_GLOBAL_WARNING,
                        0,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);
                }
                else if (create_result != FS_NO_ERROR)
                {
                    DisplayPopup(
                        (PU8) sfap_get_text(SF_STR_ID_ERROR),//磁盘空间不足
                        IMG_GLOBAL_WARNING,
                        0,
                        UI_POPUP_NOTIFYDURATION_TIME,
                        WARNING_TONE);
                }
                else
                {
                    SFAppPlatform_SaveAppContent((PS8) subMenuData);

                    //DisplayPopup(
                    //    (PU8) GetString(STR_GLOBAL_DOWNLOADED),
                    //    IMG_GLOBAL_ACTIVATED,
                    //    1,
                    //    UI_POPUP_NOTIFYDURATION_TIME,
                    //    (U8) SUCCESS_TONE);
                }
            }
            else
            {
                DisplayPopup(
                    (PU8) sfap_get_text(SF_STR_ID_NO_DISK_SPACE),//空间不足
                    IMG_GLOBAL_WARNING,
                    1,
                    UI_POPUP_NOTIFYDURATION_TIME,
                    WARNING_TONE);
            }

        }
        else
        {
            DisplayPopup(
                (PU8) sfap_get_text(SF_STR_ID_NO_MEMORY_CARD),
                IMG_GLOBAL_WARNING,
                1,
                UI_POPUP_NOTIFYDURATION_TIME,
                WARNING_TONE);
        }
    }
    else
    {
        /* get drive error  */
        DisplayPopup(
            (PU8) sfap_get_text(SF_STR_ID_NO_MEMORY_CARD),
            IMG_GLOBAL_WARNING,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }
}

void SFAppPlatform_ExitStorageType(void)
{
    FS_HANDLE fd;

    SFDEBUG("SFAppPlatform_ExitStorageType");
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if file exists. Delete it. */
    fd = FS_Open((WCHAR*) g_sfplat.iTempText, FS_READ_WRITE);
    if (fd >= 0)
    {
        FS_Close(fd);
        FS_Delete((WCHAR*) g_sfplat.iTempText);
    }
    GoBackHistory();
}

void SFAppPlatform_SetStorageSelection(S8 drv)
{
    SFDEBUG("SFAppPlatform_SetStorageSelection");
    //g_sfplat.iStorageDrv=drv;
    kal_prompt_trace(MOD_NIL,"drv s %c",drv);
    //if(drv==0)
    //{
    //    g_sfplat.iStorageDrv=g_sf_local_drv;
    //}
    //else
    //{
    //    g_sfplat.iStorageDrv=g_sf_card_drv;
    
    //}
}

void SFAppPlatform_SelectStorageScreen(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer_p;
    U8* nStrItemList[2];
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    EntryNewScreen(ID_SCR_SFAPP_DA, NULL, SFAppPlatform_SelectStorageScreen, NULL);

    guiBuffer_p = GetCurrGuiBuffer(ID_SCR_SFAPP_DA);
    //菜单项
    nNumofItem = 2;

    nStrItemList[0]=(U8*)sfap_get_text(SF_STR_ID_DRV_PHONE);    
    nStrItemList[1]=(U8*)sfap_get_text(SF_STR_ID_DRV_MEMORY_CARD);

    //SetParentHandler(MENU_DOWNLOAD_SFAPP_STORAGE);

    RegisterHighlightHandler(SFAppPlatform_SelectStorageType);

    //gdi_layer_lock_frame_buffer();
    ShowCategory89Screen(
        STR_FMGR_SEL_DRV_TITLE,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        nNumofItem,
        nStrItemList,
        NULL,
        0,
        0,
        guiBuffer_p);
    SFAppPlatform_SetTitle((const UChar *) sfap_get_text(SF_STR_ID_SEL_DRV));

    //gdi_layer_unlock_frame_buffer();
    //mmi_fmgr_sel_drv_and_enter(APP_EXTRA, SFAppPlatform_SetStorageSelection, (S8)g_sfplat.iStorageDrv);

    SetLeftSoftkeyFunction(SFAppPlatform_SetStorageType, KEY_EVENT_UP);
#ifdef __MMI_WGUI_CSK_ENABLE__
    SetCenterSoftkeyFunction(SFAppPlatform_SetStorageType,KEY_EVENT_UP);
#endif //__MMI_WGUI_CSK_ENABLE__
    SetRightSoftkeyFunction(SFAppPlatform_ExitStorageType, KEY_EVENT_UP);

    SetKeyHandler(DisplayIdleScreen, KEY_END, KEY_EVENT_DOWN);
}

int sf_vfs_is_drv_ready(UChar drv);

void SFAppPlatform_HandleReciveAppFile(S32 session_id,S32 mime_type, S32 mime_subtype, S32 action, PU16 file_path, PS8 url, PS8 mime_type_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    history currHistory;
    U16 nHistory = 0;
    int local_ready;
    int card_ready;

    sf_vfs_prepare_drivers();
    SFSystem_InitSecureRecords();
    
    local_ready=(g_sf_local_drv>0 && sf_vfs_is_drv_ready(g_sf_local_drv));
    card_ready=(g_sf_card_drv>0 && sf_vfs_is_drv_ready(g_sf_card_drv));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sfplat.iStorageIdx=0;

    if (file_path)
    {
        pfnUnicodeStrcpy((S8*) g_sfplat.iTempText, (S8*) file_path);
    }
    if(local_ready && card_ready)
    {
        g_sfplat.iStorageDrv=g_sf_card_drv;
        g_sfplat.iStorageIdx=1;
        
        currHistory.scrnID = ID_SCR_SFAPP_DA;
        currHistory.entryFuncPtr = SFAppPlatform_SelectStorageScreen;
        memset((void*)currHistory.guiBuffer, 0, sizeof(currHistory.guiBuffer));
        pfnUnicodeStrcpy((S8*) currHistory.inputBuffer, (S8*) & nHistory);

        DisplayPopup(
            (PU8) sfap_get_text(SF_STR_ID_DOWNLOADED),
            IMG_GLOBAL_ACTIVATED,
            1,
            UI_POPUP_NOTIFYDURATION_TIME,
            (U8) SUCCESS_TONE);

        AddHistory(currHistory);
    }
    else if(local_ready)
    {
        //save to 
        g_sfplat.iStorageDrv=g_sf_local_drv;
        SFAppPlatform_SetStorageType();
    }
    else if(card_ready)
    {
        g_sfplat.iStorageDrv=g_sf_card_drv;
        SFAppPlatform_SetStorageType();
    }
    else
    {
       DisplayPopup(
            (PU8) sfap_get_text(SF_STR_ID_DISK_WRITE_PROTECTETION),//磁盘写保护
            IMG_GLOBAL_WARNING,
            0,
            UI_POPUP_NOTIFYDURATION_TIME,
            WARNING_TONE);
    }
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
}

typedef struct _SFAppPlatPathCache
{
    SFUint8 bValid;
    SFUint8 iHistory;
    SFModId iModId;
    UChar iPath[FS_MAX_PATH];
} SFAppPlatPathCache;

#ifdef SFCUST_COMPACT_RAM
#define MAX_PATH_MOD_CACHE  1
#else
#define MAX_PATH_MOD_CACHE  2
#endif

static SFAppPlatPathCache s_path_mod_cache[MAX_PATH_MOD_CACHE];

static SFAppPlatPathCache* PMCacheFromId(SFModId id)
{
    int i,j;
    for(i=0;i<MAX_PATH_MOD_CACHE;i++)
    {
        if(s_path_mod_cache[i].bValid)
        {
            if(s_path_mod_cache[i].iModId==id)
            {
                if(s_path_mod_cache[i].iHistory<0xFF)
                {
                    ++s_path_mod_cache[i].iHistory;
                }
                j=i;
                for(i=i+1;i<MAX_PATH_MOD_CACHE;i++)
                {
                    if(s_path_mod_cache[i].bValid && s_path_mod_cache[i].iHistory>0)
                    {
                        --s_path_mod_cache[i].iHistory;
                    }
                }
                return &s_path_mod_cache[j];
            }
            else if(s_path_mod_cache[i].iHistory>0)
            {
                --s_path_mod_cache[i].iHistory;
            }
        }
    }
    return SFNull;
}
static SFAppPlatPathCache* PMCacheFromPath(UString path)
{
    int i,j;
    for(i=0;i<MAX_PATH_MOD_CACHE;i++)
    {
        if(s_path_mod_cache[i].bValid)
        {
            if(sf_strcmp(s_path_mod_cache[i].iPath,path)==0)
            {
                if(s_path_mod_cache[i].iHistory<0xFF)
                {
                    ++s_path_mod_cache[i].iHistory;
                }
                j=i;
                for(i=i+1;i<MAX_PATH_MOD_CACHE;i++)
                {
                    if(s_path_mod_cache[i].iHistory>0)
                    {
                        --s_path_mod_cache[i].iHistory;
                    }
                }
                return &s_path_mod_cache[j];
            }
            else if(s_path_mod_cache[i].iHistory>0)
            {
                --s_path_mod_cache[i].iHistory;
            }
        }
    }
    return SFNull;
}
static void PMCacheInvalidate(SFAppPlatPathCache* c)
{
    c->iHistory=0;
    c->bValid=0;
}
static void PMCacheInvalidateAll(void)
{
    int i;
    for(i=0;i<MAX_PATH_MOD_CACHE;i++)
    {
        PMCacheInvalidate(&s_path_mod_cache[i]);
    }
}
static UString PMCacheAdd(SFModId id,UString path)
{
    int i;
    int his=0x100;
    int his_idx=0;
    for(i=0;i<MAX_PATH_MOD_CACHE;i++)
    {
        if(!s_path_mod_cache[i].bValid)
        {
            his_idx=i;
            break;
        }
        else
        {
            if(s_path_mod_cache[i].iHistory<his)
            {
                his=s_path_mod_cache[i].iHistory;
                his_idx=i;
            }
        }
    }
    //use his_idx
    s_path_mod_cache[his_idx].bValid=1;
    s_path_mod_cache[his_idx].iHistory=127;
    s_path_mod_cache[his_idx].iModId=id;
    sf_strcpy(s_path_mod_cache[his_idx].iPath,path);

    //sf_dbgprintf(L"set in cache %d %s",his_idx,s_path_mod_cache[his_idx].iPath);

    return s_path_mod_cache[his_idx].iPath;
}

//void dbg_cache0_(int v)
//{
    //sf_dbgprintf(L"%d cache[0]=%s",v,s_path_mod_cache[0].iPath);
//}

SFReason SFSystem_GetModuleIdFromPath(UString path,SFModId* pmodid)
{
    SFAppPlatPathCache* c;
    if(!path || !pmodid)
    {
        return SFReasonBadParameter;
    }
    c=PMCacheFromPath(path);
    if(c)
    {
        *pmodid=c->iModId;
        return SFReasonOK;
    }
    else
    {
        //get app desc from app
        if(!SFOS32_GetAppManifestItem(path,APK_MANIFEST__MOD_ID,pmodid,8))
        {
            return SFReasonError;
        }
        return SFReasonOK;
    }
}

struct _SFFindPathyIdParam
{
    UChar* path;
    SFModId id;
};
typedef struct _SFFindPathyIdParam SFFindPathyIdParam;

static int CB_MatchModId(SFModIterator* iter,FS_DOSDirEntry* pinfo,UChar* fn)
{
    SFCLSID clsid;
    UChar* path=sf_vfs_alloc_path_cache(FS_MAX_PATH);
    SFFindPathyIdParam* param=(SFFindPathyIdParam*)iter->iParam;

    if(!path)
    {
        SFDEBUG("CB_MatchModId: SFReasonOutOfResource");
        return -1;
    }
    sf_sprintf(path,L"%s%s",iter->iDir,fn);
    //sf_dbgprintf(path);
    
    
    if(SFOS32_GetAppManifestItem(path,APK_MANIFEST__MOD_ID,&clsid,8) && clsid==param->id)
    {
        sf_strcpy(param->path,path);
        sf_vfs_free_path_cache(path);

        //sf_dbgprintf(L"match {%08x%08x} %s",(int)(param->id>>32),(int)param->id,param->path);
        return 1;
    }
    else
    {
        //sf_dbgprintf(L"not match {%08x%08x} {%08x%08x} %s",(int)(clsid>>32),(int)(clsid),(int)(param->id>>32),(int)param->id,param->path);
    }
    sf_vfs_free_path_cache(path);
    return 0;
}


SFReason SFSystem_GetPathByModuleId(SFModId modid,UString* path)
{
    SFAppPlatPathCache* c;
    SFFindPathyIdParam param;
    if(!modid || !path)
    {
        return SFReasonBadParameter;
    }
    c=PMCacheFromId(modid);
    if(c)
    {
        //sf_dbgprintf(L"found in cache {%08x%08x} %s",(int)(modid>>32),(int)modid,c->iPath);
        *path=c->iPath;
        return SFReasonOK;
    }
    else
    {
        //list all the applications
        SFModIterator it;
        it.iIter=0;
        param.path=sf_vfs_alloc_path_cache(FS_MAX_PATH);
        if(!param.path)
        {
            SFDEBUG("SFSystem_GetPathByModuleId: SFReasonOutOfResource");
            return SFReasonOutOfResource;
        }
        param.id=modid;
        it.iParam=&param;
        if(SFModIterator_ListAll(&it,&CB_MatchModId)==1)
        {
            //cache the path
            *path=PMCacheAdd(modid,param.path);
            sf_vfs_free_path_cache(param.path);

            //sf_dbgprintf(L"new in cache {%08x%08x} %s",(int)(modid>>32),(int)modid,*path);
            return SFReasonOK;
        }
        else
        {
            sf_dbgprintf(L"{%08x%08x} not found",(int)(modid>>32),(int)modid);
            sf_vfs_free_path_cache(param.path);
            return SFReasonNotFound;
        }
    }
}

static SFModId s_cache_app_name_id=0;
static UChar s_cache_app_name[SFAPP_PLAT_NAME_LEN];
    
SFReason SFSystem_GetModNameByModId(SFModId modid,UString* name)
{
    if(s_cache_app_name_id==modid)
    {
        *name=s_cache_app_name;
        return SFReasonOK;
    }
    else
    {
        UString path;
        int r;
        if((r=SFSystem_GetPathByModuleId(modid,&path))!=SFReasonOK)
        {
            *name=0;
            return r;
        }
        if(!SFOS32_GetAppManifestItem(path,APK_MANIFEST__MOD_NAME,s_cache_app_name,32))
        {
            return SFReasonError;
        }
        s_cache_app_name_id=modid;
        *name=s_cache_app_name;
        return SFReasonOK;
    }
}


#endif //__SF_APPLICATION_PLATFORM__ENABLE__

