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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/mapi.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: mapi.h,v 1.1 2007/05/17 07:25:31 bw Exp $
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
* $Log: mapi.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/mapi.h,v 1.1 2007/05/14 09:46:43 bw Exp $
*
* ~Id: mapi.h,v 1.1 2007/05/14 09:46:43 bw Exp $
*
* ~Date: 2007/05/14 09:46:43 $
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
* ~Log: mapi.h,v $
* Revision 1.1  2007/05/14 09:46:43  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/mapi.h,v 1.2 2007/04/04 06:51:32 bw Exp $
*
* ~Id: mapi.h,v 1.2 2007/04/04 06:51:32 bw Exp $
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
* ~Log: mapi.h,v $
* Revision 1.2  2007/04/04 06:51:32  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _MAPI_H
#define _MAPI_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SUCCESS_SUCCESS			0
#define MAPI_USER_ABORT			1
#define MAPI_E_USER_ABORT		1
#define MAPI_E_FAILURE			2
#define MAPI_E_LOGIN_FAILURE		3
#define MAPI_E_LOGON_FAILURE		3
#define MAPI_E_DISK_FULL		4
#define MAPI_E_INSUFFICIENT_MEMORY	5
#define MAPI_E_ACCESS_DENIED		6
#define MAPI_E_BLK_TOO_SMALL		6
#define MAPI_E_TOO_MANY_SESSIONS	8
#define MAPI_E_TOO_MANY_FILES		9
#define MAPI_E_TOO_MANY_RECIPIENTS	10
#define MAPI_E_ATTACHMENT_NOT_FOUND	11
#define MAPI_E_ATTACHMENT_OPEN_FAILURE	12
#define MAPI_E_ATTACHMENT_WRITE_FAILURE	13
#define MAPI_E_UNKNOWN_RECIPIENT	14
#define MAPI_E_BAD_RECIPTYPE		15
#define MAPI_E_NO_MESSAGES		16
#define MAPI_E_INVALID_MESSAGE		17
#define MAPI_E_TEXT_TOO_LARGE		18
#define MAPI_E_INVALID_SESSION		19
#define MAPI_E_TYPE_NOT_SUPPORTED	20
#define MAPI_E_AMBIGUOUS_RECIPIENT	21
#define MAPI_E_AMBIGUOUS_RECIP		21
#define MAPI_E_MESSAGE_IN_USE		22
#define MAPI_E_NETWORK_FAILURE		23
#define MAPI_E_INVALID_EDITFIELDS	24
#define MAPI_E_INVALID_RECIPS		25
#define MAPI_E_NOT_SUPPORTED		26

#define MAPI_ORIG	0
#define MAPI_TO		1
#define MAPI_CC		2
#define MAPI_BCC	3

#define MAPI_LOGON_UI		0x0001
#define MAPI_NEW_SESSION	0x0002
#define MAPI_FORCE_DOWNLOAD	0x1000
#define MAPI_LOGOFF_SHARED	0x0001
#define MAPI_LOGOFF_UI		0x0002
#define MAPI_DIALOG		0x0008
#define MAPI_UNREAD_ONLY	0x0020
#define MAPI_LONG_MSGID		0x4000
#define MAPI_GUARANTEE_FIFO	0x0100
#define MAPI_ENVELOPE_ONLY	0x0040
#define MAPI_PEEK		0x0080
#define MAPI_BODY_AS_FILE	0x0200
#define MAPI_SUPPRESS_ATTACH	0x0800
#define MAPI_AB_NOMODIFY	0x0400
#define MAPI_OLE		0x0001
#define MAPI_OLE_STATIC		0x0002
#define MAPI_UNREAD		0x0001
#define MAPI_RECEIPT_REQUESTED	0x0002
#define MAPI_SENT		0x0004

#ifndef RC_INVOKED
typedef unsigned long FLAGS;
typedef unsigned long LHANDLE;
typedef unsigned long FAR *LPLHANDLE, FAR *LPULONG;

typedef struct {
  ULONG ulReserved;
  ULONG ulRecipClass;
  LPSTR lpszName;
  LPSTR lpszAddress;
  ULONG ulEIDSize;
  LPVOID lpEntryID;
} MapiRecipDesc, *lpMapiRecipDesc;
typedef struct {
  ULONG ulReserved;
  ULONG flFlags;
  ULONG nPosition;
  LPSTR lpszPathName;
  LPSTR lpszFileName;
  LPVOID lpFileType;
} MapiFileDesc, *lpMapiFileDesc;
typedef struct {
  ULONG ulReserved;
  ULONG cbTag;
  LPBYTE lpTag;
  ULONG cbEncoding;
  LPBYTE lpEncoding;
} MapiFileTagExt, *lpMapiFileTagExt;
typedef struct {
  ULONG ulReserved;
  LPSTR lpszSubject;
  LPSTR lpszNoteText;
  LPSTR lpszMessageType;
  LPSTR lpszDateReceived;
  LPSTR lpszConversationID;
  FLAGS flFlags;
  lpMapiRecipDesc lpOriginator;
  ULONG nRecipCount;
  lpMapiRecipDesc lpRecips;
  ULONG nFileCount;
  lpMapiFileDesc lpFiles;
} MapiMessage, *lpMapiMessage;

ULONG PASCAL MAPILogon (ULONG,LPSTR,LPSTR,FLAGS,ULONG,LPLHANDLE);
ULONG PASCAL MAPISendMail (LHANDLE,ULONG,lpMapiMessage,FLAGS,ULONG);
ULONG PASCAL MAPISendDocuments (ULONG,LPSTR,LPSTR,LPSTR,ULONG);
ULONG PASCAL MAPIReadMail (LHANDLE,ULONG,LPSTR,FLAGS,ULONG,
			   lpMapiMessage*);
ULONG PASCAL MAPIFindNext (LHANDLE,ULONG,LPSTR,LPSTR,FLAGS,ULONG,LPSTR);
ULONG PASCAL MAPIResolveName (LHANDLE,ULONG,LPSTR,FLAGS,ULONG,
                             lpMapiRecipDesc*);
ULONG PASCAL MAPIAddress (LHANDLE,ULONG,LPSTR,ULONG,LPSTR,ULONG,
			  lpMapiRecipDesc,FLAGS,ULONG,LPULONG,
			  lpMapiRecipDesc*);
ULONG PASCAL MAPIFreeBuffer (LPVOID);
ULONG PASCAL MAPIDetails (LHANDLE,ULONG,lpMapiRecipDesc,FLAGS,ULONG);
ULONG PASCAL MAPISaveMail (LHANDLE,ULONG,lpMapiMessage lpszMessage,
                           FLAGS,ULONG,LPSTR);
ULONG PASCAL MAPIDeleteMail (LHANDLE lpSession,ULONG,LPSTR,FLAGS,ULONG);
ULONG PASCAL MAPILogoff (LHANDLE,ULONG,FLAGS,ULONG);
/* Netscape extensions.  */
ULONG PASCAL MAPIGetNetscapeVersion (void);
ULONG PASCAL MAPI_NSCP_SynchronizeClient (LHANDLE,ULONG);

/* Handles for use with GetProcAddress */
typedef ULONG (PASCAL * LPMAPILOGON) (ULONG,LPSTR,LPSTR,FLAGS,ULONG,
				      LPLHANDLE);
typedef ULONG (PASCAL * LPMAPISENDMAIL) (LHANDLE,ULONG,lpMapiMessage,
					 FLAGS,ULONG);
typedef ULONG (PASCAL * LPMAPISENDDOCUMENTS) (ULONG,LPSTR,LPSTR,
					      LPSTR,ULONG);
typedef ULONG (PASCAL * LPMAPIREADMAIL) (LHANDLE,ULONG,LPSTR,FLAGS,
					 ULONG,lpMapiMessage*);
typedef ULONG (PASCAL * LPMAPIFINDNEXT) (LHANDLE,ULONG,LPSTR,LPSTR,
					 FLAGS,ULONG,LPSTR);
typedef ULONG (PASCAL * LPMAPIRESOLVENAME) (LHANDLE,ULONG,LPSTR,FLAGS,
					    ULONG,lpMapiRecipDesc*);
typedef ULONG (PASCAL * LPMAPIADDRESS) (LHANDLE,ULONG,LPSTR,ULONG,LPSTR,
					ULONG,lpMapiRecipDesc,FLAGS,ULONG,
					LPULONG,lpMapiRecipDesc*);
typedef ULONG (PASCAL * LPMAPIFREEBUFFER) (LPVOID lpv);
typedef ULONG (PASCAL * LPMAPIDETAILS) (LHANDLE,ULONG,lpMapiRecipDesc,
					FLAGS,ULONG);
typedef ULONG (PASCAL * LPMAPISAVEMAIL) (LHANDLE,ULONG,lpMapiMessage,
					 FLAGS,ULONG,LPSTR);
typedef ULONG (PASCAL * LPMAPIDELETEMAIL) (LHANDLE lpSession,ULONG,
					   LPSTR, FLAGS,ULONG);
typedef ULONG (PASCAL * LPMAPILOGOFF)(LHANDLE,ULONG,FLAGS,ULONG);

#endif /* RC_INVOKED */

#ifdef __cplusplus
}
#endif

#endif	/* Not _MAPI_H */

