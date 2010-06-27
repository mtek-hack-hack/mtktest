/*================================================================

 C   M O D U L E   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2000-2003
 ALL RIGHTS RESERVED

================================================================

工程名称		: mBrowser Ver3.3
 
文件名			: CmsBrowserReturn.h

功能描述		: mBrowser核心接口函数返回值定义

最近修改时间	: 11/5/2003
 
代码编写人员	: 乐海勇

================================================================*/

#ifndef CMSBROWSERRETURN_H
#define CMSBROWSERRETURN_H

/*========================= 浏览器各模块接口函数返回值 =======================*/

typedef enum _CMS_BROWSER_RET
{
	/*=== 补充的返回值 ===*/
	E_CMS_PARSER_HTML = -259,			/* 解析text/html的脚本 */

	/*=== table模块返回值 ===*/
	E_CMS_TABLE_NOCSS = -258,			/*=== 没有css属性 ===*/
	E_CMS_TABLE_NOELEMENT = -257,		/*=== 移动焦点没有发现焦点元素 ===*/
	E_CMS_TABLE_OUTOFSCRREN = -256,		/*=== td不在显示区之中 ===*/
		
	/*=== 缓存模块返回值 ===*/
	E_CMS_CACHE_SAVEERROR = -255,		/*=== 保存缓存信息文件失败 ===*/
	E_CMS_CACHE_FILEERROR = -254,		/*=== 缓存信息文件被破坏 ===*/
	E_CMS_CACHE_INVALIDCACHE = -253,	/*=== 无效CACHE信息 ===*/
	
	/*=== 设置模块返回值 ===*/
	E_CMS_SU_SAVEERROR = -252,			/*=== 保存设置文件失败 ===*/
	E_CMS_SU_INVALIDHOMEPAGE = -251,	/*=== 无效主页 ===*/
	E_CMS_SU_INVALIDGATEWAY = -250,		/*=== 无效网关 ===*/
	
	/*=== 书签模块返回值 ===*/
	E_CMS_BM_SAVEERROR = -249,			/*=== 保存书签设置文件失败 ===*/
	E_CMS_BM_RECORDFULL = -248,			/*=== 书签记录已满 ===*/
	E_CMS_BM_INVALIDURL = -247,			/*=== 无效URL ===*/
	E_CMS_BM_INVALIDTITLE = -246,		/*=== 无效标题 ===*/
	E_CMS_BM_INVALIDID = -245,			/*=== 错误的书签索引号 ===*/
	
	/*=== 历史记录模块返回值 ===*/
	E_CMS_HISTROY_INVALIDURL = -244,	/*=== 无效URL信息 ===*/
	
	/*=== 初始化模块返回值 ===*/
	E_CMS_INITBROWSER_NOTFREE = -243,	/*=== 上一次的浏览信息未被释放 ===*/
	E_CMS_INITBROWSER_SAVEPAGE = -242,	/*=== 页面保存模块初始化失败 ===*/
	E_CMS_INITBROWSER_INITAUTO = -241,	/*=== 解析自动机初始化失败 ===*/
	E_CMS_INITBROWSER_INPUTURL = -240,	/*=== URL输入模块初始化失败 ===*/
	E_CMS_INITBROWSER_CACHE = -239,		/*=== 缓存模块初始化失败 ===*/
	E_CMS_INITBROWSER_BOOKMARK = -238,	/*=== 书签模块初始化失败 ===*/
	
	/*=== URL输入模块返回值 ===*/
	E_CMS_INPUTURL_RECORDFULL = -237,	/*=== URL记录已满 ===*/
	E_CMS_INPUTURL_SAVEERROR = -236,	/*=== 保存输入URL信息文件失败 ===*/
	E_CMS_INPUTURL_INVALIDID = -235,	/*=== 错误的URL列表索引号 ===*/
	
	/*=== 页面保存模块返回值 ===*/
	E_CMS_SAVEPAGE_INVALIDID = -234,	/*=== 错误的页面保存列表索引号 ===*/
	E_CMS_SAVEPAGE_RECORDFULL = -233,	/*=== 页面保存记录已满 ===*/
	E_CMS_SAVEPAGE_FILEERROR = -232,	/*=== 已存信息文件被破坏或无法进行写操作 ===*/
	
	/*=== WBMP模块返回值 ===*/
	E_CMS_WBMP_INVALID = -231,			/*=== WBMP图片尺寸无效 ===*/
	E_CMS_WBMP_TYPEERROR = -230,		/*=== 非WBMP格式 ===*/
	E_CMS_WBMP_FILEERROR = -229,		/*=== 文件打开失败 ===*/
	
	/*=== 网络模块返回值 ===*/
	E_CMS_NETWORK_HEADMESSAGE = -228,	/*=== HTTP头信息不足 ===*/
	E_CMS_NETWORK_FILEERROR = -227,		/*=== 文件操作错误 ===*/
	E_CMS_NETWORK_NEEDDOWNLOAD = -226,	/*=== 需要继续下载 ===*/
	E_CMS_NETWORK_UNKNOWNFILE = -225,	/*=== 不支持的下载文件类型 ===*/
	E_CMS_NETWORK_DIALFAILED = -224,	/*=== 拨号失败 ===*/
	E_CMS_NETWORK_INVALIDSOCKET = -223,	/*=== 无效套接字 ===*/
	E_CMS_NETWORK_SETSOCKETFAIL = -222,	/*=== 设置套接字属性失败 ===*/
	E_CMS_NETWORK_GETHOSTFAIL = -221,	/*=== 域名解析失败 ===*/
	E_CMS_NETWORK_CONNECTFAIL = -220,	/*=== 连接服务器失败 ===*/
	E_CMS_NETWORK_TCPSENDFAIL = -219,	/*=== TCP发送数据失败 ===*/
	E_CMS_NETWORK_TCPRECVFAIL = -218,	/*=== TCP接收数据失败 ===*/

	/*=== 解析模块返回值 ===*/
	E_CMS_PARSER_HEADMESSAGE = -217,	/*=== HTTP头信息不足 ===*/
	E_CMS_PARSER_DATAFILEERROR = -216,	/*=== 解析结果临时文件错误 ===*/
	E_CMS_PARSER_GETDATAERROR = -215,	/*=== 获取解析结果错误 ===*/
	E_CMS_PARSER_PARAMERROR = -214,		/*=== 内部变量错误 ===*/
	E_CMS_PARSER_UNKNOWNCHARSET = -213,	/*=== 无效字符集 ===*/
	E_CMS_PARSER_ATTRTOOLONG = -212,	/*=== 属性超长 ===*/

	/*=== 排版模块返回值 ===*/
	E_CMS_LAYOUT_INVALID = -211,		/*=== 显示坐标无效 ===*/
	E_CMS_LAYOUT_FEWDATA = -210,		/*=== 排版链表不全，需要继续解析 ===*/
	E_CMS_LAYOUT_SCRIPT = -209,			/*=== 不支持的脚本内容 ===*/
	
	/*=== 触摸屏模块返回值 ===*/
	E_CMS_PENDOWN_INVALID = -208,		/*=== 坐标无效 ===*/
	E_CMS_PENDOWN_SCRIPT = -207,		/*=== 点击坐标对应了脚本内容 ===*/

	/*=== 公用错误号 ===*/
	E_CMS_BROWSER_INVALIDINPUT = -1,	/*=== 输入非法 ===*/
	E_CMS_BROWSER_NOMEMORY = 0,			/*=== 内存耗尽 ===*/

	/*=== 无错时的返回值 ===*/
	CMS_BROWSER_RET_OK = 1,				/*=== 操作正确 ===*/
	CMS_BROWSER_WMLONEVENT = 2,			/*=== WML ON事件 ===*/
	CMS_BROWSER_WMLONFORWARD = 3,		/*=== WML前转事件 ===*/
	CMS_BROWSER_WMLONBACKWARD = 4,		/*=== WML后转事件 ===*/
	CMS_BROWSER_WMLONTIMER = 5,			/*=== WML定时器事件 ===*/
	CMS_BROWSER_CURRENTPARSEROVER = 6,	/*=== 当前块全部解析完毕 ===*/
	CMS_BROWSER_PARSEROVER = 7,			/*=== 网页全部解析完毕 ===*/
	CMS_BROWSER_DOWNLOADIMG = 8,		/*=== 下载图片 ===*/
	CMS_BROWSER_PENDOWNVALID = 9,		/*=== 点击坐标对应了有效的URL ===*/
	CMS_BROWSER_PENDOWNEDIT = 10,		/*=== 点击坐标对应了参数编辑事件 ===*/
	CMS_BROWSER_PENDOWNSELECT = 11,		/*=== 点击坐标对应了控件选择事件 ===*/
	CMS_BROWSER_PENDOWNREFRESH = 12,	/*=== 点击坐标对应了刷新事件 ===*/

	CMS_BROWSER_LAYOUTTABLE = 13,		/*=== 排版table事件 ===*/
	CMS_BROWSER_ISDRAWING   = 14,
	CMS_BROWSER_DOWNLOAD    = 15,		/*=== 需要下载事件 ===*/

	CMS_BROWSER_VERSION		= 0xFFFF	/* 版本信息 */
}CMS_BROWSER_RET;

#endif
