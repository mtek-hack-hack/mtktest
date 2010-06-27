/* (c) Copyright Sunrun, Inc., 2006.	All rights reserved.
 *	 Sunrun Confidential Proprietary
 *	 Contains confidential proprietary information of Sunrun, Inc.
 *	 Reverse engineering is prohibited.
 *	 The copyright notice does not imply publication.
 * 
 *
 *	 描述 :	新然公司纯英文输入法产品API及函数说明.
 *   
 *
 ************** VERSION DEFINATION *******************************
      
/******************************************************************************************
 * 
 * 函数： fnEnglishSearch 
 *  
 *描述：
 *    该函数接受按键传入的按键值，利用搜索引擎查找正确的英文单词的unicode码。
 *     
 *参数：
 *    keyinput : 存储输入按键值参数的数组。
 *    csEnglishSearchResult ：存储对应输入参数值搜索到的正确英文单词的unicode码串的数组。
 *                                                每个英文单词之间以空格 0x20分开。
        EXP：    键入按键2.2.6.4在调用fnPyzhSearch函数之后搜索到对应的单词组合有“yahoo”“wagon”
                       此时csEnglishSearchResult[0]=0x77
                           csEnglishSearchResult[1]=0x61
                           csEnglishSearchResult[2]=0x67
                           csEnglishSearchResult[3]=0x6f
                           csEnglishSearchResult[4]=0x6e
                           csEnglishSearchResult[5]=0x20
                           csEnglishSearchResult[6]=0x79
                           csEnglishSearchResult[7]=0x61
                           csEnglishSearchResult[8]=0x68
                           csEnglishSearchResult[9]=0x6f
                           csEnglishSearchResult[10]=0x6f
                           csEnglishSearchResult[11]=0x20
                           default=0；
                       
 *
 说明：
 *      目前我们英文编码的最大组合长度为17，我们一般推荐定义成为keyinput[20]与笔画拼音通用；
 *      另外返回的最大字母个数为100，一般推荐定义为csEnglishSearchResult[100]；
 *      具体可参考简单实例中的定义。
 
    
 * 调用返回：
 *      0 : 调用正确。
 *      1 : 调用错误。
 *  
 * 纯DOS下简单调用实例：
 
         U16 csEnglishSearchResult[LEN_ENGLISHRESULT];
         static char csKeyInput[20];
         
         
         fnKeyInputSimu(count_input_simu);      
       
        while ( 1 ) {
            //-- lib call of fnEnglishSearch() --//
            ret = fnEnglishSearch(csKeyInput,csEnglishSearchResult);
            printf("\n------ret = %d ------------------English Result ---> ",ret);
            if ( ret == FUC_RIGHT_CALLED ) {
                printf("\n ****<< pycount_result = %d >>****\n",pycount_result);
                for ( i=0;i<LEN_ENGLISHRESULT;i++ ) {
                    printf("%c",csEnglishSearchResult[i]);
                }
                printf("\n ----------------------------------------------- ");
                fnEnCapSel(EN_CAP_FIRSTCAP,csEnglishSearchResult);
                printf("\n*********************************\n");
                for ( i=0;i<LEN_ENGLISHRESULT;i++ ) {
                    printf("%c",csEnglishSearchResult[i]);
                } 
            } else {
                printf("\n ****<< pycount_result = %d >>****\n",pycount_result);
                for ( i=0;i<LEN_ENGLISHRESULT;i++ ) {
                    printf("%c",csEnglishSearchResult[i]);
                }
                printf("\n ----------------------------------------------- ");
                count_input_simu--;
            }
            count_input_simu++;    
            fnKeyInputSimu(count_input_simu);  
        }
 
 
 *    
 *******************************************************************************************/
U16 fnEnglishSearch(char *keyinput,U16 *csEnglishSearchResult);
 

/******************************************************************************************
 * 
 * 函数: fnEnCapSel 
 *  
 * 描述：
 *    该函数用于英文输入的大小写切换功能。可提供全小写，首字大写，全部大写。 
 *    
 *     
 * 参数：
 *    msel                  : 模式选者
 *                            0:  全小写，默认。
 *                            1:  首字大写。
 *                            2:  全大写。
 *    csEnglishSearchResult : 存储对应输入参数值搜索到的正确英文单词的unicode码串的数组。
 *                                                每个英文单词之间以空格 0x20分开。
 *   
 * 调用返回：
 *      0 : 调用正确。
 *      1 : 调用错误。
 *  
 * 纯DOS下简单调用实例：
 
      可见英文调用参考中切换成首字大写的例子。
   
 
 *    
 *******************************************************************************************/
int fnEnCapSel(int msel,U16 *csEnglishSearchResult);

/******************************************************************************************/
/* 
 * cscount_result :全局变量，存储返回的正确值的个数，包括拼音笔划中的正确返回汉字数和英文中正确英文单词数。肯定小于118的最大值。 
 *                  
 * pycount_result : 全局变量，存储返回的正确的拼音组合个数，一般在  0 到MAX（最大拼音组合数）
 */
extern U16 Encscount_result ;
extern U16 Encount_result ;

#ifndef __MMI_LANG_SM_CHINESE__ /* 如果没有繁体输入法,定义下面的空函数*/
U16 fnBhSearch(char *keyinput,U16 *searchresult)
{
	return 0;
}
U16 fnPySearch(char *keyinput,U16 *csPyzhStore,U16 *searchresult,int count_pyzh_sel)
{
	return 0;
}
U16 fnCharAssociation(U16 selChar,U16 *searchresult)
{
	return 0;
}
int Give_uncode_to_GetCharInfo(unsigned short uncode,unsigned char *bh,unsigned char *py)
{
	return 0;
}
U16 cscount_result = 0 ;
/*UNI@bw_20070724 15:36:06  没有简体的版本中,定义两个空的变量  */
U16 pycount_result = 0;

#endif
#ifndef __MMI_LANG_TR_CHINESE__ /* 如果没有繁体输入法,定义下面的空函数*/
unsigned short T_fnCharAssociation(unsigned short selChar,unsigned short *searchresult)
{
	return 0;
}
int T_ZySearch( char *input,unsigned short *ZyzhStore,unsigned short *searchresult,int zyzh_sel)
{
	return 0;
}
int T_Give_uncode_to_GetCharInfo(unsigned short T_unicode,unsigned short *ZY_zh_unicode)
{
	return 0;
}
U16 zy_zh_count_result;
U16 zy_cs_count_result; 
#endif
