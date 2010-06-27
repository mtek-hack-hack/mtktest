/**
 *	Copyright Notice
 *	?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 *	Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/************************************************************** 
 FILENAME	:  
 PURPOSE		: Resource file. 
 REMARKS		: nil 
 AUTHOR		: Customization Tool 
 DATE		: . 
 **************************************************************/
#include "CustDataRes.h"
#include "CustAdoDataHWExt.h"
#include "CustResDef.h"

//const S8 CustAdoPath[]=CUST_ADO_PATH;
const unsigned short  mtk_CurrMaxAudioNumEXT=1;
const CUSTOM_AUDIO	mtk_nCustAudioNamesEXT[]={
(U8*)&________CUSTOMER__AUDIO__EMPTYAUDIO_MP3_,
};



const CUSTPACK_AUDIO_HEADER mtk_audio_header={1, (CUSTOM_AUDIO *)mtk_nCustAudioNamesEXT};