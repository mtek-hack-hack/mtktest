/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: Cms_MMSWbmp.h

    $Revision:

    $vision:       1.00

    $Date:         04/17/2003

    $Author:       mobilesoft app group

	$Declare: 
	This document contains information proprietary to MobileSoft  
 Technology (Nanjing),  Corp.    Transmittal, receipt, or possession 
 of this document does not express, license, or imply any rights to 
 use, sell, design, or manufacture from this information. No reproduction, 
 publication, or disclosure of this information, in whole or in part, 
 shall be made without prior written authorization from an officer of 
 MobileSoft Technology (NanJing), Corp.

Abstract:

Modified By:

Environment: 

Revision History:

=====================================================================*/

#ifndef CMSWBMP_H
#define CMSWBMP_H
typedef		int (*bmpdrawproc)(int, int,short);//callback used to wbmp draw pixel
int GetWbmpInfo(char *filename,int screenwidth,int *pwidth,int *pheight);
int	DrawWbmp(char *filename, bmpdrawproc pDrawPixe,unsigned int xPos, unsigned int yPos,unsigned int screenwidth);
unsigned char*  GetWbmpMetrics(char* filename, int*  pWidth, int* pHeight);

int	_ex_DrawWbmp(char *filename, 
				 int xPosition,
				 int yPosition,
				 int display_width,
				 int display_height,
				 int x_right);


#endif /* CMSWBMP_H */
