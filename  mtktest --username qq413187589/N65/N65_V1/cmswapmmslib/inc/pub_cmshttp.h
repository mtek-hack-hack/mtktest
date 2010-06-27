#ifndef _CMSHTTP_H
#define _CMSHTTP_H
/*=== http下载文件类型定义 ===*/
typedef enum 
{
	CMS_HTTP_CONTENT_ML					= 0,				/*=== 标记语言 ===*/
	CMS_HTTP_TEXT_PLAIN,									/*普通文本类型*/
	CMS_HTTP_CONTENT_CSS,								/*=====CSS=========*/
	CMS_HTTP_CONTENT_HTML,								/* text/html content type */
	
	CMS_HTTP_CONTENT_GIF					= 20,			/*=== GIF ===*/
	CMS_HTTP_CONTENT_JPEG,								/*=== JPEG ===*/
	CMS_HTTP_CONTENT_WBMP,								/*=== WBMP ===*/
	CMS_HTTP_CONTENT_BMP,								/*=== BMP ===*/
	CMS_HTTP_CONTENT_PNG,								/*=== PNG ===*/
	CMS_HTTP_CONTENT_IMAGE_ZDD,							/*Download descriptor*/
	CMS_HTTP_CONTENT_IMAGE_VIS,							/*有关VIS的 mime type*/
	CMS_HTTP_CONTENT_IMAGE_DRM,							/*有关drm的 mime type*/
	CMS_HTTP_CONTENT_IMAGE_BILL,						/*计费信息*/
	CMS_HTTP_CONTENT_IMAGE_STL,							/*有关drm的 mime type*/
	CMS_HTTP_CONTENT_CHAOTEX_CIM,						/*=== mFlash ===*/
	CMS_HTTP_CONTENT_DZD,								/*学习机课件*/
	CMS_HTTP_CONTENT_IMAGE_KJJ,							/*Lenovo KJJ			*///chaozhu.zhou add for kjj
	
	CMS_HTTP_CONTENT_MIDI				= 50,			/*=== Midi ===*/
	CMS_HTTP_CONTENT_AMR,								/*=== ARM music ===*/
	CMS_HTTP_BROWSER_MUSIC_SMAF,
	CMS_HTTP_CONTENT_MP3,
	CMS_HTTP_CONTENT_MPEG4,
	CMS_HTTP_CONTENT_AAC,
	CMS_HTTP_CONTENT_WMA,
	CMS_HTTP_CONTENT_FJAD				= 100,
	CMS_HTTP_CONTENT_FJAR,
	CMS_HTTP_CONTENT_WMLSCRIPT,							/*====wmlscript===*/
	CMS_HTTP_CONTENT_WMLSCRIPTC,						/*====wmlscriptc===*/
	
	CMS_HTTP_CONTENT_DRM_MESSAGE    	= 150,			/*=====DRM MESSAGE== =======*/
	CMS_HTTP_CONTENT_DRM_CONTENT,						/*=====DRM CONTENT== =======*/
	CMS_HTTP_CONTENT_DRM_RIGHTS_XML,					/*=====DRM  版权描述文件== =======*/
	CMS_HTTP_CONTENT_DRM_RIGHTS_WBXML,				/*=====DRM  版权对象文件二进制描述== =======*/
	CMS_HTTP_CONTENT_DRM_XWAV,							/*=== audio/x-wav===*/
	
	CMS_HTTP_BROWER_SETTING_XML		= 200,			/*http provisioning xml doc*/
	CMS_HTTP_BROWER_SETTING_WBXML,						/*浏览器二进制XML文件*/
	CMS_HTTP_BROWER_BOOKMARK_SETTING_XML,				/*书签配置XML*/
	CMS_HTTP_BROWER_BOOKMARK_SETTING_WBXML,			/*书签二进制WBXML*/
	CMS_HTTP_BROWSER_SYNCML_XML,
	CMS_HTTP_BROWSER_SYNCML_WBXML,
	CMS_HTTP_CONTENT_MSVG,								/*=== Mobile SVG ===*/
	
	CMS_HTTP_OCTET_STREAM				= 252,			/*=== 未知类型文件STREAM ===*/
	CMS_HTTP_CONTENT_DLING_FILE			= 253,			/*=== 下载未知类型文件 ===*/
	CMS_HTTP_CONTENT_DLING_IMG			= 254,			/*=== 下载图片标记 ===*/
	CMS_HTTP_CONTENT_DLFAILED			= 255			/*=== 下载失败的文件 ===*/
	
}Cms_ContentType_e;
#endif
