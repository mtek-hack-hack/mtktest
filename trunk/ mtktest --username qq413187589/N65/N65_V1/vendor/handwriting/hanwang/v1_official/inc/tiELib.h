/* 简体中文和英文的头文件 
 *(c) Copyright Sunrun, Inc., 2006.	All rights reserved.
 *	 Sunrun Confidential Proprietary
 *	 Contains confidential proprietary information of Sunrun, Inc.
 *	 Reverse engineering is prohibited.
 *	 The copyright notice does not imply publication.
 * 
 *
 *	 描述 :	新然公司输入法产品API及函数说明.
 *   
 *
 ************** VERSION DEFINATION *******************************
 

        
/******************************************************************************************
 * 
 * 函数名: fnBhSearch 
 *  
 * 描述: 
 *    该函数接受按键传入的按键值的参数，通过输入法搜索引擎，在字库内搜索到正确的汉字unicode码，并返回调用正确值0.
 *     如无输入参数对应的值，则返回调用错误值1，并返回上一次正确的参数及值。 
 *     
 *     
 * 参数：
 *    keyinput : 存储输入按键值参数的数组。其值常为1-9的按键值。
 *               -- exp. 通常参数可在 MMI 平台中定义为 " char KeyInput[20]; " ，
 *    searchresult : 存储对应输入参数值搜索到的正确汉字的unicode码串的数组。
 *               -- exp. 通常参数可在 MMI 平台中定义为 " U16 csSearchResult[LEN_RESULT_ONESEARCH];" 
 *                    LEN_RESULT_ONESEARCH 是一次搜索返回的值的数组最大长度，其值目前为118.
 * 说明：
 *      目前我们汉字编码的最大笔画为17即可得到所有汉字，则传入keyinput一般至少要大于17，我们推荐定义为keyinput[20]即可；
 *      另外返回的最大汉字个数为118，一般推荐定义为searchresult[118]；
 *      具体可参考简单实例中的定义。
 
 * 调用返回：
 *      0 : 调用正确。
 *      1 : 调用错误。
 *  
 * 纯DOS下简单调用实例： 
 
       
        static char csKeyInput[20];
        U16 csSearchResult[LEN_RESULT_ONESEARCH];
        
        
         fnKeyInputSimu(count_input_simu); 
        
        while ( 1 ) {
            
            ret=fnBhSearch(csKeyInput,csSearchResult);
            if ( ret == FUC_RIGHT_CALLED ) {
                printf("\n ret = %d",ret);
                printf("\n cscount_result = %d",cscount_result);
                showAlternate();  
            } else {
                printf("\n ret = %d",ret);
                printf("\n cscount_result = %d",cscount_result);
                printf("\n no charactors... backkey");
                count_input_simu--;
            } 
            count_input_simu++;   
            fnKeyInputSimu(count_input_simu); 
        }
        
        U16 fnKeyInputSimu(U16 count_input_simu) {
          char i;
          printf("\nPlease enter key..  ");
          scanf("%16d",&csKeyInput[count_input_simu]);
          printf("\n your keyinput is:");
          for ( i=0;i<strlen(csKeyInput);i++ ) {
             printf("(%d) ",csKeyInput[i]);
          }
        }
 *         
 *         
 *         
 *******************************************************************************************/
U16 fnBhSearch(char *keyinput,U16 *searchresult);


/******************************************************************************************
 * 
 * 函数：fnPySearch 
 *  
 * 描述： 
 *    该函数接受按键传入的按键值，形成可能的拼音组合，在确定了拼音组合后利用搜索引擎查找正确的汉字unicode码。并返回调用正确值0。
 *     如无输入参数对应的值，则返回调用错误值1，并返回上一次正确的参数及值。
 *
 * 参数：
 *    keyinput : 存储输入按键值参数的数组。其值常为1-9的按键值。
 *    csPyzhStore :  存储输入按键值可形成的对应的拼音组合的数组。如输入96键，则keyinput中存储9,6。而csPyzhStore 的值为 0x77,0x6f,0x20,0x79,0x6f,0x20,0x7a,0x6f,0x20,0x0,0x0,0x0....
                                 显示出来则是  wo yo zo。
 *    searchresult : 存储对应输入参数值搜索到的正确汉字的unicode码串的数组。
 *    count_pyzh_sel : 由于不同的按键组合会有不同的拼音组合产生，该参数用于确定目前用户选中哪个拼音组合。
                                   其值在第一次调用时传入-1表示查找拼音组合，如存在拼音组合后即csPyzhStore不为空时，
                                   可取0-MAX（最大拼音组合数）以表示你需要找字的拼音组合。在以上例子中，则count_pyzh_sel取0时表示选中wo。 
 *
 * 说明：
 *      目前我们汉字编码的最大返回拼音组合长度为30(7426键)，我们一般推荐定义成csPyzhStore[40]。另拼音的传入参数keyinput一般至少要大于6即可，但我们推荐定义为keyinput[20]与笔画通用；
 *      另外返回的最大汉字个数同笔画为118，一般推荐定义为searchresult[118]与笔画通用；
 *      具体可参考简单实例中的定义。                    
 *   
 * 调用返回：
 *      0 : 调用正确。
 *      1 : 调用错误。
 *  
 * 纯DOS下简单调用实例：
 *  
 *     #define PYSEARCH_STEP1_pyzh  -1 
 
        U16 pyzh_count = 0;
        static char csKeyInput[20];
        U16 csSearchResult[LEN_RESULT_ONESEARCH];
        U16 csEnglishSearchResult[30];
        
        
        fnKeyInputSimu(count_input_simu); 
        while ( 1 ) {
            //-- lib call of fnPySearch() --//
            ret = fnPySearch(csKeyInput,csEnglishSearchResult,csSearchResult,PYSEARCH_STEP1_pyzh);
            if ( ret == FUC_RIGHT_CALLED ) {
                printf("\n ****<< pycount_result = %d >>****",pycount_result);
                printf("\n ret1 = %d",ret);
                fnShowPyzhStore();
                printf("\nPlease select the pinyin (0--..) ..  ");
                scanf(" %d",&pyzh_count);
                ret = fnPySearch(csKeyInput,csEnglishSearchResult,csSearchResult,pyzh_count);
                printf("\n ****<< cscount_result = %d >>****",cscount_result);
                printf("\n ret2 = %d",ret);
                showAlternate(); 
            } else {  //the return ret is error
                count_input_simu--;
                //printf("\n ****<< pycount_result = %d >>****",pycount_result);
                //printf("\n ret1 = %d",ret);
                //fnShowPyzhStore();
                //printf("\n ****<< cscount_result = %d >>****",cscount_result);
                //printf("\n ret2 = %d",ret);
                //showAlternate(); 
            }
            count_input_simu++;    
            fnKeyInputSimu(count_input_simu);  
        }
 *    
 *       
 *     
 *      
 *******************************************************************************************/
U16 fnPySearch(char *keyinput,U16 *csPyzhStore,U16 *searchresult,int count_pyzh_sel);


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
 * 函数： fnCharAssociation 
 *  
 *描述：
 *    该函数用于给选中的汉字生成联想常用字，方便用户快速输入。
        EXP：选中“我”时，马上就联想到“们”等其他常用词。
 *                                                                         
 * 参数：
 *    selChar : 将要被生成联想字的unicode码值。
 *    searchresult : 生成的，可与传入汉字组成常用词组的汉字的unicode码串。
 * 
   说明：
 *      目前我们联想字的最大长度为30，只要大于30的数组都可，我们一般推荐定义成为csSearchResult[118]与笔画拼音通用；
 *      
 *      具体可参考简单实例中的定义。
   
 * 调用返回：
 *      0 : 调用正确。返回该选定字的联想字。
 *      1 : 调用错误。返回最常用的30个汉字。
 *  
 * 纯DOS下简单调用实例：
 *  
 *    
      U16 csSearchResult[LEN_RESULT_ONESEARCH];
 
       ret = fnCharAssociation(0x8d5d,csSearchResult); 
        if ( ret == FUC_RIGHT_CALLED ) {
            printf("\n cscount_result = %d ",cscount_result);
            showAlternate();    
            printf("\n ret of association = %d",ret);
        } else {
            printf("\n error in fuction call fnCharAssociation ");
            showAlternate();
        }   
 
 
 
 *   
 *******************************************************************************************/

U16 fnCharAssociation(U16 selChar,U16 *searchresult);





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



/*************************************************************************
  函数: Give_uncode_to_GetCharInfo 
  描述：输入unicode吗，得出该码对应的拼音组合及笔画次序 。
  参数：
      uncode  需要得到信息的汉字的UNICODE码值。
      bh      该UNICODE码对应汉字的笔画组合，注意bh数组长度必须大于18以便能存下所有笔画数，推荐用bh[18]。
      py      该UNICODE码对应汉字的拼音组合，注意py数组长度必须大于10以便能存下最大Py组合数，推荐用py[10]。
 

      
  调用返回：
 *      0 : 调用正确。
 *      1 : 调用错误。
  纯DOS下简单调用实例：
  
     unsigned char bh[18];
     unsigned char py[10];
  
     while(1)
         {
         printf("please input unicode:");
         scanf("%x",&input_unicode);         
         ret=Give_uncode_to_GetCharInfo(input_unicode,bh,py);
         if (ret==0) 
         {   i=0;
             printf("\nuncode input is right!\n");
             printf("bihua zhuhe is:");
         while (bh[i]!=0) {
          printf("%d",bh[i]);
          i++;
         }
         printf("\npiyin zhuhe is:%s\n",py);
         }
         else
            printf("\nuncode input is wrong!\n");  
         }
 
   如输入0x7684(的)，则bh数组的值为32511354，py数组的值位de。
************************************************************************/
int Give_uncode_to_GetCharInfo(unsigned short uncode,unsigned char *bh,unsigned char *py);

/******************************************************************************************/
/* 
 * cscount_result :全局变量，存储返回的正确值的个数，包括拼音笔划中的正确返回汉字数。肯定小于118的最大值。 
 *                  
 * pycount_result : 全局变量，存储返回的正确的拼音组合个数，一般在  0 到MAX（最大拼音组合数）,和英文中正确英文单词数。
 */
extern U16 cscount_result ;
extern U16 pycount_result ;

