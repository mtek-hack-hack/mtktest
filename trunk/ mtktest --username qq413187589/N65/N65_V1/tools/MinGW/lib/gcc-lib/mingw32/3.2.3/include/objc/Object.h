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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/Object.h,v 1.1 2007/05/17 07:25:45 bw Exp $
*
* $Id: Object.h,v 1.1 2007/05/17 07:25:45 bw Exp $
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
* $Log: Object.h,v $
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/Object.h,v 1.1 2007/05/14 09:47:14 bw Exp $
*
* ~Id: Object.h,v 1.1 2007/05/14 09:47:14 bw Exp $
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
* ~Log: Object.h,v $
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/lib/gcc-lib/mingw32/3.2.3/include/objc/Object.h,v 1.2 2007/04/04 06:51:41 bw Exp $
*
* ~Id: Object.h,v 1.2 2007/04/04 06:51:41 bw Exp $
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
* ~Log: Object.h,v $
* Revision 1.2  2007/04/04 06:51:41  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* Interface for the Object class for Objective-C.
   Copyright (C) 1993, 1994, 1995 Free Software Foundation, Inc.

This file is part of GNU CC.

GNU CC is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

GNU CC is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* As a special exception, if you link this library with files compiled
   with GCC to produce an executable, this does not cause the resulting
   executable to be covered by the GNU General Public License.  This
   exception does not however invalidate any other reasons why the
   executable file might be covered by the GNU General Public License. */

#ifndef __object_INCLUDE_GNU
#define __object_INCLUDE_GNU

#include <objc/objc.h>
#include <objc/typedstream.h>

/*
 * All classes are derived from Object.  As such,
 * this is the overhead tacked onto those objects.
 */
@interface Object
{
    Class	isa;	/* A pointer to the instance's class structure */
}

        /* Initializing classes and instances */
+ initialize;
- init;

        /* Creating, freeing, and copying instances */
+ new;
+ alloc;
- free;
- copy;
- shallowCopy;
- deepen;
- deepCopy;

        /* Identifying classes */
- (Class)class;
- (Class)superClass;
- (MetaClass)metaClass;
- (const char *)name;

        /* Identifying and comparing objects */
- self;
- (unsigned int)hash;
- (BOOL)isEqual:anObject;
- (int)compare:anotherObject;

        /* Testing object type */
- (BOOL)isMetaClass;
- (BOOL)isClass;
- (BOOL)isInstance;

        /* Testing inheritance relationships */
- (BOOL)isKindOf:(Class)aClassObject;
- (BOOL)isMemberOf:(Class)aClassObject;
- (BOOL)isKindOfClassNamed:(const char *)aClassName;
- (BOOL)isMemberOfClassNamed:(const char *)aClassName;

        /* Testing class functionality */
+ (BOOL)instancesRespondTo:(SEL)aSel;
- (BOOL)respondsTo:(SEL)aSel;

	/* Testing protocol conformance */
- (BOOL)conformsTo:(Protocol*)aProtocol;

        /* Introspection */
+ (IMP)instanceMethodFor:(SEL)aSel;
- (IMP)methodFor:(SEL)aSel;
+ (struct objc_method_description *)descriptionForInstanceMethod:(SEL)aSel;
- (struct objc_method_description *)descriptionForMethod:(SEL)aSel;

        /* Sending messages determined at run time */
- perform:(SEL)aSel;
- perform:(SEL)aSel with:anObject;
- perform:(SEL)aSel with:anObject1 with:anObject2;

        /* Forwarding */
- (retval_t)forward:(SEL)aSel :(arglist_t)argFrame;
- (retval_t)performv:(SEL)aSel :(arglist_t)argFrame;

        /* Posing */
+ poseAs:(Class)aClassObject;
- (Class)transmuteClassTo:(Class)aClassObject;

        /* Enforcing intentions */
- subclassResponsibility:(SEL)aSel;
- notImplemented:(SEL)aSel;
- shouldNotImplement:(SEL)aSel;

        /* Error handling */
- doesNotRecognize:(SEL)aSel;
- error:(const char *)aString, ...;

        /* Archiving */
+ (int)version;
+ setVersion:(int)aVersion;
+ (int)streamVersion: (TypedStream*)aStream;

- read: (TypedStream*)aStream;
- write: (TypedStream*)aStream;
- awake;

@end

#endif
