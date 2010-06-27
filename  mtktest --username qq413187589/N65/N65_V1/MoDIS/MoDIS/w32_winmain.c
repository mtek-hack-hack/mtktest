/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   w32_winmain.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Main function of PC simulator
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "stdafx.h"
#include "resource.h"
#include <stdio.h>
#include <shlobj.h>
#include <process.h>
#include "lcd_sw_inc.h"
#include "kal_release.h"
#include "w32_dspl.h"

//////////////////////////////////////////////////////////////////
// Resource defination
//////////////////////////////////////////////////////////////////
#define NVRAM_FILENAME "..\\..\\fs\\flash_device.img"
#define BACKUP_NVRAM_FILENAME "..\\..\\fs\\flash_device.bak"
#define NVRAM_SIZE (16*1024*1024)
//////////////////////////////////////////////////////////////////
// Global variable
//////////////////////////////////////////////////////////////////
#define MAX_LOADSTRING 100

HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];	
static HWND mhwnd;
static long timer_count = 0;

#define WIN_START_POSX   0
#define WIN_START_POSY   0
static char szCnfgPath[MAX_PATH];
static char currentPath[MAX_PATH];
char skin_size[20];
// The title bar text
// Foward declarations of functions included in this code module:
ATOM				w32_RegisterClass(HINSTANCE hInstance);
BOOL				w32_InitInstance(HINSTANCE, int);
BOOL				AUTO_POWER=FALSE;
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
extern BYTE *pResizeData;
extern T_W32_SCREEN_DEVICE				device;

extern unsigned __stdcall TTYInit(void *i1);


extern void	w32_key_detect_ind(unsigned char key_status, unsigned char key_code);
extern void	w32_charger_inout(void);
extern void	w32_incoming_call(void);
extern void	w32_screen_init(HWND hWnd, HINSTANCE hInstance);
extern void	mouse_lbutton_down(HWND, int, int, int, int);
extern void	mouse_lbutton_up(HWND,int ,int, int);
extern void	w32_keydown_by_shortcut(HWND, int);
extern void w32_keyup_by_shortcut(HWND, unsigned int);
extern void	mouse_move(HWND, int, int, int, int);
extern void	w32_draw_main_bitmap(HDC);
extern void w32_vibrate_by_move(kal_uint8);
extern void	w32_update_screen(void);
extern void	w32_TASK_Initialization(void);
extern void	w32_ResetKeyMemory(void);
extern void	w32_ReadKeyProfile(char path[], HWND hwnd);
extern void	w32_dspl_init(void);
extern int w32_push_input_into_editor_component(char *szItemInput, int szItemInputLen);
//extern void CALLBACK RTC_TCintr(HWND hwnd,UINT uMsg,UINT idEvent, DWORD dwTime); 
//extern void RTC_TCintr(void); 
extern void QueryUARTStatus(void);
extern void w32_send_multi_sms(void);
extern void w32_post_data(void);
extern void w32_set_channel(void);
extern void w32_send_single_sms(void);
extern void w32_send_multi_sms(void);
extern void w32_send_single_binary_sms(void);
extern kal_bool stack_resources_init(void);
extern void stack_init_buff_pool_info(void);
extern void w32_gsm_timealarm(void);
extern void w32_download(void);
extern int mainp(void);

int __stdcall  MtkWinMainStart ( void * argv);

extern __declspec(dllimport)
void modislog(BOOL poweron);
extern __declspec(dllimport)
void MoDisUIDllStart(
	void (*w32_key_detect_ind_callback)(unsigned char, unsigned char),
	void (*w32_screen_init_callback)(HWND, HINSTANCE),
	void (*w32_keydown_by_mouse_callback)(HWND, int, int,int,int),
	void (*w32_keyup_by_mouse_callback)(HWND,int, int, int),
	void (*w32_keydown_by_shortcut_callback)(HWND, int),
	void (*w32_keyup_by_shortcut_callback)(HWND, unsigned int),
	void (*w32_mouse_move_enable_callback)(HWND, int, int, int, int),
	int	 (*w32_push_input_into_editor_component)(char *, int),
	void (*w32_draw_main_bitmap_callback)(HDC),
	void (*w32_update_screen_callback)(void),
	void (*w32_TASK_Initialization_callback)(void),
	void (*w32_ReadKeyProfile_callback)(char [], HWND hwnd),
	void (*w32_ResetKeyMemory_callback)(void),
	void (*w32_dspl_init_callback)(void),
	void (*w32_timer_callback)(int),
	BOOL (*w32_msg_pretranslate_callback)(MSG*),
	void (*w32_vibrate_by_move_callback)(kal_uint8),
	char* (*w32_exec_func_callback)(unsigned int) //1,implies get version,2 implies set idle screen
	
);

////////////////////////////////////////////////////////////////////
/// function declaration
////////////////////////////////////////////////////////////////////
static int w32_SaveWinPos(void);
static int w32_ReadWinPos(POINT* pPt);
static void process_command(HWND hwnd,WORD command);

extern void w32_copy_java_file(void);
//extern void w32_timer_init(void);
extern void w32_screen_init(HWND hWnd,HINSTANCE hInstance);

extern BOOL w32_touch_screen_button_down(int,int);
extern BOOL w32_touch_screen_button_move(int,int);
extern BOOL w32_touch_screen_button_up(int,int);

static void w32_CopyNvram(const char *src_filename,const char *dest_filename);
void w32_CloseAndCreateMoDIS(void);
void w32_WaitAnotherMoDISClose(void);
extern __declspec(dllimport)
void CloseAndCreateMoDIS(void);




/////////////////////////////////////////////////////////////////////
void w32_WaitAnotherMoDISClose(void)
{
	HWND hInstance1 =	FindWindow( NULL,"MTK Simulator" );
	char path[1024],boot[20],tempbuf[1024];
	char *name;
	memset(tempbuf, 0, sizeof(tempbuf));
	if(!SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))		         
			return ;
	strncpy(tempbuf, path, strlen(path)-strlen(name));
	sprintf(path, "%sMoDIS.ini", tempbuf);
	GetPrivateProfileString("AutoTest", "MoDIS", "DEFAULT", boot, sizeof(boot), path);
	if(boot[0]=='R')//mean "Reboot"
	{
	if(hInstance1!=NULL)
	{
	   while(hInstance1!=NULL)
       {  
		   Sleep(1000);	
		   hInstance1 =	FindWindow( NULL,"MTK Simulator" );
	   }
	}
	}
}
void w32_CloseAndCreateMoDIS(void)
{
	CloseAndCreateMoDIS();
}
BOOL w32_msg_pretranslate_callback(MSG *pMsg)
{
    /* return TRUE means u want to intercept this message */

    return FALSE;
}


void w32_pc_simulator_init(void)
{
	GetCurrentDirectory(sizeof(currentPath), currentPath);
	if(stricmp(currentPath+ strlen(currentPath)-strlen("debug"),"debug")!=0)
	{
		strcat(currentPath,"\\debug");
		SetCurrentDirectory(currentPath);
	}
}

void w32_modis_poweron_log(BOOL powerok)
{
	modislog(powerok);
}


void w32_TASK_Initialization(void)
{
   //t9_support_menuitem();
   //w32_timer_init();
}

extern void fatal_error_handler( kal_uint8 *err_msg_ptr, kal_int32 err_code, kal_int32 os_err_code);
extern void InitializeResourceVariables(void);
extern unsigned int g_osc_system_initialized; 

void w32_timer_callback(int id)
{
	/* each tick is 100ms */
	timer_count++;

	if(timer_count >= 1000000)
	{
		timer_count = 0;
	}

	/* UART, 100 ms */
	QueryUARTStatus();
}


extern HBITMAP get_mainlcd_hbitmap(void);

extern char* release_verno();
extern char* release_hw_ver();
extern void mmi_netset_inject_network_attachment();
typedef enum {
	NULL_CB = 0
	,GET_MODIS_MAUI_VERSION
	,SET_IDLE_SCREEN
	,SET_AUTO_POWER_TRUE
	,GET_MMI_VERSION
    ,COPY_MAIN_LCD_SCREEN
	,GET_MMI_SKIN_SIZE
	,CREATE_LCD_BUFFER
} MODIS_CB_FUNC;
char* w32_exec_func_callback(unsigned int func_num)
{	
	/*
	if(func_num==1)
	{
		char *swver,*hwver;
		swver = release_verno();
		hwver = release_hw_ver();
		
		strcat(hwver,swver);
		return hwver;
	}
	else if(func_num==2)
	{
		mmi_netset_inject_network_attachment();
		return "DUMMY";
	}
	else if(func_num==3)
	{
		AUTO_POWER=TRUE;
		return "DUMMY";
	}
	else if(func_num==4)
	{
		#ifdef PLUTO_MMI
			return "PLUTO_MMI";
		#else
			return "LC_MMI";
		#endif
	}
	return "DUMMY";*/
	switch(func_num){
		case GET_MODIS_MAUI_VERSION:
		{
			char *swver,*hwver;
			swver = release_verno();
			hwver = release_hw_ver();
			
			strcat(hwver,swver);
			return hwver;
		}
		case SET_IDLE_SCREEN:
		{
			mmi_netset_inject_network_attachment();
			return "DUMMY";
		}
		case SET_AUTO_POWER_TRUE:
		{
			AUTO_POWER=TRUE;
			return "DUMMY";
		}
		case GET_MMI_VERSION:
		{
			#ifdef PLUTO_MMI
				return "PLUTO_MMI";
			#else
				return "LC_MMI";
			#endif
		}
        case COPY_MAIN_LCD_SCREEN:
        {   /* get main lcd bitmap */
            return (char*)get_mainlcd_hbitmap();        	       
		}
		case GET_MMI_SKIN_SIZE:
		{
			
			sprintf(skin_size, "%dx%d",LCD_WIDTH,LCD_HEIGHT );
			
			return skin_size;
			//return "176x220";
		}
		case CREATE_LCD_BUFFER:
		{
			if(pResizeData!=NULL)
				free(pResizeData);
			pResizeData = (BYTE *) malloc(device.main_lcd_width*device.main_lcd_height*sizeof(BYTE)*4);
			kal_print("device.main_lcd_width*device.main_lcd_height=%d,%d",device.main_lcd_width,device.main_lcd_height);
			return "DUMMY";
		}
		default:
			return "DUMMY";
	}
}


int __stdcall  MtkWinMainStart ( void * argv)
//karen add end

{
	char				ui_wd[256];
	char				os_wd[256];
//	unsigned	int	tid;
//	unsigned long	ret;

    HINSTANCE hInstance = GetModuleHandle(NULL);

 	// TODO: Place code here.
//	MSG msg;
//	HACCEL hAccelTable;
	
	/* get the working directory for UI */
	GetCurrentDirectory(256, ui_wd);

	/* Register display handler */
	kal_register_print_string_function((kal_print_string_func_ptr)stack_print);

	/* Register stack fatal error handler */
	kal_register_fatal_error_handler((kal_error_func_ptr)fatal_error_handler);
	
    kal_print("System > Initializing system memory...\n");
	kal_initialize_mem();
   
	/* Initializing the Buffer Pool Information */	
	stack_init_buff_pool_info();
   
	/* Create buffer pools */
	kal_print("System > Creating buffer pool...\n");
	stack_resources_init();   

	/* Initialize KAL resources */
	kal_print("System > Initializing KAL resource...\n");
	kal_initialize();	
	
	InitializeResourceVariables();

    mainp();

    g_osc_system_initialized = 1;

    kal_print("System > System initialization done!\n");
 
	/* get the working directory for OS */
	GetCurrentDirectory(256, os_wd);
	/* set the working directory to what UI needs */
	SetCurrentDirectory(ui_wd);


	/* start MoDis UI */
	MoDisUIDllStart(
		w32_key_detect_ind,
		w32_screen_init,
		mouse_lbutton_down,
		mouse_lbutton_up, 
		w32_keydown_by_shortcut,
		w32_keyup_by_shortcut,
		mouse_move,
		w32_push_input_into_editor_component,
		w32_draw_main_bitmap,
		w32_update_screen,
		w32_TASK_Initialization,
		w32_ReadKeyProfile,
		w32_ResetKeyMemory,
		w32_dspl_init,
		w32_timer_callback,
		w32_msg_pretranslate_callback,
		w32_vibrate_by_move,
		w32_exec_func_callback
	);

	/* restore to the working directory that OS needs */
	SetCurrentDirectory(os_wd);
	
	return 1;
}

ATOM w32_RegisterClass
(
 HINSTANCE hInstance
 )
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_L_MTK);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)IDC_MTK_SIMULATOR;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_S_MTK);

	return RegisterClassEx(&wcex);
}


BOOL w32_InitInstance
(
 HINSTANCE hInstance, 
 int nCmdShow
 )
{
   HWND hWnd;

   POINT xyWinPos;
   int   simulator_w,simulator_h;

   hInst = hInstance; // Store instance handle in our global variable

   memset( &xyWinPos, 0x0, sizeof(xyWinPos) );
   memset( szCnfgPath, 0x0, sizeof(szCnfgPath) );
   GetCurrentDirectory(sizeof(szCnfgPath), szCnfgPath);
   sprintf(szCnfgPath, "%s%s", szCnfgPath, "\\mtk.cfg");

   if ( !w32_ReadWinPos(&xyWinPos) )
   {
       /* fault: read positon from config file  */
       xyWinPos.x= WIN_START_POSX;
       xyWinPos.y= WIN_START_POSY;
   }
   simulator_w = 10+(LCD_WIDTH> 154 ? LCD_WIDTH: 154);
   simulator_h = 50+(LCD_HEIGHT + 10 + 261);
   #ifdef DUAL_LCD
   simulator_h += SUBLCD_HEIGHT;
   #endif

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      xyWinPos.x, xyWinPos.y, simulator_w, simulator_h, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }
   mhwnd=hWnd;
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);


   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	static HBITMAP main_bmp,key_bmp ;
	static int     cxClient, cyClient, cxSource, cySource,xPos,yPos;
	static HINSTANCE      hInstance ;
	static RECT device_lcd;
			  
	void *i1=NULL;
	extern void QueryUARTStatus();
	
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);
	switch (message) 
	{
	case WM_CREATE:
		OleInitialize(NULL);
	        hInstance = ((LPCREATESTRUCT) lParam)->hInstance ;
		w32_screen_init(hWnd,hInstance);
		
        return 0 ;

	case WM_LBUTTONDOWN:
			
		/*
			if (!w32_touch_screen_button_down(1,1))
			{
				 xPos = LOWORD(lParam);  // horizontal position of cursor 
				 yPos = HIWORD(lParam);  // vertical position of cursor
				 w32_keydown_by_mouse(hWnd,xPos,yPos);	
			 }*/
			
			 return 0;
	case WM_LBUTTONUP:
			
		/*	
		if (!w32_touch_screen_button_up())
			{
				 w32_keyup_by_mouse(hWnd);
			}
*/
			 return 0;

	case WM_KEYDOWN:	 

			w32_keydown_by_shortcut(hWnd,(int)wParam);	

			return 0;
	case WM_KEYUP:

//			w32_keyup_by_mouse(hWnd);

			return 0;
	case WM_MOUSEMOVE:
/*
			if (!w32_touch_screen_button_move())
			{
				 xPos = LOWORD(lParam);  // horizontal position of cursor 
				 yPos = HIWORD(lParam);  // vertical position of cursor
				 w32_mouse_move_enable(hWnd,xPos,yPos);	
			}*/

         return 1;
	case WM_TIMER:
	     if(wParam == 101)
	        QueryUARTStatus();
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		w32_draw_main_bitmap(hdc); 
	        w32_update_screen();
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
	         w32_SaveWinPos(); /* _wwf_901008_add for storing simulator position */
       	  PostQuitMessage(0);
			break;
	case WM_COMMAND:

		process_command(hWnd,LOWORD(wParam));
		break;
	default:

		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
static void process_command(HWND hwnd,WORD command) 
{
	switch(command)
	{
	case ID_GSM_TIMEALARM:
		w32_gsm_timealarm();
		break;
	case IDM_WIN_POS_STORE:
		w32_SaveWinPos();
		break;
	case ID_BACKUP_NVRAM:
		w32_CopyNvram(NVRAM_FILENAME,BACKUP_NVRAM_FILENAME);
		break;
	case ID_RESTORE_NVRAM:
		w32_CopyNvram(BACKUP_NVRAM_FILENAME,NVRAM_FILENAME);
		break;
	case ID_CHARGER_IN:
		w32_charger_inout();
		break;
	case ID_DOWNLOAD:
		w32_download();
		break;
	case ID_GSM_INCOMINGCALLRING:
		w32_incoming_call();
		break;
	case ID_POST_DATA:
		w32_post_data();
		break;
	case ID_SET_CHANNEL:
		w32_set_channel();
		break;
	case ID_SEND_SMS:
		w32_send_single_sms();
		break;
	case ID_SEND_SMS_MULTI:
		w32_send_multi_sms();
		break;
	case ID_JAS_SENDSMS_BINARY:
		w32_send_single_binary_sms();
		break;
	}
}

extern int mmi_get_current_editor_style();
extern int mmi_send_direct_input_req(unsigned short* input, int editor_style);

int w32_push_input_into_editor_component(char *szItemInput, int szItemInputLen)
{
	int		style = 0, ret = 0;
	DWORD	err = 0;
	WCHAR	wszInput[1000]={0};

	/* 1. Check the current screen accept the input */
	style = mmi_get_current_editor_style();
	if (style < 0)
	{
		/* current screen doesn't support input directly */
		return -1;
	}

	/* 2. check if the input is valid  */
	if (ret < 0 || szItemInputLen >= 1000)
	{
		/* input content is invalid or too large */
		return 0;
	}

	/* 3. convert the input to Unicode format */
	ret = MultiByteToWideChar( CP_ACP, 0, szItemInput,
					   		   szItemInputLen, wszInput,   
							   sizeof(wszInput)/sizeof(wszInput[0]) );
	if (ret == 0)
	{
		err = GetLastError();
	}

	/* 4. send the message to ask MMI push the data in UI editor component */
	//#ifdef PLUTO_MMI
		ret = mmi_send_direct_input_req((unsigned short*)wszInput, style);
	//#endif
	return ret;
}


// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}

static int w32_ReadWinPos(POINT* pPt)
{
    FILE    *fCnfg;

    if (!pPt) return (int)0;

    fCnfg= fopen( szCnfgPath, "r");
    if (fCnfg)
    {
        fscanf(fCnfg, "%d\n", &pPt->x);
        fscanf(fCnfg, "%d\n", &pPt->y);
        fclose(fCnfg);

        return (int)1; /* return successful*/
    }

    return (int)0; /* return fault */
}

static int w32_SaveWinPos(void)
{
    FILE    *fCnfg;
    RECT    rectWin;

    fCnfg= fopen( szCnfgPath, "w");
    if (fCnfg)
    {
        if (GetWindowRect(mhwnd, &rectWin))
        {
            fprintf(fCnfg, "%d\n", rectWin.left);
            fprintf(fCnfg, "%d\n", rectWin.top);
        }
        fclose(fCnfg);

        return (int)1; /* return successful */
    }

    return 0; /* return fault */
}
static void w32_CopyNvram(const char *src_filename,const char *dest_filename)
{
	int nvram_size=0;
//	int i;

	FILE *src,*dest;

	src = fopen(src_filename,"rb");
	dest = fopen(dest_filename,"w+b");

	if(src && dest)
	{
		char buffer[512];
		while(1)
		{
			int read_size = fread(buffer,1,sizeof(buffer),src);
			if(read_size>0)
				fwrite(buffer,1,read_size,dest);
			else
				break;
		}
		fclose(src);
		fclose(dest);
	}
}

static void  w32_charger_inout(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}
