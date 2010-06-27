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
 * TCM_COMMON.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file describes the common functions of TCM.
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
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _TCM_COMMON_H
#define _TCM_COMMON_H

#ifndef _TCM_COMMON_ENUMS_H
   #error include tcm_common_enums.h before tcm_common.h
#endif /* ~_TCM_COMMON_ENUMS_H */

#ifndef _PPP_L4_ENUMS_H
   #error include ppp_l4_enums.h before tcm_common.h
#endif /* ~_PPP_L4_ENUMS_H */

#ifndef _MMI_SM_ENUMS_H
   #error include mmi_sm_enums.h before tcm_common.h
#endif /* ~_MMI_SM_ENUMS_H */

#if !((GPRS_MAX_PDP_SUPPORT >= 2) && (GPRS_MAX_PDP_SUPPORT <= 7))
   #error please define GPRS_MAX_PDP_SUPPORT in the range [2-7]
#endif

#define MAX_PDU_LENGTH    1500
#define TCM_INIT_NPDU_NOS 0
#define MMI_MAX_NUM_CONFIG_OPTION_PACKETS 84
#define SESSION_INFO_PTR  session_info_block_struct*
/* These defines are used as a flag to determine the amount to be
 * subtracted from either a nsapi or context_id to get the
 * corresponding sib_id.
 */
#define MMI_NSAPI         0
#define MMI_CONTEXTID     1
#define MMI_CONFIG_PROTOCOL_PPP  0

#define TCM_RMMI_NSAPI 5
#define TCM_LMMI_NSAPI 6


#define SME_ASSERT(X,Y) ASSERT(X)

#define assert ASSERT
#define mmi_err(X,Y) NULL

/* Default values used in the various fields of session information
 * block.
 */
#define DEF_ADDRTYPE          IPV4_ADDR_TYPE /* Default address is
                                              * IPv4.
                                              */
#define DEF_L2P               PPP    /* Default L2P is PPP */
#define DEF_APNLENGTH         0      /* Default Apn length is zero or
                                      * no apn.
                                      */
#define DEF_APN               NULL   /* Default Apn is no apn */
#define DEF_NPDUNUM           0      /* Default Npdu number is zero */
#define DEF_PCONFOPTLENGTH    0      /* Default protocol configuration
                                      * option length is zero or no
                                      * protocol configuration length.
                                      */
#define DEF_PCONFOPTS         NULL   /* Default protocol configuration
                                      * options are no configuration.
                                      */
#define DEF_PDPADDRLEN        NULL_PDP_ADDR_LEN/* Default pdp address
                                                * length is set to
                                                * NULL_PDP_ADDR_LEN.
                                                */
/* Total number of MMI Modules */
#define MMI_NUM_MODULES       2

/* Total number of nsapi's */
/* Modified by: CH_Liang 2005.01.25
 * Description: define the NSAPI range.
 */
#define MMI_TOT_VISIBLE_CONTEXT 	MAX_EXT_PDP_CONTEXT	/* for External */
#define MMI_TOT_NSAPI     			GPRS_MAX_PDP_SUPPORT
#define MMI_TOT_CONTEXT   			(MMI_TOT_VISIBLE_CONTEXT + MMI_TOT_NSAPI)

#define MMI_INVALID_NSAPI		 	0
#define MMI_INVALID_CONTEXT_ID 	0

#define MMI_MIN_NSAPI           	MIN_VALID_NSAPI
#define MMI_MAX_NSAPI           	MAX_VALID_NSAPI
/* End of Modification, 2005.03.19. Reviewed by: Joseph */

#define MMI_MIN_CONTEXT_ID      1
#define MMI_MAX_CONTEXT_ID      1 + MMI_TOT_CONTEXT -1
#define DST_PORT_RANGE          2
#define SRC_PORT_RANGE          2
#define TOS_TRAF_CLASS_MASK_LEN 2
#define MMI_PRIMARY_UNKNOWN     12 /* Context id is set to 12 which
                                    * is not a valid context_id. Sib
                                    * should be initialized to this
                                    * value.
                                    */
#define  MMI_TFT_FIELD_NOT_PRESENT -1

#define MMI_PDP_TYPE              IPV4_ADDR_TYPE
#define MMI_PDP_LEN               IPV4_ADDR_LEN
#define MAX_SRC_ADDR_SBNET_MASK_LEN 8

/* mtk00714 w0633: AT definition*/
#define TCM_CGDCONT_DEFINED	0x01
#define TCM_CGDSCONT_DEFINED	0x02
#define TCM_CGQREQ_DEFINED	0x04
#define TCM_CGQMIN_DEFINED	0x08
#define TCM_CGTFT_DEFINED	0x10


/* This structure is used to cast any message received by the tcm
 * module. Once a message is cast to this type the corresponding nsapi
 * or context_id will be available.
 */
typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint8 id;
} mmi_nsapi_cntxt_id_cast_struct;

typedef struct pkt_filter_struct
{
    kal_uint8                context_id;
    kal_uint8                pfi;
    kal_uint8                epi;
    kal_uint8                src_addr_sb_net_mask_len;
    packet_filter_type_enum  type;
    kal_uint8       src_addr_sb_net_mask[MAX_SRC_ADDR_SBNET_MASK_LEN];
    kal_bool        prot_number_present;
    kal_uint8       prot_number_next_hdr;
    kal_uint16      dst_port_range[DST_PORT_RANGE];
    kal_uint8       dst_port_len;
    kal_uint8       src_port_len;
    kal_uint16      src_port_range[SRC_PORT_RANGE];
    kal_bool        ipsec_spi_present;
    kal_uint8       tos_len;
    kal_uint8       tos_traffic_class_mask [TOS_TRAF_CLASS_MASK_LEN];
    kal_uint32      ipsec_spi;
    kal_bool	    flow_label_present;
    kal_uint32      flow_label;
    struct pkt_filter_struct   *next_ptr;
} mmi_packet_filter_struct;

typedef struct
{
    mmi_packet_filter_struct *filter_list_ptr;
} mmi_tft_struct;

/* MMI : This is added for class-B MMI */
typedef struct mmi_protocol_config_packet_struct
{
    kal_uint16 protocol_id;
    kal_uint8  protocol_config_size;
    kal_uint8  protocol_config[ MAX_CONFIG_OPTION_CONTENT_LEN ];
    struct mmi_protocol_config_packet_struct *next_ptr;
} mmi_protocol_config_packet_struct;

typedef struct
{
    kal_uint8      context_id;/* Context identifier */
    kal_uint8      nsapi;     /* Nsapi identifier */
    kal_uint8      token_id; /* Stores the token_id sent by SM incase
                              * of a network initiated context
                              * activation indication
                              */
    kal_uint8      profile_id; /* Internal profile identifier */

    kal_uint8 	  AT_definition; //mtk00714 w0633
	
    pdp_context_type_enum context_type; /* Context type identifier
                                         * (Primary/Secondary).
                                         */
                                         
    kal_uint8  primary_context_id;/* Primary context identifier to 
                                   * which this context is associated.
                                   */
    /***************************************/
    /* affected by +CGDCONT and +CGDSCONT */
    /***************************************/
    kal_uint8      apn_len;  /* Access point name length. This is a
                              * optional parameter at the time of
                              * context activation.
                              */
    pdp_addr_type_enum     pdp_addr_type;/* pdp address type */
    pdp_addr_len_enum      pdp_addr_len; /* pdp address length */
    mmi_addr_scheme_enum   addr_scheme; /* Addressing scheme
                                         * (Static/Dynamic)
                                         */
    kal_uint8 addr_val[MAX_PDP_ADDR_LEN];/* pdp address is stored in
                                          * this field. the address is
                                          * filled in the most
                                          * significant bits; this
                                          * address received will have
                                          * variable length.
                                          */
    kal_uint8      apn[MAX_APN_LEN]; /* Access point name. */
        
    snd_pcomp_algo_enum pcomp_algo;/* Protocol compression algorithm
                                    * to be used.
                                    */
    snd_dcomp_algo_enum dcomp_algo;/* Protocol decompression algorithm
                                    * to be used.
                                    */
                                    
    /***************************************/
    /* affected by +CGQREQ and +CGEQREQ */
    /***************************************/
    qos_struct     req_qos; /* Requeseted qos */
									
    /***************************************/
    /* affected by +CGQMIN and +CGEQMIN */
    /***************************************/
    qos_struct     min_qos; /* Minimum qos */
	
    /****************************************/
    qos_struct     neg_qos; /* Negotiated qos */

    context_mod_type_enum     mod_type; /* Context modification type
                                         * field.
                                         */ 
    mmi_ltwoh_protocol_enum   l2p;   /* Layer two protocol used */
    kal_uint8 prot_option_len; /* Protocol configuration option length
                                * field.
                                */
    /* MMI: This is added for class-B MMI */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    kal_uint8           config_protocol;
    mmi_protocol_config_packet_struct  prot_options_struct;
#endif
    initiated_enum initiated_by;/* Context initiation identifier
                                 * (network/Ms)
                                 */
    mmi_tft_struct tft_in_use;  /* Traffic flow template currently
                                 * being used by a context.
                                 */
    mmi_tft_struct tft_under_mod;/* Traffic flow template to which the
                                  * context is requested to modify to.
                                  */
    mmi_startup_type_enum startup_type; /* pdp startup identifier.
                                         * Could be internal(via ATCI)
                                         * or external(via PPP).
                                         */
    mmi_context_state_enum  state;/* PDP context state. This is not to
                                   * be confused with attachstatus,
                                   * i.e. GMM state.
                                   */
    tft_opcode_enum     tft_opcode;   /* the tft operation opcode */
    mmi_sib_usage_enum  is_sib_defined;/* Used to know whether the
                                        * sib is free or in use.
                                        */
    kal_uint8          dns[4];
#ifdef __WINCE__
    kal_uint8           dns2[4];	
    module_type	module_id;
#endif
    kal_uint8          is_chap;

    kal_uint8          name_length;
    kal_uint8          name_dcs;
    kal_uint8          name[32];
    kal_uint8          user_name[TCM_MAX_GPRS_USER_NAME_LEN];
    kal_uint8          password[TCM_MAX_GPRS_PASSWORD_LEN];

    kal_uint8          src_id; /* L4C src_id, add 04.04.29 */
    kal_uint8            tear_down_flag;  //erica dallas 20060505: for 2ndary PDP

    kal_uint16 		req_n201u; //erica 20070112
}session_info_block_struct; /* End of type definition of session
                             * information block.
                             */
/* MMI common functions prototypes */

/* Functions to manipulate the session information block  */
extern kal_bool tcm_is_test_sim(void); //for __GEMINI__
							 
extern void tcm_error_handler( local_para_struct *local_para_ptr,
                               peer_buff_struct  *peer_buff_ptr );

extern kal_bool tcm_terminate_context( kal_uint8 sib_id );

extern void tcm_send_write_statistic_to_nvram( void );

extern kal_bool  mmi_create_sib( kal_uint8         sib_id );

extern kal_bool mmi_delete_sib( kal_uint8         sib_id );

extern kal_bool mmi_init_context( void );

extern kal_bool mmi_reset_context( void );

extern kal_bool mmi_check_msg( ilm_struct *ilm_ptr ); 

extern kal_bool mmi_string_cmp( kal_uint8  *str1,
                                kal_uint32 len1,
                                kal_uint8  *str2,
                                kal_uint32 len2 );

extern void tcm_qos_extend(qos_struct *qos);
extern void tcm_qos_R98_to_R99(qos_struct *s);
extern void tcm_qos_R99_to_R98(qos_struct *s);

extern void mmi_fill_def_qos_gprs( mmi_qos_type_enum         type,
                                   session_info_block_struct *sib_ptr
                                 );

extern void mmi_fill_def_qos_umts( mmi_qos_type_enum         type,
                                   session_info_block_struct *sib_ptr
                                 );


extern kal_bool mmi_is_sib_free( kal_uint8          sib_id,
                                 mmi_sib_usage_enum *sib );

extern kal_uint8 mmi_nsapi_check( kal_uint8 nsapi );

extern kal_uint8 mmi_cntxt_id_check( kal_uint8 cntxt_id );

extern kal_uint8 mmi_pdp_addr_ltcheck( pdp_addr_len_enum  pl,
                                       pdp_addr_type_enum pt );

extern kal_uint8 mmi_smcause_check( ps_cause_enum cs );

extern kal_uint8 mmi_qos_check( qos_struct *q_ptr );


extern void mmi_ignore_msg( local_para_struct  *local_para_ptr,
                            peer_buff_struct *peer_buff_ptr );

extern session_info_block_struct *mmi_get_sib_ptr( kal_uint8 sib_id );

extern mmi_packet_filter_struct *mmi_free_list(
                                mmi_packet_filter_struct *l_ptr );

extern mmi_packet_filter_struct *mmi_delete_list(
                                mmi_packet_filter_struct *d_ptr,
                                mmi_packet_filter_struct *s_ptr );
#ifdef __R99__
extern void mmi_append_list( mmi_packet_filter_struct **d_ptr,
			     mmi_packet_filter_struct **s_ptr,
			     kal_bool replace );
#endif

extern kal_uint8 mmi_get_sib_id( kal_int32 flag,
                                 kal_uint8 val );

extern kal_uint8 mmi_get_context_id( kal_uint8 sib_id );

 /* erica 20051215  mark unused codes */
//extern kal_uint8 mmi_get_nsapi( kal_uint8 sib_id );

extern void mmi_send_msg_to_mm( msg_type msg_type, void *param_ptr,
                                module_type mod_name );

extern kal_bool mmi_alloc_nsapi( kal_uint8 context_id );
extern void mmi_free_nsapi( SESSION_INFO_PTR si_db_ptr );

extern kal_uint8 mmi_nsapi_to_cid( kal_uint8 nsapi );
extern kal_uint8 mmi_cid_to_nsapi( kal_uint8 cid );
extern kal_bool mmi_cid_in_use( kal_uint8 cid );

//erica 20060916
extern void tcm_fill_config_options(void *config_option, 
							kal_uint8* config_option_num, 
							kal_uint8 is_chap, 
							kal_uint8* user_name, 
							kal_uint8*password);
#ifdef __WINCE__
extern kal_bool is_external_context(kal_uint8 context_id);
#endif

#endif


