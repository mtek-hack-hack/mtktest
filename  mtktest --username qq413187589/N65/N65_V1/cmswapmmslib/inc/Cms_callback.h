/*
* Copyright (c) 2001,Mobilesoft Technology(Nanjing) Co.,LTD.
* All rights reserved.
* 
* FileName    : Cms_callback.h
* Description :  
* 
* Version     : v1.0.0
* Author      : palmsource
* StartDate   : 2005/7/14
* FinishDate  : 
*/
#ifndef CMS_CALLBACK_H
#define CMS_CALLBACK_H
/*------------------------------------------------------------------------
 *
 *
 *
 *               the declaration of 2 callback of MMS lib & SMS　PUSH handler
 *
 *
 *
------------------------------------------------------------------------*/
typedef		int (*mmsproc)(int, void *,int);//callback used between mms library and the upper
typedef		int (*smsproc)(int, void *,int);//used at the function handling with sms
typedef		int (*brwproc)(int, void *,int);//browser库与上层交互的回调函数
#endif