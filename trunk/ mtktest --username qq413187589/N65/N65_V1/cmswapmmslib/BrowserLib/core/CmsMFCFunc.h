/******************************************************************************

 C   H E A D E R   F I L E

 (c) Copyright MobileSoft Technology (NanJing) Co.,LTD. 2001-2002
 ALL RIGHTS RESERVED

*******************************************************************************

 Project Name: mini_Browser Ver2.10
 
 File Name   : CmsMfcFunc.h

 Description : To Implement Browser application

 Last Modify : 09/29/2001
 
 Written By  : HaiYong Le


******************************************************************************/

#ifndef CMSMFCFUNC_H
#define CMSMFCFUNC_H

/***************************************************************/

#if __cplusplus 
extern "C" {
#endif
void Cms_Browser_WMLTimerEvent(void);
//int		Cms_Browser_CreateCore(int);
//void		Cms_Browser_DestroyCore(void);

int		Cms_Browser_GetNetworkErrorID(void);
void	Cms_Browser_NetworkWarnEvent(void);
unsigned char **Cms_Browser_GetInputHistoryEvent(void);

int		Cms_Browser_LastLinkFocusEvent(void);
int		Cms_Browser_NextLinkFocusEvent(void);
int		Cms_Browser_GoLinkFocusEvent(void);

//int		Cms_Browser_GIFExpire(unsigned int *timer);

unsigned char	**Cms_Browser_GetSavedPageTitle(void);

#if __cplusplus 
}
#endif

#endif