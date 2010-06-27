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
 *   rtfex.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains functions for exception handling
 *
 * Author:
 * -------
 *  
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <stddef.h>
#include <rtfex.h>
#include "kal_release.h"
#include <rtfiles.h>
#include "fs_kal.h"

#ifndef NODEBUG
   #define DEBUG
#endif

#ifdef EVALVER
#include <evalchk.h>
#else
#define RTEVALCHECK(n, m)
#endif

int _XTlsIndex = -1;  // assume this is an illegal value
#ifdef DEBUG
int _XWin32XChainTlsIndex = -1;
#endif

typedef enum { XCode,      // excuting code block
               XHandling,  // handling an exception
               XFinally    // executing finally block
             } XStatus;

/*-----------------------------------*/
static void Init(void)
{
   RTEVALCHECK(2, 0x98731092)

   _XTlsIndex = RTFSYSAllocTLS();
   if (_XTlsIndex == -1)
      RTFSYSErrorExit("Unable to allocate Exception TLS", 1);
#ifdef DEBUG
   _XWin32XChainTlsIndex = RTFSYSAllocTLS();
   if (_XWin32XChainTlsIndex == -1)
      RTFSYSErrorExit("Unable to allocate Exception TLS", 1);
#endif
}

/*-----------------------------------*/
_XData *  XAPI _XHandler(void)
{
   if (_XTlsIndex == -1)
      Init();
   return RTFSYSGetTLS(_XTlsIndex);
}

/*-----------------------------------*/
void XAPI _XRaiseException(int XValue)
{
   _XData * XD;

   if (_XTlsIndex == -1)
      Init();

#ifdef DEBUG
   if (XValue >= 0)
      RTFSYSErrorExit("Cannot raise positive error code", XValue);
#endif

   XD = RTFSYSGetTLS(_XTlsIndex);
   while (XD != NULL)
   {
#ifdef DEBUG
      //if (rtfGetFS(0) != RTFSYSGetTLS(_XWin32XChainTlsIndex))
         //RTFSYSErrorExit("Win32 exception handler frame below RTF exception frame", 1);
#endif
      XD->IsHandled = 0;
      switch (XD->State)
      {
         case XCode:       //  execute the handler
            XD->XValue = XValue;
            XD->State = XHandling;
            XRESTORECONTEXT(&XD->Context, XValue);
         case XHandling:   // next up must handle it, do finally first
            XD->XValue = XValue;
            XD->State = XFinally;
            XRESTORECONTEXT(&XD->Context, XFINALLY);
         case XFinally:  // raise within finally; propagate
#ifdef DEBUG
            RTFSYSErrorExit("Raise within finally", 1);
#endif
            RTFSYSSetTLS(_XTlsIndex, XD = XD->Next);
            break;
#ifdef DEBUG
         default:
            RTFSYSErrorExit("Corrupted exception handler chain", 1);
#endif
      }
   }
   RTFSYSErrorExit("Unhandled RTFiles exception", XValue);
}

/*-----------------------------------*/
void XAPI _XReExecute(void)
{
   _XData * XD = RTFSYSGetTLS(_XTlsIndex);

#ifdef DEBUG
   if (XD == NULL)
      RTFSYSErrorExit("no exception handler frame in XReExecute", 1);
#endif

   XD->XValue = XNOEX;
   XD->State = XCode;
   XD->IsHandled = 1;
   XRESTORECONTEXT(&XD->Context, XCODE);
}

/*-----------------------------------*/
void XAPI _XInitBlock(_XData * XD)
{
   if (_XTlsIndex == -1)
      Init();
   XD->Next = RTFSYSGetTLS(_XTlsIndex);
#ifdef DEBUG
/*
      if (XD->Next == NULL)
         RTFSYSSetTLS(_XWin32XChainTlsIndex, rtfGetFS(0));
      else
         if (rtfGetFS(0) != RTFSYSGetTLS(_XWin32XChainTlsIndex))
            RTFSYSErrorExit("Win32 exception handler frame below RTF exception frame", 1);
*/            
#endif
   RTFSYSSetTLS(_XTlsIndex, XD);
   XD->XValue = XNOEX;
   XD->State = XCode;
   XD->IsHandled = 1;
}

/*-----------------------------------*/
void  XAPI _XHandled(_XData * XD)
{
#ifdef DEBUG
   switch (XD->State)
   {
      case XHandling:
         break;
      case XCode:
      case XFinally:
         RTFSYSErrorExit("Internal: exception handled outside handler", 1);
      default:
         RTFSYSErrorExit("Corrupted exception handler chain", 1);
   }
#endif
   XD->XValue = XNOEX;
   XD->State = XCode;
   XD->IsHandled = 1;
}

/*-----------------------------------*/
XAction XAPI _XCloseBlock(_XData * XD)
{
#ifdef DEBUG
   if (RTFSYSGetTLS(_XTlsIndex) != XD)
      RTFSYSErrorExit("Corrupted exception handler chain", 1);
#endif

   switch (XD->State)
   {
      case XHandling:   // exception is now handled
      case XCode:       // no exception
         XD->State = XFinally;
         XRESTORECONTEXT(&XD->Context, XFINALLY);
      case XFinally:  // we are done
         RTFSYSSetTLS(_XTlsIndex, XD->Next);
         if (XD->IsHandled)
            return XBreak;  // continue after XTRY block
         else
            _XRaiseException(XD->XValue); // propagate
         break;
#ifdef DEBUG
      default:
         RTFSYSErrorExit("Corrupted exception handler chain", 1);
#endif
   }
   return XBreak;   // never get here
}

/*------------------------------------*/
XAction XAPI _XCloseBlockCanReturn(_XData * XD)
{
#ifdef DEBUG
   if (RTFSYSGetTLS(_XTlsIndex) != XD)
      RTFSYSErrorExit("Corrupted exception handler chain", 1);
#endif

   switch (XD->State)
   {
      case XHandling:   // exception is now handled
      case XCode:       // no exception
         XD->State = XFinally;
         XRESTORECONTEXT(&XD->Context, XFINALLY);
      case XFinally:    // we are done
         RTFSYSSetTLS(_XTlsIndex, XD->Next);
         if (XD->IsHandled)
            return XBreak;   // continue after XTRY block
         else
            if (XD->Next != NULL)
               _XRaiseException(XD->XValue); // propagate
            else
               return XReturn;  // return to return
         break;
#ifdef DEBUG
      default:
         RTFSYSErrorExit("Corrupted exception handler chain", 1);
#endif
   }
   return XBreak;   // never get here
}

/*-----------------------------------*/
XAction XAPI _XCloseBlockNoPropagate(_XData * XD)
{
#ifdef DEBUG
   if (RTFSYSGetTLS(_XTlsIndex) != XD)
      RTFSYSErrorExit("Corrupted exception handler chain", 1);
#endif

   switch (XD->State)
   {
      case XHandling:   // exception is now handled
      case XCode:       // no exception
         XD->State = XFinally;
         XRESTORECONTEXT(&XD->Context, XFINALLY);
      case XFinally:    // we are done
         RTFSYSSetTLS(_XTlsIndex, XD->Next);
         return (XD->IsHandled) ? XBreak : XReturn;
#ifdef DEBUG
      default:
         RTFSYSErrorExit("Corrupted exception handler chain", 1);
#endif
   }
   return XBreak;   // never get here
}


