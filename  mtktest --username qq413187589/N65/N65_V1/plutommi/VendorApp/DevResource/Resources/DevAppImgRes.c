#include "CustDataRes.h"
#include "DevAppImgDataHW.h"
#include "CustResDef.h"

#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
const unsigned short  DevApp_CurrMaxImageNum=1;
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
const CUSTOM_IMAGE	DevApp_nCustImageNames[]={
(U8*)&____DEVRESOURCE__IMAGES__EMPTYIMAGE_BMP,
};



