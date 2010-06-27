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
/*
 * Copyright (C) Teleca Mobile Technologies AB, 2002-2004.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Teleca Mobile Technologies AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Teleca Mobile Technologies AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */

#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_def.h"    /* MSF: Global definitions */ 
#include "msf_core.h"   /* MSF: System core call */ 
#include "msf_dcvt.h"   /* MSF: Type conversion routines */ 
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_log.h"    /* MSF: Signal logging */ 
#include "sma_if.h"     /* SMA: Interface functions for SMA */
#include "sasig.h"

/**********************************************************************
 * API invoked from other modules
 **********************************************************************/

/*!
 * \brief Starts SMA if not previously started.
 * 
 *****************************************************************************/
void SMAif_startInterface(void)
{
    MSF_SIGNAL_REG_FUNCTIONS (MSF_MODID_SMA, sma_convert, sma_destruct);
} /* SMAif_startInterface */

/*!
 * \brief Play a SMIL in a MMS message
 * 
 * \param sender Module ID of the calling module.
 * \param msgId The message ID of an MM containing a SMIL
 * \param fileType The type of the message to handle: 
 *                 MMS_SUFFIX_SEND_REQ or MMS_SUFFIX_MSG.
 * \return The result of the operation.
 *****************************************************************************/
SmaResult SMAif_playSmil(MSF_UINT8 sender, MSF_UINT32 msgId, 
    MSF_UINT32 fileType)
{
    msf_dcvt_t      cvt;
    void           *sig;
    void           *sigData;
    MSF_UINT16      length;
    SmaResult       result = SMA_RESULT_OK;

    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE_SIZE, NULL, 0, 0);
    if (!msf_dcvt_uint32(&cvt, &msgId))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
        SMA_IF_ED4BB40A22513E9AF9899CB1B9359F0B, "%s(%d) SMAif_playSmil: Module=%d, MsgId=%d\n", __FILE__, __LINE__,
        sender, msgId));
        return SMA_RESULT_ERROR;
    } /* if */ 
    
    if (!msf_dcvt_uint32(&cvt, &fileType))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
        SMA_IF_C5A6BDC482759169FED3CA04D1024EFB, "%s(%d) SMAif_playSmil: Module=%d, fileType=%d\n", __FILE__, __LINE__,
        sender, fileType));
        return SMA_RESULT_ERROR;
    } /* if */ 
    length = (MSF_UINT16)cvt.pos;

    sig = MSF_SIGNAL_CREATE (SMA_SIG_PLAY_SMIL_REQ, sender, MSF_MODID_SMA, length);
    sigData = MSF_SIGNAL_GET_USER_DATA (sig, &length);
    msf_dcvt_init (&cvt, MSF_DCVT_ENCODE, sigData, length, sender);
    if (msf_dcvt_uint32(&cvt, &msgId) && msf_dcvt_uint32(&cvt, &fileType))
    {
        MSF_SIGNAL_SEND (sig);
        result = SMA_RESULT_OK;
    } 
    else
    {
        /* error converting data */
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
        SMA_IF_ED4BB40A22513E9AF9899CB1B9359F0B, "%s(%d) SMAif_playSmil: Module=%d, MsgId=%d\n", __FILE__, __LINE__,
        sender, msgId));
        result = SMA_RESULT_ERROR;
    }/* if */
    return result;
 
} /* SMAif_playSmil */

/*!
 * \brief Convert signals owned by the SMA module.
 *        Conversion is from signal buffer to signal structs.
 * 
 * \param module Module id of the module using the convert function
 * \param signal Signal to convert
 * \param buffer Buffer to convert
 * \return <whatever is returned>
 *****************************************************************************/
void *sma_convert (MSF_UINT8 module, MSF_UINT16 signal, void* buffer)
{
    msf_dcvt_t  cvt_obj;
    void       *user_data;
    MSF_UINT16  length;
    
    if ( buffer == NULL)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
        SMA_IF_B08E79896ABE6651D4B35098C3D9EAE9, "%s(%d) sma_convert: Invalid parameter\n", __FILE__, __LINE__));
        return NULL;
    } /* if */
        
    
    user_data = MSF_SIGNAL_GET_USER_DATA (buffer, &length);
    if ((user_data == NULL) || (length == 0))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
        SMA_IF_8F32FDA9D5CC2566B0E04B72A6A40B1F, "%s(%d) sma_convert: No data received.", __FILE__, __LINE__));
        return NULL;
    } /* if */
        
    msf_dcvt_init (&cvt_obj, MSF_DCVT_DECODE, user_data, length, module);
    
    switch (signal)
    {
    case SMA_SIG_PLAY_SMIL_REQ:
        {
            SmaPlaySmilReq *data = MSF_MEM_ALLOCTYPE (module, SmaPlaySmilReq);
			if (data == NULL)
            {
                /* error allocating memoryt */
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
                SMA_IF_19BBAB47E29ACEA97F0BCA2452463947, "%s(%d) sma_convert: Unable to allocate memory.", __FILE__, __LINE__));
            }
            else 
			{	
				memset(data, 0x00, sizeof(SmaPlaySmilReq));
			
				if (!sma_cvt_SmaPlaySmilReq(&cvt_obj, data))
				{
					/* error converting data */
					MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
					SMA_IF_1FEC7F7F53C9DF60512158811BBB0BCE, "%s(%d) sma_convert: Unable convert data.", __FILE__, __LINE__));
					MSF_MEM_FREE( module, data);
					data = NULL;
				} /* if */
			} /* if */
            return data;
        }
    case SMA_SIG_PLAY_SMIL_RSP:
        {
            SmaPlaySmilRsp *data = MSF_MEM_ALLOCTYPE (module, SmaPlaySmilRsp);
                       
			if ( data == NULL)
            {
                /* error allocating memoryt */
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
                SMA_IF_19BBAB47E29ACEA97F0BCA2452463947, "%s(%d) sma_convert: Unable to allocate memory.", __FILE__, __LINE__));
            }
			else
			{
				memset(data, 0x00, sizeof(SmaPlaySmilRsp));

				if (!sma_cvt_SmaPlaySmilRsp(&cvt_obj, data))
				{
					MSF_MEM_FREE( module, data);
					data = NULL;
				} /* if */
			}
            return data;
        }
    default:
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
                SMA_IF_DA27DCD4D1116258EB097286DBA73295, "%s(%d) sma_convert: Received unknown signal.", __FILE__, __LINE__));
            return NULL;
        }
    } /* switch */
} /* sma_convert */

/*!
 * \brief Deallocate signal buffer
 * 
 * \param module The calling module identity
 * \param signal Signal identity
 * \param p The signal buffer
 *****************************************************************************/
void sma_destruct (MSF_UINT8 module, MSF_UINT16 signal, void* p)
{
    msf_dcvt_t cvt_obj;

    if (p == NULL)
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
        SMA_IF_44DC61CC8F24746382F8FB2FFDAE6195, "%s(%d) sma_destruct: no signal data \n", __FILE__, __LINE__));
        return;
    } /* if */
    
    msf_dcvt_init (&cvt_obj, MSF_DCVT_FREE, NULL, 0, module);
    switch (signal)
    {
    case SMA_SIG_PLAY_SMIL_REQ:
        {
            if ( !sma_cvt_SmaPlaySmilReq( &cvt_obj, p))
            {
                /* error converting data */
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
                SMA_IF_7C7EE78A4C10F792ECD3D71654183253, "%s(%d) sma_convert: Unable convert.", __FILE__, __LINE__));
            } /* if */
            break;
        }
    case SMA_SIG_PLAY_SMIL_RSP:
        {
            if (!sma_cvt_SmaPlaySmilRsp( &cvt_obj, p))
            {
                MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
                SMA_IF_7C7EE78A4C10F792ECD3D71654183253, "%s(%d) sma_convert: Unable convert.", __FILE__, __LINE__));
            } /* if */
            break;
        }
    default:
        {
            MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_MEDIUM, MSF_MODID_SMA,
                SMA_IF_DA27DCD4D1116258EB097286DBA73295, "%s(%d) sma_convert: Received unknown signal.", __FILE__, __LINE__));
            return;
        }
    } /* switch */
  MSF_MEM_FREE (module, p);
} /* sma_destruct */

/*
 * Converts a parameters into a signal buffer for SmaPlaySmilReq
 *
 * Please note: Doxygen dokumentation, see file description in header file.
 *****************************************************************************/
int sma_cvt_SmaPlaySmilReq(msf_dcvt_t *obj, SmaPlaySmilReq *data)
{
    MSF_UINT32 msgId;
    MSF_UINT32 fileType;

    if (NULL == data)
    {
        return FALSE;
    }
    msgId = (MSF_UINT32)data->msgId; 
    fileType = (MSF_UINT32)data->fileType;
    if (!msf_dcvt_uint32(obj, &msgId) || !msf_dcvt_uint32(obj, &fileType))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_SMA, 
            SMA_IF_7C6C5CB5C722371433C7222564DCC4B1, "%s(%d): Conversion failed.\n", __FILE__, __LINE__));
        return FALSE;
    } /* if */

#ifdef WAP_SUPPORT
    data->msgId = msgId;
#else
    data->msgId = (SmaResult)msgId;
#endif /* WAP_SUPPORT */
    data->fileType = fileType;
    return TRUE; 
} /* sma_cvt_SmaPlaySmilReq */

/*
 * Converts a parameters into a signal buffer for SmaPlaySmilRsp
 *
 * Please note: Doxygen dokumentation, see file description in header file.
 *****************************************************************************/
int sma_cvt_SmaPlaySmilRsp(msf_dcvt_t *obj, SmaPlaySmilRsp *data)
{
    MSF_UINT32 result;
    
    if (NULL == data)
    {
        return FALSE;
    }
    result = (MSF_UINT32)data->result; 
    
    if (!msf_dcvt_uint32(obj, &result))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_SMA, 
            SMA_IF_7C6C5CB5C722371433C7222564DCC4B1, "%s(%d): Conversion failed.\n", __FILE__, __LINE__));
        return FALSE;
    } /* if */
    
    data->result = (SmaResult)result;
    return TRUE; 
} /* sma_cvt_SmaPlaySmilRsp */

/*
 * Converts a parameters into a signal buffer for message ID
 *
 * Please note: Doxygen dokumentation, see file description in header file.
 *****************************************************************************/
int sma_cvt_SmaMsgId(msf_dcvt_t *obj, MSF_UINT32 *data)
{
    MSF_UINT32 msgId;
    
    if (NULL == data)
    {
        return FALSE;
    }
    msgId = *data; 
    
    if (!msf_dcvt_uint32(obj, &msgId))
    {
        MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_SMA, SMA_IF_7C6C5CB5C722371433C7222564DCC4B1, "%s(%d): Conversion failed.\n", __FILE__, __LINE__));
        return FALSE;
    }
    
    *data = msgId;
    return TRUE; 
} /* sma_cvt_SmaMsgId */

/*
 * Exported function call to check if certain attachment exists by specifying its filename
 *
 * \param filename filename of attachment
 *****************************************************************************/
char *SMAlib_getAttachment(char *filename)
{
    extern char *smaGetAttachment(char *filename);

    MSF_LOG_MSG_ARGS(( MSF_LOG_DETAIL_LOW, MSF_MODID_SMA, SMA_IF_3EABBB648D9C9B67476FF2B75B76EF1A, "%s(%d): SMAlib_getAttachment(%s)\n", __FILE__, __LINE__, filename));
    return (char *)smaGetAttachment(filename);
}

