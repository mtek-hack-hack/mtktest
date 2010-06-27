/*****************************************************************************
    Copyright (c) 2003-2004 MobileSoft Corporation All Rights Reserved.
    
    Created:	    2005-4-21  	
	Author:         liangl; liangl@mobilesoft.com.cn
    File name:      CmsSelectCtrl.h
    File ext:       c source file 
	
	purpose:		Select 控件处理
    History:
*******************************************************************************/
#ifndef __INC_CMS_SELECTCTRL_H__
#define __INC_CMS_SELECTCTRL_H__

#include "vwlibbase/vwmemory.h"
#include "CmsBrowserCfg.h"

VW_EXTERN_C_BEGIN

#undef  U8
#define U8	vwuint8

#undef	U16
#define U16 vwuint16

//changed by yangjun 06-02-07 for selectbox form
/**********************************************************************
 * 功能 : 绘制Select控件(接口函数).
 * 参数 : 
 *		nItemsCount		:	选择项数量.
 *		nCurrSelected	:	当前选择项.
 *		pItems			:	UTF16 编码的字符串数组,数组长度 nItemsCount.
 * 说明 :
 *		显示一个Select控件,在用户选择后,调用 
 *		Cms_Browser_SelectCtrl_UserSelecteItem 激活浏览器继续运行.
 **********************************************************************/
 #if 0
void Cms_Browser_DrawSelectCtrl( 
					U16                nItemsCount,
					U16                nCurrSelected,
/* UTF16 string  */ U8*				   strTitle ,
                    /* UTF16 string , size_is(nItemsCount) */
                    U8*                pItems[]
             );
 #endif


/************************************************************************
 * 功能 : 绘制Select控件后在用户选择后回调该函数(由CMS实现)
 * 参数 :
 *		nCurrSelected	:	用户选择项编号( [ 0 , nItemsCount - 1 ] ).
 ************************************************************************/
void Cms_Browser_SelectCtrl_UserSelecteItem( U16 nCurrSelected );

#undef U16
#undef U8

typedef 
struct tag_CmsSelectCtrlItems
{	
	vwuint16		nItemsCount;		/* 选项数目.   */
	vwuint16		nCurrSelected;		/* 当前选择项. */	
	
	vwuint8p		*pItems;			/*UTF16 string , size_is(nItemsCount) */
}	CmsSelectCtrlItems;

VWRESULT Cms_Browser_GetSelectMenuParam( 
		 		m_ControlElement    pCtrlObject ,
		/*out*/	CmsSelectCtrlItems* pParam );

void	 _Cms_Browser_ShowSelectCtrl( m_ControlElement pCtrlObject );
void Cms_Browser_DrawSelectCtrl(CmsSelectCtrlItems CtrlItems);//changed by yangjun 06-02-07 for selectbox form
VW_EXTERN_C_END

#endif