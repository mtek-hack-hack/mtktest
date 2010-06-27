#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#

#If CUSTOM_CFLAGS = #-g in project makefile, set some modules to apply -g
#Please remove 1st # in the following 2 lines
#DEBUG_MODULES =  		# Value should be ALL or modules.
#CUSTOM_CFLAGS  := 		# Do not add any options for this.

#If CUSTOM_CFLAGS = -g in project makefile, set some modules NOT to apply -g
#Please remove 1st # in the following line
#NON_DEBUG_MODULES = 		# Value should be ALL or modules.


#Example of DEBUG_MODULES
#1. DEBUG_MODULES =  all
#   CUSTOM_CFLAGS := 
#      ==> all modules will apply -g when update, remake or new these modules
#
#2. DEBUG_MODULES =  kal stacklib plutommi mtkapp t9
#   CUSTOM_CFLAGS  := 
#      ==> only kal, stacklib, plutommi, mtkapp, t9 will apply -g 
#          when update, remake these modules or new
#
#
# NOTE: DEBUG_MODULES =  all kal stacklib, all modules will apply -g
#


#Example of NON_DEBUG_MODULES
#1. NON_DEBUG_MODULES =  all
#      ==> all modules will NOT apply -g when update, remake or new these modules
#
#2. NON_DEBUG_MODULES =  kal stacklib plutommi mtkapp t9
#      ==> only kal, stacklib, plutommi, mtkapp, t9 will NOT apply -g 
#          when update, remake these modules or new
#
#
# NOTE: NON_DEBUG_MODULES =  all kal stacklib, all modules will NOT apply -g
#
