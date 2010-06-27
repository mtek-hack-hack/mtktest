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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/include/olectlid.h,v 1.1 2007/05/17 07:25:32 bw Exp $
*
* $Id: olectlid.h,v 1.1 2007/05/17 07:25:32 bw Exp $
*
* $Date: 2007/05/17 07:25:32 $
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
* $Log: olectlid.h,v $
* Revision 1.1  2007/05/17 07:25:32  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/include/olectlid.h,v 1.1 2007/05/14 09:46:46 bw Exp $
*
* ~Id: olectlid.h,v 1.1 2007/05/14 09:46:46 bw Exp $
*
* ~Date: 2007/05/14 09:46:46 $
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
* ~Log: olectlid.h,v $
* Revision 1.1  2007/05/14 09:46:46  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/include/olectlid.h,v 1.2 2007/04/04 06:51:33 bw Exp $
*
* ~Id: olectlid.h,v 1.2 2007/04/04 06:51:33 bw Exp $
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
* ~Log: olectlid.h,v $
* Revision 1.2  2007/04/04 06:51:33  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef _OLECTLID_H
#define _OLECTLID_H
#if __GNUC__ >=3
#pragma GCC system_header
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern const GUID IID_IDispatch;
extern const GUID IID_IPropertyNotifySink;
extern const GUID IID_IClassFactory2;
extern const GUID IID_IProvideClassInfo;
extern const GUID IID_IProvideClassInfo2;
extern const GUID IID_IConnectionPointContainer;
extern const GUID IID_IEnumConnectionPoints;
extern const GUID IID_IConnectionPoint;
extern const GUID IID_IEnumConnections;
extern const GUID IID_IOleControl;
extern const GUID IID_IOleControlSite;
extern const GUID IID_ISimpleFrameSite;
extern const GUID IID_IPersistStreamInit;
extern const GUID IID_IPersistMemory;
extern const GUID IID_IPersistPropertyBag;
extern const GUID IID_IPropertyBag;
extern const GUID IID_IErrorLog;
extern const GUID IID_IPropertyFrame;
extern const GUID IID_ISpecifyPropertyPages;
extern const GUID IID_IPerPropertyBrowsing;
extern const GUID IID_IPropertyPageSite;
extern const GUID IID_IPropertyPage;
extern const GUID IID_IPropertyPage2;
extern const GUID CLSID_CFontPropPage;
extern const GUID CLSID_CColorPropPage;
extern const GUID CLSID_CPicturePropPage;
extern const GUID CLSID_PersistPropset;
extern const GUID CLSID_ConvertVBX;
extern const GUID CLSID_StdFont;
extern const GUID CLSID_StdPicture;
extern const GUID IID_IFont;
extern const GUID IID_IFontDisp;
extern const GUID IID_IPicture;
extern const GUID IID_IPictureDisp;
extern const GUID GUID_HIMETRIC;
extern const GUID GUID_COLOR;
extern const GUID GUID_XPOSPIXEL;
extern const GUID GUID_YPOSPIXEL;
extern const GUID GUID_XSIZEPIXEL;
extern const GUID GUID_YSIZEPIXEL;
extern const GUID GUID_XPOS;
extern const GUID GUID_YPOS;
extern const GUID GUID_XSIZE;
extern const GUID GUID_YSIZE;
extern const GUID GUID_TRISTATE;
extern const GUID GUID_OPTIONVALUEEXCLUSIVE;
extern const GUID GUID_CHECKVALUEEXCLUSIVE;
extern const GUID GUID_FONTNAME;
extern const GUID GUID_FONTSIZE;
extern const GUID GUID_FONTBOLD;
extern const GUID GUID_FONTITALIC;
extern const GUID GUID_FONTUNDERSCORE;
extern const GUID GUID_FONTSTRIKETHROUGH;
extern const GUID GUID_HANDLE;
extern const GUID IID_IEnumUnknown;
extern const GUID IID_IEnumString;
extern const GUID IID_IEnumMoniker;
extern const GUID IID_IEnumFORMATETC;
extern const GUID IID_IEnumOLEVERB;
extern const GUID IID_IEnumSTATDATA;
extern const GUID IID_IEnumSTATSTG;
extern const GUID IID_IEnumGeneric;
extern const GUID IID_IEnumHolder;
extern const GUID IID_IEnumCallback;
extern const GUID IID_IPersistStream;
extern const GUID IID_IPersistStorage;
extern const GUID IID_IPersistFile;
extern const GUID IID_IPersist;
extern const GUID IID_IViewObject;
extern const GUID IID_IDataObject;
extern const GUID IID_IAdviseSink;
extern const GUID IID_IDataAdviseHolder;
extern const GUID IID_IOleAdviseHolder;
extern const GUID IID_IOleObject;
extern const GUID IID_IOleInPlaceObject;
extern const GUID IID_IOleWindow;
extern const GUID IID_IOleInPlaceUIWindow;
extern const GUID IID_IOleInPlaceFrame;
extern const GUID IID_IOleInPlaceActiveObject;
extern const GUID IID_IOleClientSite;
extern const GUID IID_IOleInPlaceSite;
extern const GUID IID_IParseDisplayName;
extern const GUID IID_IOleContainer;
extern const GUID IID_IOleItemContainer;
extern const GUID IID_IOleLink;
extern const GUID IID_IOleCache;
extern const GUID IID_IOleManager;
extern const GUID IID_IOlePresObj;
extern const GUID IID_IDropSource;
extern const GUID IID_IDropTarget;
extern const GUID IID_IDebug;
extern const GUID IID_IDebugStream;
extern const GUID IID_IAdviseSink2;
extern const GUID IID_IRunnableObject;
extern const GUID IID_IViewObject2;
extern const GUID IID_IOleCache2;
extern const GUID IID_IOleCacheControl;
extern const GUID CLSID_Picture_Metafile;
extern const GUID CLSID_Picture_Dib;

#ifdef __cplusplus
}
#endif
#endif
