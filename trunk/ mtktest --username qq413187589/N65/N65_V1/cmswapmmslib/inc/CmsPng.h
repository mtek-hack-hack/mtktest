/************************************************************************* 
 * Copyright (c) 2000-2004 MobileSoft Corporation All Rights Reserved.	
 * 日  期：  2004-10-7   	
 * 作  者：  滕永; yongt@mobilesoft.com.cn   
 * 文  件：  CmsPng.h 	    	
 * 描  述：  png head fine 
 ************************************************************************/

#ifndef _CMSPNG_H
#define _CMSPNG_H



/* callback function type */
typedef int(* pngdrawproc) (unsigned char*, int,int,int,int,int,long);

typedef int (*_ex_DrawPixel_t)(unsigned char *DataBuf,	\
							  int Hight,				\
						      int Width,				\
							  int Component,			\
							  int xPosition,			\
						      int yPosition,			\
						      double x_proportion,		\
							  double y_proportion,		\
							  int x_right);

#ifndef JPEGDRAWPROC
#define JPEGDRAWPROC
typedef		int (*_ex_jpegdrawproc)(unsigned char *, int,int,int,	\
									int,int,double,double);
#endif  // Modified by TIPrj[2005/6/29]

typedef int (*F_CmsBrwDrawPixel)(unsigned char *DataBuf, int Height, int Width, int Component,
					int xPosition, int yPosition, double proportion);

/* draw png function */
int DrawPng(char *filename,				/* in file name */
			F_CmsBrwDrawPixel pDrawPixel,		/* call back function */
			int xPosition,				/* x position of png */
			int yPosition,				/* y position of png */
			int screenwidth);			/* screen width */

int _ex_DrawPng(char *filename,
				_ex_jpegdrawproc pDrawPixel,
				int xPosition,
				int yPosition,
				int display_width,
				int display_height,
				int x_right);



int GetPngInfo(char *filename,int screenwidth,int *pwidth, int *pheight);

#endif

