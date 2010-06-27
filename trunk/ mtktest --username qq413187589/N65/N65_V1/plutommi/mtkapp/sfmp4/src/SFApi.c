/* $Id: SFApi.c,v 1.2 2007/08/01 10:07:29 bw Exp $ */

#include "MMI_features.h"
#include "SFApi.h"
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
#include "med_utility.h"

#ifndef MMI_ON_HARDWARE_P
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#endif

#include "NVRAMType.h"
#include "NVRAMProt.h"
#include "NVRAMEnum.h"

#include "VdoPlyResDef.h"
#include "app_datetime.h"

#include "med_global.h" /*Added by bob, for game simulator, @20070724*/
#include "med_utility.h" /*Added by bob, for MP4, @20070720*/
#include "mdi_video.h" /*Added by bob, for MP4, @20070720*/


#ifdef MMI_ON_HARDWARE_P
void* malloc(unsigned int sz);
void free(void*ptr);
extern void *kal_sys_mem_alloc(kal_uint32 size);
extern void kal_sys_mem_free(void *mem_ptr);
extern kal_uint8 custom_get_csd_profile_num(void);
#endif

extern void* sf_system_malloc(kal_uint32 size);
extern void sf_system_free(void* ptr);
extern void* sf_system_malloc_fast(kal_uint32 size);
extern void sf_system_free_fast(void* ptr);

typedef struct _SFTimerInfo
{
	SFTIMER_ID iTimerId;
	ISFApplication* pHandler;
	SFInt iExpiredTime;
	SFBool bOnce;
} SFTimerInfo;

typedef struct _SFAppKernal
{
	SFTimerInfo iTimerInfo;
	ISFApplication* pApplication;
	SFBool bAppRunning;
	SFUint32 iKeyState;
	gdi_handle iGdiLayer;
	SFAnyPtr pHeap;
	SFBool bWavPlaying;
	SFBool bMidiPlaying;
#ifdef WIN32
	FILE*fpFile;
#else
	FS_HANDLE hFile;
#endif
} SFAppKernal;

void SFDEBUG(const char*str)
{
#ifdef MMI_ON_HARDWARE_P
//kal_prompt_trace(MOD_MMI,(char *)str);
#endif
}


#define SNOWFISH_APP_MEM_LENGTH (512*1024+256*1024)
//U8  SnowFishMemPool[SNOWFISH_APP_MEM_LENGTH] = {0};
static U16 u16_g_game_file_name[FMGR_PATH_BUFFER_SIZE/2];

kal_uint16 g_mtk_MOD_MMI=MOD_MMI;
#ifdef __MMI_GPRS_FEATURES__
kal_uint32 g_mtk_nwk_account_id;// = custom_get_csd_profile_num();
#else
kal_uint32 g_mtk_nwk_account_id = 0;
#endif

static SFBool g_bFirstTime=SFTrue;
static SFAppKernal g_kernal;
static BOOL g_bBgMusicOn = TRUE;
static BOOL g_bRotate90 = TRUE;


/*Output voice only through earphone when earphone plugged*/
extern U8 isEarphonePlugged;


extern U8 gactivatedprofile;

#if defined(__IMT_LCD_ROTATE_MMI__)
extern U8 gMMILcdRotateState;
#endif
/*****************************************************************************************************
  *inner function declaration
  ****************************************************************************************************/

void SFApp_Entry(void);
void game_select_account(void) ;
void mmi_game_prof_data_acct_callback(U16 index) ;
void mmi_game_prof_save_data_acct(void);
static void SFApp_KeyHandler(S32 aKey,S32 aKeyState);
void SFApp_FreeGDI(void);
void EntryRomList(void);


static SFBool SFApp_IsFirstTime(void)
{
	return g_bFirstTime;
}
static void SFApp_SetFirstTime(SFBool bFirstTime)
{
	g_bFirstTime=bFirstTime;
}

ISFApplication* SFGetApp(void)
{
	return g_kernal.pApplication;
}

/**
* @brief 关闭请求，不是用户方法
*/
void SFApp_Terminate(void)
{
	GoBackHistory();
}

/**
* @brief 表示应用主动要求退出，系统随后应该发送EVT_APP_DESTORY消息
*/
void SFApp_Exit(void)
{
	//send the destroy message first
	g_kernal.bAppRunning=SFFalse;
	SFApp_Terminate();
}


/**
* @brief 获取系统的屏幕缓冲区
* @return 屏幕缓冲区指针
*/
SFNColor* SFScreen_GetBuffer(void)
{
	U8*ptr;
	gdi_layer_get_buffer_ptr(&ptr);
	return (SFNColor*)ptr;
}


/**
* @brief 获取系统的屏幕宽度
* @return 屏幕宽度
*/
SFInt SFScreen_GetWidth(void)
{
	return SF_SCREEN_WIDTH;
}


/**
* @brief 获取系统的屏幕高度
* @return 屏幕高度
*/
SFInt SFScreen_GetHeight(void)
{
	return SF_SCREEN_HEIGHT;
}

/**
* @brief 把系统的屏幕缓冲区内容刷新到前台（实际屏幕）
*/
#if 1
void SFScreen_Update(void)
{
	START_LCD_TRANSFER;
	//gdi_layer_blt_previous(0, 0,LCD_WIDTH, LCD_HEIGHT);
}
#else
/*
方案二*/
void SFScreen_Update(void)
{
	gdi_layer_blt_previous(0, 0,LCD_WIDTH, LCD_HEIGHT);
}
#endif

SFInt SFFont_GetHeight(void)
{
	return (SFInt)gui_get_character_height();
}


SFInt SFFont_GetCharWidth(UNICHAR aChar)
{
	SFInt width=0,height=0;
	U8 buf[4]={0,0,0,0};
	buf[0]=(aChar)&0xff;
	buf[1]=((aChar>>8) & 0xff);
	
	gui_measure_string_n((UI_string_type)buf,1,&width,&height);
	return width;
}


SFInt SFFont_GetStringWidth(UString aStr,SFInt aLength)
{
 SFInt width=0,height=0,i;
 //TODO LATER : should be replaced
 if(aLength<0)
 {
  aLength=sf_strlen(aStr);
 }
 for(i=0;i<aLength;i++)
 {
  width+=SFFont_GetCharWidth(aStr[i]);
 }
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

void mmi_snowfish_profile_entry_app_screen(void)
{
   //game_select_account();
}

void mmi_snowfish_profile_highlight_app(void)
{
	SetLeftSoftkeyFunction(mmi_snowfish_profile_entry_app_screen,KEY_EVENT_UP);
	SetKeyHandler(mmi_snowfish_profile_entry_app_screen, KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
	SetKeyHandler(GoBackHistory,KEY_LEFT_ARROW,KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);

}

static void SFTimer_Callback(void)
{
	ISFApplication*pHandler=g_kernal.iTimerInfo.pHandler;
	SFLPARAM idTimer=(SFLPARAM)g_kernal.iTimerInfo.iTimerId;
	if(g_kernal.iTimerInfo.bOnce)
	{
		g_kernal.iTimerInfo.pHandler=SFNull;
		g_kernal.iTimerInfo.iTimerId=0;
		//gui_cancel_timer(SFTimer_Callback);
	}
	else
	{
		gui_start_timer(g_kernal.iTimerInfo.iExpiredTime,SFTimer_Callback);
	}
	//call the handler
	pHandler->pfnEvtHandler(pHandler,EVT_TIMER,idTimer,(SFWPARAM)0);
 
	//g_bRotate90 = (SFNesEmuApp_GetStatus() == NESEMU_STATUS_GAMER90);
}    

/**
* @brief 启动一个定时器
* @param idTimer - IN 定时器ID
* @param nExpiredTime - IN 以毫秒为单位的定时时间
* @param bOnceOrPeriod - IN YSTrue 表示定时器只有效一次，YSFalse 表示按指定间隔反复发出信号
*/
void SFTimer_Start(SFTIMER_ID idTimer,SFInt nExpiredTime,SFBool bOnce,ISFApplication*pHandler)
{
	g_kernal.iTimerInfo.bOnce=bOnce;
	g_kernal.iTimerInfo.iExpiredTime=nExpiredTime;
	g_kernal.iTimerInfo.iTimerId=idTimer;
	g_kernal.iTimerInfo.pHandler=pHandler;

	gui_start_timer(nExpiredTime,SFTimer_Callback);
}


/**
* @brief 停止指定的定时器
* @param idTimer - IN 定时器ID
*/
void SFTimer_Stop(SFTIMER_ID idTimer)
{
	if(g_kernal.iTimerInfo.iTimerId==idTimer)
	{
		gui_cancel_timer(SFTimer_Callback);
	}
}


/**
* @brief 获取游戏中可分配的连续空间首地址
* @return 取得的空间首地址
*/
SFAnyPtr SFSystem_GetHeap(void)
{
	return g_kernal.pHeap;
}

extern void InitSysStream(void);

void SFSystem_Initialize(void)
{
	g_kernal.bWavPlaying=SFFalse;
	g_kernal.bMidiPlaying=SFFalse;
//#ifdef WIN32
//	g_kernal.fpFile=SFNull;
//#else
#ifndef WIN32
//Huyanwei Add Macro Control
	g_kernal.hFile=0;
#endif
//#endif
	//静态分配内存的话请在这里返回那个空间的首地址。
	//g_kernal.pHeap=&SnowFishMemPool[0];
	//g_kernal.pHeap=sf_system_malloc(SNOWFISH_APP_MEM_LENGTH);
	InitSysStream();
	
}

void SFSystem_Finalize(void)
{
	if(g_kernal.bWavPlaying || g_kernal.bMidiPlaying)
		mdi_audio_stop_string();
	if(g_kernal.pHeap)
	{
		sf_system_free(g_kernal.pHeap);
		g_kernal.pHeap=SFNull;
	}
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

void SfKey0_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_0,KEY_EVENT_DOWN);
}

void SfKey0_UpHandler(void)
{
	SFApp_KeyHandler(KEY_0,KEY_EVENT_UP);
}


void SfKey1_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_1,KEY_EVENT_DOWN);
}

void SfKey1_UpHandler(void)
{
	SFApp_KeyHandler(KEY_1,KEY_EVENT_UP);
}

void SfKey2_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_2,KEY_EVENT_DOWN);
}

void SfKey2_UpHandler(void)
{
	SFApp_KeyHandler(KEY_2,KEY_EVENT_UP);
}



void SfKey3_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_3,KEY_EVENT_DOWN);
}

void SfKey3_UpHandler(void)
{
	SFApp_KeyHandler(KEY_3,KEY_EVENT_UP);
}


void SfKey4_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_4,KEY_EVENT_DOWN);
}

void SfKey4_UpHandler(void)
{
	SFApp_KeyHandler(KEY_4,KEY_EVENT_UP);
}


void SfKey5_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_5,KEY_EVENT_DOWN);
}

void SfKey5_UpHandler(void)
{
	SFApp_KeyHandler(KEY_5,KEY_EVENT_UP);
}

void SfKey6_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_6,KEY_EVENT_DOWN);
}

void SfKey6_UpHandler(void)
{
	SFApp_KeyHandler(KEY_6,KEY_EVENT_UP);
}

void SfKey7_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_7,KEY_EVENT_DOWN);
}

void SfKey7_UpHandler(void)
{
	SFApp_KeyHandler(KEY_7,KEY_EVENT_UP);
}


void SfKey8_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_8,KEY_EVENT_DOWN);
}

void SfKey8_UpHandler(void)
{
	SFApp_KeyHandler(KEY_8,KEY_EVENT_UP);
}



void SfKey9_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_9,KEY_EVENT_DOWN);
}

void SfKey9_UpHandler(void)
{
	SFApp_KeyHandler(KEY_9,KEY_EVENT_UP);
}

void SfKeyLSK_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_LSK,KEY_EVENT_DOWN);
}

void SfKeyLSK_UpHandler(void)
{
	SFApp_KeyHandler(KEY_LSK,KEY_EVENT_UP);
}


void SfKeyRSK_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_RSK,KEY_EVENT_DOWN);
}

void SfKeyRSK_UpHandler(void)
{
	SFApp_KeyHandler(KEY_RSK,KEY_EVENT_UP);
}


void SfKeyEnter_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_ENTER,KEY_EVENT_DOWN);
}

void SfKeyEnter_UpHandler(void)
{
	SFApp_KeyHandler(KEY_ENTER,KEY_EVENT_UP);
}
void SfKeyUpArrow_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_UP_ARROW,KEY_EVENT_DOWN);
}

void SfKeyUpArrow_UpHandler(void)
{
	SFApp_KeyHandler(KEY_UP_ARROW,KEY_EVENT_UP);
}

void SfKeyDownArrow_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_DOWN_ARROW,KEY_EVENT_DOWN);
}

void SfKeyDownArrow_UpHandler(void)
{
	SFApp_KeyHandler(KEY_DOWN_ARROW,KEY_EVENT_UP);
}

void SfKeyLeftArrow_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_LEFT_ARROW,KEY_EVENT_DOWN);
}

void SfKeyLeftArrow_UpHandler(void)
{
	SFApp_KeyHandler(KEY_LEFT_ARROW,KEY_EVENT_UP);
}

void SfKeyRightArrow_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_RIGHT_ARROW,KEY_EVENT_DOWN);
}

void SfKeyRightArrow_UpHandler(void)
{
	SFApp_KeyHandler(KEY_RIGHT_ARROW,KEY_EVENT_UP);
}



void SfKeyStar_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_STAR,KEY_EVENT_DOWN);
}

void SfKeyStar_UpHandler(void)
{
	SFApp_KeyHandler(KEY_STAR,KEY_EVENT_UP);
}


void SfKeyPound_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_POUND,KEY_EVENT_DOWN);
}

void SfKeyPound_UpHandler(void)
{
	SFApp_KeyHandler(KEY_POUND,KEY_EVENT_UP);
}

void SfKeyClear_DownHandler(void)
{
  	SFApp_KeyHandler(KEY_CLEAR,KEY_EVENT_DOWN);
}

void SfKeyClear_UpHandler(void)
{
	SFApp_KeyHandler(KEY_CLEAR,KEY_EVENT_UP);
}

void SfKeyEnd_DownHandler(void)
{
	SFApp_KeyHandler(KEY_END,KEY_EVENT_DOWN);
}

void SFAppRegistKeyHandler()
{
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
	
	SetKeyHandler(SfKeyEnd_DownHandler,KEY_END,KEY_EVENT_DOWN);
	
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
    //kal_prompt_trace(MOD_MMI,"SFApp_MapKeyCode get key ===========%d",aKey);
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
		default:
			return SFKEY_NONE;
			
			
	}
}

void SFApp_Leave(void);

static void SFApp_KeyHandler(S32 aKey,S32 aKeyState)
{
	ISFApplication*pApp=SFGetApp();
	//kal_prompt_trace(MOD_MMI,"SFApp_KeyHandler get akey========%d",aKey);
	//kal_prompt_trace(MOD_MMI,"SFApp_KeyHandler get aKeyState========%d",aKeyState);
	if(aKeyState==KEY_EVENT_DOWN)
	{
		if(aKey==KEY_END)
		{
			//close the app
			g_kernal.bAppRunning=SFFalse;
			//terminate request
			SFApp_Terminate();
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
		/*if(aKey==KEY_END)
		{
			//close the app
			g_kernal.bAppRunning=SFFalse;
			//terminate request
			SFApp_Terminate();

			SFApp_Leave();
			SFDEBUG("term req");
		}
		else*/
		{
			aKey=SFApp_MapKeyCode(aKey);
			if(aKey!=SFKEY_NONE)
			{
				g_kernal.iKeyState&=~(1<<aKey);
				//call the event handler
				pApp->pfnEvtHandler(pApp,EVT_KEYUP,(SFWPARAM)aKey,0);
			}
		}
	}
}

static void SFApp_PenMoveHandler(mmi_pen_point_struct pos)
{
	ISFApplication*pApp=SFGetApp();
	pApp->pfnEvtHandler(pApp,EVT_POINTER_DRAGGED,SFMAKE_POINT(pos.x,pos.y),0);
}
static void SFApp_PenPressHandler(mmi_pen_point_struct pos)
{
	ISFApplication*pApp=SFGetApp();
	pApp->pfnEvtHandler(pApp,EVT_POINTER_PRESSED,SFMAKE_POINT(pos.x,pos.y),0);
}
static void SFApp_PenReleaseHandler(mmi_pen_point_struct pos)
{
	ISFApplication*pApp=SFGetApp();
	pApp->pfnEvtHandler(pApp,EVT_POINTER_RELEASED,SFMAKE_POINT(pos.x,pos.y),0);
}

//static void SFApp_LoadGameSetting()
//{	
//	S16 error;
//#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
//
//	ReadValue(NVRAM_GFX_BACKGROUND_MUSIC_SETTING, &g_bBgMusicOn, DS_BYTE , &error);
//
//	/* if not init, init as ON */
//	if(g_bBgMusicOn == 0xff)
//	{
//		g_bBgMusicOn = TRUE;
//	}	
//#endif	
//}

static U32 g_myKeyState=0;

static void KeyHandler_ForA_Up(void)
{
	g_myKeyState&=~SFKS_NUM2;
}
static void KeyHandler_ForB_Up(void)
{
	g_myKeyState&=~SFKS_NUM1;
}
static void KeyHandler_ForSelect_Up(void)
{
	g_myKeyState&=~SFKS_NUM8;
}
static void KeyHandler_ForStart_Up(void)
{
	g_myKeyState&=~SFKS_NUM7;
}
static void KeyHandler_ForUp_Up(void)
{
	g_myKeyState&=~SFKS_UP;
}
static void KeyHandler_ForDown_Up(void)
{
	g_myKeyState&=~SFKS_DOWN;
}
static void KeyHandler_ForLeft_Up(void)
{
	g_myKeyState&=~SFKS_LEFT;
}
static void KeyHandler_ForRight_Up(void)
{
	g_myKeyState&=~SFKS_RIGHT;
}
static void KeyHandler_ForA_Down(void)
{
	g_myKeyState|=~SFKS_NUM2;
}
static void KeyHandler_ForB_Down(void)
{
	g_myKeyState|=~SFKS_NUM1;
}
static void KeyHandler_ForSelect_Down(void)
{
	g_myKeyState|=~SFKS_NUM8;
}
static void KeyHandler_ForStart_Down(void)
{
	g_myKeyState|=~SFKS_NUM7;
}
static void KeyHandler_ForUp_Down(void)
{
	g_myKeyState|=SFKS_UP;
}
static void KeyHandler_ForDown_Down(void)
{
	g_myKeyState|=SFKS_DOWN;
}
static void KeyHandler_ForLeft_Down(void)
{
	g_myKeyState|=SFKS_LEFT;
}
static void KeyHandler_ForRight_Down(void)
{
	g_myKeyState|=SFKS_RIGHT;
}
static void KeyHandler_ForSound_Up(void)
{
	g_myKeyState&=~SFKS_NUM9;
}
static void KeyHandler_ForSound_Down(void)
{
	g_myKeyState|=SFKS_NUM9;
}

/*//tylerWang
void SetupKeyHandlers(void)
{
	g_myKeyState=0;
	
	SetKeyHandler(KeyHandler_ForUp_Up,上的键值,KEY_EVENT_UP);
	SetKeyHandler(KeyHandler_ForDown_Up,下的键值,KEY_EVENT_UP);
	SetKeyHandler(KeyHandler_ForLeft_Up,左的键值,KEY_EVENT_UP);
	SetKeyHandler(KeyHandler_ForRight_Up,右的键值,KEY_EVENT_UP);
	
	SetKeyHandler(KeyHandler_ForUp_Down,上的键值,KEY_EVENT_DOWN);
	SetKeyHandler(KeyHandler_ForDown_Down,下的键值,KEY_EVENT_DOWN);
	SetKeyHandler(KeyHandler_ForLeft_Down,左的键值,KEY_EVENT_DOWN);
	SetKeyHandler(KeyHandler_ForRight_Down,右的键值,KEY_EVENT_DOWN);
	
	SetKeyHandler(KeyHandler_ForA_Up,A的键值,KEY_EVENT_UP);
	SetKeyHandler(KeyHandler_ForB_Up,B的键值,KEY_EVENT_UP);
	SetKeyHandler(KeyHandler_ForSelect_Up,SELECT的键值,KEY_EVENT_UP);
	SetKeyHandler(KeyHandler_ForStart_Up,START的键值,KEY_EVENT_UP);
	
	SetKeyHandler(KeyHandler_ForA_Down,A的键值,KEY_EVENT_DOWN);
	SetKeyHandler(KeyHandler_ForB_Down,B的键值,KEY_EVENT_DOWN);
	SetKeyHandler(KeyHandler_ForSelect_Down,SELECT的键值,KEY_EVENT_DOWN);
	SetKeyHandler(KeyHandler_ForStart_Down,START的键值,KEY_EVENT_DOWN);
	
	SetKeyHandler(KeyHandler_ForSound_Up,声音开关键值,KEY_EVENT_UP);
	SetKeyHandler(KeyHandler_ForSound_Down,声音开关键值,KEY_EVENT_DOWN);
	
	
}
*/

void SFApp_SetupHandlers(void)
{
	//clear key states
	g_kernal.iKeyState=0;
	ClearAllKeyHandler();
	SetKeyHandler(SfKeyEnd_DownHandler,KEY_END,KEY_EVENT_DOWN);
	SetKeyHandler(mmi_gfx_volume_up,	KEY_UP_ARROW, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_gfx_volume_down,	KEY_DOWN_ARROW, KEY_EVENT_DOWN);	
	mmi_pen_register_down_handler(SFApp_PenPressHandler);
	mmi_pen_register_move_handler(SFApp_PenMoveHandler);
	mmi_pen_register_up_handler(SFApp_PenReleaseHandler);
	
	//SetupKeyHandlers();
}

#if 0
void SFApp_SetupGDI(void)
{
	gdi_handle gdi_hdlr;
	lcd_power_up();
	entry_full_screen();

	gdi_layer_reset_clip();
	gdi_layer_get_base_handle(&gdi_hdlr);
	gdi_layer_set_blt_layer(gdi_hdlr,0,0,0);

	gdi_layer_set_active(gdi_hdlr);
	gdi_layer_clear(GDI_COLOR_BLACK);
		
	TurnOnBacklight(0);

	gdi_layer_blt_ext(GDI_LAYER_MAIN_BASE_LAYER_HANDLE, 0, 0, 0,
			#ifdef GDI_6_LAYERS
						0, 0,
			#endif
						0, 0, LCD_WIDTH-1, LCD_HEIGHT-1);	

    gdi_layer_lock_frame_buffer();

	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
/*
	gdi_handle gdi_hdlr;
	lcd_power_up();
	entry_full_screen();

	gdi_layer_reset_clip();
	gdi_layer_get_base_handle(&gdi_hdlr);
	gdi_layer_set_blt_layer(gdi_hdlr,0,0,0);

	gdi_layer_set_active(gdi_hdlr);
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
*/
}

/*
方案二*/
#else
void SFApp_SetupGDI(void)
{	gdi_handle gdi_hdlr;

#if 0	//forrest
	lcd_power_up();
#endif

	entry_full_screen();

	gdi_layer_reset_clip();
	gdi_layer_get_base_handle(&gdi_hdlr);
	gdi_layer_set_blt_layer(gdi_hdlr,0,0,0);
	gdi_layer_clear(GDI_COLOR_BLACK);    

	gdi_layer_set_active(gdi_hdlr);
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
}
#endif
#if 0
void SFApp_FreeGDI(void)
{
	gdi_layer_unlock_frame_buffer();
	lcd_power_down();

	TurnOffBacklight();

	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
/*
	lcd_power_down();

	TurnOffBacklight();

	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
*/
}
#else
/*
方案二*/
void SFApp_FreeGDI(void)
{
#if 0	//forrest
	lcd_power_down();
#endif 


	TurnOffBacklight();

	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
}
#endif

void SFApp_Leave(void);
void SFApp_Enter(void);

void EntrySFApp(PS8 filename, BOOL is_short)
{
	memset(u16_g_game_file_name,0x0,FMGR_PATH_BUFFER_SIZE);
	
	pfnUnicodeStrcpy((PS8)u16_g_game_file_name, filename);
	
	SFApp_Entry();
}

void game_simu_highlight(void)
{
	SetLeftSoftkeyFunction(EntryRomList, KEY_EVENT_UP);
	SetKeyHandler(EntryRomList, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	SetRightSoftkeyFunction(GoBackHistory,KEY_EVENT_UP);
	SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}

void GameSimuInit(void)
{
	//SetHiliteHandler(MENU_ID_FNG_GAME_SIMU, game_simu_highlight);
}

U8 mmi_game_simu_delete_history_hdlr( void* in_param )
{
	ISFApplication*pApp=SFGetApp();

	if(g_kernal.bAppRunning)
	{
		g_kernal.bAppRunning = SFFalse;
		
		pApp->pfnEvtHandler(pApp,EVT_APP_DESTROY,0,0);
		SFApp_SetFirstTime(SFTrue);

		SFSystem_Finalize();		
	}
}
	
void SFApp_Entry(void)
{
	//create the app first
	EntryNewScreen(SCR_ID_VDOPLY_STREAM_EDITOR,SFApp_Leave,SFApp_Entry,SFNull);
	SetDelScrnIDCallbackHandler( SCR_ID_VDOPLY_STREAM_EDITOR, (HistoryDelCBPtr)mmi_game_simu_delete_history_hdlr );
	
	/* stop bg music */
	mdi_audio_suspend_background_play();
	SFApp_SetupHandlers();
	SFApp_SetupGDI();
	//SFApp_LoadGameSetting();
	
	if(SFApp_IsFirstTime())
	{
		//do init
		SFApp_SetFirstTime(SFFalse);
		g_kernal.bAppRunning=SFTrue;
		
		SFSystem_Initialize();

		//g_kernal.pApplication=SFApp_Create(1);

		g_kernal.pApplication->pfnEvtHandler(g_kernal.pApplication,EVT_APP_START,0,0);
	}
	else
	{
		//resume
		ISFApplication*pApp=SFGetApp();
		pApp->pfnEvtHandler(pApp,EVT_APP_RESUME,0,0);
	}
}

void SFApp_Leave(void)
{
	ISFApplication*pApp=SFGetApp();
	if(!g_kernal.bAppRunning)
	{
		//destroy
		pApp->pfnEvtHandler(pApp,EVT_APP_DESTROY,0,0);
		SFApp_SetFirstTime(SFTrue);

		SFSystem_Finalize();
	}
	else
	{
		//pause
		pApp->pfnEvtHandler(pApp,EVT_APP_PAUSE,0,0);
		//gdi_layer_blt_previous(0, 0, UI_device_width-1, UI_device_height-1);
	}

	SFApp_FreeGDI();
		
	/* resume background audio */
	mdi_audio_resume_background_play();
}


/**
* @brief 获取游戏中可分配的连续空间大小
* @return 空间的大小
*/
SFSize_T SFSystem_GetHeapSize(void)
{
	return SNOWFISH_APP_MEM_LENGTH;
}

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
	if(!g_bBgMusicOn
		|| (MMI_PROFILE_SILENT == gactivatedprofile)
		|| (MMI_PROFILE_MEETING == gactivatedprofile))
	{
		return 0;
	}
	

//Output audio only through the earphone when earphone plugged
	if(isEarphonePlugged)
	{
		if(format==SNDFORMAT_MIDI)
		{
			if(g_kernal.bMidiPlaying)
				mdi_audio_stop_string();
			//PlayAudioMidiStream((U8*)pSndBuffer,(U16)uBufferSize,0);
			mdi_audio_play_string_with_vol_path(pSndBuffer,uBufferSize,MDI_FORMAT_SMF,nLoopCount==1?DEVICE_AUDIO_PLAY_ONCE:DEVICE_AUDIO_PLAY_INFINITE,SFNull,SFNull,255,MDI_DEVICE_SPEAKER2);
			g_kernal.bMidiPlaying=SFTrue;
			return 1;
		}
		else if(format==SNDFORMAT_WAVE)
		{
			if(g_kernal.bWavPlaying)
				mdi_audio_stop_string();
			//PlayAudioWavStream((U8*)pSndBuffer,(U16)uBufferSize,0);
			mdi_audio_play_string_with_vol_path(pSndBuffer,uBufferSize,MDI_FORMAT_WAV,nLoopCount==1?DEVICE_AUDIO_PLAY_ONCE:DEVICE_AUDIO_PLAY_INFINITE,SFNull,SFNull,255,MDI_DEVICE_SPEAKER2);
			g_kernal.bWavPlaying=SFTrue;
			return 2;
		}
	}
	else
     {
	if(format==SNDFORMAT_MIDI)
	{
		if(g_kernal.bMidiPlaying)
			mdi_audio_stop_string();
		mdi_audio_play_string_with_vol_path(pSndBuffer,uBufferSize,MDI_FORMAT_SMF,nLoopCount==1?DEVICE_AUDIO_PLAY_ONCE:DEVICE_AUDIO_PLAY_INFINITE,SFNull,SFNull,255,MDI_DEVICE_SPEAKER_BOTH);
		g_kernal.bMidiPlaying=SFTrue;
		return 1;
	}
	else if(format==SNDFORMAT_WAVE)
	{
		if(g_kernal.bWavPlaying)
			mdi_audio_stop_string();
		mdi_audio_play_string_with_vol_path(pSndBuffer,uBufferSize,MDI_FORMAT_WAV,nLoopCount==1?DEVICE_AUDIO_PLAY_ONCE:DEVICE_AUDIO_PLAY_INFINITE,SFNull,SFNull,255,MDI_DEVICE_SPEAKER_BOTH);
		g_kernal.bWavPlaying=SFTrue;
		return 2;
	}
     }
     return 0;
}
/**
* @brief 结束并关闭声音的播放
* @param idSnd - 播放声音ID
*/
void SFSnd_Stop(SFSND_ID idSnd)
{
	if(idSnd==1)
	{
		mdi_audio_stop_string();
	}
	else if(idSnd==2)
	{
		mdi_audio_stop_string();
	}
}


SFFS_HANDLE SFFS_Open(UString path,SFUint flags)
{
#ifdef WIN32
	g_kernal.fpFile=_wfopen(path,(flags&SFFSF_READ)?L"rb":L"wb");
	if(!g_kernal.fpFile)
		return 0;
	return 1;
#else
	//暂时关闭存档功能
	g_kernal.hFile=FS_Open(path,(flags&SFFSF_READ)?FS_READ_ONLY:(FS_READ_WRITE|FS_CREATE));
	if(g_kernal.hFile<0)//???
		return 0;
	return 1;
#endif
	
}

SFSize_T SFFS_Read(SFFS_HANDLE hFile,SFAnyPtr buf,SFSize_T sz)
{
#ifdef WIN32
	if(!g_kernal.fpFile)
		return (SFSize_T)0;
	return (SFSize_T)fread(buf,1,sz,g_kernal.fpFile);
#else
	UINT len=0;
	FS_Read(g_kernal.hFile,buf,(UINT)sz,&len);
	return (SFSize_T)len;
#endif
}

SFSize_T SFFS_Write(SFFS_HANDLE hFile,const SFAny* buf,SFSize_T sz)
{
#ifdef WIN32
	if(!g_kernal.fpFile)
		return (SFSize_T)0;
	return (SFSize_T)fwrite(buf,1,sz,g_kernal.fpFile);
#else
	UINT len=0;
	FS_Write(g_kernal.hFile,(void*)buf,(UINT)sz,&len);
	return (SFSize_T)len;
#endif
}

void SFFS_Close(SFFS_HANDLE hHandle)
{
#ifdef WIN32
	if(!g_kernal.fpFile)
		return;
	fclose(g_kernal.fpFile);
#else
	FS_Close(g_kernal.hFile);
#endif
}

SFBool SFFS_GetSize(SFFS_HANDLE hHandle,SFSize_T*pSz)
{
#ifdef WIN32
	long fsz=_filelength(g_kernal.fpFile->_file);
	if(fsz>=0)
	{
		*pSz=fsz;
		return SFTrue;
	}
	return SFFalse;
#else
	UINT sz=0;
	FS_GetFileSize(g_kernal.hFile,&sz);
	*pSz=sz;
	return  SFTrue;
#endif
}

void SFScreen_DrawTextN(UString str,SFInt length,SFInt x,SFInt y,SFUint32 cr)
{
	S32 str_w, str_h,str_size;
	SFInt i;
	SFInt cursor_x =x;
	color text_color;
	U8 buf[4]={0,0,0,0};
	

	text_color.alpha=((cr & 0xff00000)>>24) & 0xff;
	text_color.r=((cr & 0x00ff0000)>>16) & 0xff;
	text_color.g=((cr & 0x0000ff00)>>8) & 0xff;
	text_color.b=((cr & 0x000000ff)) & 0xff;
	
       gui_set_text_color(text_color);

	for(i=0;i<length;i++){
		gui_move_text_cursor(cursor_x,y);
		buf[0]=((str[i]) &  0xff);
		buf[1]=((str[i]>>8) & 0xff);
		gui_print_text((UI_string_type)buf);
		cursor_x+=SFFont_GetCharWidth(str[i]);
	}
}

extern void SFSms_Callback(unsigned char status);
SFSMS_ID SFSms_Send(const UChar*pNumber,const UChar *pContent)
{
#if 0
	int i;
	char buf[64];
	for(i=0;i<63;i++)
	{
		if(pNumber[i])
			buf[i]=(char)pNumber[i];
		else
			break;
	}
	buf[i]='\0';
	mmi_send_short_message(buf,(unsigned char*)pContent,1,SFSms_Callback);
	return 1;
#endif
}

SFBool SFSystem_HasSim(void)
{
	if(mmi_bootup_is_sim_valid())
	{
		return SFTrue;
	}
	else
	{
		return SFFalse;
	}
}


//Data_Account Interface
extern void DataAccountReadyCheck(FuncPtr ready_callback);
extern void GPRSAppDTCNTSelect( FuncPtrShort callback, U16 AppMenuID);
extern kal_uint8 custom_get_csd_profile_num();
//void game_select_account(void) 
//{ 
//
//
//#ifdef  __MMI_GPRS_FEATURES__     
//       GPRSAppDTCNTSelect(mmi_game_prof_data_acct_callback, MENU_ID_SNOWFISH_APP); 
//#else
//       AppDTCNTSelect(mmi_game_prof_data_acct_callback,MENU_ID_SNOWFISH_APP);
//#endif
//#endif/*remove end*/
//} 

void mmi_game_prof_data_acct_callback(U16 index) 
{ 
#ifdef  __MMI_GPRS_FEATURES__     
	g_mtk_nwk_account_id = (S32)(index+custom_get_csd_profile_num()); 
#else
	g_mtk_nwk_account_id = (S32)index; 
#endif
	mmi_game_prof_save_data_acct();
#ifdef MMI_ON_HARDWARE_P
       kal_prompt_trace(MOD_MMI,"mmi_game_prof_data_acct_callback get account is %d",g_mtk_nwk_account_id);
#endif

} 

/**
 * @brief 浏览并选择一个文件以供之后打开
 * @param aBuffer - 接受文件名的缓冲
 * @param aMaxSize - 缓冲以字符为单位的大小，含0结尾
 * @param abOpenFile - 是否是打开文件还是保存文件
 * @param aFilter - 过滤字符串，格式为"*.aaa;*.bbb"，如果为SFNull表示"*.*"
 * @param aReason - 异步调用的通知结果的存放地址，调用后应当设为SF_REASON_BUSY，然后在系统处理完后设置实际的处理结果，成功的话设为SF_REASON_OK
 * @remarks 这是一个异步调用，调用后将在之后控制权交还系统时离开本应用进入系统的打开界面，之后回到应用再设置结果。
 */
void SFSystem_SelectFile(UChar* aBuffer,SFSize_T aMaxSize,SFBool bOpenFile,const UChar* aFilter,SFReason* aReason)
{
	if(bOpenFile)
	{
		AnsiiToUnicodeString((S8 *)aBuffer,(S8 *)"d:\\demo.nes");
		* aReason = SF_REASON_OK;
	}
}

#define 	SF_SOUND_BUFFER_SIZE 		0x8000
static kal_uint8	u8_g_sound_buffer[SF_SOUND_BUFFER_SIZE];

#if defined(__MTK_TARGET__)
#pragma arm section code = "AUDIOAPICODE",rwdata = "AUDIOAPIRW", zidata = "AUDIOAPIZI"
#endif
static kal_uint8	u8_g_sound_playflag=0;		// 声音播放标志
static kal_uint8	*pu8_g_sound_bufstart;		// 声音数据缓冲区首地址
static kal_uint32	u32_g_sound_bufsize;		// 声音缓冲区大小
static kal_uint8	*pu8_g_sound_out_ptr;		// 声音播出指针
static kal_uint8	*pu8_g_sound_in_ptr;		// 声音写入指针


/**
* @brief 创建一个PCM播放设备
* @param aFormat - 必须为0
* @param aSamplesPerSec - 每秒的采样数
* @param aBit - 采样精度8/16
* @param aChannel - 声道
* @return 创建的声音设备
*/
SFPCMDevice device;
SFPCMDevice* SFPCMDevice_Create(SFInt aFormat,SFInt aSamplesPerSec,SFInt
aBit,SFInt aChannel)
{
	PARAM_UNUSED(aFormat);
	PARAM_UNUSED(aSamplesPerSec);
	PARAM_UNUSED(aChannel);
	return &device;
}

/**
* @brief 开始播放指定的设备
* @param aDevice - 播放的设备
*/
void SFPCMDevice_Start(SFPCMDevice* aDevice)
{
	PARAM_UNUSED(aDevice);

	if((MMI_PROFILE_SILENT == gactivatedprofile)
		|| (MMI_PROFILE_MEETING == gactivatedprofile))
	{
		return;
	}
	
	u8_g_sound_playflag = 1;
	pu8_g_sound_bufstart = (U8 *)u8_g_sound_buffer;
	u32_g_sound_bufsize = SF_SOUND_BUFFER_SIZE;
	pu8_g_sound_in_ptr = pu8_g_sound_out_ptr = pu8_g_sound_bufstart;

	memset(pu8_g_sound_bufstart,0x0,u32_g_sound_bufsize);
	
	mdi_audio_play_string(pu8_g_sound_bufstart, u32_g_sound_bufsize, 
		MDI_FORMAT_PCM_8K, DEVICE_AUDIO_PLAY_INFINITE, NULL, NULL);
}

/**
* @brief 停止声音播放
* @param aDevice - 播放的设备
*/
void SFPCMDevice_Stop(SFPCMDevice* aDevice)
{
	PARAM_UNUSED(aDevice);

	if((MMI_PROFILE_SILENT == gactivatedprofile)
		|| (MMI_PROFILE_MEETING == gactivatedprofile))
	{
		return;
	}
	
	u8_g_sound_playflag = 0;
	mdi_audio_stop_string();
}

/**
* @brief 关闭设备
* @param aDevice - 创建的声音设备
*/
void SFPCMDevice_Close(SFPCMDevice* aDevice)
{
	PARAM_UNUSED(aDevice);
	if(u8_g_sound_playflag == 1)
	{
		u8_g_sound_playflag = 0;
		mdi_audio_stop_string();
	}
	return;
}

#if defined(__MTK_TARGET__)
#pragma arm section code rwdata zidata
#endif

/**
* @brief 设置设备的音量
* @param aDevice - 创建的声音设备
* @param aVolume - 设置的音量
*/
void SFPCMDevice_SetVolume(SFPCMDevice* aDevice,SFInt aVolume)
{
	PARAM_UNUSED(aDevice);
	PARAM_UNUSED(aVolume);
}

/**
* @brief 获取设备的音量
* @param aDevice - 创建的声音设备
* @return 音量
*/
SFInt SFPCMDevice_GetVolume(SFPCMDevice* aDevice)
{
	PARAM_UNUSED(aDevice);
	return 0;
}

void mmi_game_prof_save_data_acct(void)
{
#if 0 
	DeleteUptoScrID(SCR_ID_SNOWFISH_APP);
	GoBackHistory();
#endif/*remove end*/
}

SFSize_T SFApp_GetCommandLine(UChar* aBuffer,SFSize_T aSize)
{	
	SFSize_T realSize;
	
	realSize = pfnUnicodeStrlen((S8 *)u16_g_game_file_name);

	if(realSize >= aSize)
	{
		realSize = aSize - 1;
	}

	if(realSize > 0)
	{
		pfnUnicodeStrncpy((PS8)aBuffer, (PS8)u16_g_game_file_name,realSize);
		aBuffer[realSize + 1] = 0x0;		
	}

	return realSize;
}

#define		KEY_REGISTER_TIME		0x80200230
#define		KEY_REGISTER_LOW		0x80110004
#define		KEY_REGISTER_MID		0x80110008
#define		KEY_REGISTER_HIG		0x8011000c
//up:0xFFFFFFFE	L
//sr:0xFFFFFFFD	L
//r:0xFFFFFFFB	L
//l:0xFFFFFFF7	L
//--:0xFFFFFFEF	L
//--:0xFFFFFFDF	L
//--:0xFFFFFFBF	L

//send:0xFFFFFF7F	L
//sl:0xFFFFFEFF	L
//menu:0xFFFFFDFF	L
//d:0xFFFFFBFF	L
//--0xFFFFF7FF	L
//--0xFFFFEFFF	L
//--0xFFFFDFFF	L

//VUP:0xFFFFBFFF	L
//STAR:0xFFFF7FFF	L
//N3:FFFE	M
//N2:FFFD M
//MP3_F:FFFB M
//--:FFF7 M
//--FFEF M

//VDOWN:FFDF M
//N0:FFBF M
//N6:FF7F M
//N5:FEFF M
//MP3_B:FDFF M
//--FBFF M
//--F7FF M

//EX1:EFFF M
//HASH:DFFF M
//N9:BFFF M
//N8:7FFF M
//--FFFE H
//--FFFD H
//--FFFB H

//--FFF7 H
//N1:FFEF H
//N4:FFDF H
//N7:FFBF H
//--:FF7F H
//--
//--


#define		KEY_PUB_LSK				0xdfff//KP_MID_KEY//0xFEFF L
#define		KEY_PUB_RSK				0xbfff//KP_MID_KEY//0xFFFD L
#define		KEY_PUB_LEFT			0xbfff//KP_LOW_KEY//0xFFF7 L
#define		KEY_PUB_RIGHT			0xffdf//KP_MID_KEY//0xFFFB L
#define		KEY_PUB_UP				0xfffe//KP_LOW_KEY//0xFFFE L
#define		KEY_PUB_DOWN			0xff7f//KP_LOW_KEY//0xFBFF L
#define		KEY_PUB_OK				0xefff //KP_MID_KEY//
#define		KEY_PUB_CALL			0x7fff//KP_MID_KEY//
#define		KEY_PUB_POUND			0xfeff //KP_MID_KEY
#define		KEY_PUB_0				0xff7f //KP_MID_KEY
#define		KEY_PUB_1				0xfffd//KP_LOW_KEY
#define		KEY_PUB_4				0xfeff//KP_LOW_KEY
#define		KEY_PUB_5				0xfdff//KP_LOW_KEY
#define		KEY_PUB_6				0xfbff//KP_LOW_KEY
#define		KEY_PUB_7				0x7fff//KP_LOW_KEY
#define		KEY_PUB_8				0xfffe//KP_MID_KEY
#define		KEY_PUB_STAR			0xffbf //KP_MID_KEY
#define		KEY_PUB_9				0xfffd//KP_MID_KEY
#define		KEY_PUB_2				0xfffb//KP_LOW_KEY
#define		KEY_PUB_3				0xfff7//KP_LOW_KEY
#define		KEY_PUB_ESC				0xffbf //KP_LOW_KEY
#define		KEY_PUB_VOLUP				0xf7ff//KP_LOW_KEY
#define		KEY_PUB_VOLDOWN			0xffef //KP_LOW_KEY

#define		REGISTER_PUB_LSK		KEY_REGISTER_MID
#define		REGISTER_PUB_RSK		KEY_REGISTER_MID
#define		REGISTER_PUB_LEFT		KEY_REGISTER_LOW
#define		REGISTER_PUB_RIGHT		KEY_REGISTER_MID
#define		REGISTER_PUB_UP			KEY_REGISTER_LOW
#define		REGISTER_PUB_DOWN		KEY_REGISTER_LOW
#define		REGISTER_PUB_OK			KEY_REGISTER_MID
#define		REGISTER_PUB_CALL		KEY_REGISTER_MID
#define		REGISTER_PUB_POUND		KEY_REGISTER_MID
#define		REGISTER_PUB_0			KEY_REGISTER_MID
#define		REGISTER_PUB_1			KEY_REGISTER_LOW
#define		REGISTER_PUB_4			KEY_REGISTER_LOW
#define		REGISTER_PUB_5			KEY_REGISTER_LOW
#define		REGISTER_PUB_6			KEY_REGISTER_LOW
#define		REGISTER_PUB_7			KEY_REGISTER_LOW
#define		REGISTER_PUB_8			KEY_REGISTER_MID
#define		REGISTER_PUB_STAR		KEY_REGISTER_MID
#define		REGISTER_PUB_9			KEY_REGISTER_MID
#define		REGISTER_PUB_2			KEY_REGISTER_LOW
#define		REGISTER_PUB_3			KEY_REGISTER_LOW
#define		REGISTER_PUB_ESC		KEY_REGISTER_LOW
#define		REGISTER_PUB_VOLUP		KEY_REGISTER_LOW
#define		REGISTER_PUB_VOLDOWN		KEY_REGISTER_LOW


SFUint32 SFSystem_GetKeyState(void)
{
	SFUint32 keyValue = 0;
			
	if(g_bRotate90
	    #if defined(__IMT_LCD_ROTATE_MMI__)
	    && !gMMILcdRotateState
	    #endif
	    )
	{
		if(!(DRV_Reg32(REGISTER_PUB_1)&(~KEY_PUB_1)))
		{
			keyValue |= SFKS_UP;
			keyValue |= SFKS_RIGHT;
		}
		if(!(DRV_Reg32(REGISTER_PUB_2)&(~KEY_PUB_2)))
		{
			keyValue |= SFKS_RIGHT;
		}
		if(!(DRV_Reg32(REGISTER_PUB_3)&(~KEY_PUB_3)))
		{
			keyValue |= SFKS_DOWN;
			keyValue |= SFKS_RIGHT;
		}
		if(!(DRV_Reg32(REGISTER_PUB_4)&(~KEY_PUB_4)))
		{
			keyValue |= SFKS_UP;
		}
		if(!(DRV_Reg32(REGISTER_PUB_6)&(~KEY_PUB_6)))
		{
			keyValue |= SFKS_DOWN;
		}
		if(!(DRV_Reg32(REGISTER_PUB_7)&(~KEY_PUB_7)))
		{
			keyValue |= SFKS_UP;
			keyValue |= SFKS_LEFT;
		}
		if(!(DRV_Reg32(REGISTER_PUB_8)&(~KEY_PUB_8)))
		{
			keyValue |= SFKS_LEFT;
		}
		if(!(DRV_Reg32(REGISTER_PUB_9)&(~KEY_PUB_9)))
		{
			keyValue |= SFKS_DOWN;
			keyValue |= SFKS_LEFT;
		}	
	}
	else
	{
		if(!(DRV_Reg32(REGISTER_PUB_1)&(~KEY_PUB_1)))
		{
			keyValue |= SFKS_UP;
			keyValue |= SFKS_LEFT;
		}
		if(!(DRV_Reg32(REGISTER_PUB_2)&(~KEY_PUB_2)))
		{
			keyValue |= SFKS_UP;
		}
		if(!(DRV_Reg32(REGISTER_PUB_3)&(~KEY_PUB_3)))
		{
			keyValue |= SFKS_UP;
			keyValue |= SFKS_RIGHT;
		}
		if(!(DRV_Reg32(REGISTER_PUB_4)&(~KEY_PUB_4)))
		{
			keyValue |= SFKS_LEFT;
		}
		if(!(DRV_Reg32(REGISTER_PUB_6)&(~KEY_PUB_6)))
		{
			keyValue |= SFKS_RIGHT;
		}
		if(!(DRV_Reg32(REGISTER_PUB_7)&(~KEY_PUB_7)))
		{
			keyValue |= SFKS_DOWN;
			keyValue |= SFKS_LEFT;
		}
		if(!(DRV_Reg32(REGISTER_PUB_8)&(~KEY_PUB_8)))
		{
			keyValue |= SFKS_DOWN;
		}
		if(!(DRV_Reg32(REGISTER_PUB_9)&(~KEY_PUB_9)))
		{
			keyValue |= SFKS_DOWN;
			keyValue |= SFKS_RIGHT;
		}
		
		if(!(DRV_Reg32(REGISTER_PUB_5)&(~KEY_PUB_5)))
		{
			keyValue |= SFKS_NUM7;
		}
		if(!(DRV_Reg32(REGISTER_PUB_POUND)&(~KEY_PUB_POUND)))
		{
			keyValue |= SFKS_NUM8;
		}		
	}

	if(!(DRV_Reg32(REGISTER_PUB_5)&(~KEY_PUB_5)))
	keyValue |= SFKS_NUM7;
	if(!(DRV_Reg32(REGISTER_PUB_POUND)&(~KEY_PUB_POUND)))
	keyValue |= SFKS_NUM8;
	if(!(DRV_Reg32(REGISTER_PUB_0)&(~KEY_PUB_0)))
	keyValue |= SFKS_NUM1;	
	if(!(DRV_Reg32(REGISTER_PUB_STAR)&(~KEY_PUB_STAR)))
	keyValue |= SFKS_NUM2;			
	if(!(DRV_Reg32(REGISTER_PUB_VOLDOWN)&(~KEY_PUB_VOLDOWN)))
	keyValue |= SFKS_NUM1;	
	if(!(DRV_Reg32(REGISTER_PUB_VOLUP)&(~KEY_PUB_VOLUP)))
	keyValue |= SFKS_NUM2;	
		
	if(!(DRV_Reg32(REGISTER_PUB_LEFT)&(~KEY_PUB_LEFT)))
	keyValue |= SFKS_NUM0;
	if(!(DRV_Reg32(REGISTER_PUB_RIGHT)&(~KEY_PUB_RIGHT)))
	keyValue |= SFKS_NUM9;		

	return keyValue;
	
}

void SFPCMDevice_GetCurrentPosition(SFPCMDevice* self,SFUint32*pPlayCursor,SFUint32* pWriteCursor)
{
	PARAM_UNUSED(self);
	if(pPlayCursor)
	{
		*pPlayCursor=(uint32)(pu8_g_sound_out_ptr-pu8_g_sound_bufstart);
	}
	
	if(pWriteCursor)
	{
		*pWriteCursor=(uint32)(pu8_g_sound_in_ptr-pu8_g_sound_bufstart);
	}	
}

void SFPCMDevice_LockBuffer(SFPCMDevice* self,SFUint32 offset,SFUint32 size,SFAny** pBuf0,SFUint32* pBufSize0,SFAny** pBuf1,SFUint32* pBufSize1)
{
	if(offset==0xFFFFFFFF)
	{
		SFPCMDevice_GetCurrentPosition(self,SFNull,&offset);
	}
	
	if(offset+size>SF_SOUND_BUFFER_SIZE)
	{
		*pBuf0=pu8_g_sound_bufstart+offset;
		*pBufSize0=SF_SOUND_BUFFER_SIZE-offset;

		*pBuf1=pu8_g_sound_bufstart;
		*pBufSize1=offset+size-SF_SOUND_BUFFER_SIZE;
	}
	else
	{
		*pBuf0=pu8_g_sound_bufstart+offset;
		*pBufSize0=size;

		*pBuf1=SFNull;
		*pBufSize1=0;
	}
}

void SFPCMDevice_UnlockBuffer(SFPCMDevice* self,SFAny* aBuf0,SFUint32
aBufSize0,SFAny* aBuf1,SFUint32 aBufSize1)
{
	//提交音频数据
	if(aBuf1 && aBufSize1)
	{
		pu8_g_sound_in_ptr=(SFUint8*)aBuf1+aBufSize1;
	}
	else
	{
		pu8_g_sound_in_ptr=(SFUint8*)aBuf0+aBufSize0;
	}

//提交_pSndCommitBegin到_pSndCommitEnd的数据，提交完毕让_pSndCommitBegin＝ _pSndCommitEnd

}
//
//const U8	*u8_g_game_dir=(U8 *)L"D:\\game\\";
//
//S32 mmi_gamesimu_create_file_dir(S8 *filepath)
//{
//    
//    S8 buf_createpath[128];
//    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
//    S32 fs_ret;
//    S32 str_len;
//    S32 cmp_ret;
//    S32 i;
//    FS_HANDLE file_handle;
//
//   
//    fs_ret = 0;
//
//    file_handle = FS_Open((kal_uint16*) filepath, FS_OPEN_DIR | FS_READ_ONLY);
//
//    /* path already exist */
//    if (file_handle >= 0)
//    {
//        FS_Close(file_handle);
//        return 0;   /* already exist, 0 means successful in file system */
//    }
//
//    /* create directory if it is not there */
//    pfnUnicodeStrcpy((PS8) buf_filepath, (PS8) filepath);
//
//    str_len = pfnUnicodeStrlen((PS8) buf_filepath);
//    str_len *= ENCODING_LENGTH;
//
//    /* skip drive. "C:\" */
//    for (i = 3 * ENCODING_LENGTH; i < str_len; i += 2)
//    {
//        cmp_ret = pfnUnicodeStrncmp((PS8) & buf_filepath[i], (PS8) L"\\", 1);
//        if (cmp_ret == 0)
//        {
//            /* create dir */
//
//            pfnUnicodeStrncpy((PS8) buf_createpath, (PS8) buf_filepath, i / ENCODING_LENGTH);
//            buf_createpath[i] = '\0';
//            buf_createpath[i + 1] = '\0';
//
//            fs_ret = FS_CreateDir((PU16) buf_createpath);
//
//            if (fs_ret < 0)
//            {
//                return fs_ret;
//            }
//        }
//    }
//
//    return fs_ret;
//}
/*
void mmi_gamesimu_exit_from_fmgr(void *filename, int is_short)
{
    
    //DeleteUptoScrID(SCREENID_GAMESIMU_LIST);
    DeleteNHistory(1);
    GoBackHistory();
}
*/
void EntryRomList(void)
{
#if 0
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE file_handle;
    FMGR_FILTER filter;
    S32 create_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   memset(buf_filepath,0x00,FMGR_PATH_BUFFER_SIZE);
   pfnUnicodeStrcpy((S8 *)buf_filepath,(const S8 *)u8_g_game_dir);

    #ifndef NAND_SUPPORT
    if(fmgr_is_msdc_present() == FALSE)
    {
          DisplayPopup((PU8)GetString(STR_GLOBAL_NOTIFY_NO_MEMORY_CARD), IMG_GLOBAL_EMPTY,0, 1000, EMPTY_LIST_TONE);
          return;
    }
    #endif

    EntryNewScreen(SCREENID_GAMESIMU_LIST, NULL, EntryRomList, NULL);

    create_result = mmi_gamesimu_create_file_dir(buf_filepath);

    /* check if it is valid path */
    file_handle = FS_Open((PU16) buf_filepath, FS_OPEN_DIR | FS_READ_ONLY);

    if (file_handle >= 0)
    {
        FS_Close(file_handle);

        FMGR_FILTER_INIT(&filter);
	
	FMGR_FILTER_SET(&filter,FMGR_TYPE_NES);

        mmi_fmgr_select_path_and_enter(
            APP_GAME_SIMU,
            FMGR_SELECT_BROWSE,
            filter,
            buf_filepath,
            (PsExtFuncPtr) mmi_gamesimu_exit_from_fmgr);

        /* check if device is busy or not */
        if (FS_GetDevStatus(buf_filepath[0], FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
        {
            /*  mmi_fmgr_select_path_and_enter will also add screen to histry */
            DeleteUptoScrID(SCREENID_GAMESIMU_LIST);

            /* Delete up to previous screen */
            DeleteNHistory(1);
        }
    }
    else
    {
        {
            /* storage is card */

            /* photo's path is not exist, and card is write protected, cant create photo folder */
            if (create_result == FS_WRITE_PROTECTION)
            {
                DisplayPopup(
                    (PU8) GetString(FMGR_FS_WRITE_PROTECTION_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            }
            else if (create_result == FS_DISK_FULL)
            {
                DisplayPopup(
                    (PU8) GetString(FMGR_FS_DISK_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            }
            else if (create_result == FS_ROOT_DIR_FULL)
            {
                DisplayPopup(
                    (PU8) GetString(FMGR_FS_ROOT_DIR_FULL_TEXT),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            }
            else
            {
                DisplayPopup(
                    (PU8) GetString(STR_GLOBAL_NOTIFY_NO_MEMORY_CARD),
                    IMG_GLOBAL_WARNING,
                    1,
                    ST_NOTIFYDURATION,
                    WARNING_TONE);
            }

            DeleteUptoScrID(SCREENID_GAMESIMU);
            return;

        }
    }
#endif
}


void* sf_system_malloc(kal_uint32 size)
{
	//todo
	return med_alloc_ext_mem(size);
}
void sf_system_free(void* ptr)
{
	//todo
	med_free_ext_mem(&ptr);
}

//STATIC
//U8 __fast_mem[40000];
//STATIC
void* sf_system_malloc_fast(kal_uint32 size)
{
	//TODO: 
	//return __fast_mem;
	return med_alloc_int_mem(size);
}
void sf_system_free_fast(void* ptr)
{
	//todo
	med_free_int_mem(&ptr);
}

//UNI@bw_0801_0001 带蓝牙的版本下面的函数被定义了，所有加上下面的控制
#ifndef  __BTMODULE_MT6601__
U32 OS_GetSystemTime(void)
{
   return  drv_get_current_time();
}   
#endif

static void LCDDisplay_adrs (const lcd_frame_update_struct *lcd_param, void* adrs, U8 layer)
{
	kal_uint16 w, h;
	lcd_frame_update_struct lcd_data = {0};

#if 0 //forrest
	lcd_power_up();
#endif


	w = lcd_param->lcm_end_x - lcd_param->lcm_start_x + 1;
	h = lcd_param->lcm_end_y - lcd_param->lcm_start_y + 1;

	if (layer == 0)
	{
		SET_LCD_LAYER0_WINDOW_SIZE(w,h);
		SET_LCD_LAYER0_WINDOW_OFFSET(0,0);
		SET_LCD_LAYER0_ROTATE(lcd_param->rotate_value);
		lcd_data.update_layer=LCD_LAYER0_ENABLE;

		REG_LCD_LAYER0_BUFF_ADDR = (kal_uint32) adrs;
		//START_LCD_TRANSFER;
		//lcd_power_down();
		//return;
	}
	else if (layer == 1)
	{
		SET_LCD_LAYER1_WINDOW_SIZE(w,h);
		SET_LCD_LAYER1_WINDOW_OFFSET(0,0);
		SET_LCD_LAYER1_ROTATE(lcd_param->rotate_value);
		lcd_data.update_layer=LCD_LAYER1_ENABLE;

		REG_LCD_LAYER1_BUFF_ADDR = (kal_uint32) adrs;
		//START_LCD_TRANSFER;
		//lcd_power_down();
		//return;
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
extern  lcd_frame_update_struct  lcd_data;

void SF_vdo_screen_update(const lcd_frame_update_struct *lcd_param_temp )
{
	U8 *buf_ptr;
	U8  layer_pos;
	
        lcd_frame_update_struct * lcd_param = &lcd_data;
	 
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
		//START_LCD_TRANSFER;
		//}}方案一
		
		//{{方案二
		gdi_layer_blt_previous(lcd_param->lcm_start_y, lcd_param->lcm_start_x, lcd_param->lcm_end_y, lcd_param->lcm_end_x);
		//}}方案二
	}
	else
	{
		LCDDisplay_adrs(lcd_param, buf_ptr, layer_pos);
	}
}
SFBool SFSystem_IsTouchSupported(void)
{
#ifdef __MMI_TOUCH_SCREEN__
	return SFTrue;
#else
    return SFFalse;
#endif //__MMI_TOUCH_SCREEN__
}

#include "SSCStringHandle.h"

extern const UChar g_strVMACRecordPath[]={0};
//#endif //__SF_MTK_APPLICATION_STOCK__ENABLE__
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;

int SFSystem_GetLanguageId(void)
{
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
}
