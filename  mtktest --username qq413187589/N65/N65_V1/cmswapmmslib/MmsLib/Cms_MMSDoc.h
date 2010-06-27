/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: "Cms_MMSDoc.h"

    $Revision:

    $vision:       1.00

    $Date:         08/10/2002

    $Author:       mobilesoft app group

	$Declare: 
	This document contains information proprietary to MobileSoft  
 Technology (Nanjing),  Corp.    Transmittal, receipt, or possession 
 of this document does not express, license, or imply any rights to 
 use, sell, design, or manufacture from this information. No reproduction, 
 publication, or disclosure of this information, in whole or in part, 
 shall be made without prior written authorization from an officer of 
 MobileSoft Technology (NanJing), Corp.

Abstract:

Modified By:

Environment: 

Revision History: 添加视频标志video_flag
                  添加MMS_TYPE_3GP定义
=====================================================================*/

#ifndef MMSDOC_H
#define MMSDOC_H
//#include "Cms_MMSGlobal.h"
//#include "Cms_MMSCfg.h"
#include "Cms_MMSDebug.h"

#ifndef CENT_FILL_FIELD1
#define CENT_FILL_FIELD1  char  unuseful1;
#endif

#ifndef CENT_FILL_FIELD2
#define CENT_FILL_FIELD2  char  unuseful1;\
							char  unuseful2;
#endif

#ifndef CENT_FILL_FIELD3
#define CENT_FILL_FIELD3  char  unuseful1;\
							char unuseful2; \
						char unuseful3;
#endif

#ifndef MMS_FILE_NAME_LEN
#define MMS_FILE_NAME_LEN 128
#endif

#define MMS_TYPE_TEXT	0x01
#define MMS_TYPE_WBMP	0x02
#define MMS_TYPE_GIF	0x03
#define MMS_TYPE_JPEG	0x04
#define MMS_TYPE_WAV	0x05
#define MMS_TYPE_AMR	0x06		/*Adpatative Multi Rate*/
#define MMS_TYPE_MIDI	0x07
#define MMS_TYPE_MP3	0x08
#define MMS_TYPE_IMY	0x09
#define MMS_TYPE_MMF	0x0A
#define MMS_TYPE_BMP1	0x0B
#define MMS_TYPE_MP4	0x0C
#define MMS_TYPE_PNG	0x0D
#define MMS_TYPE_3GP    0x0E   //xuelianb Modify for Video
#define MMS_TYPE_VCF     0x0F  //add by jinliang.wang 20070724
#define MMS_TYPE_VCS     0x10  //add by jinliang.wang 20070724


#define MMS_TYPE_UNKNOWNAUDIO	0x71
#define MMS_TYPE_UNKNOWNIMAGE	0x72   //20041118
#define DEFAULT_SLIDE_TIMES		3000  //
#define MMS_PLAY_WIDTH		128
#define MMS_PLAY_HEIGHT		128

typedef struct MMS_Content{
	struct MMS_Content	*prev,			/*上一内容*/
						*next;			/*下一内容*/
	int		         	x,				/*位置x*///可以考虑不要
						y,				/*位置y*/////可以考虑不要
						width,			/*显示宽度*/
						height;			/*显示高度*/
	unsigned int			type;			/*内容类型*/
	unsigned int			time_start,		/*开始播放时间(ms)*/
						time_end;		/*结束播放时间(ms)*/
	//unsigned char			*data;			/*text data, define for text content,image audio memory filename */
	unsigned int			color;			/*色彩, define for text content */
	
	char			filename[MMS_FILE_NAME_LEN];
	char			forwardlock;					/*1:drm forwardlocked content; 0 free content */
	int                  contentsize;       //the size of text or image file 2003.73
	unsigned char			size;			/*大小, define for text content */
	//CENT_FILL_FIELD3
}MMS_CONTENT,*pMMS_Content;

typedef struct MMS_Slide{
	struct MMS_Slide	*prev,				/*上一帧*/
						*next;				/*下一帧*/
	unsigned int			times;			/*播放总时间(ms)*/
	unsigned int			color;			/*背景颜色*/
	char			audiofile[MMS_FILE_NAME_LEN];
	char			audio_type;				/*背景声音格式*/
	char			audio_forwardlock;	/* 1:drm forwardlocked content; 0 free content */
	char			text_flag;
	char			image_flag;
	char            video_flag;        //xuelianb Modify for Video
	char               accessory_flag;       //add by jinliang.wang 20070724
	//CENT_FILL_FIELD1
	pMMS_Content		content_root,	/*帧内容结构*/
						content_cur;	/*帧当前内容*/
	int                   audiosize;    //the size of audio file 2003.7.3
	int					textimage_order;  /* support the display station  */
}MMS_SLIDE,*pMMS_Slide;

typedef struct MMS_EDocument{
	int		        	width,			/*默认屏幕宽度*/
						height;			/*默认屏幕高度*/ 
	int		           	ftype;			/*文件类型*/
	pMMS_Slide			slide_root,		/*MMS帧结构*/
						slide_cur;		/*MMS当前帧*/
	int                 totalsize;      //  byte 2003.7.3
//	int					textimage_order;
}MMS_EDOCUMENT,*pMMS_EDocument;

/*
typedef enum _textimageorder
{
	TEXT_FIRST = 1,
	IMAGE_FIRST
}TEXTIMAGEORDER;
*/
/*20051019 cocoma xu add for MTK begin */
typedef enum
{
   IMAGE_TEXT_ORDER = 0,
   IMAGE_DOWN_TEXT_UP,
   IMAGE_UP_TEXT_DOWN,
   IMAGE_LEFT_TEXT_RIGHT,
   IMAGE_RIGHT_TEXT_LEFT
}IMAGETEXTORDER;
/*20051019 cocoma xu add for MTK end*/

/*
void MMS_Init();
void MMS_InitShow();
*/
int MMS_New_Audio(unsigned char *data,unsigned int type,pMMS_Slide pSlide,pMMS_EDocument pDocument);  //2003.7.3
void MMS_DelAudio(pMMS_Slide pSlide,pMMS_EDocument pDocument);

pMMS_Content MMS_New_Content(unsigned char *data,unsigned int type,pMMS_Slide pSlide,pMMS_EDocument pDocument);
void MMS_DelContent(pMMS_Slide pSlide,pMMS_EDocument pDocument);
void MMS_PrevContent(pMMS_Slide pSlide,pMMS_EDocument pDocument);
void MMS_NextContent(pMMS_Slide pSlide,pMMS_EDocument pDocument);

pMMS_Slide MMS_New_Slide(pMMS_EDocument pDocument);
void MMS_DelSlide(pMMS_EDocument pDocument);
int MMS_PrevSlide(pMMS_EDocument pDocument);
int MMS_NextSlide(pMMS_EDocument pDocument);
void MMS_HeadSlide(pMMS_EDocument pDocument);
void MMS_TailSlide(pMMS_EDocument pDocument);
pMMS_Slide MMS_GetLastNullText(pMMS_EDocument theDocument);
pMMS_Slide MMS_GetLastNullAudio(pMMS_EDocument theDocument);
pMMS_Slide MMS_GetLastNullImage(pMMS_EDocument theDocument);
pMMS_Slide MMS_GetLastNullaccessory(pMMS_EDocument theDocument);

unsigned short MMSGetSlideCount(pMMS_EDocument pDocument);
unsigned short MMSGetAllContentCount(pMMS_EDocument pDocument);
void MMSDelAllSlide(pMMS_EDocument pDocument);
unsigned short MMSGetSlideIndex(pMMS_EDocument pDocument);
pMMS_EDocument MMS_New(void);
void MMSDelDocument(pMMS_EDocument pDocument);
pMMS_EDocument MMSNewDocument(void);
//unsigned int MMS_Close(pMMS_EDocument pDocument);
void MMS_Cursor(int x,int y,pMMS_EDocument pDocument);
void MMS_Layout(pMMS_EDocument pDocument);
void MMSSetTextImageOrder(pMMS_EDocument pDocument,int order);
int MMSGetTextImageOrder(pMMS_EDocument pDocument);

#endif
