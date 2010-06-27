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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * che_hw.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Cipher/hash engine hw register definitions.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *    Rev 1.1   Jun 06 2005 19:29:20   mtk00288
 * Revise HW register.
 * Resolution for 11205: [Video/Drv][Add feature]Add MT6228 option
 *
 *    Rev 1.0   Jun 06 2005 12:57:20   BM
 * Initial revision.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef CHE_HW_H
#define CHE_HW_H


#ifndef __HW_CHE__
#define che_slowdown()
#define che_recover()
#else
void che_slowdown(void);
void che_recover(void);
#endif

#define CHE_BASE  0x80170000

#define  CHE_PDN_SET     (0x80000310)
#define  CHE_PDN_CLR     (0x80000320)
#define  CHE_PDN_BIT     0x10
#define  CHE_START       (CHE_BASE+0x0)
#define  CHE_CON         (CHE_BASE+0x4)
#define  CHE_IN0         (CHE_BASE+0x8)
#define  CHE_IN1         (CHE_BASE+0xc)
#define  CHE_IN2         (CHE_BASE+0x10)
#define  CHE_IN3         (CHE_BASE+0x14)
#define  CHE_SDRAT       (CHE_BASE+0x18)
#define  CHE_PCNT        (CHE_BASE+0x1c)     /*RO*/
#define  CHE_STAT        (CHE_BASE+0x20)     /*RO*/
#define  CHE_CDES        (CHE_BASE+0x24)     /*RO*/
#define  CHE_INTSTA      (CHE_BASE+0x28)     /*RC*/
#define  CHE_INTEN       (CHE_BASE+0x2c)     /*RW*/
#define  CHE_BCON        (CHE_BASE+0xc0)
#define  CHE_BSRC        (CHE_BASE+0xc4)
#define  CHE_BSEED       (CHE_BASE+0xc8)
#define  CHE_BENC        (CHE_BASE+0xcc)
#define  CHE_BDEC        (CHE_BASE+0xd0)

/*CHE_START*/
#define  CHE_START_DONE       0x0000
#define  CHE_START_STUD       0x0001
#define  CHE_START_LAST       0x0002
#define  CHE_START_WSTAT      0x0004
#define  CHE_START_RSTAT      0x0008
#define  CHE_START_CLEAR      0x0010
#define  CHE_START_UPDES      0x0020
#define  CHE_START_WKEY       0x0040
#define  CHE_START_RKEY       0x0080
#define  CHE_START_UPIV01     0x0100
#define  CHE_START_UPIV23     0x0200
#define  CHE_START_UPK01      0x0400
#define  CHE_START_UPK23      0x0800
#define  CHE_START_UPK45      0x1000
#define  CHE_START_UPK67      0x2000

/*CHE_CON*/
#define  CHE_CON_ATYPE_MASK         0x0007
#define  CHE_CON_ATYPE_MD5          0x0
#define  CHE_CON_ATYPE_SHA1         0x1
#define  CHE_CON_ATYPE_DES          0x2
#define  CHE_CON_ATYPE_3DES         0x3
#define  CHE_CON_ATYPE_AES_128      0x4
#define  CHE_CON_ATYPE_AES_192      0x5
#define  CHE_CON_ATYPE_AES_256      0x6
#define  CHE_CON_DECIPHER           0x0000
#define  CHE_CON_CIPHER             0x0008
#define  CHE_CON_SMODE_ECB          0x0000
#define  CHE_CON_SMODE_CBC          0x0010
#define  CHE_CON_DKEY1_64BIT        0x0000
#define  CHE_CON_DKEY1_56BIT        0x0020
#define  CHE_CON_DKEY2_64BIT        0x0000
#define  CHE_CON_DKEY2_56BIT        0x0040
#define  CHE_CON_DKEY3_64BIT        0x0000
#define  CHE_CON_DKEY3_56BIT        0x0080

/*CHE_IN0*/
#define  CHE_IN0_MASK         0xffffffff

/*CHE_IN1*/
#define  CHE_IN1_MASK         0xffffffff

/*CHE_IN2*/
#define  CHE_IN2_MASK         0xffffffff

/*CHE_IN3*/
#define  CHE_IN3_MASK         0xffffffff

/*CHE_SDRAT*/
#define  CHE_SDRAT_MASK       0x00ff      /*RW*/

/*CHE_PCNT*/
#define  CHE_PCNT_MASK        0x001f

/*CHE_STAT*/
#define  CHE_STAT_MASK        0x0007      /*RO*/
#define  CHE_STAT_OK          0x0000      /*RO*/
#define  CHE_STAT_CTRL_ERR    0x0001      /*RO*/
#define  CHE_STAT_ZEROLEN     0x0002      /*RO*/
#define  CHE_STAT_RESUME      0x0003      /*RO*/
#define  CHE_STAT_BUSY        0x0004      /*RO*/

/*CHE_CDES*/
#define  CHE_CDES_MASK        0xffffffff

/*CHE_INTSTA*/
#define  CHE_INTSTA_OK        0x1
#define  CHE_INTSTA_FAIL      0x2
#define  CHE_INTSTA_RESUME    0x3   //??

/*CHE_INTEN*/
#define  CHE_INTEN_OK         0x1
#define  CHE_INTEN_FAIL       0x2

#define CHE_REGSET_START(_data)  \
{\
   DRV_WriteReg32(CHE_START, (_data));\
   che_hw_setting[CHE_HW_SETTING_START] = (_data);\
}

#define CHE_REGSET_INTEN(_data)  \
{\
   DRV_WriteReg32(CHE_INTEN, (_data));\
   che_hw_setting[CHE_HW_SETTING_INTEN] = (_data);\
}

#define CHE_REGSET_CON(_data)  \
{\
   DRV_WriteReg32(CHE_CON, (_data));\
   che_hw_setting[CHE_HW_SETTING_CON] = (_data);\
}

#define CHE_REGSET_KEY0(_data)  \
{\
   DRV_WriteReg32(CHE_IN0, (_data));\
   che_hw_setting[CHE_HW_SETTING_KEY0] = (_data);\
}

#define CHE_REGSET_KEY1(_data)  \
{\
   DRV_WriteReg32(CHE_IN1, (_data));\
   che_hw_setting[CHE_HW_SETTING_KEY1] = (_data);\
}

#define CHE_REGSET_KEY2(_data)  \
{\
   DRV_WriteReg32(CHE_IN2, (_data));\
   che_hw_setting[CHE_HW_SETTING_KEY2] = (_data);\
}

#define CHE_REGSET_KEY3(_data)  \
{\
   DRV_WriteReg32(CHE_IN3, (_data));\
   che_hw_setting[CHE_HW_SETTING_KEY3] = (_data);\
}

#define CHE_REGSET_KEY4(_data)  \
{\
   DRV_WriteReg32(CHE_IN0, (_data));\
   che_hw_setting[CHE_HW_SETTING_KEY4] = (_data);\
}

#define CHE_REGSET_KEY5(_data)  \
{\
   DRV_WriteReg32(CHE_IN1, (_data));\
   che_hw_setting[CHE_HW_SETTING_KEY5] = (_data);\
}

#define CHE_REGSET_KEY6(_data)  \
{\
   DRV_WriteReg32(CHE_IN2, (_data));\
   che_hw_setting[CHE_HW_SETTING_KEY6] = (_data);\
}

#define CHE_REGSET_KEY7(_data)  \
{\
   DRV_WriteReg32(CHE_IN3, (_data));\
   che_hw_setting[CHE_HW_SETTING_KEY7] = (_data);\
}

#define CHE_REGSET_CKEY(_data)  \
{\
   DRV_WriteReg32(CHE_IN3, (_data));\
   che_hw_setting[CHE_HW_SETTING_CKEY] = (_data);\
}

#define CHE_REGSET_IV0(_data)  \
{\
   DRV_WriteReg32(CHE_IN0, (_data));\
   che_hw_setting[CHE_HW_SETTING_IV0] = (_data);\
}

#define CHE_REGSET_IV1(_data)  \
{\
   DRV_WriteReg32(CHE_IN1, (_data));\
   che_hw_setting[CHE_HW_SETTING_IV1] = (_data);\
}

#define CHE_REGSET_IV2(_data)  \
{\
   DRV_WriteReg32(CHE_IN2, (_data));\
   che_hw_setting[CHE_HW_SETTING_IV2] = (_data);\
}

#define CHE_REGSET_IV3(_data)  \
{\
   DRV_WriteReg32(CHE_IN3, (_data));\
   che_hw_setting[CHE_HW_SETTING_IV3] = (_data);\
}

#define CHE_REGSET_SRC(_data)  \
{\
   DRV_WriteReg32(CHE_IN0, _data);\
   che_hw_setting[CHE_HW_SETTING_SRC] = (_data);\
}

#define CHE_REGSET_DST(_data)  \
{\
   DRV_WriteReg32(CHE_IN1, _data);\
   che_hw_setting[CHE_HW_SETTING_DST] = (_data);\
}

#define CHE_REGSET_LEN(_data)  \
{\
   DRV_WriteReg32(CHE_IN2, _data);\
   che_hw_setting[CHE_HW_SETTING_LEN] = (_data);\
}

#define CHE_REGSET_SADDR(_data)  \
{\
   DRV_WriteReg32(CHE_IN3, _data);\
   che_hw_setting[CHE_HW_SETTING_SADDR] = (_data);\
}

#define CHE_WAIT_STAT_OK()  \
{\
   kal_uint32 status;\
   while(DRV_Reg32(CHE_STAT) != CHE_STAT_OK);\
   status = DRV_Reg32(CHE_INTSTA);\
}

#define CHE_WAIT_STAT_RESUME()  \
{\
   kal_uint32 status;\
   while(DRV_Reg32(CHE_STAT) != CHE_STAT_RESUME);\
   status = DRV_Reg32(CHE_INTSTA);\
}



#define CHE_MAX_CHANNEL       32
#define CHE_HW_STATUS_SIZE    120
//#define CHE_INTR_ENABLE

/*AES 10000, DES 20000*/
#define ISR_ENABLE_DATA_LENGTH      15000

typedef enum {
   CHE_HW_SETTING_START = 0,
   CHE_HW_SETTING_CON,  /*1*/
   CHE_HW_SETTING_KEY0, /*2*/
   CHE_HW_SETTING_KEY1, /*3*/
   CHE_HW_SETTING_KEY2, /*4*/
   CHE_HW_SETTING_KEY3, /*5*/
   CHE_HW_SETTING_KEY4, /*6*/
   CHE_HW_SETTING_KEY5, /*7*/
   CHE_HW_SETTING_KEY6, /*8*/
   CHE_HW_SETTING_KEY7, /*9*/
   CHE_HW_SETTING_CKEY, /*10*/
   CHE_HW_SETTING_IV0,  /*11*/
   CHE_HW_SETTING_IV1,  /*12*/
   CHE_HW_SETTING_IV2,  /*13*/
   CHE_HW_SETTING_IV3,  /*14*/
   CHE_HW_SETTING_SRC,  /*15*/
   CHE_HW_SETTING_DST,  /*16*/
   CHE_HW_SETTING_LEN,  /*17*/
   CHE_HW_SETTING_SADDR,   /*18*/   //state addr
   CHE_HW_SETTING_INTEN,   /*19*/
   CHE_HW_SETTING_DUMMY1,  /*20*/
   CHE_HW_SETTING_DUMMY2,  /*21*/
   CHE_HW_SETTING_DUMMY3,  /*22*/
   CHE_HW_SETTING_DUMMY4,  /*23*/
   CHE_HW_SETTING_DUMMY5,  /*24*/
   CHE_HW_SETTING_DUMMY6,  /*25*/
   CHE_HW_SETTING_DUMMY7,  /*26*/
   CHE_HW_SETTING_DUMMY8,  /*27*/
   MAX_CHE_HW_SETTING      /*28*/
} CHE_HW_SETTING;

typedef struct {
   kal_uint32           che_glb_handle;            /*CHE global handle*/
   kal_uint8            che_lastest_finish_handle; /*Avoid race condition*/
   kal_bool             che_machie_running;  /*Avoid race condition*/
   kal_uint32           che_dbg_line;     /*Just for debug*/
   kal_uint8            che_sm_handle;    /*CHE SM control*/
   kal_hisrid           hisr;             /*CHE HISR*/
   kal_eventgrpid       event;            /*CHE EVENT*/
} CHE_CB_DATA_STRUCT;




#endif
