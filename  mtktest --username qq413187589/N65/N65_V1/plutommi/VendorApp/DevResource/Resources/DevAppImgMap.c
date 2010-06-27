#include "CustDataRes.h"


#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
unsigned short DevApp_CurrMaxImageId=5;
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
const CUSTOM_IMAGE_MAP DevApp_ImageIdMap[]={
	{44300},
	{44301},
	{44302},
	{44303},
	{44304},
};



#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
unsigned short DevApp_CurrMaxSearchImageId=1;
#if  !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
const CUSTOM_IMAGE_SEARCH_MAP DevApp_ImageIdSearchMap[]={
	{44300,44304,0},
};



