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
 * Filename:
 * ---------
 * widget_linklist.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resizable array for storing widget data
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

////////////////////////////////////////////////////////////////////
// control the child links
////////////////////////////////////////////////////////////////////

#ifdef WIDGET_MALLOC_IN_OWNER_MODULE
#define widget_linklist_malloc(MODID, SIZE) widget_malloc_mem(MODID, SIZE)
#define widget_linklist_free(MODID, PTR) widget_free_mem(MODID, PTR)
#else /* WIDGET_MALLOC_IN_OWNER_MODULE */ 
#define widget_linklist_malloc(MODID, SIZE) widget_malloc_mem(SIZE)
#define widget_linklist_free(MODID, PTR)widget_free_mem(PTR)
#endif /* WIDGET_MALLOC_IN_OWNER_MODULE */ 

#define widget_insert_array(MODID,ARRAY,SIZE,MAXSIZE,ITEM,INDEX)              \
   {                                                                          \
      if(SIZE==MAXSIZE) /* need to resize array */                            \
      {                                                                       \
         widget_header_struct** new_array;                                    \
         widget_header_struct** old_array;                                    \
         WAP_DBG_ASSERT(MAXSIZE<(0xFFFF-WIDGET_BASIC_LINK_SIZE)) /* max_childs_sum is kal_uint16 */               \
         MAXSIZE = MAXSIZE+WIDGET_BASIC_LINK_SIZE;                            \
         new_array = widget_linklist_malloc(MODID, (MAXSIZE) * sizeof(void*));\
         if(INDEX>0)                                                          \
            memcpy(new_array,ARRAY,(INDEX)*sizeof(void*));                    \
         if(SIZE - INDEX>0)                                                   \
            memcpy(                                                           \
               new_array + INDEX+1,                                           \
               ARRAY+INDEX,                                                   \
               (SIZE - INDEX)*sizeof(void*));                                 \
         old_array = ARRAY;                                                   \
         ARRAY = new_array;                                                   \
         if(old_array) widget_linklist_free(MODID, old_array);                \
      }                                                                       \
      else                                                                    \
      {                                                                       \
         kal_uint16 _dest;                                                     \
         for(_dest = SIZE;_dest>INDEX;_dest--)                                \
         {                                                                    \
            ARRAY[_dest] = ARRAY[_dest-1];                                    \
         }                                                                    \
      }                                                                       \
      ARRAY[INDEX] = ITEM;                                                    \
      WAP_DBG_ASSERT(SIZE<0xFFFF) /* childs_sum is kal_uint16 */                 \
      (SIZE)++;                                                               \
   }                                                                          \

#define widget_insert_childs_by_index(PARENT,CHILD,INDEX)               \
   {                                                                    \
      ASSERT(!IS_FLAG_STATIC(CHILD));                                   \
      widget_insert_array(                                              \
         _H(PARENT)->module_id,                                         \
         _H(PARENT)->childs,                                            \
         _H(PARENT)->childs_sum,                                        \
         _H(PARENT)->max_childs_sum,                                    \
         _H(CHILD),                                                     \
         INDEX);                                                        \
                                                                        \
      _H(CHILD)->parent = _H(PARENT);                                   \
      INC_REF(_H(CHILD));                                               \
   }                                                                    \

#define widget_replace_childs_by_index(PARENT,CHILD,INDEX)              \
   {                                                                    \
      ASSERT(!IS_FLAG_STATIC(CHILD));                                   \
      if(_H(PARENT)->childs_sum>INDEX)                                  \
      {                                                                 \
         DEC_REF(_H(PARENT)->childs[INDEX]);                            \
         if(!HAS_REF(_H(PARENT)->childs[INDEX]))                        \
            widget_release(_H(PARENT)->childs[INDEX]);                  \
         _H(PARENT)->childs[INDEX] = _H(CHILD);                         \
         INC_REF(_H(CHILD));                                            \
      }                                                                 \
   }                                                                    \

#define widget_insert_first_childs(PARENT,CHILD) \
   widget_insert_childs_by_index(PARENT,CHILD,0)

#define widget_insert_last_childs(PARENT,CHILD) \
   widget_insert_childs_by_index(PARENT,CHILD,_H(PARENT)->childs_sum);

#define widget_index_childs(CNT,PARENT,CHILD)                           \
   {                                                                    \
      ASSERT(!IS_FLAG_STATIC(CHILD));                                   \
      for(CNT=0;CNT<_H(PARENT)->childs_sum;CNT++)                       \
         if(_H(PARENT)->childs[CNT] == _H(CHILD)) break;                \
      if(CNT == _H(PARENT)->childs_sum) CNT=-1;                         \
   }                                                                    \

#define widget_set_active_childs_by_index(PARENT,INDEX)                 \
   {                                                                    \
      kal_uint32 i;                                                     \
      widget_header_struct *tmp = _H(PARENT)->childs[INDEX];            \
      for(i=INDEX;i>0;i--)                                              \
         _H(PARENT)->childs[i] = _H(PARENT)->childs[i-1];               \
      _H(PARENT)->childs[0] = tmp;                                      \
   }                                                                    \

#define widget_hide_active_childs_by_index(PARENT,INDEX)                \
   {                                                                    \
      kal_uint32 i;                                                     \
      widget_header_struct *tmp = _H(PARENT)->childs[INDEX];            \
      for(i=INDEX+1;i<_H(PARENT)->childs_sum;i++)                       \
         _H(PARENT)->childs[i-1] = _H(PARENT)->childs[i];               \
      _H(PARENT)->childs[i-1] = tmp;                                    \
   }                                                                    \

#define widget_set_active_childs(PARENT,CHILD)                          \
   {                                                                    \
      kal_int32 cnt;                                                    \
      ASSERT(!IS_FLAG_STATIC(CHILD));                                   \
      widget_index_childs(cnt,PARENT,CHILD);                            \
      if(cnt!=-1)                                                       \
      {                                                                 \
         widget_set_active_childs_by_index(PARENT,cnt);                 \
      }                                                                 \
   }                                                                    \

#define widget_hide_active_childs(PARENT,CHILD)                         \
   {                                                                    \
      kal_int32 cnt;                                                    \
      ASSERT(!IS_FLAG_STATIC(CHILD));                                   \
      widget_index_childs(cnt,PARENT,CHILD);                            \
      if(cnt!=-1)                                                       \
      {                                                                 \
         widget_hide_active_childs_by_index(PARENT,cnt);                \
      }                                                                 \
   }                                                                    \

#define widget_get_active_childs(NODE,PARENT)                           \
   {                                                                    \
      kal_uint32 cnt;                                                   \
      widget_header_struct *_p = _H(PARENT);                            \
      NODE=NULL;                                                        \
      for(cnt=0;cnt<_p->childs_sum;cnt++)                               \
         if((_p->childs[cnt]->flag & WIDGET_FLAG_WINDOW)                \
         || IS_SCREEN_TYPE(_p->childs[cnt]))                            \
         {                                                              \
            widget_set_active_childs_by_index(_p,cnt);                  \
            NODE = _p->childs[0];                                       \
            break;                                                      \
         }                                                              \
   }                                                                    \

#define widget_get_next_active_childs(NODE,PARENT)                      \
   {                                                                    \
      kal_int32 cnt;                                                    \
      ASSERT(!IS_FLAG_STATIC(NODE));                                    \
      widget_index_childs(cnt,PARENT,NODE);                             \
      NODE=NULL;                                                        \
      for(cnt++;cnt<PARENT->childs_sum;cnt++)                           \
         if((PARENT->childs[cnt]->flag & WIDGET_FLAG_WINDOW)            \
         || IS_SCREEN_TYPE(PARENT->childs[cnt]))                        \
         {                                                              \
            NODE = PARENT->childs[cnt];                                 \
            break;                                                      \
         }                                                              \
   }                                                                    \

#define widget_get_last_active_childs(NODE,PARENT)                      \
   {                                                                    \
      kal_uint32 cnt;                                                   \
      ASSERT(!IS_FLAG_STATIC(NODE));                                    \
      NODE=NULL;                                                        \
      for(cnt=PARENT->childs_sum-1;cnt>=0;cnt--)                        \
         if((PARENT->childs[cnt]->flag & WIDGET_FLAG_WINDOW)            \
         || IS_SCREEN_TYPE(PARENT->childs[cnt]))                        \
         {                                                              \
            NODE = PARENT->childs[cnt];                                 \
            break;                                                      \
         }                                                              \
   }                                                                    \

#define widget_remove_childs_by_index(PARENT,INDEX)                     \
   {                                                                    \
      if(INDEX!=-1 && INDEX <_H(PARENT)->childs_sum)                    \
      {                                                                 \
         kal_uint32 i;                                                  \
         DEC_REF(_H(PARENT)->childs[INDEX]);                            \
         if(!HAS_REF(_H(PARENT)->childs[INDEX]))                        \
            widget_release(_H(PARENT)->childs[INDEX]);                  \
                                                                        \
         _H(PARENT)->childs_sum--;                                      \
         for(i=INDEX;i<_H(PARENT)->childs_sum;i++)                      \
            _H(PARENT)->childs[i] = _H(PARENT)->childs[i+1];            \
         _H(PARENT)->childs[i] = NULL;                                  \
      }                                                                 \
   }                                                                    \

#define widget_remove_childs(PARENT,NODE)                               \
   {                                                                    \
      int cnt;                                                          \
      widget_index_childs(cnt,PARENT,NODE);                             \
      if(cnt!=-1) widget_remove_childs_by_index(PARENT,cnt);            \
   }                                                                    \

#define widget_has_childs(PARENT)                                       \
   (_H(PARENT)->child_sum!=0)                                           \

#define widget_get_childs_by_index(NODE,PARENT,INDEX)                   \
   if(INDEX >=0 && INDEX< _H(PARENT)->childs_sum)                       \
      NODE=_H(PARENT)->childs[INDEX];                                   \
   else                                                                 \
      NODE=NULL;                                                        \

#define widget_set_attrib(PARENT,ATTRIB,NODE)                           \
   {                                                                    \
      if(PARENT->ATTRIB != NODE)                                        \
      {                                                                 \
         if(PARENT->ATTRIB                                              \
         && !IS_FLAG_STATIC(PARENT->ATTRIB))                            \
         {                                                              \
            widget_remove_childs(PARENT,PARENT->ATTRIB);                \
         }                                                              \
                                                                        \
         PARENT->ATTRIB = NODE;                                         \
         if(PARENT->ATTRIB                                              \
         &&!IS_FLAG_STATIC(PARENT->ATTRIB))                             \
            widget_insert_last_childs(PARENT,NODE);                     \
      }                                                                 \
   }                                                                    \

#define foreach(PARENT,TYPE,NODE,COMMANDS)                              \
   {                                                                    \
      kal_uint16 _i;                                                     \
      for(_i=0;_i<_H(PARENT)->childs_sum;_i++)                          \
         if(IS_##TYPE##_TYPE(_H(PARENT)->childs[_i]))                   \
         {                                                              \
            NODE=_##TYPE##(_H(PARENT)->childs[_i]);                     \
            COMMANDS                                                    \
            if(NODE!=_##TYPE##(_H(PARENT)->childs[_i]))                 \
               _i--;                                                    \
         }                                                              \
   }                                                                    \

#define foreach_childs(PARENT,NODE,COMMANDS)                            \
   {                                                                    \
      kal_uint16 _i;                                                     \
      for(_i=0;_i<_H(PARENT)->childs_sum;_i++)                          \
      {                                                                 \
         NODE=_H(PARENT)->childs[_i];                                   \
         COMMANDS                                                       \
         if(_H(PARENT)->childs[_i] !=NODE)                              \
            _i--;                                                       \
      }                                                                 \
   }                                                                    \

