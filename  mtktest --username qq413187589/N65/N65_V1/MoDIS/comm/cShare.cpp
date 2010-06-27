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
*  cShare.cpp
*
* Project:
* --------
*   Catcher
*
* Description:
* ------------
*   This module contains implementation of IPC between U-T and Catcher
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
//#include "StdAfx.h"
#include "cShare.h"
#include "stdio.h"

CShare::CShare()
{
	Data_Read[0] = NULL;
	Data_Read[1] = NULL;
	Data_Written[0] = NULL;
	Data_Written[1] = NULL;
	m_hMap = NULL;
	m_pSharedData = NULL;
	m_size = 0;
}

CShare::~CShare()
{
	DestroyShare();
}

bool CShare::CreateShare(const char* ID, const int &size)
{
	DestroyShare();
	char Map_ID[256];
	char Read_ID[256];
	char Write_ID[256];

  sprintf(Map_ID, "%s_Map", ID);
  if (strlen(Map_ID) > 250)
  {
  	printf("Error: CShare::CreateShare with ID too long. It won't be able to connect Catcher!\n");
  	return false;
  }
  
  sprintf(Read_ID, "%s_Read", ID);
  sprintf(Write_ID, "%s_Write", ID);
  
	m_hMap = ::CreateFileMapping(	(HANDLE)0xFFFFFFFF,
									0,					// Security
									PAGE_READWRITE,
									0,					// size --> high order
									size,				// size --> low order
									Map_ID		// map ID
								);
	if( m_hMap==NULL )
		goto Create_Failed;

	m_pSharedData = (char *)::MapViewOfFile(m_hMap,
									FILE_MAP_WRITE,
									0,				// offset high
									0,				// offset low
									0				// number of bytes, 0-->entire
									);
	if( m_pSharedData==NULL )
		goto Create_Failed;

	Data_Read[0] = ::CreateEvent(NULL, TRUE, FALSE, Read_ID);
	if( Data_Read[0]==NULL )
		goto Create_Failed;

	Data_Read[1] = ::CreateEvent(NULL, TRUE, FALSE, NULL);
	if( Data_Read[1]==NULL )
		goto Create_Failed;

	Data_Written[0] = ::CreateEvent(NULL, TRUE, FALSE, Write_ID);
	if( Data_Written[0]==NULL )
		goto Create_Failed;
	Data_Written[1] = Data_Read[1];

	m_size = size - sizeof(int);
	return true;

Create_Failed:
	DestroyShare();
	return false;
}

void CShare::DestroyShare()
{
	if( m_pSharedData!=NULL )
	{
		::UnmapViewOfFile(m_pSharedData);
		m_pSharedData = NULL;
	}
	if( m_hMap!=NULL )
	{
		CloseHandle(m_hMap);
		m_hMap = NULL;
	}
	if( Data_Read[0]!=NULL )
	{
		CloseHandle(Data_Read[0]);
		Data_Read[0] = NULL;
	}
	if( Data_Read[1]!=NULL )
	{
		CloseHandle(Data_Read[1]);
		Data_Read[1] = NULL;
	}
	if( Data_Written[0]!=NULL )
	{
		CloseHandle(Data_Written[0]);
		Data_Written[0] = NULL;
	}
	Data_Written[1] = NULL;
	m_size = 0;
}

int CShare::Write(const void *data, const int &size)
{
	if( m_pSharedData==NULL )
		return 0;

	if( size>m_size || size==0 )
		return 0;

	reinterpret_cast<const char *>(data);


	::memcpy(m_pSharedData, &size, sizeof(int));
	::memcpy(m_pSharedData+sizeof(int), data, size);

	::SetEvent(Data_Written[0]);
	if( ::WaitForMultipleObjects(2, Data_Read, FALSE, 3000)!=WAIT_OBJECT_0 )
	{
		::ResetEvent(Data_Written[0]);
		return 0;
	}
	else
	{
		::ResetEvent(Data_Read[0]);
		return size;
	}
}

int CShare::Read(void *data, const int &size)
{
	if( m_pSharedData==NULL )
		return 0;

	reinterpret_cast<char *>(data);

	int _len;

	if( ::WaitForMultipleObjects(2, Data_Written, FALSE, INFINITE)!=WAIT_OBJECT_0 )
		return 0;

	::ResetEvent(Data_Written[0]);
	::memcpy(&_len, m_pSharedData, sizeof(int));
	if( _len>=size )
	{
		::memcpy(data, m_pSharedData+sizeof(int), size);
		::SetEvent(Data_Read[0]);	
		return size;
	}
	else
	{
		::memcpy(data, m_pSharedData+sizeof(int), _len);
		::SetEvent(Data_Read[0]);	
		return _len;
	}

}

void CShare::Stop()
{
	::SetEvent(Data_Read[1]);
}
