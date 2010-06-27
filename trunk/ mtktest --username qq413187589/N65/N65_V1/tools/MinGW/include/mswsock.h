/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/mswsock.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: mswsock.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Date: 2007/05/17 07:25:31 $
*
* $Name: 1.1 $
*
* $Locker$
*
* $Revision: 1.1 $
*
* $State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* $Log: mswsock.h,v $
* Revision 1.1  2007/05/17 07:25:31  bw
* UNI@bw_20070517 15:10:01 MTK U25 U26 06B V30 version
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2007
*
*****************************************************************************/
/*============================================================================
*
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/mswsock.h,v 1.1 2007/05/14 09:46:44 bw Exp $
*
* ~Id: mswsock.h,v 1.1 2007/05/14 09:46:44 bw Exp $
*
* ~Date: 2007/05/14 09:46:44 $
*
* ~Name: 1.1 $
*
* ~Locker$
*
* ~Revision: 1.1 $
*
* ~State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* ~Log: mswsock.h,v $
* Revision 1.1  2007/05/14 09:46:44  bw
* UNI@bw_20070514 17:21:01 MTK初始版本.合并U25V20到U26V28.
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
/*****************************************************************************
* Copyright Statement:
* --------------------
* This software is protected by Copyright and the information contained
* herein is confidential. The software may not be copied and the information
* contained herein may not be used or disclosed except with the written
* permission of BEIWEI Inc. (C) 2005
*
*****************************************************************************/
/*============================================================================
*
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/mswsock.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: mswsock.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Date: 2007/04/04 06:51:32 $
*
* ~Name: 1.2 $
*
* ~Locker$
*
* ~Revision: 1.2 $
*
* ~State: Exp $
*
* HISTORY
* Below this line, this part is controlled by CVS. DO NOT MODIFY!!
*----------------------------------------------------------------------------
* ~Log: mswsock.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/*
 * mswsock.h
 * MS-specific extensions to Windows Sockets, exported from mswsock.dll.
 * These functions are N/A on Windows9x.
 *
 * This file is part of a free library for the Win32 API.
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 */
         
#ifndef _MSWSOCK_H
#define _MSWSOCK_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif
#ifdef __cplusplus
extern "C" {
#endif

#define SO_CONNDATA	0x7000
#define SO_CONNOPT	0x7001
#define SO_DISCDATA	0x7002
#define SO_DISCOPT	0x7003
#define SO_CONNDATALEN	0x7004
#define SO_CONNOPTLEN	0x7005
#define SO_DISCDATALEN	0x7006
#define SO_DISCOPTLEN	0x7007
#define SO_OPENTYPE	0x7008
#define SO_SYNCHRONOUS_ALERT	0x10
#define SO_SYNCHRONOUS_NONALERT	0x20
#define SO_MAXDG	0x7009
#define SO_MAXPATHDG	0x700A
#define SO_UPDATE_ACCEPT_CONTEXT	0x700B
#define SO_CONNECT_TIME	0x700C
#define TCP_BSDURGENT	0x7000

#define TF_DISCONNECT   1
#define TF_REUSE_SOCKET 2
#define TF_WRITE_BEHIND 4
#define TF_USE_DEFAULT_WORKER   0
#define TF_USE_SYSTEM_THREAD    16
#define TF_USE_KERNEL_APC   32

typedef struct _TRANSMIT_FILE_BUFFERS {
	PVOID Head;
	DWORD HeadLength;
	PVOID Tail;
	DWORD TailLength;
} TRANSMIT_FILE_BUFFERS, *PTRANSMIT_FILE_BUFFERS, *LPTRANSMIT_FILE_BUFFERS;

int PASCAL WSARecvEx(SOCKET,char*,int,int*);
BOOL PASCAL TransmitFile(SOCKET,HANDLE,DWORD,DWORD,LPOVERLAPPED,LPTRANSMIT_FILE_BUFFERS,DWORD);
BOOL PASCAL AcceptEx(SOCKET,SOCKET,PVOID,DWORD,DWORD,DWORD,LPDWORD,LPOVERLAPPED);
VOID PASCAL GetAcceptExSockaddrs(PVOID,DWORD,DWORD,DWORD,struct sockaddr**, LPINT, struct sockaddr**, LPINT);

#ifdef _WINSOCK2_H /* These require the winsock2 interface.  */

#define TP_ELEMENT_FILE		1
#define TP_ELEMENT_MEMORY	2
#define TP_ELEMENT_EOP		4

typedef struct _TRANSMIT_PACKETS_ELEMENT { 
	ULONG dwElFlags;
	ULONG cLength;
	_ANONYMOUS_UNION
	union {
		struct {
			LARGE_INTEGER	nFileOffset;
			HANDLE		hFile;
		};
		PVOID	pBuffer;
	};
} TRANSMIT_PACKETS_ELEMENT; 

typedef struct _WSAMSG {
	LPSOCKADDR	name;
	INT		namelen;
	LPWSABUF	lpBuffers;
	DWORD		dwBufferCount;
	WSABUF		Control;
	DWORD		dwFlags;
} WSAMSG, *PWSAMSG, *LPWSAMSG;


/* According to MSDN docs, the WSAMSG.Control buffer starts with a
   cmsghdr header of the following form.  See also RFC 2292. */

typedef struct wsacmsghdr {
	UINT	cmsg_len;
	INT	cmsg_level;
 	INT	cmsg_type;
	/* followed by UCHAR cmsg_data[]; */
} WSACMSGHDR;

/* TODO: Standard Posix.1g macros as per RFC 2292, with WSA_uglification. */
#if 0
#define WSA_CMSG_FIRSTHDR(mhdr)
#define WSA_CMSG_NXTHDR(mhdr, cmsg)
#define WSA_CMSG_SPACE(length)
#define WSA_CMSG_LEN(length)
#endif

BOOL PASCAL DisconnectEx(SOCKET,LPOVERLAPPED,DWORD,DWORD);
int PASCAL WSARecvMsg(SOCKET,LPWSAMSG,LPDWORD,LPWSAOVERLAPPED,LPWSAOVERLAPPED_COMPLETION_ROUTINE);

#endif /* _WINSOCK2_H */

#ifdef __cplusplus
}
#endif
#endif  /*  _MSWSOCK_H */

