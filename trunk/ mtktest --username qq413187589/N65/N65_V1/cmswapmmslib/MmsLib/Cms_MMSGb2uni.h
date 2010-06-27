#ifndef _GB2UNI_H_
#define _GB2UNI_H_


int trans_gb_utf8(char input[],char output[], unsigned int length);
int trans_utf8_gb(char input[],char output[], unsigned int length);

int cms_unicode2utf(unsigned short *unicode, int uni_length,unsigned char *utf8, int *utf_length);/*Modify for MTK*/
int leunicode2utf(unsigned short *unicode, int uni_length,unsigned char *utf8, int *utf_length);
int cms_utf2unicode(unsigned char*utf8,int utf_len,unsigned short *unicode,int uni_len);
int adjust_to_biged(unsigned short *us);
#endif
