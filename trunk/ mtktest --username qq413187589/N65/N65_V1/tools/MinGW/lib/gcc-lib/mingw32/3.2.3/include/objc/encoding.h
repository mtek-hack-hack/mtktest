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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/encoding.h,v 1.1 2007/05/17 07:25:45 bw Exp $
*
* $Id: encoding.h,v 1.1 2007/05/17 07:25:45 bw Exp $
*
* $Date: 2007/05/17 07:25:45 $
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
* $Log: encoding.h,v $
* Revision 1.1  2007/05/17 07:25:45  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/encoding.h,v 1.1 2007/05/14 09:47:14 bw Exp $
*
* ~Id: encoding.h,v 1.1 2007/05/14 09:47:14 bw Exp $
*
* ~Date: 2007/05/14 09:47:14 $
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
* ~Log: encoding.h,v $
* Revision 1.1  2007/05/14 09:47:14  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/encoding.h,v 1.2 2007/04/04 06:51:41 bw Exp $
*
* ~Id: encoding.h,v 1.2 2007/04/04 06:51:41 bw Exp $
*
* ~Date: 2007/04/04 06:51:41 $
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
* ~Log: encoding.h,v $
* Revision 1.2  2007/04/04 06:51:41  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* Encoding of types for Objective C.
   Copyright (C) 1993, 1997 Free Software Foundation, Inc.

Author: Kresten Krab Thorup

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* As a special exception, if you link this library with files
   compiled with GCC to produce an executable, this does not cause
   the resulting executable to be covered by the GNU General Public License.
   This exception does not however invalidate any other reasons why
   the executable file might be covered by the GNU General Public License.  */

#ifndef __encoding_INCLUDE_GNU
#define __encoding_INCLUDE_GNU

#include <ctype.h>
#include "objc/objc-api.h"

#define _C_CONST	'r'
#define _C_IN		'n'
#define _C_INOUT	'N'
#define _C_OUT      	'o'
#define _C_BYCOPY	'O'
#define _C_BYREF	'R'
#define _C_ONEWAY	'V'
#define _C_GCINVISIBLE	'!'

#define _F_CONST	0x01
#define _F_IN		0x01
#define _F_OUT		0x02
#define _F_INOUT	0x03
#define _F_BYCOPY	0x04
#define _F_BYREF	0x08
#define _F_ONEWAY	0x10
#define _F_GCINVISIBLE	0x20

int objc_aligned_size (const char* type);
int objc_sizeof_type (const char* type);
int objc_alignof_type (const char* type);
int objc_aligned_size (const char* type);
int objc_promoted_size (const char* type);

const char* objc_skip_type_qualifiers (const char* type);
const char* objc_skip_typespec (const char* type);
const char* objc_skip_offset (const char* type);
const char* objc_skip_argspec (const char* type);
int method_get_number_of_arguments (struct objc_method*);
int method_get_sizeof_arguments (struct objc_method*);

char* method_get_first_argument (struct objc_method*,
				 arglist_t argframe, 
				 const char** type);
char* method_get_next_argument (arglist_t argframe, 
				const char **type);
char* method_get_nth_argument (struct objc_method* m, 
			       arglist_t argframe,
			       int arg, 
			       const char **type);

unsigned objc_get_type_qualifiers (const char* type);


struct objc_struct_layout 
{
  const char *original_type;
  const char *type;
  const char *prev_type;
  unsigned int record_size;
  unsigned int record_align;
};

void objc_layout_structure (const char *type,
                            struct objc_struct_layout *layout);
BOOL  objc_layout_structure_next_member (struct objc_struct_layout *layout);
void objc_layout_finish_structure (struct objc_struct_layout *layout,
                                   unsigned int *size,
                                   unsigned int *align);
void objc_layout_structure_get_info (struct objc_struct_layout *layout,
                                     unsigned int *offset,
                                     unsigned int *align,
                                     const char **type);

#endif /* __encoding_INCLUDE_GNU */
