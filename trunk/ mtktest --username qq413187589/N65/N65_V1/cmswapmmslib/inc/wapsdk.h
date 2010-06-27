#ifndef WAPSDK_H
#define WAPSDK_H

#include "Cms_Css.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    int		cms_PrintHZOnScr(int x, int y, unsigned char* str, int isAnchor);
    int		cms_DrawLine(int x, int y, int length, int Horizontal);
    int		cms_DrawRect(int x, int y, int width, int height, int color);
    int		cms_ClearRect(int x, int y, int width, int height);
    int		cms_DrawCycle(int x, int y, int radius, int fill);
    int		cms_DrawPiex( int x, int y, unsigned int color );
    int cms_Put565ImgDataOnScr(int x, int y, unsigned char* ImgData );
    
    int cms_StartTimer( int timer_id,			/* (out) timer id */
						  unsigned short time_out );	/* timer period */
    void cms_StopTimer(int timerid);    
    int Cms_DisplayString (unsigned char font_type, /*(in)字体类型 */
					   int x, /*(in) 起始点的横坐标*/
                       int y, /*(in) 起始点的纵坐标*/
                       unsigned char *str, /* (in)待显示的字符串*/
                       unsigned int color, /*(in)字体颜色 */
                       unsigned char Mark, /*(in)是否标记显示*/
                       int isAnchor);/*(in)是否有下划线*/
    
    int Cms_MFCDrawColorLine (LineType_t  type, /*(in)线型*/
					   unsigned int width, /*线的宽度*/
                       unsigned int color,  /*线的颜色*/
                       int bx, /*(in)起始点横坐标*/
                       int by, /*(in)起始点纵坐标*/
                       int ex, /*(in)终点横坐标*/
                       int ey); /*(in)终点纵坐标*/
    
    void Cms_DrawBackGroundColor( unsigned int x, 
        unsigned int y, 
        unsigned int width, 
        unsigned int height,
        unsigned int BackGroudColor);
    void Cms_Browser_DrawTitle(unsigned char* title);

    void TraceInfo(char* str, ...);
    void Cms_DisplaySoftKey(unsigned char* pls, unsigned char* Rls);
    void AppExit(void);
    void Cms_Brw_SaveFile(char * data,int datalen,int type,int forwardtype);

    
#ifdef __cplusplus 
}
#endif

#endif // WAPSDK_H