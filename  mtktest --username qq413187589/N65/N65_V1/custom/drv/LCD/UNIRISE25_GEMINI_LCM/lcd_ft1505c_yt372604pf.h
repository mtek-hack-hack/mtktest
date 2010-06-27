#if defined(LCD_FT1505C_YT372604PF)

void LCD_reg_FT1505(kal_uint16 reg_index, kal_uint16 reg_data)
{
	LCD_CtrlWrite_FT1505(reg_index);
	LCD_DataWrite_FT1505(reg_data);
}
void LCD_BlockClear_FT1505(kal_uint16 startx,kal_uint16 starty,kal_uint16 endx,kal_uint16 endy,kal_uint16 data);
void LCD_Init_FT1505(kal_uint32 bkground, void **buf_addr)
{
	SET_LCD_CTRL_RESET_PIN;
	LCD_Delayms(5);
	CLEAR_LCD_CTRL_RESET_PIN;
	LCD_Delayms(50);
	SET_LCD_CTRL_RESET_PIN;

	LCD_Delayms(50);  //waiting for releasing reset

	LCD_reg_FT1505(0x002b, 0x0003);	//osc=477K, framerate=90Hz  //00 is 358KHz
	LCD_reg_FT1505(0x0000, 0x0001);	//00[0]=OSC_EN
	LCD_Delayms(50);        
	LCD_reg_FT1505(0x0007, 0x0000);//07[13:12]=PTDE[1:0]; 07[8]=BASEE; 07[5:3]=GON,DTE,CL; 07[1:0]=D[1:0]
	LCD_Delayms(50);                
	LCD_reg_FT1505(0x0012, 0x0000);//12[8:7]=VCMR,VCIRE;  12[4]=PON; 12[3:0]=VRH[3:0]
	LCD_Delayms(50);
	LCD_reg_FT1505(0x0060, 0xa700);//60[15]=GS; 60[13:8]=NL[5:0]; 60[5:0]=SCN[5:0]
	LCD_reg_FT1505(0x0008, 0x0405);//08[11:8]=FP[3:0]; 08[3:0]=BP[3:0]	
	
	
	/*************************** gamma setting ************************************/
	LCD_reg_FT1505(0x0030, 0x0101);
	LCD_reg_FT1505(0x0031, 0x0103);
	LCD_reg_FT1505(0x0032, 0x0505);
	LCD_reg_FT1505(0x0035, 0x0306);
	LCD_reg_FT1505(0x0036, 0x050B);
	LCD_reg_FT1505(0x0037, 0x0002);
	LCD_reg_FT1505(0x0038, 0x0200);
	LCD_reg_FT1505(0x0039, 0x0707);
	LCD_reg_FT1505(0x003c, 0x0000);
	LCD_reg_FT1505(0x003d, 0x0000);
	
	
	/***************************************************************************/
	
	LCD_reg_FT1505(0x0010, 0x02C0);//10[15:13]=GAP[2:0]; 10[12]=SAP; 10[11:0]=GAPSEL; 10[10:8]=BT[2:0]; 10[7]=APE; 10[6:4]=AP[2:0]; 10[2:0]=DSTB,SLP,STB;  		
	LCD_reg_FT1505(0x0011, 0x0247);//11[10:8]=DC1[2:0]; 11[6:4]=DC0[2:0]; 11[2:0]=VC[2:0];
	LCD_Delayms(30);   					
	LCD_reg_FT1505(0x0012, 0x0118);
	LCD_Delayms(30);        		
	LCD_reg_FT1505(0x0013, 0x1B00);//13[12:8]=VDV[4:0];	 //vcomL 00-1f, middle is 10xx
	LCD_reg_FT1505(0x0029, 0x000F);//29[5:0]=Vcm[5:0];	 //VcomH 00-37  middle is xx1f
	LCD_Delayms(30);  
	LCD_reg_FT1505(0x0001, 0x0100);//01[10]=SM; 01[8]=SS	
	LCD_reg_FT1505(0x0002, 0x0700);//02[9]=B/C; 02[8]=EOR; 02[5:0]=NM[5:0]	
	LCD_reg_FT1505(0x0003, 0x1030);//03[15:14]=TRI,DFM; 03[12]=BGR; 03[9]=HWM; 03[5:4]=I/D[1:0]; 03[3]=AM	
	
	LCD_reg_FT1505(0x0061, 0x0001);//61[2]=NDL; 61[1]=VLE; 61[0]=REV	
	
	LCD_reg_FT1505(0x0090, 0x0110);//90[9:8]=DIVI[1:0]; 90[4:0]=RTNI[4:0]		
	LCD_reg_FT1505(0x0092, 0x0000);//92[10:8]=NOI[2:0]		
	LCD_reg_FT1505(0x0098, 0x0202);
	LCD_reg_FT1505(0x0080, 0x0000);//80[8:0]=PTDP0[8:0]	
	LCD_reg_FT1505(0x0081, 0x0000);//81[8:0]=PTSA0[8:0]	
	LCD_reg_FT1505(0x0082, 0x013f);//82[8:0]=PTEA0[8:0]	
	LCD_reg_FT1505(0x0083, 0x0000);//83[8:0]=PTDP1[8:0]	
	LCD_reg_FT1505(0x0084, 0x0000);//84[8:0]=PTSA1[8:0]	
	LCD_reg_FT1505(0x0085, 0x013f);//85[8:0]=PTEA1[8:0]	
	
	LCD_reg_FT1505(0x0050, 0x0000);//50[7:0]=HSA[7:0]	
	LCD_reg_FT1505(0x0051, 0x00ef);//51[7:0]=HEA[7:0]	
	LCD_reg_FT1505(0x0052, 0x0000);//52[8:0]=VSA[8:0]	
	LCD_reg_FT1505(0x0053, 0x013f);//53[8:0]=VEA[8:0]	
	//display on
	LCD_reg_FT1505(0x0010, 0x12F0);
	LCD_Delayms(20);
	LCD_reg_FT1505(0x0007, 0x0133);//07[13:12]=PTDE[1:0]; 07[8]=BASEE; 07[5:3]=GON,DTE,CL; 07[1:0]=D[1:0]

	LCD_CtrlWrite_FT1505(0x22);
	LCD_BlockClear_FT1505(0, 0, LCD_WIDTH, LCD_HEIGHT, 0x0000);
}

void LCD_PWRON_FT1505(kal_bool on)
{
}

void LCD_SetContrast_FT1505(kal_uint8 level)
{
}

void LCD_ON_FT1505(kal_bool on)
{
}

void LCD_BlockClear_FT1505(kal_uint16 startx,kal_uint16 starty,kal_uint16 endx,kal_uint16 endy,kal_uint16 data) 
{
	kal_uint16 LCD_x;
	kal_uint16 LCD_y;

        while (LCD_IS_RUNNING){};

        lcd_assert_fail = KAL_TRUE;

        SET_LCD_CMD_PARAMETER(0,LCD_CMD,0x0050);
        SET_LCD_CMD_PARAMETER(1,LCD_DATA,(startx&0x00FF));
        SET_LCD_CMD_PARAMETER(2,LCD_CMD,0x0051);
        SET_LCD_CMD_PARAMETER(3,LCD_DATA,(endx&0x00FF));
        SET_LCD_CMD_PARAMETER(4,LCD_CMD,0x0052);
        SET_LCD_CMD_PARAMETER(5,LCD_DATA,(starty&0x01FF));
        SET_LCD_CMD_PARAMETER(6,LCD_CMD,0x0053);
        SET_LCD_CMD_PARAMETER(7,LCD_DATA,(endy&0x01FF));
        SET_LCD_CMD_PARAMETER(8,LCD_CMD,0x0020);
        SET_LCD_CMD_PARAMETER(9,LCD_DATA,(startx&0x00FF));

        SET_LCD_CMD_PARAMETER(10,LCD_CMD,0x0021);
        SET_LCD_CMD_PARAMETER(11,LCD_DATA,(starty&0x01FF));
        SET_LCD_CMD_PARAMETER(12,LCD_CMD,0x0022);

        ENABLE_LCD_TRANSFER_COMPLETE_INT;
        ENABLE_LCD_ROI_CTRL_CMD_FIRST;
        SET_LCD_ROI_CTRL_NUMBER_OF_CMD(13);
        START_LCD_TRANSFER;

	   for(LCD_y=starty;LCD_y<=endy;LCD_y++)
		{
		for(LCD_x=startx;LCD_x<=endx;LCD_x++)
		   {
		   	LCD_DataWrite_FT1505(data); 
		   }
		} 

        lcd_assert_fail = KAL_FALSE;
}

void LCD_BlockWrite_FT1505(kal_uint16 startx,kal_uint16 starty,kal_uint16 endx,kal_uint16 endy)
{	
        while (LCD_IS_RUNNING){};

        lcd_assert_fail = KAL_TRUE;
        SET_LCD_CMD_PARAMETER(0,LCD_CMD,0x0050);
        SET_LCD_CMD_PARAMETER(1,LCD_DATA,(startx&0x00FF));
        SET_LCD_CMD_PARAMETER(2,LCD_CMD,0x0051);
        SET_LCD_CMD_PARAMETER(3,LCD_DATA,(endx&0x00FF));
        SET_LCD_CMD_PARAMETER(4,LCD_CMD,0x0052);
        SET_LCD_CMD_PARAMETER(5,LCD_DATA,(starty&0x01FF));
        SET_LCD_CMD_PARAMETER(6,LCD_CMD,0x0053);
        SET_LCD_CMD_PARAMETER(7,LCD_DATA,(endy&0x01FF));
        SET_LCD_CMD_PARAMETER(8,LCD_CMD,0x0020);
        SET_LCD_CMD_PARAMETER(9,LCD_DATA,(startx&0x00FF));

        SET_LCD_CMD_PARAMETER(10,LCD_CMD,0x0021);
        SET_LCD_CMD_PARAMETER(11,LCD_DATA,(starty&0x01FF));
        SET_LCD_CMD_PARAMETER(12,LCD_CMD,0x0022);

        ENABLE_LCD_TRANSFER_COMPLETE_INT;
        ENABLE_LCD_ROI_CTRL_CMD_FIRST;
        SET_LCD_ROI_CTRL_NUMBER_OF_CMD(13);
        START_LCD_TRANSFER;

        lcd_assert_fail = KAL_FALSE;
}


void LCD_Size_FT1505(kal_uint16 *out_LCD_width,kal_uint16 *out_LCD_height)
{
   	*out_LCD_width = LCD_WIDTH;
   	*out_LCD_height = LCD_HEIGHT;
}

void LCD_EnterSleep_FT1505(void)
{
//*************Display Off sequence ****************// 
	LCD_reg_FT1505(0x0007, 0x0101); 
	LCD_Delayms(20); 
 	LCD_reg_FT1505(0x0012, 0x0118); 
	LCD_Delayms(20); 
	LCD_reg_FT1505(0x0007, 0x0100); 
	LCD_Delayms(20); 
	//*************Power Off sequence ******************// 
 	LCD_reg_FT1505(0x0010, 0x1180); 
 	LCD_reg_FT1505(0x0011, 0x0247); 
	LCD_reg_FT1505(0x0012, 0x1108); 
 	LCD_Delayms(20); 
 	LCD_reg_FT1505(0x0010, 0x1100); 
//*************************************************// 
 	LCD_reg_FT1505(0x0010, 0x1102); 
}

void LCD_ExitSleep_FT1505(void)
{     
 	LCD_reg_FT1505(0x0010, 0x12f0); 
//*************Display On sequence ****************// 
 	LCD_reg_FT1505(0x0007, 0x0101); 
 	LCD_Delayms(20);  
	LCD_reg_FT1505(0x0007, 0x0133); 
	LCD_Delayms(20);  
 	LCD_reg_FT1505(0x0012, 0x0118); 
 	LCD_Delayms(20);  
}

void LCD_Partial_On_FT1505(kal_uint16 start_page,kal_uint16 end_page)
{	
}

void LCD_Partial_Off_FT1505(void)
{
}

kal_uint8 LCD_Partial_line_FT1505(void)
{
	return 1;		/* partial display in 1 line alignment */
}

kal_uint8 LCD_GetParm_FT1505(lcd_func_type type)
{
	switch(type)
	{
		case lcd_Bais_func:
			return 1;
		case lcd_Contrast_func:
			return 1;
		case lcd_LineRate_func:
			return 4;
		case lcd_Temperature_Compensation_func:
			return 4;
		default:
			ASSERT(0);
			return 100;
	}
}


void LCD_SetBias_FT1505(kal_uint8 *bias)
{	
}

void LCD_Contrast_FT1505(kal_uint8 *contrast)
{
}

void LCD_LineRate_FT1505(kal_uint8 *linerate)
{
}

void LCD_Temp_Compensate_FT1505(kal_uint8 *compensate)
{
}

LCD_Funcs LCD_func_FT1505 = {
	LCD_Init_FT1505,
	LCD_PWRON_FT1505,
	LCD_SetContrast_FT1505,
	LCD_ON_FT1505,
	LCD_BlockWrite_FT1505, //8347 其他的都只要关注LCD_Init_FT1505
	LCD_Size_FT1505,
	LCD_EnterSleep_FT1505,
	LCD_ExitSleep_FT1505,
	LCD_Partial_On_FT1505,
	LCD_Partial_Off_FT1505,
	LCD_Partial_line_FT1505,
	/*Engineering mode*/
	LCD_GetParm_FT1505,
	LCD_SetBias_FT1505,
	LCD_Contrast_FT1505,
	LCD_LineRate_FT1505,
	LCD_Temp_Compensate_FT1505
};

#endif // end of _LCD_1505C
