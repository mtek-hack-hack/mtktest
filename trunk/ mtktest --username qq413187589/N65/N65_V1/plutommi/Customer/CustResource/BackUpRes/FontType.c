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
#include "MMI_features.h"
#include "FontRes.h"
#include "PixComFontEngine.h"

/*	Default fonts								*/
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
stFontAttribute		UI_DEFAULT_FONT={	0,0,0,MEDIUM_FONT,0,1	};
/*	MMI fonts									*/
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
stFontAttribute		MMI_small_font=			{	0,0,0,SMALL_FONT,0,1	};
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
stFontAttribute		MMI_medium_font=		{	0,0,0,MEDIUM_FONT,0,1	};
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
stFontAttribute		MMI_medium_bold_font=	{	1,0,0,MEDIUM_FONT,0,1	};
//MTK Add By Elvis for dialling font
#ifdef __MMI_DIALLING_FONT__
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
stFontAttribute     MMI_large_font=         {   0,0,0,MEDIUM_FONT,0,1    };
#else
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
stFontAttribute		MMI_large_font=			{	0,0,0,LARGE_FONT,0,1	};
#endif
//MTK end
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
stFontAttribute		MMI_default_font=		{	0,0,0,MEDIUM_FONT,0,1	};

/*	Dialer input box functions	*/
/* font value of dialer input box */
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
stFontAttribute wgui_dialer_box_f1={	0,0,0,DIALER_FONT,0,1	};
#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
stFontAttribute wgui_dialer_box_f2={	0,0,0,MEDIUM_FONT,0,1	};
/*	stFontAttribute wgui_dialer_box_f3={	0,0,0,SMALL_FONT,0,1	};	*/

#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
stFontAttribute		MMI_sublcd_font=			{	0,0,0,SUBLCD_FONT,0,1	};

#if !defined (MMI_ON_HARDWARE_P)
__declspec(dllexport) 
#endif
stFontAttribute		MMI_virtual_keyboard_font=			{	0,0,0,VIRTUAL_KEYBOARD_FONT,0,1	};


