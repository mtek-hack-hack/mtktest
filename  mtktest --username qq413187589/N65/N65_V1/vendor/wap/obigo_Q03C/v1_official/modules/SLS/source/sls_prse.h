/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */




#ifndef _SLS_PRSE_H
#define _SLS_PRSE_H




#define SMIL_ELEMENT_AUDIO         0x00
#define SMIL_ELEMENT_BODY          0x01
#define SMIL_ELEMENT_HEAD          0x02
#define SMIL_ELEMENT_IMG           0x03
#define SMIL_ELEMENT_LAYOUT        0x04
#define SMIL_ELEMENT_META          0x05
#define SMIL_ELEMENT_PAR           0x06
#define SMIL_ELEMENT_REF           0x07
#define SMIL_ELEMENT_REGION        0x08
#define SMIL_ELEMENT_ROOT_LAYOUT   0x09
#define SMIL_ELEMENT_SMIL          0x0A
#define SMIL_ELEMENT_TEXT          0x0B
#define SMIL_ELEMENT_VIDEO         0x0C
#define SMIL_ELEMENT_PARAM         0x0D
#define SMIL_ELEMENT_NOT_VALID     0xFF



#define SMIL_ATTRIBUTE_BEGIN        0x00
#define SMIL_ATTRIBUTE_ALT          0x01
#define SMIL_ATTRIBUTE_CONTENT      0x02
#define SMIL_ATTRIBUTE_DUR          0x03
#define SMIL_ATTRIBUTE_END          0x04
#define SMIL_ATTRIBUTE_FIT          0x05
#define SMIL_ATTRIBUTE_HEIGHT       0x06
#define SMIL_ATTRIBUTE_ID           0x07
#define SMIL_ATTRIBUTE_LEFT         0x08
#define SMIL_ATTRIBUTE_NAME         0x09
#define SMIL_ATTRIBUTE_REGION       0x0A
#define SMIL_ATTRIBUTE_SRC          0x0B
#define SMIL_ATTRIBUTE_TOP          0x0C
#define SMIL_ATTRIBUTE_WIDTH        0x0D
#define SMIL_ATTRIBUTE_BG_COLOR		0x0E
#define SMIL_ATTRIBUTE_VALUE		0x0F


typedef enum
{
	SLS_PARSE_OK,
	SLS_PARSE_ERROR_TO_MANU_SLIDES,
	SLS_PARSE_ERROR_UNKNOWN
} SlsParseResult;







SlsParseResult parseSMIL(InstanceData *instData);
#endif 


