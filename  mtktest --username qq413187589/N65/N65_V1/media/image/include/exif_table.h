//--Look up tables--

/*  Move to exif.h
#define EXIF_DEC_Orientation_MAX_LEN		11
#define EXIF_DEC_ResolutionUnit_MAX_LEN		12
#define EXIF_DEC_YCbCrPositioning_MAX_LEN	9
#define EXIF_DEC_ExposureProgram_MAX_LEN	18
#define EXIF_DEC_ComponentsConfig_MAX_LEN	6
#define EXIF_DEC_MeteringMode_MAX_LEN		24
#define EXIF_DEC_LightSource_MAX_LEN		17
#define EXIF_DEC_Flash_MAX_LEN				80
#define EXIF_DEC_ColorSpace_MAX_LEN			13
#define EXIF_DEC_ExposureMode_MAX_LEN		16
#define EXIF_DEC_SceneCaptureType_MAX_LEN	12
*/

const char* exif_Orientation_table[]=
{
 "0",
 "top-left",
 "top-right",
 "down-right",
 "down-left",

 "5",
 "6",
 "7",
 "8",
};

const char* exif_ResolutionUnit_table[]=
{
 "0",
 "1",
 "inches",
 "centimeters"
};

const char* exif_YCbCrPositioning_table[]=
{
 "0",
 "centered",
 "co-sited"
};

const char* exif_ExposureProgram_table[]=
{
 "Not defined",
 "Manual",
 "Normal program",
 "Aperture priority",// (光圈優先)
 "Shutter priority",// (快門優先)
 "Creative program",// (biased toward depth of field) (創意程式)
 "Action program",// (biased toward fast shutter speed) (動作程式)
 "Portrait mode",// (for closeup photos with the background out of focus) (人像模式)
 "Landscape mode"// (for landscape photos with the background in focus) (風景模式)
};

const char* exif_ComponentsConfig_table[]=
{
 "YCbCr",
 "RGB"
};

const char* exif_MeteringMode_table[]=
{
 "Unknown",
 "Average",					//(平均)
 "Center Weighted Average",	//(平均中央為主)
 "Spot"	,					//(點測光)
 "MultiSpot",				//(多點測光)

 "Pattern",					//(範本)
 "Partial",					//(部分)
 "Reserved",            
 "Other"               //255
};

const char* exif_LightSource_table[]=
{
 "unknown",
 "Daylight",		//(日光)
 "Fluorescent",		//(螢光)
 "Tungsten",		//(鎢光)
 "4",

 "5","6","7","8","9",
 "10","11","12","13","14",
 "15","16",
 "Standard light A", //(2855k)
 "Standard light B", //(4874k)
 "Standard light C", //(6774k)
 "D55",				//(5500k)
 "D65",				//(6504k)
 "D75"				//(7500k)
};



const char* exif_Flash_table[]=
{
 "Flash did not fire",  //0x00
 "Flash fired",
 "0x02","0x03", "0x04",
 "Strobe return light not detected",   //0x05
 "0x06",
 "Strobe return light detected",       //0x07
 
 "0x08",
 "Flash fired, compulsory mode", //0x09
 "0x0A","0x0B","0x0C",
 "Flash fired, compulsory mode, return light not detected",   //0x0d
 "0x0E",
 "Flash fired, compulsory mode, return light detected",   //0x0f
 "Flash did not fire, compulsory mode", //0x10
 "0x11","0x12","0x13","0x14","0x15","0x16","0x17",
 "Flash did not fire, auto mode",//0x18
 "Flash fired, auto mode",//0x19
 "0x1A","0x1B","0x1C",
 "Flash fired, auto mode, return light not detected",//0x1d
 "0x1E",
 "Flash fired, auto mode, return light detected",//0x1f
 "No flash function",//0x20
 "0x21","0x22","0x23","0x24","0x25","0x26","0x27","0x28","0x29","0x2A","0x2B","0x2C","0x2D","0x2E","0x2F",
 "0x30","0x31","0x32","0x33","0x34","0x35","0x36","0x37","0x38","0x39","0x3A","0x3B","0x3C","0x3D","0x3E","0x3F",
 "0x40",
 "Flash fired, red-eye reduction mode",//0x41
 "0x42","0x43","0x44",
 "Flash fired, red-eye reduction mode, return light not detected",//0x45
 "0x46",
 "Flash fired, red-eye reduction mode, return light detected",//0x47
 "0x48",
 "Flash fired, compulsory mode, red-eye reduction mode",//0x49
 "0x4A","0x4B","0x4C",
 "Flash fired, compulsory mode, red-eye reduction mode, return light not detected",//0x4D
 "0x4E",
 "Flash fired, compulsory mode, red-eye reduction mode, return light detected",//0x4F
 "0x50","0x51","0x52","0x53","0x54","0x55","0x56","0x57","0x58",
 "Flash fired, auto mode, red-eye reduction mode",//0x59
 "0x5A","0x5B","0x5C",
 "Flash fired, auto mode, return light not detected, red-eye reduction mode",//0x5D
 "0x5E",
 "Flash fired, auto mode, return light detected, red-eye reduction mode"//0x5F
};

const char* exif_ExposureMode_table[]=
{
 "Auto Exposure",
 "Manual Exposure",
 "Auto Bracket"
};

const char* exif_SceneCaptureType_table[]=
{
 "Standard",
 "Landscape",
 "Portrait",
 "Night Scene"
};

