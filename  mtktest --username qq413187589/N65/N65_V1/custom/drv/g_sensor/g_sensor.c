#if defined(G_SENSOR_SUPPORT)
//Huyanwei Add It 
#include "FSL_MMA.h"


//typedef signed char  byte ;
typedef unsigned char  byte ;

byte CalibrantionData[6] = { 0 };
unsigned short NVRAM_GSENSOR_DATA = 0 ;

VINT8 paraX = 0 ;
VINT8 paraY=0  ;
VINT8 paraZ= 0  ;



// IIC Slave address
#define SLAVE_ADD       0x1D    //If pin IADDR0 is high-level connected or unconnected
//#define SLAVE_ADD       0x1C    //If pin IADDR0 is low-level connected

// IIC Command Set
#define XOUTL            0x00
#define XOUTH           0x01
#define YOUTL           0x02
#define YOUTH           0x03
#define ZOUTL           0x04
#define ZOUTH           0x05
#define XOUT8           0x06
#define YOUT8           0x07
#define ZOUT8           0x08
#define STATUS         0x09
#define DETSRC         0x0A
#define TOUT             0x0B
#define I2CAD           0x0D
#define USRINF         0x0E
#define WHOAMI       0x0F
#define XOFFL           0x10
#define XOFFH           0x11
#define YOFFL           0x12
#define YOFFH           0x13
#define ZOFFL        0x14
#define ZOFFH        0x15
#define MCTL          0x16
#define INTRST       0x17
#define CTL1           0x18
#define CTL2           0x19
#define LDTH          0x1A
#define PDTH          0x1B
#define PW              0x1C
#define LT               0x1D
#define TW              0x1E

#define CalibrationTimes 3


extern void StoreCibrantionData(char * DataArr,unsigned char len );

void SetClibrantionData(byte * CalibrantionData )
{
	mma745x_IICWrite(0x10, (byte)CalibrantionData[0]);
	mma745x_IICWrite(0x11, (byte)CalibrantionData[1]);

	mma745x_IICWrite(0x12, (byte)CalibrantionData[2]);
       mma745x_IICWrite(0x13, (byte)CalibrantionData[3]);

	mma745x_IICWrite(0x14, (byte)CalibrantionData[4]);
       mma745x_IICWrite(0x15, (byte)CalibrantionData[5]);	
}

void  Init_GSensor(void)
{
	mma745x_init();
#if 1	
	//mma745x_IICWrite(0x16,0x03); // 0x03 pule , 0x45 meser , 0x00 standby	
	mma745x_IICWrite(0x16,0x45); // 0x03 pule , 0x45 meser , 0x00 standby	
	
	mma745x_ReadXYZ8(&paraX, &paraY, &paraZ);
#else
	// Interrupt Mode
	mma745x_IICWrite(0x16,0x46); // 0x02. level ,0x03 pule , 0x45 meser , 0x00 standby , 2g mode 
	mma745x_IICWrite(0x18,0x58); // Z enable . xy disable,  signed 
	
	mma745x_IICWrite(0x19,0x04); // pin driver,hardware IIC OK 
	mma745x_IICWrite(0x1A,0x8A);// > 0 , < 0 .interrupt 
	
#endif	

}


int FlagGSensorSleep = 0 ;

void SendMessageToCloseThreadOne(void);
void SendMessageToOpenThreadOne(void);


void SetGSensorSleepMode(unsigned char  Mode)
{
	Mode = Mode%2 ;
	if( Mode == 0 )
	{
		//Sleep State
		mma745x_IICWrite(0x16,0x44); // 0x46 pule , 0x45 meser , 0x44 standby	
	}
	else
	{
		//Work State
		mma745x_IICWrite(0x16,0x45); // 0x46 pule , 0x45 meser , 0x44 standby	
	}
	return ;
}

void EntrySleep_GSensor(void)
{
	// SetGSensorSleepMode(0);
	FlagGSensorSleep = 1 ;	
	SendMessageToCloseThreadOne();
}

void ExitSleep_GSensor(void)
{
	//SetGSensorSleepMode(1);
	FlagGSensorSleep = 0 ;	
	SendMessageToOpenThreadOne();
}

void ClearInterrupt_GSensor(void)
{
	mma745x_IICWrite(0x17,0x03); 
	mma745x_IICWrite(0x17,0x00); 
}

extern  void Calibration_XYZ(void);
extern  void Sample_n_Times(byte n, VINT16 *pX, VINT16 *pY, VINT16 *pZ);
extern  char Data_Is_Ready(void);


void Calibration_XYZ(void)
{
	  SPARAMETERS gValue;
	  char temp, i;
	  char temp1= 0, temp2= 0 ,temp3 =  0 ;

	  temp = mma745x_IICRead(MCTL);
	  
	  mma745x_IICWrite(MCTL, 0x45);

	  for(i=0;i<CalibrationTimes;i++)
	  {
	    Sample_n_Times(8, &gValue.X, &gValue.Y, &gValue.Z);

	    gValue.X *= -2;
	    temp1 = mma745x_IICRead(XOFFH);
	    temp2 = mma745x_IICRead(XOFFL);
	    temp3 = (VINT16)(((VUINT16)(temp1<<8))+(VUINT16)(temp2));
	    gValue.X += temp3;
#if 0		
	    IIC_Write(XOFFL, (byte)(gValue.X));
	    IIC_Write(XOFFH, (byte)(gValue.X>>8));
#else
	   mma745x_IICWrite(XOFFL, (byte)(gValue.X));
	   mma745x_IICWrite(XOFFH, (byte)(gValue.X>>8));
#endif

	   if( i == (CalibrationTimes -1) )
	   {
	   	CalibrantionData[0] = (byte)(gValue.X);
		CalibrantionData[1] = (byte)(byte)(gValue.X>>8) ;		
	   }

	    gValue.Y *= -2;
	    temp1 = mma745x_IICRead(YOFFH);
	    temp2 = mma745x_IICRead(YOFFL);
	    temp3 = (VINT16)(((VUINT16)(temp1<<8))+(VUINT16)(temp2));
	    gValue.Y += temp3;
#if 0		
	    IIC_Write(YOFFL, (byte)(gValue.Y));
	    IIC_Write(YOFFH, (byte)(gValue.Y>>8));
#else
	    mma745x_IICWrite(YOFFL, (byte)(gValue.Y));
	    mma745x_IICWrite(YOFFH, (byte)(gValue.Y>>8));
#endif		

	   if( i == (CalibrationTimes -1) )
	   {
	   	CalibrantionData[2] = (byte)(gValue.Y);
		CalibrantionData[3] = (byte)(byte)(gValue.Y>>8) ;		
	   }


	    gValue.Z -= -63;  // If +,63; if - ,-63
	    gValue.Z *= -2;
	    temp1 = mma745x_IICRead(ZOFFH);
	    temp2 = mma745x_IICRead(ZOFFL);
	    temp3 = (VINT16)(((VUINT16)(temp1<<8))+(VUINT16)(temp2));
	    gValue.Z += temp3;
#if 0		
	    IIC_Write(ZOFFL, (byte)(gValue.Z));
	    IIC_Write(ZOFFH, (byte)(gValue.Z>>8));
#else
	    mma745x_IICWrite(ZOFFL, (byte)(gValue.Z));
	    mma745x_IICWrite(ZOFFH, (byte)(gValue.Z>>8)); 
#endif
	     if( i == (CalibrationTimes -1) )
	    {
	   	CalibrantionData[4] = (byte)(gValue.Z);
		CalibrantionData[5] = (byte)(byte)(gValue.Z>>8) ;		
		StoreCibrantionData((char *)CalibrantionData,6);
	    }
	  }
	  mma745x_IICWrite(MCTL, temp);
}

void Sample_n_Times(byte n, VINT16 *pX, VINT16 *pY, VINT16 *pZ)
{
    byte i;
    VINT16 TmpX, TmpY, TmpZ;
    *pX=0; *pY=0; *pZ=0;
    for (i=0;i<n;i++)
    {
      while(!Data_Is_Ready());
      mma745x_ReadXYZ10(&TmpX, &TmpY, &TmpZ);
      *pX += TmpX;   
      *pY += TmpY;   
      *pZ += TmpZ;   
    }
    *pX /= n;
    *pY /= n;
    *pZ /= n;
}


char Data_Is_Ready(void)
{
  if(mma745x_IICRead(0x09)&0x01) 
  	return 1;
  return 0;
}

void Calibrantion_GSensor(void)
{
	Calibration_XYZ();
}



#define RawDataLength 20
#define TurnDelayValue 300

VUINT8 RawDataPointer;
VINT8 Xavg8, Yavg8, Zavg8;
VINT8 Xraw[RawDataLength], Yraw[RawDataLength], Zraw[RawDataLength];
VINT8 Xsmth, Ysmth, Zsmth;
VINT8 TurnDetection_Step;
VUINT16  TurnDetection_Delay;
VINT8 Zrcrd;

VUINT8 XYZ_Turn_Filter(void)
{
  VUINT8 i;
  VINT16 temp16;
  
  if(!Data_Is_Ready()) return 0;

  if((++RawDataPointer)>=RawDataLength) RawDataPointer = 0;
  Xraw[RawDataPointer] = mma745x_IICRead(XOUT8);
  Yraw[RawDataPointer] = mma745x_IICRead(YOUT8);
  Zraw[RawDataPointer] = mma745x_IICRead(ZOUT8);

  for(i=0, temp16=0;i<RawDataLength;i++)
  {
    temp16 += Xraw[i];
  }
  Xavg8 = (signed char)(temp16/RawDataLength);
  for(i=0, temp16=0;i<RawDataLength;i++)
  {
    temp16 += Yraw[i];
  }
  Yavg8 = (signed char)(temp16/RawDataLength);
  for(i=0, temp16=0;i<RawDataLength;i++)
  {
    temp16 += Zraw[i];
  }
  Zavg8 = (signed char)(temp16/RawDataLength);
  
  if(Zsmth==Zavg8) 
  	return 1;
  else if(Zsmth>Zavg8) 
  	Zsmth--;
  else
  	Zsmth++;
  return 1;
}


VUINT8 Turn_Sense(void)
{
  if(!XYZ_Turn_Filter()) return 0;
  switch(TurnDetection_Step)
  {
    case(1):
      if(abs(Zsmth-Zrcrd)>5) 
	  	TurnDetection_Step = 2;
    break;
    case(2):
      if(((++TurnDetection_Delay)<TurnDelayValue))
      {
        if(Zrcrd>30)
        {
          if((Zrcrd-Zavg8)>=120)
          {
            TurnDetection_Step = 0;
            Zsmth = Zavg8;
            return 1;
          }
        }
        else if(Zrcrd<-30)
        {
          if((Zavg8-Zrcrd)>=120)
          {
            TurnDetection_Step = 0;
            Zsmth = Zavg8;
            return 1;
          }
        }
      }
      else
      {
        TurnDetection_Step = 0;
      }
    break;
    default:
      TurnDetection_Step = 0;
      Zrcrd = 0;
      if(Zsmth==Zavg8)
      {
        Zrcrd = Zsmth;
        TurnDetection_Step = 1;
        TurnDetection_Delay = 0;
      }
    break;
  }
  return 0;
}


char GetXValue_GSensor(void)
{
	return mma745x_IICRead(XOUT8);
}

char GetYValue_GSensor(void)
{
	return mma745x_IICRead(YOUT8);
}

char GetZValue_GSensor(void)
{
	return mma745x_IICRead(ZOUT8);
}

#if 1
// Flip 

extern void mma745x_ReadXYZ10(VINT16 *pX, VINT16 *pY, VINT16 *pZ);

VUINT8 Flip_Read_RawData(VINT16 *pX, VINT16 *pY, VINT16 *pZ)
{
  if(!Data_Is_Ready())
  	return 0;               // Check whether data is ready
  mma745x_ReadXYZ10(pX, pY, pZ);          // Read 10-bit g-values and change to 16-bit signed data
  return 1;
}



#define Flip_HighThValue 200 /*150*/
#define Flip_LowThValue  (-200) /*-150*/
#define Flip_MinAbsValue 100 /*50*/
#define Flip_DelayTime 2

typedef enum {NOFLIP, XFPOS, XFNEG, YFPOS, YFNEG, ZFPOS, ZFNEG} FlipDir;   

VINT16 Xnew16, Ynew16, Znew16;
VUINT8 FlipFindFlag = 0;
VUINT8 FlipSenseStep = 0;
VUINT8 FlipDelay = 0;
VINT16 Xfst, Xsnd, Yfst, Ysnd, Zfst, Zsnd;
FlipDir FlipReport = NOFLIP;
/*shaokai modify it start.090901*/
VUINT8 Flip_Sensitivity = 10;
/*shaokai modify it end.090901*/
VINT16 Flip_HighTh = Flip_HighThValue;
VINT16 Flip_LowTh = Flip_LowThValue;
VINT16 Flip_AbsTh = Flip_MinAbsValue;


void Flip_GetSensitivity(void)
{ 
  //Get the sensitivity for flip detection
  if((Flip_Sensitivity<=5)||(Flip_Sensitivity>=51))
  	Flip_Sensitivity = 20;
       //For better performance, flip sensitivity should be larger than 10.
  Flip_HighTh = Flip_Sensitivity*10;
  Flip_LowTh = Flip_Sensitivity*(-10);
  Flip_AbsTh = Flip_HighTh /2;
}

/* 2009.04.23 added by hongzhe.liu for g sensor debug + */
void Flip_SetSensitivity( unsigned char s )
{
	Flip_Sensitivity = s;
	Flip_GetSensitivity();
}
/* 2009.04.23 added by hongzhe.liu for g sensor debug - */
#if 0
//Old 
VUINT8 Flip_Sense(void)
{

  if(!Flip_Read_RawData(&Xnew16, &Ynew16, &Znew16))
  {

  	return 0;
  }

  
  switch(FlipSenseStep)
  {
  
    case 1:             
	//Step 1 to track axes's peak value: find the first peak
      FlipSenseStep = 2;
       //If the first value is positive and it's increasing, refresh the peak value
      if((Xfst>=0)&&(Xnew16>=Flip_HighTh)&&(Xnew16>=Xfst))
      {
        Xfst = Xnew16;
        Xsnd = Xnew16;
        FlipSenseStep = 1;
      }                         //If the first value is negative and it's decreasing, refresh the peak value
      else if((Xfst<=0)&&(Xnew16<=Flip_LowTh)&&(Xnew16<=Xfst))
      {
        Xfst = Xnew16;
        Xsnd = Xnew16;
        FlipSenseStep = 1;
      }

       //Same for other axes
      if((Yfst>=0)&&(Ynew16>=Flip_HighTh)&&(Ynew16>=Yfst))
      {
        Yfst = Ynew16;
        Ysnd = Ynew16;
        FlipSenseStep = 1;
      }
      else if((Yfst<=0)&&(Ynew16<=Flip_LowTh)&&(Ynew16<=Yfst))
      {
        Yfst = Ynew16;
        Ysnd = Ynew16;
        FlipSenseStep = 1;
      }
	  
      if((Zfst>=0)&&(Znew16>=Flip_HighTh)&&(Znew16>=Zfst))
      {
        Zfst = Znew16;
        Zsnd = Znew16;
        FlipSenseStep = 1;
      }
      else if((Zfst<=0)&&(Znew16<=Flip_LowTh)&&(Znew16<=Zfst))
      {
        Zfst = Znew16;
        Zsnd = Znew16;
        FlipSenseStep = 1;
      }

    break;                            // If the first peak values found, enter step 2
    case (2):                          // Step 2: find the second peak
      FlipSenseStep = 3;
      //If the first peak is positive, find the miminum value for second peak
      if((Xfst>=Flip_HighTh)&&(Xnew16<Xsnd))
      {
        Xsnd = Xnew16;
        FlipSenseStep = 2;
      }                            //If the first peak is negative, find the maximum value for second peak
      else if((Xfst<=Flip_LowTh)&&(Xnew16>Xsnd))
      {
        Xsnd = Xnew16;
        FlipSenseStep = 2;
      }
	  
      if((Yfst>=Flip_HighTh)&&(Ynew16<Ysnd))
      {
        Ysnd = Ynew16;
        FlipSenseStep = 2;
      }
      else if((Yfst<=Flip_LowTh)&&(Ynew16>Ysnd))
      {
        Ysnd = Ynew16;
        FlipSenseStep = 2;
      }

	
      if((Zfst>=Flip_HighTh)&&(Znew16<Zsnd))
      {
        Zsnd = Znew16;
        FlipSenseStep = 2;
      }
      else if((Zfst<=Flip_LowTh)&&(Znew16>Zsnd))
      {
        Zsnd = Znew16;
        FlipSenseStep = 2;
      }

	  
      if(FlipSenseStep==3)      //If the second peak found, enter step 3: judge flip direction and axis
      {
        FlipSenseStep = 4;
        FlipReport = XFPOS;      //Assume flip on axis X and positive direction
        FlipDelay = Flip_DelayTime;
        Xsnd = abs(Xfst - Xsnd); //The axis with maximum absolute value between the first and second peaks is the fliping axis
        Ysnd = abs(Yfst - Ysnd);
        Zsnd = abs(Zfst - Zsnd);
        if(Ysnd>=Xsnd)
        {
          FlipReport += 2;       //Select axis Y
          Xfst = Yfst;
          Xsnd = Ysnd;
        }
        if(Zsnd>=Xsnd)
        {
          FlipReport += 2;       //Select axis Z
          Xfst = Zfst;
          Xsnd = Zsnd;
        }
		
        if(Xfst<0) 
			FlipReport++; //If the first peak is negative, flip direction is negative
			
        if(Xsnd<Flip_AbsTh)
			FlipReport = NOFLIP;
		
      }
    break;
    case(4):                            	// Step 4: delay between flips
      if(!(FlipDelay--)) 
	  	FlipSenseStep = 0;	//Back to step 0 when delay finished
    break;
    default:
      FlipSenseStep = 0;                // Initialize tracking records
      Xfst = 0;
      Xsnd = 0;
      Yfst = 0;
      Ysnd = 0;
      Zfst = 0;
      Zsnd = 0;
                                        // Check if any axis value beyond threshold
      if((Xnew16>=Flip_HighTh)||(Xnew16<=Flip_LowTh)) 
	  	Xfst = Xnew16;

	//Huyanwei Modifyit .YZ
      if((Ynew16>=Flip_HighTh)||(Ynew16<=Flip_LowTh)) 
	  	Yfst = Ynew16;
      if((Znew16>=Flip_HighTh)||(Znew16<=Flip_LowTh)) 
	  	Zfst = Znew16;


      if( Xfst ||Yfst ||Zfst )
	{             // If any axis g-value beyond threshold, start tracking
	        FlipSenseStep = 1;
       }
    break;
  }
  return 1;
}
#else
VUINT8 Flip_Sense(void)
{

 //hongzhe.liu  if(!Flip_Read_RawData(&Xnew16, &Ynew16, &Znew16))
 if(!Flip_Read_RawData(&Ynew16, &Xnew16, &Znew16))
 {

  	return 0;
  }

  
  switch(FlipSenseStep)
  {
  
    case 1:             
		//Step 1 to track axes's peak value: find the first peak
	      FlipSenseStep = 2;
		
	       //If the first value is positive and it's increasing, refresh the peak value
	      if((Xfst>=0)&&(Xnew16>=Flip_HighTh)&&(Xnew16>=Xfst))
	      {
		        Xfst = Xnew16;
		        Xsnd = Xnew16;
		        FlipSenseStep = 1;
	      }  //If the first value is negative and it's decreasing, refresh the peak value
	      else if((Xfst<=0)&&(Xnew16<=Flip_LowTh)&&(Xnew16<=Xfst))
	      {
		        Xfst = Xnew16;
		        Xsnd = Xnew16;
		        FlipSenseStep = 1;
	      }
	     else
 	     {
 	     	Xsnd = Xnew16;
	     }
	     // If the first peak values found, enter step 2
	    break;                        
    case 2:
	       // Step 2: find the second peak
	      FlipSenseStep = 3;
	      //If the first peak is positive, find the miminum value for second peak
	      if((Xfst>=Flip_HighTh)&&(Xnew16<Xsnd))
	      {
	        Xsnd = Xnew16;
	        FlipSenseStep = 2;
	      }                            //If the first peak is negative, find the maximum value for second peak
	      else if((Xfst<=Flip_LowTh)&&(Xnew16>Xsnd))
	      {
	        Xsnd = Xnew16;
	        FlipSenseStep = 2;
	      }

	      if(FlipSenseStep==3)      //If the second peak found, enter step 3: judge flip direction and axis
	      {
		        FlipSenseStep = 4;
		        FlipReport = XFPOS;      //Assume flip on axis X and positive direction
		        FlipDelay = Flip_DelayTime;
		        Xsnd = abs(Xfst - Xsnd); //The axis with maximum absolute value between the first and second peaks is the fliping axis

		        if(Xfst<0) 
					FlipReport++; //If the first peak is negative, flip direction is negative
					
		        if(Xsnd<Flip_AbsTh)
			{
				FlipReport = NOFLIP;			
				FlipSenseStep = 0 ;
	        	}
	      }
	
	      break;
    case 4:                            	
		// Step 4: delay between flips
	      if(!(FlipDelay--)) 
		{
			FlipSenseStep = 0;	//Back to step 0 when delay finished
			FlipFindFlag = 1  ;
	      	}
	      break;
    default:
	      FlipFindFlag = 0;
	      FlipSenseStep = 0;                // Initialize tracking records
	      Xfst = 0;
	      Xsnd = 0;

	       // Check if any axis value beyond threshold
	      if((Xnew16>=Flip_HighTh)||(Xnew16<=Flip_LowTh)) 
		  	Xfst = Xnew16;

	      if( Xfst  != 0 )
		{             
		        // If any axis g-value beyond threshold, start tracking
		        FlipSenseStep = 1;
	       }
	  
    break;
  }
  return 1;
}





#endif


extern void delayms(unsigned int t);

#define threshold 150

int MatchValue(int a,int b)
{

	int value = 0 ;
	value = ( a >= b)?(a-b):(b-a);
	if((value >= threshold ) && (a >= b))
	{
		return 1 ;		
	}
	else if ((value >= threshold ) && (a <= b))
		return 2 ;

	return 0 ;
	
}

int GetDirection(void)
{


	VUINT8 sense = 0 ;
	int Direction = 0 ; 
	int times = 0 ;
	Flip_GetSensitivity();
	{
		Flip_Sense();		
		if ( (FlipSenseStep == 0 ) && (  FlipFindFlag == 1 ))
		{
			switch(FlipReport)
			{
				case NOFLIP:
					Direction = 0 ;
					break;
				case XFPOS:
					Direction = 1;
					break;
				case XFNEG:
					Direction = 2 ;
					break;
				case YFPOS:
					Direction = 3 ;
					break;
				case YFNEG:
					Direction = 4 ;				
					break;
				case ZFPOS:
					Direction = 5 ;				
					break;
				case ZFNEG:
					Direction = 6 ;				
					break;
				default:
					Direction = 0 ;
					break;
			}
			
			if( Direction != 0 )
				FlipReport = 0 ;
		}
		else
		{
				Direction = 0 ;
		}
	}
	return 	Direction ;

}


#endif



#endif
