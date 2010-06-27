//////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                          WDXT Software System                             //
//                                                                           //
//            Copyright (c) 1999-2007 by Netone Technology Inc.              //
//                        All Rights Reserved                                //
//                                                                           //
//  Model    :	WD_Def.h                                                     //
//                                                                           //
//  Purpose  :	供外部使用的手写输入法的公共定义                             //
//                                                                           //
//  Designer :	srw,wd,nyf,zsq,rocky                                         //
//                                                                           //
// --------------------------------------------------------------------------//
//                                                                           //
//  $Workfile:: WD_HwDef.h                                                   //
//  $Date: 2007/08/02 02:59:54 $										 	 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

#ifndef WD_HWDEFINES
#define WD_HWDEFINES


	#define MAX_WORD_DATA 500		//最多的点数
	#define MAX_LETTERS_COUNT 32 //单词最大长度
	#define MAX_WORD_COUNT 10//最大单词个数

	#define WD_SYMBOL		0x01//数字

	#define WD_ENGLISH  	0x20//英文
	#define WD_RUSSIAN		0x21//俄文
	#define WD_THAI			0x22//泰文
	#define WD_ARAB			0x23//阿拉伯文
	#define WD_VIET			0x24//越南文
	#define WD_JAPANESE		0x25//日文

typedef struct WD_HwData_t
{
	WD_UINT16 width;		//手写板的宽度
	WD_UINT16 height;		//手写板的高度
	WD_UINT16 imeType;		//手写输入法类型
	WD_UINT16 maxsize;		//手写输入时最多可以接受的数据个数
	WD_UINT32 flag;			//保留参数,一般情况下传0即可
}WD_HwData;

typedef struct WD_useData_
{
	WD_UINT16* studyDataBuf;
	WD_UINT16* dataBuf;
	WD_UINT16* strokeDataBuf;
}WD_useData;


///////////////////手写输入法初始化///////////////////////
//														 /
//参数: pHwData, WD_HwData结构的指针 后三个参数自学习使用/
//返回: 成功返回0,失败返回负数,为错误代码                /
//                                                       /
//////////////////////////////////////////////////////////
WD_INT16 WD_HwInitialize(WD_HwData* pHwData,WD_useData* usedata);



///////////切换输入法//////////////////
WD_INT16 WD_HwSwitchIme(WD_UINT16 imeType);





///////////////////手写输入法识别函数/////////////////////
//														 /
//参数: data,传入用于识别的数据; letters,返回识别的结果  /
//      (备选字母列表);									 /
//					   rev保留参数,可以传0               /
//返回: 成功返回0,失败返回负数,为错误代码                /
//														 /
//////////////////////////////////////////////////////////
WD_INT16 WD_HwOnIdentify(WD_INT16* data, WD_UINT16* letters, WD_UINT32 rev);

///////////////////手写输入法识别扩展函数/////////////////
//														 /
//参数: stroke_buffer,传入用于识别的数据;				 /
//		candidate_array,返回识别的结果					 /
//					   rev保留参数,可以传0               /
//返回: 成功返回0,失败返回负数,为错误代码                /
//														 /
//////////////////////////////////////////////////////////

WD_INT16 WD_HwOnIdentify_Ex(WD_UINT16* stroke_buffer,WD_UINT16* candidate_array,WD_UINT32 rev);

//////////////////自学习功能函数///////////////////////
//													 //
//  参数:letter 要学习的字符，dataBuf 保存数据的空间 //
//  返回: 成功返回0,失败返回负数,为错误代码          //
//													 //
///////////////////////////////////////////////////////

WD_UINT8 WD_HWSetChars(WD_UINT16* letter);

//////////////////联想字功能函数///////////////////////
//													 //
//  参数:letter 联想字符的首字						 //
//  返回: 成功返回0,失败返回负数,为错误代码          //
//													 //
///////////////////////////////////////////////////////

WD_UINT8 WD_GetAssociation(WD_UINT16 letter);



////////////////得到字符集指针和长度////////////////////
//													 //
//													 //
//													 //
///////////////////////////////////////////////////////
WD_UINT8 WD_GetLetterTable();









#endif
