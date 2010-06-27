/* $Id: SFApi.h,v 1.1 2007/07/31 11:19:33 bw Exp $ */
/**
 * @file sfapi.h
 * @version 0.9.0
 * @author Myles Yu
 */

#ifndef __SNOWFISH_API__H__
#define __SNOWFISH_API__H__

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

//#define SF_SCREEN_WIDTH	240
//#define SF_SCREEN_HEIGHT	320

typedef unsigned short UNICHAR;

typedef const UNICHAR* UString;

typedef int SFInt;
typedef unsigned int SFUint;
typedef long SFInt32;
typedef unsigned long SFUint32;
typedef char SFInt8;
typedef unsigned char SFUint8;
typedef short SFInt16;
typedef unsigned short SFUint16;
typedef char SFChar;
typedef UNICHAR UChar;
typedef SFUint8 SFByte;
typedef SFByte* SFBytePtr;
typedef const SFByte* SFCBytePtr;

typedef SFInt32		int32;
typedef SFInt16		int16;
typedef SFInt8		int8;
typedef SFUint32	uint32;
typedef SFUint16	uint16;
typedef SFUint8		uint8;


typedef void SFVoid;
typedef void SFAny;
typedef void* SFAnyPtr;
typedef SFAnyPtr* SFAnyPtrPtr;

typedef SFUint32 SFSize_T;

#define SFNull	((void*)0)
#define SFNULL	((void*)0)

typedef unsigned int  SFLPARAM;
typedef unsigned int SFWPARAM;
typedef int SFEVT_ID;

typedef int SFBool;

typedef enum _SF_BOOLEAN
{
  SFTrue=1,
  SFFalse=0
} SF_BOOLEAN;

typedef SFUint16 SFNColor;


#define SFMAKE_PARAM(high,low) (((high&0xffff)<<16)|(low&0xffff))
#define SFGET_HIGH(v)  ((short)((v>>16)&0xffff))
#define SFGET_LOW(v) ((short)((v)&0xffff))

#define SFMAKE_POINT(x,y) SFMAKE_PARAM(x,y)
#define SFPOINT_X(p)  SFGET_HIGH(p)
#define SFPOINT_Y(p)  SFGET_LOW(p)

#define PARAM_UNUSED(x) (x)
//!定时器ID
typedef unsigned int SFTIMER_ID;
//!声音ID
typedef unsigned int SFSND_ID;
//!短消息ID
typedef unsigned int SFSMS_ID;

typedef struct tagISFApplication ISFApplication;

//!事件处理句柄,对于每一个消息都有一个事件ID(idEvent)和最多2个的关联的参数(lParam,wParam)
//以下关于事件一律写作 evt_id ( [param1 [,param2] ] )
//@param pApp - 系统维护的ISFApplication实例指针 (由系统调用SFApp_Create创建，到应用相应EVT_APP_DESTROY后指向的内容自动被清除)
//@param idEvent - 事件ID
//@param lParam - 事件的参数1
//@param wParam - 事件的参数2
typedef void (*SF_EVENT_HANDLER) (ISFApplication*pApp,SFEVT_ID idEvent,SFLPARAM lParam,SFWPARAM wParam);

typedef enum _SF_KEYCODE
{
	SFKEY_NONE=0,
	//左软键
	SFKEY_SL=1,
	//中软键
	SFKEY_SM,
	//右软键
	SFKEY_SR,

	SFKEY_UP,
	SFKEY_DOWN,
	SFKEY_LEFT,
	SFKEY_RIGHT,

	//数字键
	SFKEY_NUM0,
	SFKEY_NUM1,
	SFKEY_NUM2,
	SFKEY_NUM3,
	SFKEY_NUM4,
	SFKEY_NUM5,
	SFKEY_NUM6,
	SFKEY_NUM7,
	SFKEY_NUM8,
	SFKEY_NUM9,

	//井号
	SFKEY_POUND,
	//星号
	SFKEY_STAR,

	SFKEY_CLR,
	SFKEY_BACK
} SF_KEYCODE;

typedef enum _SF_SOCKET_STATUS
{
  SF_SOCK_STATUS_READY=0,
  SF_SOCK_STATUS_ERROR=1
} SF_SOCKET_STATUS;

typedef enum _SF_EVENT
{
  //EVT_APP_NONE()
  //@brief 空事件
  EVT_APP_NONE=0,
  //EVT_APP_START()
  //@brief 应用程序开始运行的信号
  EVT_APP_START,
  //EVT_APP_PAUSE()
  //@brief 应用程序暂停的信号
  EVT_APP_PAUSE,
  //EVT_APP_RESUME()
  //@brief 应用程序从暂停恢复的信号
  EVT_APP_RESUME,
  //EVT_APP_DESTROY()
  //@brief 应用程序关闭的信号
  EVT_APP_DESTROY,
  
  //EVT_KEYUP(SPLPARAM nKeyCode)
  //@brief
  //@param nKeyCode - 释放的按键的键值，见SF_KEYCODE
  EVT_KEYUP,
  //EVT_KEYDOWN(SPLPARAM nKeyCode)
  //@brief
  //@param nKeyCode - 按下的按键的键值，见SF_KEYCODE
  EVT_KEYDOWN,
  
  //EVT_POINTER_PRESSED(SPLPARAM ptPress)
  //@brief 触摸屏按下
  //@param ptPress - SFMAKE_POINT(x,y) 按下点的屏幕坐标
  EVT_POINTER_PRESSED,
  //EVT_POINTER_PRESSED(SPLPARAM ptRelease)
  //@brief 触摸屏释放
  //@param ptRelease - SFMAKE_POINT(x,y) 释放点的屏幕坐标
  EVT_POINTER_RELEASED,
  //EVT_POINTER_PRESSED(SPLPARAM ptDrag)
  //@brief 触摸屏拖动
  //@param ptDrag - SFMAKE_POINT(x,y) 拖动点的屏幕坐标
  EVT_POINTER_DRAGGED,
  
  //EVT_TIMER(SPLPARAM idTimer)
  //@brief 定时器到时
  //@param idTimer - SFTIMER_ID 到时的定时器ID
  EVT_TIMER,
  
  //EVT_SMS_SEND(SPLPARAM idSms,SFWPARAM nResult)
  //@brief 短消息发送结果
  //@param idSms - SFSMS_ID 之前取到的短消息发送ID
  //@param nResult - int 发送结果，1表示成功，0表示失败
  EVT_SMS_SEND,

  //EVT_SOCKET(SPLPARAM socket,SFWPARAM evt_err)
  //@brief socket消息
  //@param socket - SFSMS_ID 之前取到的短消息发送ID
  //@param evt_err - SFMAKE_PARAM(event,error);
  EVT_SOCKET,
  //EVT_SOCKET_STATUS(SPLPARAM idStatus)
  //@brief 网络系统状态
  //@param idStatus - SF_SOCK_STATUS_READY表示网络系统初始化，socket已经可以连接、SF_SOCK_STATUS_ERROR表示网络系统已出错关闭，需要重新初始化。
  EVT_SOCKET_STATUS
#ifdef WIN32
  ,EVT_MEM_PROFILE
#endif
} SF_EVENT;

//应用程序接口
struct tagISFApplication
{
  SF_EVENT_HANDLER pfnEvtHandler;
};

//这是我们提供实现的方法，但调用由你们这边调用，并需要保留返回值
/**
 * @brief 创建应用程序的需要系统维护的唯一实例
 * @param idGame - 游戏ID
 * @return 应用实例句柄
 */
ISFApplication* SFApp_Create(int idGame);
ISFApplication* SFAppTest_Create(int idGame);
/**
 * @brief 表示应用主动要求退出，系统随后应该发送EVT_APP_DESTORY消息
 */
void SFApp_Exit(void);

/**
 * @brief 获取系统的屏幕缓冲区
 * @return 屏幕缓冲区指针
 */
SFNColor* SFScreen_GetBuffer(void);

#ifdef WIN32
typedef struct HDC__* HDC;
HDC SFScreen_GetDC(void);
#endif //WIN32

/**
 * @brief 获取系统的屏幕宽度
 * @return 屏幕宽度
 */
SFInt SFScreen_GetWidth(void);

/**
 * @brief 获取系统的屏幕高度
 * @return 屏幕高度
 */
SFInt SFScreen_GetHeight(void);

/**
 * @brief 把系统的屏幕缓冲区内容刷新到前台（实际屏幕）
 */
void SFScreen_Update(void); 

/**
 * @brief 取得文字的逻辑高度，所有文字有统一的逻辑高度
 * @return 取得的逻辑高度
 */
SFInt SFFont_GetHeight(void);

/**
 * @brief 获取单个字符的宽度
 * @return 取得的宽度
 */
SFInt SFFont_GetCharWidth(UChar aChar);

/**
 * @brief 获取字符串的宽度
 * @return 取得的宽度
 */
SFInt SFFont_GetStringWidth(UString aStr,SFInt aLength);

/**
 * @brief 设置clipping区域，用于文字的clipping
 */
void SFScreen_SetClip(SFInt x,SFInt y,SFInt w,SFInt h);

/**
 * @brief 重置clipping区域
 */
void SFScreen_ResetClip(void);

/**
 * @brief 启动一个定时器
 * @param idTimer - IN 定时器ID
 * @param nExpiredTime - IN 以毫秒为单位的定时时间
 * @param bOnceOrPeriod - IN YSTrue 表示定时器只有效一次，YSFalse 表示按指定间隔反复发出信号
 */
void SFTimer_Start(SFTIMER_ID idTimer,int nExpiredTime,SFBool bOnce,ISFApplication*pHandler);

/**
 * @brief 停止指定的定时器
 * @param idTimer - IN 定时器ID
 */
void SFTimer_Stop(SFTIMER_ID idTimer);

/**
 * @brief 获取游戏中可分配的连续空间首地址
 * @return 取得的空间首地址
 */
SFAnyPtr SFSystem_GetHeap(void);
/**
 * @brief 获取游戏中可分配的连续空间大小
 * @return 空间的大小
 */
SFSize_T SFSystem_GetHeapSize(void);

typedef enum _SFSND_FORMAT
{
  SNDFORMAT_UNKNOWN=0,
  SNDFORMAT_MIDI=1,
  SNDFORMAT_WAVE=2
} SFSND_FORMAT;

/**
 * @brief 开始播放一个声音
 * @param pSndBuffer - 声音缓冲
 * @param uBufferSize - 声音缓冲大小
 * @param format - 声音数据格式
 * @param nLoopCount - 0表示循环播放，其他表示播放次数
 * @return 播放ID
 */
SFSND_ID SFSnd_Play(void*pSndBuffer,unsigned int uBufferSize,SFSND_FORMAT format,int nLoopCount);

/**
 * @brief 结束并关闭声音的播放
 * @param idSnd - 播放声音ID
 */
void SFSnd_Stop(SFSND_ID idSnd);

/**
 * @brief发送一条短消息
 * @param pNumber - 发送到的号码
 * @param pContent - 发送的内容
 * @return 发送的消息ID
 */
SFSMS_ID SFSms_Send(const UChar*pNumber,const UChar *pContent);

#ifdef WIN32
typedef struct _MemProfile MemProfile;
void SFMem_Profile(MemProfile*profile);
typedef struct _MemProfileEx MemProfileEx;
void SFMem_ProfileEx(MemProfileEx*profile);
#endif


typedef struct _SFDateTime
{
	SFInt nYear;
	SFInt nMonth;
	SFInt nDay;
	SFInt nHour;
	SFInt nMinute;
	SFInt nSecond;
	SFUint nMill;
} SFDateTime;

void SFSystem_GetCurrentDataTime(SFDateTime*pDataTime);

/**
* @brief 检查当前是否有SIM卡
* @return SFTrue 表示有SIM卡,SFFalse 表示没有
*/
SFBool SFSystem_HasSim(void);

/**
* @brief 检查当前平台是否支持触摸屏
* @return SFTrue 表示支持,SFFalse 表示不支持
*/
SFBool SFSystem_IsTouchSupported(void);

/**
 * @brief 绘制一行文字
 * @param str - 绘制的字符串，不要求0结尾
 * @param length - 以字符为单位的文字长度
 * @param x - 绘制的水平位置
 * @param y - 绘制的垂直位置
 * @param cr - 指定的RRGGBB颜色值
 */
void SFScreen_DrawTextN(UString str,SFInt length,SFInt x,SFInt y,SFUint32 cr);

//void SFSystem_Initialize(void);
//void SFSystem_Finalize(void);

//SFBool SFKey_IsPressed(SFInt aKeyCode);

typedef int SFFS_HANDLE;

enum SFFS_Flags
{
	SFFSF_CREATE=1,
	SFFSF_READ=2,
	SFFSF_WRITE=4
};

#define SFFS_INVALID_HANDLE	0

/**
 * @brief 打开一个文件
 * @param path - 文件路径
 * @param flags - 打开标志，参见::SFFS_Flags，可以是这些标志的或
 * @return 大开的文件句柄，如果打开失败返回SFFS_INVALID_HANDLE
 */
SFFS_HANDLE SFFS_Open(UString path,SFUint flags);

/**
 * @brief 对一个文件读取内容
 * @param hFile - 文件句柄
 * @param buf -接受数据的缓冲区的首地址
 * @param sz - 要读入的以字节为单位的大小
 * @return 实际读入的大小
 */
SFSize_T SFFS_Read(SFFS_HANDLE hFile,SFAnyPtr buf,SFSize_T sz);

/**
 * @brief 向一个文件写入内容
 * @param hFile - 文件句柄
 * @param buf - 写入的数据的首地址
 * @param sz - 写入的以字节为单位的大小
 * @return 实际写入的大小
 */
SFSize_T SFFS_Write(SFFS_HANDLE hFile,const SFAny*buf,SFSize_T sz);

/**
 * @brief 关闭一个打开的文件句柄
 * @param hHandle - 打开的文件句柄
 */
void SFFS_Close(SFFS_HANDLE hHandle);

/**
 * @brief 获取一个打开的文件的当前长度
 * @param hHandle - 打开的文件句柄
 * @return 成功或失败 
 */
SFBool SFFS_GetSize(SFFS_HANDLE hHandle,SFSize_T*pSz);


typedef SFInt32 SFReason;

enum SFReasons
{
	SF_REASON_OK=0,
	SF_REASON_FAIL=-1,
	SF_REASON_BUSY=-2,
	SF_REASON_CANCEL=-3,
	SF_REASON_NOTFOUND=-4
};

/**
 * @brief 浏览并选择一个文件以供之后打开
 * @param aBuffer - 接受文件名的缓冲
 * @param aMaxSize - 缓冲以字符为单位的大小，含0结尾
 * @param abOpenFile - 是否是打开文件还是保存文件
 * @param aFilter - 过滤字符串，格式为"*.aaa;*.bbb"，如果为SFNull表示"*.*"
 * @param aReason - 异步调用的通知结果的存放地址，调用后应当设为SF_REASON_BUSY，然后在系统处理完后设置实际的处理结果，成功的话设为SF_REASON_OK
 * @remarks 这是一个异步调用，调用后将在之后控制权交还系统时离开本应用进入系统的打开界面，之后回到应用再设置结果。
 */
void SFSystem_SelectFile(UChar* aBuffer,SFSize_T aMaxSize,SFBool bOpenFile,const UChar* aFilter,SFReason* aReason);


/**
 * @brief 调试用方法，用于打出调试信息
 */
void SFDEBUG(const char*str);

typedef struct _SFPCMDevice
{
	void * data;
}
SFPCMDevice;

/**
* @brief 声音设备结构，我这边只要指针，不需要知道其结构
*/
typedef struct _SFPCMDevice SFPCMDevice;

/**
* @brief 创建一个PCM播放设备
* @param aFormat - 必须为0
* @param aSamplesPerSec - 每秒的采样数
* @param aBit - 采样精度8/16
* @param aChannel - 声道
* @return 创建的声音设备
*/
SFPCMDevice* SFPCMDevice_Create(SFInt aFormat,SFInt aSamplesPerSec,SFInt
aBit,SFInt aChannel);

/**
* @brief 开始播放指定的设备
* @param aDevice - 播放的设备
*/
void SFPCMDevice_Start(SFPCMDevice* aDevice);

/**
* @brief 停止声音播放
* @param aDevice - 播放的设备
*/
void SFPCMDevice_Stop(SFPCMDevice* aDevice);

/**
* @brief 关闭设备
* @param aDevice - 创建的声音设备
*/
void SFPCMDevice_Close(SFPCMDevice* aDevice);

#define SF_MAX_VOLUME 32767
/**
* @brief 设置设备的音量
* @param aDevice - 创建的声音设备
* @param aVolume - 设置的音量
*/
void SFPCMDevice_SetVolume(SFPCMDevice* aDevice,SFInt aVolume);

/**
* @brief 获取设备的音量
* @param aDevice - 创建的声音设备
* @return 音量
*/
SFInt SFPCMDevice_GetVolume(SFPCMDevice* aDevice);

/**
* @brief 获取发给应用的额外命令，0结尾
* @param aBuffer - 用于获取额外字符串命令的缓冲
* @param aSize - 缓冲取的大小，以字符为单位
* @return 实际的大小，以字符为单位，不含0结尾
*/
SFSize_T SFApp_GetCommandLine(UChar* aBuffer,SFSize_T aSize);

/*
* @brief 获取当前的按键状态，每一位代表一个按键的状态，1标示按下，0标示松开。参见enum SFKeyStates
*/
SFUint32 SFSystem_GetKeyState(void);

enum SFKeyStates
{
	SFKS_UP=1,
	SFKS_DOWN=1<<1,
	SFKS_LEFT=1<<2,
	SFKS_RIGHT=1<<3,
	SFKS_NUM0=1<<4,
	SFKS_NUM1=1<<5,
	SFKS_NUM2=1<<6,
	SFKS_NUM3=1<<7,
	SFKS_NUM4=1<<8,
	SFKS_NUM5=1<<9,
	SFKS_NUM6=1<<10,
	SFKS_NUM7=1<<11,
	SFKS_NUM8=1<<12,
	SFKS_NUM9=1<<13,
	SFKS_POUND=1<<14,
	SFKS_STAR=1<<15,
	SFKS_SL=1<<16,
	SFKS_SM=1<<17,
	SFKS_SR=1<<18,
	SFKS_END=1<<19
};

/**
* @brief 获取一个可写的声音数据缓冲段
* @param aDevice - 创建的声音设备
* @param offset - 声音缓冲中的偏移，如果给0xFFFFFFFF则表示要当前写入位置
（之前提交的数据的末尾），模拟器中仅使用0xFFFFFFFF
* @param size - 要获取的声音缓冲的大小
* @param pBuf0 - 获取的缓冲第一段
* @param pBUfSize0 - 获取的缓冲第一段的大小
* @param pBuf1 - 获取的缓冲第二段，如果没有或者实现中不出现第二段缓冲这
种情况则给SFNull
* @param pBUfSize1 - 获取的缓冲第二段的大小，如果没有则给0
* @remarks 这是一个循环播放的缓冲，所以如果到达缓冲的末尾可能会出现连续
空间不够的情况，
* 那么除了这个空间，就需要额外给出位于缓冲起始的空间，所以就需要两组参数，
* 参见DirectX中的DirectSound中IDirectSoundBuffer
*/
void SFPCMDevice_LockBuffer(SFPCMDevice* aDevice,SFUint32
offset,SFUint32 size,SFAny** pBuf0,SFUint32* pBufSize0,SFAny**
pBuf1,SFUint32* pBufSize1);

/**
* @brief 提交之前获得的缓冲数据
* @param aDevice - 创建的声音设备
* @param aBuf0 - 之前获取的缓冲第一段
* @param aBUfSize0 - 实际要提交的缓冲第一段的长度
* @param aBuf1 - 之前获取的缓冲第二段，如果没有则给SFNull
* @param aBUfSize1 - 实际要提交的缓冲第一段的长度
*/
void SFPCMDevice_UnlockBuffer(SFPCMDevice* aDevice,SFAny* aBuf0,SFUint32
aBufSize0,SFAny* aBuf1,SFUint32 aBufSize1);

enum
{
	NESEMU_STATUS_NONE=0, //!< 其它状态
	NESEMU_STATUS_GAME=1, //!< 游戏中，正常屏幕
	NESEMU_STATUS_GAMER90=2 //!< 游戏中，旋转90度
};

SFInt SFNesEmuApp_GetStatus(void);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //!__SNOWFISH_API__H__


