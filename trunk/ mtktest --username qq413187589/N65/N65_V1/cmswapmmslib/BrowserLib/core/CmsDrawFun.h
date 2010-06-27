/******************************************************************************

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2001-2002
 ALL RIGHTS RESERVED

*******************************************************************************

 Project Name: mini_Browser Ver2.10
 
 File Name   : CmsDrawFun.h

 Description : To Implement Browser application

 Last Modify : 09/29/2001
 
 Written By  : HaiYong Le


******************************************************************************/

#ifndef CMSDRAWFUN_H
#define CMSDRAWFUN_H

/***************************************************************/

#if __cplusplus 
extern "C" {
#endif

int		DrawPointOnScr(int x, int y, int color);
int		PutImgDataOnScr(int x, int y, int width, int height, unsigned char* ImgData, int option);
int		PrintHZOnScr(int x, int y, unsigned char* string, int isAnchor);
int		DrawLine(int x, int y, int length, int Horizontal);
int		DrawRect(int x, int y, int width, int height, int Clear);
int		ClearRect(int x, int y, int width, int height);
int		DrawCycle(int x, int y, int radius, int fill);
void	Win_MessageBox(unsigned char *str);
void	Win_DelayTime(unsigned int TimeLength);

#if __cplusplus 
}
#endif


#endif