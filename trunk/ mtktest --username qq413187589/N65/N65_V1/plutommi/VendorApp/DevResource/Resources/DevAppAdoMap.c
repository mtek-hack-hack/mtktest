#include "CustDataRes.h"


#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
unsigned short DevApp_CurrMaxAudioId=0;
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
const CUSTOM_AUDIO_MAP DevApp_AudioIdMap[];
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
unsigned short DevApp_CurrMaxSearchAudioId=0;
CUSTOM_AUDIO_SEARCH_MAP DevApp_AudioIdSearchMap[1];
