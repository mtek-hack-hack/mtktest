#ifndef _ZARABIC_SHAPE_H_
#define _ZARABIC_SHAPE_H_

#include "Zi8API.h"

#define ARABIC_UNI_ALIF       0x627
#define ARABIC_UNI_ALIFHAMZA  0x623
#define ARABIC_UNI_ALIFIHAMZA 0x625
#define ARABIC_UNI_ALIFMADDA  0x622
#define ARABIC_UNI_LAM        0x644
#define ARABIC_UNI_HAMZA      0x621
#define ARABIC_UNI_WAW        0x648
#define ARABIC_UNI_WAWHAMZA   0x624

#define ARABIC_UNI_SHADDA     0x651
#define ARABIC_UNI_KASRA      0x650

#define ARABIC_UNI_LAM_ALIF        0xFEFB
#define ARABIC_UNI_LAM_ALIFHAMZA   0xFEF7
#define ARABIC_UNI_LAM_ALIFIHAMZA  0xFEF9
#define ARABIC_UNI_LAM_ALIFMADDA   0xFEF5

#define ARABIC_ISO_HAMZA			0xc1
#define ARABIC_ISO_SUKUN			0xf2
#define ARABIC_UNI_SUKUN			0x0652
#define ARABIC_UNI_MADDAH			0x0653

#define ARABIC_ISO_COMMA			0xAC
#define ARABIC_ISO_SOFTHYPHEN		0xAD
#define ARABIC_ISO_SEMICOLON		0xBB
#define ARABIC_ISO_QUESTIONMARK		0xBF

#define ARABIC_UNI_COMMA			0x060C
#define ARABIC_UNI_SOFTHYPHEN		0x00AD
#define ARABIC_UNI_SEMICOLON		0x061B
#define ARABIC_UNI_QUESTIONMARK		0x061F


typedef struct {
	ZI8WCHAR	wBaseChar;
	ZI8WCHAR	wCharStart;
	ZI8UCHAR		iCount;
} ShapeStruct;

typedef struct {
    ZI8WCHAR		wBaseChar;
    ZI8WCHAR		wMark1;  /* has to be initialized to zero */
    ZI8WCHAR		wVowel;  /*  */
    char		chConnectToLeft;
    signed char	chLignum; /* is a ligature with lignum aditional characters */
    char        chNumShapes; 
} CharStruct;

ZI8VOID ArabicCharStructInit(CharStruct* s);

ZI8WCHAR ArabicCharShape(ZI8WCHAR wChar, ZI8USHORT uPos);
ZI8WCHAR ArabicCharUnshape(ZI8WCHAR wChar);
ZI8BOOL ArabicIsVowel(ZI8WCHAR wChar);
ZI8UCHAR ArabicShapeCount( ZI8WCHAR wChar);
ZI8SHORT ArabicLigature(PZI8WCHAR wString,ZI8SHORT si,ZI8SHORT len,CharStruct* oldchar);
/*	Note for ArabicStringShape(): All character of the input string must be in Unicode*/
ZI8SHORT ArabicStringShape(PZI8USHORT uLen, PZI8WCHAR wString);
ZI8SHORT ArabicStringShape2(PZI8USHORT uLen, PZI8WCHAR wString, 
							PZI8USHORT pOrgToSha, PZI8USHORT pShaToOrg);
/*Arabic code convert*/
ZI8WCHAR ArabicISO8859_6ToUnicode(unsigned char ch);
ZI8UCHAR ArabicUnicodeToISO8859_6(ZI8WCHAR wch);


#endif

