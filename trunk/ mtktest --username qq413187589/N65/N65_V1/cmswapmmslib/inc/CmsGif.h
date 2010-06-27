#ifndef __GIF_H__
#define __GIF_H__

#define GIF_MAXCOLORS	256

/************************************************************/
/*					Gif数据结构								*/
/************************************************************/
typedef struct tagCOLOR
{
	char red;
	char green;
	char blue;
	//CENT_FILL_FIELD1
} GIFColor;

typedef enum {
	gif_image, 
	gif_comment, 
	gif_text
} GIFStreamType;

typedef enum {
	gif_no_disposal = 0,
	gif_keep_disposal = 1, 
	gif_color_restore = 2, 
	gif_image_restore = 3
} GIFDisposalType;

typedef struct {
	int		transparent;	/* transparency index           */
	int		delayTime;	    /* Time in 1/100 of a second    */
	int		inputFlag;	    /* wait for input after display */
	GIFDisposalType	disposal;
} GIF89info;

typedef struct GIFData {
	GIF89info	info;
	int		x, y;
	int		width, height;
	GIFStreamType	type;
	union unData{
		struct tagImage{
			int		cmapSize;
			unsigned char	cmapData[GIF_MAXCOLORS][3];
			unsigned char	*data;
			int		interlaced;
		} image;
		struct tagText{
			int	fg, bg;
			int	cellWidth, cellHeight;
			int	len;
			char	*text;
		} text;
		struct tagComment{
			int	len;
			char	*text;
		} comment;
	} data;

	struct GIFData	*next;
} GIFData;

typedef struct {
	int		width, height;

	int		colorResolution;
	int		colorMapSize;
	int		cmapSize;
	unsigned char	cmapData[GIF_MAXCOLORS][3];

	int		background;
	int		aspectRatio;

	GIFData		*data;
} GIFStream;

/* Revised by Longqiangl 2003-12-22*/
//GIFData *GIFReadSlide(FILE_HANDLE fd);
char GIFReadSlide(FILE_HANDLE fd,GIFData **pFrame);

GIFStream *GIFReadHead(FILE_HANDLE fd);


typedef struct _tagGifInfo{
    char *filename;         /***	gif文件名称  ***/    
    int screenwidth;        /***	显示屏幕的宽度***/
    
    double proportion;      /***	gif压缩比例  ***/    
    int bsingleframe;       /***	0:多帧；1：单帧  ***/        
    int width;              /***	gif动画的宽度  ***/    
    int height;             /***	gif动画的高度  ***/
    int proporwidth;        /***	gif动画压缩后的宽度  ***/
    int proporheight;       /***	gif动画压缩后的高度  ***/    
}GifInfo_t;

/***************************************************************************
 int LoadGif(void);
 Description:	进入Gif库;
 Param		:	NULL;
 Return		:	0; if OK;
				-1;if Error;
 Date		:	2003-6-9
 Author		:	滕永; yongt@mobilesoft.com.cn
****************************************************************************/
int LoadGif(void);

/***************************************************************************
 int UnLoadGif(void) ;
 Description:	退出Gif库
 Param		:	NULL;
 Return		:	0; if OK;
				-1;if Error;
 Date		:	2003-6-9
 Author		:	滕永; yongt@mobilesoft.com.cn
****************************************************************************/
int UnLoadGif(void);

/********************************************************************
 int GetGifInfo(GifInfo_t *pGifinfo)
 Description:   获得gif动画的数据信息;
 Param		:	(IN/OUT)：  gif动画的数据信息;
 Return		:	0；if Ok;
                -1;if Error;

 Date		:	2003-7-21
 Author		:	滕永; yongt@mobilesoft.com.cn
*********************************************************************/
int GetGifInfo(GifInfo_t *pGifinfo);






/***************************************************************************
 int	GIF_Verify_Legal_File(char *);	 
 Description:	判断输入的文件是否为gif文件类型;
 Param		:	(IN)file;Gif文件;
 Return		:	1;if是Gif文件类型;
				2;if不是Gif文件类型;
 Date		:	2003-5-20
 Author		:	滕永; yongt@mobilesoft.com.cn
****************************************************************************/
int GIF_Verify_Legal_File(char *file);

/***************************************************************************
 double GetProportion(int picturewidth,int screenwidth);
 Description:	获得画图比例;
 Param		:	(IN)picturewidth,图片的宽度;
				(IN)screenwidth, 屏幕的宽度;
 Return		:	double, 显示图片的比例;
 Date		:	2003-6-9
 Author		:	滕永; yongt@mobilesoft.com.cn
****************************************************************************/
float tGetProportion(int picturewidth,int screenwidth);


void FreeGifData(GIFData *pGifData);
void FreeGifStream(GIFStream *pStream);

int _ex_GetGifInfo(unsigned char * filename,int  screenwidth,unsigned int * pWidth, unsigned int * pHeight);

#endif