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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/objfwd.h,v 1.1 2007/05/17 07:25:31 bw Exp $
*
* $Id: objfwd.h,v 1.1 2007/05/17 07:25:31 bw Exp $
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
* $Log: objfwd.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/objfwd.h,v 1.1 2007/05/14 09:46:45 bw Exp $
*
* ~Id: objfwd.h,v 1.1 2007/05/14 09:46:45 bw Exp $
*
* ~Date: 2007/05/14 09:46:45 $
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
* ~Log: objfwd.h,v $
* Revision 1.1  2007/05/14 09:46:45  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/objfwd.h,v 1.2 2007/04/04 06:51:33 bw Exp $
*
* ~Id: objfwd.h,v 1.2 2007/04/04 06:51:33 bw Exp $
*
* ~Date: 2007/04/04 06:51:33 $
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
* ~Log: objfwd.h,v $
* Revision 1.2  2007/04/04 06:51:33  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _OBJFWD_H
#define _OBJFWD_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#include <basetyps.h>

#ifdef __cplusplus
extern "C" {
#endif
typedef interface IMoniker *LPMONIKER;
typedef interface IStream *LPSTREAM;
typedef interface IMarshal *LPMARSHAL;
typedef interface IMalloc *LPMALLOC;
typedef interface IMallocSpy *LPMALLOCSPY;
typedef interface IMessageFilter *LPMESSAGEFILTER;
typedef interface IPersist *LPPERSIST;
typedef interface IPersistStream *LPPERSISTSTREAM;
typedef interface IRunningObjectTable *LPRUNNINGOBJECTTABLE;
typedef interface IBindCtx *LPBINDCTX,*LPBC;
typedef interface IAdviseSink *LPADVISESINK;
typedef interface IAdviseSink2 *LPADVISESINK2;
typedef interface IDataObject *LPDATAOBJECT;
typedef interface IDataAdviseHolder *LPDATAADVISEHOLDER;
typedef interface IEnumMoniker *LPENUMMONIKER;
typedef interface IEnumFORMATETC *LPENUMFORMATETC;
typedef interface IEnumSTATDATA *LPENUMSTATDATA;
typedef interface IEnumSTATSTG *LPENUMSTATSTG;
typedef interface IEnumSTATPROPSTG LPENUMSTATPROPSTG;
typedef interface IEnumString *LPENUMSTRING;
typedef interface IEnumUnknown *LPENUMUNKNOWN;
typedef interface IStorage *LPSTORAGE;
typedef interface IPersistStorage *LPPERSISTSTORAGE;
typedef interface ILockBytes *LPLOCKBYTES;
typedef interface IStdMarshalInfo *LPSTDMARSHALINFO;
typedef interface IExternalConnection *LPEXTERNALCONNECTION;
typedef interface IRunnableObject *LPRUNNABLEOBJECT;
typedef interface IROTData *LPROTDATA;
typedef interface IPersistFile *LPPERSISTFILE;
typedef interface IRootStorage *LPROOTSTORAGE;
typedef interface IRpcChannelBuffer *LPRPCCHANNELBUFFER;
typedef interface IRpcProxyBuffer *LPRPCPROXYBUFFER;
typedef interface IRpcStubBuffer *LPRPCSTUBBUFFER;
typedef interface IPropertyStorage *LPPROPERTYSTORAGE;
typedef interface IEnumSTATPROPSETSTG *LPENUMSTATPROPSETSTG;
typedef interface IPropertySetStorage *LPPROPERTYSETSTORAGE;
typedef interface IClientSecurity *LPCLIENTSECURITY;
typedef interface IServerSecurity *LPSERVERSECURITY;
typedef interface IClassActivator *LPCLASSACTIVATOR;
typedef interface IFillLockBytes *LPFILLLOCKBYTES;
typedef interface IProgressNotify *LPPROGRESSNOTIFY;
typedef interface ILayoutStorage *LPLAYOUTSTORAGE;
#ifdef __cplusplus
}
#endif
#endif
