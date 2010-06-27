/************************************************************************* 
 * Copyright (c) 2000-2003 MobileSoft Corporation All Rights Reserved.	
 * 日  期：  2004-3-31   	
 * 作  者：  滕永; yongt@mobilesoft.com.cn   
 * 文  件：  memory_test.h 	    	
 * 描  述：		用于测试内存泄露的情况。	
 * 修改记录： 
      人  员：   原     因：                   状   态：      日   期：
      滕永      创建                          完成           2004-3-31
 ************************************************************************/
#ifndef MEMORY_TEST_H_
#define MEMORY_TEST_H_



#define my_malloc(x)	test_memory_malloc(x,__FILE__,__LINE__)
#define my_free(x)		test_memory_free(x, __FILE__, __LINE__, 1)
#define my_bogusfree(x) test_memory_free(x, __FILE__, __LINE__, 0)

#ifndef TI //  Modified by TIPrj[2005/6/29]
#if defined( __cplusplus  ) && __cplusplus
extern "C" {
#endif
#endif
	
	
/************************************************************************* 
 * 描  述：   测试分配内存
 * 返回值：   分配的内存地址.  
 * 全局量：   g_memory_info;
          
 * 日  期：  2004-3-31
 * 作  者：  滕永; yongt@mobilesoft.com.cn
 ************************************************************************/
void * test_memory_malloc(unsigned int size,	/* 所分配的内存大小 */ 
						  char *file,			/* 所在文件 */
						  int line);


/************************************************************************* 
 * 描  述：   测试释放内存
 * 返回值：    
 * 全局量：  g_memory_info;
          
 * 日  期：  2004-3-31
 * 作  者：  滕永; yongt@mobilesoft.com.cn
 ************************************************************************/
void test_memory_free(void *p_object , char* file, int line, int free_flag);


/************************************************************************* 
 * 描  述：   初始化测试内存;
 * 返回值：  1/0;  
 * 全局量：  g_memory_info;
          
 * 日  期：  2004-3-31
 * 作  者：  滕永; yongt@mobilesoft.com.cn
 ************************************************************************/
short init_memory_test( void );


/************************************************************************* 
 * 描  述：   初始化测试内存;
 * 返回值：    g_memory_info
 * 全局量：  
          
 * 日  期：  2004-3-31
 * 作  者：  滕永; yongt@mobilesoft.com.cn
 ************************************************************************/
void unload_memory_test( void );

#ifndef TI //  Modified by TIPrj[2005/6/29]
#if defined( __cplusplus  ) && __cplusplus
}
#endif
#endif

#endif

