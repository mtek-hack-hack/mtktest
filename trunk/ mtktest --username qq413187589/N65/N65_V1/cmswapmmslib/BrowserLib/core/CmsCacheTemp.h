#ifndef _CMS_CACHE_TEMP_H
#define _CMS_CACHE_TEMP_H


void   Cms_SaveCache(void * p_add, unsigned int len);
void * Cms_LoadCache(void);
int Cms_Browser_SavePageSize(void);
char* Cms_Browser_GetSavePageBuf(void);
void Cms_Browser_Download_Progress(int v_RecvBytes , int v_TotalBytes);
void Cms_Browser_Download_Result(int result);

#endif

