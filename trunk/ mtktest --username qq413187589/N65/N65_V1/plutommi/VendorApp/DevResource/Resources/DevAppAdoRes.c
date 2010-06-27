#include "CustDataRes.h"
#include "DevAppAdoDataHW.h"
#include "CustResDef.h"

#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
const unsigned short  DevApp_CurrMaxAudioNum=0;
#ifdef MMI_ON_HARDWARE_P
const CUSTOM_AUDIO	DevApp_nCustAudioNames[];
#else
CUSTOM_AUDIO	DevApp_nCustAudioNames[MAX_AUDIO_NAMES_SIZE];
#endif
#if defined(DEVELOPER_BUILD_FIRST_PASS) || defined(CUSTOMIZATION_BUILD_FIRST_PASS)|| defined(CUSTOMIZATION_BUILD_SECOND_PASS) 

AUDIONAME_LIST	DevApp_AudioNameList[MAX_AUDIO_NAMES_SIZE];
#endif
