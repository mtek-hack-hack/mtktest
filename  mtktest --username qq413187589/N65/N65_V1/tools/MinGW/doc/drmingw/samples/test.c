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
* $CVSHeader: P_U25U26_06B_V30/codes/06BW0712MP_1_U26_06B_V30_gprs_MMI/tools/MinGW/doc/drmingw/samples/test.c,v 1.1 2007/05/17 07:24:58 bw Exp $
*
* $Id: test.c,v 1.1 2007/05/17 07:24:58 bw Exp $
*
* $Date: 2007/05/17 07:24:58 $
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
* $Log: test.c,v $
* Revision 1.1  2007/05/17 07:24:58  bw
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
* ~CVSHeader: P_U25U26_06B_V28/codes/06BW0712MP_1_U26_06B_V28_gprs_MMI/tools/MinGW/doc/drmingw/samples/test.c,v 1.1 2007/05/14 09:44:28 bw Exp $
*
* ~Id: test.c,v 1.1 2007/05/14 09:44:28 bw Exp $
*
* ~Date: 2007/05/14 09:44:28 $
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
* ~Log: test.c,v $
* Revision 1.1  2007/05/14 09:44:28  bw
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
* ~CVSHeader: P_U25U26_06B/codes/U25U26_06B_W07.12_MMI/tools/MinGW/doc/drmingw/samples/test.c,v 1.2 2007/04/04 06:51:30 bw Exp $
*
* ~Id: test.c,v 1.2 2007/04/04 06:51:30 bw Exp $
*
* ~Date: 2007/04/04 06:51:30 $
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
* ~Log: test.c,v $
* Revision 1.2  2007/04/04 06:51:30  bw
* 增加.c.h文件头模板
*
*
*----------------------------------------------------------------------------
* Upper this line, this part is controlled by CVS. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/* test-c.c
 *
 * A sample C program to demonstrate the symbolic capabilities
 * of Dr.MinGW.
 *
 * Jose Fonseca
 */

#include <stdio.h>

void YetAnotherFunction(int i)
{
	int k;
	
#if 0
	/* Other ways to cause a GPF */
	*(int *)i = 5;  
	__asm ("int $3");
	(*((void (*)(void)) 0x12345678))();
#endif
	sscanf("12345", "%i", (int *) (k=i));
}

struct AStructType
{
	int AnArray[2];
};

void MyWonderfulFunction(int AnInteger, double ADouble, int AnArray[4], char * AString, enum {a,b,c} AnEnum, struct AStructType AStruct, void (*AFunction)(void))
{
	YetAnotherFunction( 8 );
}

void ASimpleFunction(void) {}

int main(int argc, char *argv[])
{
	struct AStructType AStruct = {{10, 3}};
	int AnArray[4] = {4,3,2,1};
	
	MyWonderfulFunction( 4, 5.6, AnArray, "Hello" , 1, AStruct, ASimpleFunction);

	return 0;
}
