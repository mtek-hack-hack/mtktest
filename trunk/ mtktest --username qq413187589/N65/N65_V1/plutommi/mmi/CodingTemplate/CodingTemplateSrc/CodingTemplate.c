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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  CodingTemplate.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sample_code
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_code(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 data1, data2;
    S32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * [TOPIC] BLANK SPACE
     * (1) Add a blank sapce after if/for/else/swtich, etc
     * (2) Add a blank space befor and after binary operator
     * (3) Add a blank space after semicolon(;)
     */

    if ((i < 10) || (j > 20))
    {
        return;
    }

    for (i = j - 1; i >= 0; i++)
    {
        return;
    }

    /*
     * [TOPIC] BLANK SPACE
     * (1) No blank space between function and following parenthesis
     */

    mmi_sample_code();

    /*
     * [TOPIC] SWITCH CASE
     * (1) Add one blank space between each case 
     * (2) If have bracket in case, put break inside (example's case 1)
     * (3) Should add default handler
     * (4) Indent refer to the following example
     */

    switch (i)
    {
        case 0:
            data1 = 10;
            break;

        case 1:
        {
            S32 local_data = 20;

            data1 = local_data;
            break;
        }

        case 0:
            data1 = 30;
            break;

        default:
            /* shall not enter here */
            MMI_ASSERT(0);
            break;

    }

    /*
     * [TOPIC] SPLIT LONG EXPRESSION
     * (1) Align to proper indent
     */

    if ((g_mmi_cntx->data1 == NULL) && ((g_mmi_cntx->data2 == NULL) || (g_mmi_cntx->data3 == NULL)))
    {
        return;
    }

    for (curr = *listp, tail = listp; curr != NULL; tail = &(curr->next), curr = curr->next)
    {

    }

    /*
     * [TOPIC] SPLIT LONG FUNCTION
     * (1) Parameter's align to the first tab from function's head
     */

    ret_value = mmi_this_is_a_very_long_function_name(
                    MMI_TURE,
                    g_mmi_cntx.theme.scrollbar.position,
                    g_mmi_cntx.theme.scrollbar.rect,
                    g_mmi_cntx.theme.scrollbar.color);

    long_ret_value_name
        = mmi_this_is_a_very_long_function_name(
            MMI_TURE,
            g_mmi_cntx.theme.scrollbar.position,
            g_mmi_cntx.theme.scrollbar.rect,
            g_mmi_cntx.theme.scrollbar.color);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_function
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  var_1           [IN]            Description of var_1
 *  var_2_ptr       [OUT]           Description of var_2_ptr
 *  var_3_ptr       [IN/OUT]        Description of var_3_ptr
 * RETURNS
 *  You description of return value
 * RETURN VALUE LIST
 *  MMI_RETURN_1     Description of return_1
 *  MMI_RETURN_2     Description of return_2
 *  MMI_RETURN_3     Description of return_3
 *****************************************************************************/
U16 mmi_sample_function(U16 var_1, U16 *var_2_ptr, U16 *var_3_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

}