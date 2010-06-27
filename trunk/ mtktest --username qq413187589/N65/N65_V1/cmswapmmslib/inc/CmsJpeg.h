/**************************************************************************
Copyright (c) 2001-2002 MobileSoft Corporation All Rights Reserved.
	Environment:		Windows 2000 
	Created:			20:5:2003   8:48
	Filename: 			CmsJpegLib.h
	Author:				teng yong
	E_Mail:				teng.yong@sohu.com/yongt@moiblesoft.com.cn	
	Declare:
    This document contains information proprietary to MobileSoft Technology
	(Nanjing),Corp. Transmittal, receipt, or possession of this document 
	does not express,license, or imply any rights to use, sell, design, or
	manufacture from this information. No reproduction, publication, or 
	disclosure of this	information,in whole or in part, shall be made without
	prior written authorization from  an officer of MobileSoft Technology 
	(NanJing) Corp.
	
	Abstract:			Jpeg api function
	Modify records: 
	Who           When		Where       For What       Status
	TengYong	  15:10     NanJing     Create         Finished 
**************************************************************************/

#ifndef CmsJpegLib_h_
#define CmsJpegLib_h_

/* 回调画行函数 */
extern int _ex_CmsBrwDrawPixel(unsigned char *DataBuf, int Height, int Width, int Component,
					int xPosition, int yPosition, double x_proportion, double y_proportion,int x_right);

typedef		int (*jpegdrawproc)(unsigned char *, int,int,int,int,int,double);//callback used to jpeg draw 

#ifndef JPEGDRAWPROC
#define JPEGDRAWPROC
typedef		int (*_ex_jpegdrawproc)(unsigned char *, int,int,int,	\
									int,int,double,double);//callback used to jpeg draw 
#endif  // Modified by TIPrj[2005/6/29]

/********************************************************************
 int GetJpegInfo(char *filename,int screenwidth,int *pwidth,int *pheight)
 Description:	 如果screenwidth == -1，得到实际的长度与高度；否则得到压缩
                后的长度与高度；
 Param		:	 (IN)filename;   Jpeg文件名称：
                 (IN)screenwidth;显示屏幕的宽度；
                 (OUT)pwidth;    图片宽度；
                 (OUT)pheight;   图片高度；
 Return		:	0; if OK;
				-1;if Error. pwidth == NULL || pheight == NULL 
                || screenwidth== 0 || filename == NULL;
 Date		:	2003-7-30
 Author		:	滕永; yongt@mobilesoft.com.cn
*********************************************************************/
int GetJpegInfo(char *filename,int screenwidth,int *pwidth,int *pheight);

/***************************************************************************
 int DrawJpeg(char *filename,void * pDrawPixel);
 Description:	显示一幅JPEG画形文件.
 Param		:	(IN)filename, 待显示的文件名称;
				(IN)pDrawPixel, 画一行JPEG数据的回调函数;
				(IN)xPosition, x方向原点坐标;
				(IN)yPosition, y方向原点坐标;
 Return		:	0; if OK;
				-1;if Error;
 Date		:	2003-6-9
 Author		:	滕永; yongt@mobilesoft.com.cn
****************************************************************************/
int DrawJpeg(char *filename,jpegdrawproc pDrawPixel,int xPosition,int yPosition,int screenwidth);


/*************************************************************************** 
 Description:	extend 显示一幅JPEG画形文件,可以在长度与宽度方向自由伸缩.
 Param		:	(IN)filename, 待显示的文件名称;
				(IN)pDrawPixel, 画一行JPEG数据的回调函数;
				(IN)xPosition, x方向原点坐标;
				(IN)yPosition, y方向原点坐标;
				(IN)display_width; display width
				(IN)display_height;display height

 Return		:	0; if OK;
				-1;if Error;

 Date		:	2003-6-9
 Author		:	滕永; yongt@mobilesoft.com.cn
****************************************************************************/
int _ex_DrawJpeg(char *filename,
			     _ex_jpegdrawproc pDrawPixel,
				 int xPosition,
				 int yPosition,
				 int display_width,
				 int display_height,
				 int x_right);

#endif