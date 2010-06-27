/*==============================================================

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

==============================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsBrowserCfg.c

功能描述		: 核心数据结构以及宏定义

最近修改时间	: 10/17/2003
 
代码编写人员	: 乐海勇

==============================================================*/

#ifndef CMSBROWSERCFG_H
#define CMSBROWSERCFG_H

/*=================== Head ===================*/

#include "CmsBrowserPublic.h"

#include "Cmsnetwork.h"
#include "CmsHttp.h"
#include "CmsGif.h"



/*=================== Macros ===================*/

/*======== 支持功能宏定义 ========*/
			
//#define		NEED_SMALLARRAY		/*=== 某些编译系统对于数组大小有限制，此时应当打开此开关 ===*/

/* 触摸屏支持 */
#if defined( _D_DANIEL ) && !defined( SUPPORT_TOUCHPANEL )
#	define SUPPORT_TOUCHPANEL
#endif

/* SELECT控件支持 */
#if defined( SUPPORT_TOUCHPANEL ) && !defined( SUPPORT_OPTIONSELECT_POPUP )
#	define SUPPORT_OPTIONSELECT_POPUP
#endif

#define		NEW_LINKFOCUS

#define		SUPPORT_UNICODE			/* Thunis 支持unicode */
#define		SUPPORT_GIF				/*=== GIF支持开关 ===*/
#define		SUPPORT_JPEG			/*=== JPEG支持开关 ===*/
#define		SUPPORT_WBMP			/*=== WBMP支持开关 ===*/
//#define		SUPPORT_BMP				/*=== BMP支持开关 ===*/
#define		SUPPORT_PNG				/*=== PNG支持开关 ===*/

//#define		SUPPORT_WEB				/*=== WEB浏览器开关(屏蔽为不支持) ===*/
#define		SUPPORT_WML				/*=== WAP浏览器开关(屏蔽为不支持) ===*/
#define		SUPPORT_CACHE			/*=== CACHE开关 ===*/
//#define		SUPPORT_HTTP11			/*=== 包括分块传送和相关头信息发送 ===*/
#define		SUPPORT_COOKIES			/*=== COOKIE开关 ===*/


#define		CMSCONTENTCACHE			/*=== 打开有效数据缓冲功能，可以提高浏览速度 ===*/

/*== add by roger for Tcentel 03/31/2004 ==*/
//#define		SUPPORT_WAPSTACK 		/*=== 当WAP协议栈由他方提供时，请关闭此宏 ===*/
#define 	CACHE_FOR_TCENTEL		/*=== write a new cache modules for Tcentl ===*/

/*======== 变量宏定义 ========*/

#ifdef SUPPORT_WML
#define		CMS_DEFAULT_WAPGATEWAY	"127.0.0.1"	/*=== 默认WAP网关的IP地址 ===*/
#define		CMS_DEFAULT_WAPPORT		9201			/*=== 默认WAP网关端口 ===*/
#endif
	
#define		CMS_CONFIG_SPACEMARK	0x0a			/*=== 配置文件记录间隔符 ===*/
#define		CMS_STOREURIFILE		"cmsuri.cnf"	/*=== 用户输入URL记录文件 ===*/
#define		CMS_CONTDATAFILE		"cmscont.dat"	/*=== 网页有效内容临时文件 ===*/
#define		CMS_UNI2GBFILE			"cmsuni2gb.txt"	/*=== UTF-8转码索引表文件 ===*/
#define		CMS_BOOKMARKFILE		"cmsbook.cnf"	/*=== 用户书签记录文件 ===*/
#define		CMS_SETUPFILE			"cmssetup.cnf"	/*=== 用户设置记录文件 ===*/
#define		CMS_SAVEPAGEFILE		"cmssave.cnf"	/*=== 用户保存页面记录文件 ===*/
#define		CMS_CACHEINFOFILE		"cmscache.cnf"	/*=== 用户Cache记录文件 ===*/
#define     CMS_CACHEDATAFILE       "cachedata.dat"     /*===cache数据文件===*/
#define    	CMS_PUSHFILE			"cmspushfile.cnf"	/*=== PUSH info录文件 ===*/

#define     MAXRECV					(3*512)		/*=== 一次接受的最大长度 ===*/
#define     DLLENONCE					(30*1024)	/*=== 下载块的最大长度，也是能够处理的最大WML长度 ===*/
#define		DEFAULT_HTTPPORT		80			/*=== 默认HTTP协议端口号 ===*/

#define		m_MaxState				66//65			/*=== 解析状态数 ===*/
#define		DNSLEN					128			/*=== 最大DNS长度(HTTP协议规范) ===*/
#define		MAX_CACHEFILE			50			/*=== 最大cache文件数 ===*/
//#define		MAX_CACHEFLASH			(150*1024)	/*=== Cache文件占用FLASH容量最大值 ===*/
#define		URLLEN					1500		/*=== 绝对URI的最大长度 ===*/
//#define		PARAMLEN				1400			/*=== 提交参数的最大长度 ===*/
#define		PARAMLEN				1600			/*=== 提交参数的最大长度 ===*///为了可以接收512个字的input值。
//#define		VALUELEN                512			/*=== 每一个参数的最大长度 ===*/
#define		INPUT_FILE_BUFFER_SIZE	DLLENONCE	/*=== 一次解析的最大长度 ===*/
#define		PAGECONTENTCACHELENGTH	DLLENONCE	//(10*1024)	/*=== 存放网页有效内容缓冲区的最大长度 ===*/
#define		FILENAMELENGTH			128			/*=== 系统规定的文件名长度 ===*/

#define     MAX_ATTR_VALUE_LENGTH   2*1024

#define		CMS_DEFAULT_FONT_COLOR	0			/* 默认显示字体为黑色 */
#define		CMS_DEFAULT_FONT_SIZE	"宋体"		/* 默认显示字体为宋体 */
#define		CMS_DEFAULT_FONT_TYPE	1			/* 默认显示字体为宋体 */

#define  INBUF_SIZE			(20480)	/* inbuf size every time */
#define  INBUF_MAXSIZE		(50*1024)	/* inbuf max size		 */
#define  HTTP_DATA_LENGTH  (50*1024)

#define  GET_INBUF_CHAR(pre) (*(pBrowserInfo->pParserInfo->inbuf + pre))
#define  SET_INBUF_CHAR(pos,c) {*(pBrowserInfo->pParserInfo->inbuf + pos) = c;}



/*=================== 全局错误号宏定义 ===================*/				

/*=== 网络模块错误号 ===*/
#define  CMS_BROWSER_OPENNETERROR			-1001		/*=== 拨号失败 ===*/
#define  CMS_BROWSER_CLOSENETERROR			-1002		/*=== 挂断失败 ===*/
#define  CMS_BROWSER_CREATESOCKERROR		-1003		/*=== 创建SOCKET失败 ===*/
#define  CMS_BROWSER_CLOSESOCKERROR			-1004		/*=== 关闭SOCKET失败 ===*/
#define  CMS_BROWSER_GETHOSTERROR			-1005		/*=== 服务器地址解析错误 ===*/
#define  CMS_BROWSER_CONNECTHOSTFAIL		-1006		/*=== 连接服务器失败 ===*/
#define  CMS_BROWSER_TCPSENDFAIL			-1007		/*=== 发送TCP信息失败 ===*/
#define  CMS_BROWSER_UDPSENDTOFAIL			-1008		/*=== 发送UDP信息失败 ===*/
#define  CMS_BROWSER_TCPRECVFAIL			-1009		/*=== 接收TCP信息失败 ===*/
#define  CMS_BROWSER_UDPRECVFROMFAIL		-1010		/*=== 接收UDP信息失败 ===*/
#define  CMS_BROWSER_FILEACCESSFAIL			-1011		/*=== 创建文件操作失败 ===*/
#define  CMS_BROWSER_SETTIMERERROR			-1012		/*=== 设置网络定时器失败 ===*/
#define  CMS_BROWSER_NETWORKTIMEOUT			-1013		/*=== 网络超时 ===*/
#define  CMS_BROWSER_WAPCONNECTFAIL			-1014		/*=== 连接WAP网关失败 ===*/
#define  CMS_BROWSER_WAPABORT				-1015		/*=== WAP请求被网关拒绝 ===*/
#define  CMS_BROWSER_WBMLPARSERERROR		-1016		/*=== WBML解析错误 ===*/

#define  CMS_NEW_URL_EVENT_FLAG             0XFFFF
#define  CMS_NEW_URL_EVENT_FLAG_RESTORE     0X0000
#define  CMS_JUMP_INFOBOX_FLAG_RESTORE		0X00
#define  CMS_JUMP_INFOBOX_FLAG				0xFF
/*======== 核心数据类型定义 ========*/
#ifndef TI
#if defined(__cplusplus) && __cplusplus
extern "C" {
#endif
#endif


#if 0	
typedef struct   m_tagPAGEHEADELE  m_PAGEHEADELE;		
typedef          m_PAGEHEADELE    *m_PageHeadEle;

/*=== 页头元素链表 ===*/
struct m_tagPAGEHEADELE
{
	P_CMS_BROWSER_VOID	head;	/*=== 当前页头元素 ===*/
//	P_CMS_BROWSER_VOID	tail;		/* 用于记录前页的最后一个元素滕永*/
	m_PageHeadEle		next;	/*=== 后续头元素链表 ===*/
};
#endif

typedef struct   m_tagATTRIBUTE  m_ATTRIBUTE;			
typedef          m_ATTRIBUTE    *m_Attribute;
/*=== 属性数据结构 ===*/
struct m_tagATTRIBUTE
{
	m_Attribute		m_next;		/*=== 下一个属性 ===*/
	CMS_BROWSER_U8	m_type;		/*=== 属性类型 ===*/
	MC_PCC_FILL_STRUCT3
	CMS_BROWSER_U64	m_vstart;	/*=== 属性值在临时文件(缓冲区)中的起始地址 ===*/
	CMS_BROWSER_U16	m_vlength;	/*=== 属性值的长度 ===*/
	MC_PCC_FILL_STRUCT2
};


/*=== 一般元素链表结构定义 ===*/
typedef struct m_tagELEMENT  m_ELEMENT;					
typedef        m_ELEMENT    *m_Element; 

/*=== 文本元素链表结构定义 ===*/
typedef struct m_tagTEXTELEMENT  m_TEXTELEMENT;		
typedef        m_TEXTELEMENT    *m_TextElement; 

/*=== 控件元素链表结构定义 ===*/
typedef struct m_tagCONTROLELEMENT  m_CONTROLELEMENT;
typedef        m_CONTROLELEMENT    *m_ControlElement;

/*=== 图片元素链表结构定义 ===*/
typedef struct m_tagIMAGEELEMENT  m_IMAGEELEMENT;	
typedef        m_IMAGEELEMENT    *m_ImageElement;

/*=== 可显示元素的x坐标，如果显示宽度小于256，可以设置为CMS_BROWSER_U8型，
内存耗费可以减少12％~20％ ===*/
typedef CMS_BROWSER_U8 CMS_BROWSER_ELEMENT_X_TYPE;

/*=== 联合体类型的前序元素 ===*/
typedef union _PREVELEMENT
{
	m_Element			m_prev;			/*=== 前序一般元素 ===*/
	m_TextElement		m_textprev;		/*=== 前序文本元素 ===*/
	m_ImageElement		m_imageprev;	/*=== 前序图片元素 ===*/
	m_ControlElement	m_controlprev;	/*=== 前序控件元素 ===*/

}m_PREVELEMENT;

/*=== 联合体类型的后序元素 ===*/
typedef union _NEXTELEMENT
{	
	m_Element			m_next;			/*=== 后序一般元素 ===*/
	m_TextElement		m_textnext;		/*=== 后序文本元素 ===*/
	m_ImageElement		m_imagenext;	/*=== 后序图片元素 ===*/
	m_ControlElement	m_controlnext;	/*=== 后序控件元素 ===*/

}m_NEXTELEMENT;

/*=== 一般元素链表结构定义 ===*/
struct m_tagELEMENT
{
	CMS_BROWSER_U8	m_ElTypeNum;	/*=== 元素类型 ===*/
	MC_PCC_FILL_STRUCT3
	m_Element		parent;			/* parent ele	  */
	void*			css_style;      /* css_style      */
	m_PREVELEMENT	prevelement;	/*=== 前序元素 ===*/
	m_NEXTELEMENT	nextelement;	/*=== 后序元素 ===*/
	m_Attribute		m_attribute;	/*=== 元素属性 ===*/		
};

/*=== 文本元素链表结构定义 ===*/
struct m_tagTEXTELEMENT
{
	CMS_BROWSER_U8		m_ElTypeNum;	/*=== 元素类型 ===*/
	
	MC_PCC_FILL_STRUCT3
	
	m_Element		parent;			/* parent ele	  */
	void*			css_style;		/* css_style      */

	m_PREVELEMENT		prevelement;	/*=== 前序元素 ===*/
	m_NEXTELEMENT		nextelement;	/*=== 后序元素 ===*/
	CMS_BROWSER_U64		m_start;		/*=== 文本值在临时文件(缓冲区)中的起始地址 ===*/	
	CMS_BROWSER_U16		m_length;		/*=== 文本值长度 ===*/
	CMS_BROWSER_U16     ty;				/*=== 起始行数(非页内行数) ===*/				
	CMS_BROWSER_U16     by;				/*=== 终止行数(非页内行数) ===*/
	CMS_BROWSER_ELEMENT_X_TYPE tx;		/*=== 起始X坐标 ===*/			
	CMS_BROWSER_ELEMENT_X_TYPE bx;		/*=== 终止X坐标 ===*/

	/*潘正海添加, 2004-10-25, 文本元素的颜色和字体*/
	CMS_BROWSER_U32			font_color;   /*  保存先前字体的颜色 潘正海 10-25*/
	CMS_BROWSER_U32			bg_color;
	
	CMS_BROWSER_U8			font_type;	  /*  保存先前字体的类型 潘正海 10-25*/	
	CMS_BROWSER_U8			isdrawed;		/*  是否已被画过 */

	CMS_BROWSER_S16			anchor_count;	/*	anchor 计数器 */ 
	
	CMS_BROWSER_S32         letterspace;	/*  字符间距     */

	CMS_BROWSER_U32			margin[4];
	CMS_BROWSER_U32         border_color[4];
	CMS_BROWSER_U16			border_style[4];
	CMS_BROWSER_U16			border_width[4];	
	CMS_BROWSER_S32         leftspace;
};

/*=== 控件元素链表结构定义 ===*/
struct m_tagCONTROLELEMENT
{
	CMS_BROWSER_U8		m_ElTypeNum;	/*=== 元素类型 ===*/
	MC_PCC_FILL_STRUCT3
	m_Element		parent;			/* parent ele	  */
	void*			css_style;		/* css_style      */

	m_PREVELEMENT		prevelement;	/*=== 前序元素 ===*/
	m_NEXTELEMENT		nextelement;	/*=== 后序元素 ===*/
	m_Attribute			m_attribute;	/*=== 控件元素属性 ===*/
	CMS_BROWSER_U8		m_start;		/*=== SELECT元素中可选项的个数，RADIO和CHECKBOX元素是否被选中(1:是 0:非) ===*/
	MC_PCC_FILL_STRUCT3
	CMS_BROWSER_U16		m_length;		/*=== SELECT元素中可选项的最大字符数 ===*/
	CMS_BROWSER_U16     ty;				/*=== 起始行数(非页内行数) ===*/								
	CMS_BROWSER_U16     by;				/*=== 终止行数(非页内行数) ===*/	
	CMS_BROWSER_ELEMENT_X_TYPE tx;		/*=== 起始X坐标 ===*/								
	CMS_BROWSER_ELEMENT_X_TYPE bx;		/*=== 终止X坐标 ===*/	
};

/*=== 图片元素链表结构定义 ===*/
struct m_tagIMAGEELEMENT
{
	CMS_BROWSER_U8		m_ElTypeNum;
	MC_PCC_FILL_STRUCT3
	
	m_Element		parent;			/* parent ele	  */
	void*			css_style;		/* css style      */
	m_PREVELEMENT		prevelement;
	m_NEXTELEMENT		nextelement;
	m_Attribute			m_attribute;
	P_CMS_BROWSER_U8	filename;
	CMS_BROWSER_U16     width;								
	CMS_BROWSER_U16     height;								
	CMS_BROWSER_U16     ty;	
	CMS_BROWSER_U16     by;					/* 图片结束行 */
	
	CMS_BROWSER_ELEMENT_X_TYPE     tx;								
	CMS_BROWSER_ELEMENT_X_TYPE     bx;	
	
	Cms_ContentType_e 				imagetype;	
	
	CMS_BROWSER_U32			margin[4];
	CMS_BROWSER_U32         border_color[4];
	CMS_BROWSER_U16			border_style[4];
	CMS_BROWSER_U16			border_width[4];
	
	CMS_BROWSER_S16			anchor_count;		/* anchor计数器 */
	MC_PCC_FILL_STRUCT2
};

/************************** Network information ******************/

/*=== 历史记录结构定义 ===*/


/* 潘正海rewrite历史记录*/
struct _HISTORYNODE;
typedef struct _HISTORYNODE HISTORYNODE;
typedef HISTORYNODE* P_HISTORYNODE;

struct _HISTORYNODE
{
	CMS_BROWSER_BOOL method;
	unsigned int     prevtabindex;
	P_CMS_BROWSER_U8 param;
	P_CMS_BROWSER_U8 url;
	P_HISTORYNODE    next;
	P_HISTORYNODE	 pre;
};

struct _HISTORY;
typedef struct _HISTORY HISTORY;
typedef HISTORY *P_HISTORY;

struct _HISTORY
{
	P_HISTORYNODE  histroy_head;
	P_HISTORYNODE  histroy_cur;
	P_HISTORYNODE  histroy_tail;
	CMS_BROWSER_U32 histroy_curnum;
};



/*=== 网络连接信息结构定义 ===*/
typedef struct _CONNECT								
{
		CMS_BROWSER_BOOL			reConnect;			/*=== 重连接(HTTP状态为3XX) ===*/
		CMS_BROWSER_U16				PORT;				/*=== 连接端口 ===*/
//		MC_PCC_FILL_STRUCT2
// 		CMS_BROWSER_U8				dns[DNSLEN];		/*=== DNS ===*/
		CMS_BROWSER_U16				mutateURLlen;
		P_CMS_BROWSER_U8			url;		/*=== URL ===*/		
		CMS_BROWSER_U8				path[URLLEN];		/*=== 路径 ===*/

		CMS_BROWSER_BOOL			METHOD;				/*=== 连接方式(CMS_BROWSER_FALSE---GET  CMS_BROWSER_TRUE---POST) ===*/
		CMS_BROWSER_U8				param[PARAMLEN];	/*=== 提交参数 ===*/
		P_CMS_BROWSER_U8			CurrentParam;		
		
} CONNECT, *P_CONNECT;


#define COOKIECONTENTLENGTH		256	/*=== META元素中出现的COOKIE最大长度 ===*/

typedef struct _COOKIE							/*=== COOKIE结构定义 ===*/									
{
		CMS_BROWSER_BOOL	SetCookie;			/*=== 当前页面提交是否要求携带COOKIE ===*/
		P_CMS_BROWSER_U8	CookieContent;		/*=== COOKIE内容 ===*/
		P_CMS_BROWSER_U8 	CookieUrl;			/*=== COOKIE作用域 ===*/
		CMS_BROWSER_U8		MetaSetCookieContent[COOKIECONTENTLENGTH];	/*=== 网页中的COOKIE内容 ===*/
		
} COOKIE, *P_COOKIE;


typedef struct _CMS_BROWSER_NETWORKINFO		/*=== 网络信息结构定义 ===*/
{	
	CMS_BROWSER_S32		NETWORK_ERR_NUM;	/*=== 网络错误号 ===*/
	CMS_BROWSER_BOOL	Proxy;				/*=== 使用代理 ===*/
	P_CONNECT			pConnect;			/*=== 网络连接信息 ===*/
	P_COOKIE			pCookie;			/*=== COOKIE结构 ===*/
	P_HISTORY 			pHistory;			/*=== 历史记录 ===*/
		
} CMS_BROWSER_NETWORKINFO, *P_CMS_BROWSER_NETWORKINFO;



/*********************** Parser information **********************/

#define m_MaxGIlength	50

typedef CMS_BROWSER_U8		m_State;
typedef struct 		_m_Transition *m_PtrTransition;

typedef struct 		_m_Transition
{
     CMS_BROWSER_U8		m_trigger;	
     MC_PCC_FILL_STRUCT3
     m_State			m_newState;	
     m_PtrTransition	m_nextTransition;

} m_Transition;


typedef struct m_StateDescr
{				
     m_State			m_automatonState;
     m_PtrTransition	m_firstTransition;
} m_StateDescr;


typedef struct m_sourceTransition
{
     m_State			m_initState;
     CMS_BROWSER_U8		m_trigger;
     MC_PCC_FILL_STRUCT3
     m_State			m_newState;
} m_sourceTransition;


#ifdef SUPPORT_WML

/*=== WML变量列表数据结构定义 ===*/
typedef struct tagVarlist VARLIST;
typedef  VARLIST *VarlistPtr;
struct tagVarlist
{
	CMS_BROWSER_S32		escape;		/*=== 0:noesc  1:escape  2:unesc ===*/
	P_CMS_BROWSER_U8	varname;	/*=== 变量名 ===*/
	P_CMS_BROWSER_U8	varvalue;	/*=== 变量值 ===*/
	VarlistPtr			next;		/*=== 变量列表指针 ===*/
};

/*=== WML事件列表数据结构定义 ===*/
typedef struct tagEventlist EVENTLIST;
typedef EVENTLIST *EventlistPtr;

struct tagEventlist
{
	P_CMS_BROWSER_U8	Eventtype;	
    P_CMS_BROWSER_U8	Eventdelay;
    P_CMS_BROWSER_U8	Eventname;
	P_CMS_BROWSER_U8	Eventlabel;
	m_Element			event_element;
	EventlistPtr		nextevent;
	CMS_BROWSER_U16     ty;			//可根据
	CMS_BROWSER_U16     by;			//实际情况
	CMS_BROWSER_ELEMENT_X_TYPE tx;	//改变
	CMS_BROWSER_ELEMENT_X_TYPE bx;	//类型
	MC_PCC_FILL_STRUCT2
};


typedef  struct tagWMLCARD WMLCARD;
typedef  WMLCARD *WMLCARDPtr;

struct tagWMLCARD
{
	WMLCARDPtr			next;
	WMLCARDPtr			prev;
	m_Element			root;
	EventlistPtr		firstevent;
	P_CMS_BROWSER_U8	cardID;
	P_CMS_BROWSER_U8	cardTitle;
	CMS_BROWSER_BOOL	newContext;
};

typedef struct tagDECK DECK;
typedef DECK *DECKPtr;

struct tagDECK
{
	m_Element		root;
	EventlistPtr	firstevent;
	WMLCARDPtr		firstcard;
	WMLCARDPtr		currcard;
} ;

#define TIME_LEN 10
typedef struct _WMLTREE					/*=== WML解析结构定义 ===*/
{
	CMS_BROWSER_U8	OnTimerValue[10];	/*=== ONTIMER事件延时量 ===*/
	MC_PCC_FILL_STRUCT2
	DECKPtr			WmlDeck;
	VarlistPtr		WmlVar;
	EventlistPtr    OnTimerEvent;
		
} WMLTREE, *P_WMLTREE;

typedef enum
{	
		CMS_CARD_ID,			/*=== 0: ID属性 ===*/
		CMS_CARD_TITLE,			/*=== 1: TITLE属性 ===*/
		CMS_CARD_ONTIMER,		/*=== 2: ONTIMER属性 ===*/
		CMS_CARD_ONFORWARD,		/*=== 3: ONFORWARD属性 ===*/
		CMS_CARD_ONBACKWARD,	/*=== 4: ONBACKWARD属性 ===*/
		CMS_CARD_NEWCONTEXT,	/*=== 5: NEWCONTEXT属性 ===*/
		CMS_CARD_UNSUPPORT		/*=== 5: 不支持的属性 ===*/

}CMS_CARD_ATTRIBUTETYPE;

typedef enum
{	
		CMS_TIMER_NAME,			/*=== 0: KEY属性 ===*/
		CMS_TIMER_VALUE,		/*=== 1: VALUE属性 ===*/
		CMS_TIMER_DEFAULT,		/*=== 2: DEFAULT属性 ===*/
		CMS_TIMER_UNSUPPORT		/*=== 3: 不支持的属性 ===*/

}CMS_TIMER_ATTRIBUTETYPE;

typedef enum
{	
		CMS_EVENT_TYPE,			/*=== 0: TYPE属性 ===*/
		CMS_EVENT_NAME,			/*=== 1: NAME属性 ===*/
		CMS_EVENT_LABEL,		/*=== 2: LABEL属性 ===*/
		CMS_EVENT_UNSUPPORT		/*=== 3: 不支持的属性 ===*/

}CMS_EVENT_ATTRIBUTETYPE;
#endif


#ifdef  SUPPORT_HTTP11
typedef struct _CHUNKED										/*=== 网页块传送信息结构定义 ===*/
{
		CMS_BROWSER_BOOL		ChunkNotOver;
		CMS_BROWSER_BOOL		Chunked;
		CMS_BROWSER_U64 		ChunkSize;
		CMS_BROWSER_U8			ChunkContent[10];
		MC_PCC_FILL_STRUCT2
		
} CHUNKED, *P_CHUNKED;

#endif 


#ifdef CMSCONTENTCACHE
typedef struct	_PAGECONTENTCACHE
{
	CMS_BROWSER_U64		StartInDataFile;
	CMS_BROWSER_U64		ContentLength;
	CMS_BROWSER_U8		Content[PAGECONTENTCACHELENGTH];

} CMS_PAGECONTENTCACHE;
#endif


/* 定义css类型指针 滕永 8-12*/
typedef void * P_BR_CSS;



typedef struct _CMS_BROWSER_PARSERINFO 
{
	
	CMS_BROWSER_BOOL        m_match;
	m_PtrTransition			m_trans;   
	CMS_BROWSER_U32         m_currentState; 
	m_StateDescr			m_automaton[m_MaxState];
	
	CMS_BROWSER_FILEHANDLE	OutputFile;


	unsigned char			*inbuf;			/* parser buf	*/
	unsigned int			inbuf_size;		/* buf size		*/	
	unsigned int			inbuf_usedsize;	/* used size	*/

		
//	CMS_BROWSER_U8			OutBuffer[INPUT_FILE_BUFFER_SIZE+1];	//	解析缓冲区,存放单个元素或属性的内容
//	MC_PCC_FILL_STRUCT3
#ifdef CMSCONTENTCACHE
	CMS_PAGECONTENTCACHE	ContentCache;
#else	
	CMS_BROWSER_U8			OutData[INPUT_FILE_BUFFER_SIZE+1];		//	解析缓冲区,存放解析后的有效内容
	MC_PCC_FILL_STRUCT3
#endif
	CMS_BROWSER_U8			EleAttrName[m_MaxGIlength];				//	元素名称
	CMS_BROWSER_U8			ParserFileName[FILENAMELENGTH];			//	要解析的文件名
	CMS_BROWSER_U16			Cms_long,Cms_Verylong;					//	依次为:  当前文件(数组)偏移量
																	
	CMS_BROWSER_U32			CurCharInFileBuffer;				
	CMS_BROWSER_U32			LastCharInFileBuffer;
	CMS_BROWSER_U64			Cms_now, FileOffset;					//  已解析的字符数
	CMS_BROWSER_U16			Upnum;									//  上翻的页数,用于控制上翻多次在下翻时,若已经
	MC_PCC_FILL_STRUCT2
																	//    显示过,则直接显示,而不是下载后在显示
	m_Element				Cms_root,Cms_pro;
	m_Element				Cms_DownFirstEle;
	m_TextElement			Cms_text;
	m_ControlElement		Cms_control;
	m_ImageElement			Cms_image;
	
	CMS_BROWSER_BOOL		Cms_WML_InCard;
	CMS_BROWSER_BOOL		Cms_WML_InTask;	
	CMS_BROWSER_BOOL		Cms_WML_InTimer;
	CMS_BROWSER_BOOL		Cms_WML_InTimerVar;
	CMS_CARD_ATTRIBUTETYPE	Cms_WML_CardAttType;
	CMS_TIMER_ATTRIBUTETYPE	Cms_WML_TimerAttType;
	CMS_EVENT_ATTRIBUTETYPE	Cms_WML_EventAttType;

	CMS_BROWSER_U8	    	LastElementIsScript;					//  脚本内容
	CMS_BROWSER_U8		  	Cms_Charnum;
	MC_PCC_FILL_STRUCT2

	CMS_BROWSER_BOOL    	Check_Ele;								//  有效元素
	CMS_BROWSER_BOOL    	Check_Attr;								//  有效属性
	CMS_BROWSER_BOOL		TextErr;								//  处理<< >>	
	CMS_BROWSER_BOOL		IsLessThan;								//  处理<以及之后的文本内容
	CMS_BROWSER_BOOL		EndHtmlAnchor;							//  链接元素结束
	CMS_BROWSER_BOOL		ParserOver;

#ifdef SUPPORT_WML
	P_WMLTREE				pWmlTree;
#endif

#ifdef  SUPPORT_HTTP11
	P_CHUNKED				pChunk;									//  网页为块传送的数据结构
#endif   


	P_BR_CSS			    p_head_css;	/* 头内的css 滕永 8-12*/


} CMS_BROWSER_PARSERINFO, *P_CMS_BROWSER_PARSERINFO;



/*********************** Layout information **********************/

typedef struct	_CMS_PREVIMGINFO
{
	CMS_BROWSER_U16					Width;
	CMS_BROWSER_U16					Height;
	CMS_BROWSER_U16					ty;
	CMS_BROWSER_U16					by;
	CMS_BROWSER_ELEMENT_X_TYPE		tx;
	MC_PCC_FILL_STRUCT1

}CMS_PREVIMGINFO;


/*======== GIF movie Play Information ========*/
#ifdef SUPPORT_GIF
#ifndef OS_SUPPORT_GIF

typedef struct _Cms_Browser_GIFMovie	*P_CMS_BROWSER_GIFMOVIE;

typedef struct _Cms_Browser_GIFMovie
{
	P_CMS_BROWSER_U8		GIFFilename;			/*=== GIF文件名 ===*/
	CMS_BROWSER_S32			FileHandle;			/*== */
	CMS_BROWSER_S32			BeSingleFrame;			/*== */
	CMS_BROWSER_S32			Playing;			/*== */
	CMS_BROWSER_U32			x;
	CMS_BROWSER_U32			y;
	CMS_BROWSER_U32			width;				/*=== 实际显示宽度 ===*/
	CMS_BROWSER_U32			height;				/*=== 实际显示高度 ===*/
	CMS_BROWSER_U32			GIFMovieID;				/*=== 当前页多帧GIF动画索引 ===*/
	CMS_BROWSER_U32			CurrGIFMovieFrameID;	/*=== 当前帧ID ===*/
	CMS_BROWSER_OS_TIMER	GIFMovieTimer;			/*=== 定时器 ===*/
	GIFStream				*pGIFMovieStream;		/*=== GIF图片数据结构 ===*/
	P_CMS_BROWSER_U16		GIFImageData;			/*=== GIF图片点阵数据 ===*/
	MC_PCC_FILL_STRUCT2
	P_CMS_BROWSER_GIFMOVIE	pNextGIFMovie;			/*=== 下一个GIF图片 ===*/
	
	double x_proportion;      /***	gif压缩比例  ***/    
	double y_proportion;      /***	gif压缩比例  ***/

	unsigned int bg_color;    /*** gif图片的背景色 ***/
	
}CMS_BROWSER_GIFMOVIE;

#endif
#endif

/*=== 2004-10-30 Accesskey&BGSound ===*/
/*=== accesskey链表结构定义 ===*/
typedef struct m_tagACCESSKEY  CMS_BR_ACCESSKEY;
typedef CMS_BR_ACCESSKEY  *P_CMS_BR_ACCESSKEY;

struct m_tagACCESSKEY
{
	P_CMS_BROWSER_U8 pKey;
	m_Element pElement;
	P_CMS_BR_ACCESSKEY pNextAccesskey;
};

/*=== 背景音乐结构 ===*/
typedef struct m_tagBGSOUND 
{
	P_CMS_BROWSER_U8 pURL;
	P_CMS_BROWSER_U8 pFileName;
	CMS_BROWSER_S32 loop;
	CMS_BROWSER_U32 status;	/*=== 状态 0：无效 1：下载中 2：下载结束 3：播放中 ===*/
	Cms_ContentType_e content_type;

}CMS_BR_BGSOUND;
/*=== 2004-10-30 Accesskey&BGSound end ===*/


#ifdef CMS_NOTOUCHPANNEL

typedef struct LinkFocusTabTag LinkFocusTabT;

struct LinkFocusTabTag
{
	void*			pFocusObject;
	LinkFocusTabT*  next;
	LinkFocusTabT*	prev;
	P_CMS_BROWSER_U8 linkname;
	CMS_BROWSER_U16	tabindex;
	CMS_BROWSER_U16 objectflag;      /* 1: 元素, 2: 二叉树结点, 3: 事件 */
};

typedef struct LinkFocusInPageTag LinkFocusInPageT;

struct LinkFocusInPageTag
{
	void*				pFocus;		  /* 第一个字节会用来表示objectflag */
	LinkFocusInPageT*	next;
	LinkFocusInPageT*	prev;
};

typedef struct LinkFocusTag
{
	LinkFocusTabT*	pTablist;			/* 一个页面中按tabindex排序的焦点元素链表 */
	LinkFocusTabT*	curFocus;			/* 当前的tabindex结点 */
//	LinkFocusTabT*	prevFocus;

	LinkFocusInPageT* head;				 //焦点头结点
	LinkFocusInPageT* tail;					//焦点尾结点

	void*			  curFocusObj;
	void*			  prevFocusObj;

}LinkFocusT;

#endif

struct _CMS_BROWSER_FILELIST;
typedef struct _CMS_BROWSER_FILELIST CMS_BROWSER_FILELIST;
typedef CMS_BROWSER_FILELIST* P_CMS_BROWSER_FILELIST;

struct _CMS_BROWSER_FILELIST
{
	char*					filename;	
	int						length;
	int						type;
	P_CMS_BROWSER_FILELIST	next;		
};

// MarkFocus 的标记状态值
typedef enum tagMarkState
{
    MS_DEFAULT = 0,     // 未选中  
    MS_SELECTED,        // 选中
    MS_DESELECTED       // 去选中
}CMS_MARKSTATE;
#define SELECTED_COLOUR 0x000000FF // 选中颜色

typedef struct _CMS_BROWSER_LAYOUTINFO 
{	
	CMS_BROWSER_ELEMENT_X_TYPE	px;
	MC_PCC_FILL_STRUCT3
	CMS_BROWSER_U16				py;
	CMS_BROWSER_U16 			PageTopLine;


	/*=== 2004-10-30 Accesskey&BGSound ===*/
	CMS_BR_BGSOUND				BGSound;
	P_CMS_BR_ACCESSKEY			pAccesskey;
	/*=== 2004-10-30 Accesskey&BGSound end ===*/

	m_Element					SelectElement;
	//add by roger
	m_IMAGEELEMENT				CurImgElement;


	CMS_BROWSER_U8				LayoutStatus;
	CMS_BROWSER_U8				DrawFromHead;
	MC_PCC_FILL_STRUCT2
	
	P_CMS_BROWSER_U8 			CurrentTitle;
	CMS_BROWSER_BOOL        	Ontimer;
	CMS_BROWSER_U16 			ImgCurrent;
	CMS_BROWSER_U16 			ImgTotal;
	
	CMS_BROWSER_BOOL			NoframeOver;
	


	struct 
	{
		CMS_BROWSER_U16 current;
		CMS_BROWSER_U16 total;
	//	m_PageHeadEle headchain;

	}Cms_PageHead; 

	CMS_PREVIMGINFO	PrevImgInfo; 

#ifdef SUPPORT_GIF
#ifndef OS_SUPPORT_GIF
	P_CMS_BROWSER_GIFMOVIE		pGIFMovie;
#endif
#endif
	
#ifdef CMS_NOTOUCHPANNEL
	CMS_BROWSER_U8	MarkFocus;
	MC_PCC_FILL_STRUCT3
	
	LinkFocusT		LinkFocus;		

#endif
	
	P_CMS_BROWSER_FILELIST	pFileList;

	/* 记录再次排版前的显示页面信息 */
//	void*               DisplayPtr;
	EventlistPtr		DisplayEvent;
	m_Element			DisplayElement;
	CMS_BROWSER_S32		TopLineOffSET; 	
		
} CMS_BROWSER_LAYOUTINFO, *P_CMS_BROWSER_LAYOUTINFO;

/*======== InputURLHistory Information ========*/

typedef struct _Cms_Browser_InputHistory
{
	CMS_BROWSER_S32		Total;
	CMS_BROWSER_S32		Current;
	P_CMS_BROWSER_U8	url[MAX_INPUTDNS];

} CMS_BROWSER_INPUTHISTORY;



/*======== 枚举当前browser的状态 ========*/
typedef enum
{
	IDLE_STATE	  ,				/* 空闲状态			*/
	DOWNLOAD_STATE,				/* 下载状态			*/
	DOWNLOADING_ITEM_STATE,		/* 下载需要保存状态 */
	INVALID_URL_STATE,			/* 非法url			*/
	TEMP_STATE	= 0x3FFFFFFF	/* temp state		*/
}E_WAP_STATE;




/*======== BrowserBookmark Information ========*/

typedef struct _Cms_Browser_Bookmark
{
	P_CMS_BROWSER_U8 title;
	P_CMS_BROWSER_U8 url;

}CMS_BROWSER_BOOKMARK;

typedef struct _Cms_Browser_Display
{
	CMS_BROWSER_U16			Display_Screen_W;
	CMS_BROWSER_U16			Display_Screen_H;

	CMS_BROWSER_U16			Display_Scrollbar_W;
	CMS_BROWSER_U16			Display_Title_H;

	CMS_BROWSER_U16			Display_Statusbar_W;
	CMS_BROWSER_U16			Display_Statusbar_H;


	CMS_BROWSER_U16			Display_Select_H;
	CMS_BROWSER_U16			Display_Font_W;


	CMS_BROWSER_U16			Display_Origin_X_D;
	MC_PCC_FILL_STRUCT2

}CMS_BROWSER_DISPLAYDATA, *P_CMS_BROWSER_DISPLAYDATA;


/*======== mini_Browser  information ========*/

typedef struct _CMS_BROWSERINFO 
{
	CMS_BROWSER_U16				PenDnX;
	MC_PCC_FILL_STRUCT2
	CMS_BROWSER_U16				PenDnY;
	MC_PCC_FILL_STRUCT2
	
	CMS_BROWSER_U8				DelayTime;	
	MC_PCC_FILL_STRUCT3
	CMS_BROWSER_GUI_LANGUAGE	Language;				/*=== 显示语言 ===*/
	CMS_BROWSER_S32				Network;
	CMS_BROWSER_OS_TIMER		WMLTimer;
	CMS_BROWSER_OS_TIMER		HTMLRefreshTimer;
	Cms_ContentType_e			FileType;
	P_CMS_BROWSER_U8			DlFileName;
	MC_PCC_FILL_STRUCT3
	CMS_BROWSER_BOOL			DownloadOver;
	CMS_BROWSER_BOOL			BeginWrite;
	CMS_BROWSER_BOOL       		IsWml;	
	CMS_BROWSER_BOOL       		UrlChange;	
	CMS_BROWSER_BOOL			UserCancle;
	CMS_BROWSER_BOOL			NetNoSignal;
	
	CMS_BROWSER_BOOL			DnsChange;	
	CMS_BROWSER_BOOL			LastPage;				/*=== 是否为最后一页 ===*/
	
	CMS_BROWSER_BOOL			HtmlRefresh;							//网页重载
	CMS_BROWSER_BOOL			NoDisplay;
	CMS_BROWSER_BOOL			WmlCard;
	CMS_BROWSER_BOOL			ForEvent;
	CMS_BROWSER_BOOL			BackEvent;
	CMS_BROWSER_BOOL			Back;
	CMS_BROWSER_BOOL			stop;
	CMS_BROWSER_BOOL			Cms_WAP_Working;		/*=== WAP协议栈是否处于工作状态 ===*/

	CMS_BROWSER_BOOL			DisplayImg;
	CMS_BROWSER_BOOL			BrowserLocalFile;
	CMS_BROWSER_BOOL			BrowserCacheFile;
	CMS_BROWSER_BOOL			Refresh;								//刷新功能
	CMS_BROWSER_BOOL			Bookmark;
	CMS_BROWSER_BOOL			SupportCache;
	CMS_BROWSER_BOOL			CacheOption;
	
	CMS_BROWSER_BOOL			EditType;			/*=== CMS_BROWSER_TRUE: PASSWORD  CMS_BROWSER_FALSE: TEXT ===*/	
	CMS_BROWSER_U32				EditMaxlength;		/*=== 最大编辑长度 ===*/
	
	P_CMS_BROWSER_VOID			LayoutOverElement;
	CMS_BROWSER_U16				ImgFileID;
	MC_PCC_FILL_STRUCT2
	CMS_BROWSER_U8				CardId[120];
	CMS_BROWSER_U8				ImgFileName[FILENAMELENGTH];
	CMS_BROWSER_U8				HomePageUrl[URLLEN];
	CMS_BROWSER_U8 				WAPGateway[DNSLEN];		/*=== WAP 网关 ===*/
	MC_PCC_FILL_STRUCT2
	CMS_BROWSER_U16				WAPPort;				/*=== WAP 端口号 ===*/
	MC_PCC_FILL_STRUCT2
		
	CMS_BROWSER_INPUTHISTORY	InputUrlHistory;
	CMS_BROWSER_BOOKMARK		BookmarkInfo[BOOKMARKNUM];
	//CMS_SIL_PUSH				SILPUSHInfo[CMS_MAX_PUSH];

	//add by roger
	CMS_BROWSER_STATE_STR		BrowserState;
	CMS_BROWSER_U32				IsBusy;
	CMS_BROWSER_U32				Browserexitflag;
	CMS_BROWSER_U32				IsBrwWorking;//0:not working;1:working.


	CMS_BROWSER_S32				IsLayoutImg;
	CMS_BROWSER_S32				IsBrwStop;
	CMS_BROWSER_S32				PlayingGifNum;
	CMS_BROWSER_S32				IsGifLoad;
	CMS_BROWSER_S32				IsDownloadFile;
	CMS_BROWSER_S32				PrevPageTime;
	CMS_BROWSER_S32				ShowSoftKey;

	CMS_BROWSER_S32				IsRedirectDownload;
	CMS_BROWSER_S32				IsSelfDraw;
	CMS_BROWSER_S32				IsFromTimer;
	CMS_BROWSER_S32				IsDrawing;
	CMS_BROWSER_S32				IsTimerDownload;
	CMS_BROWSER_S32				IsWMLTimerRun;
	
	P_CMS_BROWSER_NETWORKINFO	pNetworkInfo;
	P_CMS_BROWSER_PARSERINFO	pParserInfo;
	P_CMS_BROWSER_LAYOUTINFO	pLayoutInfo;
	
		/*== add by roger for Tcentel ==*/
#ifdef CACHE_FOR_TCENTEL
	P_CMS_BROWSER_U8			CacheBlock;		//  Cache content for Tcentel
#endif

	Cms_EncodingType_e			encoding;			/*  当前网页内容编码 */	
    Cms_ContentType_e  current_download_content_type; /*下载类容类型,shoumingl*/

	CMS_BROWSER_U32				default_font_color; /*  默认显示字体的颜色 滕永 8-13*/
	CMS_BROWSER_U8			    default_font_type;	/*  默认的字体 滕永 8-13*/

	P_CMS_BROWSER_DISPLAYDATA	DisplayData;			/*显示用的属性*/			
	CMS_BROWSER_U8				JumpInforBoxFlag;/*弹出对话框标记,lee*/
	E_WAP_STATE					wap_state;		/* 当前wap的状态 */

	/*add by lee,临时解决异步事件冲突的问题，彻底的解决办法等待互斥机制的实现*/
	CMS_BROWSER_U16				PICnewurleventflag;
	CMS_BROWSER_U16				ABORTnewurleventflag;
	
	CMS_BROWSER_U8				CurrentAccesskeyValue[4];
} CMS_BROWSERINFO, *P_CMS_BROWSERINFO;

/* add a struct for start a post request */

typedef struct __ConnectRequestTag
{
	Cms_BR_HttpMethod_e method;
	char*				url;
	char*				param;
}ConnectRequestT;

#ifndef TI
#if defined(__cplusplus) && __cplusplus
}
#endif
#endif
/*======== Constants ========*/
/*======== Enumeration ========*/
/*======== Global Data ========*/
/*======== Function prototype ========*/


#endif
