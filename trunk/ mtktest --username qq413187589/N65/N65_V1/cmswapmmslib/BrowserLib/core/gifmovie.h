#ifndef __GIF_H__
#define __GIF_H__


#define		GIF_MAXCOLORS	256
#define		GIF_TIMERID		200

typedef struct tagCOLOR
{
	char red;
	char green;
	char blue;
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





int 	CMS_GIF_Init(char *filename, int x, int y, int width, int height, int taskid, void *mempool);
int		CMS_GIF_Stop();
int		CMS_GIF_Draw(int timerid, void *mempool);

int				GIFGetDimension(char *filename, int *width, int *height);
unsigned short	*GIFGetData (char *datafile, int *w, int *h, void *mempool);
GIFStream		*GIFGetAllData (char *datafile, int *w, int *h, void *mempool);


#endif