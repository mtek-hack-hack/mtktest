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
#ifndef _mma_intsig_h
#define _mma_intsig_h

/**********************************************************************
 * Macro definition
 **********************************************************************/
#define MMA_SIGNAL_SENDTO(sig) \
      mma_signal_send_to ((sig), 0, 0, 0, NULL)
    
#define MMA_SIGNAL_SENDTO_I(sig, i) \
      mma_signal_send_to ((sig), i, 0, 0, NULL)
    
#define MMA_SIGNAL_SENDTO_U(sig, u) \
      mma_signal_send_to ((sig), 0, (u), 0, NULL)
    
#define MMA_SIGNAL_SENDTO_IU(sig, i, u) \
      mma_signal_send_to ((sig), (i), (u), 0, NULL)
    
#define MMA_SIGNAL_SENDTO_UU(sig, u1, u2) \
      mma_signal_send_to ((sig), 0, (u1), (u2), NULL)
    
#define MMA_SIGNAL_SENDTO_IUU(sig, i, u1, u2) \
      mma_signal_send_to ((sig), (i), (u1), (u2), NULL)
    
#define MMA_SIGNAL_SENDTO_P(sig, p) \
      mma_signal_send_to ((sig), 0, 0, 0, (p))
    
#define MMA_SIGNAL_SENDTO_IP(sig, i, p) \
      mma_signal_send_to ((sig), (i), 0, 0, (p))
    
#define MMA_SIGNAL_SENDTO_UP(sig, u, p) \
      mma_signal_send_to ((sig), 0, (u), 0, (p))
    
#define MMA_SIGNAL_SENDTO_IUP(sig, i, u, p) \
      mma_signal_send_to ((sig), (i), (u), 0, (p))
    
#define MMA_SIGNAL_SENDTO_UUP(sig, u1, u2, p) \
      mma_signal_send_to ((sig), 0, (u1), (u2), (p))
    
#define MMA_SIGNAL_SENDTO_IUUP(sig, i, u1, u2, p) \
      mma_signal_send_to ((sig), (i), (u1), (u2), (p))

/**********************************************************************
 * Constant definition
 **********************************************************************/
typedef enum 
{
    MMA_SIG_CREATE_CONTINUE
}MmaSignalId;


/**********************************************************************
 * Structure definition
 **********************************************************************/
typedef struct MmaSignalStruct {
    struct MmaSignalStruct *next;
//    int                    dst;      /* Not used in MMA. The destination for this signal */
    int                    type;     /* Which signal it is */
    long int               i_param;  /* Parameters: */
    unsigned long int      u_param1;
    unsigned long int      u_param2;
    void                   *p_param;
} MmaSignal;

/**********************************************************************
 * Function declarations
 **********************************************************************/
void mma_signal_init (void);
void mma_signal_process(void);
void mma_signal_terminate (void);
void mma_signal_delete(MmaSignal *sig);
MmaSignal *mma_signal_send_to(int signum, long i_param, unsigned long u_param1, unsigned long u_param2, void *p_param);
kal_bool mma_signal_queue_is_empty (void);

#endif /* _mma_intsig_h */
