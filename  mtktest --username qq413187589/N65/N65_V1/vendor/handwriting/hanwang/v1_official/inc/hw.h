#if defined(__USE_JIETONG_HANDWRITING__)//使用捷通手写识别

#ifdef __cplusplus
extern "C"    {
#endif

#ifdef HZRECOG_EXPORTS
	#define	HZRECOGAPI __declspec( dllexport )
#else
	#define	HZRECOGAPI /*__declspec( dllimport )*/
#endif

#define HZ_VOID void
#define HZ_INT8 char
#define HZ_UINT8 unsigned char
#define HZ_INT16 short
#define HZ_UINT16 unsigned short
#define HZ_INT32 long				
#define HZ_UINT32 unsigned long		

#define HZ_BOOL HZ_INT32
#define HZ_BYTE HZ_UINT8			
#define HZ_WORD HZ_UINT16			
#define HZ_DWORD HZ_UINT32			

// Recognition Kernel Initialization
// call this function before using other functions in handwritting recognition kernel
// the pointer is ROM address for placing HZRecog.dat or is file name string
// Return value :	TRUE	success
//					FALSE	fail
HZRECOGAPI HZ_BOOL  HZInitCharacterRecognition(HZ_VOID* pPointer);

// Recognition Kernel Exit
// call this function before using other functions handwritting recognition kernel no more
// Return value :	TRUE	success
//					FALSE	fail
HZRECOGAPI HZ_BOOL  HZExitCharacterRecognition(HZ_VOID);

#define RECOG_RANGE_NUMBER			0x00000001		// 数字，0~9十个数字
#define RECOG_RANGE_UPPERCASE		0x00000002		// 大写字母，26个
#define RECOG_RANGE_LOWERCASE		0x00000004		// 小写字母，26个
#define RECOG_RANGE_INTERPUNCTION	0x00000008		// 标点符号，31个
#define RECOG_RANGE_GESTURE			0x00000010		// 笔势符号
///// 以下这些定义不要使用
#define RECOG_RANGE_GB1_ONLY		0x00000100
#define RECOG_RANGE_GB1_BIG51		0x00000200
#define RECOG_RANGE_GB1_BIG52		0x00000400
#define RECOG_RANGE_GB2_ONLY		0x00000800
#define RECOG_RANGE_GB2_BIG51		0x00001000
#define RECOG_RANGE_GB2_BIG52		0x00002000
#define RECOG_RANGE_BIG51_ONLY		0x00004000
#define RECOG_RANGE_BIG52_ONLY		0x00008000
#define RECOG_RANGE_GBK_ONLY		0x00010000
///// 以上这些定义不要使用
#define RECOG_RANGE_ADAPTATION		0x10000000		// 自学习字

// 国标一级汉字，总共3755个汉字
#define RECOG_RANGE_GB1				(RECOG_RANGE_GB1_ONLY | RECOG_RANGE_GB1_BIG51 | RECOG_RANGE_GB1_BIG52)
// 国标二级汉字，总共3008个汉字
#define RECOG_RANGE_GB2				(RECOG_RANGE_GB2_ONLY | RECOG_RANGE_GB2_BIG51 | RECOG_RANGE_GB2_BIG52)
// Big5常用汉字，总共5401个汉字
#define RECOG_RANGE_BIG51			(RECOG_RANGE_GB1_BIG51 | RECOG_RANGE_GB2_BIG51 | RECOG_RANGE_BIG51_ONLY)
// Big5非常用汉字，总共7659个汉字
#define RECOG_RANGE_BIG52			(RECOG_RANGE_GB1_BIG52 | RECOG_RANGE_GB2_BIG52 | RECOG_RANGE_BIG52_ONLY)

// 字母符号，总共52个大小写字母
#define RECOG_RANGE_SYMBOL			(RECOG_RANGE_UPPERCASE | RECOG_RANGE_LOWERCASE)
// 国标一二级汉字，总共6763个汉字
#define RECOG_RANGE_GB				(RECOG_RANGE_GB1 | RECOG_RANGE_GB2)
// Big5汉字，总共13060个汉字
#define RECOG_RANGE_BIG5			(RECOG_RANGE_BIG51 | RECOG_RANGE_BIG52)
// GBK全部汉字，总共21003个汉字
#define RECOG_RANGE_GBK				(RECOG_RANGE_GB | RECOG_RANGE_BIG5 | RECOG_RANGE_GBK_ONLY)
#define RECOG_RANGE_ALL				(RECOG_RANGE_NUMBER | RECOG_RANGE_SYMBOL | RECOG_RANGE_INTERPUNCTION | RECOG_RANGE_GESTURE | RECOG_RANGE_GBK | RECOG_RANGE_ADAPTATION)
// Main Recognition Function
// Return value is recognition result number, its valid value are [-1, MAX_CANDIDATE_NUM]
// pnStrokeBuffer is handwritting buffer of Chinese character.
// (x, y) make up one point, and x and y are short type, their valid value are from -1 to 32767.
// (-1, 0) is end flag of stroke, (-1, -1) is end flag of character.
// pwResultBuffer is recognition result buffer, we recommend its size are MAX_CANDIDATE_NUM+1
// uMatchRange is one of four kinds of match_range or combination of them. Note: it is not null(zero)
// moreover, uMatchRange may include ADAPTATION_MATCH_RANGE only after calling 'HZInitAdaptation'
HZRECOGAPI HZ_INT32  HZCharacterRecognize(HZ_INT16* pnStrokeBuffer, HZ_WORD* pwResult, HZ_INT32 iMaxCandNum, HZ_UINT32 uMatchRange);

#ifdef __cplusplus
}
#endif 

#else  //__USE_JIETONG_HANDWRITING__

#ifndef BYTE
#define BYTE unsigned char
#define WORD unsigned short
#define DWORD unsigned long

typedef BYTE *LPBYTE; 
typedef WORD *LPWORD;
typedef DWORD *LPDWORD;

#if !defined(WIN32) 
#define WINAPI
#else
#define WINAPI __stdcall
#endif
#endif

#define	HWX_COMMON_SIMPLE_CHS		0x0001		/*GB2312 Level1*/
#define	HWX_RARE_SIMPLE_CHS			0x0002		/*GB2312 Level2,²»°üº¬?«??*/
#define	HWX_COMMON_TRADITIONAL_CHS	0x0004		/*BIG5 Level1*/
#define	HWX_RARE_TRADITIONAL_CHS	0x0008		/*BIG5 Level2*/
#define	HWX_HK						0x0010		/*Hong Kong character */
#define	HWX_TRADITIONAL_TO_SIMPLE	0x0020		/*?Ž·±µ??ò£¬?»???ò?å?¶±ð???¹??*//*For Simple Chinese recognizer,
												Recognize some traditional characters,
												and change the result code to relative simplified character code */
#define	HWX_SIMPLE_TO_TRADITIONAL	0x0040		/*?Ž?òµ?·±£¬?»??·±?å?¶±ð???¹??*//*For Traditional Chinese Recognizer,
												Recognize some simple Chinese characters and change the result code to traditional code */
#define	HWX_RADICAL					0x0080		/*GB2312??µ??«??*//*Stroke components*/
#define	HWX_LOW_ENG					0x0100		/*Lowercase Latin characters ( a-z )*/
#define	HWX_UP_ENG					0x0200		/*Uppercase Latin characters ( A-Z )*/
#define	HWX_NUM						0x0400		/*Number ( 0-9 )*/
#define	HWX_COMMON_PUNC				0x0800		/*8 Commonly used punctuation marks !",:;?¡¢¡£	*/
#define	HWX_RARE_PUNC				0x1000		/*10 Extended punctuation marks '()¡?¬¡ª¡­¡Ž¡µ¡¶¡?*/
#define	HWX_COMMON_SYM				0x2000		/*Commonly used symbols ( ¡ê£??.=/>$-%+<*@&? )*/
#define	HWX_RARE_SYM				0x4000		/*Extended symbols ( ~{}^`\]_[| )*/
#define	HWX_GES						0x8000		/*Special symbols ( Space(0x20), Carriage Return(0x0d), Backspace(0x08), Delete(0x10), Table 0x0009 */
/*16-31	Reserved*/
#define	ALC_VALID					0x0000FFFF

#ifdef __cplusplus
extern "C"{
#endif
int WINAPI HWRecognize( WORD* pbTrace, char* pResult, int nCand, WORD wRange );
void WINAPI HWSetDictionary( DWORD dwRam, DWORD dwRom );

#ifdef __cplusplus
}
#endif


#endif  //__USE_JIETONG_HANDWRITING__