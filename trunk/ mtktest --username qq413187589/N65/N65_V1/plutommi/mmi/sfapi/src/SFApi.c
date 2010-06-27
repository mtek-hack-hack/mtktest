#ifdef __SF_MP4_SUPPORT__
#include <SFApi.h>
#ifdef SFAPI_WIN
#include <SFAPI_Std.h>
#include "mtk/mtk.h"
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#else //SFAPI_WIN
#include "MMI_features.h"
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
#include "wgui_categories_popup.h"
#include "SettingProfile.h"
#include "FileManagerGProt.h"
#include "SSCStringHandle.h"

#include "wapadp.h"
#include "soc_api.h"
#include "app2soc_struct.h"

#include "SettingProfile.h"
#include "kal_trace.h"    
#include "wap_ps_struct.h"

#include "SMSApi.h"
#include "SMSStruct.h"
#include "Conversions.h"

#include "wgui_categories_inputs.h"
#include "AlarmFrameworkProt.h"
#include "ProfileGprots.h"
#include "SimDetectionGprot.h"
#include "abm_soc_enums.h"
#include "ConnectManageGProt.h"



#ifndef MMI_ON_HARDWARE_P
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#endif //!MMI_ON_HARDWARE_P

#include "NVRAMType.h"
#include "NVRAMProt.h"
#include "NVRAMEnum.h"
#include "app_datetime.h"

#include "med_global.h" 
#include "med_utility.h" 
#include "mdi_video.h" 

#include "Kbd_table.h"
#include "keypad_sw.h"

#include "gpioInc.h"
#include "DataAccountDef.h"

#ifdef __MMI_DUAL_SIM_MASTER__
#include "mtpnp_ad_master_if.h"
#endif


#endif //SFAPI_WIN

#include "sfapp_custom.h"

#ifndef UNUSED_PARAM
#define UNUSED_PARAM(v) ((void)(v))
#endif //UNUSED_PARAM

#if defined(__MMI_DUAL_SIM_MASTER__) && !defined(MTK_07B)
#define MTK_07B
#endif

#define dbg_last_evt()    
//dbg_last_evt_(__LINE__)

void dbg_last_evt_(int v);

extern void sf_dbgprintf(const UChar* msg,...);
extern int sf_strbegins(const UChar* str,int len,const UChar* substr,int lensub);
extern UChar* sf_strcat(UChar*buf,const UChar* str);
extern int sf_astricmp(const char* str,const char* pat);
extern UChar* sf_strncpy(UChar* dest,const UChar* src,SFSize_T sz);
extern int sf_strlen(UString str);

extern SFReason SFSystem_GetPathByModuleId(SFModId modid,UString* path);
extern int sf_sprintf(UChar*buf,const UChar*format,...);

extern void sf_slist_add_head(void** l,void* p);
extern void sf_slist_add_tail(void** l,void* p);
extern void* sf_slist_remove_head(void** l);
extern void* sf_slist_remove_tail(void** l);
extern void* sf_slist_peek_head(void** l);
extern void* sf_slist_peek_tail(void** l);
extern void sf_slist_empty(void** l);
extern void sf_slist_add_head_array(void** l,void* arr,SFSize_T sz,SFSize_T count);


#if defined(SFAPI_WIN) && !defined(__MMI_TOUCH_SCREEN__)
#define __MMI_TOUCH_SCREEN__
#define __MMI_GPRS_FEATURES__
#define __SF_PCMDRV_SUPPORT__
#define WAP_SUPPORT
#endif //defined(SFAPI_WIN) && !defined(__MMI_TOUCH_SCREEN__)

#if defined(MTK_O7A) || defined(MTK_07B)
#define lcd_power_up()  lcd_power_ctrl(KAL_TRUE)
#define lcd_power_down() lcd_power_ctrl(KAL_FALSE)
#endif

#if (defined(__SF_MTK_APPLICATION_EMU__ENABLE__)||defined(__SF_APPLICATION_PLATFORM__ENABLE__)) && !defined(__SF_PCMDRV_SUPPORT__)
#define __SF_PCMDRV_SUPPORT__
#endif //(defined(__SF_MTK_APPLICATION_EMU__ENABLE__)||defined(__SF_APPLICATION_PLATFORM__ENABLE__)) && !defined(__SF_PCMDRV_SUPPORT__)


#ifdef SFCUST_COMPACT_RAM
void SFAllocWorkMemory(void);
void SFFreeWorkMemory(void);
void SFWorkMemory_AddRef(void);
int SFWorkMemory_Release(void);
#endif //SFCUST_COMPACT_RAM




#if defined(__SF_MTK_APPLICATION_EMU__ENABLE__)

enum
{
	NESEMU_STATUS_NONE=0, //!< 其它状态
	NESEMU_STATUS_GAME=1, //!< 游戏中，正常屏幕
	NESEMU_STATUS_GAMER90=2 //!< 游戏中，旋转90度
};

SFInt SFNesEmuApp_GetStatus(void);

#endif //defined(__SF_MTK_APPLICATION_EMU__ENABLE__)


#ifdef MMI_ON_HARDWARE_P
extern kal_uint8 custom_get_csd_profile_num(void);
#endif

#ifdef SFCUST_COMPACT_RAM
#define MAX_FS_PATH_CACHE   4
#else
#define MAX_FS_PATH_CACHE   6
#endif

static UChar s_path_cache[MAX_FS_PATH_CACHE][FS_MAX_PATH+1];

UChar* sf_vfs_alloc_path_cache(SFSize_T sz)
{
    int i;
    for(i=0;i<MAX_FS_PATH_CACHE;i++)
    {
        if(s_path_cache[i][0]==0)
        {
            s_path_cache[i][0]=(UChar)sz;
            return s_path_cache[i]+1;
        }
    }
    SFDEBUG("out of path cache");
    return SFNull;
}
void sf_vfs_free_path_cache(UChar* path)
{
    int i;
    for(i=0;i<MAX_FS_PATH_CACHE;i++)
    {
        if(path==s_path_cache[i]+1)
        {
            path[-1]=0;
            return;
        }
    }
}
void sf_vfs_path_get_dir(UString path,UChar* dir)
{
    int len=sf_strlen(path);
    while(len>0 && (path[len-1]=='/' || path[len-1]=='\\'))
        --len;
    while(len>0 && path[len-1]!='/' && path[len-1]!='\\')
        --len;
    if(len>0)
        memcpy(dir,path,len*sizeof(UChar));
    dir[len]=0;
}

/*
file_path: crwx
dir_name: lrw
*/



enum ModuleRights
{
    SFMOD_RIGHTS_GDI,
    SFMOD_RIGHTS_INPUT_KEY,
    SFMOD_RIGHTS_INPUT_TOUCH,
    SFMOD_RIGHTS_TIMER,
    SFMOD_RIGHTS_MEDIA,
    SFMOD_RIGHTS_NETWORK,
    SFMOD_RIGHTS_SEND_SMS,
    SFMOD_RIGHTS_MAKE_CALL,
    SFMOD_RIGHTS_LISTEN_SMS,
    SFMOD_RIGHTS_LISTEN_CALL,
    
    SFMOD_RIGHTS_VFS_CARD,
    SFMOD_RIGHTS_VFS_LOCAL,
    SFMOD_RIGHTS_VFS_PRIV,
    SFMOD_RIGHTS_VFS_SYS,
    SFMOD_RIGHTS_VFS_PUB,
    SFMOD_RIGHTS_VFS_DATA,
    SFMOD_RIGHTS_VFS_HOME,
    SFMOD_RIGHTS_VFS_TMP,
    SFMOD_RIGHTS_VFS_APP,
    SFMOD_RIGHTS_VFS_CONF,

    SFMOD_RIGHTS_LAST,
    SFMOD_RIGHTS_END=0xFFFF,
    __SFMOD_RIGHTS__INT32__=0x7FFFFFFF
};

#define HAS_RIGHT(mod,right)    ((mod)->iRight[(right)>>4]&(1<<((right)&0xF)))
#define AM_HAS_RIGHT(right)     ((g_kernal.iActiveModule)->iRight[(right)>>4]&(1<<((right)&0xF)))
#define SET_RIGHT(mod,right)    ((mod)->iRight[(right)>>4]|=(1<<((right)&0xF)))
#define CLR_RIGHT(mod,right)    ((mod)->iRight[(right)>>4]&=~(1<<((right)&0xF)))



#define SF_DEFAULT_NO_RIGHTS    SFNull

const SFUint16 SF_DEFAULT_APP_RIGHTS[]=
{
    SFMOD_RIGHTS_GDI,
    SFMOD_RIGHTS_INPUT_KEY,
    SFMOD_RIGHTS_INPUT_TOUCH,
    SFMOD_RIGHTS_TIMER,
    SFMOD_RIGHTS_MEDIA,
    SFMOD_RIGHTS_NETWORK,
    SFMOD_RIGHTS_SEND_SMS,
    SFMOD_RIGHTS_MAKE_CALL,
    
    SFMOD_RIGHTS_END
};



const static SFBuiltInApp s_builtin_module[]=
{
#if defined(SFCUST_BUILTIN_APP_LIST)
    SFCUST_BUILTIN_APP_LIST
#endif //SFCUST_BUILTIN_APP_LIST
    {0,0,0,SFNull,SFNull}
};


enum
{
    SFMOD_STATE_NONE=0,
    SFMOD_STATE_CREATING=1,    
    SFMOD_STATE_RUNNING=2,
    SFMOD_STATE_SUSPENDING=3,
    SFMOD_STATE_WAITING=4,
    SFMOD_STATE_DYING=5,
    SFMOD_STATE_DEAD=6
};

typedef struct _SFDeviceKeyMap
{
    SFUint8 iDeviceKey;
    SFUint8 iSFKey;
} SFDeviceKeyMap;

#define _DEVICE_KEY_LAST_ 0xFF


struct _SFModule;
struct _SFEventObject;

typedef struct _SFModule SFModule;
typedef struct _SFEventObject SFEventObject;

#ifdef SFCUST_COMPACT_RAM
#define MAX_WAIT_EVENTS 48
#define WAIT_EVENT_TABLE_SIZE     17
#else //SFCUST_COMPACT_RAM
#define MAX_WAIT_EVENTS 64
#define WAIT_EVENT_TABLE_SIZE     23
#endif //SFCUST_COMPACT_RAM


struct _SFModule
{
    ISFApplication* pApplication;
    SFInt iRefCount;
    SFUint16 iFlag;
    SFUint16 iRight[(SFMOD_RIGHTS_LAST+15)/16];

    //for mtk target
    SFUint16 iScrId;
    
    SFUint8 iState;
    SFUint8 iType;
    SFUint8 iNetworkAccountId;

    int iLastError;
    SFModId iModId;
    const SFDeviceKeyMap* iKeyStateMap;

    void* iLocalHeap;           //!< used by legacy applications, new applications must use the gloabl heap
    SFUint32 iLocalHeapSize;    //!< used by legacy applications, new applications must use the gloabl heap

    SFEModule* iEModule;        //!< used by external modules
};

enum
{
    SF_EVT_OBJECT=0,
    SF_EVT_WAIT_OBJECT=1
};

struct _SFEventObject
{
    SFEventObject *pNext;
    SFUint8 iType;
    SFReason* iReason;
    SFModule* iModule;
    union SFEventObjectParam
    {
        SFCallback iCallback;
        struct EventData
        {
            SFModule* iModuleFrom;
            SFInt iEvent;
            SFLPARAM lParam;
            SFWPARAM wParam;
        } iEvent;
    } iParam;
};

typedef struct _SFTimerInfo
{
    SFModule* iMod;
    ISFApplication* pHandler;
    SFTIMER_ID iTimerId;
    SFInt iExpiredTime;
    SFInt8 bOnce;
    SFInt8 iIdx;
} SFTimerInfo;

#define SF_MAX_TIMERS       4

#ifdef SFCUST_COMPACT_RAM
#define SF_MAX_APPS         2
#define SF_MAX_SERVICES     2
#else //SFCUST_COMPACT_RAM
#define SF_MAX_APPS         4
#define SF_MAX_SERVICES     8
#endif 

typedef struct _SFAppKernal
{
    
    SFTimerInfo iTimerInfoPool[SF_MAX_TIMERS];
    SFModule* iActiveApp;
    SFModule* iActiveModule;
    SFModule* iSmsModule;//!< 当前短信处理模块，同一时刻只能有一个模块处理短信
    SFUint16 iSmsPsedoId;

    ISFApplication* pSmsHandler;
    
    SFUint32 iKeyState;
    
    SFInt8 bWavPlaying;
    SFInt8 bMidiPlaying;
    SFInt8 bFilePlaying;
    SFInt8 bSavToneState;
    SFUint8 iVolume;//saved volume fo this module

    SFBool bActivated;//!< whether the sf app system is activated

    SFModule iModulePool[SF_MAX_APPS+SF_MAX_SERVICES+1];//the 0-index is the idle app, iActiveApp or iActiveModule must not be null. if either is invalid then the value will be  &iModulePool[0]   
    SFModule* iModuleFreeList;

    SFModule* iAppStack[SF_MAX_APPS];
    SFInt8 iAppSP;
    
    SFModule* iService[SF_MAX_SERVICES];

    SFEventObject iEventObjectPool[MAX_WAIT_EVENTS];
    SFEventObject* iFreeEventObject;
    SFEventObject* iEventObjectExecChain;
    SFEventObject* iEventObjectExecChainLast;
    
    SFEventObject* iEventObjectHash[WAIT_EVENT_TABLE_SIZE];
    
} SFAppKernal;

static SFAppKernal g_kernal;
static kal_bool g_bRotate90 = KAL_TRUE;


#define ENTER_MODULE(mod)  { SFModule* _sav_module=g_kernal.iActiveModule;g_kernal.iActiveModule=(mod);(mod)->iState=SFMOD_STATE_RUNNING;
#define LEAVE_MODULE()  g_kernal.iActiveModule->iState=SFMOD_STATE_SUSPENDING;g_kernal.iActiveModule=_sav_module; }

#define IDLE_MODULE     (&g_kernal.iModulePool[0])
#define ACTIVE_MODULE   g_kernal.iActiveModule


void dbg_last_evt_(int v)
{
    sf_dbgprintf(L"%d 0x%08x 0x%08x",v,g_kernal.iEventObjectExecChainLast,g_kernal.iEventObjectExecChain);
}

static SFEventObject* SFEventObject_Alloc(void)
{
    dbg_last_evt();
    if(g_kernal.iFreeEventObject)
    {
        SFEventObject* obj=g_kernal.iFreeEventObject;
        g_kernal.iFreeEventObject=obj->pNext;
        //sf_dbgprintf(L"SFEventObject_Alloc 0x%08x 0x%08x",obj,g_kernal.iFreeEventObject);
        return obj;
    }
    return SFNull;
}

static void SFEventObject_Free(SFEventObject* obj)
{
    if(!obj)
        return;
    dbg_last_evt();
    //sf_dbgprintf(L"SFEventObject_Free 0x%08x",obj);
    obj->pNext=g_kernal.iFreeEventObject;
    g_kernal.iFreeEventObject=obj;
}

static void SFEventObject_InitFreeList(void)
{
    int i;
    for(i=0;i<MAX_WAIT_EVENTS;i++)
    {
        SFEventObject_Free(&g_kernal.iEventObjectPool[i]);
    }
    dbg_last_evt();
}

SFReason SFSystem_UnloadModule(SFModule* pMod);
extern SFReason SFSystem_LoadEModule(UString path,SFEModule** ppEMod);
extern SFReason SFSystem_UnloadEModule(SFEModule* pEMod);

static void SFSystem_ExecPendingEvents(void)
{
    SFEventObject* obj,* temp;
    //sf_dbgprintf(L"exec chain 0x%08x",(int)g_kernal.iEventObjectExecChain);
    obj=g_kernal.iEventObjectExecChain;
    while(obj!=SFNull)
    {
        SFDEBUG("SFSystem_ExecPendingEvents 1");
        
        g_kernal.iEventObjectExecChain=SFNull;
        g_kernal.iEventObjectExecChainLast=SFNull;

        while(obj!=SFNull)
        {
            if(obj->iType==SF_EVT_WAIT_OBJECT)
            {
                if(obj->iParam.iCallback.iCallback)
                {
                    ENTER_MODULE(obj->iModule)
                    obj->iParam.iCallback.iCallback(obj->iParam.iCallback.iParam);
                    LEAVE_MODULE()
                }
            }
            else if(obj->iType==SF_EVT_OBJECT)
            {
                if(obj->iParam.iEvent.iEvent==EVT_APP_DESTROY)
                {
                    obj->iModule->iState=SFMOD_STATE_DYING;
                    if(obj->iModule==g_kernal.iActiveApp)
                    {
                        sf_dbgprintf(L"destroy A");
                        
                        ENTER_MODULE(obj->iModule)
                            GoBackHistory();
                        LEAVE_MODULE()
                    }
                    else
                    {
                        sf_dbgprintf(L"destroy B");
                        SFSystem_UnloadModule(obj->iModule);
                    }
                }
                else
                {
                    sf_dbgprintf(L"evt %d",obj->iParam.iEvent.iEvent);
                    
                    if(obj->iModule->pApplication && obj->iModule->pApplication->pfnEvtHandler)
                    {
                        ENTER_MODULE(obj->iModule)
                        (*obj->iModule->pApplication->pfnEvtHandler)(obj->iModule->pApplication,
                            obj->iParam.iEvent.iEvent,
                            obj->iParam.iEvent.lParam,
                            obj->iParam.iEvent.wParam);
                        LEAVE_MODULE()
                    }
                }
            }
            temp=obj->pNext;
            //remove object
            SFEventObject_Free(obj);
            obj=temp;
        }
        obj=g_kernal.iEventObjectExecChain;
    }
}


#define POST_EVENT_PROCESS()    SFSystem_ExecPendingEvents();



static void SFSystem_AddPengingEvent(SFEventObject* obj)
{
    
    
    obj->pNext=SFNull;

    if(g_kernal.iEventObjectExecChainLast)
    {
        SFDEBUG("SFSystem_AddPengingEvent B");
        
        g_kernal.iEventObjectExecChainLast->pNext=obj;
    }
    else
    {
        SFDEBUG("SFSystem_AddPengingEvent A");
        
        g_kernal.iEventObjectExecChain=obj;
        g_kernal.iEventObjectExecChainLast=obj;
    }
}

static SFReason SFSystem_PostMessageTo(SFModule* mod,SFInt event,SFLPARAM lParam,SFWPARAM wParam)
{
    SFEventObject* evt=SFEventObject_Alloc();
    if(!evt)
    {
        SFDEBUG("SFSystem_PostMessageTo:SFReasonOutOfResource");
        return SFReasonOutOfResource;
    }
    evt->iType=SF_EVT_OBJECT;
    evt->iModule=mod;
    evt->iParam.iEvent.iModuleFrom=g_kernal.iActiveModule;
    evt->iParam.iEvent.iEvent=event;
    evt->iParam.iEvent.lParam=lParam;
    evt->iParam.iEvent.wParam=wParam;
    
    SFSystem_AddPengingEvent(evt);
    return SFReasonOK;
}


#define EVENT_HASH(p)   ((int)((int)p>>2)%WAIT_EVENT_TABLE_SIZE)

static SFEventObject* SFSystem_RemoveWaitEventHash(SFReason* aReason)
{
    SFEventObject* obj;
    int h=EVENT_HASH(aReason);
    
    if((obj=g_kernal.iEventObjectHash[h])!=SFNull)
    {
        SFEventObject** ppObj=&g_kernal.iEventObjectHash[h];
        do
        {
            if(obj->iReason==aReason)
            {
                //then the obejct should be removed
                *ppObj=obj->pNext;
                return obj;
            }
            ppObj=&obj->pNext;
            obj=*ppObj;
        } while(obj!=SFNull);

    }
    return SFNull;
}

static void SFSystem_AddWaitEventHash(SFEventObject* obj)
{
    int h=EVENT_HASH(obj->iReason);
    obj->pNext=g_kernal.iEventObjectHash[h];
    g_kernal.iEventObjectHash[h]=obj;
}

SFReason SFSystem_WaitFor(SFReason* aReason,const SFCallback* cb)
{
    if(aReason)
    {
        SFEventObject* evt=SFEventObject_Alloc();
        if(!evt)
            return SFReasonOutOfResource;
        evt->iType=SF_EVT_WAIT_OBJECT;
        evt->iModule=g_kernal.iActiveModule;
        if(cb)
        {
            evt->iParam.iCallback=*cb;
        }
        else
        {
            evt->iParam.iCallback.iCallback=SFNull;
            evt->iParam.iCallback.iParam=SFNull;
        }
            
        evt->iReason=aReason;
        if(*aReason==SFReasonPending)
        {
            //wait
            SFSystem_AddWaitEventHash(evt);
        }
        else
        {
            //just exec
            SFSystem_AddPengingEvent(evt);
        }
        return SFReasonOK;
    }
    else
    {
        return SFReasonBadParameter;
    }
}



void SFSystem_NotifyAll(SFReason* aReason)
{
    //wake up all the modules
    if(aReason)
    {
        SFEventObject* obj;
        while((obj=SFSystem_RemoveWaitEventHash(aReason))!=SFNull)
        {
            SFSystem_AddPengingEvent(obj);
        }
    }
}

void SFSystem_NotifyAllV(SFReason* aReason,SFReason aV)
{
    if(aReason)
    {
        SFEventObject* obj;
        *aReason=aV;
        while((obj=SFSystem_RemoveWaitEventHash(aReason))!=SFNull)
        {
            SFSystem_AddPengingEvent(obj);
        }
    }
}

void SFSystem_Cancel(SFReason* aReason)
{
    SFEventObject* obj;
    while((obj=SFSystem_RemoveWaitEventHash(aReason))!=SFNull)
    {
        SFEventObject_Free(obj);
    }
}


SFAnyPtr SFSystem_Alloc(SFSize_T newSize)
{
#if defined(SFAPI_WIN)
    return med_alloc_ext_mem(newSize);
#elif defined(SFCUST_SYSALLOC_USE_MEDIA_SPACE)
    return med_alloc_ext_mem(newSize);
#elif defined(SFCUST_SYSALLOC_USE_MANAGED_SPACE)
    //pass
#else
    return SFNull;
#endif
}

SFAnyPtr SFSystem_Realloc(SFAnyPtr ptr,SFSize_T newSize)
{
    ptr=ptr;
    newSize=newSize;
    
    return SFNull;
}

void SFSystem_Free(SFAnyPtr p)
{
#if defined(SFAPI_WIN)
    med_free_ext_mem(&p);
#elif defined(SFCUST_SYSALLOC_USE_MEDIA_SPACE)
    med_free_ext_mem(&p);
#elif defined(SFCUST_SYSALLOC_USE_MANAGED_SPACE)
    //pass
#else
    //pass
#endif
}


SFReason SFSystem_SetPerfs(SFCLSID perf,const void* data,SFSize_T size)
{
    UNUSED_PARAM(perf);
    UNUSED_PARAM(data);
    UNUSED_PARAM(size);
    return SFReasonNotSupported;
}
SFReason SFSystem_GetPerfs(SFCLSID perf,void* data,SFSize_T size)
{
    UNUSED_PARAM(perf);
    UNUSED_PARAM(data);
    UNUSED_PARAM(size);
    return SFReasonNotSupported;
}
SFReason SFApp_SavePerfs(const void* data,SFSize_T size)
{
    UNUSED_PARAM(data);
    UNUSED_PARAM(size);
    return SFReasonNotSupported;
}
SFReason SFApp_GetPerfs(void* data,SFSize_T size)
{
    UNUSED_PARAM(data);
    UNUSED_PARAM(size);
    return SFReasonNotSupported;
}



#if defined(__SF_KEYPAD_SUPPORT__)
static SFUint8 s_bKeypadEnable=1;

#define KEYPAD_UART_PORT    SFCUST_KEYPAD_UART_PORT
#define MAX_KEYPAD_BUFFER_SIZE  64
#define MAX_KEYPAD_KEYS 16

static int bytes_in_buffer=0;//must be cleared when starting
static SFUint8 keypad_buffer[MAX_KEYPAD_BUFFER_SIZE];
static SFUint32 keypad_data=0;//must be cleared

static void SFKeypad_Clear(void);

#endif //defined(__SF_KEYPAD_SUPPORT__)



#if defined(SFCUST_SFAPP_STATIC_HEAP) && !defined(SFCUST_APPPLAT_STATIC_HEAP)
SFUint64 s_sfap_wrkmem[SF_DEFAULT_WORKMEM_SIZE*1024/sizeof(SFUint64)];
#endif


void SFDEBUG(const char*str)
{
#if defined(MMI_ON_HARDWARE_P) || defined(SFAPI_WIN)
    kal_prompt_trace(SFCUST_TRACE_MOD,(char *)str);
#endif
}


static U16 u16_g_game_file_name[FMGR_PATH_BUFFER_SIZE/2];




static SFModule* SFSystem_AllocModule(void)
{
    if(g_kernal.iModuleFreeList)
    {
        SFModule* mod=g_kernal.iModuleFreeList;
        g_kernal.iModuleFreeList=*(SFModule**)mod;
        return mod;
    }
    return SFNull;
}
static void SFSystem_FreeModule(SFModule*mod)
{
    if(mod==IDLE_MODULE)
        return;
    *(SFModule**)mod=g_kernal.iModuleFreeList;
    g_kernal.iModuleFreeList=mod;
    mod->iState=SFMOD_STATE_NONE;
}

static void SFSystem_InitModuleFreeList(void)
{
    int i;
    g_kernal.iModuleFreeList=SFNull;
    for(i=1;i<=SF_MAX_APPS+SF_MAX_SERVICES;i++)
    {
        SFSystem_FreeModule(&g_kernal.iModulePool[i]);
    }
}


SFReason SFSystem_PushApplication(SFModule* pApp)
{
    dbg_last_evt();
    
    if(g_kernal.iAppSP<SF_MAX_APPS-1)
    {
        if(g_kernal.iActiveApp!=IDLE_MODULE)
        {
            ++g_kernal.iAppSP;
            g_kernal.iAppStack[g_kernal.iAppSP]=g_kernal.iActiveApp;
        }
        g_kernal.iActiveApp=pApp;
        return SFReasonOK;
    }
    else
    {
        return SFReasonOutOfResource;
    }
}

SFReason SFSystem_PopApplication(void)
{
    if(g_kernal.iAppSP>=0)
    {
        g_kernal.iActiveApp=g_kernal.iAppStack[g_kernal.iAppSP];
        g_kernal.iAppStack[g_kernal.iAppSP]=SFNull;
        --g_kernal.iAppSP;
    }
    else
    {
        if(g_kernal.iActiveApp==IDLE_MODULE)
        {
            return SFReasonOutOfRange;
        }
        g_kernal.iActiveApp=IDLE_MODULE;
    }
    return SFReasonOK;
}



SFModId SFSystem_GetCurrentModuleId(void)
{
    if(g_kernal.iActiveModule)
    {
        return g_kernal.iActiveModule->iModId;
    }
    return 0;
}

void SFSystem_SwitchApp(SFModule* pMod)
{
    if(g_kernal.iActiveApp)
    {
    }
    //g_kernal.pApplication=pMod->pApplication;
    g_kernal.iActiveApp=pMod;
    if(g_kernal.iActiveApp)
    {
    }
}


/*Output voice only through earphone when earphone plugged*/
extern U8 isEarphonePlugged;

extern U8 gactivatedprofile;

#if defined(__IMT_LCD_ROTATE_MMI__)
extern U8 gMMILcdRotateState;
#endif
/*****************************************************************************************************
  *inner function declaration
  ****************************************************************************************************/

static void SFFS_Cleanup(SFModule* pMod);
static void SFApp_KeyHandler(S32 aKey,S32 aKeyState);
void SFApp_FreeGDI(void);
void* sf_system_malloc_fast(unsigned int size); 
void sf_system_free_fast(void*ptr);
void* sf_system_malloc(unsigned int size);
void sf_system_free(void*ptr);


#if 0
/**
* @brief 关闭请求，不是用户方法
*/
void SFApp_Terminate(void)
{
	GoBackHistory();//?
}
#endif //0


void SFSystem_PreDestroyModule(SFModule* pMod);

/**
* @brief 表示应用主动要求退出，系统随后应该发送EVT_APP_DESTORY消息
*/
void SFApp_Exit(void)
{
	//send the destroy message first
	SFDEBUG("SFApp_Exit");
    if(g_kernal.iActiveModule->iState==SFMOD_STATE_DYING
        || g_kernal.iActiveModule->iState==SFMOD_STATE_DEAD)
    {
        SFDEBUG("Already Exit");
        return;
    }
    //SFSystem_PreDestroyModule(g_kernal.iActiveModule);
    g_kernal.iActiveModule->iState=SFMOD_STATE_DYING;
    
    SFSystem_PostMessageTo(g_kernal.iActiveModule,EVT_APP_DESTROY,0,0);
}


/**
* @brief 获取系统的屏幕缓冲区
* @return 屏幕缓冲区指针
*/
SFNColor* SFScreen_GetBuffer(void)
{
#ifndef SFAPI_WIN
    extern U32 gdi_base_layer_buffer_pool[];
#endif
    void*ptr;
    if(AM_HAS_RIGHT(SFMOD_RIGHTS_GDI))
    {
#ifndef SFAPI_WIN
        if((g_kernal.iActiveModule->iFlag&SFMOD_ATTR_FAST_SCREEN_UPDATE))
        {
    	    return (SFNColor*)gdi_base_layer_buffer_pool;
        }
        else
#endif
        {
    	    gdi_layer_get_buffer_ptr((U8**)&ptr);
            return (SFNColor*)ptr;
        }
    }
    else
    {
        return SFNull;
    }
}


/**
* @brief 获取系统的屏幕宽度
* @return 屏幕宽度
*/
SFInt SFScreen_GetWidth(void)
{
	return LCD_WIDTH;
}


/**
* @brief 获取系统的屏幕高度
* @return 屏幕高度
*/
SFInt SFScreen_GetHeight(void)
{
	return LCD_HEIGHT;
}


static int s_lock_gdi=0;
static char s_bFastScreenUpdate=0;

/**
* @brief 把系统的屏幕缓冲区内容刷新到前台（实际屏幕）
*/
void SFScreen_Update(void)
{
    if(AM_HAS_RIGHT(SFMOD_RIGHTS_GDI) /* && g_kernal.iActiveModule==g_kernal.iActiveApp */)
    {
    	if(s_bFastScreenUpdate && s_lock_gdi)
    	{
            
#if defined(HW_USE_VIM_DSP)
            U32 sav=*(volatile U32*)0x90000018;
            *(volatile U32*)0x90000018=0x08002100;
            lcd_power_up();
    	    START_LCD_TRANSFER;
            while(LCD_IS_RUNNING) /* loop */;
            *(volatile U32*)0x90000018=sav;
#else
            
            while(LCD_IS_RUNNING) /* wait */;
            lcd_power_up();
        	START_LCD_TRANSFER;
            //
#endif
    	}
    	else
    	{
    		gdi_layer_blt_previous(0, 0,LCD_WIDTH, LCD_HEIGHT);
    	}
    }
}

SFReason SFScreen_GetInfo(SFScreenInfo* pInfo)
{
    if(!pInfo)
        return SFReasonBadParameter;
    if(pInfo->iScreenId!=SF_MAIN_SCREEN)
        return SFReasonNotFound;
    pInfo->iFlags=0;
    pInfo->iFormat=SF_PIXELFORMAT_RGB565;
    pInfo->iWidth=(SFInt16)LCD_WIDTH;
    pInfo->iHeight=(SFInt16)LCD_HEIGHT;
    pInfo->iPitch=pInfo->iWidth;
    pInfo->pBits=(void*)SFScreen_GetBuffer();
    return SFReasonOK;
}

SFReason SFScreen_UpdateEx(SFInt id,SFInt x,SFInt y,SFInt w,SFInt h)
{
    if(id!=SF_MAIN_SCREEN)
        return SFReasonNotSupported;
    if(w<=0 || h<=0)
        return SFReasonOK;
    if(AM_HAS_RIGHT(SFMOD_RIGHTS_GDI) /* && g_kernal.iActiveModule==g_kernal.iActiveApp */)
    {
        if(s_bFastScreenUpdate && s_lock_gdi)
        {
            while(LCD_IS_RUNNING) /* wait */;
            lcd_power_up();
            START_LCD_TRANSFER;
        }
        else
        {
            gdi_layer_blt_previous(x, y,x+w, y+h);
        }
    }
    return SFReasonOK;
}

static SFGDIFont s_gdi_font;

void SFFont_SetFont(const SFGDIFont* pFont)
{
    stFontAttribute fnt;
    
    s_gdi_font=*pFont;
    
    fnt.bold=pFont->iStyle&SF_GDI_FONT_STYLE_BOLD;
    fnt.underline=pFont->iStyle&SF_GDI_FONT_STYLE_UNDERLINE;
    fnt.italic=pFont->iStyle&SF_GDI_FONT_STYLE_ITALIC;
    fnt.oblique=pFont->iStyle&SF_GDI_FONT_STYLE_OBLIQUE;
    fnt.smallCaps=pFont->iStyle&SF_GDI_FONT_STYLE_STRIKETHROUGH;
    fnt.color=0;
    fnt.type=1;
    switch(pFont->iSize)
    {
    case SF_GDI_FONT_SIZE_SMALL:
        fnt.size=SMALL_FONT;
        break;
    default:
    case SF_GDI_FONT_SIZE_MEDIUM:
        fnt.size=MEDIUM_FONT;
        break;
    case SF_GDI_FONT_SIZE_LARGE:
        fnt.size=LARGE_FONT;
        break;
    }
    gui_set_font(&fnt);
}

void SFFont_GetFont(SFGDIFont* pFont)
{
    *pFont=s_gdi_font;
}

SFInt SFFont_GetHeight(void)
{
	return (SFInt)gui_get_character_height();
}


SFInt SFFont_GetCharWidth(UChar aChar)
{
	SFInt width=0,height=0;
	U8 buf[4]={0,0,0,0};
	buf[0]=(U8)((aChar)&0xff);
	buf[1]=(U8)((aChar>>8) & 0xff);
	
	gui_measure_string_n((UI_string_type)buf,1,&width,&height);
	return width;
}

extern int sf_strlen(UString str);

SFInt SFFont_GetStringWidth(UString aStr,SFInt aLength)
{
    SFInt width=0,height=0;//,i;
    if(aLength<0)
    {
        aLength=sf_strlen(aStr);
    }
    if(aLength<=0)
        return 0;

    gui_measure_string_n((UI_string_type)aStr,aLength,&width,&height);
    return width;
}

void SFScreen_SetClip(SFInt x,SFInt y,SFInt w,SFInt h)
{
	gdi_layer_set_clip(x,y,x+w,y+h);
}

void SFScreen_ResetClip(void)
{
	gdi_layer_reset_clip();
}


extern void SetLeftSoftkeyFunction(void (*f)(void),MMI_key_event_type k);
extern void SetKeyHandler(FuncPtr funcPtr, U16 keyCode, U16 keyType);

static void SFTimer_StopSysTimer(int idx);
static void SFTimer_StartSysTimer(int idx,int atime);
static void SFTimer_FreeSlot(int i);

static void SFNesEmuApp_ResetKeyMap(void);

static void SFTimer_Callback(int idx)
{
    SFTimerInfo* pInfo=&g_kernal.iTimerInfoPool[idx];
    SFModule* pMod=pInfo->iMod;
    ISFApplication* pHandler=pInfo->pHandler;
    SFLPARAM idTimer=(SFLPARAM)pInfo->iTimerId;
    if(!pMod || !pHandler || !pHandler->pfnEvtHandler)
    {
        SFTimer_FreeSlot(pInfo->iIdx);
        return;
    }
    
	if(pInfo->bOnce)
	{
        SFTimer_FreeSlot(pInfo->iIdx);
	}
	else
	{
        SFTimer_StartSysTimer(pInfo->iIdx,pInfo->iExpiredTime);
	}
	//call the handler
    ENTER_MODULE(pMod)
    (*pHandler->pfnEvtHandler)(pHandler,EVT_TIMER,idTimer,(SFWPARAM)0);
    LEAVE_MODULE()

    POST_EVENT_PROCESS()

#ifdef __SF_MTK_APPLICATION_EMU__ENABLE__
    if(pMod->iModId==SFMODID_GAME_NESEMU)
    {
        SFNesEmuApp_ResetKeyMap();
    }
#if defined(__SF_MTK_APPLICATION_EMU__FREEGAMES__)
    if(pMod->iModId==SFMODID_GAME_NESEMUF)
    {
        SFNesEmuApp_ResetKeyMap();
    }
#endif //defined(__SF_MTK_APPLICATION_EMU__FREEGAMES__)
#endif //__SF_MTK_APPLICATION_EMU__ENABLE__
}

static void SFTimer_Callback0(void) { SFTimer_Callback(0); }
static void SFTimer_Callback1(void) { SFTimer_Callback(1); }
static void SFTimer_Callback2(void) { SFTimer_Callback(2); }
static void SFTimer_Callback3(void) { SFTimer_Callback(3); }

static SFTimerInfo* SFTimer_AllocSlot(void)
{
    int i;
    for(i=0;i<4;i++)
    {
        if(g_kernal.iTimerInfoPool[i].pHandler==NULL)
        {
            g_kernal.iTimerInfoPool[i].iIdx=(SFInt8)i;
            return &g_kernal.iTimerInfoPool[i];
        }
    }
    return NULL;
}

typedef void (* func_void__void)(void);

static const func_void__void s_timer_funcs[]=
{
    &SFTimer_Callback0,
    &SFTimer_Callback1,
    &SFTimer_Callback2,
    &SFTimer_Callback3
};


static void SFTimer_StartSysTimer(int idx,int atime) { gui_start_timer(atime,s_timer_funcs[idx]); }

static void SFTimer_StopSysTimer(int idx) { gui_cancel_timer(s_timer_funcs[idx]); }

static SFTimerInfo* SFTimer_FromSlot(int id)
{
    int i;
    for(i=0;i<4;i++)
    {
        if(g_kernal.iTimerInfoPool[i].iMod!=NULL && g_kernal.iTimerInfoPool[i].iTimerId==(SFTIMER_ID)id)
        {
            return &g_kernal.iTimerInfoPool[i];
        }
    }
    return NULL;
}

static void SFTimer_FreeSlot(int i)
{
    if(i>=0 && i<4)
    {
        if(g_kernal.iTimerInfoPool[i].iMod!=NULL)
        {
            SFTimer_StopSysTimer(i);
            g_kernal.iTimerInfoPool[i].pHandler=NULL;
            g_kernal.iTimerInfoPool[i].iMod=NULL;
        }
    }
}



static void SFTimer_Initialize(void)
{
    int i;
    for(i=0;i<4;i++)
    {
        memset(&g_kernal.iTimerInfoPool[i],0,sizeof(SFTimerInfo));
        g_kernal.iTimerInfoPool[i].iIdx=(SFInt8)i;
    }
}

static void SFTimer_Cleanup(SFModule* pMod)
{
    int i;
    for(i=0;i<4;i++)
    {
        if(!pMod || g_kernal.iTimerInfoPool[i].iMod==pMod)
        {
            SFTimer_StopSysTimer(i);
            memset(&g_kernal.iTimerInfoPool[i],0,sizeof(SFTimerInfo));
            g_kernal.iTimerInfoPool[i].iIdx=(SFInt8)i;
        }
    }
}

SFReason SFTimer_StartEx(SFTIMER_ID idTimer,int nExpiredTime,SFBool bOnce,ISFApplication*pHandler)
{
    SFTimerInfo* info=SFTimer_AllocSlot();
    if(!info)
        return SFReasonOutOfResource;
    info->bOnce=(SFInt8)bOnce;
    info->iExpiredTime=nExpiredTime;
    info->iTimerId=idTimer;
    info->iMod=g_kernal.iActiveModule;
    info->pHandler=pHandler;

    SFTimer_StartSysTimer(info->iIdx,nExpiredTime);
    return SFReasonOK;
}


/**
* @brief 启动一个定时器
* @param idTimer - IN 定时器ID
* @param nExpiredTime - IN 以毫秒为单位的定时时间
* @param bOnceOrPeriod - IN YSTrue 表示定时器只有效一次，YSFalse 表示按指定间隔反复发出信号
*/
void SFTimer_Start(SFTIMER_ID idTimer,SFInt nExpiredTime,SFBool bOnce,ISFApplication*pHandler)
{
    SFTimer_StartEx(idTimer,nExpiredTime,bOnce,pHandler);
}


/**
* @brief 停止指定的定时器
* @param idTimer - IN 定时器ID
*/
void SFTimer_Stop(SFTIMER_ID idTimer)
{
    SFTimerInfo* info=SFTimer_FromSlot(idTimer);
	if(info)
	{
        SFTimer_FreeSlot(info->iIdx);
	}
}


/**
* @brief 获取游戏中可分配的连续空间首地址
* @return 取得的空间首地址
*/
SFAnyPtr SFSystem_GetHeap(void)
{
	return g_kernal.iActiveModule->iLocalHeap;
}

/**
* @brief 获取游戏中可分配的连续空间大小
* @return 空间的大小
*/
SFSize_T SFSystem_GetHeapSize(void)
{
	return g_kernal.iActiveModule->iLocalHeapSize;
}


static SFUint8 s_prev_get_millis=0;
static SFUint64 s_prev_time_in_ticks=0;
    
SFUint64 SFOS32_GetCurrentTimeMillis(void)
{
    kal_uint32 time_in_ticks;
    kal_uint64 ctm;
    kal_get_time(&time_in_ticks);
    if(s_prev_get_millis)
    {
        ctm=s_prev_time_in_ticks;
        if(time_in_ticks<(SFUint32)ctm)
        {
            ctm+=0x100000000ULL;
        }
        ctm=(ctm&0xFFFFFFFF00000000ULL)|time_in_ticks;
    }
    else
    {
        s_prev_get_millis=1;
        ctm=time_in_ticks;
    }
    s_prev_time_in_ticks=ctm;
    return ctm*4615/1000;
}



static void sf_vfs_init(void);
static void SFSystem_NetInitialize(void);
static void SFFS_Initialize(void);


static char s_kernal_inited=0;

static void s_idle_module_proc(ISFApplication*pApp,SFEVT_ID idEvent,SFLPARAM lParam,SFWPARAM wParam) 
{
    UNUSED_PARAM(pApp);
    UNUSED_PARAM(idEvent);
    UNUSED_PARAM(lParam);
    UNUSED_PARAM(wParam);
}

static ISFApplication s_idle_module[]={{&s_idle_module_proc}};

static void SFSysTimer_Initialize(void);
static int _socket_handler(void* msg);
static void SFSocket_gethostbyname_work(void* msg);
static void CSFNetworkManager_OnGetAccountInfo(void* msg);
#if defined(WAP_SUPPORT)
static int SFSystem_HandleWapProfile(wap_get_bra_prof_id_rsp_struct* profile);
static int SFSystem_HandleWapProfileContent(wap_get_prof_content_rsp_struct* profile);
#endif //defined(WAP_SUPPORT)
static void SFSocketDNS_Initialize(void);
static void InitInternalFilePool(void);
static void SFSystem_InitCBTable(void);

int SFSystem_Initialize(void)
{
    if(s_kernal_inited)
        return 0;

    SFDEBUG("SFSystem_Initialize");
        
    s_kernal_inited=1;

    memset(&g_kernal,0,sizeof(SFAppKernal));
    memset(s_path_cache,0,sizeof(s_path_cache));

    SFSystem_InitCBTable();
    SFEventObject_InitFreeList();
    SFSystem_InitModuleFreeList();
    sf_vfs_init();
    SFFS_Initialize();
    SFSystem_NetInitialize();
    SFTimer_Initialize();
    SFSysTimer_Initialize();
    SFSocketDNS_Initialize();
    InitInternalFilePool();

    g_kernal.iVolume=GetRingVolumeLevel();
    
	g_kernal.bWavPlaying=SFFalse;
	g_kernal.bMidiPlaying=SFFalse;
    g_kernal.bFilePlaying=SFFalse;

    g_kernal.pSmsHandler=SFNull;
    g_kernal.iAppSP=-1;


    s_prev_get_millis=0;

    IDLE_MODULE->pApplication=s_idle_module;
    IDLE_MODULE->iFlag=SFMOD_ATTR_SYSTEM;
    memset(IDLE_MODULE->iRight,0xFF,sizeof(IDLE_MODULE->iRight));
    IDLE_MODULE->iNetworkAccountId=SFCUST_NET_ACCOUNT;

    g_kernal.iActiveApp=g_kernal.iActiveModule=IDLE_MODULE;


    dbg_last_evt();
#if defined(SFAPI_DEBUG_USE_PROTOCOL_EVENT)
    SetProtocolEventHandler((PsFuncPtr)&_socket_handler,MSG_ID_APP_SOC_NOTIFY_IND);
    SetProtocolEventHandler((PsFuncPtr)&SFSocket_gethostbyname_work,MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND);
#if defined(WAP_SUPPORT)
    SetProtocolEventHandler((PsFuncPtr)&SFSystem_HandleWapProfile,MSG_ID_WAP_GET_BRA_PROF_ID_RSP);
    SetProtocolEventHandler((PsFuncPtr)&SFSystem_HandleWapProfileContent,MSG_ID_WAP_GET_PROF_CONTENT_RSP);
#endif //defined(WAP_SUPPORT)
    SetProtocolEventHandler((PsFuncPtr)&CSFNetworkManager_OnGetAccountInfo,MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP);
#endif //defined(SFAPI_USE_PROTOCOL_EVENTS)
    return 0;
}


void SFApp_NetFinalize(void);


static void sf_vfs_fini(void);
static void SFSystem_NetFinalize(void);

void SFSystem_Finalize(void)
{

    SFDEBUG("SFSystem_Finalize");
    
    sf_vfs_fini();
    
    g_kernal.iKeyState=0;

    //gui_cancel_timer(SFTimer_Callback);
    SFTimer_Cleanup(SFNull);
    SFFS_Cleanup(SFNull);
    SFSystem_NetFinalize();

    //g_kernal.pApplication = SFNull;
    g_kernal.pSmsHandler = SFNull;
}

static const SFByte s_mapKey[MAX_KEYS] =
{
	SFKEY_NUM0,//KEY_0= 0,
	SFKEY_NUM1,//KEY_1,				
	SFKEY_NUM2,//KEY_2,				
	SFKEY_NUM3,//KEY_3,				
	SFKEY_NUM4,//KEY_4,				
	SFKEY_NUM5,//KEY_5,				
	SFKEY_NUM6,//KEY_6,				
	SFKEY_NUM7,//KEY_7,				
	SFKEY_NUM8,//KEY_8,				
	SFKEY_NUM9,//KEY_9,				
	SFKEY_SL,//KEY_LSK,			
	SFKEY_SR,//KEY_RSK,			
	SFKEY_SM,//KEY_CSK,
	SFKEY_UP,//KEY_UP_ARROW,			
	SFKEY_DOWN,//KEY_DOWN_ARROW,		
	SFKEY_LEFT,//KEY_LEFT_ARROW,		
	SFKEY_RIGHT,//KEY_RIGHT_ARROW,		
	SFKEY_NONE,//KEY_SEND,					
	SFKEY_NONE,//KEY_END,					
	SFKEY_CLR,//KEY_CLEAR,				
	SFKEY_STAR,//KEY_STAR,					
	SFKEY_POUND,//KEY_POUND,				
	SFKEY_NONE,//KEY_VOL_UP,				
	SFKEY_NONE,//KEY_VOL_DOWN,			
	SFKEY_NONE,//KEY_QUICK_ACS,KEY_CAMERA			
	SFKEY_NONE,//KEY_ENTER,KEY_WAP,KEY_IP					
	SFKEY_NONE,//KEY_EXTRA_1,
	SFKEY_NONE//KEY_EXTRA_2,
};

static void SfKey0_DownHandler(void) { SFApp_KeyHandler(KEY_0,KEY_EVENT_DOWN); }
static void SfKey0_UpHandler(void) { SFApp_KeyHandler(KEY_0,KEY_EVENT_UP); }
static void SfKey1_DownHandler(void) { SFApp_KeyHandler(KEY_1,KEY_EVENT_DOWN); }
static void SfKey1_UpHandler(void) { SFApp_KeyHandler(KEY_1,KEY_EVENT_UP); }
static void SfKey2_DownHandler(void){ SFApp_KeyHandler(KEY_2,KEY_EVENT_DOWN);}
static void SfKey2_UpHandler(void){ SFApp_KeyHandler(KEY_2,KEY_EVENT_UP);}
static void SfKey3_DownHandler(void){ SFApp_KeyHandler(KEY_3,KEY_EVENT_DOWN);}
static void SfKey3_UpHandler(void){ SFApp_KeyHandler(KEY_3,KEY_EVENT_UP);}
static void SfKey4_DownHandler(void){ SFApp_KeyHandler(KEY_4,KEY_EVENT_DOWN);}
static void SfKey4_UpHandler(void){ SFApp_KeyHandler(KEY_4,KEY_EVENT_UP);}
static void SfKey5_DownHandler(void){ SFApp_KeyHandler(KEY_5,KEY_EVENT_DOWN);}
static void SfKey5_UpHandler(void){ SFApp_KeyHandler(KEY_5,KEY_EVENT_UP);}
static void SfKey6_DownHandler(void){ SFApp_KeyHandler(KEY_6,KEY_EVENT_DOWN);}
static void SfKey6_UpHandler(void){ SFApp_KeyHandler(KEY_6,KEY_EVENT_UP);}
static void SfKey7_DownHandler(void){ SFApp_KeyHandler(KEY_7,KEY_EVENT_DOWN);}
static void SfKey7_UpHandler(void){ SFApp_KeyHandler(KEY_7,KEY_EVENT_UP);}
static void SfKey8_DownHandler(void){ SFApp_KeyHandler(KEY_8,KEY_EVENT_DOWN);}
static void SfKey8_UpHandler(void){ SFApp_KeyHandler(KEY_8,KEY_EVENT_UP);}
static void SfKey9_DownHandler(void){ SFApp_KeyHandler(KEY_9,KEY_EVENT_DOWN);}
static void SfKey9_UpHandler(void){ SFApp_KeyHandler(KEY_9,KEY_EVENT_UP);}
static void SfKeyLSK_DownHandler(void){ SFApp_KeyHandler(KEY_LSK,KEY_EVENT_DOWN);}
static void SfKeyLSK_UpHandler(void){ SFApp_KeyHandler(KEY_LSK,KEY_EVENT_UP);}
static void SfKeyRSK_DownHandler(void){ SFApp_KeyHandler(KEY_RSK,KEY_EVENT_DOWN);}
static void SfKeyRSK_UpHandler(void){ SFApp_KeyHandler(KEY_RSK,KEY_EVENT_UP);}
static void SfKeyEnter_DownHandler(void){ SFApp_KeyHandler(KEY_ENTER,KEY_EVENT_DOWN);}
static void SfKeyEnter_UpHandler(void){ SFApp_KeyHandler(KEY_ENTER,KEY_EVENT_UP);}
static void SfKeyUpArrow_DownHandler(void){ SFApp_KeyHandler(KEY_UP_ARROW,KEY_EVENT_DOWN);}
static void SfKeyUpArrow_UpHandler(void){ SFApp_KeyHandler(KEY_UP_ARROW,KEY_EVENT_UP);}
static void SfKeyDownArrow_DownHandler(void){ SFApp_KeyHandler(KEY_DOWN_ARROW,KEY_EVENT_DOWN);}
static void SfKeyDownArrow_UpHandler(void){ SFApp_KeyHandler(KEY_DOWN_ARROW,KEY_EVENT_UP);}
static void SfKeyLeftArrow_DownHandler(void){ SFApp_KeyHandler(KEY_LEFT_ARROW,KEY_EVENT_DOWN);}
static void SfKeyLeftArrow_UpHandler(void){ SFApp_KeyHandler(KEY_LEFT_ARROW,KEY_EVENT_UP);}
static void SfKeyRightArrow_DownHandler(void){ SFApp_KeyHandler(KEY_RIGHT_ARROW,KEY_EVENT_DOWN);}
static void SfKeyRightArrow_UpHandler(void){ SFApp_KeyHandler(KEY_RIGHT_ARROW,KEY_EVENT_UP);}
static void SfKeyStar_DownHandler(void){ SFApp_KeyHandler(KEY_STAR,KEY_EVENT_DOWN);}
static void SfKeyStar_UpHandler(void){ SFApp_KeyHandler(KEY_STAR,KEY_EVENT_UP);}
static void SfKeyPound_DownHandler(void){ SFApp_KeyHandler(KEY_POUND,KEY_EVENT_DOWN);}
static void SfKeyPound_UpHandler(void){ SFApp_KeyHandler(KEY_POUND,KEY_EVENT_UP);}
static void SfKeyClear_DownHandler(void){ SFApp_KeyHandler(KEY_CLEAR,KEY_EVENT_DOWN);}
static void SfKeyClear_UpHandler(void){ SFApp_KeyHandler(KEY_CLEAR,KEY_EVENT_UP);}
static void SfKeyEnd_DownHandler(void){ SFApp_KeyHandler(KEY_END,KEY_EVENT_DOWN);}
static void SfKeyVolUp_UpHandler(void) { SFApp_KeyHandler(KEY_VOL_UP,KEY_EVENT_UP); }
static void SfKeyVolUp_DownHandler(void) { SFApp_KeyHandler(KEY_VOL_UP,KEY_EVENT_DOWN); }
static void SfKeyVolDown_UpHandler(void) { SFApp_KeyHandler(KEY_VOL_DOWN,KEY_EVENT_UP); }
static void SfKeyVolDown_DownHandler(void) { SFApp_KeyHandler(KEY_VOL_DOWN,KEY_EVENT_DOWN);}
static void SfKeySend_UpHandler(void) { SFApp_KeyHandler(KEY_SEND,KEY_EVENT_UP); }
static void SfKeySend_DownHandler(void) { SFApp_KeyHandler(KEY_SEND,KEY_EVENT_DOWN);}
static void SfKeyPower_UpHandler(void) { SFApp_KeyHandler(KEY_POWER,KEY_EVENT_UP); }
static void SfKeyPower_DownHandler(void) { SFApp_KeyHandler(KEY_POWER,KEY_EVENT_DOWN);}


static void SFAppRegistKeyHandler(void)
{
    //如果MMI_DEVICE_KEY有问题，删除下列一行
    ClearInputEventHandler(MMI_DEVICE_KEY);
	   
	SetKeyHandler(SfKey0_DownHandler,KEY_0,KEY_EVENT_DOWN);
	SetKeyHandler(SfKey0_UpHandler,KEY_0,KEY_EVENT_UP);

	SetKeyHandler(SfKey1_DownHandler,KEY_1,KEY_EVENT_DOWN);
	SetKeyHandler(SfKey1_UpHandler,KEY_1,KEY_EVENT_UP);

	SetKeyHandler(SfKey2_DownHandler,KEY_2,KEY_EVENT_DOWN);
	SetKeyHandler(SfKey2_UpHandler,KEY_2,KEY_EVENT_UP);

	SetKeyHandler(SfKey3_DownHandler,KEY_3,KEY_EVENT_DOWN);
	SetKeyHandler(SfKey3_UpHandler,KEY_3,KEY_EVENT_UP);

	SetKeyHandler(SfKey4_DownHandler,KEY_4,KEY_EVENT_DOWN);
	SetKeyHandler(SfKey4_UpHandler,KEY_4,KEY_EVENT_UP);

	SetKeyHandler(SfKey5_DownHandler,KEY_5,KEY_EVENT_DOWN);
	SetKeyHandler(SfKey5_UpHandler,KEY_5,KEY_EVENT_UP);


	SetKeyHandler(SfKey6_DownHandler,KEY_6,KEY_EVENT_DOWN);
	SetKeyHandler(SfKey6_UpHandler,KEY_6,KEY_EVENT_UP);

	SetKeyHandler(SfKey7_DownHandler,KEY_7,KEY_EVENT_DOWN);
	SetKeyHandler(SfKey7_UpHandler,KEY_7,KEY_EVENT_UP);


	SetKeyHandler(SfKey8_DownHandler,KEY_8,KEY_EVENT_DOWN);
	SetKeyHandler(SfKey8_UpHandler,KEY_8,KEY_EVENT_UP);
	
	SetKeyHandler(SfKey9_DownHandler,KEY_9,KEY_EVENT_DOWN);
	SetKeyHandler(SfKey9_UpHandler,KEY_9,KEY_EVENT_UP);


	SetKeyHandler(SfKeyLSK_DownHandler,KEY_LSK,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyLSK_UpHandler,KEY_LSK,KEY_EVENT_UP);

	SetKeyHandler(SfKeyRSK_DownHandler,KEY_RSK,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyRSK_UpHandler,KEY_RSK,KEY_EVENT_UP);

	SetKeyHandler(SfKeyEnter_DownHandler,KEY_ENTER,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyEnter_UpHandler,KEY_ENTER,KEY_EVENT_UP);

	SetKeyHandler(SfKeyUpArrow_DownHandler,KEY_UP_ARROW,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyUpArrow_UpHandler,KEY_UP_ARROW,KEY_EVENT_UP);


	SetKeyHandler(SfKeyDownArrow_DownHandler,KEY_DOWN_ARROW,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyDownArrow_UpHandler,KEY_DOWN_ARROW,KEY_EVENT_UP);

	SetKeyHandler(SfKeyLeftArrow_DownHandler,KEY_LEFT_ARROW,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyLeftArrow_UpHandler,KEY_LEFT_ARROW,KEY_EVENT_UP);

	SetKeyHandler(SfKeyRightArrow_DownHandler,KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyRightArrow_UpHandler,KEY_RIGHT_ARROW,KEY_EVENT_UP);
	
	SetKeyHandler(SfKeyStar_DownHandler,KEY_STAR,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyStar_UpHandler,KEY_STAR,KEY_EVENT_UP);

	SetKeyHandler(SfKeyPound_DownHandler,KEY_POUND,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyPound_UpHandler,KEY_POUND,KEY_EVENT_UP);
	
	SetKeyHandler(SfKeyClear_DownHandler,KEY_CLEAR,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyClear_UpHandler,KEY_CLEAR,KEY_EVENT_UP);

    SetKeyHandler(SfKeyVolUp_DownHandler,KEY_VOL_UP,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyVolUp_UpHandler,KEY_VOL_UP,KEY_EVENT_UP);

    SetKeyHandler(SfKeyVolDown_DownHandler,KEY_VOL_DOWN,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyVolDown_UpHandler,KEY_VOL_DOWN,KEY_EVENT_UP);

    SetKeyHandler(SfKeySend_DownHandler,KEY_SEND,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeySend_UpHandler,KEY_SEND,KEY_EVENT_UP);

    SetKeyHandler(SfKeyPower_DownHandler,KEY_POWER,KEY_EVENT_DOWN);
	SetKeyHandler(SfKeyPower_UpHandler,KEY_POWER,KEY_EVENT_UP);
	
	//SetKeyHandler(SfKeyEnd_DownHandler,KEY_END,KEY_EVENT_DOWN);
	
}


SFBool SFKey_IsPressed(SFInt aKeyCode)
{
	if(g_kernal.iKeyState&(1<<aKeyCode))
	{
		return SFTrue;
	}
	else
	{
		return SFFalse;
	}
}

static SFInt SFApp_MapKeyCode(S32 aKey)
{
    switch(aKey){
    case KEY_0:
        return SFKEY_NUM0;
    case KEY_1:
        return SFKEY_NUM1;
    case KEY_2:
        return SFKEY_NUM2;
    case KEY_3:
        return SFKEY_NUM3;
    case KEY_4:
        return SFKEY_NUM4;
    case KEY_5:
        return SFKEY_NUM5;
    case KEY_6:
        return SFKEY_NUM6;
    case KEY_7:
        return SFKEY_NUM7;
    case KEY_8:
        return SFKEY_NUM8;
    case KEY_9:
        return SFKEY_NUM9;
    case KEY_LSK:
        return SFKEY_SL;
    case KEY_RSK:
        return SFKEY_SR;
    case KEY_ENTER:
        return SFKEY_SM;
    case KEY_UP_ARROW:
        return SFKEY_UP;
    case KEY_DOWN_ARROW:
        return SFKEY_DOWN;
    case KEY_LEFT_ARROW:
        return SFKEY_LEFT;
    case KEY_RIGHT_ARROW:
        return SFKEY_RIGHT;
    case KEY_STAR:
        return SFKEY_STAR;
    case KEY_POUND:
        return SFKEY_POUND;
    case KEY_CLEAR:
        return SFKEY_CLR;
    case KEY_VOL_UP:
        return SFKEY_VOLUP;
    case KEY_VOL_DOWN:
        return SFKEY_VOLDOWN;
    case KEY_SEND:
        return SFKEY_SEND;
    case KEY_POWER:
        return SFKEY_POWER;
    default:
        return SFKEY_NONE;
    }
}


static void SFApp_KeyHandler(S32 aKey,S32 aKeyState)
{
    SFModule* pMod=g_kernal.iActiveApp;
	ISFApplication*pApp;
    if(!pMod)
        return;
    pApp=g_kernal.iActiveApp->pApplication;
    if(!pApp || !pApp->pfnEvtHandler)
        return;

    ENTER_MODULE(pMod)
	if(aKeyState==KEY_EVENT_DOWN)
	{
        if(aKey==KEY_END)
        {
            //close the app
            //terminate request
#if defined(MMI_ON_HARDWARE_P)
            kal_prompt_trace(SFCUST_TRACE_MOD,"SFApp_KeyHandler: End");
#endif //defined(MMI_ON_HARDWARE_P)
            g_kernal.iActiveModule->iState=SFMOD_STATE_DYING;
            SFSystem_PostMessageTo(g_kernal.iActiveModule,EVT_APP_DESTROY,0,0);
        }
        else
        {
            aKey=SFApp_MapKeyCode(aKey);
            if(aKey!=SFKEY_NONE)
            {
                g_kernal.iKeyState|=1<<aKey;
                //call the event handler
                pApp->pfnEvtHandler(pApp,EVT_KEYDOWN,(SFWPARAM)aKey,0);
            }
    	}
	}
	else if(aKeyState==KEY_EVENT_UP)
	{
        aKey=SFApp_MapKeyCode(aKey);
        if(aKey!=SFKEY_NONE)
        {
            g_kernal.iKeyState&=~(1<<aKey);
            //call the event handler
            pApp->pfnEvtHandler(pApp,EVT_KEYUP,(SFWPARAM)aKey,0);
        }
    }
    LEAVE_MODULE()

    POST_EVENT_PROCESS()
}


#if defined(__MMI_TOUCH_SCREEN__)

static void SFApp_PenMoveHandler(mmi_pen_point_struct pos)
{
	SFModule* pMod=g_kernal.iActiveApp;
	ISFApplication*pApp;
    if(!pMod)
        return;
    pApp=g_kernal.iActiveApp->pApplication;
    if(!pApp || !pApp->pfnEvtHandler)
        return;

    ENTER_MODULE(pMod)
    pApp->pfnEvtHandler(pApp,EVT_POINTER_DRAGGED,SFMAKE_POINT(pos.x,pos.y),0);
    LEAVE_MODULE()

    POST_EVENT_PROCESS()
}
static void SFApp_PenPressHandler(mmi_pen_point_struct pos)
{
	SFModule* pMod=g_kernal.iActiveApp;
	ISFApplication*pApp;
    if(!pMod)
        return;
    pApp=g_kernal.iActiveApp->pApplication;
    if(!pApp || !pApp->pfnEvtHandler)
        return;

    ENTER_MODULE(pMod)
    pApp->pfnEvtHandler(pApp,EVT_POINTER_PRESSED,SFMAKE_POINT(pos.x,pos.y),0);
    LEAVE_MODULE()

    POST_EVENT_PROCESS()
}
static void SFApp_PenReleaseHandler(mmi_pen_point_struct pos)
{
	SFModule* pMod=g_kernal.iActiveApp;
	ISFApplication*pApp;
    if(!pMod)
        return;
    pApp=g_kernal.iActiveApp->pApplication;
    if(!pApp || !pApp->pfnEvtHandler)
        return;

    ENTER_MODULE(pMod)
    pApp->pfnEvtHandler(pApp,EVT_POINTER_RELEASED,SFMAKE_POINT(pos.x,pos.y),0);
    LEAVE_MODULE()

    POST_EVENT_PROCESS()
}

#endif //defined(__MMI_TOUCH_SCREEN__)


static void SFSystem_SetupKeyMapTable(const SFDeviceKeyMap* keypadRemapTable);

void SFApp_SetupHandlers(void)
{
	//clear key states
	g_kernal.iKeyState=0;

	ClearAllKeyHandler();
    SFAppRegistKeyHandler();
	SetKeyHandler(SfKeyEnd_DownHandler,KEY_END,KEY_EVENT_DOWN);
//#ifdef __MMI_GAME__
//	SetKeyHandler(mmi_gfx_volume_up,	KEY_VOL_UP, KEY_EVENT_DOWN);
//	SetKeyHandler(mmi_gfx_volume_down,	KEY_VOL_DOWN, KEY_EVENT_DOWN);	
//#endif //__MMI_GAME__
#if defined(__MMI_TOUCH_SCREEN__)
	mmi_pen_register_down_handler(SFApp_PenPressHandler);
	mmi_pen_register_move_handler(SFApp_PenMoveHandler);
	mmi_pen_register_up_handler(SFApp_PenReleaseHandler);
#endif //defined(__MMI_TOUCH_SCREEN__)
    //SFSystem_InitKeyStateMap();

    SFSystem_SetupKeyMapTable(g_kernal.iActiveApp->iKeyStateMap);
}

extern SFUint64 SFAppPlatform_GetCurrentAppId(void);



void SFApp_SetupGDI(SFInt flag)
{
    //*(((volatile unsigned int*)0x80701040)+4)=0x8000057;
    s_bFastScreenUpdate=(char)flag;
    if(s_bFastScreenUpdate)
    {
        //kal_prompt_trace(SFCUST_TRACE_MOD,"SFApp_SetupGDI Fast %d",s_lock_gdi);

        gdi_layer_set_source_key(KAL_FALSE,GDI_COLOR_TRANSPARENT);
        //gdi_layer_clear(GDI_COLOR_BLACK);
    		
        TurnOnBacklight(0);
    	
       	entry_full_screen();

        gdi_layer_blt_ext(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0,
#ifdef GDI_6_LAYERS
                            0, 0,
#endif
                            0, 0, LCD_WIDTH-1, LCD_HEIGHT-1);	

        lcd_power_up();
        gdi_layer_lock_frame_buffer();
    }
    else
    {
        gdi_handle gdi_hdlr;
        
        //kal_prompt_trace(SFCUST_TRACE_MOD,"SFApp_SetupGDI %d",s_lock_gdi);

        
        
        lcd_power_up();
        entry_full_screen();
    
        gdi_layer_reset_clip();
        //gdi_layer_get_active(&gdi_hdlr);
        gdi_layer_get_base_handle(&gdi_hdlr);
        gdi_layer_set_blt_layer(gdi_hdlr,0,0,0);
    
        gdi_layer_set_active(gdi_hdlr);
        gdi_layer_set_source_key(FALSE,GDI_COLOR_TRANSPARENT);
    }
    ++s_lock_gdi;

}

void SFApp_FreeGDI(void)
{
    //*(((volatile unsigned int*)0x80701040)+4)=0;
    if(s_lock_gdi)
    {
        --s_lock_gdi;
        if(s_lock_gdi<=0)
        {
            if(s_bFastScreenUpdate)
            {
                gdi_layer_unlock_frame_buffer();
            }

            lcd_power_down();

            TurnOffBacklight();
        }
    }
}



static void (*s_post_exec_entry)(void*param)=NULL;
static void *s_post_exec_param=NULL;
    
void SFSystem_Exec(void (*exec_entry)(void*param),void*param)
{
    s_post_exec_entry=exec_entry;
    s_post_exec_param=param;
    SFApp_Exit();
}


#if 0
static U8 SFApp_DeleteEntry( void* in_param )
{
    SFModule* pMod;
	ISFApplication*pApp;

    SFApp_FreeGDI();
    
    pMod=g_kernal.iActiveApp;

    
    mmi_frm_kbd_set_tone_state(g_kernal.bSavToneState);
    mdi_audio_resume_background_play();

    if(pMod==IDLE_MODULE)
    {
        return MMI_HIST_ALLOW_DELETING;
    }
    if(!pMod || !pMod->pApplication)
    {
        return MMI_HIST_ALLOW_DELETING;
    }
    pApp=pMod->pApplication;

    if(pApp->pfnEvtHandler)
    {
        ENTER_MODULE(pMod)
	    (*pApp->pfnEvtHandler)(pApp,EVT_APP_DESTROY,0,0);
        LEAVE_MODULE()

        POST_EVENT_PROCESS()
    }

    g_kernal.iActiveApp=IDLE_MODULE;

	SFSystem_Finalize();

    
#if 0
    {
        void (*exec_entry)(void*param)=s_post_exec_entry;
        s_post_exec_entry=NULL;
        if(exec_entry)
            (*exec_entry)(s_post_exec_param);
    }
#endif
    return MMI_HIST_ALLOW_DELETING;
}
#endif //0

void SFOS32_SetLastError(int err)
{
    g_kernal.iActiveModule->iLastError=err;
}

int SFOS32_GetLastError(void)
{
    return g_kernal.iActiveModule->iLastError;
}

static void SFSystem_BeforeEnterApp(void)
{
    mdi_audio_suspend_background_play();
    mdi_audio_set_volume(MDI_VOLUME_MEDIA,g_kernal.iVolume);
    SFApp_SetupHandlers();
    g_kernal.bSavToneState=mmi_frm_kbd_get_key_tone_state();
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    SFApp_SetupGDI((g_kernal.iActiveApp->iFlag&SFMOD_ATTR_FAST_SCREEN_UPDATE)?1:0);
#if defined(__SF_KEYPAD_SUPPORT__)
    SFKeypad_Clear();
#endif //defined(__SF_KEYPAD_SUPPORT__)
}

static void SFSystem_AfterLeaveApp(void)
{
    SFApp_FreeGDI();
    mmi_frm_kbd_set_tone_state(g_kernal.bSavToneState);
    
    /* resume background audio */
    mdi_audio_resume_background_play();
    //do not clear the handlers 
}


void SFSystem_UnregisterAllCallbacksForApp(SFModule* pMod);
static void sf_vfs_close_module(SFModule* mod);
static void SFSystem_NetFinalizeForModule(SFModule* aModule);
static void SFSysTimer0_KillAllFor(SFModule* aModule);
static void SFSocket_canceldnsqueryForModule(SFModule* mod);
static void FreeSubfilesForModule(SFModule* pMod);

void SFSystem_FreeModuleResources(SFModule* pMod)
{
    SFDEBUG("SFSystem_UnloadModule B");
    FreeSubfilesForModule(pMod);
    SFFS_Cleanup(pMod);
    sf_vfs_close_module(pMod);
    SFTimer_Cleanup(pMod);
    SFSystem_UnregisterAllCallbacksForApp(pMod);
    SFSystem_NetFinalizeForModule(pMod);
    SFSysTimer0_KillAllFor(pMod);
    SFSocket_canceldnsqueryForModule(pMod);
    SFDEBUG("SFSystem_UnloadModule E");
    
}

void SFSystem_GCModules(SFModule* pMod)
{
    int i,j;
    for(i=g_kernal.iAppSP;i>=0;i--)
    {
        if(g_kernal.iAppStack[i]==pMod)
        {
            g_kernal.iAppStack[i]=IDLE_MODULE;
            break;
        }
    }
    j=0;
    for(i=0;i<=g_kernal.iAppSP;i++)
    {
        if(g_kernal.iAppStack[i]!=IDLE_MODULE)
        {
            g_kernal.iAppStack[j]=g_kernal.iAppStack[i];
            ++j;
        }
    }
    g_kernal.iAppSP=j-1;
    for(i=0;i<SF_MAX_SERVICES;i++)
    {
        if(g_kernal.iService[i]==pMod)
        {
            g_kernal.iService[i]=SFNull;
            break;
        }
    }
}

SFReason SFSystem_UnloadModule(SFModule* pMod)
{
    ISFApplication*pApp;

    SFDEBUG("SFSystem_UnloadModule B");
    if(!pMod || pMod->iState!=SFMOD_STATE_DYING)
        return SFReasonError;

    pApp=pMod->pApplication;
    if(pApp && pApp->pfnEvtHandler)
    {
        ENTER_MODULE(pMod)
	    (*pApp->pfnEvtHandler)(pApp,EVT_APP_DESTROY,0,0);
        LEAVE_MODULE()
    }
    //free the module in the module list
    SFSystem_GCModules(pMod);
    //unload all the other things
    SFSystem_FreeModuleResources(pMod);
    pMod->iState=SFMOD_STATE_DEAD;
    
    POST_EVENT_PROCESS()
            
    SFDEBUG("SFSystem_UnloadModule A");
    
    //free the modules
    if(pMod->iLocalHeap)
    {
        SFSystem_Free(pMod->iLocalHeap);
    }
#if defined(__SF_APPLICATION_PLATFORM__ENABLE__) || defined(SFAPI_WIN)
    if(pMod->iEModule)
    {
        SFSystem_UnloadEModule(pMod->iEModule);
        pMod->iEModule=SFNull;
    }
#endif //defined(__SF_APPLICATION_PLATFORM__ENABLE__)
    SFSystem_FreeModule(pMod);
    SFDEBUG("SFSystem_UnloadModule E");
#ifdef SFCUST_COMPACT_RAM
    SFWorkMemory_Release();
#endif
    return SFReasonOK;
}

static void SFApplication_OnLeave(void)
{
    SFModule* pMod;

    pMod=g_kernal.iActiveApp;

    SFDEBUG("SFApplication_OnLeave");
    
    if(pMod!=IDLE_MODULE)
    {
        if(pMod->iState==SFMOD_STATE_DYING)
        {
            SFDEBUG("Exit");
            
            SFSystem_PopApplication();
            //dispose the module
            SFSystem_UnloadModule(pMod);
        }
        else
        {
            SFDEBUG("PAUSE");
            
            ENTER_MODULE(pMod)
            (*pMod->pApplication->pfnEvtHandler)(pMod->pApplication,EVT_APP_PAUSE,0,0);
            LEAVE_MODULE()

            POST_EVENT_PROCESS()
            //switch to idle task
            SFSystem_PushApplication(IDLE_MODULE);

            if(pMod->iFlag&SFMOD_ATTR_DYNAMIC_MEMORY)
            {
                //free the memory
                if(pMod->iLocalHeap)
                {
                    SFSystem_Free(pMod->iLocalHeap);
                    pMod->iLocalHeap=SFNull;
                }
            }
        }
    }
    SFSystem_AfterLeaveApp();
}

static U8 SFApplication_OnDestroy(void* in_param)
{
    SFModule* pMod;
	
    //SFApp_FreeGDI();

    SFDEBUG("SFApplication_OnDestroy");
    
    
    pMod=g_kernal.iActiveApp;


    if(pMod==IDLE_MODULE)
    {
        return MMI_HIST_ALLOW_DELETING;
    }
    if(!pMod || !pMod->pApplication)
    {
        return MMI_HIST_ALLOW_DELETING;
    }
    pMod->iState=SFMOD_STATE_DYING;
    
    
    //dispose the module
    //SFSystem_UnloadModule(pMod);

    //g_kernal.iActiveApp=IDLE_MODULE;

    //SFSystem_AfterLeaveApp();

	//SFSystem_Finalize();
    return MMI_HIST_ALLOW_DELETING;
}


static void SFApplication_OnResume(void)
{
    SFModule* pMod;
    SFUint16 scrid;

    SFDEBUG("SFApplication_OnResume");
    
    if(g_kernal.iAppSP>0)
    {
        scrid=g_kernal.iAppStack[g_kernal.iAppSP-1]->iScrId;
    }
    else
    {
        scrid=SFCUST_MAIN_SCREEN_ID;
    }
    
    EntryNewScreen(scrid,&SFApplication_OnLeave,&SFApplication_OnResume,SFNull);
	SetDelScrnIDCallbackHandler( scrid, (HistoryDelCBPtr)&SFApplication_OnDestroy );
    
    SFSystem_PopApplication();

    SFSystem_BeforeEnterApp();
    
    pMod=g_kernal.iActiveApp;

    if(pMod->iFlag&SFMOD_ATTR_DYNAMIC_MEMORY)
    {
        //free the memory
        if(pMod->iLocalHeapSize && !pMod->iLocalHeap)
        {
            pMod->iLocalHeap=SFSystem_Alloc(pMod->iLocalHeapSize);
        }
    }

    if(pMod!=IDLE_MODULE)
    {
        ENTER_MODULE(pMod)
        (*pMod->pApplication->pfnEvtHandler)(pMod->pApplication,EVT_APP_RESUME,0,0);
        LEAVE_MODULE()

        POST_EVENT_PROCESS()
    }
}


void SFSystem_HandleCmdLine(SFModule*pMod,const UChar* aCmdLine,SFUint32 aFlag)
{
    if(aCmdLine)
    {
        switch(aFlag&SF_LAUNCH_TYPE_MASK)
        {
        case SF_LAUNCH_WITH_FILE:
            (*pMod->pApplication->pfnEvtHandler)(pMod->pApplication,EVT_APP_HANDLE_FILE,(SFLPARAM)aCmdLine,0);
            break;
        case SF_LAUNCH_WITH_URL:
            (*pMod->pApplication->pfnEvtHandler)(pMod->pApplication,EVT_APP_HANDLE_URL,(SFLPARAM)aCmdLine,0);
            break;
        case SF_LAUNCH_WITH_MESSAGE:
            (*pMod->pApplication->pfnEvtHandler)(pMod->pApplication,EVT_APP_HANDLE_MESSAGE,(SFLPARAM)aCmdLine,0);
            break;
        }
    }
}


static void SFSystem_LaunchActiveApp(const UChar* aCmdLine,SFUint32 aFlag)
{
    SFModule* pMod;
    pMod=g_kernal.iActiveApp;

    dbg_last_evt();
    
    if(pMod!=IDLE_MODULE)
    {
        SFDEBUG("SFSystem_LaunchActiveApp");

        
        
        EntryNewScreen(pMod->iScrId,SFApplication_OnLeave,SFApplication_OnResume,SFNull);
    	SetDelScrnIDCallbackHandler( pMod->iScrId, (HistoryDelCBPtr)SFApplication_OnDestroy );

        SFSystem_BeforeEnterApp();
        
        ENTER_MODULE(pMod)
	    (*pMod->pApplication->pfnEvtHandler)(pMod->pApplication,EVT_APP_START,0,0);
        SFSystem_HandleCmdLine(pMod,aCmdLine,aFlag);
        LEAVE_MODULE()

        POST_EVENT_PROCESS()
    }
}


static void SFSystem_ApplyRightList(SFModule* mod,const SFUint16* rights)
{
    if(mod->iType&SFMOD_ATTR_SYSTEM)
    {
        memset(mod->iRight,0xFF,sizeof(mod->iRight));
    }
    else if(rights)
    {
        while(*rights!=SFMOD_RIGHTS_END)
        {
            SET_RIGHT(mod,*rights);
            ++rights;
        }
    }
}

SFReason SFSystem_PrepareBuiltInModule(const SFBuiltInApp* pAppDesc,SFModule** ppMod)
{
    SFModule* pMod;
    ISFApplication* pApp;
    if(pAppDesc->iFlag&SFMOD_ATTR_APPLICATION)
    {
        if(g_kernal.iAppSP>=SF_MAX_APPS-1)
        {
            //failed
            SFDEBUG("app sp overflow");
            return SFReasonOutOfResource;
        }
    }
    else
    {
        int i;
        int found=0;
        for(i=0;i<SF_MAX_SERVICES;i++)
        {
            if(!g_kernal.iService[i])
            {
                found=1;
            }
            else if(g_kernal.iService[i]->iModId==pAppDesc->iModId)
            {
                //failed
                SFDEBUG("app service overflow");
                return SFReasonExists;
            }
        }
        if(!found)
            return SFReasonOutOfResource;
    }
    
    pMod=SFSystem_AllocModule();
    if(!pMod)
    {
        //failed
        SFDEBUG("out of module");
        return SFReasonOutOfResource;
    }

    pMod->iRefCount=1;
    pMod->iLastError=0;
    if(pAppDesc->iFlag&SFMOD_ATTR_NATIVE_SFAPI_COMPATIBILITY)
    {
        pMod->iFlag=pAppDesc->iFlag;
    }
    else
    {
        pMod->iFlag=pAppDesc->iFlag|SFMOD_ATTR_BUILTIN;
    }
    pMod->iKeyStateMap=SFNull;
    pMod->iModId=pAppDesc->iModId;
    pMod->iState=SFMOD_STATE_CREATING;
    pMod->iLocalHeapSize=1024*pAppDesc->iLocalHeapSize;
    pMod->iEModule=SFNull;
    SFSystem_ApplyRightList(pMod,pAppDesc->iRight);

    //create the local heap
    if(pMod->iLocalHeapSize)
    {
        pMod->iLocalHeap=SFSystem_Alloc(pMod->iLocalHeapSize);
        if(!pMod->iLocalHeap)
        {
            SFSystem_FreeModule(pMod);
            sf_dbgprintf(L"sss %d",pMod->iLocalHeapSize);
            return SFReasonOutOfMemory;
        }
    }
    ENTER_MODULE(pMod)
    pApp=(*(SF_MODULE_CREATE)pAppDesc->iEntryFunc)();
    LEAVE_MODULE()
    
    if(!pApp)
    {
        SFSystem_FreeModule(pMod);
        return SFReasonFail;
    }
    pMod->iState=SFMOD_STATE_SUSPENDING;
    pMod->pApplication=pApp;
    
    
    *ppMod=pMod;
    return SFReasonOK;
}

void SFSystem_ShowErrorMessage(SFReason r)
{
    U16 err_str_id;
    switch(r)
    {
    case SFReasonNotFound://文件无法打开
        err_str_id=STR_GLOBAL_NOT_AVAILABLE;
        break;
    case SFReasonBadFormat://文件格式错误
        err_str_id=STR_GLOBAL_ERROR;
        break;
    default:
        err_str_id=STR_GLOBAL_ERROR;
        break;
    }
    DisplayConfirm(
			        STR_GLOBAL_OK,
			        0,
			        0,
			        0,
			        get_string(err_str_id),
			        0,
			        ERROR_TONE);
    SetLeftSoftkeyFunction(&GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(&GoBackHistory,KEY_END,KEY_EVENT_DOWN);
}



SFReason SFSystem_LaunchService(SFModule*pMod,const UChar* aCmdLine,SFUint32 aFlag)
{
    int i;
    SFDEBUG("SFSystem_LaunchService");
    for(i=0;i<SF_MAX_SERVICES;i++)
    {
        if(!g_kernal.iService[i])
        {
            g_kernal.iService[i]=pMod;

            ENTER_MODULE(pMod)
    	    (*pMod->pApplication->pfnEvtHandler)(pMod->pApplication,EVT_APP_START,0,0);
            SFSystem_HandleCmdLine(pMod,aCmdLine,aFlag);
            LEAVE_MODULE()

            SFDEBUG("SFSystem_LaunchService: OK");
            
            return SFReasonOK;
        }
    }
    return SFReasonOutOfResource;
}

const SFBuiltInApp* SFSystem_FindBuiltinModule(SFModId mod)
{
    const SFBuiltInApp* pAppDesc;
    pAppDesc=s_builtin_module;
    
    while(pAppDesc->iModId!=0 && pAppDesc->iModId!=mod)
    {
        pAppDesc=pAppDesc+1;
    }
#ifdef SFAPI_WIN
    if(pAppDesc->iModId==0)
    {
        extern const SFBuiltInApp* EmuGetAppInfo(void);
        if(EmuGetAppInfo())
            pAppDesc=EmuGetAppInfo();
    }
#endif
    if(pAppDesc->iModId==0)
        return SFNull;
    return pAppDesc;
}



#if defined(__SF_APPLICATION_PLATFORM__ENABLE__)

SFReason SFSystem_PrepareEModule(UString path,SFModId modid,SFModule** ppMod)
{
    SFReason r;
    SFEModule* pEMod;
    SFModule* pMod;
    ISFApplication* pApp;
    
    r=SFSystem_LoadEModule(path,&pEMod);
    if(r!=SFReasonOK)
        return r;
    
    if(pEMod->iFlag&SFMOD_ATTR_APPLICATION)
    {
        if(g_kernal.iAppSP>=SF_MAX_APPS-1)
        {
            //failed
            SFSystem_UnloadEModule(pEMod);
            return SFReasonOutOfResource;
        }
    }
    else
    {
        int i;
        int found=0;
        for(i=0;i<SF_MAX_SERVICES;i++)
        {
            if(!g_kernal.iService[i])
            {
                found=1;
            }
            else if(g_kernal.iService[i]->iModId==modid)
            {
                //failed
                SFSystem_UnloadEModule(pEMod);
                return SFReasonExists;
            }
        }
        if(!found)
        {
            SFSystem_UnloadEModule(pEMod);
            return SFReasonOutOfResource;
        }
    }
    
    pMod=SFSystem_AllocModule();
    if(!pMod)
    {
        //failed
        SFSystem_UnloadEModule(pEMod);
        return SFReasonOutOfResource;
    }

    pMod->iKeyStateMap=SFNull;
    pMod->iRefCount=1;
    pMod->iLastError=0;
    pMod->iFlag=pEMod->iFlag&~SFMOD_ATTR_BUILTIN;
    pMod->iModId=modid;
    pMod->iState=SFMOD_STATE_CREATING;
    pMod->iEModule=pEMod;
    pMod->iLocalHeapSize=1024*pEMod->iLocalHeapSize;

    //create the local heap
    if(pMod->iLocalHeapSize)
    {
        pMod->iLocalHeap=SFSystem_Alloc(pMod->iLocalHeapSize);
        if(!pMod->iLocalHeap)
        {
            SFSystem_UnloadEModule(pEMod);
            SFSystem_FreeModule(pMod);
            return SFReasonOutOfMemory;
        }
    }
    SFSystem_ApplyRightList(pMod,SF_DEFAULT_APP_RIGHTS);

    ENTER_MODULE(pMod)
    if(pEMod->iImageVersion<=2)
    {
        r=(*pEMod->iEntry.iLegacyMethod)(SFNull,(void**)&pApp);
        if(r!=0)
            r=SFReasonError;
    }
    else
    {
        r=(*pEMod->iEntry.iMethod)(modid,(void**)&pApp);
        
    }
    LEAVE_MODULE()
    pMod->iState=SFMOD_STATE_SUSPENDING;
    if(r!=0)
    {
        //failed
        SFSystem_UnloadEModule(pEMod);
        SFSystem_FreeModule(pMod);
        return SFReasonError;
    }

    pMod->pApplication=pApp;

    
    *ppMod=pMod;
    return SFReasonOK;
}

SFReason SFSystem_PrepareEModuleByModId(SFModId mod,SFModule** ppMod)
{
    //search the application on disk
    UString path;
    SFReason r=SFSystem_GetPathByModuleId(mod,&path);
    if(r==SFReasonOK)
    {
        SFDEBUG("ok a");
        return SFSystem_PrepareEModule(path,mod,ppMod);
    }
    return r;
}

#endif //defined(__SF_APPLICATION_PLATFORM__ENABLE__)

SFReason SFSystem_LeaveSFAPICompabileNativeModule(SFModId mod)
{
    SFModule* pMod=g_kernal.iActiveApp;
    //check the active app
    if(pMod==IDLE_MODULE || pMod->iModId!=mod)
    {
        return SFReasonNotFound;
    }
    pMod->iState=SFMOD_STATE_DYING;
    return SFSystem_UnloadModule(pMod);
}

SFReason SFSystem_EnterSFAPICompabileNativeModule(SFModId mod)
{
    const SFBuiltInApp* pAppDesc;
    SFReason r=SFReasonNotFound;
    SFModule*pMod;

    SFSystem_Initialize();
    
    dbg_last_evt();

    pAppDesc=SFSystem_FindBuiltinModule(mod);
    dbg_last_evt();
    if(pAppDesc)
    {
        if(pAppDesc->iFlag&SFMOD_ATTR_NATIVE && pAppDesc->iFlag&SFMOD_ATTR_APPLICATION)
        {
            if(!(pAppDesc->iFlag&SFMOD_ATTR_NATIVE_SFAPI_COMPATIBILITY))
            {
                if(pAppDesc->iEntryFunc)
                {
                    (*pAppDesc->iEntryFunc)();
                }
                return SFReasonOK;
            }
        }
        dbg_last_evt();
        r=SFSystem_PrepareBuiltInModule(pAppDesc,&pMod);
    }
    if(r!=SFReasonOK)
        return r;

    SFSystem_PushApplication(pMod);
    pMod->iState=SFMOD_STATE_RUNNING;

    return SFReasonOK;
}

SFUint16 SFSystem_GetNextScreenId(void)
{
    int i;
    char buf[SF_MAX_APPS];
    for(i=0;i<SF_MAX_APPS;i++) buf[i]=0;
    for(i=g_kernal.iAppSP;i>=0;i--)
    {
        buf[g_kernal.iAppStack[i]->iScrId-SFCUST_MAIN_SCREEN_ID]=1;
    }
    for(i=0;i<SF_MAX_APPS;i++)
    {
        if(buf[i]==0)
        {
            return SFCUST_MAIN_SCREEN_ID+i;
        }
    }
    return SFCUST_MAIN_SCREEN_ID;
}

int SFSystem_ModuleExists(SFModId mod)
{
    const SFBuiltInApp* pAppDesc;
    UString path;
    SFReason r;
    pAppDesc=SFSystem_FindBuiltinModule(mod);
    if(pAppDesc)
        return 1;
#if !defined(SFAPI_WIN) && defined(__SF_APPLICATION_PLATFORM__ENABLE__)
    if(SFSystem_GetPathByModuleId(mod,&path)==SFReasonOK)
    {
        return 1;
    }
#endif 
    return 0;
    
}


SFReason SFSystem_LaunchModule(SFModId mod,const UChar* aCmdLine,SFUint32 aFlag)
{
    const SFBuiltInApp* pAppDesc;
    SFReason r;
    SFModule*pMod;
#ifdef __J2ME__
        if(jvm_is_pause_mode())
        {
            mmi_java_display_is_busy_for_pause_mode();
            return SFReasonBusy;
        }
#endif

    SFSystem_Initialize();
#ifdef SFCUST_COMPACT_RAM
    SFAllocWorkMemory();
#endif
    pAppDesc=SFSystem_FindBuiltinModule(mod);
    dbg_last_evt();
    if(pAppDesc)
    {
        if(pAppDesc->iFlag&SFMOD_ATTR_NATIVE)
        {
            if(pAppDesc->iEntryFunc)
            {
                (*pAppDesc->iEntryFunc)();
            }
            return SFReasonOK;
        }
        r=SFSystem_PrepareBuiltInModule(pAppDesc,&pMod);
    }
#if defined(__SF_APPLICATION_PLATFORM__ENABLE__)
    else
    {
        r=SFSystem_PrepareEModuleByModId(mod,&pMod);
    }
#endif //defined(__SF_APPLICATION_PLATFORM__ENABLE__)
    dbg_last_evt();
    if(r==SFReasonOK)
    {
        if(pMod->iFlag&SFMOD_ATTR_APPLICATION)
        {
            //assign a new screen id
            pMod->iScrId=SFSystem_GetNextScreenId();
            SFSystem_PushApplication(pMod);
            SFSystem_LaunchActiveApp(aCmdLine,aFlag);
        }
        else
        {
            //service
            SFSystem_LaunchService(pMod,aCmdLine,aFlag);
        }
        dbg_last_evt();
        return SFReasonOK;
    }
    else
    {
        //
        sf_dbgprintf(L"err %d",r);
        SFSystem_ShowErrorMessage(r);
#ifdef SFCUST_COMPACT_RAM
        SFWorkMemory_Release();
#endif
        return SFReasonError;
    }
}



#ifdef __SF_MTK_APPLICATION_EMU__ENABLE__
extern void SFNesPay_SetInitInfo(int freePoint,int payType,int cost,const UChar* path);	
extern void SFNesEmuApp_SetOptionSaveDir(UString path);
static void SFSystem_SetActiveAppKeyMapTable(const SFDeviceKeyMap* keypadRemapTable);

enum
{
    SFKS_NES_UP=SFKS_UP,
    SFKS_NES_DOWN=SFKS_DOWN,
    SFKS_NES_LEFT=SFKS_LEFT,
    SFKS_NES_RIGHT=SFKS_RIGHT,
    SFKS_NES_A=SFKS_NUM2,
    SFKS_NES_B=SFKS_NUM1,
    SFKS_NES_SELECT=SFKS_NUM7,
    SFKS_NES_START=SFKS_NUM8,
    SFKS_NES_ROTATE=SFKS_NUM9,
    SFKS_NES_SOUND_SWITCH=SFKS_NUM0
};

enum
{
    SFKEY_NES_UP=SFKEY_UP,
    SFKEY_NES_DOWN=SFKEY_DOWN,
    SFKEY_NES_LEFT=SFKEY_LEFT,
    SFKEY_NES_RIGHT=SFKEY_RIGHT,
    SFKEY_NES_A=SFKEY_NUM2,
    SFKEY_NES_B=SFKEY_NUM1,
    SFKEY_NES_SELECT=SFKEY_NUM7,
    SFKEY_NES_START=SFKEY_NUM8,
    SFKEY_NES_ROTATE=SFKEY_NUM9,
    SFKEY_NES_SOUND_SWITCH=SFKEY_NUM0
};


#if !defined(SFCUST_NESEMU_KEYMAP)
const SFDeviceKeyMap s_nesemu_keymap_normal[]=
{
    {DEVICE_KEY_UP,SFKEY_NES_UP},
    {DEVICE_KEY_DOWN,SFKEY_NES_DOWN},
    {DEVICE_KEY_LEFT,SFKEY_NES_LEFT},
    {DEVICE_KEY_RIGHT,SFKEY_NES_RIGHT},
    {DEVICE_KEY_1,SFKEY_NES_A},
    {DEVICE_KEY_2,SFKEY_NES_B},
    {DEVICE_KEY_4,SFKEY_NES_A},
    {DEVICE_KEY_5,SFKEY_NES_B},
    {DEVICE_KEY_7,SFKEY_NES_SELECT},
    {DEVICE_KEY_8,SFKEY_NES_START},
    {_DEVICE_KEY_LAST_,0}
};
const SFDeviceKeyMap s_nesemu_keymap_r90[]=
{
    {DEVICE_KEY_LEFT,SFKEY_NES_UP},
    {DEVICE_KEY_RIGHT,SFKEY_NES_DOWN},
    {DEVICE_KEY_DOWN,SFKEY_NES_LEFT},
    {DEVICE_KEY_UP,SFKEY_NES_RIGHT},
    {DEVICE_KEY_7,SFKEY_NES_A},
    {DEVICE_KEY_4,SFKEY_NES_B},
    {DEVICE_KEY_8,SFKEY_NES_A},
    {DEVICE_KEY_5,SFKEY_NES_B},
    {DEVICE_KEY_9,SFKEY_NES_SELECT},
    {DEVICE_KEY_6,SFKEY_NES_START},
    {_DEVICE_KEY_LAST_,0}
};
#endif

void SFNesEmuApp_ResetKeyMap(void)
{
    kal_bool br90=(SFNesEmuApp_GetStatus() == NESEMU_STATUS_GAMER90);
    if(br90!=g_bRotate90)
    {
        //reset the key map
        g_bRotate90=br90;
        if(br90)
        {
            SFSystem_SetActiveAppKeyMapTable(s_nesemu_keymap_r90);
            SFSystem_SetupKeyMapTable(s_nesemu_keymap_r90);
}
        else
{
            SFSystem_SetActiveAppKeyMapTable(s_nesemu_keymap_normal);
            SFSystem_SetupKeyMapTable(s_nesemu_keymap_normal);
        }
    }
}

void SFNesEmuEntry(PS8 filename, BOOL is_short)
{
#ifdef __J2ME__
	if(jvm_is_pause_mode())
	{
		mmi_java_display_is_busy_for_pause_mode();
		return;
	}
#endif
    SFDEBUG("SFNesEmuEntry");

	memset(u16_g_game_file_name,0x0,FMGR_PATH_BUFFER_SIZE);
	
	pfnUnicodeStrcpy((PS8)u16_g_game_file_name, filename);

    SFNesPay_SetInitInfo(100,0,2,L"Z:");	
    SFNesEmuApp_SetOptionSaveDir(L"Z:\\");	
	//SFApp_Entry();
    SFSystem_LaunchModule(SFMODID_GAME_NESEMU,(UString)filename,0);
    //setup the custom key map
    SFNesEmuApp_ResetKeyMap();
}

static void SFNesEmuEntry2(PS8 filename,int is_short)
{
    if(filename==NULL)
    {
        GoBackHistory();
        return;
    }
    SFNesEmuEntry(filename,is_short);
}

static const char s_NesEmuDirPath[]="Games\\";
#define DEFAULT_EMU_DRV 'E'

static BOOL SFNesEmuApp_GetDiskPath(PS8 drv_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (FS_NO_ERROR == FS_GetDevStatus(DEFAULT_EMU_DRV ,FS_MOUNT_STATE_ENUM))
    {
        sprintf(buf, "%c:\\%s", (U8)DEFAULT_EMU_DRV,s_NesEmuDirPath);
        AnsiiToUnicodeString(drv_buf, buf);
        return TRUE;
    }
    else
    {
        U16 drv = (U16) MMI_PUBLIC_DRV;

        if (FS_NO_ERROR != FS_GetDevStatus(drv ,FS_MOUNT_STATE_ENUM))
            return FALSE;

        sprintf(buf, "%c:\\%s", (U8)drv,s_NesEmuDirPath );
        AnsiiToUnicodeString(drv_buf, buf);
        return TRUE;
    }   
}


void SFNesEmuAppEntry(void)
{
    FS_HANDLE hDir=-1;
    S8 path[128];

    SFDEBUG("SFNesEmuAppEntry");
    
    if(SFNesEmuApp_GetDiskPath((PS8)path))
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
        FMGR_FILTER_SET(&filter,FMGR_TYPE_NES);
        
        mmi_fmgr_select_path_and_enter(APP_GAMES,FMGR_SELECT_FILE,filter,path,(PsExtFuncPtr)SFNesEmuEntry2);
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


#if defined(__SF_MTK_APPLICATION_EMU__FREEGAMES__)

void SFNesEmuEntryF(PS8 filename, BOOL is_short)
{
#ifdef __J2ME__
	if(jvm_is_pause_mode())
	{
		mmi_java_display_is_busy_for_pause_mode();
		return;
	}
#endif
    SFDEBUG("SFNesEmuEntryF");

	memset(u16_g_game_file_name,0x0,FMGR_PATH_BUFFER_SIZE);
	
	pfnUnicodeStrcpy((PS8)u16_g_game_file_name, filename);

    //SFNesPay_SetInitInfo(100,0,2,L"Z:");	
    SFNesEmuApp_SetOptionSaveDir(L"Z:\\");	
	//SFApp_Entry();
    SFSystem_LaunchModule(SFMODID_GAME_NESEMUF,(UString)filename,0);
    //setup the custom key map
    SFNesEmuApp_ResetKeyMap();
}

static void SFNesEmuEntry2F(PS8 filename,int is_short)
{
    if(filename==NULL)
    {
        GoBackHistory();
        return;
    }
    SFNesEmuEntryF(filename,is_short);
}

static const char s_NesEmuDirPathF[]="FreeGames\\";
#define DEFAULT_EMU_DRVF 'E'

static BOOL SFNesEmuApp_GetDiskPathF(PS8 drv_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (FS_NO_ERROR == FS_GetDevStatus(DEFAULT_EMU_DRVF ,FS_MOUNT_STATE_ENUM))
    {
        sprintf(buf, "%c:\\%s", (U8)DEFAULT_EMU_DRVF,s_NesEmuDirPathF);
        AnsiiToUnicodeString(drv_buf, buf);
        return TRUE;
    }
    else
    {
        U16 drv = (U16) MMI_PUBLIC_DRV;

        if (FS_NO_ERROR != FS_GetDevStatus(drv ,FS_MOUNT_STATE_ENUM))
            return FALSE;

        sprintf(buf, "%c:\\%s", (U8)drv,s_NesEmuDirPathF );
        AnsiiToUnicodeString(drv_buf, buf);
        return TRUE;
    }   
}
void SFNesEmuAppEntryF(void)
{
    FS_HANDLE hDir=-1;
    S8 path[128];
    if(SFNesEmuApp_GetDiskPathF((PS8)path))
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
        FMGR_FILTER_SET(&filter,FMGR_TYPE_NES);
        
        mmi_fmgr_select_path_and_enter(APP_GAMES,FMGR_SELECT_FILE,filter,path,(PsExtFuncPtr)SFNesEmuEntry2F);
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

#endif //__SF_MTK_APPLICATION_EMU__FREEGAMES__

#endif //__SF_MTK_APPLICATION_EMU__ENABLE__


#ifdef __SF_MTK_APPLICATION_MAJIANG__ENABLE__

//无存档情况下初始给的点数
extern void SFMajiang_SetInitPoint(int val);

void SFMajiangEntry(void)
{
#ifdef __J2ME__
	if(jvm_is_pause_mode())
	{
		mmi_java_display_is_busy_for_pause_mode();
		return;
	}
#endif

    //设置初始点数
	SFMajiang_SetInitPoint(99);

	SFSystem_LaunchModule(SFMODID_GAME_MAJIANG,SFNull,SF_LAUNCH_NORMAL);
}

#endif //__SF_MTK_APPLICATION_MAJIANG__ENABLE__

#ifdef __SF_MTK_APPLICATION_RABBIT__ENABLE__

extern ISFApplication* SFRabbit_Create(void);

/*
设置免费关数、多少关收一次费方法：
SFRabbit_SetInitStage(int valfree,int val)
比如头2关免费，后每3关收费1.5元：SFRabbit_SetInitStage(2,3);
*/
extern void SFRabbit_SetInitStage(int valfree,int val);

void SFRabbitEntry(void)
{
#ifdef __J2ME__
	if(jvm_is_pause_mode())
	{
		mmi_java_display_is_busy_for_pause_mode();
		return;
	}
#endif


    //设置初始点数
	SFRabbit_SetInitStage(2,3);

	SFSystem_LaunchModule(SFMODID_GAME_RABBIT,SFNull,SF_LAUNCH_NORMAL);
}

#endif //__SF_MTK_APPLICATION_RABBIT__ENABLE__



#ifdef __SF_MTK_APPLICATION_3D__ENABLE__

//extern ISFApplication* SFAppTest_Create(void);

//无存档情况下初始给的点数

//extern void SetMyThemePath(UString path);

void SFApp3DEntry()
{
    //设置初始点数
	//SFMajiang_SetInitPoint(99);
	//if(theme)
	//{
    //    SetMyThemePath(L"E:\\themes\\theme2\\");
    //
	//}
    //else
    //{
    //    SetMyThemePath(L"E:\\themes\\theme1\\");
    //}

    SFSystem_LaunchModule(SFMODID_APP_TEST3D,SFNull,SF_LAUNCH_NORMAL);
}

#endif //__SF_MTK_APPLICATION_3D__ENABLE__




void SFSystem_GetCurrentDataTime(SFDateTime*pDataTime)
{
	MYTIME mt;
	DTGetRTCTime(&mt);
	pDataTime->nYear=(U16)mt.nYear;
	pDataTime->nMonth=(U8)mt.nMonth;
	pDataTime->nDay=(U8)mt.nDay;
	pDataTime->nHour=(U8)mt.nHour;
	pDataTime->nMinute=(U8)mt.nMin;
	pDataTime->nSecond=(U8)mt.nSec;
	kal_get_time(&pDataTime->nMill);
}


#define MAX_REGISTERED_SYS_CALLBACKS    32

typedef struct _SFSysCallbackTab
{
    SFUint32 iSysCallbackType;
    SFModule* iModule;
    SFCallback iCallback;
} SFSysCallbackTab;


static SFSysCallbackTab s_sys_callbacks[MAX_REGISTERED_SYS_CALLBACKS];
static SFInt8 s_sys_callbacks_cnt[SFSYS_CALLBACK_LAST];

static void SFSystem_InitCBTable(void)
{
    sf_memset(s_sys_callbacks,0,sizeof(s_sys_callbacks));
    sf_memset(s_sys_callbacks_cnt,0,sizeof(s_sys_callbacks_cnt));
}

extern SFUint64 SFAppPlatform_GetCurrentAppId(void);

SFReason SFSystem_RegisterCallbackInternal(SFModule* pMod,SFInt aIdxCallback,SFCallback aCallback)
{
    int i;
    SFSysCallbackTab* empty_slot=NULL;
    if(aIdxCallback<=SFSYS_CALLBACK_NONE||aIdxCallback>=SFSYS_CALLBACK_LAST)
        return SFReasonBadParameter;
    for(i=0;i<MAX_REGISTERED_SYS_CALLBACKS;i++)
    {
        if(!empty_slot && s_sys_callbacks[i].iSysCallbackType==0)
        {
            empty_slot=&s_sys_callbacks[i];
        }
        else if(s_sys_callbacks[i].iSysCallbackType==aIdxCallback && s_sys_callbacks[i].iModule==pMod)
        {
            empty_slot=&s_sys_callbacks[i];
            break;
        }
    }
    if(!empty_slot)
        return SFReasonOutOfResource;
    s_sys_callbacks_cnt[aIdxCallback]++;
    empty_slot->iModule=pMod;
    empty_slot->iSysCallbackType=aIdxCallback;
    empty_slot->iCallback=aCallback;
    empty_slot->iModule=g_kernal.iActiveModule;
    return SFReasonOK;
}

SFReason SFSystem_UnregisterCallbackInternal(SFModule* pMod,SFInt aIdxCallback,SFCallback aCallback)
{
    int i;
    for(i=0;i<MAX_REGISTERED_SYS_CALLBACKS;i++)
    {
        if(s_sys_callbacks[i].iSysCallbackType==aIdxCallback && s_sys_callbacks[i].iModule==pMod)
        {
            if(s_sys_callbacks[i].iModule==g_kernal.iActiveModule
                || (g_kernal.iActiveModule->iFlag&SFMOD_ATTR_SYSTEM))
            {
                --s_sys_callbacks_cnt[aIdxCallback];
                if(s_sys_callbacks_cnt[aIdxCallback]<0)
                    s_sys_callbacks_cnt[aIdxCallback]=0;
                s_sys_callbacks[i].iSysCallbackType=0;
                return SFReasonOK;
            }
            else
            {
                return SFReasonAccessDenied;
            }
        }
    }
    return SFReasonNotFound;
}

SFReason SFSystem_RegisterCallback(SFInt aIdxCallback,SFCallback aCallback)
{
    return SFSystem_RegisterCallbackInternal(g_kernal.iActiveModule,aIdxCallback,aCallback);
}


SFReason SFSystem_UnregisterCallback(SFInt aIdxCallback,SFCallback aCallback)
{
    return SFSystem_UnregisterCallbackInternal(g_kernal.iActiveModule,aIdxCallback,aCallback);
}

void SFSystem_UnregisterAllCallbacksForApp(SFModule* pMod)
{
    int i;
    for(i=0;i<MAX_REGISTERED_SYS_CALLBACKS;i++)
    {
        if(s_sys_callbacks[i].iSysCallbackType!=0 && (s_sys_callbacks[i].iModule==pMod||!pMod))
        {
            --s_sys_callbacks_cnt[s_sys_callbacks[i].iSysCallbackType];
                if(s_sys_callbacks_cnt[s_sys_callbacks[i].iSysCallbackType]<0)
                    s_sys_callbacks_cnt[s_sys_callbacks[i].iSysCallbackType]=0;
            s_sys_callbacks[i].iSysCallbackType=0;
            s_sys_callbacks[i].iModule=SFNull;
        }
    }
}



typedef int (*SMS_CB)(void* param,SFSMSMsg* msg);

int SFSystem_HandleSMSInternal(SFInt aIdxCallback,SFSMSMsg* msg)
{
    int i;
    for(i=0;i<MAX_REGISTERED_SYS_CALLBACKS;i++)
    {
        if(s_sys_callbacks[i].iSysCallbackType==aIdxCallback)
        {
            SMS_CB cb=(SMS_CB)s_sys_callbacks[i].iCallback.iCallback;
            if(cb)
            {
                int r;
                ENTER_MODULE(s_sys_callbacks[i].iModule)
                    r=(*cb)(s_sys_callbacks[i].iCallback.iParam,msg);
                LEAVE_MODULE()

                POST_EVENT_PROCESS()
                if(r!=0)
                {
                    return r;
                }
            }
        }
    }
    return 0;
}


SFCallback* SFSystem_GetCallback(SFModule* pMod,SFInt aIdxCallback)
{
    int i;
    for(i=0;i<MAX_REGISTERED_SYS_CALLBACKS;i++)
    {
        if(s_sys_callbacks[i].iModule==pMod && s_sys_callbacks[i].iSysCallbackType==aIdxCallback)
            return &s_sys_callbacks[i].iCallback;
    }
    return NULL;
}


static char bInMakeCall=0;

void SFSystem_OnMakeCall(const UChar* num)
{
    bInMakeCall=1;
}
void SFSystem_OnCallEventInternal(int v)
{
    int i;
    
    // 1 call connected
    // 2 call ended
    
    if(bInMakeCall)
    {
        if(s_sys_callbacks_cnt[SFSYS_CALLBACK_MAKE_CALL]>0)
        {
        for(i=0;i<MAX_REGISTERED_SYS_CALLBACKS;i++)
        {
            if(s_sys_callbacks[i].iSysCallbackType==SFSYS_CALLBACK_MAKE_CALL)
            {
                ENTER_MODULE(s_sys_callbacks[i].iModule)
                    s_sys_callbacks[i].iCallback.iCallback(s_sys_callbacks[i].iCallback.iParam);
                LEAVE_MODULE()

                POST_EVENT_PROCESS()
                break;
            }
        }
        }
        bInMakeCall=0;
    }
}

#define __PSEUDO_SND_ID_INVALID 0
#define __PSEUDO_SND_ID_MIDI    1
#define __PSEUDO_SND_ID_WAVE    2
#define __PSEUDO_SND_ID_FILE    3

SFSND_ID SFSnd_PlayFile(const UChar* path,SFSND_FORMAT format,int nLoopCount)
{
    if((MMI_PROFILE_SILENT == gactivatedprofile)
		|| (MMI_PROFILE_MEETING == gactivatedprofile)
		|| g_kernal.bFilePlaying
		|| g_kernal.bWavPlaying
		|| g_kernal.bMidiPlaying)
	{
		return __PSEUDO_SND_ID_INVALID;
	}
    if(mdi_audio_play_file((void*)path,nLoopCount==1?DEVICE_AUDIO_PLAY_ONCE:DEVICE_AUDIO_PLAY_INFINITE,NULL,NULL)==MDI_AUDIO_SUCCESS)
    {
        g_kernal.bFilePlaying=SFTrue;
        return __PSEUDO_SND_ID_FILE;
    }
    else
    {
        return __PSEUDO_SND_ID_INVALID;
    }
}



void SFSnd_SetVolume(SFSND_ID snd,int volume)
{
    volume=volume*MAX_VOL_LEVEL/SF_MAX_VOLUME;
    if(volume<0)
        volume=0;
    else if(volume>MAX_VOL_LEVEL)
        volume=MAX_VOL_LEVEL;
    
    switch(snd)
    {
    default:
        g_kernal.iVolume=volume;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA,volume);
        break;
    }
}

int SFSnd_GetVolume(SFSND_ID snd)
{
    switch(snd)
    {
    default:
        return g_kernal.iVolume*SF_MAX_VOLUME/MAX_VOL_LEVEL;
    }
}

/**
* @brief 开始播放一个声音
* @param pSndBuffer - 声音缓冲
* @param uBufferSize - 声音缓冲大小
* @param format - 声音数据格式
* @param nLoopCount - 0表示循环播放，其他表示播放次数
* @return 播放ID
*/
SFSND_ID SFSnd_Play(void*pSndBuffer,unsigned int uBufferSize,SFSND_FORMAT format,int nLoopCount)
{
	if((MMI_PROFILE_SILENT == gactivatedprofile)
		|| (MMI_PROFILE_MEETING == gactivatedprofile))
	{
		return __PSEUDO_SND_ID_INVALID;
	}
	if(g_kernal.bMidiPlaying || g_kernal.bWavPlaying || g_kernal.bFilePlaying)
        return __PSEUDO_SND_ID_INVALID;
//Output audio only through the earphone when earphone plugged
	if(format==SNDFORMAT_MIDI)
	{
		mdi_audio_stop_string();
		//PlayAudioMidiStream((U8*)pSndBuffer,(U16)uBufferSize,0);
		mdi_audio_play_string_with_vol_path(pSndBuffer,uBufferSize,MDI_FORMAT_SMF,nLoopCount==1?DEVICE_AUDIO_PLAY_ONCE:DEVICE_AUDIO_PLAY_INFINITE,SFNull,SFNull,255,isEarphonePlugged?MDI_DEVICE_SPEAKER2:MDI_DEVICE_SPEAKER_BOTH);
		g_kernal.bMidiPlaying=SFTrue;
		return __PSEUDO_SND_ID_MIDI;
	}
	else if(format==SNDFORMAT_WAVE
        || format==SNDFORMAT_AAC
        || format==SNDFORMAT_AMR)
	{
		mdi_audio_stop_string();
		//PlayAudioWavStream((U8*)pSndBuffer,(U16)uBufferSize,0);
		mdi_audio_play_string_with_vol_path(pSndBuffer,uBufferSize,(format==SNDFORMAT_AAC)?MDI_FORMAT_AAC:((format==SNDFORMAT_AMR)?MDI_FORMAT_AMR:MDI_FORMAT_WAV),nLoopCount==1?DEVICE_AUDIO_PLAY_ONCE:DEVICE_AUDIO_PLAY_INFINITE,SFNull,SFNull,255,isEarphonePlugged?MDI_DEVICE_SPEAKER2:MDI_DEVICE_SPEAKER_BOTH);
		g_kernal.bWavPlaying=SFTrue;
		return __PSEUDO_SND_ID_WAVE;
	}
    return __PSEUDO_SND_ID_INVALID;
}
/**
* @brief 结束并关闭声音的播放
* @param idSnd - 播放声音ID
*/
void SFSnd_Stop(SFSND_ID idSnd)
{
	if(idSnd==__PSEUDO_SND_ID_MIDI)
	{
        mdi_audio_stop_string();
        g_kernal.bMidiPlaying=0;
	}
	else if(idSnd==__PSEUDO_SND_ID_WAVE)
	{
        mdi_audio_stop_string();
        g_kernal.bWavPlaying=0;
	}
    else if(idSnd==__PSEUDO_SND_ID_FILE)
    {
        mdi_audio_stop_file();
        g_kernal.bFilePlaying=0;
    }
}


#define SFFS_MAX_OPEN_FILES 4

typedef struct _SFFS_Handle
{
    FS_HANDLE hFile;
    SFModule* iModule;
} SFFS_Handle;

static SFFS_Handle s_hFileList[SFFS_MAX_OPEN_FILES];
static void SFFS_Initialize(void)
{
    int i;
    for(i=0;i<SFFS_MAX_OPEN_FILES;i++)
    {
        s_hFileList[i].iModule=SFNull;
        s_hFileList[i].hFile=1;
    }
}
static void SFFS_Cleanup(SFModule* pMod)
{
    int i;
    for(i=0;i<SFFS_MAX_OPEN_FILES;i++)
    {
        if(s_hFileList[i].iModule && (!pMod || s_hFileList[i].iModule==pMod))
        {
            if(s_hFileList[i].hFile>=0)
                FS_Close(s_hFileList[i].hFile);
            s_hFileList[i].hFile=-1;
            s_hFileList[i].iModule=SFNull;
        }
    }
}


static SFFS_HANDLE SFFS_AllocSlot(void)
{
    int i;
    for(i=0;i<SFFS_MAX_OPEN_FILES;i++)
    {
        if(s_hFileList[i].iModule==SFNull)
        {
            return i+1;
        }
    }
    return 0;
}
static void SFFS_FreeSlot(SFFS_HANDLE id)
{
    if(id<=0 || id>SFFS_MAX_OPEN_FILES)
        return;
    s_hFileList[id-1].hFile=-1;
    s_hFileList[id-1].iModule=SFNull;
}

static void SFFS_SetHandle(SFFS_HANDLE id,FS_HANDLE hFile)
{
    if(id<=0 || id>SFFS_MAX_OPEN_FILES)
        return;
    s_hFileList[id-1].hFile=hFile;
    s_hFileList[id-1].iModule=g_kernal.iActiveModule;
}

static FS_HANDLE SFFS_FromHandle(SFFS_HANDLE id)
{
    if(id<=0 || id>SFFS_MAX_OPEN_FILES || s_hFileList[id-1].iModule!=g_kernal.iActiveModule)
        return -1;
    return s_hFileList[id-1].hFile;
}

struct _sf_vfs_i;
struct _sf_vfs_file_i;
struct _sf_vfs_class_i;
struct _sf_vfs_file_class_i;


typedef struct _sf_vfs_class_i sf_vfs_class_i;
typedef struct _sf_vfs_file_class_i sf_vfs_file_class_i;

typedef struct _sf_vfs_i sf_vfs_i;
typedef struct _sf_vfs_file_i sf_vfs_file_i;


struct _sf_vfs_i
{
    const sf_vfs_class_i* __vftab;
    int nRefCount;
    SFUint8 iVFSNodeIdx;
    SFModule* iModule;
    FS_HANDLE hFileFind;
    int iLastError;
};


static sf_vfs_char_t s_sf_vfs_temp_path[FS_MAX_PATH+1];

static sf_vfs_string_t sf_vfs_remap_path(sf_vfs_i* vfs,sf_vfs_char_t*tmp,sf_vfs_string_t path);

SFFS_HANDLE SFFS_Open(UString path,SFUint flags)
{
    UINT f=0;
    SFFS_HANDLE hFile=SFFS_AllocSlot();
    FS_HANDLE h;

    const UChar* n=SFNull;
    if(!hFile)
    {
        SFDEBUG("no free fs handlers");
        return SFFS_INVALID_HANDLE;
    }
	//暂时关闭存档功能
    if(flags&SFFSF_WRITE)
    {
        if(flags&SFFSF_CREATE)
        {
            f=FS_READ_WRITE|FS_CREATE_ALWAYS;//FROM FS_CREATE
        }
        else
        {
            f=FS_READ_WRITE;
        }
    }
    else if(flags&SFFSF_READ)
    {
        f=FS_READ_ONLY;
    }
    else if(flags&FS_CREATE)
    {
        f=FS_READ_WRITE|FS_CREATE_ALWAYS;
    }
    else
    {
        return 0;
    }
    if(sf_strbegins(path,-1,L"vfs:/",-1))
    {
        n=sf_vfs_remap_path(NULL,s_sf_vfs_temp_path,path);
        if(!n)
            n=path;
    }
    else
    {
        n=path;
    }
    
	h=FS_Open(n,f);
	if(h<0)
		return 0;
    if((flags&SFFSF_APPEND) && (flags&(SFFSF_WRITE|FS_CREATE)))
    {
        FS_Seek(h,0,FS_FILE_END);
    }
    SFFS_SetHandle(hFile,h);
	return hFile;
}


SFSize_T SFFS_Seek(SFFS_HANDLE hFile,SFSize_T sz,int pos)
{
    FS_HANDLE h=SFFS_FromHandle(hFile);
    if(h<0)
        return (SFSize_T)-1;
    return (SFSize_T)FS_Seek(h,(int)sz,pos);
}



SFSize_T SFFS_Read(SFFS_HANDLE hFile,SFAnyPtr buf,SFSize_T sz)
{
	UINT len=0;
    FS_HANDLE h=SFFS_FromHandle(hFile);
    if(h<0)
        return 0;
	FS_Read(h,buf,(UINT)sz,&len);
	return (SFSize_T)len;
}

SFSize_T SFFS_Write(SFFS_HANDLE hFile,const SFAny* buf,SFSize_T sz)
{
	UINT len=0;
    FS_HANDLE h=SFFS_FromHandle(hFile);
    if(h<0)
        return 0;
	FS_Write(h,(void*)buf,(UINT)sz,&len);
	return (SFSize_T)len;
}

void SFFS_Close(SFFS_HANDLE hHandle)
{
    FS_HANDLE h=SFFS_FromHandle(hHandle);
    if(h<0)
        return;
	FS_Close(h);
    SFFS_FreeSlot(hHandle);
}

SFBool SFFS_GetSize(SFFS_HANDLE hHandle,SFSize_T*pSz)
{
	UINT sz=0;
    FS_HANDLE h=SFFS_FromHandle(hHandle);
    if(h<0)
        return SFFalse;
	FS_GetFileSize(h,&sz);
	*pSz=sz;
	return  SFTrue;
}

int SFFS_GetAttributes(UString path,SFUint32* pattr)
{
    int attr=FS_GetAttributes(path);
    if(attr>=0)
    {
        *pattr=(SFUint32)attr;
        return 1;
    }
    else
    {
        return 0;
    }
}

int SFFS_SetAttributes(UString path,SFUint32 attr)
{
    return FS_SetAttributes((const WCHAR *) path,(BYTE) attr);
}


void SFScreen_DrawTextN(UString str,SFInt length,SFInt x,SFInt y,SFUint32 cr)
{
    color text_color;
    if(!str)
        return;
    if(length<0)
        length=sf_strlen(str);
    if(length>0)
    {
        text_color.alpha=(unsigned char)((cr & 0xff00000)>>24);
        text_color.r=(unsigned char)((cr & 0x00ff0000)>>16);
        text_color.g=(unsigned char)((cr & 0x0000ff00)>>8);
        text_color.b=(unsigned char)((cr & 0x000000ff));
        gui_set_text_color(text_color);
        gui_move_text_cursor(x,y);
        gui_print_text_n((UI_string_type)str,length);
	}
#if 0
	for(i=0;i<length;i++){
        
        buf[0]=((str[i]) &  0xff);
        buf[1]=((str[i]>>8) & 0xff);
        gui_print_text((UI_string_type)buf);
        cursor_x+=SFFont_GetCharWidth(str[i]);
	}
#endif //0
}

#define __PSEUDO_SMS_ID            1
#define __PSEUDO_INVALID_SMS_ID    0


static void SFSms_CallbackEx(void* number, module_type mod, U16 result)
{
    ISFApplication* pApp;
    SFModule* pMod=g_kernal.iSmsModule;
    if(!pMod)
        return;
    pApp=g_kernal.pSmsHandler;
    if(!pApp || !pApp->pfnEvtHandler)
        pApp=pMod->pApplication;
    g_kernal.iSmsModule=SFNull;
    g_kernal.pSmsHandler=SFNull;
    if(!pApp || !pApp->pfnEvtHandler)
    {
#ifndef SFAPI_WIN
        mmi_frm_sms_delete_screen_history();
#endif //!SFAPI_WIN
    }
    else
    {
        SFUint16 id=g_kernal.iSmsPsedoId;
        ++g_kernal.iSmsPsedoId;
        if(g_kernal.iSmsPsedoId==0)
            g_kernal.iSmsPsedoId=1;
        ENTER_MODULE(pMod)
#ifndef SFAPI_WIN
    	switch(result)
    	{
    	case MMI_FRM_SMS_OK:
    		DisplayPopup ((PU8)GetString(STR_SMS_SEND_SUCCESS), IMG_SEND_SUCCESS_PIC_MSG, 1, MESSAGES_POPUP_TIME_OUT, (U8)SUCCESS_TONE);
    		mmi_frm_sms_delete_screen_history();
    		AlmEnableSPOF();		
         	(*pApp->pfnEvtHandler)(pApp,EVT_SMS_SEND,(SFLPARAM)id,(SFWPARAM)1);
    		break;
    	case MMI_FRM_SMS_ABORT:
    		DisplayPopup ((PU8)GetString (STR_ABORT_SENDING_SMS), IMG_GLOBAL_ACTIVATED, 1, MESSAGES_POPUP_TIME_OUT, (U8)SUCCESS_TONE);
    		mmi_frm_sms_delete_screen_history();
    		AlmEnableSPOF();		
    		(*pApp->pfnEvtHandler)(pApp,EVT_SMS_SEND,(SFLPARAM)id,(SFWPARAM)0);
    		break;
    	case MMI_FRM_SMS_NOTREADY:
    		DisplayPopup ((PU8)GetString(STR_SMS_MSG_NOT_READY_YET), IMG_SEND_FAIL_PIC_MSG, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);			
    		AlmEnableSPOF();	
    		(*pApp->pfnEvtHandler)(pApp,EVT_SMS_SEND,(SFLPARAM)id,(SFWPARAM)0);
    		break;
    	case MMI_FRM_SMS_RETURN:
    	case MMI_FRM_SMS_END:
    		break;
    	default:
    		DisplayPopup ((PU8)GetString(STR_SMS_SEND_FAILED), IMG_SEND_FAIL_PIC_MSG, 1, MESSAGES_POPUP_TIME_OUT, (U8)ERROR_TONE);
    		mmi_frm_sms_delete_screen_history();
    		AlmEnableSPOF();		
    		(*pApp->pfnEvtHandler)(pApp,EVT_SMS_SEND,(SFLPARAM)id,(SFWPARAM)0);
    		break;
    	}
#else //!SFAPI_WIN
        (*pApp->pfnEvtHandler)(pApp,EVT_SMS_SEND,(SFLPARAM)id,(SFWPARAM)1);
#endif //SFAPI_WIN
        LEAVE_MODULE()

        POST_EVENT_PROCESS()
    }
}

extern int sf_ucs2_to_utf8(char *pszDest, int nSize,const UChar *pIn,int len,int *consumed);
extern UChar* sf_strcpy(UChar*buf,const UChar*str);

void SFSms_SendExA(const UChar*pNumber,const UChar *pContent,SFReason* pReason)
{
    mmi_frm_sms_send_struct sendData;

    if(g_kernal.iSmsModule)
    {
        if(pReason) *pReason=SFReasonNotReady;
        return;
    }
    memset((S8*)&sendData, 0, sizeof(mmi_frm_sms_send_struct));
    if(sf_ucs2_to_utf8((char*)sendData.number,sizeof(sendData.number),pNumber,-1,SFNull)<=0)
    {
        if(pReason) *pReason=SFReasonBadParameter;
        return;
    }

    if(pReason)
        *pReason=SFReasonPending;
    
    g_kernal.iSmsModule=g_kernal.iActiveModule;
    g_kernal.pSmsHandler=SFNull;

    //sending  code
    sendData.dcs=SMSAL_UCS2_DCS;
    sendData.stringlength=sf_strlen(pContent);
    sendData.string=OslMalloc((sendData.stringlength+1)*sizeof(UChar));
    sf_strcpy((UChar*)sendData.string, pContent);
#if defined(__MMI_DUAL_SIM_MASTER__)
    sendData.sendrequire|=MMI_FRM_SMS_DISP_SIM_OPT;
#endif //defined(__MMI_DUAL_SIM_MASTER__)
    
    mmi_frm_sms_send_sms(SFSms_CallbackEx, SFCUST_APP_MOD, &sendData);
}

SFSMS_ID SFSms_SendEx(const UChar*pNumber,const UChar *pContent,ISFApplication* pHandler)
{
    mmi_frm_sms_send_struct sendData;
    

    if(g_kernal.iSmsModule)
        return __PSEUDO_INVALID_SMS_ID;

    memset((S8*)&sendData, 0, sizeof(mmi_frm_sms_send_struct));
    
    if(sf_ucs2_to_utf8((char*)sendData.number,sizeof(sendData.number),pNumber,-1,SFNull)<=0)
        return __PSEUDO_INVALID_SMS_ID;
    
    g_kernal.iSmsModule=g_kernal.iActiveModule;
    g_kernal.pSmsHandler=pHandler;
    
    //sending  code
    sendData.dcs=SMSAL_UCS2_DCS;
    sendData.stringlength=sf_strlen(pContent);
    sendData.string=OslMalloc((sendData.stringlength+1)*sizeof(UChar));
    sf_strcpy((UChar*)sendData.string, pContent);
#if defined(__MMI_DUAL_SIM_MASTER__)
    sendData.sendrequire|=MMI_FRM_SMS_DISP_SIM_OPT;
#endif //defined(__MMI_DUAL_SIM_MASTER__)
    
    mmi_frm_sms_send_sms(SFSms_CallbackEx, SFCUST_APP_MOD, &sendData);

    if(g_kernal.iSmsPsedoId==0)
        g_kernal.iSmsPsedoId=1;
    
    return g_kernal.iSmsPsedoId;
}

SFSMS_ID SFSms_Send(const UChar*pNumber,const UChar *pContent)
{
    return SFSms_SendEx(pNumber,pContent,g_kernal.iActiveModule->pApplication);
}

SFBool SFSystem_HasSim(void)
{
	return (mmi_bootup_is_sim_valid())?SFTrue:SFFalse;
}


//Data_Account Interface
extern void DataAccountReadyCheck(FuncPtr ready_callback);
extern void GPRSAppDTCNTSelect( FuncPtrShort callback, U16 AppMenuID);
extern kal_uint8 custom_get_csd_profile_num(void);




typedef struct _SFPCMDrvParam SFPCMDrvParam;
struct _SFPCMDrvParam
{
    kal_uint8* pBuffer;
    kal_uint32 uBufferSize;
    kal_uint8* pReader;//for drv
    kal_uint8* pWriter;//for app
};


struct _SFPCMDevice
{
    SFModule* iModule;
    SFInt8 iVolume;
    SFUint32 iSamplePerSec;
    SFPCMDrvParam iParam;
    SFUint8 bIsActive;
};

/**
* @brief 创建一个PCM播放设备
* @param aFormat - 必须为0
* @param aSamplesPerSec - 每秒的采样数
* @param aBit - 采样精度8/16
* @param aChannel - 声道
* @return 创建的声音设备
*/
static SFPCMDevice s_pcm_device;

void SFPCMDrv_GetParam(SFPCMDrvParam** aParam)
{
    *aParam=&s_pcm_device.iParam;
}

kal_bool SFPCMDrv_IsActive(void)
{
    return s_pcm_device.bIsActive;
}

void SFPCMDrv_SetActive(kal_bool bActive)
{
    s_pcm_device.bIsActive=bActive;
}

#ifdef SFCUST_STATIC_PCMDRV_BUFFER
#define SF_SOUND_BUFFER_SIZE 16384
static SFUint32 s_pcm_drv_buf[SF_SOUND_BUFFER_SIZE/sizeof(SFUint32)];
#endif //SFCUST_STATIC_PCMDRV_BUFFER

SFPCMDevice* SFPCMDevice_Create(SFInt aFormat,SFInt aSamplesPerSec,SFInt aBit,SFInt aChannel)
{
#ifdef SFAPI_WIN
    extern SFPCMDevice* SFPCMDevice_CreateW(SFInt aFormat,SFInt aSamplesPerSec,SFInt aBit,SFInt aChannel);
    return SFPCMDevice_CreateW(aFormat,aSamplesPerSec,aBit,aChannel);
#else
    if(aChannel!=1 || aFormat!=0 || aBit!=16 || (aSamplesPerSec!=8000 && aSamplesPerSec!=16000)
        || s_pcm_device.iModule!=SFNull)
        return SFNull;
    s_pcm_device.iVolume=g_kernal.iVolume;
    s_pcm_device.iModule=g_kernal.iActiveModule;
    s_pcm_device.iSamplePerSec=aSamplesPerSec;
#ifdef SFCUST_STATIC_PCMDRV_BUFFER
    memset(s_pcm_drv_buf,0,SF_SOUND_BUFFER_SIZE);

    s_pcm_device.iParam.pBuffer=(kal_uint8*)s_pcm_drv_buf;
    s_pcm_device.iParam.uBufferSize=SF_SOUND_BUFFER_SIZE;
#else //SFCUST_STATIC_PCMDRV_BUFFER
    s_pcm_device.iParam.pBuffer=SFNull;
    s_pcm_device.iParam.uBufferSize=0;
#endif //SFCUST_STATIC_PCMDRV_BUFFER
    s_pcm_device.iParam.pReader=s_pcm_device.iParam.pBuffer;
    s_pcm_device.iParam.pWriter=s_pcm_device.iParam.pBuffer;
	return &s_pcm_device;
#endif
}

void SFPCMDevice_SetBuffer(SFPCMDevice* aDevice,void* aBuffer,SFSize_T aSize)
{
    if(aDevice->iModule==g_kernal.iActiveModule)
    {
#ifndef SFAPI_WIN
        aDevice->iParam.pBuffer=(kal_uint8*)aBuffer;
        aDevice->iParam.uBufferSize=aSize;
        aDevice->iParam.pReader=(kal_uint8*)aBuffer;
        aDevice->iParam.pWriter=(kal_uint8*)aBuffer;
#endif //SFAPI_WIN
    }
}

/**
* @brief 开始播放指定的设备
* @param aDevice - 播放的设备
*/
void SFPCMDevice_Start(SFPCMDevice* aDevice)
{
	if(aDevice->iModule==g_kernal.iActiveModule)
	{
#ifdef SFAPI_WIN
        extern void SFPCMDevice_StartW(SFPCMDevice* aDevice);
        SFPCMDevice_StartW(aDevice);
#else
    	if((MMI_PROFILE_SILENT == gactivatedprofile)
    		|| (MMI_PROFILE_MEETING == gactivatedprofile)
    		|| !aDevice->iParam.uBufferSize
    		|| !aDevice->iParam.pBuffer)
    	{
    		return;
    	}
        //active the drv
    	SFPCMDrv_SetActive(1);

        aDevice->iParam.pReader=aDevice->iParam.pBuffer;
        aDevice->iParam.pWriter=aDevice->iParam.pBuffer;

    	mdi_audio_play_string_with_vol_path_non_block(aDevice->iParam.pBuffer, aDevice->iParam.uBufferSize, 
    		aDevice->iSamplePerSec==8000?MDI_FORMAT_PCM_8K:MDI_FORMAT_PCM_16K, 
    		DEVICE_AUDIO_PLAY_INFINITE, NULL, NULL,GetRingVolumeLevel(),MDI_DEVICE_SPEAKER2);
#endif 
	}
}

/**
* @brief 停止声音播放
* @param aDevice - 播放的设备
*/
void SFPCMDevice_Stop(SFPCMDevice* aDevice)
{
    if(aDevice->iModule==g_kernal.iActiveModule 
        || (g_kernal.iActiveModule->iFlag&SFMOD_ATTR_SYSTEM))
    {
#ifdef SFAPI_WIN
        extern void SFPCMDevice_StopW(SFPCMDevice* aDevice);
        SFPCMDevice_StopW(aDevice);
#else
    	if(aDevice->bIsActive)
    	{
            mdi_audio_stop_string();
    	    SFPCMDrv_SetActive(0);
    	}
#endif
    }
}

/**
* @brief 关闭设备
* @param aDevice - 创建的声音设备
*/
void SFPCMDevice_Close(SFPCMDevice* aDevice)
{
#ifdef SFAPI_WIN
    extern void SFPCMDevice_CloseW(SFPCMDevice* aDevice);
    SFPCMDevice_CloseW(aDevice);
#else
    if(aDevice->iModule==g_kernal.iActiveModule 
        || (g_kernal.iActiveModule->iFlag&SFMOD_ATTR_SYSTEM))
    {
    	if(aDevice->bIsActive)
    	{
            mdi_audio_stop_string();
    	    SFPCMDrv_SetActive(0);
    	}
        aDevice->iModule=SFNull;
    }
#endif
}

/**
* @brief 设置设备的音量
* @param aDevice - 创建的声音设备
* @param aVolume - 设置的音量
*/
void SFPCMDevice_SetVolume(SFPCMDevice* aDevice,SFInt aVolume)
{
    aVolume=aVolume*MAX_VOL_LEVEL/SF_MAX_VOLUME;
    if(aVolume<0)
        aVolume=0;
    else if(aVolume>MAX_VOL_LEVEL)
        aVolume=MAX_VOL_LEVEL;
    
    aDevice->iVolume=aVolume;
    mdi_audio_set_volume(MDI_VOLUME_MEDIA,aVolume);
}

/**
* @brief 获取设备的音量
* @param aDevice - 创建的声音设备
* @return 音量
*/
SFInt SFPCMDevice_GetVolume(SFPCMDevice* aDevice)
{
	return aDevice->iVolume*SF_MAX_VOLUME/MAX_VOL_LEVEL;
}




SFSize_T SFApp_GetCommandLine(UChar* aBuffer,SFSize_T aSize)
{
#ifdef SFAPI_WIN
    extern SFSize_T SFApp_GetCommandLineW(UChar* aBuffer,SFSize_T aSize);
    return SFApp_GetCommandLineW(aBuffer,aSize);
#else
	SFSize_T realSize;
	realSize=sf_strlen(u16_g_game_file_name);
    if(realSize>=aSize)
        realSize=aSize=1;
    memcpy(aBuffer,u16_g_game_file_name,sizeof(UChar)*realSize);
	sf_strcpy(aBuffer,u16_g_game_file_name);
    aBuffer[realSize] = 0x0;		

	return realSize;
#endif
}





static const SFDeviceKeyMap* s_keypadRemapTable=SFNull;

static SFUint8 s_bKeyStateMapInited=0;
static SFUint32 s_KeyStateMap[42]=
{
    0
};
static SFUint8 s_KeyMap[42]=
{
    0
};

static SFUint32 SFSystem_MapKeyToKeyState(int k)
{
    switch(k)
    {
    case SFKEY_NUM0:
        return SFKS_NUM0;
    case SFKEY_NUM1:
        return SFKS_NUM1;
    case SFKEY_NUM2:
        return SFKS_NUM2;
    case SFKEY_NUM3:
        return SFKS_NUM3;
    case SFKEY_NUM4:
        return SFKS_NUM4;
    case SFKEY_NUM5:
        return SFKS_NUM5;
    case SFKEY_NUM6:
        return SFKS_NUM6;
    case SFKEY_NUM7:
        return SFKS_NUM7;
    case SFKEY_NUM8:
        return SFKS_NUM8;
    case SFKEY_NUM9:
        return SFKS_NUM9;
    case SFKEY_STAR:
        return SFKS_STAR;
    case SFKEY_POUND:
        return SFKS_POUND;
    case SFKEY_VOLUP:
        return SFKS_VOLUP;
    case SFKEY_VOLDOWN:
        return SFKS_VOLDOWN;
    case SFKEY_UP:
        return SFKS_UP;
    case SFKEY_DOWN:
        return SFKS_DOWN;
    case SFKEY_LEFT:
        return SFKS_LEFT;
    case SFKEY_RIGHT:
        return SFKS_RIGHT;
    case SFKEY_SM:
        return SFKS_SM;
    case SFKEY_SL:
        return SFKS_SL;
    case SFKEY_SR:
        return SFKS_SR;
    case SFKEY_SEND:
        return SFKS_SEND;
    case SFKEY_END:
        return SFKS_END;
    case SFKEY_POWER:
        return SFKS_POWER;
    case SFKEY_CLR:
        return SFKS_CLR;
    }
    return 0;
}



static void SFSystem_InitKeyStateMap(void);

static void SFSystem_SetupKeyMapTable(const SFDeviceKeyMap* keypadRemapTable)
{
    if(s_keypadRemapTable!=keypadRemapTable)
{
    s_keypadRemapTable=keypadRemapTable;
    s_bKeyStateMapInited=SFFalse;
    SFSystem_InitKeyStateMap();
}
}

static void SFSystem_SetActiveAppKeyMapTable(const SFDeviceKeyMap* keypadRemapTable)
{
    g_kernal.iActiveApp->iKeyStateMap=keypadRemapTable;
}

static void SFSystem_InitKeyStateMap2(void)
{
#ifdef MMI_ON_HARDWARE_P
    int i;
    extern const keypad_struct *keypad_Get_Data(void);
    const SFUint8* kstab=keypad_Get_Data()->keypad;
    for(i=0;i<42;i++)
    {
        if(s_keypadRemapTable)
        {
            SFUint8 k=0xFF;

            int j;
            switch(kstab[i])
            {
            case DEVICE_KEY_MENU:
                k=SFKEY_SM;
                break;
            case DEVICE_KEY_SK_LEFT:
                k=SFKEY_SL;
                break;
            case DEVICE_KEY_SK_RIGHT:
                k=SFKEY_SR;
                break;
            case DEVICE_KEY_SEND:
                k=SFKEY_SEND;
                break;
            case DEVICE_KEY_END:
                k=SFKEY_END;
                break;
            case DEVICE_KEY_POWER:
                k=SFKEY_POWER;
                break;
            case DEVICE_KEY_CLEAR:
                k=SFKEY_CLR;
                break;
            }
            s_KeyMap[i]=k;

            for(j=0;s_keypadRemapTable[j].iSFKey!=0;j++)
            {
                if(kstab[i]==s_keypadRemapTable[j].iDeviceKey)
                {
                    s_KeyMap[i]=s_keypadRemapTable[j].iSFKey;
                }
            }
        }
        else
        {
        SFUint8 k=0xFF;
        switch(kstab[i])
        {
        case DEVICE_KEY_0:
            k=SFKEY_NUM0;
            break;
        case DEVICE_KEY_1:
            k=SFKEY_NUM1;
            break;
        case DEVICE_KEY_2:
            k=SFKEY_NUM2;
            break;
        case DEVICE_KEY_3:
            k=SFKEY_NUM3;
            break;
        case DEVICE_KEY_4:
            k=SFKEY_NUM4;
            break;
        case DEVICE_KEY_5:
            k=SFKEY_NUM5;
            break;
        case DEVICE_KEY_6:
            k=SFKEY_NUM6;
            break;
        case DEVICE_KEY_7:
            k=SFKEY_NUM7;
            break;
        case DEVICE_KEY_8:
            k=SFKEY_NUM8;
            break;
        case DEVICE_KEY_9:
            k=SFKEY_NUM9;
            break;
        case DEVICE_KEY_STAR:
            k=SFKEY_STAR;
            break;
        case DEVICE_KEY_HASH:
            k=SFKEY_POUND;
            break;
        case DEVICE_KEY_VOL_UP:
            k=SFKEY_VOLUP;
            break;
        case DEVICE_KEY_VOL_DOWN:
            k=SFKEY_VOLDOWN;
            break;
        case DEVICE_KEY_UP:
            k=SFKEY_UP;
            break;
        case DEVICE_KEY_DOWN:
            k=SFKEY_DOWN;
            break;
        case DEVICE_KEY_LEFT:
            k=SFKEY_LEFT;
            break;
        case DEVICE_KEY_RIGHT:
            k=SFKEY_RIGHT;
            break;
        case DEVICE_KEY_MENU:
            k=SFKEY_SM;
            break;
        case DEVICE_KEY_SK_LEFT:
            k=SFKEY_SL;
            break;
        case DEVICE_KEY_SK_RIGHT:
            k=SFKEY_SR;
            break;
        case DEVICE_KEY_SEND:
            k=SFKEY_SEND;
            break;
        case DEVICE_KEY_END:
            k=SFKEY_END;
            break;
        case DEVICE_KEY_POWER:
            k=SFKEY_POWER;
            break;
        case DEVICE_KEY_CLEAR:
            k=SFKEY_CLR;
            break;
        }
            s_KeyMap[i]=k;
        }
        s_KeyStateMap[i]=SFSystem_MapKeyToKeyState(s_KeyMap[i]);
    }
#endif //MMI_ON_HARDWARE_P
}

static void SFSystem_InitKeyStateMap(void)
{
    if(!s_bKeyStateMapInited)
    {
        s_bKeyStateMapInited=SFTrue;
        SFSystem_InitKeyStateMap2();
    }
}


#define		KEY_REGISTER_TIME		0x80200230
#define		KEY_REGISTER_LOW		0x80110004
#define		KEY_REGISTER_MID		0x80110008
#define		KEY_REGISTER_HIG		0x8011000c

#if 0
/* automatically generated by snowfish keygen tool (C) 2007, Yu Simin @ Snowfish Tech. */
#define KEY_PUB_VOLDOWN 0xFFFE
#define REGISTER_PUB_VOLDOWN KEY_REGISTER_LOW
#define KEY_PUB_VOLUP 0xFFFD
#define REGISTER_PUB_VOLUP KEY_REGISTER_LOW
#define KEY_PUB_LSK 0xFFFB
#define REGISTER_PUB_LSK KEY_REGISTER_LOW
#define KEY_PUB_RSK 0xFFF7
#define REGISTER_PUB_RSK KEY_REGISTER_LOW
#define KEY_PUB_UP 0xFF7F
#define REGISTER_PUB_UP KEY_REGISTER_LOW
#define KEY_PUB_OK 0xFEFF
#define REGISTER_PUB_OK KEY_REGISTER_LOW
#define KEY_PUB_LEFT 0xFDFF
#define REGISTER_PUB_LEFT KEY_REGISTER_LOW
#define KEY_PUB_RIGHT 0xFBFF
#define REGISTER_PUB_RIGHT KEY_REGISTER_LOW
#define KEY_PUB_CALL 0xBFFF
#define REGISTER_PUB_CALL KEY_REGISTER_LOW
#define KEY_PUB_DOWN 0x7FFF
#define REGISTER_PUB_DOWN KEY_REGISTER_LOW
#define KEY_PUB_1 0xFFDF
#define REGISTER_PUB_1 KEY_REGISTER_MID
#define KEY_PUB_2 0xFFBF
#define REGISTER_PUB_2 KEY_REGISTER_MID
#define KEY_PUB_3 0xFF7F
#define REGISTER_PUB_3 KEY_REGISTER_MID
#define KEY_PUB_STAR 0xFEFF
#define REGISTER_PUB_STAR KEY_REGISTER_MID
#define KEY_PUB_4 0xEFFF
#define REGISTER_PUB_4 KEY_REGISTER_MID
#define KEY_PUB_5 0xDFFF
#define REGISTER_PUB_5 KEY_REGISTER_MID
#define KEY_PUB_6 0xBFFF
#define REGISTER_PUB_6 KEY_REGISTER_MID
#define KEY_PUB_0 0x7FFF
#define REGISTER_PUB_0 KEY_REGISTER_MID
#define KEY_PUB_7 0x03F7
#define REGISTER_PUB_7 KEY_REGISTER_HIG
#define KEY_PUB_8 0x03EF
#define REGISTER_PUB_8 KEY_REGISTER_HIG
#define KEY_PUB_9 0x03DF
#define REGISTER_PUB_9 KEY_REGISTER_HIG
#define KEY_PUB_POUND 0x03BF
#define REGISTER_PUB_POUND KEY_REGISTER_HIG

#endif //0








#if defined(__SF_KEYPAD_SUPPORT__)

static const int keypad_mask_map[MAX_KEYPAD_KEYS]=
{
    SFKS_NES_UP,            //virtual key mask for 00 01 UP
    SFKS_NES_DOWN,          //virtual key mask for 00 02 DOWN
    SFKS_NES_LEFT,          //virtual key mask for 00 04 LEFT
    SFKS_NES_RIGHT,         //virtual key mask for 00 08 RIGHT
    SFKS_NES_SOUND_SWITCH,  //virtual key mask for 00 10 L
    SFKS_NES_ROTATE,        //virtual key mask for 00 20 R
    SFKS_NES_SELECT,        //virtual key mask for 00 40 SEL
    SFKS_NES_START,         //virtual key mask for 00 80 START
    
    0,                      //virtual key mask for 01 00 TURBO
    SFKS_NES_A,             //virtual key mask for 02 00 1
    SFKS_NES_B,             //virtual key mask for 04 00 2
    SFKS_NES_A,             //virtual key mask for 08 00 3
    SFKS_NES_B,             //virtual key mask for 10 00 4
    0,                      //virtual key mask for 20 00 
    0,                      //virtual key mask for 40 00
    0                       //virtual key mask for 80 00
};
#endif //defined(__SF_KEYPAD_SUPPORT__)



#if defined(__SF_KEYPAD_SUPPORT__)

static void SFKeypad_Clear(void)
{
    module_type prev_owner=0;
    prev_owner=UART_GetOwnerID(KEYPAD_UART_PORT);
    UART_SetOwner(KEYPAD_UART_PORT,SFCUST_APP_MOD);
    do
    {
        int len=UART_GetBytesAvail(KEYPAD_UART_PORT);
        SFUint8 status;
        if(len>0)
        {
            SFUint8 temp[64];
            UART_GetBytes(KEYPAD_UART_PORT,temp,64,&status,SFCUST_APP_MOD);
        }
        else
            break;
    } while(len>0);
    bytes_in_buffer=0;
    keypad_data=0;
}

#endif //defined(__SF_KEYPAD_SUPPORT__)

#if defined(__SF_KEYPAD_SUPPORT__)

SFUint32 SFSystem_GetKeypadState(void)
{
    SFUint32 keyValue = 0;
    int i;
    if(s_bKeypadEnable)
    {
        int j;
        module_type prev_owner=0;
        prev_owner=UART_GetOwnerID(KEYPAD_UART_PORT);
        UART_SetOwner(KEYPAD_UART_PORT,SFCUST_APP_MOD);
        for(;;)
        {
            int len=UART_GetBytesAvail(KEYPAD_UART_PORT);
            int remain=MAX_KEYPAD_BUFFER_SIZE-bytes_in_buffer;
            if(len>0)
            {
                int i,read_len;
                SFUint8 status;
                
                len=len<remain?len:remain;
                read_len=UART_GetBytes(KEYPAD_UART_PORT,keypad_buffer+bytes_in_buffer,len,&status,SFCUST_APP_MOD);

                //ASSERT(len==read_len);
                bytes_in_buffer+=read_len;
                //process the data
                for(i=0;i<bytes_in_buffer-4;i++)
                {
                    if(keypad_buffer[i]==0xFF && keypad_buffer[i+1]==0x55 && keypad_buffer[i+4]==0xAA)
                    {
                        //start code and end code detected
                        keypad_data=(keypad_buffer[i+2]<<8)|keypad_buffer[i+3];
                        i+=4;
                    }
                }
                if(i<bytes_in_buffer)
                {
                    memcpy(keypad_buffer,keypad_buffer+i,bytes_in_buffer-i);
                    bytes_in_buffer-=i;
                }
                else
                {
                    bytes_in_buffer=0;
                }
            }
            else
            {
                break;
            }
        }
        UART_SetOwner(KEYPAD_UART_PORT,prev_owner);
        for(j=0;j<MAX_KEYPAD_KEYS;j++)
        {
            if(keypad_data&(1<<j))
            {
                keyValue|=keypad_mask_map[j];
            }
        }
    }
    return keyValue;
}
#else
SFUint32 SFSystem_GetKeypadState(void)
{
    return 0;
}

#endif //defined(__SF_KEYPAD_SUPPORT__)

SFUint32 SFSystem_GetKeyState(void)
{
#ifdef SFAPI_WIN
    extern SFUint32 SFSystem_GetKeyStateW(void);
    return SFSystem_GetKeyStateW();
#else
	SFUint32 keyValue = 0;
    SFUint32 regval1=0,regval2=0;
    int i;
#if defined(__SF_KEYPAD_SUPPORT__)
    keyValue=SFSystem_GetKeypadState();
#endif //defined(__SF_KEYPAD_SUPPORT__)

#if defined(__SF_MTK_APPLICATION_EMU__ENABLE__) && defined(SFCUST_NESEMU_LEGACY_KEYMAP)
    SFCUST_NESEMU_LEGACY_KEYMAP
#endif //defined(__SF_MTK_APPLICATION_EMU__ENABLE__)

    regval1=DRV_Reg32(KEY_REGISTER_LOW);
    regval2=DRV_Reg32(KEY_REGISTER_MID);

    for(i=0;i<16;i++)
    {
        if(!(regval1&(~(SFUint16)(~(1<<i)))))
        {
            keyValue|=s_KeyStateMap[i];
        }
        if(!(regval2&(~(SFUint16)(~(1<<i)))))
        {
            keyValue|=s_KeyStateMap[i+16];
        }
    }
    regval1=DRV_Reg32(KEY_REGISTER_HIG);
    for(i=0;i<10;i++)
    {
        if(!(regval1&(~((0x3FF)&(~(1<<i))))))
        {
            keyValue|=s_KeyStateMap[i+32];
        }
    }
#ifdef SFCUST_GET_KEY_STATE
	SFCUST_GET_KEY_STATE
#endif //SFCUST_GET_KEY_STATE
	return keyValue;
#endif
}

#ifdef __SF_PCMDRV_SUPPORT__

void SFPCMDevice_GetCurrentPosition(SFPCMDevice* self,SFUint32*pPlayCursor,SFUint32* pWriteCursor)
{
#ifdef SFAPI_WIN
    extern void SFPCMDevice_GetCurrentPositionW(SFPCMDevice* self,SFUint32*pPlayCursor,SFUint32* pWriteCursor);
    SFPCMDevice_GetCurrentPositionW(self,pPlayCursor,pWriteCursor);
#else
	if(!self)
	{
        if(pPlayCursor)
            *pPlayCursor=0;
        if(pWriteCursor)
            *pWriteCursor=0;
	}
    else
    {

        if(pPlayCursor)
    	{
    		*pPlayCursor=(uint32)(self->iParam.pReader-self->iParam.pBuffer);
    	}
    	
    	if(pWriteCursor)
    	{
    		*pWriteCursor=(uint32)(self->iParam.pWriter-self->iParam.pBuffer);
    	}
    }
#endif
}


void SFPCMDevice_LockBuffer(SFPCMDevice* self,SFUint32 offset,SFUint32 size,SFAny** pBuf0,SFUint32* pBufSize0,SFAny** pBuf1,SFUint32* pBufSize1)
{
#ifdef SFAPI_WIN
    extern void SFPCMDevice_LockBufferW(SFPCMDevice* self,SFUint32 offset,SFUint32 size,SFAny** pBuf0,SFUint32* pBufSize0,SFAny** pBuf1,SFUint32* pBufSize1);

    SFPCMDevice_LockBufferW(self,offset,size,pBuf0,pBufSize0,pBuf1,pBufSize1);
#else

 	if(!self || !self->bIsActive)
	{
		*pBuf0 = NULL;
		*pBuf1 = NULL;
		*pBufSize0 = 0;
		*pBufSize1 = 0;
		return;
	}
    
    if(offset==0xFFFFFFFF)
	{
		SFPCMDevice_GetCurrentPosition(self,SFNull,&offset);
	}
	
	if(offset+size>self->iParam.uBufferSize)
	{
		*pBuf0=self->iParam.pBuffer+offset;
		*pBufSize0=self->iParam.uBufferSize-offset;

		*pBuf1=self->iParam.pBuffer;
		*pBufSize1=offset+size-self->iParam.uBufferSize;
	}
	else
	{
		*pBuf0=self->iParam.pBuffer+offset;
		*pBufSize0=size;

		*pBuf1=SFNull;
		*pBufSize1=0;
	}
#endif 
}

void SFPCMDevice_UnlockBuffer(SFPCMDevice* self,SFAny* aBuf0,SFUint32 aBufSize0,SFAny* aBuf1,SFUint32 aBufSize1)
{
#ifdef SFAPI_WIN
    extern void SFPCMDevice_UnlockBufferW(SFPCMDevice* self,SFAny* aBuf0,SFUint32 aBufSize0,SFAny* aBuf1,SFUint32 aBufSize1);

    SFPCMDevice_UnlockBufferW(self,aBuf0,aBufSize0,aBuf1,aBufSize1);
#else
    //提交音频数据
    if(!self || !self->bIsActive)
        return;
    
	if(aBuf1 && aBufSize1)
	{
		self->iParam.pWriter=(SFUint8*)aBuf1+aBufSize1;
	}
	else
	{
		self->iParam.pWriter=(SFUint8*)aBuf0+aBufSize0;
	}
#endif
}

#endif //__SF_PCMDRV_SUPPORT__


#ifdef __SF_MP4_SUPPORT__

extern const char* vdo_get_wap_service_url(int service_id);
int sf_wap_start_browser(const char* url);

void vdo_open_wap_service(int service_id)
{
    sf_wap_start_browser(vdo_get_wap_service_url(service_id));
}

#endif //__SF_MP4_SUPPORT__




void* sf_system_malloc(unsigned int size)
{
	return med_alloc_ext_mem(size);
}

void* sf_system_malloc_fast(unsigned int size)
{
	return med_alloc_int_mem(size);
}

void sf_system_free(void*ptr)
{
	med_free_ext_mem(&ptr);
}

void sf_system_free_fast(void*ptr)
{
	med_free_int_mem(&ptr);
}



#if defined(__SF_MP4_SUPPORT__)

#include "med_global.h" 
#include "med_utility.h" 
#include "mdi_video.h" 

static void LCDDisplay_adrs (const lcd_frame_update_struct *lcd_param, void* adrs, U8 layer)
{
	kal_uint16 w, h;
	lcd_frame_update_struct lcd_data = {0};

	lcd_power_up();

	w = lcd_param->lcm_end_x - lcd_param->lcm_start_x + 1;
	h = lcd_param->lcm_end_y - lcd_param->lcm_start_y + 1;

	if (layer == 0)
	{
		SET_LCD_LAYER0_WINDOW_SIZE(w,h);
		SET_LCD_LAYER0_WINDOW_OFFSET(0,0);
		SET_LCD_LAYER0_ROTATE(lcd_param->rotate_value);
		lcd_data.update_layer=LCD_LAYER0_ENABLE;

		REG_LCD_LAYER0_BUFF_ADDR = (kal_uint32) adrs;
	}
	else if (layer == 1)
	{
		SET_LCD_LAYER1_WINDOW_SIZE(w,h);
		SET_LCD_LAYER1_WINDOW_OFFSET(0,0);
		SET_LCD_LAYER1_ROTATE(lcd_param->rotate_value);
		lcd_data.update_layer=LCD_LAYER1_ENABLE;

		REG_LCD_LAYER1_BUFF_ADDR = (kal_uint32) adrs;
	}
	else if (layer == 2)
	{
		SET_LCD_LAYER2_WINDOW_SIZE(w,h);
		SET_LCD_LAYER2_WINDOW_OFFSET(0,0);
		SET_LCD_LAYER2_ROTATE(lcd_param->rotate_value);
		lcd_data.update_layer=LCD_LAYER2_ENABLE;

		REG_LCD_LAYER2_BUFF_ADDR = (kal_uint32) adrs;
	}
	else if (layer == 3)
	{
		SET_LCD_LAYER3_WINDOW_SIZE(w,h);
		SET_LCD_LAYER3_WINDOW_OFFSET(0,0);
		SET_LCD_LAYER3_ROTATE(lcd_param->rotate_value);
		lcd_data.update_layer=LCD_LAYER3_ENABLE;

		REG_LCD_LAYER3_BUFF_ADDR = (kal_uint32) adrs;
	}
	else
	{
		MMI_ASSERT(0);
	}


	if (lcd_param->rotate_value == MDI_VIDEO_LCD_ROTATE_0)
	{
		lcd_data.roi_offset_x = 0;
		lcd_data.roi_offset_y = 0;
	}
	else
	{
		lcd_data.roi_offset_x = lcd_param->roi_offset_x;
		lcd_data.roi_offset_y = lcd_param->roi_offset_y;
	}

	lcd_data.lcm_start_x = lcd_param->lcm_start_x;
	lcd_data.lcm_start_y = lcd_param->lcm_start_y;
	lcd_data.lcm_end_x = lcd_param->lcm_end_x;
	lcd_data.lcm_end_y = lcd_param->lcm_end_y;
	lcd_data.rotate_value = lcd_param->rotate_value;
	lcd_data.update_layer = lcd_param->update_layer;
	lcd_data.hw_update_layer = lcd_param->hw_update_layer;

	lcd_data.module_id = LCD_UPDATE_MODULE_JPEG_VIDEO;
	lcd_data.lcd_id = MAIN_LCD;
	lcd_data.fb_update_mode = LCD_SW_TRIGGER_MODE;
	lcd_data.memory_output  = KAL_FALSE;
	lcd_data.block_mode_flag = KAL_TRUE;
	lcd_data.lcd_block_mode_cb = NULL;

	lcd_fb_update(&lcd_data);
}

extern void vdo_get_active_buffer(U8** ptr);

void SF_vdo_screen_update(const lcd_frame_update_struct *lcd_param)
{
	U8 *buf_ptr;
	U8  layer_pos=0;

	if ((lcd_param->hw_update_layer & LCD_LAYER0_ENABLE) != 0)
		layer_pos = 0;
	else if ((lcd_param->hw_update_layer & LCD_LAYER1_ENABLE) != 0)
		layer_pos = 1;
	else if ((lcd_param->hw_update_layer & LCD_LAYER2_ENABLE) != 0)
		layer_pos = 2;
	else if ((lcd_param->hw_update_layer & LCD_LAYER3_ENABLE) != 0)
		layer_pos = 3;
	else
		MMI_ASSERT(0);

	vdo_get_active_buffer(&buf_ptr);

	if (lcd_param->rotate_value == MDI_VIDEO_LCD_ROTATE_270)
	{
		//{{方案一
#ifdef __SF_MP4_FAST_UPDATE_SCREEN__
		lcd_power_up();
		START_LCD_TRANSFER;
#else //__SF_MP4_FAST_UPDATE_SCREEN__
		//}}方案一
		
		//{{方案二
		gdi_layer_blt_previous(lcd_param->lcm_start_y, lcd_param->lcm_start_x, lcd_param->lcm_end_y, lcd_param->lcm_end_x);
		//}}方案二
#endif //__SF_MP4_FAST_UPDATE_SCREEN__
	}
	else
	{
		LCDDisplay_adrs(lcd_param, buf_ptr, layer_pos);
	}
}


#endif

SFBool SFSystem_IsTouchSupported(void)
{
#ifdef __MMI_TOUCH_SCREEN__
	return SFTrue;
#else
    return SFFalse;
#endif //__MMI_TOUCH_SCREEN__
}


static SFReason* s_get_imei_reason;
static char* s_imei_ptr;


static void SFSystem_GetIMEIRsp(void* imei)
{
    mmi_nw_get_imei_rsp_struct*pimei=(mmi_nw_get_imei_rsp_struct*)imei;
    //ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_IMEI_RSP);
    if(s_get_imei_reason)
    {
        SFReason* reason=s_get_imei_reason;
        s_get_imei_reason=SFNull;
    if(pimei->result)
    {
        memcpy(s_imei_ptr,pimei->imei,SF_IMEI_LENGTH);
            s_imei_ptr=SFNull;
            SFSystem_NotifyAllV(reason,SFReasonOK);
    }
    else
    {
            s_imei_ptr=SFNull;
            SFSystem_NotifyAllV(reason,SFReasonFail);
        }
    }
}

void SFSystem_GetIMEI(char* pIMEI,SFReason* pReason)
{
    MYQUEUE Message;
    if(!pReason)
        return;
    if(!pIMEI)
    {
        SFSystem_NotifyAllV(pReason,SFReasonBadParameter);
        return;
    }

    //ASSERT(pIMEI!=NULL);
    //ASSERT(pReason!=NULL);
    
    *pReason=SFReasonPending;
    s_get_imei_reason=pReason;
    s_imei_ptr=pIMEI;
       
    Message.oslMsgId = MSG_ID_MMI_NW_GET_IMEI_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr= NULL;
    Message.oslSrcId=SFCUST_APP_MOD;
    Message.oslDestId=MOD_L4C;
    OslMsgSendExtQueue(&Message);
    //SetProtocolEventHandler (SFSystem_GetIMEIRsp, MSG_ID_MMI_NW_GET_IMEI_RSP); 
}


static SFReason* s_get_imsi_reason;
static char* s_imsi_ptr;


static void SFSystem_GetIMSIRsp(void* imsi)
{
    if(s_get_imsi_reason)
    {
        SFReason* reason=s_get_imsi_reason;
    mmi_smu_get_imsi_rsp_struct*pimsi=(mmi_smu_get_imsi_rsp_struct*)imsi;
        s_get_imsi_reason=SFNull;
        //ClearProtocolEventHandler(MSG_ID_MMI_SMU_GET_IMSI_RSP);
    if(pimsi->result)
    {
        memcpy(s_imsi_ptr,pimsi->imsi,SF_IMSI_LENGTH);
            s_imsi_ptr=SFNull;
            SFSystem_NotifyAllV(reason,SFReasonOK);
    }
    else
    {
            s_imsi_ptr=SFNull;
            SFSystem_NotifyAllV(reason,SFReasonFail);
        }
    }
}

void SFSystem_GetIMSI(char* pIMSI,SFReason* pReason)
{
    MYQUEUE Message;

    if(!pReason)
        return;
    if(!pIMSI)
    {
        SFSystem_NotifyAllV(pReason,SFReasonBadParameter);
        return;
    }


    if(!SFSystem_HasSim())
    {
        SFSystem_NotifyAllV(pReason,SFReasonFail);
        return;
    }

    *pReason=SF_REASON_BUSY;
    s_get_imsi_reason=pReason;
    s_imsi_ptr=pIMSI;
    

    //SetProtocolEventHandler(SFSystem_GetIMSIRsp, MSG_ID_MMI_SMU_GET_IMSI_RSP);

    Message.oslSrcId = SFCUST_APP_MOD;
    Message.oslDestId = MOD_L4C;
    Message.oslMsgId = MSG_ID_MMI_SMU_GET_IMSI_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}




static int DirWritable(const UChar*path)
{
    FS_HANDLE hDir;
    hDir=FS_Open(path,FS_OPEN_DIR | FS_READ_ONLY);
    if(hDir>=0)
    {
        int disk_free_space;
        FS_DiskInfo disk_info;
        FS_Close(hDir);
        memset(&disk_info,0,sizeof(disk_info));
        
        FS_GetDiskInfo((PU16) path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
        
        disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;

        if(disk_free_space>=1024 && !disk_info.WriteProtect)// 2 
        {
            return 1;
        }
    }
    
    return 0;
}



#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
extern int SFSystem_GetAppPrivDir(SFModId modid,UChar* path);
extern int SFSystem_GetAppDir(SFModId modid,UChar* path);
extern int SFSystem_GetAppHomeDir(SFModId modid,UChar* path);
extern int SFSystem_GetAppConfDir(SFModId modid,UChar* path);
extern int SFSystem_GetAppPubDir(SFModId modid,UChar* path);
extern int SFSystem_GetAppTempDir(SFModId modid,UChar* path);
extern int SFSystem_GetDataDir(SFModId modid,UChar* path);
extern int SFAppPlatform_GetConfigDir(UChar* path_dir);
SFReason SFSystem_GetEModulePath(SFEModule* pEMod,UString* path);
#endif


SFInt SFSystem_GetFolder(SFInt idx,UChar* buf,SFInt len)
{
    int drv=0;
    
    switch(idx)
    {
    case SF_FOLDER_APPDATA:
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
        if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN))
        {
            SFSystem_GetAppDir(g_kernal.iActiveModule->iModId,buf);
            if(DirWritable(buf))
                break;
        }
#endif //__SF_APPLICATION_PLATFORM__ENABLE__
#ifdef SFCUST_FOLDER_APPDATA
        sf_strcpy(buf,SFCUST_FOLDER_APPDATA);
        if(DirWritable(buf))
            break;
#endif //SFCUST_FOLDER_APPDATA
#ifdef MMI_PUBLIC_DRV
        drv=MMI_PUBLIC_DRV;
#endif //MMI_PUBLIC_DRV
#ifdef MMI_CARD_DRV
        if(drv<=0)
            drv=MMI_CARD_DRV;
#endif //MMI_CARD_DRV
        if(drv<=0)
            buf[0]=0;
        else
        {
            sf_sprintf(buf,L"%c:\\",drv);
            if(!DirWritable(buf))
                buf[0]=0;
        }
        break;
    case SF_FOLDER_APPCONFIG:
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
        if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN) && SFSystem_GetAppConfDir(g_kernal.iActiveModule->iModId,buf)==0 && DirWritable(buf))
            break;
#endif //__SF_APPLICATION_PLATFORM__ENABLE__
#ifdef SFCUST_FOLDER_APPCONFIG
        sf_strcpy(buf,SFCUST_FOLDER_APPCONFIG);
        if(DirWritable(buf))
            break;
#endif //SFCUST_FOLDER_APPCONFIG
#ifdef MMI_PUBLIC_DRV
        drv=MMI_PUBLIC_DRV;
#endif //MMI_PUBLIC_DRV
#ifdef MMI_CARD_DRV
        if(drv<=0)
            drv=MMI_CARD_DRV;
#endif //MMI_CARD_DRV
        if(drv<=0)
            buf[0]=0;
        else
        {
            sf_sprintf(buf,L"%c:\\",drv);
            if(!DirWritable(buf))
                buf[0]=0;
        }
        break;
    case SF_FOLDER_APPPRIVATE:
#ifdef SFCUST_FOLDER_APPPRIVATE
        sf_strcpy(buf,SFCUST_FOLDER_APPPRIVATE);
        if(DirWritable(buf))
            break;
#endif //SFCUST_FOLDER_APPPRIVATE
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
        if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN))
        {
            SFAppPlatform_GetConfigDir(buf);
            if(DirWritable(buf))
                break;
        }
#endif //__SF_APPLICATION_PLATFORM__ENABLE__
#ifdef MMI_PRIVATE_DRV
        drv=MMI_PRIVATE_DRV;
#endif //MMI_PRIVATE_DRV
#ifdef MMI_PUBLIC_DRV
        if(drv<=0)
            drv=MMI_PUBLIC_DRV;
#endif //MMI_PUBLIC_DRV
#ifdef MMI_CARD_DRV
        if(drv<=0)
            drv=MMI_CARD_DRV;
#endif //MMI_CARD_DRV
        if(drv<=0)
            buf[0]=0;
        else
        {
            sf_sprintf(buf,L"%c:\\",drv);
            if(!DirWritable(buf))
            {
                buf[0]=0;
            }
        }
        break;
    case SF_FOLDER_SYSDATA:
        break;
    case SF_FOLDER_SYSCONFIG:
        break;
    case SF_FOLDER_SYSPRIVATE:
        break;
    default:
        return 0;
    }
    return sf_strlen(buf);
}



extern void sb_init(const char* url);
extern void sf_cancel_browser(void);


//ASCII/UTF-8 version
int sf_wap_start_browsera(kal_uint8 option, const char *url)
{
#ifdef SFAPI_WIN
    wap_browser_startup_req_struct *p = NULL;
    ilm_struct *ilm_ptr = NULL;

    p = (wap_browser_startup_req_struct*) construct_local_para(sizeof(wap_browser_startup_req_struct), TD_CTRL);

    p->type = option;

    memset(p->url, 0, sizeof(p->url));
    strcpy((char*)p->url,url);
    //UnicodeNToAnsii((S8 *)p->url, (S8 *) url, sizeof(p->url));

    ilm_ptr = allocate_ilm(SFCUST_APP_MOD);
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_STARTUP_REQ;
    ilm_ptr->peer_buff_ptr = NULL;

    ilm_ptr->src_mod_id  = SFCUST_APP_MOD;
    ilm_ptr->dest_mod_id = MOD_WAP;
    ilm_ptr->sap_id = WAP_MMI_SAP;
    msg_send_ext_queue(ilm_ptr);
#else
#ifdef WAP_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_browser_startup_req_struct *p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wap_is_ready())
    {
        wap_entry_no_ready_screen(WAP_SERVICE_BROWSER);
        return -1;
    }

    /* Disable key to prevent sending duplicated requests */
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    if (wap_browser_is_open())
    {
        if(option != WAP_BROWSER_GOTO_URL_BACKGROUND)
        {
        #ifdef JATAAYU_SUPPORT
            jbrowser_shutdown();
        #elif defined(OBIGO_SUPPORT)
            widget_MMI_shutdown_WAP_Widget_UI();
        #endif
        }
    }
#ifdef MMS_SUPPORT
    else if(wap_mms_is_open())
    {
    #ifdef JATAAYU_SUPPORT
    #elif defined(OBIGO_SUPPORT)
        widget_MMI_shutdown_WAP_Widget_UI();
    #endif
    }
#endif

    p = (wap_browser_startup_req_struct*) construct_local_para(sizeof(wap_browser_startup_req_struct), TD_CTRL);

    p->type = option;

    memset(p->url, 0, sizeof(p->url));
    strcpy((char*)p->url,url);
    //UnicodeNToAnsii((S8 *)p->url, (S8 *) url, sizeof(p->url));

    ilm_ptr = allocate_ilm(SFCUST_APP_MOD);
    ilm_ptr->local_para_ptr = (local_para_struct*) p;
    ilm_ptr->msg_id = MSG_ID_WAP_BROWSER_STARTUP_REQ;
    ilm_ptr->peer_buff_ptr = NULL;
   
    ilm_ptr->src_mod_id  = SFCUST_APP_MOD;
    ilm_ptr->dest_mod_id = MOD_WAP;
    ilm_ptr->sap_id = WAP_MMI_SAP;
    msg_send_ext_queue(ilm_ptr);
#endif //WAP_SUPPORT
#endif
    return 0;
}







#define SB_NWK_ACCOUNT_ID  0xFF



void sb_start_timer(int tm,void (*cb)(void))
{
    gui_start_timer(tm,cb);
}
void sb_cancel_timer(void (*cb)(void))
{
    gui_cancel_timer(cb);
}




void sb_end_helper(void)
{
    //soc_close_nwk_account(MOD_MMI);
    GoBackHistory();
}

typedef struct _sb_socket_handler_param
{
    int socket;
    int event_type; /* soc_event_enum */
    int result;
    int error_cause;  /* used only when EVENT is close/connect */
    int detail_cause; /* refer to ps_cause_enum if error_cause is */
} sb_socket_handler_param;

typedef void(*sb_socket_handler)(sb_socket_handler_param* param);


static sb_socket_handler sb_handler=NULL;


static void sb_socket_handler_work(void* msg)
{
    app_soc_notify_ind_struct * soc_ind = (app_soc_notify_ind_struct *)msg;
    sb_socket_handler_param param;
    if(!sb_handler)
        return;
    param.socket=soc_ind->socket_id;
    param.event_type=soc_ind->event_type;
    param.result=soc_ind->result;
    param.error_cause=soc_ind->error_cause;
    param.detail_cause=soc_ind->detail_cause;
    sb_handler(&param);
}

void sb_set_socket_handler(sb_socket_handler hdlr)
{
    sb_handler=hdlr;
    if(hdlr)
        SetProtocolEventHandler(sb_socket_handler_work, MSG_ID_APP_SOC_NOTIFY_IND);
    else
        ClearProtocolEventHandler(MSG_ID_APP_SOC_NOTIFY_IND);
}




static kal_uint8 sb_got_wap_nw_account=(SB_NWK_ACCOUNT_ID==0xFF)?0:1;
static kal_uint32 sb_wap_nw_account=SB_NWK_ACCOUNT_ID;


kal_uint32 sb_get_nw_account(kal_uint32* acc)
{
    kal_uint32 account_id=sb_wap_nw_account;
#ifdef __MMI_DUAL_SIM_MASTER__
{
        E_MTPNP_AD_SIMCARD_USABLE_SIDE state = MTPNP_AD_Get_UsableSide();
        switch (state)
        {
        case MTPNP_AD_DUALSIM_USABLE:
            {
                if (mmi_bootup_is_nw_registration_ok()) //booo1
                    account_id = always_ask_encode_data_account_id(account_id, 1, 0, 0);
                else if(mmi_bootup_is_sim2_nw_registration_ok())
                    account_id = always_ask_encode_data_account_id(account_id, 2, 0, 0);
            }
            break;

        case MTPNP_AD_SIMCARD1_USABLE:   
            account_id = always_ask_encode_data_account_id(account_id, 1, 0, 0);
            break;

        case MTPNP_AD_SIMCARD2_USABLE:
            account_id = always_ask_encode_data_account_id(account_id, 2, 0, 0);         
            break;

        default:
            return 0;
        }
    }
#endif

    *acc=account_id;
    return sb_got_wap_nw_account;
}
int sb_get_module(void)
{
    return SFCUST_APP_MOD;
}

static void sb_get_wap_rsp(void *MsgStruct)
{
#ifdef MMI_ON_HARDWARE_P
    kal_prompt_trace(SFCUST_TRACE_MOD,"sb_get_wap_rsp");
#endif //MMI_ON_HARDWARE_P
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
    sb_got_wap_nw_account=1;
	sb_wap_nw_account = ((wap_get_bra_prof_id_rsp_struct*) MsgStruct)->net_id;
}

extern void sb_start_http(void);

static void sb_get_wap_rsp_deamon(void)
{
    if(!sb_got_wap_nw_account)
    {
        gui_start_timer(50,sb_get_wap_rsp_deamon);
    }
    else
    {
#ifndef SFAPI_WIN
        sb_start_http();
#endif //!SFAPI_WIN
    }
}

void sb_get_default_wap_account(void)
{
#if SB_NWK_ACCOUNT_ID==0xFF
    MYQUEUE Message;

    sb_got_wap_nw_account=0;
    
    SetProtocolEventHandler(sb_get_wap_rsp, MSG_ID_WAP_GET_BRA_PROF_ID_RSP);
    Message.oslSrcId = SFCUST_APP_MOD;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_GET_BRA_PROF_ID_REQ;
    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
#else
    sb_got_wap_nw_account=1;
    sb_wap_nw_account=SB_NWK_ACCOUNT_ID;

#endif
    gui_start_timer(50,sb_get_wap_rsp_deamon);
}


extern void sb_init(const char* url);
extern void sb_get_default_wap_account(void);

static void sf_wap_wait(void)
{
#ifndef SFAPI_WIN
    EntryNewScreen(GetCurrScrnId()+100,NULL,sf_wap_wait,NULL);
    ShowCategory64Screen(STR_GLOBAL_PLEASE_WAIT,IMG_GLOBAL_PROGRESS,GetCurrGuiBuffer(GetCurrScrnId()));
    ClearAllKeyHandler();
    SetKeyHandler(&sf_cancel_browser,KEY_END,KEY_EVENT_DOWN);
#endif //SFAPI_WIN
}

int sf_wap_start_browser(const char* url)
{    
#ifdef WAP_SUPPORT
    if(!mmi_bootup_is_sim_valid()||(mmi_bootup_is_sim_removed()))
    {
        //show a message
        DisplayConfirm(
					        STR_GLOBAL_YES,
					        IMG_GLOBAL_YES,
					        NULL,
					        NULL,
					        get_string(STR_GLOBAL_NOT_AVAILABLE),
					        NULL,
					        ERROR_TONE);
        SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(&GoBackHistory,KEY_END,KEY_EVENT_DOWN);
        return -1;
    }
#ifndef SFAPI_WIN
    sb_init(url);

    sf_wap_wait();
    
    sb_get_default_wap_account();
#endif //!SFAPI_WIN
#endif //WAP_SUPPORT
    return 0;
}

SFUint32 SFApp_GetModule(void)
{
    return SFCUST_APP_MOD;
}

static uint8 s_na_type=0;


SFUint32 SFApp_GetNetworkAccount(int type)
{
    if(type==SF_NETWORK_ACCOUNT_AUTO)
        type=s_na_type;//cmwap
    switch(type)
    {
    case SF_NETWORK_ACCOUNT_WAP:
        return SFCUST_WAP_ACCOUNT;
    case SF_NETWORK_ACCOUNT_AUTO:
    case SF_NETWORK_ACCOUNT_SOCKET:
    default://cmnet
        return SFCUST_NET_ACCOUNT;
    }
}

SFRESULT SFSystem_SetNetworkAccount(int type)
{
    s_na_type=(uint8)type;
    g_kernal.iActiveModule->iNetworkAccountId=SFApp_GetNetworkAccount(type);
    return SFR_OK;
}

#ifdef __SF_APPLICATION_PLATFORM__ENABLE__

extern int SFAppPlatform_GetAppDataAccount(void);
SFUint32 SFApp_GetNetworkAccountSFAP(int type)
{
    return SFAppPlatform_GetAppDataAccount();
}

#endif //__SF_APPLICATION_PLATFORM__ENABLE__


#define SFSOCK_MAX_ADDRESS  4


typedef struct _SFSockHostent {
    short h_length;
    long h_addr_list[SFSOCK_MAX_ADDRESS];
} SFSockHostent;

typedef void (*SFSocketHostByNameCallbackProc)(void* param,SFSockHostent* ent);





typedef long SFSOCKET;


typedef void (*SFSocketEventCallbackProc)(SFSOCKET soc, long event, long error);

typedef struct _SFSockAddr
{
	unsigned short sa_family;/* address family */
	char  sa_data[14];
}SFSockAddr;
struct sf_in_addr {
	union {
		struct { unsigned char s_b1,s_b2,s_b3,s_b4; } S_un_b;
		struct { unsigned short s_w1,s_w2; } S_un_w;
		unsigned long S_addr;
	} S_un;
//#define s_addr  S_un.S_addr
//	/* can be used for most tcp & ip code */
//#define s_host  S_un.S_un_b.s_b2
//	/* host on imp */
//#define s_net   S_un.S_un_b.s_b1
//	/* network */
//#define s_imp   S_un.S_un_w.s_w2
//	/* imp */
//#define s_impno S_un.S_un_b.s_b4
//	/* imp # */
//#define s_lh    S_un.S_un_b.s_b3
//	/* logical host */
};
//#endif

typedef struct _SFSockAddr_in {
	short   sin_family;
	unsigned short sin_port;
	struct  sf_in_addr sin_addr;
	char    sin_zero[8];
} SFSockAddr_in;



#define SFSOCKET_ERROR	(-1)


/* Socket Event Flags */
#define SFSOCK_EVENT_READ       0x0001
#define SFSOCK_EVENT_WRITE      0x0002
//#define SOCK_EVENT_OOB        0x0004
//#define SOCK_EVENT_ACCEPT     0x0008
#define SFSOCK_EVENT_CONNECT    0x0010
#define SFSOCK_EVENT_CLOSE      0x0020
//#define SOCK_EVENT_DNS        0x0040
#define SFSOCK_EVENT_DESTROYED  0x0080
//#define SOCK_EVENT_LISTENING  0x0100
#define SFSOCK_EVENT_ERROR		0x0200

#define SFSOCK_EDEAD          -1

#define SFSOCK_EOK           0  /* No error                                   */
#define SFSOCK_EBADF         1  /* Invalid socket descriptor                  */
#define SFSOCK_EFAULT        2  /* Bad address specified                      */
#define SFSOCK_EINVAL        3  /* Invalid operation                          */
#define SFSOCK_EMFILE        4  /* No free socket descriptors                 */
#define SFSOCK_EWOULDBLOCK   5  /* The operation would block                  */
#define SFSOCK_EALREADY      6  /* A previous attempt at this operation is    */
/* still ongoing                              */
#define SFSOCK_EDESTADDRREQ  7  /* Socket is not bound                        */
#define SFSOCK_EMSGSIZE      8  /* The supplied buffer was too large / small  */
#define SFSOCK_ENOTSUPP      9  /* Flags not supported                        */
#define SFSOCK_EOPNOTSUPP    10  /* Operation not supported                    */
#define SFSOCK_EADDRINUSE    11  /* The address is already in use              */
#define SFSOCK_ENETDOWN      12  /* The network is unavailable                 */
#define SFSOCK_ECONNABORTED  13  /* An established connection was aborted,     */
/* possibly due to a data transmission        */
/* time-out or protocol error                 */
#define SFSOCK_ECONNRESET    14  /* Remote host has reset the  connection.     */
#define SFSOCK_ENOBUFS       15  /* No buffer space available                  */
#define SFSOCK_EISCONN       16  /* The socket is already connected            */
#define SFSOCK_ENOTCONN      17  /* The socket is not connected                */
#define SFSOCK_ESHUTDOWN     18  /* Socket has been shutdown                   */
#define SFSOCK_ETIMEDOUT     19  /* Connection timed out                       */
#define SFSOCK_ECONNREFUSED  20  /* Remote host has rejected the connection.   */
#define SFSOCK_EHOSTUNREACH  21  /* Remote host is unreachable                 */
#define SFSOCK_EUNEXPECTED   22  /* An unexpected error occurred               */








typedef struct _SFSocketImpl
{
    kal_int8 sock;
    kal_int8 last_error;
    kal_int16 evtmask;
    SFSocketEventCallbackProc callback;
    SFModule* module;
    void* param;
} SFSocketImpl;

#define SF_MAX_SOCKETS	6


static SFSocketImpl s_socket[SF_MAX_SOCKETS];
static SFInt16 s_socket_count=0;

static char s_bCloseNetworkAccount=SFFalse;

#define DELAYED_CLOSE_NW_ACCOUNT_TIME   (20*1000)
static void SFSocket_DoCloseNetworkAccount(void)
{
    s_bCloseNetworkAccount=SFFalse;
    soc_close_nwk_account((kal_uint16)SFApp_GetModule());
}

static void SFSocket_CloseNetworkAccount(void)
{
    //gui_start_timer()
    s_bCloseNetworkAccount=SFTrue;
    gui_start_timer(DELAYED_CLOSE_NW_ACCOUNT_TIME,&SFSocket_DoCloseNetworkAccount);
}

static void SFSocket_CancelCloseNetworkAccount(void)
{
    if(s_bCloseNetworkAccount)
    {
        gui_cancel_timer(&SFSocket_DoCloseNetworkAccount);
        s_bCloseNetworkAccount=SFFalse;
    }
}

#ifdef __SOCK_DEBUG
#define SFSOCKET_DEBUG(s)   kal_prompt_trace s
#else
#define SFSOCKET_DEBUG(s)
#endif


#define MAX_GETHOSTBYNAME   4
#define GETHOSTBYNAME_REQUEST_ID_BASE   0x12347
static struct _SFDNSCB
{
    SFSocketHostByNameCallbackProc iCallback;
    void* iParam;
    SFSockHostent* iHostent;
    SFModule* iModule;
} s_dns_cblist[MAX_GETHOSTBYNAME]={SFNull};

static void SFSocketDNS_Initialize(void)
{
    sf_memset(s_dns_cblist,0,sizeof(s_dns_cblist));
}

static void SFSocket_gethostbyname_work(void* msg)
{
    app_soc_get_host_by_name_ind_struct* dns_ind=(app_soc_get_host_by_name_ind_struct*)msg;
    int idx=dns_ind->request_id-GETHOSTBYNAME_REQUEST_ID_BASE;
    if(idx>=0 && idx<MAX_GETHOSTBYNAME)
    {
        //ClearProtocolEventHandler(MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND);
        struct _SFDNSCB cb=s_dns_cblist[idx];
        s_dns_cblist[idx].iHostent=SFNull;
        s_dns_cblist[idx].iCallback=SFNull;
        s_dns_cblist[idx].iParam=SFNull;
        if(dns_ind->result == KAL_TRUE)
        {
            //ok
            //kal_prompt_trace(SFCUST_TRACE_MOD,"dns ok %d.%d.%d.%d",dns_ind->entry[0].address[0],dns_ind->entry[0].address[1],dns_ind->entry[0].address[2],dns_ind->entry[0].address[3]);
            if(cb.iHostent)
            {
                cb.iHostent->h_length=1;
                //for 6226
                //s_dns_ent->h_addr_list[0]=(dns_ind->addr[0])
                //    | (dns_ind->addr[1]<<8) | (dns_ind->addr[2]<<16) | (dns_ind->addr[3]<<24);//(s_gethostbyname.addr[0])|(s_gethostbyname.addr[1]<<8)|(s_gethostbyname.addr[2]<<16)|(s_gethostbyname.addr[3]<<24);
                cb.iHostent->h_addr_list[0]=(dns_ind->entry[0].address[0])
                    | (dns_ind->entry[0].address[1]<<8) | (dns_ind->entry[0].address[2]<<16) | (dns_ind->entry[0].address[3]<<24);//(s_gethostbyname.addr[0])|(s_gethostbyname.addr[1]<<8)|(s_gethostbyname.addr[2]<<16)|(s_gethostbyname.addr[3]<<24);
            }
            else
            {
                SFDEBUG("dns ok but no s_dns_ent");
            }
        }
        else
        {
            //fail
            sf_memset(cb.iHostent,0,sizeof(SFSockHostent));
            cb.iHostent->h_length=-1;//fail
            //kal_prompt_trace(SFCUST_TRACE_MOD,"dns err %d %d %d",dns_ind->detail_cause,dns_ind->error_cause,dns_ind->request_id);
        }
        if(cb.iCallback)
        {
            cb.iCallback(cb.iParam,cb.iHostent);
        }
        if(s_socket_count<=0)
        {
            //try to close the socket
            SFSocket_CloseNetworkAccount();
        }
    }
}
    
static void SFSocket_canceldnsqueryForModule(SFModule* mod)
{
    int i;
    for(i=0;i<MAX_GETHOSTBYNAME;i++)
    {
        if(s_dns_cblist[i].iCallback
            && ( s_dns_cblist[i].iModule==mod || !mod))
        {
            soc_abort_dns_query(0,0,1,GETHOSTBYNAME_REQUEST_ID_BASE+i,0,0,0,0);
            s_dns_cblist[i].iCallback=SFNull;
            s_dns_cblist[i].iParam=SFNull;
            s_dns_cblist[i].iHostent=SFNull;
            s_dns_cblist[i].iModule=SFNull;
        }
    }
}

long SFSocket_canceldnsquery(SFSockHostent* ent,SFSocketHostByNameCallbackProc callbackProc,void*param)
{
    int i;
    for(i=0;i<MAX_GETHOSTBYNAME;i++)
    {
        if(s_dns_cblist[i].iModule==ACTIVE_MODULE
            && s_dns_cblist[i].iCallback==callbackProc
            && s_dns_cblist[i].iParam==param
            && s_dns_cblist[i].iHostent==ent)
        {
            soc_abort_dns_query(0,0,1,GETHOSTBYNAME_REQUEST_ID_BASE+i,0,0,0,0);
            s_dns_cblist[i].iCallback=SFNull;
            s_dns_cblist[i].iParam=SFNull;
            s_dns_cblist[i].iHostent=SFNull;
            s_dns_cblist[i].iModule=SFNull;
            return SFSOCK_EOK;
        }
    }
    return SFSOCK_EBADF;
}

long SFSocket_gethostbyname(const char* hostname,SFSockHostent* ent,SFSocketHostByNameCallbackProc callbackProc,void*param)
{
    kal_int8 r;
    int i;
    SFUint8 j = 0;
    sockaddr_struct s_gethostbyname;
    SFBool need_ask_dns=SFFalse;
#ifdef MMI_ON_HARDWARE_P
    kal_prompt_trace(SFCUST_TRACE_MOD,"SFSocket_gethostbyname %s",hostname);
#endif //MMI_ON_HARDWARE_P
    s_gethostbyname.addr_len=0;
    //check if the host is in a.b.c.d format
    for (i = 0; hostname[i]; i++)
    {
        if (hostname[i] < '0' || hostname[i] > '9')
        {
            if (hostname[i] != '.')
            {
                need_ask_dns = SFTrue;
                break;
            }
            else
            {
                ++j;
            }
        }
    }
    if(j!=3)
        need_ask_dns=1;

    if(need_ask_dns)
    {
        //find the slot
        int i;
        for(i=0;i<MAX_GETHOSTBYNAME;i++)
        {
            if(!s_dns_cblist[i].iCallback)
            {
                break;
            }
        }
        if(i>=MAX_GETHOSTBYNAME)
        {
            SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"SFSocket_gethostbyname: out of slot"));
            return SFSOCK_EFAULT;
        }
        if((r=soc_gethostbyname(KAL_FALSE,SFCUST_APP_MOD,GETHOSTBYNAME_REQUEST_ID_BASE+i,(const kal_char *) hostname,(kal_uint8 *)s_gethostbyname.addr,(kal_uint8 *)&s_gethostbyname.addr_len,0,g_kernal.iActiveModule->iNetworkAccountId))!=SOC_SUCCESS)
        {
            if(r==SOC_WOULDBLOCK)
            {
                SFSocket_CancelCloseNetworkAccount();
                //SetProtocolEventHandler((PsFuncPtr)SFSocket_gethostbyname_work,MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND);
                s_dns_cblist[i].iCallback=callbackProc;
                s_dns_cblist[i].iParam=param;
                s_dns_cblist[i].iHostent=ent;
                s_dns_cblist[i].iModule=ACTIVE_MODULE;
                return SFSOCK_EWOULDBLOCK;
            }
#ifdef MMI_ON_HARDWARE_P
            SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"SFSocket_gethostbyname %d",r));
#endif //!MMI_ON_HARDWARE_P
            return SFSOCK_EFAULT;
        }
    }
    else
    {
        //copy the dns info
        //ent->h_length=1;
        //ent->h_addr_list[0]=(s_gethostbyname.addr[0])|(s_gethostbyname.addr[1]<<8)|(s_gethostbyname.addr[2]<<16)|(s_gethostbyname.addr[3]<<24);
        //return SFSOCK_EOK;
        SFUint8 ipdigit;
        j=0;

        /* Native layer only support IP4 */
        for (i = 0; hostname[i]; i++)
        {
            ipdigit = 0;
            for (; hostname[i] >= '0' && hostname[i] <= '9';)
            {
                ipdigit = ipdigit * 10 + (SFUint8) hostname[i++] - '0';
            }

            if (j >= 4)
            {
                break;
            }
            s_gethostbyname.addr[j++] = ipdigit;
        }
        s_gethostbyname.addr_len=4;
    }
    ent->h_length=1;
    ent->h_addr_list[0]=(s_gethostbyname.addr[0])|(s_gethostbyname.addr[1]<<8)|(s_gethostbyname.addr[2]<<16)|(s_gethostbyname.addr[3]<<24);
    return SFSOCK_EOK;
}


static int _socket_get_from_handle(kal_int8 h)
{
    int i;
    if(h==-1)
        return SFSOCKET_ERROR;
    for(i=0;i<SF_MAX_SOCKETS;i++)
    {
        //SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"cmp [%d]=%d %d",i,s_socket[i].sock,h));
        if(s_socket[i].sock==h)
        {
            return i;
        }
    }
    return SFSOCKET_ERROR;
}

static int _socket_map_error(long v);

static int _socket_handler(void* msg)
{
    app_soc_notify_ind_struct * soc_ind = (app_soc_notify_ind_struct *)msg;
    SFSOCKET sock;//=_socket_get_from_handle(soc_ind->socket_id);
    SFSocketImpl* s;
    if(!s_socket_count)
        return 0;//pass
    sock=_socket_get_from_handle(soc_ind->socket_id);
    if(sock==SFSOCKET_ERROR || !s_socket[sock].callback || !s_socket[sock].module)
    {
        SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"other sock cb %d %d",sock,soc_ind->socket_id));
        return 0;//pass
    }
    s=&s_socket[sock];
    ENTER_MODULE(s->module);
    if(soc_ind->result)
	{
        s->last_error=SFSOCK_EOK;
        switch( soc_ind->event_type )
		{
		case SOC_CONNECT:
            if(s->evtmask&SFSOCK_EVENT_CONNECT)
            {
                SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"evt connect %d",sock));
                s->callback(sock,SFSOCK_EVENT_CONNECT,SFSOCK_EOK);
            }
            else if(s->evtmask&SFSOCK_EVENT_WRITE)
            {
                SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"evt write %d",sock));
                s->callback(sock,SFSOCK_EVENT_WRITE,SFSOCK_EOK);
            }
			break;
		case SOC_WRITE:
            if(s->evtmask&SFSOCK_EVENT_WRITE)
            {
                SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"evt write %d",sock));
                s->callback(sock,SFSOCK_EVENT_WRITE,SFSOCK_EOK);
            }
			break;
		case SOC_READ:
			{
				if(s->evtmask&SFSOCK_EVENT_READ)
				{
                    SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"evt read %d",sock));
                    s->callback(sock,SFSOCK_EVENT_READ,SFSOCK_EOK);
				}
	 		}
			break;
		case SOC_CLOSE:
            if(soc_ind->error_cause==SOC_CONNRESET)
            {
                //notify
                s->last_error=SFSOCK_ECONNRESET;
                SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"evt reset %d",sock));
                if(s->evtmask&SFSOCK_EVENT_CONNECT)
				{
                    
                    s->callback(sock,SFSOCK_EVENT_CONNECT,SFSOCK_ECONNRESET);
                    goto L_evt_return;
				}
                else if(s->evtmask&SFSOCK_EVENT_READ)
                {
                    s->callback(sock,SFSOCK_EVENT_READ,SFSOCK_ECONNRESET);
                    goto L_evt_return;
                }
                else if(s->evtmask&SFSOCK_EVENT_WRITE)
                {
                    s->callback(sock,SFSOCK_EVENT_WRITE,SFSOCK_ECONNRESET);
                    goto L_evt_return;
                } 
            }
            else
            {
                s->last_error=SFSOCK_EUNEXPECTED;
                SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"evt error %d",sock));
                if(s->evtmask&SFSOCK_EVENT_CONNECT)
				{
                    s->callback(sock,SFSOCK_EVENT_CONNECT,SFSOCK_EUNEXPECTED);
                    goto L_evt_return;
				}
                else if(s->evtmask&SFSOCK_EVENT_WRITE)
                {
                    s->callback(sock,SFSOCK_EVENT_WRITE,SFSOCK_EUNEXPECTED);
                    goto L_evt_return;
                }
                else if(s->evtmask&SFSOCK_EVENT_READ)
                {
                    s->callback(sock,SFSOCK_EVENT_READ,SFSOCK_EUNEXPECTED);
                    goto L_evt_return;
                }
            }
            //invalid the socket
            soc_close(s->sock);
            s->last_error=SFSOCK_EDEAD;
			break;

		default:
			break;
		}
    }
    else
    {
        //fail
        s->last_error=_socket_map_error(soc_ind->error_cause);
        SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"failed sock %d %d %d %d",soc_ind->socket_id,soc_ind->event_type,soc_ind->error_cause,soc_ind->detail_cause));
        //kal_prompt_trace(SFCUST_TRACE_MOD,"failed ?");
        switch( soc_ind->event_type )
		{
        case SOC_CLOSE:
            if(soc_ind->error_cause==SOC_CONNRESET)
            {
                if(s->evtmask&SFSOCK_EVENT_CONNECT)
    			{
                    
                    s->callback(sock,SFSOCK_EVENT_CONNECT,SFSOCK_ECONNRESET);
    			}
                else if(s->evtmask&SFSOCK_EVENT_READ)
                {
                    s->callback(sock,SFSOCK_EVENT_READ,SFSOCK_ECONNRESET);
                }
                else if(s->evtmask&SFSOCK_EVENT_WRITE)
                {
                    s->callback(sock,SFSOCK_EVENT_WRITE,SFSOCK_ECONNRESET);
                } 
                soc_close(s->sock);
                s->last_error=SFSOCK_EDEAD;
                goto L_evt_return;
            }
            //close the socket

        default:
            if(s->evtmask&SFSOCK_EVENT_CONNECT)
			{
                s->callback(sock,SFSOCK_EVENT_CONNECT,s->last_error);
                goto L_evt_return;
			}
            else if(s->evtmask&SFSOCK_EVENT_READ)
            {
                s->callback(sock,SFSOCK_EVENT_READ,s->last_error);
                goto L_evt_return;
            }
            else if(s->evtmask&SFSOCK_EVENT_WRITE)
            {
                s->callback(sock,SFSOCK_EVENT_WRITE,s->last_error);
                goto L_evt_return;
            }
            //invalid the socket
            soc_close(s->sock);
            s->last_error=SFSOCK_EDEAD;
            break;
        }
    }
L_evt_return:
    LEAVE_MODULE()

    POST_EVENT_PROCESS()
    return 1;
}

void SFApp_NetInitialize(void)
{
    
}

long SFSocket_close (SFSOCKET socket);

static void SFSystem_NetInitialize(void)
{
    int i;
    //set the handler
    SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"SFApp_NetInitialize"));
    
    //SetProtocolEventHandler(_socket_handler, MSG_ID_APP_SOC_NOTIFY_IND);
    for(i=0;i<SF_MAX_SOCKETS;i++)
    {
        s_socket[i].sock=SOC_ERROR;
        s_socket[i].callback=(void*)0;
        s_socket[i].evtmask=0;
        s_socket[i].last_error=0;
        s_socket[i].module=SFNull;
    }
}

static void SFSystem_NetFinalizeForModule(SFModule* aModule)
{
    int i;
    if(s_socket_count)
    {
    for(i=0;i<SF_MAX_SOCKETS;i++)
    {
        if(s_socket[i].module==aModule || !aModule)
        {
            s_socket[i].callback=NULL;
            SFSocket_close(i);
        }
    }
        if(s_socket_count<=0)
        {
            SFSocket_DoCloseNetworkAccount();
        }
}
}

static void SFSystem_NetFinalize(void)
{
    SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"SFSystem_NetFinalize"));
    
    SFSystem_NetFinalizeForModule(NULL);
}

void SFApp_NetFinalize(void)
{
    SFSystem_NetFinalizeForModule(g_kernal.iActiveModule);
}

static int _socket_map_error(long v)
{
    switch(v)
    {
    case SOC_SUCCESS:
		return SFSOCK_EOK;
	case SOC_INVALID_SOCKET:
		return SFSOCK_EBADF;
	case SOC_ERROR:
		return SFSOCK_EFAULT;
	case SOC_INVAL:
		return SFSOCK_EINVAL;
	case SOC_LIMIT_RESOURCE:
		return SFSOCK_EMFILE;
	case SOC_WOULDBLOCK:
		return SFSOCK_EWOULDBLOCK;
	case SOC_ALREADY:
		return SFSOCK_EALREADY;
	case SOC_NAMETOOLONG:
		return SFSOCK_EDESTADDRREQ;
	case SOC_MSGSIZE:
		return SFSOCK_EMSGSIZE;
	case SOC_OPNOTSUPP:
		return SFSOCK_EOPNOTSUPP;
	case SOC_CONNABORTED:
		return SFSOCK_ECONNABORTED;
	case SOC_CONNRESET:
		return SFSOCK_ECONNRESET;
	case SOC_NOTCONN:
		return SFSOCK_ENOTCONN;
	default:
		return SFSOCK_EUNEXPECTED;
    }
}

static long _socket_catch_error(SFSOCKET sock,long v)
{
    if(v>=0)
    {
        s_socket[sock].last_error=SFSOCK_EOK;
        SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"result %d %d %d",sock,s_socket[sock].sock,s_socket[sock].last_error));
        return v;
    }
    s_socket[sock].last_error=_socket_map_error(v);
    SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"result %d %d %d",sock,s_socket[sock].sock,s_socket[sock].last_error));
    return SFSOCKET_ERROR;
}


static sockaddr_struct s_saved_addr;

static long SFSocket_SetNBIO(kal_int8 sock)
{
	kal_uint8 val=1;
	SFDEBUG("nblock setting");

	if(soc_setsockopt(sock,SOC_NBIO,&val,sizeof(val))<0)
	{
        return 0;
	}

	val = SOC_READ|SOC_WRITE|SOC_CONNECT|SOC_CLOSE;
	if(soc_setsockopt(sock,SOC_ASYNC,&val,sizeof(val))<0)
	{
        return 0;
	}
	SFDEBUG("nblock set");
    return 1;
}


SFSOCKET SFSocket_create(int af, int type, int protocol, SFSocketEventCallbackProc callbackProc, long *error_p)
{
    long soc;
    kal_int8 sock;
    kal_uint32 account_id;
    if(!g_kernal.iActiveModule || !(AM_HAS_RIGHT(SFMOD_RIGHTS_NETWORK)))
    {
        if(error_p)
            *error_p=SFSOCK_ENETDOWN;
        SFDEBUG("sfsock fail 1");
        return SFSOCKET_ERROR;
    }
        

    for(soc=0;soc<SF_MAX_SOCKETS;soc++)
    {
        if(s_socket[soc].sock==SOC_ERROR)
        {
            break;
        }
    }
    if(soc>=SF_MAX_SOCKETS)
    {
        //failed
        if(error_p)
            *error_p=SFSOCK_EMFILE;
        SFDEBUG("sfsock fail 1");
        return SFSOCKET_ERROR;
    }
    account_id=g_kernal.iActiveModule->iNetworkAccountId;
#ifdef __MMI_DUAL_SIM_MASTER__
    {
        E_MTPNP_AD_SIMCARD_USABLE_SIDE state = MTPNP_AD_Get_UsableSide();
        switch (state)
        {
        case MTPNP_AD_DUALSIM_USABLE:
            {
                if (mmi_bootup_is_nw_registration_ok()) //booo1
                    account_id = always_ask_encode_data_account_id(account_id, ALWAYS_ASK_SIM_INFO_SIM1, 0, 0);
                else if(mmi_bootup_is_sim2_nw_registration_ok())
                    account_id = always_ask_encode_data_account_id(account_id, ALWAYS_ASK_SIM_INFO_SIM2, 0, 0);
            }
            break;

        case MTPNP_AD_SIMCARD1_USABLE:   
            account_id = always_ask_encode_data_account_id(account_id, ALWAYS_ASK_SIM_INFO_SIM1, 0, 0);
            break;

        case MTPNP_AD_SIMCARD2_USABLE:
            account_id = always_ask_encode_data_account_id(account_id, ALWAYS_ASK_SIM_INFO_SIM2, 0, 0);		 
            break;

        default:
            return SFSOCKET_ERROR;
        }
    }
#endif

    sock=soc_create(af,type,protocol,SFApp_GetModule(),(kal_uint32)account_id);
    if(sock<0)
    {
        if(error_p)
            *error_p=(unsigned short int)SFSOCK_EMFILE;

		SFDEBUG("sfsock fail 0");

		return SFSOCKET_ERROR;
    }
    if(!SFSocket_SetNBIO(sock))
    {
        soc_close(sock);
        if(error_p)
            *error_p=(unsigned short int)SFSOCK_EMFILE;
        SFDEBUG("sfsock fail 2");

		return SFSOCKET_ERROR;
    }

    SFSocket_CancelCloseNetworkAccount();

    ++s_socket_count;
    s_socket[soc].module=g_kernal.iActiveModule;
    s_socket[soc].sock=sock;
    s_socket[soc].callback=callbackProc;
    s_socket[soc].evtmask=0;
    s_socket[soc].last_error=SFSOCK_EOK;
    s_socket[soc].param=NULL;
    
    SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"soc create %d %d",soc,sock));
    
    if(error_p)
        *error_p=(unsigned short int)SFSOCK_EOK;

    return soc;
}

long sb_connect(long sock,void*addr,int szaddr,int port)
{
    sockaddr_struct a;
    memset(&a,0,sizeof(a));
    memcpy(a.addr,addr,szaddr);
    a.addr_len=szaddr;
    a.port=port;
    return soc_connect(sock,&a);
}

long SFSocket_aselect (SFSOCKET socket, long eventMask)
{
    if(socket<0 || socket>=SF_MAX_SOCKETS || s_socket[socket].last_error==SFSOCK_EDEAD)
        return SFSOCKET_ERROR;
    s_socket[socket].evtmask=(kal_uint16)eventMask;
    return 0;
}

long SFSocket_close (SFSOCKET socket)
{
    SFSocketEventCallbackProc cb;
    if(socket<0 || socket>=SF_MAX_SOCKETS)
        return SFSOCKET_ERROR;

    SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"SFSocket_close %d %d",socket,s_socket[socket].sock));
    
    cb=s_socket[socket].callback;
    if(s_socket[socket].last_error!=SFSOCK_EDEAD && s_socket[socket].sock!=SOC_ERROR)
        soc_close(s_socket[socket].sock);
    s_socket[socket].sock=SOC_ERROR;
    s_socket[socket].callback=(void*)0;
	s_socket[socket].evtmask=0;
    s_socket[socket].last_error=0;
    --s_socket_count;
    if(cb)
        cb(socket,SFSOCK_EVENT_DESTROYED,0);
    if(s_socket_count<=0)
    {
        s_socket_count=0;
        SFSocket_CloseNetworkAccount();
    }
    return 0;
}

static void sockaddr_from(sockaddr_struct* addr,const SFSockAddr *name_p)
{
    int port=((SFSockAddr_in*)name_p)->sin_port;
    addr->addr_len=4;
	addr->port=((port&0xff)<<8)|((port>>8)&0xff);
	addr->addr[0]=((SFSockAddr_in*)name_p)->sin_addr.S_un.S_un_b.s_b1;
	addr->addr[1]=((SFSockAddr_in*)name_p)->sin_addr.S_un.S_un_b.s_b2;
	addr->addr[2]=((SFSockAddr_in*)name_p)->sin_addr.S_un.S_un_b.s_b3;
	addr->addr[3]=((SFSockAddr_in*)name_p)->sin_addr.S_un.S_un_b.s_b4;
}

long SFSocket_connect (SFSOCKET socket, const SFSockAddr *name_p, long nameLen)
{
    if(socket<0 || socket>=SF_MAX_SOCKETS || s_socket[socket].last_error==SFSOCK_EDEAD || nameLen!=sizeof(SFSockAddr_in))
        return SFSOCKET_ERROR;

    SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"SFSocket_connect %d",socket));
    
	//sockaddr_struct addr;
	sockaddr_from(&s_saved_addr,name_p);

    return _socket_catch_error(socket,soc_connect(s_socket[socket].sock,(sockaddr_struct*)&s_saved_addr));
}

long SFSocket_geterror (SFSOCKET socket)
{
    if(socket<0 || socket>=SF_MAX_SOCKETS)
        return SFSOCK_EBADF;
    if(s_socket[socket].last_error==SFSOCK_EDEAD)
        return SFSOCK_EUNEXPECTED;
    return s_socket[socket].last_error;
}

long SFSocket_bind(SFSOCKET socket,const SFSockAddr *name_p, long nameLen)
{
    sockaddr_struct addr;
    
    if(socket<0 || socket>=SF_MAX_SOCKETS || s_socket[socket].last_error==SFSOCK_EDEAD || nameLen!=sizeof(SFSockAddr_in))
        return SFSOCKET_ERROR;

    SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"SFSocket_Bind %d",socket));

    sockaddr_from(&addr,name_p);
    
    return _socket_catch_error(socket,soc_bind(s_socket[socket].sock,&addr));
}

//listen 
//accept
//

long SFSocket_recv (SFSOCKET socket, void *buf_p, long len, long flags)
{
    if(socket<0 || socket>=SF_MAX_SOCKETS || s_socket[socket].last_error==SFSOCK_EDEAD)
        return SFSOCKET_ERROR;

    SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"SFSocket_recv %d %d",socket,len));
    
    return _socket_catch_error(socket,soc_recv(s_socket[socket].sock,(kal_uint8*)buf_p,len,(kal_uint8)flags));
}

long SFSocket_send (SFSOCKET socket, const void *buf_p, long len, long flags)
{
    if(socket<0 || socket>=SF_MAX_SOCKETS || s_socket[socket].last_error==SFSOCK_EDEAD)
        return SFSOCKET_ERROR;

    SFSOCKET_DEBUG((SFCUST_TRACE_MOD,"SFSocket_send %d %d",socket,len));
    
    return _socket_catch_error(socket,soc_send(s_socket[socket].sock,(kal_uint8*)buf_p,len,(kal_uint8)flags));
}

void SFSocket_setParam(SFSOCKET socket,void*param)
{
    if(socket<0 || socket>=SF_MAX_SOCKETS)
        return;
    s_socket[socket].param=param;
}

void* SFSocket_getParam(SFSOCKET socket)
{
    if(socket<0 || socket>=SF_MAX_SOCKETS)
        return NULL;
    return s_socket[socket].param;
}


extern int SFSystem_HandleSMSInternal(SFInt aIdxCallback,SFSMSMsg* msg);

//mmi_frm_sms_set_protocol_event_handler
static int SFSystem_HandleSMS(mmi_sms_deliver_msg_ind_struct *d)
{
    SFSMSMsg msg;
    smsal_concat_struct concat_info;
    if(s_sys_callbacks_cnt[SFSYS_CALLBACK_SMS_MSG]>0)
    {
    memcpy(&concat_info,&d->concat_info,sizeof(smsal_concat_struct));
    msg.iDestPort=d->dest_port;
    msg.iSrcPort=d->src_port;
    msg.iDCS=d->dcs;
    msg.iMTI=d->mti;
    msg.iMessageLen=d->no_msg_data;
    if(msg.iMessageLen>SFSMS_MAX_MSG_LEN)
    {
        SFDEBUG("SMS tuncated");
        msg.iMessageLen=SFSMS_MAX_MSG_LEN;
    }
    msg.iTotalSegments=concat_info.total_seg;
    msg.iSegment=concat_info.seg;
    msg.iNumberLen=d->oa_number.length;
    memset(msg.iNumber,0,sizeof(msg.iNumber));
    memcpy(msg.iNumber,d->oa_number.number,msg.iNumberLen);
    memset(msg.iSCTS,0,sizeof(msg.iSCTS));
    memcpy(msg.iSCTS,d->scts,7);
    memcpy(msg.iMessageData,d->msg_data,msg.iMessageLen);

#ifdef MMI_ON_HARDWARE_P
    kal_prompt_trace(SFCUST_TRACE_MOD,"on sms %s %d %s",msg.iNumber,msg.iMessageLen,msg.iMessageData);
#endif //MMI_ON_HARDWARE_P

    return SFSystem_HandleSMSInternal(SFSYS_CALLBACK_SMS_MSG,&msg);
}
    else
    {
        return 0;
    }
}

static int SFSystem_HandleSMSData(mmi_sms_app_data_ind_struct *d)
{
    SFSMSMsg msg;
    smsal_concat_struct concat_info;
    if(s_sys_callbacks_cnt[SFSYS_CALLBACK_SMS_DATA]>0)
    {
    memcpy(&concat_info,&d->concat_info,sizeof(smsal_concat_struct));
    msg.iDestPort=d->dest_port;
    msg.iSrcPort=d->src_port;
    msg.iDCS=d->dcs;
    msg.iMTI=d->mti;
    msg.iMessageLen=d->message_len;
    if(msg.iMessageLen>SFSMS_MAX_MSG_LEN)
    {
        SFDEBUG("SMS tuncated");
        msg.iMessageLen=SFSMS_MAX_MSG_LEN;
    }
    msg.iTotalSegments=concat_info.total_seg;
    msg.iSegment=concat_info.seg;
    msg.iNumberLen=d->oa.length;
    memset(msg.iNumber,0,sizeof(msg.iNumber));
    memcpy(msg.iNumber,d->oa.number,msg.iNumberLen);
    memset(msg.iSCTS,0,sizeof(msg.iSCTS));
    memcpy(msg.iSCTS,d->scts,7);

    
    memcpy(msg.iMessageData,d->msg_data,msg.iMessageLen);
    if(msg.iMessageLen<SFSMS_MAX_MSG_LEN)
        msg.iMessageData[msg.iMessageLen]=0;

#ifdef MMI_ON_HARDWARE_P
    kal_prompt_trace(SFCUST_TRACE_MOD,"on sms data %s %d %s",msg.iNumber,msg.iMessageLen,msg.iMessageData);
#endif //MMI_ON_HARDWARE_P

    return SFSystem_HandleSMSInternal(SFSYS_CALLBACK_SMS_DATA,&msg);
    }
    else
    {
        return 0;
    }
}


#if defined(WAP_SUPPORT)
static int SFSystem_HandleWapProfileContent(wap_get_prof_content_rsp_struct* profile);
static int SFSystem_HandleWapProfile(wap_get_bra_prof_id_rsp_struct* profile);
#endif //defined(WAP_SUPPORT)
static void CSFNetworkManager_OnGetAccountInfo(void* ptr);

int SFSystem_HandleTaskEvent(U16 eventID, void *MsgStruct, int mod_src, void *peerBuf)
{
    int r;
    SFSystem_Initialize();
    switch(eventID)
    {
    case MSG_ID_MMI_SMU_GET_IMSI_RSP:
        SFSystem_GetIMSIRsp(MsgStruct);
        r=0;
        break;
    case MSG_ID_MMI_NW_GET_IMEI_RSP:
        SFSystem_GetIMEIRsp(MsgStruct);
        r=0;
        break;
    case MSG_ID_APP_SOC_NOTIFY_IND:
        r=_socket_handler(MsgStruct);
        break;
    case MSG_ID_MMI_SMS_APP_DATA_IND:
        r=SFSystem_HandleSMSData((mmi_sms_app_data_ind_struct*)MsgStruct);
        break;
    case MSG_ID_MMI_SMS_DELIVER_MSG_IND:
        r=SFSystem_HandleSMS((mmi_sms_deliver_msg_ind_struct*)MsgStruct);
        break;
    case MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND:
        SFSocket_gethostbyname_work(MsgStruct);
        r= 0;//pass
        break;
    case MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP:
        CSFNetworkManager_OnGetAccountInfo(MsgStruct);
        r= 0;//pass
        break;
#if defined(WAP_SUPPORT)
    case MSG_ID_WAP_GET_BRA_PROF_ID_RSP:
        r=SFSystem_HandleWapProfile((wap_get_bra_prof_id_rsp_struct *)MsgStruct);
        break;
    case MSG_ID_WAP_GET_PROF_CONTENT_RSP:
        r=SFSystem_HandleWapProfileContent((wap_get_prof_content_rsp_struct *)MsgStruct);
        break;
#endif //defined(WAP_SUPPORT)
    default:
        return 0;
    }
    POST_EVENT_PROCESS()
    return r;
}


#ifdef __SF_MTK_APPLICATION_STOCK__ENABLE__
extern ISFApplication* SFStock_Create(void);


void SFStockEntry(void)
{
#ifdef __J2ME__
	if(jvm_is_pause_mode())
	{
		mmi_java_display_is_busy_for_pause_mode();
		return;
	}
#endif
    FS_SetCurrentDir(L"E:\\");
    
    SFSystem_LaunchModule(SFMODID_APP_STOCK,SFNull,SF_LAUNCH_NORMAL);
}





#endif //__SF_MTK_APPLICATION_STOCK__ENABLE__

extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

static const UChar*const s_LanguageStr[]=
{
    L"UNKNOWN",
    L"CHS",
    L"CHT",
    L"EN"
};
static const char*const s_LanguageStrA[]=
{
    "UNKNOWN",
    "CHS",
    "CHT",
    "EN"
};

const UChar* SFSystem_GetLanguageName(int idx)
{
    if(idx<0 || idx>3)
        idx=0;
    return s_LanguageStr[idx];
}

const char* SFSystem_GetLanguageNameA(int idx)
{
    if(idx<0 || idx>3)
        idx=0;
    return s_LanguageStrA[idx];
}

int SFSystem_GetLanguageId(void)
{
#ifdef SFAPI_WIN
    extern int MtkHal_GetLanguageId(void);
    return MtkHal_GetLanguageId();
#else
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE) == 0)
    {
        return 1;
    }

    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) == 0)
    {
        return 2;
    }

    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH) == 0)
    {
        return 3;
    }
    return 0;
#endif
}




static void* sf_dummy_vf(void*p)
{
    return p;
}

static int sf_dummy_vf_q(SFUint32 l,SFUint32 r,void** p)
{
    return SFReasonNotSupported;
}


struct _sf_vfs_file_class_i
{
    DECLARE_INTERFACE_BASIC_FUNCS(sf_vfs_file_i)

    int (*vfs_file_close)(sf_vfs_file_i* fd);
    int (*vfs_file_read)(sf_vfs_file_i* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz);
    int (*vfs_file_write)(sf_vfs_file_i* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz);
    int (*vfs_file_seek)(sf_vfs_file_i* fd,sf_vfs_offset_t offset,int orig);
    int (*vfs_file_commit)(sf_vfs_file_i* fd);
    int (*vfs_file_tell)(sf_vfs_file_i* fd,sf_vfs_offset_t* poffset);
    int (*vfs_file_chsize)(sf_vfs_file_i* fd,sf_vfs_size_t sz);
    int (*vfs_file_eof)(sf_vfs_file_i* fd);
    int (*vfs_file_trunc)(sf_vfs_file_i* fd);
    int (*vfs_file_getlasterror)(sf_vfs_file_i* fd);
    int (*vfs_file_filelength)(sf_vfs_file_i* fd,sf_vfs_size_t* psize);
} ;

struct _sf_vfs_class_i
{
    DECLARE_INTERFACE_BASIC_FUNCS(sf_vfs_i)

    int (*vfs_open_file)(sf_vfs_i* fs,sf_vfs_string_t file,int mode,sf_vfs_file**pfile);
    int (*vfs_getlasterror)(sf_vfs_i* fs);
    int (*vfs_rename)(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_string_t newname);
    int (*vfs_getattr)(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_attr_t* pattr);
    int (*vfs_setattr)(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_attr_t attr);
    int (*vfs_getaccess)(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_access_t* paccess);
    int (*vfs_setaccess)(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_access_t access);
    int (*vfs_remove)(sf_vfs_i* fs,sf_vfs_string_t name);
    int (*vfs_getcwd)(sf_vfs_i* fs,sf_vfs_char_t* buf,SFSize_T maxlen);
    int (*vfs_chcwd)(sf_vfs_i* fs,sf_vfs_string_t path);
    int (*vfs_mkdir)(sf_vfs_i* fs,sf_vfs_string_t name);
    int (*vfs_rmdir)(sf_vfs_i* fs,sf_vfs_string_t name);
    int (*vfs_exist)(sf_vfs_i* fs,sf_vfs_string_t name,int mode);
    int (*vfs_getfileinfo)(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_fileinfo* pinfo);
    int (*vfs_enum_first)(sf_vfs_i* fs,sf_vfs_string_t path,int mode,sf_vfs_fileinfo* pinfo);
    int (*vfs_enum_next)(sf_vfs_i* fs,sf_vfs_fileinfo* pinfo);
    int (*vfs_enum_close)(sf_vfs_i* fs);
    int (*vfs_getfreespace)(sf_vfs_i* fs,sf_vfs_string_t path,sf_vfs_size_t *psize);
} ;

struct _sf_vfs_file_i
{
    const sf_vfs_file_class* __vftab;
    SFUint8 iFileNodeIdx;
    int nRefCount;
    int iLastError;
    FS_HANDLE hFile;
    int iMode;
    sf_vfs_i* vfs;
};




#define SF_VFS_MAX_OPEN_FILES   8

static sf_vfs_file_i s_vfs_files[SF_VFS_MAX_OPEN_FILES];


static sf_vfs_file_i* sf_vfs_alloc_file_node(sf_vfs_i* fs)
{
    int i;
    for(i=0;i<SF_VFS_MAX_OPEN_FILES;i++)
    {
        if(s_vfs_files[i].vfs==NULL)
        {
            s_vfs_files[i].vfs=fs;
            s_vfs_files[i].iFileNodeIdx=(SFUint8)i;
            s_vfs_files[i].hFile=-1;
#ifdef SF_VFS_DEBUG
            sf_dbgprintf(L"sf_vfs_alloc_file_node %d",s_vfs_files[i].iFileNodeIdx);
#endif

            return &s_vfs_files[i];
        }
    }
    SFDEBUG("sf_vfs_alloc_file_node out of nodes");
    return SFNull;
}

static int sf_vfs_i_remap_error(int err)
{
    switch(err)
    {
    case FS_NO_ERROR:
        return 0;
    case FS_DRIVE_NOT_FOUND:
    case FS_WRONG_MEDIA:
    case FS_FILE_NOT_FOUND:
    case FS_PATH_NOT_FOUND:
        return SFReasonNotFound;
    case FS_TOO_MANY_FILES:
        return SFReasonOutOfResource;
    case FS_PARAM_ERROR:
    case FS_INVALID_FILENAME:
    case FS_INVALID_FILE_POS:
    case FS_LONG_FILE_POS:
        return SFReasonBadParameter;
    case FS_INVALID_FILE_HANDLE:
        return SFReasonInternalError;
    case FS_ACCESS_DENIED:
    case FS_WRITE_PROTECTION:
    case FS_READ_ONLY_ERROR:
        return SFReasonAccessDenied;
    case FS_ROOT_DIR_FULL:
    case FS_DISK_FULL:
    case FS_APP_QUOTA_FULL:
        return SFReasonFull;
    case FS_BAD_SECTOR:
    case FS_CORRUPTED_PARTITION_TABLE:
    case FS_DATA_ERROR:
    case FS_SECTOR_NOT_FOUND:
    case FS_DEVICE_RESOURCE_ERROR:
    case FS_BAD_DIR_ENTRY:
        return SFReasonCorrupted;
    case FS_MEDIA_CHANGED:
        return SFReasonDeviceChanged;
    case FS_DRIVE_NOT_READY:
        return SFReasonNotReady;
    case FS_QUOTA_OVER_DISK_SPACE:
        return SFReasonOSError;
    case FS_DEVICE_BUSY:
        return SFReasonDeviceBusy;
    case FS_FILE_EXISTS:
        return SFReasonExists;
    default:
        return SFReasonError;
    }
}


static int sf_vfs_file_i_close(sf_vfs_file_i* fd);
static int sf_vfs_file_i_read(sf_vfs_file_i* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz);
static int sf_vfs_file_i_write(sf_vfs_file_i* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz);
static int sf_vfs_file_i_seek(sf_vfs_file_i* fd,sf_vfs_offset_t offset,int orig);
static int sf_vfs_file_i_commit(sf_vfs_file_i* fd);
static int sf_vfs_file_i_tell(sf_vfs_file_i* fd,sf_vfs_offset_t* poffset);
static int sf_vfs_file_i_chsize(sf_vfs_file_i* fd,sf_vfs_size_t sz);
static int sf_vfs_file_i_eof(sf_vfs_file_i* fd);
static int sf_vfs_file_i_trunc(sf_vfs_file_i* fd);
static int sf_vfs_file_i_getlasterror(sf_vfs_file_i* fd);
static int sf_vfs_file_i_filelength(sf_vfs_file_i* fd,sf_vfs_size_t* psize);

static int sf_vfs_i_release(sf_vfs_i* fs);
static int sf_vfs_i_open_file(sf_vfs_i* fs,sf_vfs_string_t file,int mode,sf_vfs_file**pfile);
static int sf_vfs_i_getlasterror(sf_vfs_i* fs);
static int sf_vfs_i_rename(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_string_t newname);
static int sf_vfs_i_getattr(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_attr_t* pattr);
static int sf_vfs_i_setattr(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_attr_t attr);
static int sf_vfs_i_getaccess(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_access_t* paccess);
static int sf_vfs_i_setaccess(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_access_t access);
static int sf_vfs_i_remove(sf_vfs_i* fs,sf_vfs_string_t name);
static int sf_vfs_i_getcwd(sf_vfs_i* fs,sf_vfs_char_t* buf,SFSize_T maxlen);
static int sf_vfs_i_chcwd(sf_vfs_i* fs,sf_vfs_string_t path);
static int sf_vfs_i_mkdir(sf_vfs_i* fs,sf_vfs_string_t name);
static int sf_vfs_i_rmdir(sf_vfs_i* fs,sf_vfs_string_t name);
static int sf_vfs_i_exists(sf_vfs_i* fs,sf_vfs_string_t name,int mode);
static int sf_vfs_i_getfileinfo(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_fileinfo* pinfo);
static int sf_vfs_i_enum_first(sf_vfs_i* fs,sf_vfs_string_t path,int mode,sf_vfs_fileinfo* pinfo);
static int sf_vfs_i_enum_next(sf_vfs_i* fs,sf_vfs_fileinfo* pinfo);
static int sf_vfs_i_enum_close(sf_vfs_i* fs);
static int sf_vfs_i_getfreespace(sf_vfs_i* fs,sf_vfs_string_t path,sf_vfs_size_t *psize);

static int sf_vfs_file_i_catch_error(sf_vfs_file_i* file,int err)
{
    file->iLastError=sf_vfs_i_remap_error(err);
#ifdef SF_VFS_DEBUG
        if(file->iLastError!=0)
        {
            sf_dbgprintf(L"sf_vfs_file_i_catch_error %d",err);
        }
#endif

    return file->iLastError;
}

static int sf_vfs_i_catch_error(sf_vfs_i* fs,int err)
{
    fs->iLastError=sf_vfs_i_remap_error(err);
#ifdef SF_VFS_DEBUG
    if(fs->iLastError!=0)
    {
        sf_dbgprintf(L"sf_vfs_i_catch_error %d",err);
    }
#endif
    return fs->iLastError;
}

static void sf_vfs_free_file_node(sf_vfs_file_i* file)
{
    if(!file)
        return;
#ifdef SF_VFS_DEBUG
    sf_dbgprintf(L"sf_vfs_free_file_node %d",file->iFileNodeIdx);
#endif
    
    s_vfs_files[file->iFileNodeIdx].vfs=SFNull;
    s_vfs_files[file->iFileNodeIdx].iLastError=0;
    s_vfs_files[file->iFileNodeIdx].hFile=-1;
}



UChar g_sf_local_drv=0xFF;//SFCUST_VFS_LOCAL_DRV;
UChar g_sf_card_drv=0xFF;//SFCUST_VFS_CARD_DRV;
UChar g_sf_sys_drv=0xFF;


void sf_vfs_prepare_drivers(void)
{
    int drv;
    if(g_sf_local_drv!=0xFF)
        return;
#ifdef MMI_PUBLIC_DRV

    drv=MMI_PUBLIC_DRV;

    if(drv>0)
    {
        g_sf_local_drv=(UChar)drv;
    }
    else
    {
        g_sf_local_drv=0;
    }
#else //MMI_PUBLIC_DRV
    g_sf_local_drv=0;
#endif //MMI_PUBLIC_DRV
    
#ifdef MMI_CARD_DRV
    drv=MMI_CARD_DRV;
    if(drv>0)
    {
        g_sf_card_drv=(UChar)drv;
    }
    else
    {
        g_sf_card_drv=0;
    }
#else //MMI_CARD_DRV
    g_sf_card_drv=0;
#endif //MMI_CARD_DRV

#ifdef MMI_PRIVATE_DRV
    drv=MMI_PRIVATE_DRV;
#else
    drv=0;
#endif
    if(drv==0)
    {
#ifdef MMI_SYSTEM_DRV
        drv=MMI_SYSTEM_DRV;
        if(drv>0)
        {
            g_sf_sys_drv=(UChar)drv;
        }
        else
        {
            g_sf_sys_drv=0;
        }
#else
        g_sf_sys_drv=0;
#endif
    }
    else
    {
        g_sf_sys_drv=(UChar)drv;
    }
    if(g_sf_card_drv && g_sf_card_drv==g_sf_local_drv)
    {
        //no local storage
        g_sf_local_drv=0;
    }
}

void sf_vfs_refresh_drivers(void)
{
    g_sf_local_drv=0xFF;
    g_sf_card_drv=0xFF;
    g_sf_sys_drv=0xFF;

    sf_vfs_prepare_drivers();
}


static char s_sf_vfs_inited=0;

#define SF_VFS_MAX_NODES   4

static sf_vfs_i s_vfs_nodes[SF_VFS_MAX_NODES];

static sf_vfs_i* sf_vfs_alloc_node(void)
{
    int i;
    for(i=0;i<SF_VFS_MAX_NODES;i++)
    {
        if(s_vfs_nodes[i].iModule==SFNull)
        {
            s_vfs_nodes[i].iVFSNodeIdx=i;
            s_vfs_nodes[i].iModule=g_kernal.iActiveModule;
            return &s_vfs_nodes[i];
        }
    }
    return SFNull;
}

static void sf_vfs_free_node(sf_vfs_i* node)
{
    SFDEBUG("free vfs");
    s_vfs_nodes[node->iVFSNodeIdx].iModule=SFNull;
}

static void sf_vfs_i_addref(sf_vfs_i* fs);

static SFReason sf_vfs_i_query_interface(sf_vfs_i* fs,SFUint32 l,SFUint32 h,void**p)
{
    return SFReasonNotSupported;
}

static sf_vfs* sf_vfs_new(void)
{
    static const sf_vfs_class_i s_cls[1]=
    {{
        &sf_vfs_i_addref,
        &sf_vfs_i_release,
        &sf_vfs_i_query_interface,
        &sf_vfs_i_open_file,
        &sf_vfs_i_getlasterror,
        &sf_vfs_i_rename,
        &sf_vfs_i_getattr,
        &sf_vfs_i_setattr,
        &sf_vfs_i_getaccess,
        &sf_vfs_i_setaccess,
        &sf_vfs_i_remove,
        &sf_vfs_i_getcwd,
        &sf_vfs_i_chcwd,
        &sf_vfs_i_mkdir,
        &sf_vfs_i_rmdir,
        &sf_vfs_i_exists,
        &sf_vfs_i_getfileinfo,
        &sf_vfs_i_enum_first,
        &sf_vfs_i_enum_next,
        &sf_vfs_i_enum_close,
        &sf_vfs_i_getfreespace
    }};
    sf_vfs_i* vfs=sf_vfs_alloc_node();
    if(vfs)
    {
        vfs->iLastError=SFReasonOK;
        vfs->__vftab=s_cls;
        vfs->hFileFind=-1;
        vfs->nRefCount=1;
    }
    return (sf_vfs*)vfs;
}


static void sf_vfs_init(void)
{
    if(!s_sf_vfs_inited)
    {
        int i;
        s_sf_vfs_inited=1;
        sf_vfs_prepare_drivers();
        SFSystem_InitSecureRecords();
        for(i=0;i<SF_VFS_MAX_OPEN_FILES;i++)
        {
            s_vfs_files[i].hFile=-1;
            s_vfs_files[i].vfs=SFNull;
        }
        for(i=0;i<SF_VFS_MAX_NODES;i++)
        {
            s_vfs_nodes[i].iModule=SFNull;
            s_vfs_nodes[i].iVFSNodeIdx=i;
            s_vfs_nodes[i].hFileFind=-1;
            s_vfs_nodes[i].iLastError=SFReasonOK;
        }
    }
}

static void sf_vfs_close_module(SFModule* mod)
{
    int i;
    for(i=0;i<SF_VFS_MAX_OPEN_FILES;i++)
    {
        if(s_vfs_files[i].vfs && (s_vfs_files[i].vfs->iModule==mod || !mod) )
        {
            if(s_vfs_files[i].hFile>=0)
            {
                FS_Close(s_vfs_files[i].hFile);
                s_vfs_files[i].hFile=-1;
                s_vfs_files[i].vfs=SFNull;
            }
        }
    }
    for(i=0;i<SF_VFS_MAX_NODES;i++)
    {
        if(s_vfs_nodes[i].iModule==mod || !mod)
        {
            if(s_vfs_nodes[i].hFileFind>=0)
            {
                FS_FindClose(s_vfs_nodes[i].hFileFind);
                s_vfs_nodes[i].hFileFind=-1;
            }
            sf_vfs_free_node(&s_vfs_nodes[i]);
        }
    }
}

static void sf_vfs_fini(void)
{
    sf_vfs_close_module(SFNull);
}


static ISFTimer* ISFTimer_NewSystemTimer(void);
static ISFNetworkManager* ISFNetworkManager_NewObject(void);

int sf_create_object(SFUint32 clsid_L,SFUint32 clsid_H,void**obj)
{
    if(!obj)
        return SFReasonBadParameter;
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
    {
        int r;
        extern int sf_create_object_ap(SFUint32 clsid_L,SFUint32 clsid_H,void**obj);
        r=sf_create_object_ap(clsid_L,clsid_H,obj);
        if(r==0)
            return 0;
    }
#endif //__SF_APPLICATION_PLATFORM__ENABLE__
    if(clsid_L==SF_CLSID_IVFS_L && clsid_H==SF_CLSID_IVFS_H)
    {
#ifdef SF_VFS_DEBUG
        SFDEBUG("sf_vfs_new");
#endif

        *obj=(void*)sf_vfs_new();

        return SFReasonOK;
    }
    else if(clsid_L==SF_CLSID_ISFTimer_L && clsid_H==SF_CLSID_ISFTimer_H)
    {
        *obj=(void*)ISFTimer_NewSystemTimer();
        return SFReasonOK;
    }
    else if(clsid_L==SF_CLSID_ISFNetworkManager_L && clsid_H==SF_CLSID_ISFNetworkManager_H)
    {
        *obj=(void*)ISFNetworkManager_NewObject();
        return SFReasonOK;
    }
    return SFReasonNotSupported;
}

int sf_vfs_dir_exists(const UChar*path)
{
    FS_HANDLE hDir;
    hDir=FS_Open(path,FS_OPEN_DIR | FS_READ_ONLY);
    if(hDir>=0)
    {
        FS_Close(hDir);
        return 1;
    }
    
    return 0;
}


int sf_vfs_repare_dir(const UChar* path)
{
    if(!sf_vfs_dir_exists(path))
    {
        //create the path
        FS_CreateDir(path);
        if(!sf_vfs_dir_exists(path))
        {
            sf_dbgprintf(L"cannot create dir %s",path);
            return -1;
        }
        FS_SetAttributes(path,FS_ATTR_HIDDEN);
    }
    else
    {
        int attr=FS_GetAttributes(path);
        if(attr>=0)
        {
            if((attr&FS_ATTR_HIDDEN)!=FS_ATTR_HIDDEN)
            {
                FS_SetAttributes(path,FS_ATTR_HIDDEN);
            }
        }
    }
    return 0;
}


int sf_vfs_is_drv_ready(UChar drv)
{
    UChar buf[6];
    sf_sprintf(buf,L"%c:\\",drv);
#ifdef SF_VFS_DEBUG
    sf_dbgprintf(L"check drv '%c'",drv);
#endif //SF_VFS_DEBUG
    return sf_vfs_dir_exists(buf);
}

extern int sf_strcmp(UString a,UString b);

static sf_vfs_string_t sf_vfs_remap_path(sf_vfs_i* vfs,sf_vfs_char_t*tmp,sf_vfs_string_t path)
{
    //parse the path

    SFModId modid;
    int len;
    sf_vfs_char_t* pstr;

    sf_vfs_prepare_drivers();

    if(!tmp|| !path)
        return SFNull;
    len=sf_strlen(path);
    modid=g_kernal.iActiveModule->iModId;
    
    if(sf_strbegins(path,-1,L"vfs:/",-1))
    {
        
        path+=5;
        len-=5;
#ifdef SF_VFS_DEBUG
        sf_dbgprintf(path);
        sf_dbgprintf(L"%s %d",L"bin/:0",sf_strcmp(path,L"bin/:0"));

#endif
        
        if(sf_strcmp(path,L"bin/:0")==0)
        {
            //copy the active app file path
#if defined(__SF_APPLICATION_PLATFORM__ENABLE__) || defined(SFAPI_WIN)
            

            if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN))
            {
                UString mod_path;
                if(SFSystem_GetEModulePath(g_kernal.iActiveModule->iEModule,&mod_path)!=SFReasonOK || !mod_path)
                    return NULL;
                sf_strcpy(tmp,mod_path);
#ifdef SF_VFS_DEBUG
                sf_dbgprintf(tmp);
#endif

                return tmp;
            }        
#endif //defined(__SF_APPLICATION_PLATFORM__ENABLE__) || defined(SFAPI_WIN)
            return NULL;
        }
        else if(sf_strbegins(path,len,L"~/",2))
        {
            path+=2;
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
            if(SFSystem_GetAppHomeDir(modid,tmp)!=0)
                tmp[0]=0; 
#else
            tmp[0]=0; 
#endif
        }
        else if(sf_strbegins(path,len,L"dev/local/",10))
        {
            //local fs
            path+=10;
#ifdef SF_VFS_DEBUG
            sf_dbgprintf(L"d dev/local");
#endif

            if(g_sf_local_drv>0 && sf_vfs_is_drv_ready(g_sf_local_drv))
            {
                sf_sprintf(tmp,L"%c:\\",g_sf_local_drv);
            }
            else
            {
                return SFNULL;
            }
        }
        else if(sf_strbegins(path,len,L"dev/card0/",10))
        {
            //card fs
            path+=10;
#ifdef SF_VFS_DEBUG
            sf_dbgprintf(L"d dev/card0");
#endif

            if(g_sf_card_drv>0 && sf_vfs_is_drv_ready(g_sf_card_drv))
            {
                sf_sprintf(tmp,L"%c:\\",g_sf_card_drv);
            }
            else
            {
#ifdef SF_VFS_DEBUG
                sf_dbgprintf(L"dd dev/card0 %d %d",g_sf_card_drv,sf_vfs_is_drv_ready(g_sf_card_drv));
#endif

                return SFNULL;
            }
        }
        else if(sf_strbegins(path,len,L"dev/sys/",8))
        {
            //card fs
            path+=8;
            if(g_sf_sys_drv>0 && sf_vfs_is_drv_ready(g_sf_sys_drv))
            {
                sf_sprintf(tmp,L"%c:\\",g_sf_sys_drv);
            }
            else
            {
                return SFNull;
            }
        }
        else if(sf_strbegins(path,len,L"sys/",4))
        {
            path+=4;
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
            if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN))
            {
                sf_sprintf(tmp,L"%c:\\@sfos\\",g_sf_sys_drv);
                if(!sf_vfs_dir_exists(tmp))
                {
                    return SFNull;
                }
            }
            else
                tmp[0]=0;
#endif
            if(tmp[0]==0 && sf_vfs_is_drv_ready(g_sf_sys_drv))
                sf_sprintf(tmp,L"%c:\\",g_sf_sys_drv);
        }
        else if(sf_strbegins(path,len,L"priv/",5))
        {
            path+=5;
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
            if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN))
            {
                if(SFSystem_GetAppPrivDir(modid,s_sf_vfs_temp_path)!=0)
                    tmp[0]=0;
            }
            else
                tmp[0]=0;
#endif

            //use get folder
            if(tmp[0]==0)
                SFSystem_GetFolder(SF_FOLDER_APPPRIVATE,tmp,FS_MAX_PATH);

        }
        else if(sf_strbegins(path,len,L"data/",5))
        {
            path+=5;
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
            if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN))
            {
                if(SFSystem_GetDataDir(modid,tmp)!=0)
                    tmp[0]=0;
            }
            else
#endif
            if(tmp[0]==0)
                SFSystem_GetFolder(SF_FOLDER_APPDATA,tmp,FS_MAX_PATH);

        }
        else if(sf_strbegins(path,len,L"app/",4))
        {
            path+=4;
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
            if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN))
            {
#ifdef SF_VFS_DEBUG
                sf_dbgprintf(L"apps dir");
#endif

                SFSystem_GetAppDir(modid,tmp);
            }
            else
#endif
            {
                if(g_sf_card_drv!=0 && sf_vfs_is_drv_ready(g_sf_card_drv))
                {
                    sf_sprintf(tmp,L"%c:\\Application\\",g_sf_card_drv);
                }
                else if(g_sf_local_drv!=0 && sf_vfs_is_drv_ready(g_sf_local_drv))
                {
                    sf_sprintf(tmp,L"%c:\\Application\\",g_sf_local_drv);
                }
                else
                {
                    return NULL;
                }
            }
        }
        else if(sf_strbegins(path,len,L"conf/",5))
        {
            path+=5;
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
            if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN))
            {
                if(SFSystem_GetAppConfDir(modid,tmp)!=0)
                    SFSystem_GetFolder(SF_FOLDER_APPCONFIG,tmp,FS_MAX_PATH);
            }
            else
#endif

            SFSystem_GetFolder(SF_FOLDER_APPCONFIG,tmp,FS_MAX_PATH);
        }
        else if(sf_strbegins(path,len,L"tmp/",4))
        {
            path+=4;
 #ifdef __SF_APPLICATION_PLATFORM__ENABLE__
            if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN))
            {
                if(SFSystem_GetAppTempDir(modid,tmp)!=0)
                    tmp[0]=0;
            }
            else
                tmp[0]=0;
#endif
            //try to prepare the temp dir
            if(tmp[0]==0)
            {
                if(g_sf_card_drv!=0 && sf_vfs_is_drv_ready(g_sf_card_drv))
                {
                    sf_sprintf(tmp,L"%c:\\tmp\\",g_sf_card_drv);
                }
                else if(g_sf_local_drv!=0 && sf_vfs_is_drv_ready(g_sf_local_drv))
                {
                    sf_sprintf(tmp,L"%c:\\tmp\\",g_sf_local_drv);
                }
            }
        }
        else if(sf_strbegins(path,len,L"pub/",4))
        {
            path+=4;
 #ifdef __SF_APPLICATION_PLATFORM__ENABLE__
            if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN))
            {
                if(SFSystem_GetAppPubDir(modid,tmp)!=0)
                    tmp[0]=0;
            }
            else
                tmp[0]=0;
#endif
            if(tmp[0]==0)
            {
                if(g_sf_card_drv!=0 && sf_vfs_is_drv_ready(g_sf_card_drv))
                {
                    sf_sprintf(tmp,L"%c:\\pub\\",g_sf_card_drv);
                }
                else if(g_sf_local_drv!=0 && sf_vfs_is_drv_ready(g_sf_local_drv))
                {
                    sf_sprintf(tmp,L"%c:\\pub\\",g_sf_local_drv);
                }
            }

        }
        else
        {
            return NULL;
        }
        
    }
    else if(sf_strbegins(path,-1,L"native:/",-1))
    {
        tmp[0]=0;
        path+=8;
    }
    else
    {
        //use the data dir
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
        if(!(g_kernal.iActiveModule->iFlag&SFMOD_ATTR_BUILTIN))
        {
            if(SFSystem_GetDataDir(modid,tmp)!=0)
        tmp[0]=0;
    }
        else
#endif
        if(tmp[0]==0)
        {
            SFSystem_GetFolder(SF_FOLDER_APPDATA,tmp,FS_MAX_PATH);
        }
    }

    sf_strcat(tmp,path);
    pstr=tmp;
    while(*pstr)
    {
        if(*pstr=='/')
        {
            *pstr='\\';
        }
        ++pstr;
    }
#ifdef SF_VFS_DEBUG
    sf_dbgprintf(tmp);
#endif //SF_VFS_DEBUG
    return tmp;
}

static UINT sf_vfs_remap_open_mode(int flags)
{
    UINT f;
    if(flags&SF_VFS_OPEN_WRITE)
    {
        if(flags&SF_VFS_OPEN_CREATE)
        {
            f=FS_READ_WRITE|FS_CREATE_ALWAYS;//FROM FS_CREATE
        }
        else
        {
            f=FS_READ_WRITE;
        }
    }
    else if(flags&SF_VFS_OPEN_READ)
    {
        f=FS_READ_ONLY;
    }
    else if(flags&SF_VFS_OPEN_CREATE)
    {
        f=FS_READ_WRITE|FS_CREATE_ALWAYS;
    }
    else
    {
        return 0;
    }
    return f;
	
}

static void sf_vfs_file_i_AddRef(sf_vfs_file_i* fd)
{
    ++fd->nRefCount;
}
static int sf_vfs_file_i_Release(sf_vfs_file_i* fd)
{
    --fd->nRefCount;
    if(fd->nRefCount<=0)
    {
        //close
        if(fd->hFile>=0)
        {
            //close 
            FS_Close(fd->hFile);
            fd->hFile=-1;
        }
        sf_vfs_release((sf_vfs*)fd->vfs);
        sf_vfs_free_file_node(fd);
        return 0;
    }
    return fd->nRefCount;
}
static SFReason sf_vfs_file_i_QueryInterface(sf_vfs_file_i* self,SFUint32 l,SFUint32 h,void**ptr)
{
    return SFReasonNotSupported;
}

static int sf_vfs_i_open_file(sf_vfs_i* fs,sf_vfs_string_t file,int mode,sf_vfs_file**pfile)
{
    sf_vfs_file_i* pFile;
    sf_vfs_string_t n;
#if defined(__SF_APPLICATION_PLATFORM__ENABLE__) || defined(SFAPI_WIN)
    SFReason ret;
#endif //defined(__SF_APPLICATION_PLATFORM__ENABLE__)

    static const sf_vfs_file_class_i __sf_vfs_clsss[1]=
    {
        {
            &sf_vfs_file_i_AddRef,
            &sf_vfs_file_i_Release,
            &sf_vfs_file_i_QueryInterface,
            &sf_vfs_file_i_close,
            &sf_vfs_file_i_read,
            &sf_vfs_file_i_write,
            &sf_vfs_file_i_seek,
            &sf_vfs_file_i_commit,
            &sf_vfs_file_i_tell,
            &sf_vfs_file_i_chsize,
            &sf_vfs_file_i_eof,
            &sf_vfs_file_i_trunc,
            &sf_vfs_file_i_getlasterror,
            &sf_vfs_file_i_filelength,
        }
    };
    if(!fs)
    {
        SFDEBUG("no fs");
        return SFReasonError;
    }
    if(!pfile || !file)
    {
#ifdef SF_VFS_DEBUG
        sf_dbgprintf(L"sf_vfs_i_open_file SFReasonBadParameter");
#endif

        fs->iLastError=SFReasonBadParameter;
        return SFReasonBadParameter;
    }
#if defined(__SF_APPLICATION_PLATFORM__ENABLE__) || defined(SFAPI_WIN)
    if(g_kernal.iActiveModule->iEModule)
    {
        extern SFReason sf_vfs_emodule_open_file(SFEModule* mod,sf_vfs_string_t file,int mode,sf_vfs_file**pfile);
        
        ret=sf_vfs_emodule_open_file(g_kernal.iActiveModule->iEModule,file,mode,pfile);
        if(ret!=SFReasonNotSupported)
        {
            sf_dbgprintf(L"apk file not found %d",ret);
            return ret;
        }
    }
#endif //defined(__SF_APPLICATION_PLATFORM__ENABLE__)
    pFile=sf_vfs_alloc_file_node(fs);
    if(!pFile)
    {
#ifdef SF_VFS_DEBUG
        sf_dbgprintf(L"sf_vfs_i_open_file SFReasonOutOfResource");
#endif

        fs->iLastError=SFReasonOutOfResource;
        return SFReasonOutOfResource;
    }
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,file);
    if(!n)
    {
#ifdef SF_VFS_DEBUG
        sf_dbgprintf(L"sf_vfs_i_open_file SFReasonNotFound");
#endif
        sf_vfs_free_file_node(pFile);
        *pfile=SFNull;
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    
    pFile->hFile=FS_Open(n,sf_vfs_remap_open_mode(mode));
    pFile->__vftab=(const sf_vfs_file_class*)__sf_vfs_clsss;
    if(pFile->hFile>=0)
    {
        fs->iLastError=SFReasonOK;
        pFile->iMode=mode;
        pFile->nRefCount=1;
        sf_vfs_addref((sf_vfs*)fs);
        
        *pfile=(sf_vfs_file*)pFile;

        if((mode&SF_VFS_OPEN_APPEND) && (mode&(SF_VFS_OPEN_WRITE|SF_VFS_OPEN_CREATE)))
        {
            FS_Seek(pFile->hFile,0,FS_FILE_END);
        }
#ifdef SF_VFS_DEBUG
        sf_dbgprintf(L"sf_vfs_i_open_file ok");
#endif

        return SFReasonOK;
    }
    else
    {
        //fail
        int r=pFile->hFile;
#ifdef SF_VFS_DEBUG
                        sf_dbgprintf(L"sf_vfs_i_open_file f %d",pFile->hFile);
#endif

        sf_vfs_free_file_node(pFile);
        *pfile=SFNull;
        return sf_vfs_i_catch_error(fs,r);
    }
}
static void sf_vfs_i_addref(sf_vfs_i* fs)
{
    ++fs->nRefCount;
}

static int sf_vfs_i_release(sf_vfs_i* fs)
{
    if(!fs)
    {
        return SFReasonError;
    }
    --fs->nRefCount;
    if(fs->nRefCount<=0)
    {
        //release the vfs node
        sf_vfs_free_node(fs);
    return 0;
}
    return fs->nRefCount;
}

static int sf_vfs_file_i_close(sf_vfs_file_i* fd)
{
    if(!fd)
    {
        return SFReasonError;
    }
    if(fd->hFile>=0)
    {
    FS_Close(fd->hFile);
        fd->hFile=-1;
    }
    sf_vfs_file_i_Release(fd);
    return 0;
}

static int sf_vfs_file_i_read(sf_vfs_file_i* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz)
{
    if(!fd)
    {
        return SFReasonError;
    }
    if(!fd->iMode&SF_VFS_OPEN_READ)
    {
        fd->iLastError=SFReasonAccessDenied;
        return SFReasonAccessDenied;
    }
    return sf_vfs_file_i_catch_error(fd,FS_Read(fd->hFile,buf,sz,(UINT*)rsz));
}

static int sf_vfs_file_i_write(sf_vfs_file_i* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz)
{
    if(!fd)
    {
        return SFReasonError;
    }
    if(!fd->iMode&(SF_VFS_OPEN_WRITE|SF_VFS_OPEN_CREATE))
    {
        fd->iLastError=SFReasonAccessDenied;
        return SFReasonAccessDenied;
    }
    return sf_vfs_file_i_catch_error(fd,FS_Write(fd->hFile,buf,sz,(UINT*)rsz));
}

static int sf_vfs_file_i_seek(sf_vfs_file_i* fd,sf_vfs_offset_t offset,int orig)
{
    int r;
    if(!fd)
    {
        return SFReasonError;
    }
    r=FS_Seek(fd->hFile,offset,orig);
    if(r>=0)
    {
        fd->iLastError=SFReasonOK;
        return r;
    }
    return sf_vfs_file_i_catch_error(fd,r);
}

static int sf_vfs_file_i_commit(sf_vfs_file_i* fd)
{
    if(!fd)
    {
        return SFReasonError;
    }
    return sf_vfs_file_i_catch_error(fd,FS_Commit(fd->hFile));
}

static int sf_vfs_file_i_tell(sf_vfs_file_i* fd,sf_vfs_offset_t* poffset)
{
    if(!fd)
    {
        return SFReasonError;
    }
    return sf_vfs_file_i_catch_error(fd,FS_GetFilePosition(fd->hFile,(UINT *) poffset));
}

static int sf_vfs_file_i_chsize(sf_vfs_file_i* fd,sf_vfs_size_t sz)
{
    UINT oldsz;
    if(!fd)
    {
        return SFReasonError;
    }
    FS_GetFileSize(fd->hFile,&oldsz);
    if(oldsz<sz)
    {
        FS_Extend(fd->hFile,sz-oldsz);
    }
    else if(oldsz>sz)
    {
        UINT oldpos;
        FS_GetFilePosition(fd->hFile,&oldpos);
        FS_Seek(fd->hFile,sz,FS_FILE_BEGIN);
        FS_Truncate(fd->hFile);
        if(oldpos<sz)
        {
            FS_Seek(fd->hFile,oldpos,FS_FILE_BEGIN);
        }
    }
    fd->iLastError=SFReasonOK;
    return fd->iLastError;
}

static int sf_vfs_file_i_eof(sf_vfs_file_i* fd)
{
    UINT oldsz;
    UINT oldpos;
    if(!fd)
        return -1;
    FS_GetFileSize(fd->hFile,&oldsz);
    FS_GetFilePosition(fd->hFile,&oldpos);
    if(oldpos<oldsz)
        return 0;
    else
        return 1;
}

static int sf_vfs_file_i_trunc(sf_vfs_file_i* fd)
{
    if(!fd)
    {
        return SFReasonError;
    }
    return sf_vfs_file_i_catch_error(fd,FS_Truncate(fd->hFile));
}

static int sf_vfs_file_i_getlasterror(sf_vfs_file_i* fd)
{
    if(!fd)
    {
        return SFReasonError;
    }
    return fd->iLastError;
}

static int sf_vfs_file_i_filelength(sf_vfs_file_i* fd,sf_vfs_size_t* psize)
{
    UINT sz;
    int r;
    if(!fd)
    {
        return SFReasonError;
    }
    r=FS_GetFileSize(fd->hFile,&sz);
    if(r==FS_NO_ERROR)
        *psize=sz;
    return sf_vfs_file_i_catch_error(fd,r);
}

static int sf_vfs_i_getlasterror(sf_vfs_i* fs)
{
    if(!fs)
        return 0;
    return fs->iLastError;
}
static int sf_vfs_i_rename(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_string_t newname)
{
    sf_vfs_string_t n1,n2;
    sf_vfs_char_t tmp[SFFS_MAX_PATH_LEN];
    if(!fs)
    {
        return SFReasonError;
    }
    n1=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,name);
    n2=sf_vfs_remap_path(fs,tmp,newname);
    if(!n1 || !n2)
    {
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    return sf_vfs_i_catch_error(fs,FS_Rename(n1,n2));
}
static int sf_vfs_i_getattr(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_attr_t* pattr)
{
    sf_vfs_string_t n;
    int r;
    if(!fs)
    {
        return SFReasonError;
    }
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,name);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    r=FS_GetAttributes(n);
    if(r>=0)
        *pattr=(sf_vfs_attr_t)r;
    return sf_vfs_i_catch_error(fs,r);
}
static int sf_vfs_i_setattr(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_attr_t attr)
{
    sf_vfs_string_t n;
    if(!fs)
    {
        return SFReasonError;
    }
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,name);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    return sf_vfs_i_catch_error(fs,FS_SetAttributes(n,(BYTE)attr));
}
static int sf_vfs_i_getaccess(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_access_t* paccess)
{
    sf_vfs_string_t n;
    if(!fs)
    {
        return SFReasonError;
    }
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,name);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    fs->iLastError=SFReasonNotSupported;
    return SFReasonNotSupported;
}
static int sf_vfs_i_setaccess(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_access_t access)
{
    sf_vfs_string_t n;
    if(!fs)
    {
        return SFReasonError;
    }
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,name);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    fs->iLastError=SFReasonNotSupported;
    return SFReasonNotSupported;
}
static int sf_vfs_i_remove(sf_vfs_i* fs,sf_vfs_string_t name)
{
    sf_vfs_string_t n;
    if(!fs)
    {
        return SFReasonError;
    }
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,name);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    return sf_vfs_i_catch_error(fs,FS_Delete(n));
}


static int sf_vfs_i_getcwd(sf_vfs_i* fs,sf_vfs_char_t* buf,SFSize_T maxlen)
{
#ifndef SF_VFS_CWD_SUPPORT
    return SFReasonNotSupported;
#else //!SF_VFS_CWD_SUPPORT
    if(!fs)
    {
        return SFReasonError;
    }
    return sf_vfs_i_catch_error(fs,FS_GetCurrentDir(buf,maxlen*2));
#endif //!SF_VFS_CWD_SUPPORT
}
static int sf_vfs_i_chcwd(sf_vfs_i* fs,sf_vfs_string_t path)
{
#ifndef SF_VFS_CWD_SUPPORT
    return SFReasonNotSupported;
#else
    sf_vfs_string_t n;
    if(!fs)
    {
        return SFReasonError;
    }
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,path);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    return sf_vfs_i_catch_error(fs,FS_SetCurrentDir(n));
#endif //!SF_VFS_CWD_SUPPORT
}
static int sf_vfs_i_mkdir(sf_vfs_i* fs,sf_vfs_string_t name)
{
    sf_vfs_string_t n;
    if(!fs)
    {
        return SFReasonError;
    }
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,name);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    return sf_vfs_i_catch_error(fs,FS_CreateDir(n));
}
static int sf_vfs_i_rmdir(sf_vfs_i* fs,sf_vfs_string_t name)
{
    sf_vfs_string_t n;
    if(!fs)
    {
        return SFReasonError;
    }
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,name);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    return sf_vfs_i_catch_error(fs,FS_RemoveDir(n));
}
static int sf_vfs_i_exists(sf_vfs_i* fs,sf_vfs_string_t name,int mode)
{
    FS_HANDLE hFile;
    sf_vfs_string_t n;
    if(!fs)
    {
        return 0;
    }
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,name);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return 0;
    }
    if(mode==0)
        mode=SF_VFS_FIND_ALL;
    fs->iLastError=SFReasonOK;
    if(mode&SF_VFS_FIND_DIR)
    {
        if(!(mode&SF_VFS_FIND_FILE))
        {
            hFile=FS_Open(n,FS_READ_ONLY|FS_OPEN_NO_DIR);
            if(hFile>=0)
            {
                FS_Close(hFile);
                return 0;
            }
        }
        if(sf_vfs_dir_exists(n))
        {
            return 1;
        }
    }
    if(mode&SF_VFS_FIND_FILE)
    {
        hFile=FS_Open(n,FS_READ_ONLY|FS_OPEN_NO_DIR);
        if(hFile>=0)
        {
            FS_Close(hFile);
            return 1;
        }
        sf_vfs_i_catch_error(fs,hFile);
    }

    
    return 0;
}

#define SF_MKTM(y,mm,d,h,m,s,ms) ((ms)|(((SFUint64)(s))<<10)|(((SFUint64)(mm))<<15)|(((SFUint64)(h))<<21)|(((SFUint64)(d))<<26)|(((SFUint64)(m))<<31)|(((SFUint64)(y))<<35))

static void sf_sysfileentry_to_fileinfo(const FS_DOSDirEntry* pfinfo,sf_vfs_fileinfo* pinfo)
{
    pinfo->access=0;
    pinfo->attrib=pfinfo->Attributes;
    pinfo->size=pfinfo->FileSize;

    //y m d h m s ms
    //   4  5 5 6 5  10
    
    pinfo->time_create=SF_MKTM(pfinfo->CreateDateTime.Year1980+1980,pfinfo->CreateDateTime.Month,pfinfo->CreateDateTime.Day,pfinfo->CreateDateTime.Hour,pfinfo->CreateDateTime.Minute,pfinfo->CreateDateTime.Second2,0);
    pinfo->time_write=SF_MKTM(pfinfo->DateTime.Year1980+1980,pfinfo->DateTime.Month,pfinfo->DateTime.Day,pfinfo->DateTime.Hour,pfinfo->DateTime.Minute,pfinfo->DateTime.Second2,0);
    pinfo->time_access=pinfo->time_write;

}

static void sf_sysfileinfo_to_fileinfo(const FS_FileInfo* pfinfo,sf_vfs_fileinfo* pinfo)
{
    sf_sysfileentry_to_fileinfo(pfinfo->DirEntry,pinfo);
    if(pfinfo->FullName)
        sf_strcpy(pinfo->name,(UString)pfinfo->FullName);
    else
        pinfo->name[0]=0;
}

static int sf_vfs_i_getfileinfo(sf_vfs_i* fs,sf_vfs_string_t name,sf_vfs_fileinfo* pinfo)
{
    FS_FileInfo finfo;
    FS_HANDLE hFile;
    int r;
    sf_vfs_string_t n;
    if(!fs)
    {
        return SFReasonError;
    }
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,name);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    hFile=FS_Open(n,FS_READ_ONLY);
    if(hFile<0)
    {
        return sf_vfs_i_catch_error(fs,hFile);
    }
    r=FS_GetFileInfo(hFile,&finfo);
    if(r<0)
    {
        FS_Close(hFile);
        return sf_vfs_i_catch_error(fs,hFile);
    }
    sf_sysfileinfo_to_fileinfo(&finfo,pinfo);
    
    FS_Close(hFile);
    return sf_vfs_i_catch_error(fs,FS_NO_ERROR);
}


static int sf_vfs_i_enum_first(sf_vfs_i* fs,sf_vfs_string_t path,int mode,sf_vfs_fileinfo* pinfo)
{
    FS_DOSDirEntry entry;
    BYTE nattr=0;
    BYTE attr=0;
    sf_vfs_string_t n;
    if(!fs)
    {
        return SFReasonError;
    }
    
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,path);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return SFReasonNotFound;
    }
    
    if(s_sf_vfs_temp_path[0] && s_sf_vfs_temp_path[sf_strlen(s_sf_vfs_temp_path)-1]=='\\')
    {
        //append
        sf_strcat(s_sf_vfs_temp_path,L"*");
    }
    
    
    if(fs->hFileFind>=0)
    {
        fs->iLastError=SFReasonOutOfResource;
        return SFReasonOutOfResource;
    }
    if((mode&(SF_VFS_FIND_FILE|SF_VFS_FIND_DIR))!=(SF_VFS_FIND_FILE|SF_VFS_FIND_DIR))
    {
        if(mode&SF_VFS_FIND_FILE)
        {
            nattr=FS_ATTR_DIR;
        }
        else if(mode&SF_VFS_FIND_DIR)
        {
            attr=FS_ATTR_DIR;
        }
    }
    fs->hFileFind=FS_FindFirst(n,attr,nattr,&entry,pinfo->name,sizeof(pinfo->name));
    if(fs->hFileFind<0)
    {
        return sf_vfs_i_catch_error(fs,fs->hFileFind);
    }
    sf_sysfileentry_to_fileinfo(&entry,pinfo);
    return SFReasonOK;
    
}

static int sf_vfs_i_enum_next(sf_vfs_i* fs,sf_vfs_fileinfo* pinfo)
{
    FS_DOSDirEntry entry;
    int r;
    if(!fs)
    {
        return SFReasonError;
    }
    if(fs->hFileFind<0)
    {
        fs->iLastError=SFReasonNotReady;
        return SFReasonNotReady;
    }
    if((r=FS_FindNext(fs->hFileFind,&entry,pinfo->name,sizeof(pinfo->name)))==FS_NO_ERROR)
    {
        sf_sysfileentry_to_fileinfo(&entry,pinfo);
        fs->iLastError=SFReasonOK;
        return SFReasonOK;
    }
    //SFReasonEndOfFile
    if(r==FS_NO_MORE_FILES)
    {
        fs->iLastError=SFReasonEndOfFile;
        return SFReasonEndOfFile;
    }
    else
    {
        return sf_vfs_i_catch_error(fs,r);
    }
}

static int sf_vfs_i_enum_close(sf_vfs_i* fs)
{
    int r;
    if(!fs)
    {
        return SFReasonError;
    }
    r=sf_vfs_i_catch_error(fs,FS_FindClose(fs->hFileFind));
    fs->hFileFind=-1;
    return r;
}
static int sf_vfs_i_getfreespace(sf_vfs_i* fs,sf_vfs_string_t path,sf_vfs_size_t *psize)
{
    sf_vfs_string_t n=SFNull;
    FS_DiskInfo dinfo;
    SFUint64 sz;
    int r;
    if(!fs)
    {
        return SFReasonError;
    }
    if(!psize)
    {
        fs->iLastError=SFReasonBadParameter;
        return SFReasonBadParameter;
    }
    fs->iLastError=SFReasonOK;
    n=sf_vfs_remap_path(fs,s_sf_vfs_temp_path,path);
    if(!n)
    {
        fs->iLastError=SFReasonNotFound;
        return fs->iLastError;
    }
    else if(!(((n[0]>='A'&&n[0]>='Z')||(n[0]>='a'&&n[0]>='z')) && n[1]==L':' && n[2]==L'\\'))
    {
        r=FS_GetCurrentDir(s_sf_vfs_temp_path,sizeof(s_sf_vfs_temp_path));
        if(r!=FS_NO_ERROR)
            return sf_vfs_i_catch_error(fs,r);
        n=s_sf_vfs_temp_path;
    }
    r=FS_GetDiskInfo(n,&dinfo,FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if(r!=FS_NO_ERROR)
        return sf_vfs_i_catch_error(fs,r);
    sz=dinfo.FreeClusters*dinfo.BytesPerSector;
    if(sz>0xFFFFFFFFULL)
    {
        *psize=0xFFFFFFFF;
    }
    else
    {
        *psize=(sf_vfs_size_t)sz;
    }
    return fs->iLastError;
}

typedef struct _SFSecureRecord
{
    SFUint64 iAppId;
    SFUint32 iRecordId;
    SFUint32 vL;
    SFUint32 vH;
} SFSecureRecord;

typedef struct _SFSecureRecordHeader
{
    SFUint32 iMagic;
    SFUint32 iMaxRecords;
} SFSecureRecordHeader;


#define SF_MAX_SECURE_RECORDS_SFAP   1200
#define SF_MAX_SECURE_RECORDS       128

int SFSystem_InitSecureRecordsFile(const UChar* path,SFInt records)
{
    FS_HANDLE hFile;
    UINT rsz;
    UINT sz;
    UINT remain=records*sizeof(SFSecureRecord);
    UINT szall=0;
    SFSecureRecordHeader hdr;
    SFSecureRecord buf[32];
    hFile=FS_Open(path,FS_READ_WRITE);
    if(hFile>=0)
    {
        FS_Close(hFile);
        return 0;
    }
    hFile=FS_Open(path,FS_READ_WRITE|FS_CREATE);
    
    if(hFile<0)
        return -1;
    memset(buf,0,sizeof(buf));
    memset(&hdr,0,sizeof(SFSecureRecordHeader));
    if(FS_Write(hFile,buf,sizeof(SFSecureRecordHeader),&rsz)!=FS_NO_ERROR)
    {
        FS_Close(hFile);
        FS_Delete(path);
        return -1;
    }
    while(remain>0)
    {
        
        sz=remain;
        if(sz>sizeof(buf))
            sz=sizeof(buf);
        if(FS_Write(hFile,buf,sz,&rsz)!=FS_NO_ERROR)
        {
            FS_Close(hFile);
            FS_Delete(path);
            return -1;
        }
        szall+=rsz;
        if(rsz>=remain)
            break;
        remain-=rsz;
        
        if(rsz<sz)
        {
            break;
        }
    }
    sz=szall/sizeof(SFSecureRecord);
    if(sz==0)
    {
        //fail
        FS_Close(hFile);
        FS_Delete(path);
        return -1;
    }
    hdr.iMagic=0x11000011;
    hdr.iMaxRecords=sz;
    FS_Seek(hFile,0,FS_FILE_BEGIN);
    FS_Write(hFile,&hdr,sizeof(SFSecureRecordHeader),&rsz);
    FS_Close(hFile);
    FS_SetAttributes(path,FS_ATTR_HIDDEN|FS_ATTR_SYSTEM);
#ifdef SF_VFS_DEBUG
    sf_dbgprintf(L"sec c %d",hdr.iMaxRecords);
#endif //SF_VFS_DEBUG
    return 0;
}


extern int SFAppPlatform_GetOSDir(UChar* path_dir);

static int SFSystem_GetSecureRecordPath(int idx,UChar* path)
{
    if(idx==0)
    {
        //SFApp_Get
        sf_sprintf(path,L"Z:\\");
    }
#ifdef __SF_APPLICATION_PLATFORM__ENABLE__
    else if(idx==1)
    {
        //SFApp_Get
        SFAppPlatform_GetOSDir(path);
    }
#endif
    else
    {
        return -1;
    }
    sf_strcat(path,L"_sec.dat");
    return 0;
}
int SFSystem_InitSecureRecords(void)
{
    if(SFSystem_GetSecureRecordPath(0,s_sf_vfs_temp_path)==0)
    {
        SFSystem_InitSecureRecordsFile(s_sf_vfs_temp_path,SF_MAX_SECURE_RECORDS);
    }
    if(SFSystem_GetSecureRecordPath(1,s_sf_vfs_temp_path)==0)
    {
        SFSystem_InitSecureRecordsFile(s_sf_vfs_temp_path,SF_MAX_SECURE_RECORDS_SFAP);
    }
    return 0;
}

int SFSystem_WriteSecureRecordInternal(SFUint64 id,SFInt32 id_record,SFInt32 vL,SFInt32 vH)
{
    FS_HANDLE hFile;
    UINT rsz;
    UINT remain;
    UINT sz;
    SFSecureRecordHeader hdr;
    SFSecureRecord buf[32];
    SFSystem_InitSecureRecords();

    if(id==0)
    {
        SFSystem_GetSecureRecordPath(0,s_sf_vfs_temp_path);
    }
    else
    {
        if(SFSystem_GetSecureRecordPath(1,s_sf_vfs_temp_path)!=0)
        {
            SFSystem_GetSecureRecordPath(0,s_sf_vfs_temp_path);
        }
    }

    hFile=FS_Open(s_sf_vfs_temp_path,FS_READ_WRITE);
    
    if(hFile>=0)
    {
        //read records
        if(FS_Read(hFile,&hdr,sizeof(SFSecureRecordHeader),&rsz)!=FS_NO_ERROR || hdr.iMagic!=0x11000011)
        {
            FS_Close(hFile);
            return -1;
        }
        
        remain=hdr.iMaxRecords*sizeof(SFSecureRecord);
        while(remain)
        {
            UINT recs;
            UINT i;
            UINT pos;
            sz=remain;
            if(sz>sizeof(buf))
            {
                sz=sizeof(buf);
            }
            FS_GetFilePosition(hFile,&pos);
            if(FS_Read(hFile,buf,sz,&rsz)!=FS_NO_ERROR)
            {
                FS_Close(hFile);
                return -1;
            }
            recs=rsz/sizeof(SFSecureRecord);
            for(i=0;i<recs;i++)
            {
                if(buf[i].iAppId==id && buf[i].iRecordId==id_record)
                {
                    buf[i].vH=vH;
                    buf[i].vL=vL;
#ifdef SF_VFS_DEBUG
                    sf_dbgprintf(L"sec w %d %d %d %d %d %d",hdr.iMaxRecords,(int)buf[i].iAppId,pos+i*sizeof(SFSecureRecord),buf[i].iRecordId,buf[i].vL,buf[i].vH);
#endif //SF_VFS_DEBUG


                    //
                    FS_Seek(hFile,pos+i*sizeof(SFSecureRecord),FS_FILE_BEGIN);
                    FS_Write(hFile,&buf[i],sizeof(SFSecureRecord),&sz);
                    FS_Close(hFile);
                    return 0;
                }
            }
            if(rsz>=remain)
                break;
            remain-=rsz;
        }
        //else
        FS_Seek(hFile,sizeof(SFSecureRecordHeader),FS_FILE_BEGIN);
        remain=hdr.iMaxRecords*sizeof(SFSecureRecord);
        while(remain>0)
        {
            UINT recs;
            UINT i;
            UINT pos;
            sz=remain;
            if(sz>sizeof(buf))
            {
                sz=sizeof(buf);
            }
            FS_GetFilePosition(hFile,&pos);
            if(FS_Read(hFile,buf,sz,&rsz)!=FS_NO_ERROR)
            {
                FS_Close(hFile);
                return -1;
            }
            recs=rsz/sizeof(SFSecureRecord);
            for(i=0;i<recs;i++)
            {
                if(buf[i].iAppId==0 || (buf[i].vL==0 && buf[i].vH==0))
                {
                    buf[i].vH=vH;
                    buf[i].vL=vL;
                    buf[i].iAppId=id;
                    buf[i].iRecordId=id_record;
#ifdef SF_VFS_DEBUG
                    sf_dbgprintf(L"sec w %d %d %d %d %d %d",hdr.iMaxRecords,(int)buf[i].iAppId,pos+i*sizeof(SFSecureRecord),buf[i].iRecordId,buf[i].vL,buf[i].vH);
#endif //SF_VFS_DEBUG

                    //
                    FS_Seek(hFile,pos+i*sizeof(SFSecureRecord),FS_FILE_BEGIN);
                    FS_Write(hFile,&buf[i],sizeof(SFSecureRecord),&sz);
                    FS_Close(hFile);
                    return 0;
                }
            }
            if(rsz>=remain)
                break;
            remain-=rsz;
        }
        FS_Close(hFile);
        return SFReasonOutOfResource;
    }
    return -1;
}

#ifdef __SF_APPLICATION_PLATFORM__ENABLE__

int SFSystem_ClearSecureRecordInternal(SFUint64 id)
{
    FS_HANDLE hFile;
    UINT rsz;
    UINT remain;
    UINT sz;
    SFSecureRecordHeader hdr;
    SFSecureRecord buf[32];
    SFSystem_InitSecureRecords();

    if(id==0)
    {
        SFSystem_GetSecureRecordPath(0,s_sf_vfs_temp_path);
    }
    else
    {
        if(SFSystem_GetSecureRecordPath(1,s_sf_vfs_temp_path)!=0)
        {
            SFSystem_GetSecureRecordPath(0,s_sf_vfs_temp_path);
        }
    }
#ifdef SF_VFS_DEBUG
    sf_dbgprintf(L"sec cc %d,%d",(int)(id>>32),(int)id);
#endif //SF_VFS_DEBUG
    hFile=FS_Open(s_sf_vfs_temp_path,FS_READ_WRITE);
    
    if(hFile>=0)
    {
        //read records
        if(FS_Read(hFile,&hdr,sizeof(SFSecureRecordHeader),&rsz)!=FS_NO_ERROR || hdr.iMagic!=0x11000011)
        {
            FS_Close(hFile);
            return -1;
        }
        
        remain=hdr.iMaxRecords*sizeof(SFSecureRecord);
        while(remain)
        {
            UINT recs;
            UINT i;
            UINT pos;
            UINT changed=0;
            sz=remain;
            if(sz>sizeof(buf))
            {
                sz=sizeof(buf);
            }
            FS_GetFilePosition(hFile,&pos);
            if(FS_Read(hFile,buf,sz,&rsz)!=FS_NO_ERROR)
            {
                FS_Close(hFile);
                return -1;
            }
            recs=rsz/sizeof(SFSecureRecord);
            for(i=0;i<recs;i++)
            {
                if(buf[i].iAppId==id)
                {
#ifdef SF_VFS_DEBUG
                    sf_dbgprintf(L"sec clr %d %d %d %d %d %d",(int)(buf[i].iAppId>>32),(int)buf[i].iAppId,pos+i*sizeof(SFSecureRecord),buf[i].iRecordId,buf[i].vL,buf[i].vH);
#endif //SF_VFS_DEBUG

                    buf[i].iAppId=0;
                    buf[i].iRecordId=0;
                    buf[i].vH=0;
                    buf[i].vL=0;


                    changed=1;
                }
#ifdef SF_VFS_DEBUG
                if(buf[i].iAppId)
                    sf_dbgprintf(L"sec skip %d %d %d %d %d %d",(int)(buf[i].iAppId>>32),(int)buf[i].iAppId,pos+i*sizeof(SFSecureRecord),buf[i].iRecordId,buf[i].vL,buf[i].vH);
#endif //SF_VFS_DEBUG

            }
            if(changed)
            {
                UINT wsz;
                //rewrite
                FS_Seek(hFile,pos,FS_FILE_BEGIN);
                FS_Write(hFile,buf,recs*sizeof(SFSecureRecord),&wsz);
                changed=0;
            }
            if(rsz>=remain)
                break;
            remain-=recs*sizeof(SFSecureRecord);
        }
        FS_Close(hFile);
        return 0;
    }
    return -1;
}

#endif //__SF_APPLICATION_PLATFORM__ENABLE__

int SFSystem_ReadSecureRecordInternal(SFUint64 id,SFInt32 id_record,SFInt32*vL,SFInt32*vH)
{
    FS_HANDLE hFile;
    UINT rsz;
    UINT remain;
    UINT sz;
    SFSecureRecordHeader hdr;
    SFSecureRecord buf[32];

    SFSystem_InitSecureRecords();
    if(id==0)
    {
        SFSystem_GetSecureRecordPath(0,s_sf_vfs_temp_path);
    }
    else
    {
        if(SFSystem_GetSecureRecordPath(1,s_sf_vfs_temp_path)!=0)
        {
            SFSystem_GetSecureRecordPath(0,s_sf_vfs_temp_path);
        }
    }
    hFile=FS_Open(s_sf_vfs_temp_path,FS_READ_WRITE);
    
    if(hFile>=0)
    {
        //read records
        if(FS_Read(hFile,&hdr,sizeof(SFSecureRecordHeader),&rsz)!=FS_NO_ERROR || hdr.iMagic!=0x11000011)
        {
            FS_Close(hFile);
            return -1;
        }
        
        remain=hdr.iMaxRecords*sizeof(SFSecureRecord);
        while(remain)
        {
            UINT recs;
            UINT i;
            UINT pos;
            sz=remain;
            if(sz>sizeof(buf))
            {
                sz=sizeof(buf);
            }
            FS_GetFilePosition(hFile,&pos);
            if(FS_Read(hFile,buf,sz,&rsz)!=FS_NO_ERROR)
            {
                FS_Close(hFile);
                return -1;
            }
            recs=rsz/sizeof(SFSecureRecord);
            for(i=0;i<recs;i++)
            {
                if(buf[i].iAppId==id && buf[i].iRecordId==id_record)
                {
                    if(vH) *vH=buf[i].vH;
                    if(vL) *vL=buf[i].vL;
#ifdef SF_VFS_DEBUG
                    sf_dbgprintf(L"sec r %d %d %d %d %d %d",hdr.iMaxRecords,(int)buf[i].iAppId,pos+i*sizeof(SFSecureRecord),buf[i].iRecordId,buf[i].vL,buf[i].vH);
#endif //SF_VFS_DEBUG
                    FS_Close(hFile);
                    return SFReasonOK;
                }
            }
            if(rsz>=remain)
                break;
            remain-=rsz;
        }
        FS_Close(hFile);
        return SFReasonNotFound;
    }
    return SFReasonNotFound;
}

int SFApp_WriteSecureRecord(SFInt32 id_record,SFInt32 vL,SFInt32 vH)
{
    return SFSystem_WriteSecureRecordInternal(g_kernal.iActiveModule->iModId,id_record,vL,vH);
}

int SFApp_ReadSecureRecord(SFInt32 id_record,SFInt32* vL,SFInt32* vH)
{
    return SFSystem_ReadSecureRecordInternal(g_kernal.iActiveModule->iModId,id_record,vL,vH);
}


void SFSystem_GetCurrentDateTime(SFDateTime*pDataTime)
{
    SFSystem_GetCurrentDataTime(pDataTime);
}

void sf_time(sf_time_t* tm)
{
    SFDateTime dt;
    if(tm)
    {
        SFSystem_GetCurrentDateTime(&dt);
        *tm=SF_MKTM(dt.nYear,dt.nMonth,dt.nDay,dt.nHour,dt.nMinute,dt.nSecond,0);
    }
}

//


void SFSystem_SelectFile(UChar* aBuffer,SFSize_T aMaxSize,SFUint32 aFlags,const UChar* aFilter,SFReason* aReason)
{
#ifdef SFAPI_WIN
    extern void SFSystem_SelectFileW(UChar* aBuffer,SFSize_T aMaxSize,SFBool bOpenFile,const UChar* aFilter,SFReason* aReason);

    SFSystem_SelectFileW(aBuffer,aMaxSize,aFlags,aFilter,aReason);
#else
    //currently not supported 
    SFSystem_NotifyAllV(aReason,SFReasonNotSupported);
#endif
}


#define MAX_TITLE_LEN   32
static SFReason* s_input_text_result=NULL;
static int s_input_text_method;
static UChar *s_input_text_buffer;
static SFSize_T s_input_text_buffer_length;
static UChar s_input_text_title_buffer[MAX_TITLE_LEN+1];

static UChar *s_input_text_title;

static void SFSystem_InputTextCancel(void)
{
    SFDEBUG("SFSystem_InputTextCancel");
    if(s_input_text_result)
    {
        SFReason* aReason=s_input_text_result;
        s_input_text_result=NULL;
        SFSystem_NotifyAllV(aReason,SFReasonCancel);
    }
    GoBackHistory();
}
static void SFSystem_InputTextOKFromOption(void)
{
    SFDEBUG("SFSystem_InputTextOKFromOption");
    if(s_input_text_result)
    {
        SFReason* aReason=s_input_text_result;
        s_input_text_result=NULL;
        SFSystem_NotifyAllV(aReason,SFReasonOK);
    }
    GoBacknHistory(1);
}

extern UI_string_type MMI_title_string;

#define SF_INPUT_TYPE_BASIC_MASK    0xFF



static int map_input_type(SFUint32 type)
{
    int r=0;
    if(type&SF_INPUT_TYPE_ENGLISH_ONLY)
    {
        r|=INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
    }
    switch(type&SF_INPUT_TYPE_BASIC_MASK)
    {
    case SF_INPUT_TYPE_NUMERIC:
        if(type&SF_INPUT_TYPE_PASSWORD)
        {
            return INPUT_TYPE_NUMERIC_PASSWORD|r;
        }
        else
        {
            return INPUT_TYPE_NUMERIC|r;
        }
    case SF_INPUT_TYPE_PHONENUMBER:
        return INPUT_TYPE_PHONE_NUMBER|INPUT_TYPE_PLUS_CHARACTER_HANDLING|r;
    case SF_INPUT_TYPE_DECIMAL:
        return INPUT_TYPE_DECIMAL_NUMERIC|r;
    case SF_INPUT_TYPE_EMAILADDR:
    case SF_INPUT_TYPE_URL:
    case SF_INPUT_TYPE_ANY:
        if(type&SF_INPUT_TYPE_PASSWORD)
        {
            return INPUT_TYPE_ALPHANUMERIC_PASSWORD|r;
        }
        else
        {
            return INPUT_TYPE_ALPHANUMERIC_SENTENCECASE|r;
        }
        break;
    default:
        return -1;;
    }
}

struct s2v_lookup_tab
{
    const char* name;
    SFInt16 id;
};

#if 0
static const struct s2v_lookup_tab input_modes[]=
{
    {"default",-1},
    {"UCB_BASIC_LATIN",INPUT_MODE_MULTITAP_LOWERCASE_ABC},
    {"UCB_GREEK",INPUT_MODE_MULTITAP_LOWERCASE_GREEK},
    {"UCB_CYRILLIC",INPUT_MODE_MULTITAP_LOWERCASE_ABC},
    {"UCB_ARMENIAN",INPUT_MODE_MULTITAP_LOWERCASE_ABC},
    {"UCB_HEBREW",INPUT_MODE_MMI_MULTITAP_HEBREW},
    {"UCB_ARABIC",INPUT_MODE_MMI_MULTITAP_ARABIC},
    {"UCB_DEVANAGARI",INPUT_MODE_MULTITAP_LOWERCASE_ABC},
    {"UCB_BENGALI",INPUT_MODE_MULTITAP_LOWERCASE_ABC},
    {"UCB_THAI",INPUT_MODE_MMI_MULTITAP_THAI},
    {"UCB_HIRAGANA",INPUT_MODE_MULTITAP_LOWERCASE_ABC},
    {"UCB_KATAKANA",INPUT_MODE_MULTITAP_LOWERCASE_ABC},
    {"UCB_HANGUL_SYLLABLES",INPUT_MODE_MULTITAP_LOWERCASE_ABC},
    {"IS_FULLWIDTH_DIGITS",INPUT_MODE_123},
    {"IS_FULLWIDTH_LATIN",INPUT_MODE_MULTITAP_UPPERCASE_ABC},
    {"IS_HALFWIDTH_KATAKANA",INPUT_MODE_MULTITAP_UPPERCASE_ABC},
    {"IS_HANJA",INPUT_MODE_MULTITAP_LOWERCASE_ABC},
    {"IS_KANJI",INPUT_MODE_MULTITAP_UPPERCASE_ABC},
    {"IS_LATIN",INPUT_MODE_MULTITAP_LOWERCASE_ABC},
    {"IS_LATIN_DIGITS",INPUT_MODE_MULTITAP_LOWERCASE_ABC},
    {"IS_SIMPLIFIED_HANZI",INPUT_MODE_SM_PINYIN},
    {"IS_TRADITIONAL_HANZI",INPUT_MODE_TR_BOPOMO},
    {"SF_UPPERCASE_LATIN",INPUT_MODE_MULTITAP_UPPERCASE_ABC},
    {"SF_LOWERCASE_LATIN",INPUT_MODE_MULTITAP_LOWERCASE_ABC}
};

static int input_mode_lookup(const char* input_mode)
{
    int i;
    if(!input_mode|| strlen(input_mode)==0)
        return -1;
    for(i=0;i<sizeof(input_modes)/sizeof(struct s2v_lookup_tab);i++)
    {
        if(sf_astricmp(input_mode,input_modes[i].name)==0)
        {
            return input_modes[i].id;
        }
    }
    return -1;
}
#endif //0

void SFSystem_InputTextReturn(void)
{
    GoBacknHistory(1);
}

static SFInt8 s_input_text_highlight=0;

void SFSystem_InputTextOptionHandle(S32 hiliteid)
{
    s_input_text_highlight=(SFInt8)hiliteid;
}

void SFSystem_InputTextOptionAction(void)
{
    switch(s_input_text_highlight)
    {
    case 0:
        SFSystem_InputTextOKFromOption();
        break;
    case 1:
        EntryInputMethodScreen();
        break;
    //case 2:
    //    GoBackHistory();
    //    break;
    default:
        //pass
        GoBackHistory();
        break;
    }
}

void SFSystem_InputTextOption(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U8 *guiBuffer;
    U16 nNumofItem;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SFCUST_UI_SCREEN_ID+2, NULL, SFSystem_InputTextOption, NULL);

    guiBuffer = GetCurrGuiBuffer(SFCUST_UI_SCREEN_ID+2);

    RegisterHighlightHandler(&SFSystem_InputTextOptionHandle);
    nNumofItem = 3;
    //GetSequenceStringIds(MITEM_FMGR_EDITOR_OPTION, nStrItemList);
    //SetParentHandler(MITEM_FMGR_EDITOR_OPTION);
    nStrItemList[0]=STR_GLOBAL_DONE;
    nStrItemList[1]=STR_GLOBAL_INPUT_METHOD;
    //nStrItemList[2]=STR_GLOBAL_CLEAR;
    nStrItemList[2]=STR_GLOBAL_BACK;

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        NULL,
        1,
        0,
        guiBuffer);

    RegisterInputMethodScreenCloseFunction(&SFSystem_InputTextReturn);
    SetRightSoftkeyFunction(&GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(&GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(&SFSystem_InputTextOptionAction, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory,KEY_END, KEY_EVENT_DOWN);
}

void SFSystem_InputTextEntry(void)
{
    U8 *history_buffer;
    
    EntryNewScreen(SFCUST_UI_SCREEN_ID+1, NULL, &SFSystem_InputTextEntry, NULL);
    history_buffer = GetCurrGuiBuffer(SFCUST_UI_SCREEN_ID+1);

    ShowCategory5Screen(
        s_input_text_title?STR_GLOBAL_EDIT:0,
        (U16) 0,
        STR_GLOBAL_OPTIONS,
        (U16) 0,
        STR_GLOBAL_BACK,
        (U16) 0,
        (S16)s_input_text_method,
        (U8*) s_input_text_buffer,
        s_input_text_buffer_length,
        history_buffer);

    SetLeftSoftkeyFunction(SFSystem_InputTextOption, KEY_EVENT_UP);
    
    SetKeyHandler(SFSystem_InputTextCancel, KEY_END, KEY_EVENT_DOWN);
    SetCategory5RightSoftkeyFunction(SFSystem_InputTextCancel, KEY_EVENT_UP);

    if(s_input_text_title)
    {
        MMI_title_string=(UI_string_type)s_input_text_title;
        draw_title();
    }
}

void SFSystem_InputText(UString aCaption,SFUint32 aFlags,UChar * aBuffer,SFSize_T aMaxLength,const char* aInputMode,SFReason* aNotifier)
{
    s_input_text_method=map_input_type(aFlags);
    if(s_input_text_method<0)
    {
        SFSystem_NotifyAllV(aNotifier,SFReasonBadParameter);
        return;
    }

    s_input_text_buffer=aBuffer;
    s_input_text_buffer_length=aMaxLength;
    s_input_text_result=aNotifier;
    if(aCaption)
    {
        sf_strncpy(s_input_text_title_buffer,aCaption,MAX_TITLE_LEN);
        s_input_text_title_buffer[MAX_TITLE_LEN]=0;
        s_input_text_title=s_input_text_title_buffer;
    }
    else
    {
        s_input_text_title=SFNull;
    }
    
    SFSystem_InputTextEntry();
    
}

void SFSystem_OpenBrowser(const char* aURL,SFUint32 aFlags,SFReason* aNotifier)
{
    int r=sf_wap_start_browsera(2,aURL);

    SFSystem_NotifyAllV(aNotifier,r<0?SFReasonFail:SFReasonOK);

}

void MakeCall(PS8 strNumber);

extern void SFSystem_OnMakeCall(const UChar* num);
extern void SFSystem_OnCallEventInternal(int v);

void SFSystem_OnCallEvent(int v)
{
#ifdef MMI_ON_HARDWARE_P
    kal_prompt_trace(SFCUST_TRACE_MOD,"on call event %d",v);
#endif //MMI_ON_HARDWARE_P
    SFSystem_OnCallEventInternal(v);
}

void SFSystem_MakeVoiceCall(UString aPhoneNumber,SFReason* aNotifier)
{
    SFSystem_OnMakeCall(aPhoneNumber);
    MakeCall((PS8)aPhoneNumber);

    SFSystem_NotifyAllV(aNotifier,SFReasonNoResult);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_chset_convert
 * DESCRIPTION
 *  Convert string between 2 character sets. (will add the terminate character)
 * PARAMETERS
 *  src_type        [IN]        Charset type of source
 *  dest_type       [IN]        Charset type of destination
 *  src_buff        [IN]        Buffer stores source string
 *  dest_buff       [OUT]       Buffer stores destination string
 *  dest_size       [IN]        Size of destination buffer (bytes)
 * RETURNS
 *  Length of destination string, including null terminator. (bytes)
 *****************************************************************************/
extern kal_int32 mmi_chset_convert(mmi_chset_enum src_type,mmi_chset_enum dest_type,
            char *src_buff,
            char *dest_buff,
            kal_int32 dest_size);



extern mmi_chset_enum g_chset_text_encoding;

static const struct s2v_lookup_tab ecoding_names[]=
{
#ifdef __MMI_CHSET_GB2312__
    {"gb2312",MMI_CHSET_GB2312},
  #ifndef __MMI_CHSET_GB18030__
    {"gbk",MMI_CHSET_GB2312},
  #endif //!__MMI_CHSET_GB18030__
#endif //__MMI_CHSET_GB2312__
#ifdef __MMI_CHSET_GB18030__
    {"gbk",MMI_CHSET_GB18030},
    {"gb18030",MMI_CHSET_GB18030},
#endif //__MMI_CHSET_GB18030__
#ifdef __MMI_CHSET_BIG5__
    {"big5",MMI_CHSET_BIG5},
#endif //__MMI_CHSET_BIG5__
    {"utf8",MMI_CHSET_UTF8},
    {"utf-8",MMI_CHSET_UTF8},
#ifdef __MMI_CHSET_UTF7__
    {"utf7",MMI_CHSET_UTF7},
    {"utf-7",MMI_CHSET_UTF7},
#endif //__MMI_CHSET_UTF7__
    {"ucs2",MMI_CHSET_UCS2},
    {"ucs-2",MMI_CHSET_UCS2}
};

static int encoding_from_name(const char* encoding)
{
    int i;
    if(!encoding || sf_astricmp(encoding,"default")==0 || strlen(encoding)==0)
    {
        return g_chset_text_encoding;
    }
    for(i=0;i<sizeof(ecoding_names)/sizeof(struct s2v_lookup_tab);i++)
    {
        if(sf_astricmp(ecoding_names[i].name,encoding)==0)
        {
            return ecoding_names[i].id;
        }
    }
    return -1;
}

SFInt SFSystem_MultiBytesToWideChars(UChar* dest,SFInt dest_len,const char* src,const char* encoding)
{
    int enc;
    if(!dest && dest_len!=0)
        return -1;
    enc=encoding_from_name(encoding);
    if(enc<0)
        return -1;
    return mmi_chset_convert((mmi_chset_enum)enc,MMI_CHSET_UCS2,(char*)src,(char *)dest,dest_len<<1)>>1;
}

SFInt SFSystem_WideCharsToMultiBytes(char* dest,SFInt dest_len,const UChar* src,const char* encoding)
{
    int enc;
    if(!dest && dest_len!=0)
        return -1;
    enc=encoding_from_name(encoding);
    if(enc<0)
        return -1;
    return mmi_chset_convert(MMI_CHSET_UCS2,(mmi_chset_enum)enc,(char*)src,(char *)dest,dest_len);
}





extern kal_uint8 custom_get_csd_profile_num(void);
extern kal_uint8 custom_get_gprs_profile_num(void);

static SFModule * s_get_nw_account_module=SFNull;
static SFReason * s_get_nw_account_reason=SFNull;


static SFReason CSFNetworkManager_GetActiveAccount(ISFNetworkManager*self,SFInt* pIdx)
{
#if defined(__MMI_GPRS_FEATURES__)
    *pIdx=g_kernal.iActiveModule->iNetworkAccountId-custom_get_csd_profile_num();
    return SFReasonOK;
#else
    return SFReasonNotSupported;
#endif
}
static SFReason CSFNetworkManager_SetActiveAccount(ISFNetworkManager*self,SFInt idx)
{
#if defined(__MMI_GPRS_FEATURES__)
    g_kernal.iActiveModule->iNetworkAccountId=idx+custom_get_csd_profile_num();
    return SFReasonOK;
#else
    return SFReasonNotSupported;
#endif  
}
static SFReason CSFNetworkManager_GetAccountCount(ISFNetworkManager*self,SFInt* account)
{
    if(!account || !self)
        return SFReasonBadParameter;
#if defined(__MMI_GPRS_FEATURES__)
    *account=custom_get_gprs_profile_num();
    sf_dbgprintf(L"APN count %d",*account);
    return SFReasonOK;
#else
    return SFReasonNotSupported;
#endif
}

static SFReason* s_get_Account_info_r=SFNull;
static SFReason* s_set_Account_info_r=SFNull;
static SFNetworkAccountInfo* s_get_Account_info=SFNull;

static void CSFNetworkManager_OnGetAccountInfo(void* ptr)
{
    mmi_ps_get_gprs_data_account_rsp_struct* rsp=(mmi_ps_get_gprs_data_account_rsp_struct*)ptr;
    SFDEBUG("ON ACI");
    if(s_get_Account_info_r)
    {
        SFReason * r=s_get_Account_info_r;
        s_get_Account_info_r=SFNull;
        //if(rsp->result)
        {
            //copy some thing
            sf_memcpy(s_get_Account_info->iUserName,rsp->gprs_account.user_name,32);
            sf_memcpy(s_get_Account_info->iUserPass,rsp->gprs_account.password,32);

            sf_memcpy(s_get_Account_info->iAPN,rsp->gprs_account.apn,sizeof(rsp->gprs_account.apn));
            s_get_Account_info->iAuthType=rsp->gprs_account.authentication_type;
            sf_memcpy(s_get_Account_info->iDNSIP,rsp->gprs_account.dns,4);

            AnsiiNToUnicodeString(
                (PS8)  s_get_Account_info->iAPN,
                (PS8) rsp->gprs_account.apn,
                (U32) rsp->gprs_account.apn_length);
            
            if (rsp->gprs_account.name_dcs == DATA_ACCOUNT_UCS)
            {
                int i = 0;

                if (rsp->gprs_account.name_length == 0)
                {
                    sf_strcpy(s_get_Account_info->iName,s_get_Account_info->iAPN);
    }
    else
    {
                    while (i != rsp->gprs_account.name_length)
                    {
                        ((kal_uint8*)s_get_Account_info->iName)[i] = rsp->gprs_account.name[i + 1];
                        ((kal_uint8*)s_get_Account_info->iName)[i + 1] = rsp->gprs_account.name[i];
                        i += 2;
                    }
                    ((kal_uint8*)s_get_Account_info->iName)[rsp->gprs_account.name_length] = 0x00;
                    ((kal_uint8*)s_get_Account_info->iName)[rsp->gprs_account.name_length + 1] = 0x00;
    }
            }
            else if (rsp->gprs_account.name_dcs == DATA_ACCOUNT_ASCII)
    {
                if (rsp->gprs_account.name_length == 0)
                {
                    sf_strcpy(s_get_Account_info->iName,s_get_Account_info->iAPN);
    }
    else
    {
                    AnsiiNToUnicodeString(
                        (PS8) s_get_Account_info->iName,
                        (PS8) rsp->gprs_account.name,
                        rsp->gprs_account.name_length);
    }
}

            SFSystem_NotifyAllV(r,SFReasonOK);
        }
        /*else
        {
            SFSystem_NotifyAllV(r,SFReasonError);
        }*/
    }
//#if defined(SFAPI_DEBUG_USE_PROTOCOL_EVENT)
    POST_EVENT_PROCESS()
//#endif //defined(SFAPI_DEBUG_USE_PROTOCOL_EVENT)
}

static void CSFNetworkManager_AGetAccountInfo(ISFNetworkManager*self,int idx,SFNetworkAccountInfo* pAccount,SFReason* aReason)
{
#if defined(__MMI_GPRS_FEATURES__)
    if(idx==-1)
    {
        //then use the module default
        idx=g_kernal.iActiveModule->iNetworkAccountId-custom_get_csd_profile_num();
    }
    //else
    //{
    //    idx+=custom_get_csd_profile_num();
    //}
    if(pAccount->iStructSize!=sizeof(SFNetworkAccountInfo))
    {
        SFSystem_NotifyAllV(aReason,SFReasonNotSupported);
    }
    else
    {
        mmi_ps_get_gprs_data_account_req_struct *myMsgPtr;

        MYQUEUE Message;

        *aReason=SFReasonPending;
        s_get_Account_info_r=aReason;
        s_get_Account_info=pAccount;
        //send the message
#if defined(SFAPI_DEBUG_USE_PROTOCOL_EVENT)
        SetProtocolEventHandler((PsFuncPtr)&CSFNetworkManager_OnGetAccountInfo,MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP);
#endif //defined(SFAPI_USE_PROTOCOL_EVENTS)
        myMsgPtr =
            (mmi_ps_get_gprs_data_account_req_struct*)
            OslConstructDataPtr(sizeof(mmi_ps_get_gprs_data_account_req_struct));

        myMsgPtr->profile_id = idx+1;

        Message.oslSrcId = MOD_MMI;
        Message.oslDestId = MOD_L4C;
        Message.oslMsgId = MSG_ID_MMI_PS_GET_GPRS_DATA_ACCOUNT_REQ;
        Message.oslDataPtr = (oslParaType*) myMsgPtr;
        Message.oslPeerBuffPtr = NULL;

        //SetProtocolEventHandler(DTCNTGPRSGetAccountRsp, PRT_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP);
        OslMsgSendExtQueue(&Message);
    }
#else
    SFSystem_NotifyAllV(aReason,SFReasonNotSupported);
#endif
}
static void CSFNetworkManager_ASetAccountInfo(ISFNetworkManager*self,int idx,const SFNetworkAccountInfo* pAccount,SFReason* aReason)
{
#if defined(__MMI_GPRS_FEATURES__)
    //mmi_ps_set_gprs_data_account_req_struct *myMsgPtr;

    //MYQUEUE Message;

    //if(idx==-1)
    //{
    //    //then use the module default
    //    idx=g_kernal.iActiveModule->iNetworkAccountId;
    //}
    //else
    //{
    //    idx+=custom_get_csd_profile_num();
    //}
    //if(pAccount->iStructSize!=sizeof(SFNetworkAccountInfo))
    //{
    //    SFSystem_NotifyAllV(aReason,SFReasonNotSupported);
    //}
    //else
    //{
    //    mmi_ps_set_gprs_data_account_req_struct *myMsgPtr;

    //    MYQUEUE Message;

    //    *aReason=SFReasonPending;
    //    s_set_Account_info_r=aReason;
    //    //send the message

    //    myMsgPtr =
    //        (mmi_ps_set_gprs_data_account_req_struct*)
    //        OslConstructDataPtr(sizeof(mmi_ps_set_gprs_data_account_req_struct));

    //    sf_memset(myMsgPtr,0,sizeof(mmi_ps_set_gprs_data_account_req_struct));
    //    myMsgPtr->gprs_account.name_dcs=;// = idx;
    //    myMsgPtr->gprs_account.context_id=;
    //    myMsgPtr->gprs_account.authentication_type=;
    //    myMsgPtr->gprs_account.password;
    //    myMsgPtr->gprs_account.name;
    //    sf_memcpy(myMsgPtr->gprs_account.dns,pAccount->iDNSIP,4);

    //    Message.oslSrcId = MOD_MMI;
    //    Message.oslDestId = MOD_L4C;
    //    Message.oslMsgId = PRT_MMI_PS_SET_GPRS_DATA_ACCOUNT_REQ;
    //    Message.oslDataPtr = (oslParaType*) myMsgPtr;
    //    Message.oslPeerBuffPtr = NULL;

    //    //SetProtocolEventHandler(DTCNTGPRSGetAccountRsp, PRT_MMI_PS_GET_GPRS_DATA_ACCOUNT_RSP);
    //    OslMsgSendExtQueue(&Message);

    //    
    //}
    SFSystem_NotifyAllV(aReason,SFReasonNotSupported);
#else
    SFSystem_NotifyAllV(aReason,SFReasonNotSupported);
#endif
}

#ifndef MTK_07B
static void SFApp_OnAppNetworkAccount(U16 index)
#else
static void SFApp_OnAppNetworkAccount(U32 index)
#endif
{
    SFReason* aNotifier=s_get_nw_account_reason;
    s_get_nw_account_reason=SFNull;
    //save the config
    if(s_get_nw_account_module)
    {
        s_get_nw_account_module->iNetworkAccountId=(SFUint8)index;
        s_get_nw_account_module=SFNull;
    }
    SFSystem_NotifyAllV(aNotifier,SFReasonOK);

    GoBackHistory();

    POST_EVENT_PROCESS()
}

static void CSFNetworkManager_SelectAccount(ISFNetworkManager*self,SFReason* pReason)
{
    if(pReason)
        *pReason=SFReasonPending;
    s_get_nw_account_module=g_kernal.iActiveModule;
    s_get_nw_account_reason=pReason;
    mmi_dtcnt_select_account_ext(&SFApp_OnAppNetworkAccount, SERVICES_WAP_MENU_ID, DATA_ACCOUNT_BEARER_GPRS,g_kernal.iActiveModule->iNetworkAccountId);
}

#if defined(WAP_SUPPORT)

static SFReason* s_WapProfileReason=SFNull;
static SFWapProfile* s_pProfile=SFNull;


static int SFSystem_HandleWapProfileContent(wap_get_prof_content_rsp_struct* profile)
{
    if(s_WapProfileReason)
    {
        SFReason *pReason=s_WapProfileReason;

        //copy the data
        //s_WapProfileGot=SFTrue;
        //s_WapProfile.iNetworkAccount=profile->net_id;
        s_pProfile->iNetworkAccount=profile->net_id-custom_get_csd_profile_num();
        memcpy(s_pProfile->iProxyIP,profile->prx_ip,4);
        s_pProfile->iProxyPort=profile->prx_port;
        s_pProfile->iType=profile->conn_type;
        memset(s_pProfile->iUserName,0,sizeof(s_pProfile->iUserName));
        memset(s_pProfile->iUserPass,0,sizeof(s_pProfile->iUserPass));
        memcpy(s_pProfile->iUserName,profile->username,sizeof(profile->username));
        memcpy(s_pProfile->iUserName,profile->password,sizeof(profile->password));

        s_WapProfileReason=SFNull;
        SFSystem_NotifyAllV(pReason,SFReasonOK);
        
        POST_EVENT_PROCESS()

        return 1;
    }
    return 0;
}

static int SFSystem_HandleWapProfile(wap_get_bra_prof_id_rsp_struct* profile)
{
    
    if(s_WapProfileReason)
    {
        MYQUEUE Message;

        wap_get_prof_content_req_struct *get_prof;

        get_prof = construct_local_para(sizeof(wap_get_prof_content_req_struct), TD_CTRL);
        get_prof->id = profile->prof_id;

        Message.oslSrcId = SFCUST_APP_MOD;
        Message.oslDestId = MOD_WAP;
        Message.oslMsgId = MSG_ID_WAP_GET_PROF_CONTENT_REQ;
        Message.oslDataPtr = (local_para_struct*) get_prof;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
        
        POST_EVENT_PROCESS()

        return 1;
    }
    return 0;//pass
}

#endif //defined(WAP_SUPPORT)

void CSFNetworkManager_AGetWapProfile(ISFNetworkManager*self,int idx,SFWapProfile* pProfile,SFReason* pReason)
{
#if defined(WAP_SUPPORT)
    if(idx==-1)
    {
        MYQUEUE Message;
        if(s_WapProfileReason)
        {
            *pReason=SFReasonExists;
            return;
        }
        s_pProfile=pProfile;
        s_WapProfileReason=pReason;
        
        Message.oslSrcId = SFCUST_APP_MOD;
        Message.oslDestId = MOD_WAP;
        Message.oslMsgId = MSG_ID_WAP_GET_BRA_PROF_ID_REQ;
        Message.oslDataPtr = NULL;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
    }
    else
    {
        MYQUEUE Message;

        wap_get_prof_content_req_struct *get_prof;

        if(s_WapProfileReason)
        {
            *pReason=SFReasonExists;
            return;
        }
        s_pProfile=pProfile;
        s_WapProfileReason=pReason;
        
        get_prof = construct_local_para(sizeof(wap_get_prof_content_req_struct), TD_CTRL);
        get_prof->id = idx;

        Message.oslSrcId = SFCUST_APP_MOD;
        Message.oslDestId = MOD_WAP;
        Message.oslMsgId = MSG_ID_WAP_GET_PROF_CONTENT_REQ;
        Message.oslDataPtr = (local_para_struct*) get_prof;
        Message.oslPeerBuffPtr = NULL;
        OslMsgSendExtQueue(&Message);
        *pReason=SFReasonPending;
    }
#else
    *pReason=SFReasonNotSupported;
#endif //defined(WAP_SUPPORT)
}


IMPLEMENT_SHARED_INTERFACE_BASIC_FUNCS(ISFNetworkManager,CSFNetworkManager_)

static struct ISFNetworkManager_classImpl
{
    //normal 
    DECLARE_INTERFACE_BASIC_FUNCS(ISFNetworkManager)

    SFReason (*GetActiveAccount)(ISFNetworkManager*self,SFInt* pIdx);
    SFReason (*SetActiveAccount)(ISFNetworkManager*self,SFInt idx);
    SFReason (*GetAccountCount)(ISFNetworkManager*self,SFInt* account);
    void (*AGetAccountInfo)(ISFNetworkManager*self,int idx,SFNetworkAccountInfo* pAccount,SFReason* aReason);
    void (*ASetAccountInfo)(ISFNetworkManager*self,int idx,const SFNetworkAccountInfo* pAccount,SFReason* aReason);
    void (*ASelectAccount)(ISFNetworkManager*self,SFReason* pReason);
    void (*AGetWapProfile)(ISFNetworkManager*self,int idx,SFWapProfile* pProfile,SFReason* pReason);
} s_ISFNetworkManager_class[]=
{{
    DEFINE_INTERFACE_BASIC_FUNCS(ISFNetworkManager,CSFNetworkManager_),
    CSFNetworkManager_GetActiveAccount,
    CSFNetworkManager_SetActiveAccount,
    CSFNetworkManager_GetAccountCount,
    CSFNetworkManager_AGetAccountInfo,
    CSFNetworkManager_ASetAccountInfo,
    CSFNetworkManager_SelectAccount,
    CSFNetworkManager_AGetWapProfile
}};

static ISFNetworkManager s_shared_nw_mgr={(ISFNetworkManager_class*)s_ISFNetworkManager_class};

static ISFNetworkManager* ISFNetworkManager_NewObject(void) { return &s_shared_nw_mgr; }


void SFApp_SelectNetworkAccount(SFReason* pReason)
{
    if(pReason)
        *pReason=SFReasonPending;
    s_get_nw_account_module=g_kernal.iActiveModule;
    s_get_nw_account_reason=pReason;
    mmi_dtcnt_select_account_ext(&SFApp_OnAppNetworkAccount, SERVICES_WAP_MENU_ID, DATA_ACCOUNT_BEARER_GPRS,g_kernal.iActiveModule->iNetworkAccountId);
}

#ifdef SFCUST_COMPACT_RAM
#define MAX_SYS_TIMERS2     16
#else
#define MAX_SYS_TIMERS2     32
#endif

typedef struct _ShellTimer
{
    struct _ShellTimer*next;
    struct _ShellTimer*prev;
    SF_FUNC_CALLBACK callback;
    void* user;
    int32 time;//time count down
    int32 base;
    SFModule* module;
} ShellTimer;

typedef struct _SFTimerSysImpl
{
    DEFINE_INTERFACE_VFTABLE(ISFTimer)

    ShellTimer _poolTimer[MAX_SYS_TIMERS2];
    ShellTimer* pFreeTimer;
    ShellTimer* pActiveTimer;
    int32 iCurrentTimerTime;
} SFTimerSysImpl;

static SFTimerSysImpl s_itimer;

static void SFSysTimer_Initialize(void)
{
    int i;
    ShellTimer* t;
    SFTimerSysImpl*pIShell=&s_itimer;
    pIShell->pFreeTimer=SFNull;
    pIShell->pActiveTimer=SFNull;
    pIShell->pFreeTimer=pIShell->_poolTimer;
    pIShell->iCurrentTimerTime=0;
    t=pIShell->pFreeTimer;
    for(i=1;i<MAX_SYS_TIMERS2;i++)
    {
        t->next=&pIShell->_poolTimer[i];
        t=&pIShell->_poolTimer[i];
    }
    t->next=NULL;
}

static void SFSysTimer_AddRef(SFTimerSysImpl* self)
{
    UNUSED_PARAM(self);
}
static int SFSysTimer_Release(SFTimerSysImpl* self)
{
    UNUSED_PARAM(self);
    //cannot release the system timer
    return 1;
}
static SFReason SFSysTimer_QueryInterface(SFTimerSysImpl* self,SFUint32 l,SFUint32 h,void**ptr)
{
    UNUSED_PARAM(l);
    UNUSED_PARAM(h);
    UNUSED_PARAM(ptr);
    return SFReasonNotSupported;
}
static SFReason SFSysTimer_SetParentTimer(SFTimerSysImpl*self,ISFTimer* parent)
{
    return SFReasonNotSupported;
}
static void SFSysTimer_TimerHook(void)
{
    SFTimerSysImpl* pIShell=&s_itimer;
    int32 t=(int32)SFOS32_GetCurrentTimeMillis();
    int32 dtime;//=t-pIShell->iPrevTime;
    int32 minTime=0x7FFFFFFF;
    ShellTimer* timer=pIShell->pActiveTimer;
    while(timer)
    {
        dtime=t-timer->base;
        timer->time-=dtime;
        if(timer->time>0 && timer->time<minTime)
        {
            minTime=timer->time;
        }
        timer->base+=dtime;
        //System_out_println(L"timer %p %d %d",timer,timer->time,dtime);
        timer=timer->next;

    }
    pIShell->iCurrentTimerTime=0;
    if(minTime<0x7FFFFFFF)
    {
        minTime+=5;
        if(minTime<20)
            minTime=20;
        gui_start_timer(minTime,&SFSysTimer_TimerHook);
        pIShell->iCurrentTimerTime=minTime;
    }
    //pIShell->iPrevTime=t;
    while(pIShell->pActiveTimer && pIShell->pActiveTimer->time<=0)
    {
        timer=pIShell->pActiveTimer;
        pIShell->pActiveTimer=pIShell->pActiveTimer->next;
        if(pIShell->pActiveTimer)
        {
            pIShell->pActiveTimer->prev=SFNull;
        }
        if(timer->callback)
            (*timer->callback)(timer->user);

        timer->next=pIShell->pFreeTimer;
        pIShell->pFreeTimer=timer;

    }
}

static SFReason SFSysTimer_SetTimer(SFTimerSysImpl*pIShell,SFInt32 dwMSecs,SF_FUNC_CALLBACK pfn,void* pUser)
{
    ShellTimer* tm=pIShell->pActiveTimer;
    //search for the same timer first
    while(tm)
    {
        if(tm->module==g_kernal.iActiveModule && (tm->callback==pfn && tm->user==pUser ))
        {
            tm->callback=pfn;
            tm->user=pUser;
            return SFReasonExists;
        }
        tm=tm->next;
    }
    //allocate a new timer object
    if(pIShell->pFreeTimer)
    {
        ShellTimer * tl,*ptl=SFNull;
        tm=pIShell->pFreeTimer;
        pIShell->pFreeTimer=pIShell->pFreeTimer->next;
        tm->callback=pfn;
        tm->user=pUser;
        tm->time=dwMSecs;
        tm->module=ACTIVE_MODULE;
        tm->base=(int32)SFOS32_GetCurrentTimeMillis();
        if(pIShell->iCurrentTimerTime==0 || (pIShell->iCurrentTimerTime>tm->time && pIShell->iCurrentTimerTime>20))
        {
            gui_cancel_timer(&SFSysTimer_TimerHook);
            pIShell->iCurrentTimerTime=tm->time;
            if(pIShell->iCurrentTimerTime<1)
                pIShell->iCurrentTimerTime=1;
            gui_start_timer(pIShell->iCurrentTimerTime,&SFSysTimer_TimerHook);
        }

        //insert to the timer list
        if(!pIShell->pActiveTimer)
        {
            pIShell->pActiveTimer=tm;
            tm->next=SFNull;
            tm->prev=SFNull;
        }
        else
        {
            tl=pIShell->pActiveTimer;
            while(tl && tm->time>tl->time){
                ptl=tl;
                tl=tl->next;
            }

            if(ptl==NULL)
            {
                //header
                pIShell->pActiveTimer=tm;
            }
            else
            {
                ptl->next=tm;
            }
            tm->prev=ptl;
            tm->next=tl;
            if(tl)
                tl->prev=tm;

        }
        return SFReasonOK;
    }
    return SFReasonOutOfResource;
}
static SFReason SFSysTimer_KillTimer(SFTimerSysImpl*pIShell,SF_FUNC_CALLBACK pfn,void* pUser)
{
    ShellTimer* tm=pIShell->pActiveTimer;
    while(tm)
    {
        if(tm->module==g_kernal.iActiveModule && tm->callback==pfn && tm->user==pUser)
        {
            //remove the timer
            if(tm==pIShell->pActiveTimer){
                pIShell->pActiveTimer=pIShell->pActiveTimer->next;
                tm->next=pIShell->pFreeTimer;
                tm->callback=SFNull;
                pIShell->pFreeTimer=tm;
                if(pIShell->pActiveTimer)
                    pIShell->pActiveTimer->prev=SFNull;
            }else{
                ShellTimer* tmn=tm->next;
                if(tmn)
                    tmn->prev=tm->prev;
                tm->prev->next=tmn;

                tm->next=pIShell->pFreeTimer;
                tm->callback=SFNull;
                pIShell->pFreeTimer=tm;
            }
            return SFReasonOK;
        }
        tm=tm->next;
    }
    return SFReasonNotFound;//not found
}

static void SFSysTimer_KillAllFor(SFTimerSysImpl*pIShell,SFModule* aModule)
{
    ShellTimer* tm=pIShell->pActiveTimer;
    SFDEBUG("SFSysTimer_KillAllFor");
    while(tm)
    {
        if(tm->module==aModule)
        {
            //remove the timer
            ShellTimer* tm_next=tm->next;
            if(tm==pIShell->pActiveTimer){
                pIShell->pActiveTimer=pIShell->pActiveTimer->next;
                tm->next=pIShell->pFreeTimer;
                tm->callback=SFNull;
                pIShell->pFreeTimer=tm;
                if(pIShell->pActiveTimer)
                    pIShell->pActiveTimer->prev=SFNull;
            }else{
                ShellTimer* tmn=tm->next;
                if(tmn)
                    tmn->prev=tm->prev;
                tm->prev->next=tmn;

                tm->next=pIShell->pFreeTimer;
                tm->callback=SFNull;
                pIShell->pFreeTimer=tm;
            }
            tm=tm_next;
            
        }
        else
        {
            tm=tm->next;
        }
    }
}

static SFReason SFSysTimer_KillAll(SFTimerSysImpl*self)
{
    //kill all of the curent module
    SFSysTimer_KillAllFor(self,g_kernal.iActiveModule);
    return SFReasonOK;
}

static const struct _ISFTimer_class
{
    void (*AddRef)(SFTimerSysImpl*self);
    int (*Release)(SFTimerSysImpl*self);
    SFReason (*QueryInterface)(SFTimerSysImpl* self,SFUint32 l,SFUint32 h,void**ptr);
    SFReason (*SetParentTimer)(SFTimerSysImpl*self,ISFTimer* parent);
    SFReason (*SetTimer)(SFTimerSysImpl*self,SFInt32 dwMSecs,SF_FUNC_CALLBACK pfn,void* pUser);
    SFReason (*KillTimer)(SFTimerSysImpl*self,SF_FUNC_CALLBACK pfn,void* pUser);
    SFReason (*KillAll)(SFTimerSysImpl*self);
} s_ISFTimer_class[]=
{{
    SFSysTimer_AddRef,
    SFSysTimer_Release,
    SFSysTimer_QueryInterface,
    SFSysTimer_SetParentTimer,
    SFSysTimer_SetTimer,
    SFSysTimer_KillTimer,
    SFSysTimer_KillAll
}};


static ISFTimer* ISFTimer_NewSystemTimer(void)
{
    s_itimer.__vftab=(ISFTimer_class*)s_ISFTimer_class;
    return (ISFTimer*)&s_itimer;
}

static void SFSysTimer0_KillAllFor(SFModule* aModule)
{
    SFSysTimer_KillAllFor(&s_itimer,aModule);
}

struct _apkfile;
struct _apkfile_class;

typedef struct _apkfile apkfile;
typedef struct _apkfile_class apkfile_class;

typedef struct _SFEModuleDataSection
{
    SFUint32 iOffset;
    SFUint32 iSize;
    //SFUint16 iNameOffset;
    //SFUint16 iNameLength;
} SFApkDataSection;


struct _apkfile
{
    const sf_vfs_file_class* __vftab;
    SFUint8 iFileNodeIdx;
    int nRefCount;
    int iLastError;
    const UChar* iPath;
    FS_HANDLE hFile;
    int iFileRefCount;
    int iMode;

    SFUint8 bLockHandle;
    SFUint8 iFlags;
    SFUint16 iFormat;
    SFUint16 iCompressMethod;
    SFUint32 iBlockSize;
    SFUint32 iBlockCount;
    SFUint32 iLastBlockSize;
    SFUint32 iBufPos;
    SFUint32 iPos;
    SFUint32 iContentLength;
    SFUint8* pFileBuf;
    SFUint32 iFileBufSize;
    SFUint32 iFileBufMaxSize;

    SFUint32 iCacheReadSize;
    SFUint16 iCacheBlock;
    SFUint32 iCacheBlockOffset;

    SFUint16* pBlockTable;

    SFUint16 iApkSectionCount;
    SFApkDataSection* iApkSection;
    
};


#ifdef SFCUST_COMPACT_RAM
#define MAX_SYS_APKFILES    2
#else //SFCUST_COMPACT_RAM
#define MAX_SYS_APKFILES    8
#endif //SFCUST_COMPACT_RAM
static apkfile s_apkfile_pool[MAX_SYS_APKFILES];
static apkfile* s_apkfile_freelist[1];
//the vfs file is opened from a sf_vfs_file object


#ifdef SFCUST_COMPACT_RAM
#define MAX_APK_SUB_FILES   32
#else //SFCUST_COMPACT_RAM
#define MAX_APK_SUB_FILES   256
#endif //SFCUST_COMPACT_RAM
static SFApkDataSection s_ApkCache[MAX_APK_SUB_FILES];
static void* s_ApkCacheObject=SFNull;

SFBool SFGetApkContentListCache(void* pObject,void**pBuf)
{
    *pBuf=s_ApkCache;
    if(s_ApkCacheObject==pObject)
        return SFTrue;
    s_ApkCacheObject=pObject;
    return SFFalse;
}

void SFReleaseApkContentListCache(void* pObject)
{
    if(s_ApkCacheObject==pObject)
    {
        s_ApkCacheObject=SFNull;
    }
}


enum
{
    InvalidBlock=-1,
    InvalidBufferPos=-1,
    FormatSingle=0,
    FormatMulti=1,
    CompressMethodNone=0,
    CompressMethodLZ=1,
    FlagIndividualCSize=1,

    DefaultFileBufferSize=8192
};

static SFReason apkfile_read_block_table(apkfile* papk)
{
    if(papk->iFormat==FormatMulti)
    {
        int i;
        UINT sz;
        if(FS_Seek(papk->hFile,8,FS_FILE_BEGIN)<0)
            return SFReasonError;
        //read the data
        FS_Read(papk->hFile,papk->pBlockTable,(papk->iBlockCount+1)*2,&sz);
        if(sz<(papk->iBlockCount+1)*2)
            return SFReasonError;
    }
    //now the file is built
    return SFReasonOK;
}

#define MAX_SHARED_BUFFER_SIZE  8192
static void* s_BufferOwner=SFNull;

#define MAX_TEMP_BUFFER_SIZE    8192
#define MAX_APK_BLOCKS  2048

static void* s_ApkBlockTableBufferOwner=SFNull;

#ifdef SFCUST_COMPACT_RAM
static SFUint32 *s_Buffer=SFNull;//[MAX_SHARED_BUFFER_SIZE/sizeof(SFUint32)];
static SFUint32 *s_TempBuffer=SFNull;//[MAX_TEMP_BUFFER_SIZE/sizeof(SFUint32)];
static SFUint16 *s_ApkBlockTableBuffer=SFNull;//[MAX_APK_BLOCKS];
static int s_WorkmemoryRefCount=0;

void SFAllocWorkMemory(void)
{
	if(s_Buffer)
	{
		++s_WorkmemoryRefCount;
		return;
	}
	s_Buffer=(SFUint32*) SFSystem_Alloc(MAX_SHARED_BUFFER_SIZE);
	s_TempBuffer=(SFUint32*) SFSystem_Alloc(MAX_TEMP_BUFFER_SIZE);
	s_ApkBlockTableBuffer=(SFUint16*) SFSystem_Alloc(MAX_APK_BLOCKS*2);
	s_WorkmemoryRefCount=1;

	SFDEBUG("Alloc Work Memory");
}
void SFFreeWorkMemory(void)
{
	if(s_Buffer)
		SFSystem_Free(s_Buffer);
	if(s_TempBuffer)
		SFSystem_Free(s_TempBuffer);
	if(s_ApkBlockTableBuffer)
		SFSystem_Free(s_ApkBlockTableBuffer);
	s_Buffer=SFNull;
	s_TempBuffer=SFNull;
	s_ApkBlockTableBuffer=SFNull;
	s_WorkmemoryRefCount=0;

	SFDEBUG("Free Work Memory");
}
void SFWorkMemory_AddRef(void)
{
	++s_WorkmemoryRefCount;
}
int SFWorkMemory_Release(void)
{
	--s_WorkmemoryRefCount;
	if(s_WorkmemoryRefCount<=0)
	{
		SFFreeWorkMemory();
		return 0;
	}
	return s_WorkmemoryRefCount;
}
#else
static SFUint32 s_Buffer[MAX_SHARED_BUFFER_SIZE/sizeof(SFUint32)];
static SFUint32 s_TempBuffer[MAX_TEMP_BUFFER_SIZE/sizeof(SFUint32)];
static SFUint16 s_ApkBlockTableBuffer[MAX_APK_BLOCKS];
#endif



static SFBool SFGetApkBlockTableBuffer(void* pOwner,SFUint16** ppBuffer)
    {
    *ppBuffer=s_ApkBlockTableBuffer;
    if(pOwner==s_ApkBlockTableBufferOwner)
        return SFTrue;
    else
        {
        s_ApkBlockTableBufferOwner=pOwner;
        return SFFalse;
        }
        }

static void SFReleaseApkBlockTableBuffer(void* pOwner)
        {
    if(pOwner==s_ApkBlockTableBufferOwner)
    {
        s_BufferOwner=SFNull;
        }
    }

static SFBool SFGetSharedBuffer(void* pOwner,void** ppBuffer)
    {
    *ppBuffer=s_Buffer;
    if(pOwner==s_BufferOwner)
        return SFTrue;
    else
    {
        s_BufferOwner=pOwner;
        return SFFalse;
    }
}

static void SFReleaseSharedBuffer(void* pOwner)
{
    if(pOwner==s_BufferOwner)
    {
        s_BufferOwner=SFNull;
    }
}

#if 1
SFReason apkfile_read_raw_data(apkfile*zins,void* buffer,SFUint32 offset,SFUint32 size)
{
    UINT sz;
    if(zins->hFile<0)
    {
        //open the file to read
        zins->hFile=FS_Open(zins->iPath,FS_READ_ONLY);
        if(zins->hFile<0)
            return SFReasonBadParameter;
    }
    if(FS_Seek(zins->hFile,(int)offset,FS_FILE_BEGIN)<0)
        return SFReasonError;
    FS_Read(zins->hFile,buffer,size,&sz);
    if(sz<size)
        return SFReasonError;
    return SFReasonOK;
}

extern SFInt LzDecompress (SFCBytePtr src, SFSize_T src_len, SFBytePtr dst, SFSize_T* dst_len );

SFReason apkfile_fetch_block(apkfile*zins,SFUint idxBlock)
{
    //__ASSERT_DEBUG(iFormat==FormatMulti,User::Invariant());
    SFUint iBlockInBuf=zins->iBufPos/zins->iBlockSize;
    SFReason r;
    //check buffer info
    if(zins->iBufPos==(SFUint32)InvalidBufferPos || idxBlock!=iBlockInBuf)
    {
        SFInt read_offset;
        SFInt read_size;
        SFSize_T len;
        SFInt size=(idxBlock==zins->iBlockCount-1)?zins->iLastBlockSize:zins->iBlockSize;
        //check if the block is compressed
        if(zins->iCompressMethod==CompressMethodNone)
        {
            //not compressed
            read_offset=10+idxBlock*zins->iBlockSize;
            read_size=zins->iBlockSize;
        }
        else
        {
            if(idxBlock==zins->iCacheBlock)
            {
                read_size=zins->iCacheReadSize;
                read_offset=zins->iCacheBlockOffset;
            }
            else
            {
            SFUint32 i;

                //prepare the block table
                if(!SFGetApkBlockTableBuffer(zins,&zins->pBlockTable))
                {
                    //reload the block table
                    if((r=apkfile_read_block_table(zins))!=SFReasonOK)
                    {
                        return r;
                    }
                }

                if(zins->iCacheBlock!=0xFFFF && zins->iCacheBlock<idxBlock)
                {
                    read_offset=zins->iCacheBlockOffset;
                    i=zins->iCacheBlock;
                }
                else
                {
                    i=0;
                    read_offset=10+sizeof(SFUint16)*zins->iBlockCount;
                }
                for(;i<idxBlock;i++)
            {
                SFUint32 sz=zins->pBlockTable[i];
                if(sz==0)
                    read_offset+=zins->iBlockSize;
                else
                    read_offset+=sz;
            }
                read_size=zins->pBlockTable[idxBlock];
            if(read_size==0)
                read_size=zins->iBlockSize;

                //cache
                zins->iCacheBlock=idxBlock;
                zins->iCacheReadSize=read_size;
                zins->iCacheBlockOffset=read_offset;
            }
            
        }
        //decompress the block
        len=(SFSize_T)size;
        if(zins->iCompressMethod!=CompressMethodNone)
        {
            if((SFUint32)read_size==zins->iBlockSize)
            {
                SFUint32 k;
                len=read_size;
                apkfile_read_raw_data(zins,zins->pFileBuf,read_offset,len);
            }
            else
            {
                apkfile_read_raw_data(zins,s_TempBuffer,read_offset,read_size);

                LzDecompress((SFCBytePtr)s_TempBuffer,read_size,(SFBytePtr)zins->pFileBuf,&len);
            }
        }
        else
        {
            apkfile_read_raw_data(zins,zins->pFileBuf,read_offset,len);
        }
        if(len!=(SFSize_T)size)
        {
            //YSM TODO !!!
            return SFReasonError;
        }
        zins->iFileBufSize=len;
        zins->iBufPos=idxBlock*zins->iBlockSize;
    }
    return SFReasonOK;
}

static int apkfile_read(apkfile* zins,void* aBuf,sf_vfs_size_t aLength,sf_vfs_size_t* rsz)
{
    SFSize_T req_length;
    SFByte*pBuffer;
    SFSize_T i;

    if(!zins)
    {
        return SFReasonError;
    }
    if(!(zins->iMode&SF_VFS_OPEN_READ))
    {
        zins->iLastError=SFReasonAccessDenied;
        return SFReasonAccessDenied;
    }

    //return sf_vfs_file_i_catch_error(fd,FS_Read(fd->hFile,buf,sz,(UINT*)rsz));


    
    pBuffer=(SFByte*)aBuf;
    if(aLength==0)
    {
        *rsz=0;
        return SFReasonOK;
    }

    if(aLength+zins->iPos>zins->iContentLength)
    {
        aLength=zins->iContentLength-zins->iPos;
    }
    req_length=aLength;
    if(zins->iFormat==FormatSingle && zins->iCompressMethod==CompressMethodNone)
    {
        apkfile_read_raw_data(zins,pBuffer,zins->iPos+8,aLength);
        zins->iPos+=aLength;
        *rsz=aLength;
        return SFReasonOK;
    }

    if(!SFGetSharedBuffer(zins,(void**)&zins->pFileBuf))
    {
        zins->iBufPos=(SFUint32)InvalidBufferPos;
    }

    //check iPos
    while(aLength>0)
    {
        if(zins->iBufPos!=InvalidBufferPos && zins->iPos>=zins->iBufPos && zins->iPos<zins->iBufPos+zins->iFileBufSize)
        {
            
            SFSize_T len=zins->iBufPos+zins->iFileBufSize-zins->iPos;
            if(len>aLength)
            {
                len=aLength;
            }
            //read
            sf_memcpy(pBuffer,zins->pFileBuf+(zins->iPos-zins->iBufPos),len);

            aLength-=len;
            pBuffer+=len;
            zins->iPos+=len;
        }
        else
        {
            //try to fill the buffer
            if(zins->iFormat==FormatSingle)
            {
                //__ASSERT_DEBUG(iCompressMethod==CompressMethodNone,User::Invariant());
                zins->iBufPos=zins->iPos;
                zins->iFileBufSize=zins->iFileBufMaxSize;
                if(zins->iBufPos+zins->iFileBufSize>zins->iContentLength)
                {
                    zins->iFileBufSize=zins->iContentLength-zins->iBufPos;
                }
                //TPtr8 ptr((TUint8*)pFileBuf,iFileBufSize);
                //User::LeaveIfError(iFile.Read(iBufPos+8,ptr));
                apkfile_read_raw_data(zins,zins->pFileBuf,zins->iBufPos+8,zins->iFileBufSize);
            }
            else //FormatMulti
            {
                //try to get a block
                SFUint block=zins->iPos/zins->iBlockSize;
                apkfile_fetch_block(zins,block);
            }
        }
    }
    *rsz=req_length;
    return SFReasonOK;
}

static int apkfile_getlasterror(apkfile* zins)
{
    return zins->iLastError;
}

static int apkfile_tell(apkfile* zins,sf_vfs_offset_t* poffset)
{
    *poffset=zins->iPos;
    return SFReasonOK;
}

static int apkfile_commit(apkfile* zins)
{
    return SFReasonNotSupported;
}

/**
* @brief 
*/
static int apkfile_chsize(apkfile* zins,sf_vfs_size_t sz)
{
    return SFReasonNotSupported;
}

/**
* @brief 
*/
static int apkfile_trunc(apkfile* zins)
{
    return SFReasonNotSupported;
}

/**
* @brief 
*/
static int apkfile_filelength(apkfile* zins,sf_vfs_size_t* psize)
{
    *psize=(sf_vfs_size_t)zins->iContentLength;
    return SFReasonOK;;
}

static int apkfile_eof(apkfile* zins)
{
    if(zins->iPos>=zins->iContentLength)
        return 1;
    else
        return 0;
}

static int apkfile_seek(apkfile* zins,sf_vfs_offset_t offset,int pos)
{
    if(pos==SEEK_SET)
    {
        pos=offset;
    }
    else if(pos==SEEK_END)
    {
        pos=zins->iContentLength+offset;
    }
    else if(pos==SEEK_CUR)
    {
        pos=zins->iPos+offset;
    }
    else
    {
        return SFReasonError;
    }
    if((SFUint32)pos>zins->iContentLength)
    {
        zins->iPos=zins->iContentLength;
    }
    else if(pos<0)
    {
        zins->iPos=0;
    }
    else
    {
        zins->iPos=pos;
    }
    return zins->iPos;
}


static int apkfile_write(apkfile* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz)
{
    return SFReasonNotSupported;
}

static void apkfile_AddRef(apkfile* self)
{
    ++self->nRefCount;
}
static int apkfile_Release(apkfile* self)
{
    --self->nRefCount;
    if(self->nRefCount==1 && !self->bLockHandle)
    {
        //close the hFile
        if(self->hFile>=0)
        {
            FS_Close(self->hFile);
            self->hFile=-1;
        }
        
    }
    else if(self->nRefCount<=0)
    {
        if(self->hFile>=0)
        {
            FS_Close(self->hFile);
            self->hFile=-1;
        }
        SFReleaseSharedBuffer(self);
        SFReleaseApkBlockTableBuffer(self);
        //free
        SFDEBUG("free apk");
        sf_slist_add_head((void**)s_apkfile_freelist,self);
        return 0;
    }
    return self->nRefCount;
}

static void apkfile_release_manifest_buffer(void* owner);

static int apkfile_close(apkfile* zins)
{
    if(zins->hFile>=0)
    {
        FS_Close(zins->hFile);
        zins->hFile=-1;
    }
    SFReleaseSharedBuffer(zins);
    SFReleaseApkBlockTableBuffer(zins);
    SFReleaseApkContentListCache(zins);
    apkfile_release_manifest_buffer(zins);

    zins->iFlags=0;
    zins->iFormat=0;
    zins->iCompressMethod=0;
    zins->iFileBufSize=0;
    zins->iBlockSize=0;
    zins->iBlockCount=0;
    zins->iLastBlockSize=0;
    //iBlockInBuf=(XSUInt32)InvalidBlock;
    zins->iBufPos=(SFUint32)InvalidBufferPos;
    zins->iPos=0;
    zins->iContentLength=0;
    apkfile_Release(zins);
    return SFReasonOK;
}

static SFReason apkfile_QueryInterface(apkfile* self,SFUint32 l,SFUint32 h,void**ptr)
{
    return SFReasonNotSupported;
}

struct _apkfile_class
{
    DECLARE_INTERFACE_BASIC_FUNCS(apkfile)

    int (*close)(apkfile* fd);
    int (*read)(apkfile* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz);
    int (*write)(apkfile* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz);
    int (*seek)(apkfile* fd,sf_vfs_offset_t offset,int orig);
    int (*commit)(apkfile* fd);
    int (*tell)(apkfile* fd,sf_vfs_offset_t* poffset);
    int (*chsize)(apkfile* fd,sf_vfs_size_t sz);
    int (*eof)(apkfile* fd);
    int (*trunc)(apkfile* fd);
    int (*getlasterror)(apkfile* fd);
    int (*filelength)(apkfile* fd,sf_vfs_size_t* psize);
};

static const apkfile_class s_apkfile_class[]=
{{
    apkfile_AddRef,
        apkfile_Release,
        apkfile_QueryInterface,
        //
        apkfile_close,
        apkfile_read,
        apkfile_write,
        apkfile_seek,
        apkfile_commit,
        apkfile_tell,
        apkfile_chsize,
        apkfile_eof,
        apkfile_trunc,
        apkfile_getlasterror,
        apkfile_filelength
}};

SFReason apkfile_close_native_handle(apkfile* apk,const UChar* path)
{
    if(apk->hFile>=0)
    {
        FS_Close(apk->hFile);
        apk->hFile=-1;
    }
    apk->iPath=path;
    return SFReasonOK;
}

SFReason apkfile_parse(apkfile* apk_file);

SFReason apkfile_open(const UChar* path,apkfile** ppFile)
{
    apkfile* papk;
    SFUint8 buf[12];
    FS_HANDLE hFile;
    UINT read_size=0;
    SFReason r;
    
    //read the file
    //this kind of file is read only at the moment
    //read the data from the stream

    hFile=FS_Open(path,FS_READ_ONLY);
    if(hFile<0)
    {
        SFDEBUG("apk -1");
        return SFReasonError;
    }
    FS_Read(hFile,buf,sizeof(buf),&read_size);
    if(read_size<12)
    {
        SFDEBUG("apk -2");
        return SFReasonError;
    }
    papk=(apkfile*)sf_slist_remove_head((void**)s_apkfile_freelist);
    if(!papk)
    {
        SFDEBUG("apk -3");
        return SFReasonOutOfResource;
    }
    papk->hFile=hFile;
    papk->iMode=SF_VFS_OPEN_READ;
    //copy the data
    sf_memcpy(&papk->iFormat,buf,2);
    sf_memcpy(&papk->iCompressMethod,buf+2,2);
    if(papk->iFormat==FormatSingle)
    {
        if(papk->iCompressMethod==CompressMethodLZ)
        {
            //
            sf_memcpy(&papk->iBlockSize,buf+4,4);
            sf_memcpy(&papk->iContentLength,buf+8,4);

            papk->iFileBufMaxSize=papk->iContentLength;

            if(papk->iBlockSize>MAX_SHARED_BUFFER_SIZE)
            {
                FS_Close(hFile);
                sf_slist_add_head((void**)s_apkfile_freelist,papk);

                SFDEBUG("apk -4");
                return SFReasonNotSupported;
            }
        }
        else if(papk->iCompressMethod==CompressMethodNone)
        {
            //
            sf_memcpy(&papk->iContentLength,buf+4,4);
            //papk->iContentLength=FileReadU32();
            if(papk->iContentLength<DefaultFileBufferSize)
            {
                //just use the buffer
                papk->iFileBufMaxSize=papk->iContentLength;
            }
            else
            {
                papk->iFileBufMaxSize=DefaultFileBufferSize;
            }
            papk->iFileBufSize=0;
        }
        else
        {
            FS_Close(hFile);
            sf_slist_add_head((void**)s_apkfile_freelist,papk);

            SFDEBUG("apk -5");
            return SFReasonError;
        }
    }
    else if(papk->iFormat==FormatMulti)
    {
        //
        papk->iBlockSize=256<<buf[4];
        papk->iFlags=buf[5];
        sf_memcpy(&papk->iBlockCount,buf+6,2);

        if(papk->iBlockSize>MAX_SHARED_BUFFER_SIZE)
        {
            FS_Close(hFile);
            sf_slist_add_head((void**)s_apkfile_freelist,papk);
            SFDEBUG("e pk block size");
            return SFReasonNotSupported;
        }
        if(papk->iBlockCount>MAX_APK_BLOCKS)
        {
            FS_Close(hFile);
            sf_slist_add_head((void**)s_apkfile_freelist,papk);
            SFDEBUG("e pk blocks");
            return SFReasonNotSupported;
        }
        SFGetApkBlockTableBuffer(papk,&papk->pBlockTable);
        //reload the block table
        if((r=apkfile_read_block_table(papk))!=SFReasonOK)
        {
            SFDEBUG("apk -6");
            return r;
        }
        papk->iLastBlockSize=papk->pBlockTable[papk->iBlockCount];
        if(papk->iLastBlockSize==0)
        {
            papk->iLastBlockSize=65536;
        }
        papk->iContentLength=(papk->iBlockCount-1)*papk->iBlockSize+papk->iLastBlockSize;
    }
    else
    {
        FS_Close(hFile);
        sf_slist_add_head((void**)s_apkfile_freelist,papk);

        SFDEBUG("apk -7");
        return SFReasonError;
    }
    
    papk->iCacheBlock=0xFFFF;//no cache
    papk->nRefCount=1;
    papk->bLockHandle=0;
    papk->__vftab=(const sf_vfs_file_class*)s_apkfile_class;

    if((r=apkfile_parse(papk))!=SFReasonOK)
    {
        FS_Close(hFile);
        sf_slist_add_head((void**)s_apkfile_freelist,papk);

        SFDEBUG("apk -8");
        return r;
    }
    *ppFile=papk;
    
    
    return SFReasonOK;
}

void apkfile_lock_native_handle(apkfile* fp)
{
    fp->bLockHandle=1;
}

void apkfile_unlock_native_handle(apkfile* fp)
{
    fp->bLockHandle=0;
}

struct _subfile;
struct _subfile_class;
typedef struct _subfile_class subfile_class;
typedef struct _subfile subfile;

struct _subfile
{
    const sf_vfs_file_class* __vftab;
    SFModule* iModule;
    sf_vfs_file* pFile;
    int nRefCount;
    sf_vfs_size_t iBase;
    sf_vfs_size_t iLength;
    sf_vfs_offset_t iPos;
    ISFMalloc* pMalloc;
};

#define MAX_SYS_SUBFILES    32
static subfile s_subfile_pool[MAX_SYS_SUBFILES];
static subfile* s_subfile_freelist[1];

static void FreeSubfilesForModule(SFModule* pMod)
{
    int i;
    for(i=0;i<MAX_SYS_SUBFILES;i++)
    {
        if(s_subfile_pool[i].iModule && 
            (s_subfile_pool[i].iModule==pMod||!pMod))
        {
            //close
            if(s_subfile_pool[i].pFile)
            {
                //free the file
                sf_vfs_file_release(s_subfile_pool[i].pFile);
                s_subfile_pool[i].pFile=SFNull;
            }
            s_subfile_pool[i].iModule=SFNull;
            SFDEBUG("free sub m");
            s_subfile_pool[i].iModule=SFNull;
            sf_slist_add_head((void**)s_subfile_freelist,&s_subfile_pool[i]);
        }
    }
}

static void InitInternalFilePool(void)
{
    sf_slist_empty((void**)s_subfile_freelist);
    sf_slist_add_head_array((void**)s_subfile_freelist,s_subfile_pool,sizeof(subfile),MAX_SYS_SUBFILES);

    sf_slist_empty((void**)s_apkfile_freelist);
    sf_slist_add_head_array((void**)s_apkfile_freelist,s_apkfile_pool,sizeof(apkfile),MAX_SYS_APKFILES);
}

struct _subfile_class
{
    DECLARE_INTERFACE_BASIC_FUNCS(subfile)

    int (*close)(subfile* fd);
    int (*read)(subfile* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz);
    int (*write)(subfile* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz);
    int (*seek)(subfile* fd,sf_vfs_offset_t offset,int orig);
    int (*commit)(subfile* fd);
    int (*tell)(subfile* fd,sf_vfs_offset_t* poffset);
    int (*chsize)(subfile* fd,sf_vfs_size_t sz);
    int (*eof)(subfile* fd);
    int (*trunc)(subfile* fd);
    int (*getlasterror)(subfile* fd);
    int (*filelength)(subfile* fd,sf_vfs_size_t* psize);
};


static void subfile_AddRef(subfile* fd)
{
    ++fd->nRefCount;
}
static int subfile_Release(subfile* fd)
{
    --fd->nRefCount;
    if(fd->nRefCount<=0)
    {
        //close
        if(fd->pFile)
        {
            sf_vfs_file_release(fd->pFile);
            fd->pFile=SFNull;
        }
        if(fd->pMalloc)
        {
            ISFMalloc_Free(fd->pMalloc,fd);
        }
        else
        {
            //free to pool
            SFDEBUG("free sub");
            fd->iModule=SFNull;
            sf_slist_add_head((void**)s_subfile_freelist,fd);
        }
        return 0;
    }
    return fd->nRefCount;
}
static SFReason subfile_QueryInterface(subfile* self,SFUint32 l,SFUint32 h,void**ptr)
{
    return SFReasonNotSupported;
}


static int subfile_close(subfile* fd)
{
    //release self
    if(fd->pFile)
    {
        sf_vfs_file_release(fd->pFile);
        fd->pFile=SFNull;
    }
    subfile_Release(fd);
    return SFReasonOK;
}

static int subfile_read(subfile* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz)
{
    //seek first and read
    int r=sf_vfs_file_seek(fd->pFile,fd->iPos+fd->iBase,SFFS_SEEK_SET);
    if(r<0)
        return r;
    if(fd->iPos+sz>fd->iLength)
    {
        sz=fd->iLength-fd->iPos;
        if(sz>0)
        {
            sf_vfs_size_t read_size;
            r=sf_vfs_file_read(fd->pFile,buf,sz,&read_size);
            if(r!=0)
                return r;
            fd->iPos+=read_size;
            *rsz=read_size;
            return 0;
        }
        else
        {
            *rsz=0;
            return SFReasonOK;
        }
    }
    else
    {
        sf_vfs_size_t read_size;
        r=sf_vfs_file_read(fd->pFile,buf,sz,&read_size);
        if(r!=0)
            return r;
        fd->iPos+=read_size;
        *rsz=read_size;
        return 0;
    }
}

static int subfile_write(subfile* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz)
{
    return SFReasonNotSupported;
}
static int subfile_seek(subfile* fd,sf_vfs_offset_t offset,int orig)
{
    //just change the position
    switch(orig)
    {
    case SFFS_SEEK_SET:
        if(offset<0 || offset>fd->iLength)
            return SFReasonBadParameter;
        fd->iPos=offset;
        break;
    case SFFS_SEEK_CUR:
        if(fd->iPos+offset<0 || fd->iPos+offset>fd->iLength)
            return SFReasonBadParameter;
        fd->iPos+=offset;
        break;
    case SFFS_SEEK_END:
        if(fd->iLength+offset<0 || fd->iLength+offset>fd->iLength)
            return SFReasonBadParameter;
        fd->iPos=fd->iLength+offset;
        break;
    default:
        return SFReasonBadParameter;
    }
    return fd->iPos;
}
static int subfile_commit(subfile* fd)
{
    return SFReasonNotSupported;
}
static int subfile_tell(subfile* fd,sf_vfs_offset_t* poffset)
{
    *poffset=fd->iPos;
    return SFReasonOK;
}
static int subfile_chsize(subfile* fd,sf_vfs_size_t sz)
{
    return SFReasonNotSupported;
}
static int subfile_eof(subfile* fd)
{
    return (fd->iPos>=fd->iLength)?SFTrue:SFFalse;
}
static int subfile_trunc(subfile* fd)
{
    return SFReasonNotSupported;
            }
static int subfile_getlasterror(subfile* fd)
{
    return sf_vfs_file_getlasterror(fd->pFile);
}
static int subfile_filelength(subfile* fd,sf_vfs_size_t* psize)
{
    *psize=fd->iLength;
    return SFReasonOK;
}

sf_vfs_file* sf_subfile_new(sf_vfs_file* parent,sf_vfs_offset_t offset,sf_vfs_size_t size)
{
    subfile* sub=sf_slist_remove_head((void**)s_subfile_freelist);
    static const subfile_class s_class[]=
    {{
        subfile_AddRef,
        subfile_Release,
        subfile_QueryInterface,

        subfile_close,
        subfile_read,
        subfile_write,
        subfile_seek,
        subfile_commit,
        subfile_tell,
        subfile_chsize,
        subfile_eof,
        subfile_trunc,
        subfile_getlasterror,
        subfile_filelength
    }};
    if(sub)
    {
        sub->__vftab=(const sf_vfs_file_class*)s_class;
        sub->iModule=ACTIVE_MODULE;
        sub->iBase=offset;
        sub->iLength=size;
        sub->iPos=0;
        sub->nRefCount=1;
        sub->pFile=parent;
        sf_vfs_file_addref(parent);
        sub->pMalloc=SFNull;
    }
    return (sf_vfs_file*)sub;
}



extern int sf_wparse_int(const UChar*buf,int length,int*val);


#define MAX_APK_PATH_LENGTH 512

SFReason sf_vfs_apk_open_file(apkfile* self,sf_vfs_string_t file,int mode,sf_vfs_file**pfile,int access);


//in current version one apk contains only one application
//

typedef struct _SFApkManifestItem
{
    SFUint16 iName;
    SFUint16 iValue;
} SFApkManifestItem;

#define APK_MANIFEST_MAX_ITEMS  64
typedef struct _SFApkManifest
{
    SFUint32 iCount;
    SFApkManifestItem iContent[APK_MANIFEST_MAX_ITEMS];
    char* pRawData;
    SFUint32 iRawLength;
} SFApkManifest;

//get the apk content buffer
#define APK_MANIFEST_FILE_SIZE  2048
#define APK_MANIFEST_BUFFER_SIZE    (2048+512)
static SFUint32 s_apk_manifest_buffer[APK_MANIFEST_BUFFER_SIZE/sizeof(SFUint32)];
static void* s_apk_manifest_owner=SFNull;
static SFApkManifest s_apk_manifest;


static int apkfile_get_manifest_buffer(void* owner,SFApkManifest** ppbuf)
{
    *ppbuf=&s_apk_manifest;
    s_apk_manifest.pRawData=(char*)s_apk_manifest_buffer;
    if(s_apk_manifest_owner==owner)
        return SFTrue;
    s_apk_manifest_owner=owner;
    return SFFalse;
}

static void apkfile_release_manifest_buffer(void* owner)
{
    if(owner==s_apk_manifest_owner)
    {
        s_apk_manifest_owner=SFNull;
    }
}

//SFReason sf_vfs_apk_open_file(apkfile* self,sf_vfs_string_t file,int mode,sf_vfs_file**pfile,int access);
#define APK_ACCESS_SECURITY 0
#define APK_ACCESS_MANIFEST 2
#define APK_ACCESS_FILELIST 1

typedef struct _SFStringC sf_cstring;
struct _SFStringC
{
    SFSize_T length;
    const char* cstring;
};

SFReason apkfile_read_manifest(apkfile* self,SFApkManifest* manifest)
{
    //read the file, manifest must be smaller than 2K
    sf_cstring cstr;
    sf_cstring cstr_line;
    sf_cstring cstr_name;
    sf_cstring cstr_value;int xx;
    sf_vfs_file* pfile;
    sf_vfs_size_t sz;
    if(sf_vfs_apk_open_file(self,L"",SF_VFS_OPEN_READ,&pfile,APK_ACCESS_MANIFEST)!=SFReasonOK)
        return SFReasonError;
    if(sf_vfs_file_filelength(pfile,&sz)!=SFReasonOK || sz>=APK_MANIFEST_FILE_SIZE)
    {
        sf_vfs_file_close(pfile);
        return SFReasonError;
    }
    //memset(manifest->pRawData,0,APK_MANIFEST_FILE_SIZE);
    if(sf_vfs_file_read(pfile,manifest->pRawData,APK_MANIFEST_FILE_SIZE,&manifest->iRawLength)!=SFReasonOK)
    {
        sf_vfs_file_close(pfile);
        return SFReasonError;
    }
    manifest->pRawData[manifest->iRawLength]=0;
    //parse the manifest
    sf_cstring_construct2(&cstr,manifest->pRawData,manifest->iRawLength);
    

    manifest->iCount=0;
    
    while(sf_cstring_get_line(&cstr,&cstr_line))
    {
        //parse the line
        if(cstr_line.length>2)
        {
            int name_len=sf_sub_astring(cstr_line.cstring,cstr_line.length,":");
            sf_cstring_construct2(&cstr_name,cstr_line.cstring,name_len);
            sf_cstring_trim(&cstr_name,SFNull);

            cstr_value.cstring=cstr_line.cstring+name_len+1;
            cstr_value.length=cstr_line.length-name_len-1;
            sf_cstring_trim(&cstr_value,SFNull);
            
            manifest->iContent[manifest->iCount].iName=(SFUint16)(cstr_name.cstring-manifest->pRawData);
            manifest->iContent[manifest->iCount].iValue=(SFUint16)(cstr_value.cstring-manifest->pRawData);
            
            ((char*)cstr_name.cstring)[cstr_name.length]=0;
            ((char*)cstr_value.cstring)[cstr_value.length]=0;
            
            manifest->iCount++;
            
        }
    }
    sf_vfs_file_close(pfile);
    return SFReasonOK;
}

SFReason SFSystem_ParseCLSID(const UChar* clsid,int len,SFCLSID* pCLSID)
{
    int i;
    int j;
    SFCLSID r=0;
    if(len<0)
        len=sf_strlen(clsid);
    if(len!=19 || *clsid!='{' || clsid[18]!='}' || clsid[9]!='-')
        return SFReasonError;
    for(j=0;j<2;j++)
    {
        for(i=0;i<8;i++)
        {
            int ch=clsid[1+i+j*9];
            if(ch>='0' && ch<='9')
            {
                ch-='0';
            }
            else if(ch>='a' && ch<='f')
            {
                ch=ch+10-'a';
            }
            else if(ch>='A' && ch<='F')
            {
                ch=ch+10-'A';
            }
            else
            {
                return SFReasonError;
            }
            r|=((SFCLSID)ch)<<((1-j)*32+(7-i)*4);
        }
    }
    *pCLSID=r;
    return SFReasonOK;
}

SFReason SFSystem_ParseCLSIDA(const char* clsid,int len,SFCLSID* pCLSID)
{
    int i;
    int j;
    SFCLSID r=0;
    if(len<0)
        len=strlen(clsid);
    if(len!=19 || *clsid!='{' || clsid[18]!='}' || clsid[9]!='-')
        return SFReasonError;
    for(j=0;j<2;j++)
    {
        for(i=0;i<8;i++)
        {
            int ch=clsid[1+i+j*9];
            if(ch>='0' && ch<='9')
            {
                ch-='0';
            }
            else if(ch>='a' && ch<='f')
            {
                ch=ch+10-'a';
            }
            else if(ch>='A' && ch<='F')
            {
                ch=ch+10-'A';
            }
            else
            {
                return SFReasonError;
            }
            r|=((SFCLSID)ch)<<((1-j)*32+(7-i)*4);
        }
    }
    *pCLSID=r;
    return SFReasonOK;
}



SFReason _apkfile_manifest_get(apkfile* self,const char* name,const char** value)
{
    int i;
    SFApkManifest* manifest;
    if(!apkfile_get_manifest_buffer(self,&manifest))
    {
        int r=apkfile_read_manifest(self,manifest);
        if(r!=SFReasonOK)
            return r;
    }

    for(i=0;i<manifest->iCount;i++)
    {
        const char* str=manifest->pRawData+manifest->iContent[i].iName;
        if(strcmp(str,name)==0)
        {
            *value=manifest->pRawData+manifest->iContent[i].iValue;
            return SFReasonOK;
        }
        }
    return SFReasonNotFound;
}

SFReason apkfile_manifest_get(apkfile* self,const char* name,const char** value)
{
    //try to get the local string
    int lang=SFSystem_GetLanguageId();
    const char* lang_str=SFSystem_GetLanguageNameA(lang);
    if(lang_str)
    {
        char buf[128];
        int r;
        sprintf(buf,"%s[%s]",name,lang_str);
        r=_apkfile_manifest_get(self,buf,value);
        if(r!=SFReasonNotFound)
            return r;
    }
    return _apkfile_manifest_get(self,name,value);
}


int sf_stricmp(UString str,UString pat);

SFReason sf_vfs_apk_open_file(apkfile* self,sf_vfs_string_t file,int mode,sf_vfs_file**pfile,int access)
{
    //SFEModuleImpl* self=(SFEModuleImpl*)_self;
    SFUint32 sz;

    //if(mode!=SF_VFS_OPEN_READ)
        //return SFReasonError;
    if(*file=='/')
        ++file;

    //fetch the offset table
    {
        int file_id=-1;
        if(!SFGetApkContentListCache(self,(void**)&self->iApkSection))
        {
            //fill the data
            sf_vfs_file_seek(self,16,SF_VFS_SEEK_SET);
            sf_vfs_file_read(self,self->iApkSection,self->iApkSectionCount*8,&sz);
        }
        if(access>=0)
        {
            file_id=access;
        }
        else if(*file==L':')
        {
            if(!sf_wparse_int(file+1,-1,&file_id))
                return SFReasonNotFound;
            //use the file index
            //but the entry 0 to 3 cannot be used directly, protected by the os
            //entry 0 is the security info, must not be null
            //entry 1 is the file descripter table, may be null
            //entry 2 is the manifest file, must not be null
            //entry 3 must be reserved
            //others are the resource sections, eg: icon
    }
        else if(self->iApkSectionCount>1 && self->iApkSection[APK_ACCESS_FILELIST].iSize>0)
        {
            
            int str_len;
            sf_vfs_file* fn_table;
            str_len=sf_strlen(file);
            //use the file path
            //search the file in FT
            
            fn_table=sf_subfile_new((sf_vfs_file*)self,self->iApkSection[APK_ACCESS_FILELIST].iOffset,self->iApkSection[APK_ACCESS_FILELIST].iSize);
            //deal with the file
            if(!fn_table)
            {
                return SFReasonNotFound;
            }
            else 
            {
                //get the table
                int idx=0;
                UChar* tab=sf_vfs_alloc_path_cache(MAX_APK_PATH_LENGTH);
                SFUint32 size=0;
                while(!sf_vfs_file_eof(fn_table))
                {
                    int j=size;
                    int base=0;
                    SFUint32 sz;
                    sf_vfs_file_read(fn_table,tab+size,(MAX_APK_PATH_LENGTH-size)*2,&sz);
                    size+=sz>>1;
                    for(;j<size;j++)
                    {
                        if(tab[j]==0)
                        {
                            //find the string
                            if(str_len==j-base && sf_stricmp(tab+base,file)==0)
                            {
                                //ok,break;
                                file_id=idx;
                                goto L_found_fid;
}
                            base=j+1;
                            ++idx;
                        }
                    }
                    //move the data
                    sf_memmove(tab,tab+base,size-base);
                    size-=base;
                }
L_found_fid:
                sf_vfs_free_path_cache(tab);
                sf_vfs_file_close(fn_table);
            }
        }
        if((file_id!=access && file_id<4) || file_id>=self->iApkSectionCount || self->iApkSection[file_id].iOffset==0)
        {
            return SFReasonNotFound;
        }
        //just use the entry
        //
        *pfile=sf_subfile_new((sf_vfs_file*)self,self->iApkSection[file_id].iOffset,self->iApkSection[file_id].iSize);
        if(!*pfile)
            return SFReasonOutOfResource;
        return SFReasonOK;
    }

}

#define APK_HDR_MAGIC   (('A')|('P'<<8)|('K'<<16)|(19<<24))

SFReason apkfile_parse(apkfile* apk_file)
{
    SFUint32 hdr[4];
    SFUint32 sz;
    //read the data
    //parse the file
    sf_vfs_file_read(apk_file,hdr,16,&sz);
    if(sz!=16)
    {
        SFDEBUG("apk -9");
        return SFReasonError;
    }
    if(hdr[0]!=APK_HDR_MAGIC || hdr[1]!=1 || hdr[2]!=0)
    {
        SFDEBUG("apk -10");
        sf_dbgprintf(L"%08x %08x %08x %08x",hdr[0],hdr[1],hdr[2],hdr[3]);
        return SFReasonError;
    }
    apk_file->iApkSectionCount=(SFUint16)hdr[3];
    return SFReasonOK;
}

#endif 
#endif 
