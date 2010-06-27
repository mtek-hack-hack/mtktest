/************************************************************************* 
 * Copyright (c) 2000-2004 MobileSoft Corporation All Rights Reserved.	
 * 日  期：  2004-9-26   	
 * 作  者：  滕永; yongt@mobilesoft.com.cn   
 * 文  件：  cmspictogram.h 	    	
 * 描  述：  pictogram header file 
 ************************************************************************/
#ifndef _CMSPICTOGRAM_H
#define _CMSPICTOGRAM_H



#ifdef __cplusplus
extern "C"{
#endif
	


int Cms_IsPictScheme( char *abs_URI );
char *Cms_GetPictoClassName( char *abs_URI );
	
#ifdef __cplusplus
}
#endif



#endif
