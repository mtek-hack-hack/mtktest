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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/unknwn.h,v 1.1 2007/05/17 07:25:35 bw Exp $
*
* $Id: unknwn.h,v 1.1 2007/05/17 07:25:35 bw Exp $
*
* $Date: 2007/05/17 07:25:35 $
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
* $Log: unknwn.h,v $
* Revision 1.1  2007/05/17 07:25:35  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/unknwn.h,v 1.1 2007/05/14 09:46:52 bw Exp $
*
* ~Id: unknwn.h,v 1.1 2007/05/14 09:46:52 bw Exp $
*
* ~Date: 2007/05/14 09:46:52 $
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
* ~Log: unknwn.h,v $
* Revision 1.1  2007/05/14 09:46:52  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/unknwn.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Id: unknwn.h,v 1.2 2007/04/04 06:51:34 bw Exp $
*
* ~Date: 2007/04/04 06:51:34 $
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
* ~Log: unknwn.h,v $
* Revision 1.2  2007/04/04 06:51:34  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#endif

#ifndef _UNKNWN_H
#define _UNKNWN_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C"{
#endif
#include <objfwd.h>
#include <wtypes.h>

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free(void*);
EXTERN_C const IID IID_IUnknown;
EXTERN_C const IID IID_IClassFactory;
#ifndef __IUnknown_INTERFACE_DEFINED__
#define __IUnknown_INTERFACE_DEFINED__
#undef INTERFACE
#define INTERFACE IUnknown
DECLARE_INTERFACE(IUnknown)
{
	STDMETHOD(QueryInterface)(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_(ULONG,AddRef)(THIS) PURE;
	STDMETHOD_(ULONG,Release)(THIS) PURE;
};
typedef IUnknown *LPUNKNOWN;
#endif
#ifndef __IClassFactory_INTERFACE_DEFINED__
#define __IClassFactory_INTERFACE_DEFINED__
#undef INTERFACE
#define INTERFACE IClassFactory
DECLARE_INTERFACE_(IClassFactory,IUnknown)
{
	STDMETHOD(QueryInterface)(THIS_ REFIID,PVOID*) PURE;
	STDMETHOD_(ULONG,AddRef)(THIS) PURE;
	STDMETHOD_(ULONG,Release)(THIS) PURE;
	STDMETHOD(CreateInstance)(THIS_ LPUNKNOWN,REFIID,PVOID*) PURE;
	STDMETHOD(LockServer)(THIS_ BOOL) PURE;
};
typedef IClassFactory *LPCLASSFACTORY;
#endif
HRESULT STDMETHODCALLTYPE IUnknown_QueryInterface_Proxy(IUnknown*,REFIID,void**);
void __RPC_STUB IUnknown_QueryInterface_Stub(LPRPCSTUBBUFFER,LPRPCCHANNELBUFFER,PRPC_MESSAGE,PDWORD);
ULONG STDMETHODCALLTYPE IUnknown_AddRef_Proxy(IUnknown*);
void __RPC_STUB IUnknown_AddRef_Stub(LPRPCSTUBBUFFER,LPRPCCHANNELBUFFER,PRPC_MESSAGE,PDWORD);
ULONG STDMETHODCALLTYPE IUnknown_Release_Proxy(IUnknown*);
void __RPC_STUB IUnknown_Release_Stub(LPRPCSTUBBUFFER,LPRPCCHANNELBUFFER,PRPC_MESSAGE,PDWORD);
HRESULT STDMETHODCALLTYPE IClassFactory_RemoteCreateInstance_Proxy(IClassFactory*,REFIID,IUnknown**);
void __RPC_STUB IClassFactory_RemoteCreateInstance_Stub(LPRPCSTUBBUFFER,LPRPCCHANNELBUFFER,PRPC_MESSAGE,PDWORD);
HRESULT __stdcall IClassFactory_RemoteLockServer_Proxy(IClassFactory*,BOOL);
void __RPC_STUB IClassFactory_RemoteLockServer_Stub(LPRPCSTUBBUFFER,LPRPCCHANNELBUFFER,PRPC_MESSAGE,PDWORD);
HRESULT STDMETHODCALLTYPE IClassFactory_CreateInstance_Proxy(IClassFactory*,IUnknown*,REFIID,void**);
HRESULT STDMETHODCALLTYPE IClassFactory_CreateInstance_Stub(IClassFactory*,REFIID,IUnknown**);
HRESULT STDMETHODCALLTYPE IClassFactory_LockServer_Proxy(IClassFactory*,BOOL);
HRESULT STDMETHODCALLTYPE IClassFactory_LockServer_Stub(IClassFactory*,BOOL);

#if (!defined (__cplusplus) || defined (CINTERFACE)) \
    && defined (COBJMACROS)
#define IUnknown_QueryInterface(T,r,O) (T)->lpVtbl->QueryInterface(T,r,O)
#define IUnknown_AddRef(T) (T)->lpVtbl->AddRef(T)
#define IUnknown_Release(T) (T)->lpVtbl->Release(T)
#define IClassFactory_QueryInterface(T,r,O) (T)->lpVtbl->QueryInterface(T,r,O)
#define IClassFactory_AddRef(T) (T)->lpVtbl->AddRef(T)
#define IClassFactory_Release(T) (T)->lpVtbl->Release(T)
#define IClassFactory_CreateInstance(T,p,r,O) (T)->lpVtbl->CreateInstance(T,p,r,O)
#define IClassFactory_LockServer(T,f) (T)->lpVtbl->LockServer(T,f)
#endif /* COBJMACROS */
#ifdef __cplusplus
}
#endif
#endif
