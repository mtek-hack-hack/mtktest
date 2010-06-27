/* $Id: SFApi.h 142 2006-12-22 02:28:50Z snowfish $ */
/**
 * @file SFApi.h
 * @version 1.1.0 (保密文件)
 * @author 上海奥讯电子科技有限公司
 */

#ifndef __SNOWFISH_API__H__
#define __SNOWFISH_API__H__

#include <stdarg.h>

//__SF_API__版本号，为aabbccdd形式（[aa] bb.cc.dd），bb为主版本号，cc为次版本号,dd为修订版本号,aa为特别版本号（00表示为标准版本）
#define __SF_API__  00020100

#if defined(WIN32) && !defined(MMI_ON_WIN32)
# define SFAPI_WIN
#endif

#if defined(_DEBUG) && !defined(SF_RT_DEBUG)
# define SF_RT_DEBUG
#endif

#if defined(WIN32) && !defined(SF_PC_EXPORT)
# define SF_PC_EXPORT __declspec(dllexport) 
#endif

#ifndef SF_PC_EXPORT
# define SF_PC_EXPORT
#endif //SF_PC_EXPORT

#ifdef _MSC_VER
# ifdef SFAPI_WIN
#  ifdef _DEBUG
#   pragma comment(lib,"SFAPId.lib")
#  else
#   pragma comment(lib,"SFAPI.lib")
#  endif
# endif
#endif

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#if __SF_API__<00020000
#if !defined(SF_SCREEN_WIDTH) || !defined(SF_SCREEN_HEIGHT)
# error SF_SCREEN_WIDTH and SF_SCREEN_HEIGHT must be both defined
#endif
#endif

#if 0
#ifndef SF_DYNAMIC_MODULE_CLASS0
#define SFAPI_METHOD(ret_type,name,param) typedef ret_type (*PAPI_##name) param;\
    ret_type name param
#else //!SF_DYNAMIC_MODULE_CLASS0
#define SFAPI_METHOD(ret_type,name,param) typedef ret_type (*PAPI_##name) param;
#endif //!SF_DYNAMIC_MODULE_CLASS0
#endif //0

#ifndef sf_inline
# if defined(_MSC_VER)
#  define sf_inline static __inline
#  define sf_always_inline static __inline
# elif defined(__ARMCC_VERSION)
#  define sf_inline static __inline
#  define sf_always_inline static __inline
# elif defined(__GNUC__)
#  define sf_inline static inline
#  define sf_always_inline static inline
# else
#  define sf_inline static 
#  define sf_always_inline static 
# endif
#endif //!sf_inline


#ifndef _UNICHAR_DEFINED
  #define _UNICHAR_DEFINED
  typedef unsigned short UNICHAR;
#endif //_UNICHAR_DEFINED

#ifndef _UCHAR_DEFINED
  #define _UCHAR_DEFINED
  typedef UNICHAR UChar;
#endif //_UCHAR_DEFINED

#ifndef _USTRING_DEFINED
  #define _USTRING_DEFINED
  typedef const UNICHAR* UString;
#endif //_USTRING_DEFINED

typedef int SFInt;
typedef unsigned int SFUint;
typedef long SFInt32;
#ifndef SFAPI_WIN
typedef long long SFInt64;
typedef unsigned long long SFUint64;
#else
typedef  long SFInt64;
typedef unsigned  long SFUint64;
#endif
typedef unsigned long SFUint32;
typedef signed char SFInt8;
typedef unsigned char SFUint8;
typedef short SFInt16;
typedef unsigned short SFUint16;
typedef char SFChar;
typedef SFUint8 SFByte;
typedef SFByte* SFBytePtr;
typedef const SFByte* SFCBytePtr;

#ifndef NDS_JTYPES_INCLUDE

#ifndef _INT32_DEFINED
  #define _INT32_DEFINED
  typedef SFInt32       int32;
#endif //_INT32_DEFINED

#ifndef _INT16_DEFINED
  #define _INT16_DEFINED
  typedef SFInt16       int16;
#endif //_INT16_DEFINED

#ifndef _INT8_DEFINED
  #define _INT8_DEFINED
  typedef SFInt8        int8;
#endif //_INT8_DEFINED

#ifndef _UINT64_DEFINED
  #define _UINT64_DEFINED
#ifndef WIN32
  typedef unsigned long long uint64;
#else
   typedef unsigned  long uint64;
#endif 
#endif //_UINT64_DEFINED

#ifndef _INT64_DEFINED
  #define _INT64_DEFINED
#ifndef WIN32
  typedef long long int64;
#else
	typedef  long int64;
#endif
#endif //_INT64_DEFINED

#ifndef _UINT32_DEFINED
  #define _UINT32_DEFINED
  typedef SFUint32  uint32;
#endif //_UINT32_DEFINED

#ifndef _UINT16_DEFINED
  #define _UINT16_DEFINED
  typedef SFUint16  uint16;
#endif //_UINT16_DEFINED

#ifndef _UINT8_DEFINED
  #define _UINT8_DEFINED
  typedef SFUint8       uint8;
#endif //_UINT8_DEFINED

#endif //!NDS_JTYPES_INCLUDE

#ifndef __SF_ALIGN
#if defined(_MSC_VER)
#define __SF_ALIGN(n) __declspec(align(n))
#elif defined(__ARMCC_VERSION)
#define __SF_ALIGN(n) __align(n)
#elif defined(__GNUC__)
#define __SF_ALIGN(n) __attribute__((aligned(n)))
#else
#define __SF_ALIGN(n) __SF_ALIGN not supported
#endif
#endif //!__SF_ALIGN

#ifndef __SF_PACKED
#if defined(_MSC_VER)
#define __SF_PACKED __declspec(align(1))
#elif defined(__ARMCC_VERSION)
#define __SF_PACKED __packed
#elif defined(__GNUC__)
#define __SF_PACKED __attribute__((packed))
#else
#define __SF_PACKED __SF_PACKED not supported
#endif
#endif //!__SF_ALIGN

#ifndef __cplusplus
#ifndef _BOOLEAN_DEFINED
typedef uint8 boolean;
#define _BOOLEAN_DEFINED
#endif
# ifndef true
#  define true 1
# endif //true
# ifndef false
#  define false 0
# endif //false
#endif

typedef void SFVoid;
typedef void SFAny;
typedef void* SFAnyPtr;
typedef const void* SFAnyPtrC;
typedef void** SFAnyPtrPtr;

typedef SFUint32 SFUint_Ptr;
typedef SFInt32 SFInt_Ptr;

typedef SFUint32 SFSize_T;

typedef SFUint64 SFModId;
typedef SFUint64 SFCLSID;
#define SFMODID(h,l)   ((((SFUint64)(h))<<32)|(SFUint32)(l))

#ifdef __cplusplus
#define SFNull  0
#define SFNULL  0
#else
#define SFNull  ((void*)0)
#define SFNULL  ((void*)0)
#endif

typedef unsigned int  SFLPARAM;
typedef unsigned int SFWPARAM;
typedef int SFEVT_ID;

typedef int SFBool;

typedef enum _SF_BOOLEAN
{
  SFTrue=1,
  SFFalse=0
} SF_BOOLEAN;

#ifdef SF_NATIVE_COLOR_RGB888
#define SF_NATIVE_COLOR_BITS    24
typedef SFUint32 SFNColor;
#elif defined(SF_NATIVE_COLOR_XRGB8888)
#define SF_NATIVE_COLOR_BITS    32
typedef SFUint32 SFNColor;
#else
#define SF_NATIVE_COLOR_BITS    16
typedef SFUint16 SFNColor;
#endif //SF_NATIVE_COLOR_RGB888

typedef SFUint32 SFColor32;

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



#undef DECLARE_INTERFACE
#undef BEGIN_DEFINE_INTERFACE
#undef END_DEFINE_INTERFACE

#define DECLARE_INTERFACE(name) struct _interface_##name;\
    typedef struct _interface_##name name;\
    struct _interface_##name##_class;\
    typedef struct _interface_##name##_class name##_class;\
    typedef void (*_interface_##name##_AddRef_T)(name* self);\
    typedef int (*_interface_##name##_Release_T)(name* self);\
    typedef SFReason (*_interface_##name##_QueryInterface_T)(name* self,SFUint32 l,SFUint32 h,void**ptr);

#define BEGIN_DEFINE_INTERFACE(name)   struct _interface_##name {\
        const struct _interface_##name##_class* __vftab;\
    };\
    struct _interface_##name##_class {\
        void (*AddRef)(name* self);\
        int (*Release)(name* self);\
        SFReason (*QueryInterface)(name* self,SFUint32 l,SFUint32 h,void**ptr);
    

#define DEFINE_INTERFACE_VFTABLE(name) const struct _interface_##name##_class* __vftab;

#define END_DEFINE_INTERFACE(name)     };

#define DECLARE_INTERFACE_BASIC_FUNCS(name)   void (*AddRef)(name* self);\
    int (*Release)(name* self);\
    SFReason (*QueryInterface)(name* self,SFUint32 l,SFUint32 h,void**ptr);

#define DEFINE_INTERFACE_BASIC_FUNCS(name,prefix)  (_interface_##name##_AddRef_T)prefix##AddRef,\
    (_interface_##name##_Release_T)prefix##Release,\
    (_interface_##name##_QueryInterface_T)prefix##QueryInterface

#define IMPLEMENT_SHARED_INTERFACE_BASIC_FUNCS(name,prefix) \
    void prefix##AddRef(name* self) {}\
    int prefix##Release(name* self) { return 1; }\
    SFReason prefix##QueryInterface(name* self,SFUint32 l,SFUint32 h,void**ptr) { return SFReasonNotSupported; }


typedef struct tagISFApplication ISFApplication;

//!事件处理句柄,对于每一个消息都有一个事件ID(idEvent)和最多2个的关联的参数(lParam,wParam)
//以下关于事件一律写作 evt_id ( [param1 [,param2] ] )
//@param pApp - 系统维护的ISFApplication实例指针 (由系统调用SFApp_Create创建，到应用相应EVT_APP_DESTROY后指向的内容自动被清除)
//@param idEvent - 事件ID
//@param lParam - 事件的参数1
//@param wParam - 事件的参数2
typedef void (*SF_EVENT_HANDLER) (ISFApplication*pApp,SFEVT_ID idEvent,SFLPARAM lParam,SFWPARAM wParam);

typedef ISFApplication* (*SF_MODULE_CREATE)(void);

typedef void (*SF_FUNC_VOID__VOID)(void);

typedef void (*SF_FUNC_CALLBACK)(void*);

typedef void* (*SF_FUNC_ALLOC_P)(void* param,SFSize_T sz);

typedef void* (*SF_FUNC_REALLOC_P)(void* param,void* ptr,SFSize_T sz);

typedef void (*SF_FUNC_FREE_P)(void* param,void* ptr);

typedef void* (*SF_FUNC_ALLOC)(SFSize_T sz);

typedef void* (*SF_FUNC_REALLOC)(void* ptr,SFSize_T sz);

typedef void (*SF_FUNC_FREE)(void* ptr);

/**
 * @brief 按键键值
 */
typedef enum _SF_KEYCODE
{
    SFKEY_NONE=0,   //!< 表示无键按下的值
    SFKEY_SL=1,     //!< 左软键
    SFKEY_SM,       //!< 中软键
    SFKEY_SR,       //!< 右软键

    SFKEY_UP,       //!< 方向键上
    SFKEY_DOWN,     //!< 方向键下
    SFKEY_LEFT,     //!< 方向键左
    SFKEY_RIGHT,    //!< 方向键右

    //数字键
    SFKEY_NUM0,     //!< 数字键0
    SFKEY_NUM1,     //!< 数字键1
    SFKEY_NUM2,     //!< 数字键2
    SFKEY_NUM3,     //!< 数字键3
    SFKEY_NUM4,     //!< 数字键4
    SFKEY_NUM5,     //!< 数字键5
    SFKEY_NUM6,     //!< 数字键6
    SFKEY_NUM7,     //!< 数字键7
    SFKEY_NUM8,     //!< 数字键8
    SFKEY_NUM9,     //!< 数字键9

    SFKEY_POUND,    //!< 井号
    
    SFKEY_STAR,     //!< 星号

    SFKEY_CLR,      //!< 强行退出

    SFKEY_END,
    SFKEY_SEND,
    SFKEY_POWER,
    SFKEY_VOLUP,
    SFKEY_VOLDOWN,

    SFKEY_LAST
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
  //@since 1.0.0
  EVT_APP_NONE=0,
  //EVT_APP_START()
  //@brief 应用程序开始运行的信号
  //@since 1.0.0
  EVT_APP_START,
  //EVT_APP_PAUSE()
  //@brief 应用程序暂停的信号
  //@since 1.0.0
  EVT_APP_PAUSE,
  //EVT_APP_RESUME()
  //@brief 应用程序从暂停恢复的信号
  //@since 1.0.0
  EVT_APP_RESUME,
  //EVT_APP_DESTROY()
  //@brief 应用程序关闭的信号
  //@since 1.0.0
  EVT_APP_DESTROY,
  
  //EVT_KEYUP(SPLPARAM nKeyCode)
  //@brief
  //@param nKeyCode - 释放的按键的键值，见SF_KEYCODE
  //@since 1.0.0
  EVT_KEYUP,
  //EVT_KEYDOWN(SPLPARAM nKeyCode)
  //@brief
  //@param nKeyCode - 按下的按键的键值，见SF_KEYCODE
  //@since 1.0.0
  EVT_KEYDOWN,
  
  //EVT_POINTER_PRESSED(SPLPARAM ptPress)
  //@brief 触摸屏按下
  //@param ptPress - SFMAKE_POINT(x,y) 按下点的屏幕坐标
  //@since 1.0.0
  EVT_POINTER_PRESSED,
  //EVT_POINTER_PRESSED(SPLPARAM ptRelease)
  //@brief 触摸屏释放
  //@param ptRelease - SFMAKE_POINT(x,y) 释放点的屏幕坐标
  //@since 1.0.0
  EVT_POINTER_RELEASED,
  //EVT_POINTER_PRESSED(SPLPARAM ptDrag)
  //@brief 触摸屏拖动
  //@param ptDrag - SFMAKE_POINT(x,y) 拖动点的屏幕坐标
  //@since 1.0.0
  EVT_POINTER_DRAGGED,
  
  //EVT_TIMER(SPLPARAM idTimer)
  //@brief 定时器到时
  //@param idTimer - SFTIMER_ID 到时的定时器ID
  //@since 1.0.0
  EVT_TIMER,
  
  //EVT_SMS_SEND(SPLPARAM idSms,SFWPARAM nResult)
  //@brief 短消息发送结果
  //@param idSms - SFSMS_ID 之前取到的短消息发送ID
  //@param nResult - int 发送结果，1表示成功，0表示失败
  //@since 1.0.0
  EVT_SMS_SEND,

  //EVT_SOCKET(SPLPARAM socket,SFWPARAM evt_err)
  //@brief socket消息
  //@param socket - SFSMS_ID 之前取到的短消息发送ID
  //@param evt_err - SFMAKE_PARAM(event,error);
  //@since 1.0.0
  EVT_SOCKET,
  
  //EVT_SOCKET_STATUS(SPLPARAM idStatus)
  //@brief 网络系统状态
  //@param idStatus - SF_SOCK_STATUS_READY表示网络系统初始化，socket已经可以连接、SF_SOCK_STATUS_ERROR表示网络系统已出错关闭，需要重新初始化。
  //@since 1.0.0
  //@remarks 已废弃
  EVT_SOCKET_STATUS,

  //EVT_APP_HANDLE_FILE(SPLPARAM path)
  //@brief 处理一个文件，EVT_APP_START后才可以收到
  //@param path - UCS-2编码的文件路径
  EVT_APP_HANDLE_FILE,
  
  //EVT_APP_HANDLE_URL(SPLPARAM url)
  //@brief 处理一个URL，EVT_APP_START后才可以收到
  //@param url - UCS-2编码的URL
  EVT_APP_HANDLE_URL,
  
  //EVT_APP_HANDLE_MESSAGE(SPLPARAM lparam)
  //@brief 处理一个特定消息，EVT_APP_START后才可以收到
  //@param lparam - 参数1，一一个UNICODE字符串
  EVT_APP_HANDLE_MESSAGE,

  //EVT_PAINT(...)
  //@remarks 暂时未使用
  EVT_PAINT,
  
  //EVT_NOTIFY(...)
  //@remarks 暂时未使用
  EVT_NOTIFY,

  //EVT_COMMAND(...)
  //@remarks 暂时未使用
  EVT_COMMAND,

  //EVT_DBLCLICK(...)
  //@remarks 暂时未使用
  EVT_DBLCLICK,

//#ifdef WIN32
//  EVT_MEM_PROFILE=0x1000,
//#endif

  __EVT_INT32_PROTECTION__=0x7FFFFFFF
} SF_EVENT;

/**
 * @brief 应用程序接口对象结构
 * @since 1.0.0
 */
struct tagISFApplication
{
    SF_EVENT_HANDLER pfnEvtHandler; //!< 消息处理句柄
};


/**
 * @brief 用于异步调用的消息通知变量的类型
 */
typedef SFInt32 SFReason;

/**
 * @brief SFReason取值
 */
enum SFReasons
{
    SF_REASON_OK=0,         //!< 异步调用的消息通知值，表示成功
    SFReasonOK=SF_REASON_OK,
    
    SF_REASON_FAIL=-1,      //!< 异步调用的消息通知值，表示一般的失败
    SFReasonFail=SF_REASON_FAIL,
    SFReasonError=SF_REASON_FAIL,
    
    SF_REASON_BUSY=-2,      //!< 异步调用的消息通知值，表示操作正在进行，请等待
    SFReasonBusy=SF_REASON_BUSY,
    SF_REASON_PENDING=SF_REASON_BUSY,
    SF_REASON_WOULDBLOCK=SF_REASON_BUSY,
    SFReasonPending=SF_REASON_BUSY,
    SFReasonWouldBlock=SF_REASON_BUSY,
    
    SF_REASON_CANCEL=-3,    //!< 异步调用的消息通知值，一般表示取消
    SFReasonCancel=SF_REASON_CANCEL,
    
    SF_REASON_NOTFOUND=-4,  //!< 异步调用的消息通知值，一般表示没有找到
    SFReasonNotFound=SF_REASON_NOTFOUND,

    SF_REASON_BADPARAMETER=-5,
    SFReasonBadParameter=SF_REASON_BADPARAMETER,

    SF_REASON_QUITREQUEST=-6,
    SFReasonQuitRequest=SF_REASON_QUITREQUEST,

    SF_REASON_NORESULT=-7, //!< 系统已接受请求，但无法获知结果
    SFReasonNoResult=SF_REASON_NORESULT,

    SF_REASON_NOTSUPPORTED=-8,
    SFReasonNotSupported=SF_REASON_NOTSUPPORTED,

    SF_REASON_OUTOFMEMORY=-9,
    SFReasonOutOfMemory=SF_REASON_OUTOFMEMORY,

    SF_REASON_OUTOFRESOURCE=-10,
    SFReasonOutOfResource=SF_REASON_OUTOFRESOURCE,

    SF_REASON_INTERNALERROR=-11,
    SFReasonInternalError=SF_REASON_INTERNALERROR,

    SF_REASON_OSERROR=-12,
    SFReasonOSError=SF_REASON_OSERROR,

    SF_REASON_ACCESSDENIED=-13,
    SFReasonAccessDenied=SF_REASON_ACCESSDENIED,

    SF_REASON_FULL=-14,
    SFReasonFull=SF_REASON_FULL,

    SF_REASON_CORRUPTED=-15,
    SFReasonCorrupted=SF_REASON_CORRUPTED,

    SF_REASON_DEVICECHANGED=-16,
    SFReasonDeviceChanged=SF_REASON_DEVICECHANGED,

    SF_REASON_NOTREADY=-17,
    SFReasonNotReady=SF_REASON_NOTREADY,

    SF_REASON_DEVICEBUSY=-18,
    SFReasonDeviceBusy=SF_REASON_DEVICEBUSY,

    SF_REASON_EXISTS=-19,
    SFReasonExists=SF_REASON_EXISTS,

    SF_REASON_OUTOFRANGE=-20,
    SFReasonOutOfRange=SF_REASON_OUTOFRANGE,

    SF_REASON_ENDOFFILE=-21,
    SFReasonEndOfFile=SF_REASON_ENDOFFILE,

    SF_REASON_BADFORMAT=-22,
    SFReasonBadFormat=SF_REASON_BADFORMAT,
    

    __SFReasons__INT32__=0x7FFFFFFF
};

#define MAKE_REASON_E(v1,v2)    ((SFReason)(0x80000000|((v1)<<12)|(v2)))

struct _SFEModule;
struct _SFBuiltInApp;
typedef struct _SFEModule SFEModule;
typedef struct _SFBuiltInApp SFBuiltInApp;

enum SFModuleAttrs
{
    SFMOD_ATTR_SYSTEM=0x00000001,               //!< system module, with all the acess rights
    SFMOD_ATTR_SERVICE=0x00000002,              //!< service module
    SFMOD_ATTR_APPLICATION=0x00000004,          //!< application module

    SFMOD_ATTR_NATIVE=0x00000008,               //!< native code
    SFMOD_ATTR_BUILTIN=0x00000010,              //!< whether the module is built-in or not

    SFMOD_ATTR_FAST_SCREEN_UPDATE=0x00000020,   //!< fast screen update support
    SFMOD_ATTR_MOVEABLE=0x00000040,             //!< the module can be moved to any other memory space
    SFMOD_ATTR_NATIVE_SFAPI_COMPATIBILITY=0x00000080, //!< native module with the ability to use the SFAPI, can only be used with SFMOD_ATTR_NATIVE
    SFMOD_ATTR_DYNAMIC_MEMORY=0x00000100,    //!< free the memory resource

    __SFMOD_ATTR__INT32__=0x7FFFFFFF
};


typedef SFReason (*SFEMODULE_ENTRY)(SFModId aModId,void** ppObj);
typedef SFReason (*SFEMODULE_ENTRY_LEGACY)(const SFModId* pModId,void** ppObj);

SFReason SFSystem_LeaveSFAPICompabileNativeModule(SFModId mod);
SFReason SFSystem_EnterSFAPICompabileNativeModule(SFModId mod);

/**
 * @brief the base structure for an EModule object
 */
struct _SFEModule
{
    SFUint16 iStructSize;       //!< the size of the structure
    SFUint16 iImageVersion;     //!< the format version of the loaded image, 1 is the first version, 2 is the second version, currently the version number is 3
    union
    {
        SFEMODULE_ENTRY iMethod;              //!< new modules (iImageVersion>3) should use this
        SFEMODULE_ENTRY_LEGACY iLegacyMethod; //!< for compatible with the legacy applications
    } iEntry;
    SFUint16 iFlag;             //!< @see SFModuleAttrs，ignore SFMOD_ATTR_NATIVE and SFMOD_ATTR_BUILTIN
    SFUint16 iLocalHeapSize;    //!< local heap size in KB
    SFUint32* iImageBase;       //!< the base of the loaded image, but the address may not be the allocated address of the memory block
    SFUint32 iImageSize;        //!< the size of the loaded image
    const SFCLSID* iRights;     //!< access rights in SFCLSID
};

struct _SFBuiltInApp
{
    SFModId iModId;
    SFUint16 iFlag;                 //!< @see SFModuleAttrs, SFMOD_ATTR_BUILTIN will be added automatically
    SFUint16 iLocalHeapSize;        //!< local heap size in KB
    SF_FUNC_VOID__VOID iEntryFunc;  //!< for the normal native app
    const SFUint16* iRight;         //!< access rights in native format
};

extern const SFUint16 SF_DEFAULT_APP_RIGHTS[];

enum
{
    SF_LAUNCH_NORMAL=0,
    SF_LAUNCH_WITH_FILE=1,
    SF_LAUNCH_WITH_URL=2,
    SF_LAUNCH_WITH_MESSAGE=3,

    SF_LAUNCH_TYPE_MASK=0xFF
};

SFReason SFSystem_LaunchModule(SFModId mod,const UChar* aCmdLine,SFUint32 aFlag);


/**
 * @brief 表示应用主动要求退出，系统随后必须发送EVT_APP_DESTORY消息来让应用程序做清理工作
 * @since 1.0.0
 */
void SFApp_Exit(void);


/**
 * @brief 获取系统的屏幕缓冲区
 * @return 屏幕缓冲区指针
 * @since 1.0.0
 */
SFNColor* SFScreen_GetBuffer(void);

#ifdef WIN32
typedef struct HDC__* HDC;
HDC SFScreen_GetDC(void);
#endif //WIN32

/**
 * @brief 获取系统的屏幕宽度
 * @return 屏幕宽度
 * @since 1.0.0
 */
SFInt SFScreen_GetWidth(void);

/**
 * @brief 获取系统的屏幕高度
 * @return 屏幕高度
 * @since 1.0.0
 */
SFInt SFScreen_GetHeight(void);

/**
 * @brief 把系统的屏幕缓冲区内容刷新到前台（实际屏幕）
 * @since 1.0.0
 */
void SFScreen_Update(void); 

enum
{
    SF_GDI_FONT_STYLE_PLAIN=0x00,
    SF_GDI_FONT_STYLE_UNDERLINE=0x01,
    SF_GDI_FONT_STYLE_BOLD=0x02,
    SF_GDI_FONT_STYLE_ITALIC=0x04,
    SF_GDI_FONT_STYLE_OBLIQUE=0x08,
    SF_GDI_FONT_STYLE_STRIKETHROUGH=0x10,

    SF_GDI_FONT_SIZE_SMALL=-1,
    SF_GDI_FONT_SIZE_MEDIUM=0,
    SF_GDI_FONT_SIZE_LARGE=-2,

    SF_GDI_FONT_FACE_SYSTEM=0,
    SF_GDI_FONT_FACE_MONOSPACE=1,
    SF_GDI_FONT_FACE_PROPORTIONAL=2,

    SF_GDI_FONT_TYPE_ANY=0,
    SF_GDI_FONT_TYPE_TITLE=1,
    SF_GDI_FONT_TYPE_UI=2,
    SF_GDI_FONT_TYPE_INPUT=3,
    SF_GDI_FONT_TYPE_STATIC=4
};

typedef struct _SFGDIFont
{
    SFUint8 iFace;
    SFUint8 iStyle;
    SFInt8 iSize;
    SFUint8 iType;
} SFGDIFont;

void SFFont_SetFont(const SFGDIFont* pFont);

void SFFont_GetFont(SFGDIFont* pFont);

/**
 * @brief 取得文字的逻辑高度，所有文字有统一的逻辑高度
 * @return 取得的逻辑高度
 * @since 1.0.0
 */
SFInt SFFont_GetHeight(void);

/**
 * @brief 获取单个字符的宽度
 * @param aChar - UNICODE UTF16 编码的字符
 * @return 取得的宽度
 * @since 1.0.0
 */
SFInt SFFont_GetCharWidth(UChar aChar);

/**
 * @brief 获取字符串的宽度（不使用'\\0'结尾）
 * @param aStr - UNICODE UTF16 编码的字符串
 * @param aLength - 字符串的长度
 * @return 取得的宽度
 * @since 1.0.0
 */
SFInt SFFont_GetStringWidth(UString aStr,SFInt aLength);

/**
 * @brief 设置屏幕裁减区域，用于文字的裁减
 * @param x - 左上角X坐标
 * @param y - 左上角Y坐标
 * @param w - 裁减区域宽度
 * @param h - 裁减区域高度
 * @since 1.0.0
 */
void SFScreen_SetClip(SFInt x,SFInt y,SFInt w,SFInt h);

/**
 * @brief 重置屏幕裁减区域
 * @since 1.0.0
 */
void SFScreen_ResetClip(void);

/**
 * @brief 启动一个定时器
 * @param idTimer - 定时器ID
 * @param nExpiredTime - 以毫秒为单位的定时时间
 * @param bOnce - YSTrue 表示定时器只有效一次，YSFalse 表示按指定间隔反复发出信号
 * @param pHandler - 用于接受定时器事件的消息处理句柄，参见EVT_TIMER
 * @remarks 已废弃，新的应用程序应当使用
 * @since 1.0.0
 */
void SFTimer_Start(SFTIMER_ID idTimer,int nExpiredTime,SFBool bOnce,ISFApplication*pHandler);

/**
 * @brief 停止指定的定时器
 * @param idTimer - 定时器ID
 * @since 1.0.0
 */
void SFTimer_Stop(SFTIMER_ID idTimer);

/**
 * @brief 获取游戏中可分配的连续空间首地址
 * @return 取得的空间首地址
 * @remarks 这个方法会被反复调用，请务必返回同一连续空间的首地址
 * @since 1.0.0
 */
SFAnyPtr SFSystem_GetHeap(void);
/**
 * @brief 获取游戏中可分配的连续空间大小
 * @return 空间的大小
 * @since 1.0.0
 */
SFSize_T SFSystem_GetHeapSize(void);

/**
 * @brief 系统的分配内存方法
 * @param newSize - 分配的空间的大小
 * @return 分配的空间的首地址
 * @since 1.0.2
 */
SFAnyPtr SFSystem_Alloc(SFSize_T newSize);

/**
 * @brief 系统的重分配内存方法
 * @param ptr - 原内存块首地址
 * @param newSize - 新空间的大小
 * @return 新空间的首地址，原空间同时被释放，为SFNull表示失败，且原空间没有被释放
 * @since 1.0.2
 */
SFAnyPtr SFSystem_Realloc(SFAnyPtr ptr,SFSize_T newSize);

/**
 * @brief 系统的释放空间的方法
 * @param ptr - 要释放的空间的首地址，必须是由之前的SFSystem_Alloc/SFSystem_Realloc调用返回的
 * @since 1.0.2
 */
void SFSystem_Free(SFAnyPtr ptr);



/**
 * @brief 声音播放格式
 */
typedef enum _SFSND_FORMAT
{
  SNDFORMAT_UNKNOWN=0,  //!< 未知格式，可以忽略
  SNDFORMAT_MIDI=1,     //!< MIDI格式
  SNDFORMAT_WAVE=2,		//!< WAVE格式
  SNDFORMAT_AMR=3,      //!<AMR-NB，@since 2.1.0
  SNDFORMAT_AAC=4       //!<AAC，@since 2.1.0
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


SFSND_ID SFSnd_PlayFile(const UChar* path,SFSND_FORMAT format,int nLoopCount);

/**
 * @brief 结束并关闭声音的播放
 * @param idSnd - 播放声音ID
 */
void SFSnd_Stop(SFSND_ID idSnd);

/**
 * @brief 发送一条短消息，结果应该以消息EVT_SMS_SEND形式发给当前的应用，新的应用应该使用SFSms_SendEx
 * @param pNumber - 发送到的号码
 * @param pContent - 发送的内容
 * @return 发送的消息ID
 * @remarks 一般都是同时只运行一个应用，新版本的应用会逐步使用::SFSms_SendEx
 */
SFSMS_ID SFSms_Send(const UChar*pNumber,const UChar *pContent);

/**
 * @brief 发送一条短消息，结果应该以消息EVT_SMS_SEND形式发给pHandler
 * @param pNumber - 发送到的号码
 * @param pContent - 发送的内容
 * @param pHandler - 接受通知消息的应用句柄
 * @return 发送的消息ID
 */
SFSMS_ID SFSms_SendEx(const UChar*pNumber,const UChar *pContent,ISFApplication* pHandler);


#ifdef WIN32
# ifndef __MemProfile_T
#  define __MemProfile_T
typedef struct _MemProfile MemProfile;
# endif //__MemProfile_T
void SFMem_Profile(MemProfile*profile);
# ifndef __MemProfileEx_T
#  define __MemProfileEx_T
typedef struct _MemProfileEx MemProfileEx;
# endif //__MemProfileEx_T
void SFMem_ProfileEx(MemProfileEx*profile);
#endif


/**
 * @brief 获取系统时间的结构
 */
typedef struct _SFDateTime
{
    SFInt nYear;    //!< 年份
    SFInt nMonth;   //!< 月份
    SFInt nDay;     //!< 天
    SFInt nHour;    //!< 小时
    SFInt nMinute;  //!< 分钟
    SFInt nSecond;  //!< 秒
    SFUint nMill;   //!< 系统走过的毫秒级别的时间
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

/**
 * @brief 文件句柄类型
 */
typedef int SFFS_HANDLE;

/**
 * @brief 文件的打开用标志
 */
enum SFFS_Flags
{
    SFFSF_CREATE=1, //!< 创建
    SFFSF_READ=2,   //!< 读取
    SFFSF_WRITE=4,  //!< 写入
    SFFSF_APPEND=8
};


/**
 * @brief 无效句柄
 */
#define SFFS_INVALID_HANDLE 0

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

enum SFFS_Seek_Flags
{
    SFFS_SEEK_SET=0,
    SFFS_SEEK_CUR=1,
    SFFS_SEEK_END=2
};
SFSize_T SFFS_Seek(SFFS_HANDLE hFile,SFSize_T sz,int pos);

/**
 * @brief 关闭一个打开的文件句柄
 * @param hHandle - 打开的文件句柄
 */
void SFFS_Close(SFFS_HANDLE hHandle);

/**
 * @brief 获取一个打开的文件的当前长度
 * @param hHandle - 打开的文件句柄
 * @param pSz - 用以获取文件长度的指针
 * @return 成功或失败 
 */
SFBool SFFS_GetSize(SFFS_HANDLE hHandle,SFSize_T*pSz);


#define SFFS_MAX_FILE_NAME_LEN  256
#define SFFS_MAX_PATH_LEN       520

enum SFFS_Attrs
{
    SFFS_ATTR_NORMAL           =0x00,
    SFFS_ATTR_READ_ONLY        =0x01,
    SFFS_ATTR_HIDDEN           =0x02,
    SFFS_ATTR_SYSTEM           =0x04,
    SFFS_ATTR_VOLUME           =0x08,
    SFFS_ATTR_DIR              =0x10,
    SFFS_ATTR_ARCHIVE          =0x20,
    SFFS_LONGNAME_ATTR         =0x0F
};

int SFFS_SetAttributes(UString path,SFUint32 attr);

int SFFS_GetAttributes(UString path,SFUint32* attr);


typedef SFInt32 SFRESULT;

enum SFRESULTS
{
    SFR_OK=0,
    SFR_ERROR=-1,
    SFR_EOF=-2,
    SFR_FAIL=-3,
    SFR_BUSY=-4,
    SFR_CANCEL=-5,
    SFR_NOTFOUND=-6,
    SFR_WOULDBLOCK=-7
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
void SFSystem_SelectFile(UChar* aBuffer,SFSize_T aMaxSize,SFUint32 aFlags,const UChar* aFilter,SFReason* aReason);


enum SF_INPUT_TYPES
{
    SF_INPUT_TYPE_ANY=0,
    SF_INPUT_TYPE_NUMERIC=1,
    SF_INPUT_TYPE_EMAILADDR=2,
    SF_INPUT_TYPE_PHONENUMBER=3,
    SF_INPUT_TYPE_URL=4,
    SF_INPUT_TYPE_DECIMAL=5,

    SF_INPUT_TYPE_PASSWORD=0x100,
    SF_INPUT_TYPE_UNEDITABLE=0x200,
    SF_INPUT_TYPE_SENSITIVE=0x400,
    SF_INPUT_TYPE_NON_PREDICTIVE=0x800,
    SF_INPUT_TYPE_INITIAL_CAPS_WORD=0x1000,
    SF_INPUT_TYPE_INITIAL_CAPS_SENTENCE=0x2000,
    SF_INPUT_TYPE_UPPERCASE=0x4000,
    SF_INPUT_TYPE_ENGLISH_ONLY=0x8000
};


/**
 * @brief 异步方法，让用户输入一个文本
 * @param aCaption - 输入框标题，为SFNull表示没有标题
 * @param aBuffer - 接受输入的缓冲区，其初始内容作为输入框中文本的初始内容，输出结果含L'\0'结尾
 * @param aMaxLength - 可以输入的最大长度，不计L'0'结尾
 * @param aNotifier - 用于获取异步通知的变量，不可以是局部变量的地址
 * @remarks 本方法为异步方法，本方法调用中，如果没有出现系统错误，则aNotifier中马上置为::SFReasons::SFReasonPending，
 *                   如果出错则置为SFReasonError，成功调用后，方法马上返回等当前事件句柄返回切换为系统界面，等输入框处理完返回，
 *                   如果用户输入确认，把aNotifier置为::SFReasons::SFReasonOK，如果用户取消，则把aNotifier置为::SFReasons::SFReasonCancel，
 *                   对于异步调用，用户代码应当轮询aNotifier，事实上像这类弹出系统界面的，当系统界面运行时按照当前框架的实现，
 *                   是不会调用当前应用的方法的，因此只有在返回用户程序才会运行到用户轮询的代码（通过恢复定时器或响应RESUME）
 */

void SFSystem_InputText(UString aCaption,SFUint32 aFlags,UChar * aBuffer,SFSize_T aMaxLength,const char* aInputMode,SFReason* aNotifier);


/**
 * @brief 异步方法，弹出浏览器，浏览指定的URL
 * @param aURL - 要访问的URL，UTF8
 * @param aNotifier - 用于获取异步通知的变量，不可以是局部变量的地址
 * @remarks aNotifier设为::VResultConsts::KResultQuitRequest如果需要当前应用退出，
 *  ::SFReasons::SFReasonPending表示正在浏览器中，
 *  ::SFReasons::SFReasonOK表示浏览器结束，
 *  ::SFReasons::SFReasonError表示出错
 *  关于异步方法的详细说明参见VOS_InputText(const UChar * aCaption,UChar * aBuffer,int aMaxLength,VResult* aNotifier)的说明
 */
void SFSystem_OpenBrowser(const char* aURL,SFUint32 aFlags,SFReason* aNotifier);


/**
 * @brief 异步方法，拨打指定的电话号码
 * @param aPhoneNumber - 要拨打的号码
 * @param aNotifier - 用于获取异步通知的变量，不可以是局部变量的地址
 * @remarks aNotifier设为::SFReasons::SFReasonQuitRequest如果需要当前应用退出，
 *  ::SFReasons::SFReasonPending表示正在通话中，
 *  ::SFReasons::SFReasonOK表示通话结束，
 *  ::SFReasons::SFReasonError表示出错，
 *  ::SFReasons::SFReasonCancel表示用户取消
 *  关于异步方法的详细说明参见SFSystem_InputText(const UChar * aCaption,SFUint32 aFlags,UChar * aBuffer,SFSize_T aMaxLength,SFReason* aNotifier)的说明
 */
void SFSystem_MakeVoiceCall(UString aPhoneNumber,SFReason* aNotifier);


SFInt SFSystem_MultiBytesToWideChars(UChar* dest,SFInt dest_len,const char* src,const char* encoding);

SFInt SFSystem_WideCharsToMultiBytes(char* dest,SFInt dest_len,const UChar* src,const char* encoding);

#define SFSMS_MAX_MSG_LEN           (160)
#define SFSMS_MAX_DIGITS_LEN        41

enum SFSMS_DCS_ENUM
{
    SFSMS_DCS_GSM_7BIT_DEFAULT  = 0x00,  /* GSM 7-bit */
    SFSMS_DCS_OCTET             = 0x04,  /* 8-bit */
    SFSMS_DCS_UCS2              = 0x08,  /* UCS2 */  

    __SFSMS_DCS_ENUM__INT32__   = 0x7FFFFFFF
};

typedef struct _SFSMSMsg
{
    SFUint16 iDestPort;
    SFUint16 iSrcPort;
    SFUint8  iDCS;
    SFUint8  iMTI;
    
    SFUint16 iMessageLen;
    SFUint8  iTotalSegments; /* total segments*/
    SFUint8  iSegment; /* indicate which segment*/

    SFUint8  iNumberLen;
    char     iNumber[SFSMS_MAX_DIGITS_LEN];
   
    SFUint8  iSCTS[7+1];//pedding
    //align 4
    SFUint8  iMessageData[SFSMS_MAX_MSG_LEN];
} SFSMSMsg;

typedef struct _SFCallback
{
    void (*iCallback)(void*param);
    void* iParam;
} SFCallback;

enum SFAPP_SYS_CALLBACKS
{
    SFSYS_CALLBACK_NONE=0,
    SFSYS_CALLBACK_SMS_MSG,
    SFSYS_CALLBACK_SMS_DATA,
    SFSYS_CALLBACK_MAKE_CALL,

    SFSYS_CALLBACK_LAST,

    __SFAPP_SYS_CALLBACKS__INT32__=0x7FFFFFFF
};

SFReason SFSystem_RegisterCallback(SFInt aIdxCallback,SFCallback aCallback);

SFReason SFSystem_UnregisterCallback(SFInt aIdxCallback,SFCallback aCallback);


/**
 * @brief 调试用方法，用于打出调试信息，正式版可以给空实现
 */
void SFDEBUG(const char*str);

/**
 * @brief 声音设备结构，我们这边只要指针，不需要知道其结构
 */
typedef struct _SFPCMDevice SFPCMDevice;

/**
 * @brief 创建一个PCM播放设备
 * @param aFormat - 必须为0
 * @param aSamplesPerSec - 每秒的采样数（实际只用8000或16000）
 * @param aBit - 采样精度8/16（实际上暂时只用16bit）
 * @param aChannel - 声道（实际只用1）
 * @return 创建的声音设备
 */
SFPCMDevice* SFPCMDevice_Create(SFInt aFormat,SFInt aSamplesPerSec,SFInt aBit,SFInt aChannel);

/**
 * @brief 开始播放指定的设备
 * @param aDevice - 播放的设备
 */
void SFPCMDevice_Start(SFPCMDevice* aDevice);

/**
 * @brief 停止声音播放，但不关闭设备，之后仍然可以调用SFPCMDevice_Start
 * @param aDevice - 播放的设备
 */
void SFPCMDevice_Stop(SFPCMDevice* aDevice);

/**
 * @brief 关闭设备，关闭后设备句柄变为无效
 * @param aDevice - 创建的声音设备
 */
void SFPCMDevice_Close(SFPCMDevice* aDevice);

/**
 * @brief 向设备写声音数据，接在之前播放的声音之后
 * @param aDevice - 创建的声音设备
 * @param aData - 声音数据缓冲指针
 * @param aSize - 声音数据缓冲的以字节为单位的大小
 * @deprecated 废弃不用
 */
void SFPCMDevice_Write(SFPCMDevice* aDevice,const SFAny* aData,SFSize_T aSize);

/**
 * @brief 声音设备的最大音量
 */
#define SF_MAX_VOLUME   32767
    
/**
 * @brief 设置设备的音量
 * @param aDevice - 创建的声音设备
 * @param aVolume - 设置的音量
 */
void SFPCMDevice_SetVolume(SFPCMDevice* aDevice,SFInt aVolume);


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
 * @remarks 这是一个循环播放的缓冲，所以如果到达缓冲的末尾可能会出现连续空间不够的情况，
 *          那么除了这个空间，就需要额外给出位于缓冲起始的空间，所以就需要两组参数，
 *          参见DirectX中的DirectSound中IDirectSoundBuffer
 */
void SFPCMDevice_LockBuffer(SFPCMDevice* aDevice,SFUint32 offset,SFUint32 size,SFAny** pBuf0,SFUint32* pBufSize0,SFAny**pBuf1,SFUint32* pBufSize1);

/**
 * @brief 提交之前获得的缓冲数据
 * @param aDevice - 创建的声音设备
 * @param aBuf0 - 之前获取的缓冲第一段
 * @param aBUfSize0 - 实际要提交的缓冲第一段的长度
 * @param aBuf1 - 之前获取的缓冲第二段，如果没有则给SFNull
 * @param aBUfSize1 - 实际要提交的缓冲第一段的长度
 */
void SFPCMDevice_UnlockBuffer(SFPCMDevice* aDevice,SFAny* aBuf0,SFUint32 aBufSize0,SFAny* aBuf1,SFUint32 aBufSize1);

/**
 * @brief 获取设备的音量
 * @param aDevice - 创建的声音设备
 * @return 音量
 */
SFInt SFPCMDevice_GetVolume(SFPCMDevice* aDevice);

/**
 * @brief 获取发给应用的额外命令，'\\0'结尾
 * @param aBuffer - 用于获取额外字符串命令的缓冲，为UNICODE UTF16格式
 * @param aSize - 缓冲取的大小，以字符为单位
 * @return 实际的大小，以字符为单位，不含'\\0'结尾
 */
SFSize_T SFApp_GetCommandLine(UChar* aBuffer,SFSize_T aSize);

/**
 * @brief 获取当前的按键状态
 * @return 当前的按键状态，每一位代表一个按键的状态，为1表示按下，为0表示没有按下，参见::SFKeyStates
 */
SFUint32 SFSystem_GetKeyState(void);

/**
 * @brief 按键状态掩码值
 */
enum SFKeyStates
{
    SFKS_UP=1,          //!< 方向键上
    SFKS_DOWN=1<<1,     //!< 方向键下
    SFKS_LEFT=1<<2,     //!< 方向键左
    SFKS_RIGHT=1<<3,    //!< 方向键右
    SFKS_NUM0=1<<4,     //!< 数字键0
    SFKS_NUM1=1<<5,     //!< 数字键1
    SFKS_NUM2=1<<6,     //!< 数字键2
    SFKS_NUM3=1<<7,     //!< 数字键3
    SFKS_NUM4=1<<8,     //!< 数字键4
    SFKS_NUM5=1<<9,     //!< 数字键5
    SFKS_NUM6=1<<10,    //!< 数字键6
    SFKS_NUM7=1<<11,    //!< 数字键7
    SFKS_NUM8=1<<12,    //!< 数字键8
    SFKS_NUM9=1<<13,    //!< 数字键9
    SFKS_POUND=1<<14,   //!< #
    SFKS_STAR=1<<15,    //!< *
    SFKS_SL=1<<16,      //!< 左软键
    SFKS_SM=1<<17,      //!< 中软键
    SFKS_SR=1<<18,      //!< 右软键
    SFKS_END=1<<19,
    SFKS_SEND=1<<20,
    SFKS_CLR=1<<21,
    SFKS_POWER=1<<22,
    SFKS_VOLUP=1<<23,
    SFKS_VOLDOWN=1<<24
};


/**
* @brief 应用一个新堆栈调用一个函数
* @stack_addr - 堆栈首地址
* @stack_size -堆栈尺寸
* @method -方法
* @argc -参数个数
* @... - 附加参数
* @return 被调用方法的返回值
*/
SFUint32 SFOS32_InvokeWithStack(void* stack_addr,SFUint32 stack_size,void (*method)(void),SFUint32 argc,...);

/**
 * @brief 获取当前以毫秒为单位的时间，这个值仅用来计算时间差，并且要求调用间隔不太久，无法确定其值为0时的准确时刻。
 * @return 以毫秒为单位的系统时间。
 */
SFUint64 SFOS32_GetCurrentTimeMillis(void);

#ifdef SF_STOCK_RESOURCE
//所有的内置资源都含有能识别其类型的字段（一般在返回的数据之前4或8个字节） 
SFInt32 SFOS32_GetStockResource(SFUint32 idx,void *res);

SFInt32 SFOS32_ReleaseStockResource(void *res);
#endif //SF_STOCK_RESOURCE

//raw size without '\0'
#define SF_IMEI_LENGTH  15
//raw size without '\0'
#define SF_IMSI_LENGTH  16

/**
* @brief 获取手机识别码
* @param pIMEI - 用于保存手机识别码的缓冲的首地址，不能小于SF_IMEI_LENGTH
* @param pReason - 异步方法通知
*/
void SFSystem_GetIMEI(char* pIMEI,SFReason* pReason);

/**
* @brief 获取个人识别码
* @param pIMEI - 用于保存个人识别码的缓冲的首地址，不能小于SF_IMSI_LENGTH
* @param pReason - 异步方法通知，如果无SIM卡则直接返回SF_REASON_FAIL
*/
void SFSystem_GetIMSI(char* pIMSI,SFReason* pReason);




void SFSystem_Exec(void (*exec_entry)(void*param),void*param);

//void* SFSystem_CreateNativeGraphicsHandler(SFInt w,SFInt h,void* p,SFInt nBits);


enum
{
    SF_FOLDER_APPDATA=0,//read only
    SF_FOLDER_APPCONFIG,//rw only for this app
    SF_FOLDER_APPPRIVATE,//rw only for this app, not visible by normal user (may be encrypted)
    SF_FOLDER_SYSDATA,//global read only
    SF_FOLDER_SYSCONFIG,//global rw
    SF_FOLDER_SYSPRIVATE//global rw, not visible by normal user(may be encrypted)
};

SFInt SFSystem_GetFolder(SFInt idx,UChar* buf,SFInt len);

enum
{
    SF_NETWORK_ACCOUNT_AUTO=0,
    SF_NETWORK_ACCOUNT_WAP,//with wap support
    SF_NETWORK_ACCOUNT_SOCKET//with socket support
};


SFRESULT SFSystem_SetNetworkAccount(SFInt type);





typedef SFUint64 sf_time_t;

/**
 * @brief 获取当前系统时间 澹（包含日期和毫秒，但毫秒不保证正确甚至不保证真真含毫秒）
 * @parma tm - 用以获取时间的指针
 */
void sf_time(sf_time_t* tm);

DECLARE_INTERFACE(ISFMalloc)
    
BEGIN_DEFINE_INTERFACE(ISFMalloc)
    void* (*Alloc)(ISFMalloc*self,SFSize_T sz);
    void* (*Realloc)(ISFMalloc*self,void* ptr,SFSize_T sz);
    void (*Free)(ISFMalloc*self,void* ptr);
    int (*DidAlloc)(ISFMalloc*self,void* ptr);
    SFSize_T (*GetSize)(ISFMalloc*self,void* ptr);
    //SFSize_T (*GetMaxAllocatableSize)(ISFHeap*self);
    //SFSize_T (*GetTotalAllocatedSize)(ISFHeap*self);
END_DEFINE_INTERFACE(ISFMalloc)

#define ISFMalloc_AddRef(self)                 (self)->__vftab->AddRef((ISFMalloc*)(self))
#define ISFMalloc_Release(self)                (self)->__vftab->Release((ISFMalloc*)(self))
#define ISFMalloc_QueryInterface(self,clsid_l,clsid_h,ppInterface)  (p)->__vftab->QueryInterface((ISFMalloc*)(self),clsid_l,clsid_h,ppInterface)
#define ISFMalloc_Alloc(self,size)               (self)->__vftab->Alloc((ISFMalloc*)(self),size)
#define ISFMalloc_Free(self,ptr)                (self)->__vftab->Free((ISFMalloc*)(self),ptr)
#define ISFMalloc_Realloc(self,ptr,new_size)          (self)->__vftab->Realloc((ISFMalloc*)(self),(void*)ptr,new_size)
#define ISFMalloc_DidAlloc(self,ptr)            (self)->__vftab->DidAlloc((ISFMalloc*)(self),(void*)ptr)
#define ISFMalloc_GetSize(self,ptr)             (self)->__vftab->GetSize((ISFMalloc*)(self),(void*)ptr)


DECLARE_INTERFACE(ISFTimer)

BEGIN_DEFINE_INTERFACE(ISFTimer)
    SFReason (*SetParentTimer)(ISFTimer*self,ISFTimer* parent);
    SFReason (*SetTimer)(ISFTimer*self,SFInt32 dwMSecs,SF_FUNC_CALLBACK pfn,void* pUser);
    SFReason (*KillTimer)(ISFTimer*self,SF_FUNC_CALLBACK pfn,void* pUser);
    SFReason (*KillAll)(ISFTimer*self);
END_DEFINE_INTERFACE(ISFTimer)

#define ISFTimer_AddRef(self)                       (self)->__vftab->AddRef((ISFTimer*)(self))
#define ISFTimer_Release(self)                      (self)->__vftab->Release((ISFTimer*)(self))
#define ISFTimer_QueryInterface(self,clsid_l,clsid_h,ppInterface)        (self)->__vftab->QueryInterface((ISFTimer*)(self),clsid_l,clsid_h,ppInterface) 
#define ISFTimer_SetParentTimer(self,pParentTimer)            (self)->__vftab->SetParentTimer((ISFTimer*)(self),(ISFTimer*)(pParentTimer))
#define ISFTimer_SetTimer(self,dwMSecs,pfn,pUser)   (self)->__vftab->SetTimer((ISFTimer*)(self),dwMSecs,pfn,pUser)
#define ISFTimer_KillTimer(self,pfn,pUser)          (self)->__vftab->KillTimer((ISFTimer*)(self),pfn,pUser)
#define ISFTimer_KillAll(self)                      (self)->__vftab->KillAll((ISFTimer*)(self))


typedef struct _SFWapProfile
{
    SFUint16 iStructSize;
    SFUint16 iType;//wap/http/...
    SFUint8 iProxyIP[4];
    SFUint16 iProxyPort;
    SFUint16 iNetworkAccount;
    SFUint8 iUserName[32];
    SFUint8 iUserPass[32];
} SFWapProfile;


enum
{
    SF_NETACCOUNT_AUTH_PAP=0,
    SF_NETACCOUNT_AUTH_CHAP=1
};

typedef struct _SFNetworkAccountInfo
{
    SFUint16 iStructSize;
    SFUint16 iAuthType;
    UChar iName[32];
    UChar iAPN[64];
    SFUint8 iDNSIP[4];
    SFUint8 iUserName[32];
    SFUint8 iUserPass[32];
} SFNetworkAccountInfo;


DECLARE_INTERFACE(ISFNetworkManager)
    
BEGIN_DEFINE_INTERFACE(ISFNetworkManager)
    SFReason (*GetActiveAccount)(ISFNetworkManager*self,SFInt* pIdx);
    SFReason (*SetActiveAccount)(ISFNetworkManager*self,SFInt idx);
    SFReason (*GetAccountCount)(ISFNetworkManager*self,SFInt* account);
    void (*AGetAccountInfo)(ISFNetworkManager*self,int idx,SFNetworkAccountInfo* pAccount,SFReason* aReason);
    void (*ASetAccountInfo)(ISFNetworkManager*self,int idx,const SFNetworkAccountInfo* pAccount,SFReason* aReason);
    void (*ASelectAccount)(ISFNetworkManager*self,SFReason* pReason);
    void (*AGetWapProfile)(ISFNetworkManager*self,int idx,SFWapProfile* pProfile,SFReason* pReason);
END_DEFINE_INTERFACE(ISFNetworkManager)

#define ISFNetworkManager_AddRef(self)                                  (self)->__vftab->AddRef((ISFNetworkManager*)(self))
#define ISFNetworkManager_Release(self)                                 (self)->__vftab->Release((ISFNetworkManager*)(self))
#define ISFNetworkManager_QueryInterface(self)                          (self)->__vftab->QueryInterface((ISFNetworkManager*)(self))
#define ISFNetworkManager_GetActiveAccount(self,pAccountIdx)            (self)->__vftab->GetActiveAccount((ISFNetworkManager*)(self),pAccountIdx)
#define ISFNetworkManager_SetActiveAccount(self,aAccountIdx)            (self)->__vftab->SetActiveAccount((ISFNetworkManager*)(self),aAccountIdx)
#define ISFNetworkManager_GetAccountCount(self,pCount)                  (self)->__vftab->GetAccountCount((ISFNetworkManager*)(self),pCount)
#define ISFNetworkManager_AGetAccountInfo(self,aAccountIdx,pInfo,aReason) (self)->__vftab->AGetAccountInfo((ISFNetworkManager*)(self),aAccountIdx,pInfo,aReason)
#define ISFNetworkManager_ASetAccountInfo(self,aAccountIdx,pInfo,aReason) (self)->__vftab->ASetAccountInfo((ISFNetworkManager*)(self),aAccountIdx,pInfo,aReason)
#define ISFNetworkManager_ASelectAccount(self,aAyncNotify)              (self)->__vftab->ASelectAccount((ISFNetworkManager*)(self),aAyncNotify)
#define ISFNetworkManager_AGetWapProfile(self,idx,pProfile,pReason)     (self)->__vftab->AGetWapProfile((ISFNetworkManager*)(self),idx,pProfile,pReason)




void SFSystem_NotifyAll(SFReason* aReason);
void SFSystem_Cancel(SFReason* aReason);
SFReason SFSystem_WaitFor(SFReason* aReason,const SFCallback* cb);

typedef SFUint32 sf_vfs_size_t;         //!<文件系统使用的大小
typedef SFInt32 sf_vfs_offset_t;        //!<文件系统使用的偏移量
typedef SFUint32 sf_vfs_attr_t;         //!<文件的属性
typedef SFUint32 sf_vfs_access_t;       //!<文件的访问权限
typedef UChar sf_vfs_char_t;            //!<文件名用的单个字符
typedef const UChar* sf_vfs_string_t;   //!<文件名

struct _sf_vfs_fileinfo;

DECLARE_INTERFACE(sf_vfs_file)
DECLARE_INTERFACE(sf_vfs)


typedef struct _sf_vfs_fileinfo
{
   sf_vfs_attr_t attrib;        //!< 文件属性
   sf_vfs_access_t access;      //!< 访问权限
   sf_vfs_size_t size;          //!< 文件大小
   SFUint32 reserved;           //!<  对齐目的
   
   sf_time_t time_create;       //!< 创捷时间
   sf_time_t time_access;       //!< 上次访问时间，此版本中，即为写入时间
   sf_time_t time_write;        //!< 上次修改时间
   
   sf_vfs_char_t name[SFFS_MAX_FILE_NAME_LEN];
} sf_vfs_fileinfo;

BEGIN_DEFINE_INTERFACE(sf_vfs_file)
    
    /**
     * @brief 关闭此打开的文件，句柄随即无效，同时此操作会调用一次Release，因此调用Close后不应当对此对象再调用Release，另外即时从来没有调用过Close最后的一次Release也会关闭此文件指针
     * @param fd - 文件对象指针
     * @return 
     */
    int (*vfs_file_close)(sf_vfs_file* fd);
    
    /**
     * @brief 读取文件
     * @param fd - 文件对象指针
     * @param buf - 存放读取数据的缓冲的首地址
     * @param sz - 要读取的长度
     * @param rsz - 用于获取实际读取长度的指针
     * @return 
     */
    int (*vfs_file_read)(sf_vfs_file* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz);
    
    /**
     * @brief 写入文件
     * @param fd - 文件对象指针
     * @param buf - 存放待写入数据的缓冲的首地址
     * @param sz - 要写入的长度
     * @param rsz - 用以获取实际写入长度的指针
     * @return 
     */
    int (*vfs_file_write)(sf_vfs_file* fd,void* buf,sf_vfs_size_t sz,sf_vfs_size_t* rsz);
    
    /**
     * @brief 
     * @param fd - 文件对象指针
     * @param offset - 
     * @param orig -
     * @return 
     */
    int (*vfs_file_seek)(sf_vfs_file* fd,sf_vfs_offset_t offset,int orig);
    
    /**
    * @brief 提交所有的未实际写入磁盘的数据和操作
    * @param fd - 文件对象指针
    * @return 
    */
    int (*vfs_file_commit)(sf_vfs_file* fd);
    
    /**
    * @brief 获取当前的文件读写指针的位置
    * @param fd - 文件对象指针
    * @param offset - 用于存放读写指针位置的指针
    * @return 
    */
    int (*vfs_file_tell)(sf_vfs_file* fd,sf_vfs_offset_t* poffset);
    
    /**
    * @brief 改变一个文件的大小，文件必须处于可写入的模式
    * @param fd - 文件对象指针
    * @param sz - 要改变到的大小
    * @return 
    */
    int (*vfs_file_chsize)(sf_vfs_file* fd,sf_vfs_size_t sz);
    
    /**
    * @brief 检查当前文件指针是否到达了文件的末尾
    * @param fd - 文件对象指针
    * @return 0 表示没有到达末尾，1表示到达末尾
    */
    int (*vfs_file_eof)(sf_vfs_file* fd);
    
    /**
    * @brief 截断文件到当前写入指针的位置，文件必须处于可写入的模式
    * @param fd - 文件对象指针
    * @return 
    */
    int (*vfs_file_trunc)(sf_vfs_file* fd);
    
    /**
    * @brief 用以获取在这个文件对象上的上一个错误
    * @param fd - 文件对象指针
    * @return 
    */
    int (*vfs_file_getlasterror)(sf_vfs_file* fd);
    
    /**
    * @brief 获取文件的长度
    * @param fd - 文件对象指针
    * @param psize - 用于存放返回大小的指针
    * @return 
    */
    int (*vfs_file_filelength)(sf_vfs_file* fd,sf_vfs_size_t* psize);
END_DEFINE_INTERFACE(sf_vfs_file)


BEGIN_DEFINE_INTERFACE(sf_vfs)
    /**
        * @brief 
        */
    int (*vfs_open_file)(sf_vfs* fs,sf_vfs_string_t file,int mode,sf_vfs_file**pfile);

    /**
        * @brief 
        */
    int (*vfs_getlasterror)(sf_vfs* fs);

    /**
        * @brief 
        */
    int (*vfs_rename)(sf_vfs* fs,sf_vfs_string_t name,sf_vfs_string_t newname);

    /**
        * @brief 
        */
    int (*vfs_getattr)(sf_vfs* fs,sf_vfs_string_t name,sf_vfs_attr_t* pattr);

    /**
        * @brief 
        */
    int (*vfs_setattr)(sf_vfs* fs,sf_vfs_string_t name,sf_vfs_attr_t attr);

    /**
        * @brief 
        */
    int (*vfs_getaccess)(sf_vfs* fs,sf_vfs_string_t name,sf_vfs_access_t* paccess);

    /**
        * @brief 
        */
    int (*vfs_setaccess)(sf_vfs* fs,sf_vfs_string_t name,sf_vfs_access_t access);

    /**
        * @brief 
        */
    int (*vfs_remove)(sf_vfs* fs,sf_vfs_string_t name);

    /**
        * @brief 
        */
    int (*vfs_getcwd)(sf_vfs* fs,sf_vfs_char_t* buf,SFSize_T maxlen);

    /**
        * @brief 
        */
    int (*vfs_chcwd)(sf_vfs* fs,sf_vfs_string_t path);

    /**
        * @brief 
        */
    int (*vfs_mkdir)(sf_vfs* fs,sf_vfs_string_t name);

    /**
        * @brief 
        */
    int (*vfs_rmdir)(sf_vfs* fs,sf_vfs_string_t name);

    /**
        * @brief 
        */
    int (*vfs_exists)(sf_vfs* fs,sf_vfs_string_t name,int mode);

    /**
        * @brief 
        */
    int (*vfs_getfileinfo)(sf_vfs* fs,sf_vfs_string_t name,sf_vfs_fileinfo* pinfo);

    /**
        * @brief 
        */
    int (*vfs_enum_first)(sf_vfs* fs,sf_vfs_string_t path,int mode,sf_vfs_fileinfo* pinfo);

    /**
        * @brief 
        */
    int (*vfs_enum_next)(sf_vfs* fs,sf_vfs_fileinfo* pinfo);

    /**
        * @brief 
        */
    int (*vfs_enum_close)(sf_vfs* fs);

    /**
        * @brief 
        */
    int (*vfs_getfreespace)(sf_vfs* fs,sf_vfs_string_t path,sf_vfs_size_t *psize);
END_DEFINE_INTERFACE(sf_vfs)



enum sf_vfs_open_mode_enum
{
    SF_VFS_OPEN_CREATE=0x01,    //!< 
    SF_VFS_OPEN_READ=0x02,      //!< 
    SF_VFS_OPEN_WRITE=0x04,     //!< 
    SF_VFS_OPEN_APPEND=0x08,    //!< 
    
    SF_VFS_OPEN_RW=SF_VFS_OPEN_READ|SF_VFS_OPEN_WRITE
};

enum sf_vfs_file_position_enum
{
    SF_VFS_SEEK_SET=0,
    SF_VFS_SEEK_CUR=1,
    SF_VFS_SEEK_END=2
};

enum sf_vfs_find_mode_enum
{
    SF_VFS_FIND_FILE=1,
    SF_VFS_FIND_DIR=2,
    SF_VFS_FIND_ALL=SF_VFS_FIND_FILE|SF_VFS_FIND_DIR
};

#define sf_vfs_file_addref(fd)                  (fd)->__vftab->AddRef((sf_vfs_file*)(fd))
#define sf_vfs_file_release(fd)                 (fd)->__vftab->Release((sf_vfs_file*)(fd))
#define sf_vfs_file_close(fd)                   (fd)->__vftab->vfs_file_close((sf_vfs_file*)(fd))
#define sf_vfs_file_read(fd,buf,sz,rsz)         (fd)->__vftab->vfs_file_read((sf_vfs_file*)(fd),buf,sz,rsz)
#define sf_vfs_file_write(fd,buf,sz,rsz)        (fd)->__vftab->vfs_file_write((sf_vfs_file*)(fd),buf,sz,rsz)
#define sf_vfs_file_seek(fd,offset,orig)        (fd)->__vftab->vfs_file_seek((sf_vfs_file*)(fd),offset,orig)
#define sf_vfs_file_commit(fd)                  (fd)->__vftab->vfs_file_commit((sf_vfs_file*)(fd))
#define sf_vfs_file_tell(fd,poffset)            (fd)->__vftab->vfs_file_tell((sf_vfs_file*)(fd),poffset)
#define sf_vfs_file_chsize(fd,sz)               (fd)->__vftab->vfs_file_chsize((sf_vfs_file*)(fd),sz)
#define sf_vfs_file_eof(fd)                     (fd)->__vftab->vfs_file_eof((sf_vfs_file*)(fd))
#define sf_vfs_file_trunc(fd)                   (fd)->__vftab->vfs_file_trunc((sf_vfs_file*)(fd))
#define sf_vfs_file_getlasterror(fd)            (fd)->__vftab->vfs_file_getlasterror((sf_vfs_file*)(fd))
#define sf_vfs_file_filelength(fd,psize)        (fd)->__vftab->vfs_file_filelength((sf_vfs_file*)(fd),psize)

#define sf_vfs_release(fs)                      (fs)->__vftab->Release((sf_vfs*)(fs))
#define sf_vfs_addref(fs)                      (fs)->__vftab->AddRef((sf_vfs*)(fs))
#define sf_vfs_open_file(fs,file,mode,pfile)    (fs)->__vftab->vfs_open_file((sf_vfs*)(fs),file,mode,pfile)
#define sf_vfs_getlasterror(fs)                 (fs)->__vftab->vfs_getlasterror((sf_vfs*)(fs))
#define sf_vfs_rename(fs,name,newname)          (fs)->__vftab->vfs_rename((sf_vfs*)(fs),name,newname)
#define sf_vfs_getattr(fs,name,pattr)           (fs)->__vftab->vfs_getattr((sf_vfs*)(fs),name,pattr)
#define sf_vfs_setattr(fs,name,attr)            (fs)->__vftab->vfs_setattr((sf_vfs*)(fs),name,attr)
#define sf_vfs_getaccess(fs,name,paccess)       (fs)->__vftab->vfs_getaccess((sf_vfs*)(fs),name,paccess)
#define sf_vfs_setaccess(fs,name,access)        (fs)->__vftab->vfs_setaccess((sf_vfs*)(fs),name,access)
#define sf_vfs_remove(fs,name)                  (fs)->__vftab->vfs_remove((sf_vfs*)(fs),name)
#define sf_vfs_getcwd(fs,buf,maxlen)            (fs)->__vftab->vfs_getcwd((sf_vfs*)(fs),buf,maxlen)
#define sf_vfs_chcwd(fs,path)                   (fs)->__vftab->vfs_chcwd((sf_vfs*)(fs),path)
#define sf_vfs_mkdir(fs,name)                   (fs)->__vftab->vfs_mkdir((sf_vfs*)(fs),name)
#define sf_vfs_rmdir(fs,name)                   (fs)->__vftab->vfs_rmdir((sf_vfs*)(fs),name)
#define sf_vfs_exists(fs,name,mode)             (fs)->__vftab->vfs_exists((sf_vfs*)(fs),name,mode)
#define sf_vfs_getfileinfo(fs,name,pinfo)       (fs)->__vftab->vfs_getfileinfo((sf_vfs*)(fs),name,pinfo)
#define sf_vfs_enum_first(fs,path,mode,pinfo)   (fs)->__vftab->vfs_enum_first((sf_vfs*)(fs),path,mode,pinfo)
#define sf_vfs_enum_next(fs,pinfo)              (fs)->__vftab->vfs_enum_next((sf_vfs*)(fs),pinfo)
#define sf_vfs_enum_close(fs)                   (fs)->__vftab->vfs_enum_close((sf_vfs*)(fs))
#define sf_vfs_getfreespace(fs,path,psize)      (fs)->__vftab->vfs_getfreespace((sf_vfs*)(fs),path,psize)


#define SF_CLSID_IUnknown_L 0x00000010
#define SF_CLSID_IUnknown_H 0x00001219
#define SF_CLSID_IUnknown SF_CLSID_IUnknown_L,SF_CLSID_IUnknown_H


#define SF_CLSID_IVFS_L 0x00000030
#define SF_CLSID_IVFS_H 0x00001219
#define SF_CLSID_IVFS SF_CLSID_IVFS_L,SF_CLSID_IVFS_H

#define SF_CLSID_ISFTimer_L 0x00000030
#define SF_CLSID_ISFTimer_H 0x00001226
#define SF_CLSID_ISFTimer SF_CLSID_ISFTimer_L,SF_CLSID_ISFTimer_H

#define SF_CLSID_ISFNetworkManager_L    0x00000030
#define SF_CLSID_ISFNetworkManager_H    0x00001231
#define SF_CLSID_ISFNetworkManager SF_CLSID_ISFNetworkManager_L,SF_CLSID_ISFNetworkManager_H



int sf_create_object(SFUint32 l,SFUint32 h,void**ptr);




int SFApp_WriteSecureRecord(SFInt32 id_record,SFInt32 vL,SFInt32 vH);

int SFApp_ReadSecureRecord(SFInt32 id_record,SFInt32* vL,SFInt32* vH);

enum
{
    SF_STOCK_OBJ_SFGRAPHICS=1,
    SF_STOCK_OBJ_GRAPHICS=2
};

SFRESULT SFSystem_GetStockObject(SFUint type,void**p);

enum
{
    SF_MAIN_SCREEN=0
};
enum
{
    SF_PIXELFORMAT_PAL2=1,
    SF_PIXELFORMAT_PAL4,
    SF_PIXELFORMAT_PAL16,
    SF_PIXELFORMAT_PAL256,
    SF_PIXELFORMAT_RGB565,
    SF_PIXELFORMAT_RGB555,
    SF_PIXELFORMAT_ARGB1555,
    SF_PIXELFORMAT_RGB444,
    SF_PIXELFORMAT_ARGB4444,
    SF_PIXELFORMAT_RGB888,
    SF_PIXELFORMAT_XRGB8888,
    SF_PIXELFORMAT_ARGB8888
};
typedef struct _SFScreenInfo
{
    SFUint16 iScreenId; //!< [IN|OUT] 
    SFUint16 iFlags;    //!< 
    void* pBits;        
    SFUint16 iFormat;
    SFUint16 iWidth;
    SFUint16 iHeight;
    SFUint16 iPitch;
} SFScreenInfo;

SFReason SFScreen_GetInfo(SFScreenInfo* pInfo);
SFReason SFScreen_UpdateEx(SFInt id,SFInt x,SFInt y,SFInt w,SFInt h);

struct _SFAppPlatformFeatureNode;

typedef struct _SFAppPlatformFeatureNode SFAppPlatformFeatureNode;

struct _SFAppPlatformFeatureNode
{
    const SFAppPlatformFeatureNode* pNextFeature;
    SFUint32 iFeatureType;
};

enum SFAppPlatformFeatures
{
    SFAPPPLAT_FEATURE_NONE=0,
    SFAPPPLAT_FEATURE_KEYBOARD=1,//!< 按键支持
    SFAPPPLAT_FEATURE_TOUCH=1<<1,//!< 触摸支持
    SFAPPPLAT_FEATURE_WAP=1<<2,//!< 弹出WAP浏览器支持
    SFAPPPLAT_FEATURE_SMS=1<<3,//!< 短信发送支持
    SFAPPPLAT_FEATURE_SOCKET=1<<4,//!< SOCKET支持
    SFAPPPLAT_FEATURE_FAST_MEM=1<<5,//!< 快速内存支持
    SFAPPPLAT_FEATURE_GRAPHICS_ARC=1<<6,//!< ARC支持
    SFAPPPLAT_FEATURE_API2=1<<15
};

struct _SFAppPlatformInfo;

typedef struct _SFAppPlatformInfo SFAppPlatformInfo;

struct _SFAppPlatformInfo

{
    SFUint32 iPlatformVersion;
    SFUint32 iAPIVersion;
    SFUint32 iPlatformFeature;
    const SFAppPlatformFeatureNode* iFeatureDetail;
} ;

//内部信息
struct _SFAppPlatformSysInfo;

typedef struct _SFAppPlatformSysInfo SFAppPlatformSysInfo;

struct _SFAppPlatformSysInfo
{
    const UChar* iManufacture;//最长32个UNICODE UCS-2 的字符串，算上'\0'结尾
    const char iIMEI[16];
};

struct _SFAppPlatformSysInfo2;

typedef struct _SFAppPlatformSysInfo2 SFAppPlatformSysInfo2;

struct _SFAppPlatformSysInfo2
{
    SFUint8 iWapDataAccount;
    SFUint8 iNetDataAccount;
};



#define APK_MANIFEST__MOD_ID                "APK-Mod-ID"
#define APK_MANIFEST__MOD_NAME              "APK-Mod-Name"
#define APK_MANIFEST__MOD_DESC              "APK-Mod-Desc"
#define APK_MANIFEST__MOD_TYPE              "APK-Mod-Type"
#define APK_MANIFEST__MOD_LANG              "APK-Mod-Lang"
#define APK_MANIFEST__MOD_ICON              "APK-Mod-Icon"
#define APK_MANIFEST__MOD_VENDOR            "APK-Mod-Vendor"
#define APK_MANIFEST__MOD_LOCALHEAPSIZE     "APK-Mod-LocalHeapSize"
#define APK_MANIFEST__MOD_PATH              "APK-Mod-Path"



#ifdef __cplusplus
}
#endif //__cplusplus

#endif //!__SNOWFISH_API__H__

