/*
* Copyright (c) 2001,Mobilesoft Technology(Nanjing) Co.,LTD.
* All rights reserved.
* 
* FileName    : cmsword.h
* Description : convert word head file 
* 
* Version     : v1.0.0
* Author      : palmsource
* StartDate   : 2005/4/13
* FinishDate  : 2005/4/13
*/
#ifndef CMSWORD_H
#define CMSWORD_H

#include "cms_sysfun.h"

extern const unsigned short ASCIItoUNItbl[];
extern const unsigned int   CODE_NUM;
#define MIN_ASCII_CODE 	0xA1A1
#define MAX_ASCII_CODE 	0xF7FE

#define UTF8_VALID1(p) \
	( 0 == ((p)[0] & 0x80) )

#define UTF8_VALID2(p) \
	( 0xc0==( (p)[0]&0xe0 ) &&  (0x80== ( (p)[1]&0xc0) )  )

#define UTF8_VALID3(p) \
	( (0xe0==( (p)[0]&0xf0) ) &&  (0x80==( (p)[1]&0xc0) ) && (0x80== ( (p)[2]&0xc0) ) )

#define UTF8_VALID4(p) \
	( (0xf0==( (p)[0]&0xf8) ) &&  (0x80==( (p)[1]&0xc0) ) && (0x80==( (p)[2]&0xc0) ) && (0x80==( (p)[3]&0xc0) ) )

#ifndef TI //  Modified by TIPrj[2005/6/29]
#if defined( __cplusplus  ) && __cplusplus
extern "C"{
#endif
#endif 

unsigned int Cms_AsciiStrlen	(const unsigned char input[]);
unsigned int Cms_UTF16Strlen	(const unsigned char input[]);
unsigned int Cms_UTF8Strlen		(const unsigned char input[]);

unsigned int Cms_AsciitoUTF8Len	(const unsigned char input[]);
unsigned int Cms_AsciitoUTF16Len(const unsigned char input[]);
unsigned int Cms_UTF16toUTF8Len	(const unsigned char input[]);
unsigned int Cms_UTF16toAsciiLen(const unsigned char input[]);
unsigned int Cms_UTF8toAsciiLen	(const unsigned char input[]);
unsigned int Cms_UTF8toUTF16Len	(const unsigned char input[]);
unsigned int Cms_Latin1toUTF8Len(const unsigned char input[]);

unsigned short	Cms_UTF16ChartoAscii(unsigned short c);
void Cms_UTF16ChartoAsciiStr(unsigned short c, unsigned char uword[], unsigned int length);
int  Cms_UTF16ChartoUTF8    (unsigned short c, unsigned char output[], int length);
void Cms_UTF16toUTF8	    (const unsigned char input[], unsigned int inlen, unsigned int outlen, unsigned char output[]);
void Cms_UTF16toAscii	    (const unsigned char input[], unsigned int inlen, unsigned int outlen, unsigned char output[]);
void Cms_Latin1toUTF8		(const unsigned char input[], unsigned int inlen, unsigned int outlen, unsigned char output[]);

unsigned short	Cms_AsciiChartoUTF16(unsigned short c);
void Cms_AsciitoUTF8 (const unsigned char input[], unsigned int inlen, unsigned int outlen, unsigned char output[]);
void Cms_AsciitoUTF16(const unsigned char input[], unsigned int inlen, unsigned int outlen, unsigned char output[]);

int	 Cms_UTF8ChartoUTF16(const unsigned char input[], int length, unsigned short *output);
void Cms_UTF8toUTF16	(const unsigned char input[], unsigned int inlen, unsigned int outlen, unsigned char output[]);
void Cms_UTF8toAscii	(const unsigned char input[], unsigned int inlen, unsigned int outlen, unsigned char output[]);

#ifndef TI  //  Modified by TIPrj[2005/6/29]
#if defined(__cplusplus) && (__cplusplus)
}
#endif
#endif 

#endif //CMSASCII_H