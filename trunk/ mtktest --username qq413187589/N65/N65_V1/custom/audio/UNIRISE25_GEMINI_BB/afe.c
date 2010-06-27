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
 * afe.c
 *
 * Project:
 * --------
 *   MT6219
 *
 * Description:
 * ------------
 *   Audio Front End
 *
 * Author:
 * -------
 * -------
 *
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
 *******************************************************************************/
#include "kal_release.h"
#include "pmic6318_sw.h"

#define  AFE_VAC_DCON1  (volatile unsigned short*)(0x8040000CL)  /* AFE Voice Analog Circuit Control Register 1   */
#define  AFE_VAC_CON0   (volatile unsigned short*)(0x80500104L)  /* AFE Voice Analog-Circuit Control Register 0   */

/*****************************************************************************
* FUNCTION
*  AFE_Initialize
* DESCRIPTION
*   This function is to set the initial value of AFE HW.
*****************************************************************************/
void AFE_Initialize( void )
{
   /// AFE_VAC_CON0::VCALI is chip dependent, will be set in l1audio\afe2.c
   /// immediately after this function is called.
   *AFE_VAC_CON0  = 0x40;
   *AFE_VAC_DCON1 = 0x80;
}

void AFE_Delayms(kal_uint8 time)
{
	volatile unsigned long delay;
	for (delay =0;delay <time*(9600);delay++) {} // 1ms
}
/*****************************************************************************
* FUNCTION
*  AFE_SwitchExtAmplifier
* DESCRIPTION
*   This function is to turn on/off external amplifier.
*****************************************************************************/
#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It For G Sensor 
int FlagOpener =  0 ; // 0 => Normal Open ; 1 => Gsensor Open
int FlagCloser   = 0 ; // 0 => Normal Close ; 1 => Gsensor Close
#endif

#if (defined PCB_N65_V2P0)
extern const char gpio_afe_amplifier_pin;
#elif (defined PCB_N65_V1P0)
extern const char gpio_afe_l_aw8145_ctrl_pin_1;
extern const char gpio_afe_l_aw8145_ctrl_pin_2;

extern const char gpio_afe_r_aw8145_ctrl_pin_1;
extern const char gpio_afe_r_aw8145_ctrl_pin_2;
#endif

void AFE_SwitchExtAmplifier( char sw_on )
{
#ifdef __CUST_NEW__
//   #if defined(MT6318)
//   if( sw_on )
//      pmic_speaker_enable(KAL_TRUE);
//   else
//      pmic_speaker_enable(KAL_FALSE);
//   #else/*MT6305*/

#if (defined PCB_N65_V2P0)

	if( sw_on )
	{
		AFE_Delayms(50);
		GPIO_ModeSetup(gpio_afe_amplifier_pin, 0);
		GPIO_InitIO(1, gpio_afe_amplifier_pin);
		GPIO_WriteIO( 1, gpio_afe_amplifier_pin);
	}
	else
	{
		GPIO_ModeSetup(gpio_afe_amplifier_pin, 0);
		GPIO_InitIO(1, gpio_afe_amplifier_pin);
		GPIO_WriteIO( 0, gpio_afe_amplifier_pin);
	}


#elif (defined PCB_N65_V1P0)


   if( sw_on )
   {
   		AFE_Delayms(50);
	#if defined(G_SENSOR_SUPPORT)
	//Huyanwei Add It 
	FlagOpener = 0;
	#endif
	
	GPIO_ModeSetup(gpio_afe_l_aw8145_ctrl_pin_1, 0);
	GPIO_InitIO(1, gpio_afe_l_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 1, gpio_afe_l_aw8145_ctrl_pin_1);

	GPIO_ModeSetup(gpio_afe_l_aw8145_ctrl_pin_2, 0);
	GPIO_InitIO(1, gpio_afe_l_aw8145_ctrl_pin_2);
    	GPIO_WriteIO( 1, gpio_afe_l_aw8145_ctrl_pin_2);

	GPIO_ModeSetup(gpio_afe_r_aw8145_ctrl_pin_1, 0);
	GPIO_InitIO(1, gpio_afe_r_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 1, gpio_afe_r_aw8145_ctrl_pin_1);

	GPIO_ModeSetup(gpio_afe_r_aw8145_ctrl_pin_2, 0);
	GPIO_InitIO(1, gpio_afe_r_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 1, gpio_afe_r_aw8145_ctrl_pin_2);
  }
   else
   {
   	#if defined(G_SENSOR_SUPPORT)
	//Huyanwei Add It 
	FlagCloser = 0;
	#endif

	GPIO_ModeSetup(gpio_afe_l_aw8145_ctrl_pin_1, 0);
	GPIO_InitIO(1, gpio_afe_l_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 0, gpio_afe_l_aw8145_ctrl_pin_1);

	GPIO_ModeSetup(gpio_afe_l_aw8145_ctrl_pin_2, 0);
	GPIO_InitIO(1, gpio_afe_l_aw8145_ctrl_pin_2);
    	GPIO_WriteIO( 0, gpio_afe_l_aw8145_ctrl_pin_2);

	GPIO_ModeSetup(gpio_afe_r_aw8145_ctrl_pin_1, 0);
	GPIO_InitIO(1, gpio_afe_r_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 0, gpio_afe_r_aw8145_ctrl_pin_1);

	GPIO_ModeSetup(gpio_afe_r_aw8145_ctrl_pin_2, 0);
	GPIO_InitIO(1, gpio_afe_r_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 0, gpio_afe_r_aw8145_ctrl_pin_2);
   }
#endif
   
//   #endif
#else /* __CUST_NEW__ */
//   #if defined(MT6318)
//   if( sw_on )
//      pmic_speaker_enable(KAL_TRUE);
//   else
//      pmic_speaker_enable(KAL_FALSE);
//   #else/*MT6305*/
   if( sw_on )
      GPIO_WriteIO( 1, 5 );
   else
      GPIO_WriteIO( 0, 5 );
//   #endif
#endif /* __CUST_NEW__ */
}


extern void LCD_Delayms(kal_uint16 time) ;

#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It For G Sensor 
void AFE_GSensor_SwitchExtAmplifier( char sw_on )
{

#if (defined PCB_N65_V2P0)

	if( sw_on )
	{
		AFE_Delayms(50);

		GPIO_ModeSetup(gpio_afe_amplifier_pin, 0);
		GPIO_InitIO(1, gpio_afe_amplifier_pin);
		GPIO_WriteIO( 1, gpio_afe_amplifier_pin);
	}
	else
	{
		GPIO_ModeSetup(gpio_afe_amplifier_pin, 0);
		GPIO_InitIO(1, gpio_afe_amplifier_pin);
		GPIO_WriteIO( 0, gpio_afe_amplifier_pin);
	}

#elif (defined PCB_N65_V1P0)

/*
 *     8145 control description:
 *                      NCN1              NCN2                 NCNOFF                OFF
 *    Ctr1           H                     H                       L                          L
 *    Ctr2           H                     L                        H                         L
 *
 *    NOTE: If NCN2 or NCNOFF , NCN1 should be first!
 */

   if( sw_on )
   {
   	  AFE_Delayms(50);
	  FlagOpener = 1 ;

	GPIO_ModeSetup(gpio_afe_l_aw8145_ctrl_pin_1, 0);
	GPIO_InitIO(1, gpio_afe_l_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 1, gpio_afe_l_aw8145_ctrl_pin_1);

	GPIO_ModeSetup(gpio_afe_l_aw8145_ctrl_pin_2, 0);
	GPIO_InitIO(1, gpio_afe_l_aw8145_ctrl_pin_2);
    	GPIO_WriteIO( 1, gpio_afe_l_aw8145_ctrl_pin_2);

	GPIO_ModeSetup(gpio_afe_r_aw8145_ctrl_pin_1, 0);
	GPIO_InitIO(1, gpio_afe_r_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 1, gpio_afe_r_aw8145_ctrl_pin_1);

	GPIO_ModeSetup(gpio_afe_r_aw8145_ctrl_pin_2, 0);
	GPIO_InitIO(1, gpio_afe_r_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 1, gpio_afe_r_aw8145_ctrl_pin_2);

	LCD_Delayms(40);

	GPIO_ModeSetup(gpio_afe_l_aw8145_ctrl_pin_1, 0);
	GPIO_InitIO(1, gpio_afe_l_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 0, gpio_afe_l_aw8145_ctrl_pin_1);

	GPIO_ModeSetup(gpio_afe_l_aw8145_ctrl_pin_2, 0);
	GPIO_InitIO(1, gpio_afe_l_aw8145_ctrl_pin_2);
    	GPIO_WriteIO( 1, gpio_afe_l_aw8145_ctrl_pin_2);

	GPIO_ModeSetup(gpio_afe_r_aw8145_ctrl_pin_1, 0);
	GPIO_InitIO(1, gpio_afe_r_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 0, gpio_afe_r_aw8145_ctrl_pin_1);

	GPIO_ModeSetup(gpio_afe_r_aw8145_ctrl_pin_2, 0);
	GPIO_InitIO(1, gpio_afe_r_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 1, gpio_afe_r_aw8145_ctrl_pin_2);
   }
   else
   {
   	FlagCloser    = 1 ;
	GPIO_ModeSetup(gpio_afe_l_aw8145_ctrl_pin_1, 0);
	GPIO_InitIO(1, gpio_afe_l_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 0, gpio_afe_l_aw8145_ctrl_pin_1);

	GPIO_ModeSetup(gpio_afe_l_aw8145_ctrl_pin_2, 0);
	GPIO_InitIO(1, gpio_afe_l_aw8145_ctrl_pin_2);
    	GPIO_WriteIO( 0, gpio_afe_l_aw8145_ctrl_pin_2);

	GPIO_ModeSetup(gpio_afe_r_aw8145_ctrl_pin_1, 0);
	GPIO_InitIO(1, gpio_afe_r_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 0, gpio_afe_r_aw8145_ctrl_pin_1);

	GPIO_ModeSetup(gpio_afe_r_aw8145_ctrl_pin_2, 0);
	GPIO_InitIO(1, gpio_afe_r_aw8145_ctrl_pin_1);
    	GPIO_WriteIO( 0, gpio_afe_r_aw8145_ctrl_pin_2);
   }

#endif
   
}

#endif





