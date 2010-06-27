/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  cShare.h
*
* Project:
* --------
*   Catcher
*
* Description:
* ------------
*   This module contains the definitions for cShare.cpp
*
* Author:
* -------
*  Spancer
*
*==============================================================================
*           HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
* $Revision:
* $Modtime:
* $Log:
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*==============================================================================
*******************************************************************************/
#ifndef CSHARE_MEM_H
#define CSHARE_MEM_H

#pragma warning (disable:4786)

#include <windows.h>

class CShare
{
private:
	HANDLE	Data_Written[2];
	HANDLE	Data_Read[2];
	HANDLE	m_hMap;
	char	*m_pSharedData;
	int		m_size;
public:
	CShare();
	~CShare();

	bool CreateShare(const char* ID, const int &size);
	void DestroyShare();
	int Write(const void *data, const int &size);
	int Read(void *data, const int &size);
	void Stop();
};

#endif
