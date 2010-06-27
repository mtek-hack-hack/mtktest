/* ------------------------------------------------------------
  Copyright (C) 汉王科技股份有限公司, 2006
  
  File:       HWAPI.h

  创建者：秦建辉 jhqin@hanwang.com.cn

  日期：2006年8月8日

  关键字：英文＋泰文版 UNICODE编码 代码字典集成
------------------------------------------------------------ */

#ifndef __HWAPI_H
#define __HWAPI_H
#define HANWANG_DICINTEGRATION				//字典集成
/* -----------识别范围--------------- */
#define ALC_THAICON			0x00000001     // Thai Consonant 0x0E01 ~ 0x0E2E
#define ALC_THAIVOW			0x00000002     // Thai Vowel     0x0E30 ~ 0x0E3A, 0X0E40 ~0x0E44, 0x0E47
#define ALC_THAISIGN		0x00000004     // Thai Sign      0x0E2F, 0x0E45, 0x0E46, 0x0E5A, 0x0E5B, 0x0E4C ~ 0x0E4F
#define ALC_THAIDIGI		0x00000008     // Thai Digit     0x0E50 ~ 0x0E59
#define ALC_THAITONE		0x00000010     // Thai ToneMark  0x0E48 ~ 0x0E4B 
#define ALC_THAICUR			0x00000020     // Thai Currency  0x0E3F

#define ALC_UCALPHA			0x00000040		//大写字母	Uppercase Latin characters ( A-Z )
#define ALC_LCALPHA			0x00000080		//小写字母	Lowercase Latin characters ( a-z )

#define ALC_NUMERIC			0x00000100		//数字	Number ( 0-9 )

#define ALC_PUNCTUATION		0x00000200		/* punctuation marks 
                                                !	0021	Exclamation（感叹号）
                                                "	0022	Double Quotation Marks（双引号）
                                                ,	002C	Comma（逗号）
                                                ：	003A	Colon（冒号）
                                                ；	003B	Semicolon（分号）
                                                ?	003F	Question Mark（问号）
                                                '	0027	Single Quotation Marks（单引号）
                                                (	0028	Left Bracket（左圆括号）
                                                )	0029	Right Bracket（右圆括号）
                                                */
#define ALC_SYMBOL          0x00000400      /* Symbols
                                                #	0023	Number（井号）
                                                $	0024	Dollar（美元符号）
                                                %	0025	Percent Sign （百分比符号）
                                                &	0026	Ampersand（与符号）
                                                *	002A	Asterisk （星号）
                                                +	002B	Plus Sign（加号）
                                                -	002D	Subtraction Sign（减号）
                                                .	002E	Dot（点）
                                                /	002F	Virgule（斜线号）
                                                <	003C	Is less than Sign（小于号）
                                                =	003D	Is less than（等于号）
                                                >	003E	Is more than（大于号）
                                                @	0040	AT（单价号）
                                                ［	005B	Left square brackets（左方括号）
                                                ］	005D	Right square brackets（右方括号）
                                                \	005C	Backlash（反斜线）
                                                _	005F	Underline（下划线）
                                                `	0060	Apostrophe（所有格符号）
                                                ｛	007B	（左大括号）
                                                ｝	007D	（右大括号）
                                                |	007C	
                                                ~	007E	Swung dash（代字号）
                                                */
#define	ALC_GESTURE			0x00000800		/* Control gesture
											  Space(0x20), Carriage Return(0x0d), 
                                              Backspace(0x08), Toggle 0x0010	*/

//-----------------输出自动转换-------------------------------------
#define OUT_LOWERCASE		0x20000000	//自动将大写字母转成小写字母
#define OUT_UPPERCASE		0x40000000	//自动将小写字母转成大写字母
#define OUT_FULLWIDTH		0x80000000	//输出全角字符

//-----------------常用组合-----------------------------------------
#define CHARSET_ENGLISH			(ALC_UCALPHA | ALC_LCALPHA)			//英文识别
#define CHARSET_THAILAND		(ALC_THAICON | ALC_THAIVOW | ALC_THAISIGN | ALC_THAIDIGI | ALC_THAITONE | ALC_THAICUR) //泰文识别

/* ----------------定义手势编码值------------------------------- */
#define CODE_BACKSPACE			0x0008	//回删
#define CODE_TOGGLE				0x0010	//Toggle
#define CODE_RETURN				0x000D	//回车
#define CODE_SPACE				0x0020	//空格

//---------------常量定义----------------------------
#define MAXCANDNUM				10			// 可提供的最大候选字个数
#define HWRERAMSIZE				(14*1024)	// 引擎需要的临时运算空间大小

//------------笔迹结构定义-------------------
#define STROKEENDMARK			(-1)		// 定义笔画结束标记值

typedef struct tagTHWPoint
{
	short x; // 笔迹 X 坐标
	short y; // 笔迹 Y 坐标
} THWPoint;

//------------识别属性定义------------------
typedef struct tagTHWAttribute
{
	unsigned long	dwRange;	// 识别范围	
	int	iCandidateNum;	// 用户需要的候选字个数。
	int	iBoxWidth;		// 书写框宽度，不需要则设成 <= 0
	int	iBoxHeight;		// 书写框高度，不需要则设成 <= 0
	unsigned char*	pRam;		// 运算空间，大小为 HWRERAMSIZE，要求起始地址4字节对齐
	unsigned char*	pRom;
} THAI_THWAttribute;

#ifdef __cplusplus
extern "C" {
#endif

/*
功能：笔迹识别
参数说明：
	pTrace：笔迹数据，其格式为(x1,y1),(x2,y2),...,(STROKEENDMARK,0),...,
	        (STROKEENDMARK,0),(STROKEENDMARK,STROKEENDMARK)，
			其中(STROKEENDMARK,0)为笔画结束标志，
			(STROKEENDMARK,STROKEENDMARK)为字结束标志。
	pAttr：识别属性。
	pResult：识别结果。其缓冲区大小为 HWRESULTBUFSIZE。	
返回值：
	=-1:错误的运算空间
	= 0:拒识
	> 0:候选字个数
*/
int HWRecognizeThai( const THWPoint* pTrace, const THAI_THWAttribute* pAttr, unsigned short* pResult );

#ifdef __cplusplus
}
#endif

#endif
