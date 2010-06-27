/*********************************************************************
 
  (c) copyright Freescale Semiconductor Ltd. 2008
  ALL RIGHTS RESERVED
 
 ********************************************************************
 Ver 0	Initial release
 ********************************************************************/

#ifndef _DATA_H
#define _DATA_H

typedef signed char VINT8;
typedef unsigned char VUINT8;
typedef signed short VINT16;
typedef unsigned short VUINT16;

typedef struct {
  VINT16  X;
  VINT16  Y;
  VINT16  Z;  
} SPARAMETERS;

#define MOTION_SENSOR_SUPPORT
//#define ACC_DEBUG  0 //ghw111

#endif
