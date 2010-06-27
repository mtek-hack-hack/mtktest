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
#include "CustImgDataHWExt.h"
#include "CustResDef.h"

//const S8 CustImgPath[]=CUST_IMG_PATH;
const unsigned short  mtk_CurrMaxImageNumEXT=8;
const CUSTOM_IMAGE	mtk_nCustImageNamesEXT[]={
(U8*)&__MAINLCD__ACTIVE__POWERONOFF__SMILE_LOGO_BMP_,
(U8*)&__MAINLCD__ACTIVE__POWERONOFF__SMILE_POON_GIF_,
(U8*)&__MAINLCD__ACTIVE__POWERONOFF__SMILE_POOFF_GIF_,
(U8*)&__MAINLCD__IDLESCREEN__WALLPAPER__WALL01_GIF_,
(U8*)&__MAINLCD__IDLESCREEN__WALLPAPER__WALL02_GIF_,
(U8*)&__MAINLCD__IDLESCREEN__WALLPAPER__WALL03_GIF_,
(U8*)&__MAINLCD__IDLESCREEN__WALLPAPER__WALL04_GIF_,
(U8*)&__MAINLCD__IDLESCREEN__WALLPAPER__WALL05_GIF_,
};



const CUSTPACK_IMAGE_HEADER mtk_image_header={8, (CUSTOM_IMAGE *)mtk_nCustImageNamesEXT};