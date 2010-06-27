#include "kal_release.h" 
kal_char* release_verno(void) 
{ 
   static kal_char verno_str[] = "LBSCS03.8.12.1.0T08M0718_M501C"; 
   return verno_str; 
} 
kal_char* release_hw_ver(void) 
{ 
   static kal_char hw_ver_str[] = "UNIRISE25_GEMINI_HW"; 
   return hw_ver_str; 
} 
kal_char* build_date_time(void) 
{ 
   static kal_char build_date_time_str[] = "2010/06/19 20:34"; 
   return build_date_time_str; 
} 
kal_char* release_build(void) 
{ 
   static kal_char build_str[] = "B0001"; 
   return build_str; 
} 
kal_char* release_branch(void) 
{ 
   static kal_char build_branch_str[] = "GEMINI"; 
   return build_branch_str; 
} 
kal_char* software_summary(void) 
{ 
   static kal_char software_comment_str[] = "N65_[BB]MT6225_[PCB]V2P0_[RFPA:850|900|1800|1900]RF7168_[Mem]K5L2731CAA_[LCD]FT1505C_YT372804PL_[MainCam]OV7680_[SubCam]OV7680_[BT]MT6601_[TV]TLG1100_[FM]NONE_[ANI]SMILE_[KEY]V1_[JAVA]NO_[TP]YES"; 
   return software_comment_str; 
} 
