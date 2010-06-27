/* (c) Copyright Sunrun, Inc., 2006.	All rights reserved.
 *	 Sunrun Confidential Proprietary
 *	 Contains confidential proprietary information of Sunrun, Inc.
 *	 Reverse engineering is prohibited.
 *	 The copyright notice does not imply publication.
 * 
 *
 *	 描述 :	新然公司输入法繁体输入法产品API及函数说明.
 *     
 *
    注意：该产品为最标准的台湾BIG5字库集
 
 
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
 *      目前我们英文编码的最大组合长度为17，我们一般推荐定义成为keyinput[20]；
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
 * 函数： T_fnCharAssociation 
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
 *      目前我们联想字的最大长度为30，只要大于30的数组都可；
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

unsigned short T_fnCharAssociation(unsigned short selChar,unsigned short *searchresult);





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



/********************************************************************************
*  说明：繁体注音输入发搜索主函数
*
*   输入参数1：input，键值，注音的输入参数范围为1-9的字符
*   输入参数2：zyzh_sel，注音组合选择，-1时查找注音组合，其他情况选取注音组合
*   输出参数3：ZyzhStore，注音组合(返回注音组合的unicode，组合间以空格分开)
*   输出参数4：searchresult，返回的查找结果的unicode码,最大返回280个字
*   功能及参数说明可参考简体拼音输入函数
*   注意：
*       input 赋值时要注意为字符型。如 input='2'；
*    RETURN VALUE: 
*      0 : work correctly.
*      1 : work incorrectly.
*    变量定义参考：
*   
*       char a[10];
*       char a_tmp[10];
*       unsigned short b[20];
*       unsigned short c[280];
*       int d; 
*       int count_input_simu=0;
*       int ret=0; 
*   函数引用参考： 
*
*     while(1)
*         {
*           
*           KeyInput_zy(count_input_simu);
*           
*            while(T_ZySearch(a,b,c,-1)==1)
*              {printf("\nyou input error key!\n");
*               printf("\nThe last right input zyzh is:");
*               for ( i=0;i<strlen(a_tmp);i++ ) 
*                  printf("(%c) ",a_tmp[i]);
*               printf("\n");
*               for(ret=0;ret<(sizeof(b)>>1);ret++)
*                 printf("(%d)0x%x ",ret,b[ret]);
*               printf("\nThe last right zyresult is:");
*               for(ret=0;ret<sizeof(c)>>1;ret++)
*                 printf("(%d)0x%x ",ret,c[ret]);
*               KeyInput_zy(count_input_simu);
*               //printf("\nplease input key:\n");
*               //a[count_input_simu]=getche();
*               }
*           memcpy(a_tmp,a,10);
*           printf("\nThe right zyzh is:");
*           for(ret=0;ret<(sizeof(b)>>1);ret++)
*              printf("(%d)0x%x ",ret,b[ret]);
*           printf("\nplease input sel(0--):\n");
*           printf("you input sel is:");
*           scanf("%d",&d);                       
*           if (T_ZySearch(a,b,c,d)==1)
*              printf("can not find word!\n");
*           else
*              {printf("The right zyresult is:");
*               for(ret=0;ret<(sizeof(c)>>1);ret++)
*                  printf("(%d)0x%x ",ret,c[ret]);
*              }
*           count_input_simu++;
*          }  
*
*
*     ********************
*     取得注音的键盘输入
*     ********************
*     U16 KeyInput_zy(U16 count_input_simu) 
*      {
*        int i;
*
*        printf("\nPlease enter key..  ");
*    
*       //a[count_input_simu]=getche();
*       scanf(" %c",&a[count_input_simu]);
*      
*     
*       printf("\n your keyinput is:");
*       for ( i=0;i<strlen(a);i++ ) 
*          printf("(%c)",a[i]);
*    
*    
*       printf("\n");
*    
*     }
*
*********************************************************************************/
int T_ZySearch( char *input,unsigned short *ZyzhStore,unsigned short *searchresult,int zyzh_sel);

/**************************************************************
 说明：输入繁体字unicode码得到其注音组合unicode码

 输入参数 ：T_unicode
 输出参数 ：ZY_zh_unicode

 调用参考：
     unsigned short ZY_zh_unicode[4];
     unsigned short input_unicode;

     while(1)
           {
             printf("\nplease input unicode:");
             scanf("%x",&input_unicode);         
             ret=T_Give_uncode_to_GetCharInfo(input_unicode,ZY_zh_unicode);
            if (ret==0) 
            {   i=0;
               printf("unicode input is right!\n");
               printf("zuyin zhuhe is:");
              while (ZY_zh_unicode[i]!=0) {
                printf("0x%x,",ZY_zh_unicode[i]);
                i++;
              }
             
            }
           else
             printf("\nuncode input is wrong!\n");  
           }
 
***************************************************************/
int T_Give_uncode_to_GetCharInfo(unsigned short T_unicode,unsigned short *ZY_zh_unicode);





/******************************************************************************************/

/* 
 * cscount_result :全局变量，存储返回的正确值的个数。 
 *                  
 * pycount_result : 全局变量，英文中正确英文单词数
 *
 *
 * zy_zh_count_result ：返回找到的注音组合数
 * zy_cs_count_result： 返回找到的对应准确注音及衍生音的字的个数,肯定小于280的最大值
 */
extern U16 cscount_result ;
extern U16 pycount_result ;
extern U16 zy_zh_count_result;
extern U16 zy_cs_count_result; 
