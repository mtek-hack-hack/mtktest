/*
 * Copyright (c) 2001,Mobilesoft Technology(Nanjing) Co.,LTD.
 * All rights reserved.
 * 
 * FileName    : cms_TimerTrigger.h
 * brief       : 定时器触发头文件  
 * 
 * Version     : v1.0.0
 * Author      : palmsource
 * StartDate   : 2005/7/19
 * FinishDate  : 2005/7/19
 */
#ifndef CMS_TIMERTRIGER_H
#define CMS_TIMERTRIGER_H
#if 0
//20051007 cocoma xu modify for MTK
typedef enum
{	
	WML_TIMER = 0,			/*=== 0: WML页面定时器 ===*/
	GIF_TIMER,  			/*=== 1: GIF定时器     ===*/
	WTP_TIMER,              /*=== 2: WTP定时器     ===*/
	HTTP_TIMER,             /*=== 3: HTTP定时器     ===*/
	MARQUEE_TIMER,          /*=== 4: 跑马灯定时器  ===*/ //  Modified by TIPrj[2005/8/30]
	TIMER_COUNT
}TIMER_TYPE;

int		Cms_StartTimer  (TIMER_TYPE timerType, int timeId,  unsigned short millsec, int loop );
void    Cms_StopTimer   (int timerID);
void    TimerList_Clear (void);
int     TimerList_Empty (void);
#endif //xiaoyongq 20051007
#endif // end CMS_TIMERTRIGER_H
