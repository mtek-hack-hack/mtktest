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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/wtypes.h,v 1.1 2007/05/17 07:25:37 bw Exp $
*
* $Id: wtypes.h,v 1.1 2007/05/17 07:25:37 bw Exp $
*
* $Date: 2007/05/17 07:25:37 $
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
* $Log: wtypes.h,v $
* Revision 1.1  2007/05/17 07:25:37  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/wtypes.h,v 1.1 2007/05/14 09:46:56 bw Exp $
*
* ~Id: wtypes.h,v 1.1 2007/05/14 09:46:56 bw Exp $
*
* ~Date: 2007/05/14 09:46:56 $
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
* ~Log: wtypes.h,v $
* Revision 1.1  2007/05/14 09:46:56  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/wtypes.h,v 1.2 2007/04/04 06:51:35 bw Exp $
*
* ~Id: wtypes.h,v 1.2 2007/04/04 06:51:35 bw Exp $
*
* ~Date: 2007/04/04 06:51:35 $
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
* ~Log: wtypes.h,v $
* Revision 1.2  2007/04/04 06:51:35  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#include <rpc.h>
#include <rpcndr.h>

#ifndef _WTYPES_H
#define _WTYPES_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define IID_NULL GUID_NULL
#define CLSID_NULL GUID_NULL
#define CBPCLIPDATA(d) ((d).cbSize-sizeof((d).ulClipFmt))
#define DECIMAL_NEG ((BYTE)0x80)
#define DECIMAL_SETZERO(d) {(d).Lo64=(d).Hi32=(d).signscale=0;}
#define ROTFLAGS_REGISTRATIONKEEPSALIVE	0x01
#define ROTFLAGS_ALLOWANYCLIENT		0x02

#ifndef __BLOB_T_DEFINED /* also in winsock2.h */
#define __BLOB_T_DEFINED
typedef struct _BLOB {
	ULONG	cbSize;
	BYTE	*pBlobData;
} BLOB,*PBLOB,*LPBLOB;
#endif
typedef enum tagDVASPECT {
	DVASPECT_CONTENT=1,
	DVASPECT_THUMBNAIL=2,
	DVASPECT_ICON=4,
	DVASPECT_DOCPRINT=8
} DVASPECT;
typedef enum tagDVASPECT2 {
	DVASPECT_OPAQUE=16,
	DVASPECT_TRANSPARENT=32
} DVASPECT2;
typedef enum tagSTATFLAG {
	STATFLAG_DEFAULT=0,
	STATFLAG_NONAME=1
} STATFLAG;
typedef enum tagMEMCTX {
	MEMCTX_TASK=1,
	MEMCTX_SHARED,
	MEMCTX_MACSYSTEM,
	MEMCTX_UNKNOWN=-1,
	MEMCTX_SAME=-2
} MEMCTX;
typedef enum tagMSHCTX {
	MSHCTX_LOCAL,
	MSHCTX_NOSHAREDMEM,
	MSHCTX_DIFFERENTMACHINE,
	MSHCTX_INPROC
} MSHCTX;
typedef enum tagCLSCTX {
	CLSCTX_INPROC_SERVER=1,CLSCTX_INPROC_HANDLER=2,CLSCTX_LOCAL_SERVER=4,
	CLSCTX_INPROC_SERVER16=8,CLSCTX_REMOTE_SERVER=16
} CLSCTX;
typedef enum tagMSHLFLAGS {
	MSHLFLAGS_NORMAL,MSHLFLAGS_TABLESTRONG,MSHLFLAGS_TABLEWEAK
} MSHLFLAGS;
typedef struct _FLAGGED_WORD_BLOB {
	unsigned long fFlags;
	unsigned long clSize;
	unsigned short asData[1];
}FLAGGED_WORD_BLOB;

#ifndef OLE2ANSI
typedef WCHAR OLECHAR;
typedef LPWSTR LPOLESTR;
typedef LPCWSTR LPCOLESTR;
#define OLESTR(s) L##s
#else
typedef char OLECHAR;
typedef LPSTR LPOLESTR;
typedef LPCSTR LPCOLESTR;
#define OLESTR(s) s
#endif
typedef unsigned short VARTYPE;
typedef short VARIANT_BOOL;
typedef VARIANT_BOOL _VARIANT_BOOL;
#define VARIANT_TRUE ((VARIANT_BOOL)0xffff)
#define VARIANT_FALSE ((VARIANT_BOOL)0)
typedef OLECHAR *BSTR;
typedef FLAGGED_WORD_BLOB *wireBSTR;
typedef BSTR *LPBSTR;
typedef LONG SCODE;
typedef void *HCONTEXT;
typedef union tagCY {
	_ANONYMOUS_STRUCT struct {
		unsigned long Lo;
		long Hi;
	}_STRUCT_NAME(s);
	LONGLONG int64;
} CY;
typedef double DATE;
typedef struct  tagBSTRBLOB {
	ULONG cbSize;
	PBYTE pData;
}BSTRBLOB;
typedef struct tagBSTRBLOB *LPBSTRBLOB;
typedef struct tagCLIPDATA {
	ULONG cbSize;
	long ulClipFmt;
	PBYTE pClipData;
}CLIPDATA;
typedef enum tagSTGC {
	STGC_DEFAULT,STGC_OVERWRITE,STGC_ONLYIFCURRENT,
	STGC_DANGEROUSLYCOMMITMERELYTODISKCACHE
}STGC;
typedef enum tagSTGMOVE {
	STGMOVE_MOVE,STGMOVE_COPY,STGMOVE_SHALLOWCOPY
}STGMOVE;
enum VARENUM {
	VT_EMPTY,VT_NULL,VT_I2,VT_I4,VT_R4,VT_R8,VT_CY,VT_DATE,VT_BSTR,VT_DISPATCH,
	VT_ERROR,VT_BOOL,VT_VARIANT,VT_UNKNOWN,VT_DECIMAL,VT_I1=16,VT_UI1,VT_UI2,VT_UI4,VT_I8,
	VT_UI8,VT_INT,VT_UINT,VT_VOID,VT_HRESULT,VT_PTR,VT_SAFEARRAY,VT_CARRAY,VT_USERDEFINED,
	VT_LPSTR,VT_LPWSTR,VT_RECORD=36,VT_FILETIME=64,VT_BLOB,VT_STREAM,VT_STORAGE,VT_STREAMED_OBJECT,
	VT_STORED_OBJECT,VT_BLOB_OBJECT,VT_CF,VT_CLSID,VT_BSTR_BLOB=0xfff,VT_VECTOR=0x1000,
	VT_ARRAY=0x2000,VT_BYREF=0x4000,VT_RESERVED=0x8000,VT_ILLEGAL= 0xffff,VT_ILLEGALMASKED=0xfff,
	VT_TYPEMASK=0xfff
};
#ifdef _WIN64
#define VT_INT_PTR  VT_I8
#define VT_UINT_PTR VT_UI8
#else
#define VT_INT_PTR  VT_I4
#define VT_UINT_PTR VT_UI4
#endif

typedef struct _BYTE_SIZEDARR {
	unsigned long clSize;
	byte *pData;
}BYTE_SIZEDARR;
typedef struct _SHORT_SIZEDARR {
	unsigned long clSize;
	unsigned short *pData;
}WORD_SIZEDARR;
typedef struct _LONG_SIZEDARR {
	unsigned long clSize;
	unsigned long *pData;
}DWORD_SIZEDARR;
typedef struct _HYPER_SIZEDARR {
	unsigned long clSize;
	hyper *pData;
}HYPER_SIZEDARR;
typedef double DOUBLE;
typedef struct tagDEC {
	USHORT wReserved;
	_ANONYMOUS_UNION union {
		_ANONYMOUS_STRUCT struct {
			BYTE scale;
			BYTE sign;
		}_STRUCT_NAME(s);
		USHORT signscale;
	} DUMMYUNIONNAME;
	ULONG Hi32;
	_ANONYMOUS_UNION union {
		_ANONYMOUS_STRUCT struct {
			ULONG Lo32;
			ULONG Mid32;
		}_STRUCT_NAME(s2);
		ULONGLONG Lo64;
	} DUMMYUNIONNAME2;
} DECIMAL;
typedef void *HMETAFILEPICT;
#ifdef __cplusplus
}
#endif
#endif
