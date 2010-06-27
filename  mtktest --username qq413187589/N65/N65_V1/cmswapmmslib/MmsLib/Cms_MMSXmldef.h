/*=====================================================================

 Copyright (c) 2001-2002 MobileSoft Corporation

    All Rights Reserved.

    $Logfile: cmsxmldefine.h

    $Revision:

    $vision:       1.00

    $Date:         07/21/2002

    $Author:       hulf

	$Declare: 
	This document contains information proprietary to MobileSoft  
 Technology (Nanjing),  Corp.    Transmittal, receipt, or possession 
 of this document does not express, license, or imply any rights to 
 use, sell, design, or manufacture from this information. No reproduction, 
 publication, or disclosure of this information, in whole or in part, 
 shall be made without prior written authorization from an officer of 
 MobileSoft Technology (NanJing), Corp.

 

Abstract:

 

Modified By:

 

Environment: 

 

Revision History:

 

=====================================================================*/


#ifndef CMSHTMLDEF_H
#define CMSHTMLDEF_H

/*****************************************************************************/

/* WML ELEMENT DEFINE */

#define XML_EL_NULL				0
#define WML_EL_A				1
#define WML_EL_ABBR				2 
#define WML_EL_ACRONYM			3
#define WML_EL_ACCESS			4
#define WML_EL_ADDRESS			5
#define WML_EL_ANCHOR			6
#define WML_EL_B				7
#define WML_EL_BASE				8
#define WML_EL_BIG				9
#define WML_EL_BLOCKQUOTE		10
#define WML_EL_BODY				11
#define WML_EL_BR				12
#define WML_EL_CAPTION			13
#define WML_EL_CARD				14
#define WML_EL_CITE				15
#define WML_EL_CODE				16
#define WML_EL_DD				17
#define WML_EL_DFN				18
#define WML_EL_DIV				19
#define WML_EL_DEFINITION_LIST	20
#define WML_EL_DO				21
#define WML_EL_TERM				22
#define WML_EL_EMPHASIS			23
#define WML_EL_FIELDSET			24
#define WML_EL_FORM				25
#define WML_EL_GETVAR			26
#define WML_EL_GO				27
#define WML_EL_H1				28
#define WML_EL_H2				29
#define WML_EL_H3				30
#define WML_EL_H4				31
#define WML_EL_H5				32
#define WML_EL_H6				33
#define WML_EL_HEAD				34
#define WML_EL_HORIZONTAL_RULE	35
#define WML_EL_HTML				36
#define WML_EL_I				37
#define WML_EL_IMG				38
#define WML_EL_INPUT			39
#define WML_EL_KBD				40
#define WML_EL_LABEL			41
#define WML_EL_LIST_ITEM		42
#define WML_EL_LINK				43
#define WML_EL_META				44
#define WML_EL_NOOP				45
#define WML_EL_OBJECT			46
#define WML_EL_NUMBERED_LIST	47
#define WML_EL_ONEVENT			48
#define WML_EL_OPTGROUP			49
#define WML_EL_OPTION			50
#define WML_EL_PARAGRAPH		51
#define WML_EL_PARAM			52
#define WML_EL_POSTFIELD		53
#define WML_EL_PREFORMATTED		54
#define WML_EL_PREV				55
#define WML_EL_REFRESH			56
#define WML_EL_QUOTATION		57
#define WML_EL_SAMP				58
#define WML_EL_SELECT			59
#define WML_EL_SETVAR			60
#define WML_EL_SMALL			61
#define WML_EL_SPAN				62
#define WML_EL_STRONG			63
#define WML_EL_STYLE			64
#define WML_EL_TABLE			65
#define WML_EL_DATA_CELL		66
#define WML_EL_TEXT				67
#define WML_EL_TEXTAREA			68
#define WML_EL_TABLE_HEAD		69
#define WML_EL_TIMER			60
#define WML_EL_TITLE			71
#define WML_EL_TABLE_ROW		72
#define WML_EL_UNDERLINED_TEXT	73
#define WML_EL_UNNUMBERED_LIST	74
#define WML_EL_VARIABLE			75
#define WML_EL_WIDGET			76
#define WML_EL_WML				77

/* SMIL ELEMENT DEFINE */

#define SMIL_EL_A				101
#define SMIL_EL_ANCHOR			102
#define SMIL_EL_ANIMATE			163
#define SMIL_EL_ANIMATECOLOR	104
#define SMIL_EL_ANIMATEMOTION	105
#define SMIL_EL_ANIMATION		106
#define SMIL_EL_AREA			107
#define SMIL_EL_AUDIO			108
#define SMIL_EL_BRUSH			109
#define SMIL_EL_BODY			110
#define SMIL_EL_CUSTOMATTRIBUTES	111
#define SMIL_EL_CUSTOMTEST		112
#define SMIL_EL_EXCL			113
#define SMIL_EL_HEAD			114
#define SMIL_EL_IMG				115
#define SMIL_EL_LAYOUT			116
#define SMIL_EL_META			117
#define SMIL_EL_METADATA		118
#define SMIL_EL_PAR				119
#define SMIL_EL_PARAM			120
#define SMIL_EL_PREFETCH		121
#define SMIL_EL_PRIORITYCLASS	122
#define SMIL_EL_REF				123
#define SMIL_EL_REGION			124
#define SMIL_EL_REGPOINT		125
#define SMIL_EL_ROOT_LAYOUT		126
#define SMIL_EL_SEQ				127
#define SMIL_EL_SET				128
#define SMIL_EL_SMIL			129
#define SMIL_EL_SWITCH			130
#define SMIL_EL_TEXT			131
#define SMIL_EL_TEXTSTREAM		132
#define SMIL_EL_TOPLAYOUT		133
#define SMIL_EL_TRANSITION		134
#define SMIL_EL_TRANSITIONFILTER	135
#define SMIL_EL_VIDEO			136
#define SMIL_EL_ACCESSORY			137

/* WML ATTRIBUTE DEFINE */

#define WML_ATTR_abbr				0
#define WML_ATTR_accept				1
#define WML_ATTR_accept_charset		2
#define WML_ATTR_accesskey			3
#define WML_ATTR_ActiveLinkColor	4
#define WML_ATTR_Align				5
#define WML_ATTR_Alignment			6
#define WML_ATTR_ALT				7	
#define WML_ATTR_applet_name		8
#define WML_ATTR_archive			9
#define WML_ATTR_Area_Size			10
#define WML_ATTR_Associated_control 11
#define WML_ATTR_axis				12
#define WML_ATTR_BackgroundColor	13
#define WML_ATTR_background_		14
#define WML_ATTR_BaseFontColor		15
#define WML_ATTR_BaseFontFace		16
#define WML_ATTR_BaseFontSize		17
#define WML_ATTR_Border				18
#define WML_ATTR_BulletStyle		19
#define WML_ATTR_Button_type		20
#define WML_ATTR_cellpadding		21
#define WML_ATTR_cellspacing		22
#define WML_ATTR_Cell_align			23
#define WML_ATTR_Cell_valign		24
#define WML_ATTR_char				25
#define WML_ATTR_charoff			26
#define WML_ATTR_charset			27
#define WML_ATTR_Checked			28
#define WML_ATTR_cite				29
#define WML_ATTR_Class				30
#define WML_ATTR_classid			31
#define WML_ATTR_Clear				32
#define WML_ATTR_code				33
#define WML_ATTR_codebase			34
#define WML_ATTR_codetype			35
#define WML_ATTR_color				36
#define WML_ATTR_colspan_			37
#define WML_ATTR_Columns			38
#define WML_ATTR_ColWidth			39
#define WML_ATTR_COMPACT			40
#define WML_ATTR_content_type		41
#define WML_ATTR_coords				42
#define WML_ATTR_data				43
#define MML_ATTR_datapagesize		44
#define WML_ATTR_datetime			45
#define WML_ATTR_declare			46
#define WML_ATTR_defer				47
#define WML_ATTR_dir				48
#define WML_ATTR_disabled			49
#define WML_ATTR_ENCTYPE			50
#define WML_ATTR_event				51
#define WML_ATTR_face				52
#define WML_ATTR_Font_size			53
#define WML_ATTR_for_				54
#define WML_ATTR_frame				55
#define WML_ATTR_frameborder		56
#define WML_ATTR_FrameName			57
#define WML_ATTR_FrameSrc			58
#define WML_ATTR_Ghost_restruct		59
#define WML_ATTR_headers			60
#define WML_ATTR_Height_			61
#define WML_ATTR_hreflang			62
#define WML_ATTR_HREF_				63
#define WML_ATTR_hspace				64
#define WML_ATTR_http_equiv			65
#define WML_ATTR_ID					66
#define WML_ATTR_Img_border			67
#define WML_ATTR_Invalid_attribute	68
#define WML_ATTR_ISMAP				69
#define WML_ATTR_ItemStyle			70
#define WML_ATTR_ItemValue			71
#define WML_ATTR_label				72
#define WML_ATTR_Langue				73
#define WML_ATTR_LinkColor			74
#define WML_ATTR_Link_type			75
#define WML_ATTR_longdesc			76
 
#define WML_ATTR_marginheight		77
#define WML_ATTR_marginwidth		78
#define WML_ATTR_MaxLength			79
#define WML_ATTR_media				80
#define WML_ATTR_MenuSize			81
#define WML_ATTR_meta_content		82
#define WML_ATTR_meta_name			83
#define WML_ATTR_METHOD				84
#define WML_ATTR_mode				85
#define WML_ATTR_Multiple			86
#define WML_ATTR_NAME				87
#define WML_ATTR_nohref				88
#define WML_ATTR_NoShade			89
#define WML_ATTR_Notation			90
#define WML_ATTR_no_resize			91
#define WML_ATTR_No_wrap			92
#define WML_ATTR_NumberStyle		93
#define WML_ATTR_object				94
#define WML_ATTR_Object_type		95
#define WML_ATTR_onblur				96
#define WML_ATTR_onchange			97
#define WML_ATTR_onclick			98
#define WML_ATTR_ondblclick			99
#define WML_ATTR_onfocus			100
#define WML_ATTR_onkeydown			101
#define WML_ATTR_onkeypress			102
#define WML_ATTR_onkeyup			103
#define WML_ATTR_onload				104
#define WML_ATTR_onmousedown		105
#define WML_ATTR_onmousemove		106
#define WML_ATTR_onmouseout			107
#define WML_ATTR_onmouseover		108
#define WML_ATTR_onmouseup			109
#define WML_ATTR_onreset			110
#define WML_ATTR_onselect			111
#define WML_ATTR_onsubmit			112
#define WML_ATTR_onunload			113
#define WML_ATTR_Param_name			114
#define WML_ATTR_Param_type			115
#define WML_ATTR_Param_value		116
#define WML_ATTR_Position			117
#define WML_ATTR_profile			118
#define WML_ATTR_Prompt				119
#define WML_ATTR_readonly			120
#define WML_ATTR_REL				121
#define WML_ATTR_REV				122
#define WML_ATTR_RowHeight			123
#define WML_ATTR_Rows				124
#define WML_ATTR_rowspan_			125
#define WML_ATTR_Row_valign			126
#define WML_ATTR_rules_				127
#define WML_ATTR_scheme				128
#define WML_ATTR_scope				129
#define WML_ATTR_URL				132

#define WML_ATTR_scrolling			133
#define WML_ATTR_Selected			134
#define WML_ATTR_shape				135
#define WML_ATTR_Size_				136
#define WML_ATTR_SRC				137
#define WML_ATTR_standby			138
#define WML_ATTR_Start				139
#define WML_ATTR_Style_				140
#define WML_ATTR_summary			141
#define WML_ATTR_tabindex			142
#define WML_ATTR_target_			143
#define WML_ATTR_TextAlign			144
#define WML_ATTR_TextColor			145
#define WML_ATTR_Title				146
#define WML_ATTR_USEMAP				147
#define WML_ATTR_valuetype			148
#define WML_ATTR_Value_				149
#define WML_ATTR_VisitedLinkColor	150
#define WML_ATTR_vspace				151
#define WML_ATTR_Width__			152
#define WML_ATTR_x_coord			153
#define WML_ATTR_y_coord			154
#define WML_ATTR_IntWidthPxl		155
#define WML_ATTR_height_			156
#define WML_ATTR_DefaultSelected	157
#define WML_ATTR_Default_Value		158
#define WML_ATTR_IntItemStyle		159
#define WML_ATTR_Error_type			160
#define WML_ATTR_PseudoClass		161
#define WML_ATTR_DefaultChecked		162
#define WML_ATTR_IntWidthPercent	163
#define WML_ATTR_IntSizeIncr		164
#define WML_ATTR_IntSizeDecr		165
#define WML_ATTR_IntSizeRel			166
#define WML_ATTR_Ref_column			167
#define WML_ATTR_RowExt				168
#define WML_ATTR_ColExt				169

#define WML_ATTR_direction			170
#define WML_ATTR_spacetype			171
#define WML_ATTR_LENGTH				172
#define WML_ATTR_TYPE				173
#define WML_ATTR_scrolldelay		174
#define WML_ATTR_scrollamount		175
#define WML_ATTR_option_onpick		176
#define WML_ATTR_HTTP_EQUIV			177
#define WML_ATTR_ontimer			178
#define WML_ATTR_DO_TYPE			179
#define WML_ATTR_ONEVENT_TYPE		180
#define WML_ATTR_DO_optional		181
#define WML_ATTR_onenterbackward	182
#define WML_ATTR_onenterforward		183
#define WML_ATTR_NULL				200  

/* SMIL ATTRIBUTE DEFINE */

#define SMIL_ATTR_abstract			201
#define SMIL_ATTR_accelerate		202
#define SMIL_ATTR_accesskey			203
#define SMIL_ATTR_accumulate		204
#define SMIL_ATTR_actuate			205
#define SMIL_ATTR_additive			206
#define SMIL_ATTR_alt				207
#define SMIL_ATTR_attributeName		208
#define SMIL_ATTR_attributeType		209
#define SMIL_ATTR_author			210
#define SMIL_ATTR_autoReverse		211
#define SMIL_ATTR_backgroundColor	212
#define SMIL_ATTR_background_color	213
#define SMIL_ATTR_bandwidth			214
#define SMIL_ATTR_begin				215
#define SMIL_ATTR_borderColor		216
#define SMIL_ATTR_borderWidth		217
#define SMIL_ATTR_bottom			218
#define SMIL_ATTR_by				219
#define SMIL_ATTR_calcMode			220
#define SMIL_ATTR_class				221
#define SMIL_ATTR_clipBegin			222
#define SMIL_ATTR_clip_begin		223
#define SMIL_ATTR_clipEnd			224
#define SMIL_ATTR_clip_end			225
#define SMIL_ATTR_close				226
#define SMIL_ATTR_color				227
#define SMIL_ATTR_content			228
#define SMIL_ATTR_coords			229
#define SMIL_ATTR_copyright			230
#define SMIL_ATTR_customTest		231
#define SMIL_ATTR_decelerate		232
#define SMIL_ATTR_defaultState		233
#define SMIL_ATTR_destinationLevel	234
#define SMIL_ATTR_destinationPlaystate	235
#define SMIL_ATTR_direction			236
#define SMIL_ATTR_dur				237
#define SMIL_ATTR_end				238
#define SMIL_ATTR_endProgress		239
#define SMIL_ATTR_endsync			240
#define SMIL_ATTR_erase				241
#define SMIL_ATTR_external			242
#define SMIL_ATTR_fadeColor			243
#define SMIL_ATTR_fill				244
#define SMIL_ATTR_fillDefault		245
#define SMIL_ATTR_fillTransition	246
#define SMIL_ATTR_fit				247
#define SMIL_ATTR_fragment			248
#define SMIL_ATTR_from				249
#define SMIL_ATTR_height			250
#define SMIL_ATTR_higher			251
#define SMIL_ATTR_horzRepeat		252
#define SMIL_ATTR_href				253
#define SMIL_ATTR_id				254
#define SMIL_ATTR_keySplines		255
#define SMIL_ATTR_keyTimes			256
#define SMIL_ATTR_left				257
#define SMIL_ATTR_longdesc			258
#define SMIL_ATTR_lower				259
#define SMIL_ATTR_max				260
#define SMIL_ATTR_mediaRepeat		261
#define SMIL_ATTR_mediaSize			262
#define SMIL_ATTR_mediaTime			263
#define SMIL_ATTR_min				264
#define SMIL_ATTR_mode				265
#define SMIL_ATTR_name				266
#define SMIL_ATTR_nohref			267
#define SMIL_ATTR_open				268
#define SMIL_ATTR_origin			269
#define SMIL_ATTR_override			270
#define SMIL_ATTR_path				271
#define SMIL_ATTR_pauseDisplay		272
#define SMIL_ATTR_peers				273
#define SMIL_ATTR_readIndex			274
#define SMIL_ATTR_regAlign			275
#define SMIL_ATTR_region			276
#define SMIL_ATTR_regionName		277
#define SMIL_ATTR_regPoint			278
#define SMIL_ATTR_repeat			279
#define SMIL_ATTR_repeatCount		280
#define SMIL_ATTR_repeatDur			281
#define SMIL_ATTR_restart			282
#define SMIL_ATTR_restartDefault	283
#define SMIL_ATTR_right				284
#define SMIL_ATTR_shape				285
#define SMIL_ATTR_show				286
#define SMIL_ATTR_showBackground	287
#define SMIL_ATTR_skip_content		288
#define SMIL_ATTR_soundLevel		289
#define SMIL_ATTR_sourceLevel		290
#define SMIL_ATTR_sourcePlaystate	291
#define SMIL_ATTR_speed				292
#define SMIL_ATTR_src				293
#define SMIL_ATTR_startProgress		294
#define SMIL_ATTR_subtype			295
#define SMIL_ATTR_syncBehavior		296
#define SMIL_ATTR_syncBehaviorDefault	297
#define SMIL_ATTR_syncMaster		298
#define SMIL_ATTR_syncTolerance		299
#define SMIL_ATTR_syncToleranceDefault	300
#define SMIL_ATTR_systemAudioDesc	301
#define SMIL_ATTR_systemBitrate		302
#define SMIL_ATTR_systemCaptions	303
#define SMIL_ATTR_systemComponent	304
#define SMIL_ATTR_systemCPU			305
#define SMIL_ATTR_systemLanguage	306
#define SMIL_ATTR_systemOperatingSystem	307
#define SMIL_ATTR_system_overdub_or_caption	308
#define SMIL_ATTR_systemOverdubOrSubtitle	309
#define SMIL_ATTR_systemRequired	310
#define SMIL_ATTR_systemScreenDepth	311
#define SMIL_ATTR_systemScreenSize	312
#define SMIL_ATTR_tabindex			313
#define SMIL_ATTR_target			314
#define SMIL_ATTR_targetElement		315
#define SMIL_ATTR_timeAction		316
#define SMIL_ATTR_timeContainer		317
#define SMIL_ATTR_title				318
#define SMIL_ATTR_to				319
#define SMIL_ATTR_top				320
#define SMIL_ATTR_transIn			321
#define SMIL_ATTR_transOut			322
#define SMIL_ATTR_type				323
#define SMIL_ATTR_uid				324
#define SMIL_ATTR_value				325
#define SMIL_ATTR_values			326
#define SMIL_ATTR_valuetype			327
#define SMIL_ATTR_vertRepeat		328
#define SMIL_ATTR_width				329
#define SMIL_ATTR_lang				330
#define SMIL_ATTR_xmlns				331
#define SMIL_ATTR_z_index			332


/* WML ATTRIBUTE VALUE DEFINE FOR ENUM TYOE */

#define WML_ATTR_Alignment_VAL_Bottom_ 0
#define WML_ATTR_Alignment_VAL_Left_ 1
#define WML_ATTR_Alignment_VAL_Middle_ 2
#define WML_ATTR_Alignment_VAL_Right_ 3
#define WML_ATTR_Alignment_VAL_Top_ 4
#define WML_ATTR_Align_VAL_center_ 5
#define WML_ATTR_Align_VAL_left_ 6
#define WML_ATTR_Align_VAL_right_ 7
#define WML_ATTR_BulletStyle_VAL_circle 8
#define WML_ATTR_BulletStyle_VAL_disc 9
#define WML_ATTR_BulletStyle_VAL_square 10
#define WML_ATTR_Button_type_VAL_button 11
#define WML_ATTR_Button_type_VAL_reset 12
#define WML_ATTR_Button_type_VAL_submit 13
#define WML_ATTR_Cell_align_VAL_Cell_center 14
#define WML_ATTR_Cell_align_VAL_Cell_char 15
#define WML_ATTR_Cell_align_VAL_Cell_justify 16
#define WML_ATTR_Cell_align_VAL_Cell_left 17
#define WML_ATTR_Cell_align_VAL_Cell_right 18
#define WML_ATTR_Cell_valign_VAL_Cell_baseline 19
#define WML_ATTR_Cell_valign_VAL_Cell_bottom 20
#define WML_ATTR_Cell_valign_VAL_Cell_middle 21
#define WML_ATTR_Cell_valign_VAL_Cell_top 22
#define WML_ATTR_Checked_VAL_Yes_ 23
#define WML_ATTR_Clear_VAL_All_ 24
#define WML_ATTR_Clear_VAL_Left_ 25
#define WML_ATTR_Clear_VAL_None 26
#define WML_ATTR_Clear_VAL_Right_ 27
#define WML_ATTR_COMPACT_VAL_Yes_ 28
#define WML_ATTR_declare_VAL_Yes_ 29
#define WML_ATTR_defer_VAL_Yes_ 30
#define WML_ATTR_dir_VAL_ltr 31
#define WML_ATTR_dir_VAL_rtl 32
#define WML_ATTR_disabled_VAL_Yes_ 33
#define WML_ATTR_frameborder_VAL_Border0 34
#define WML_ATTR_frameborder_VAL_Border1 35
#define WML_ATTR_frame_VAL_above 36
#define WML_ATTR_frame_VAL_below 37
#define WML_ATTR_frame_VAL_border 38
#define WML_ATTR_frame_VAL_box 39
#define WML_ATTR_frame_VAL_hsides 40
#define WML_ATTR_frame_VAL_lhs 41
#define WML_ATTR_frame_VAL_rhs 42
#define WML_ATTR_frame_VAL_void 43
#define WML_ATTR_frame_VAL_vsides 44
#define WML_ATTR_ISMAP_VAL_Yes_ 45
#define WML_ATTR_ItemStyle_VAL_Arabic_ 46
#define WML_ATTR_ItemStyle_VAL_circle 47
#define WML_ATTR_ItemStyle_VAL_disc 48
#define WML_ATTR_ItemStyle_VAL_LowerAlpha 49
#define WML_ATTR_ItemStyle_VAL_LowerRoman 50
#define WML_ATTR_ItemStyle_VAL_square 51
#define WML_ATTR_ItemStyle_VAL_UpperAlpha 52
#define WML_ATTR_ItemStyle_VAL_UpperRoman 53
#define WML_ATTR_METHOD_VAL_Get_ 54
#define WML_ATTR_METHOD_VAL_Post_ 55
#define WML_ATTR_mode_VAL_display 56
#define WML_ATTR_mode_VAL_inline_math 57
#define WML_ATTR_Multiple_VAL_Yes_ 58
#define WML_ATTR_nohref_VAL_Yes_ 59
#define WML_ATTR_NoShade_VAL_NoShade_ 60
#define WML_ATTR_No_wrap_VAL_no_wrap 61
#define WML_ATTR_NumberStyle_VAL_Arabic_ 62
#define WML_ATTR_NumberStyle_VAL_LowerAlpha 63
#define WML_ATTR_NumberStyle_VAL_LowerRoman 64
#define WML_ATTR_NumberStyle_VAL_UpperAlpha 65
#define WML_ATTR_NumberStyle_VAL_UpperRoman 66
#define WML_ATTR_Position_VAL_Position_bottom 67
#define WML_ATTR_Position_VAL_Position_left 68
#define WML_ATTR_Position_VAL_Position_right 69
#define WML_ATTR_Position_VAL_Position_top 70
#define WML_ATTR_readonly_VAL_Yes_ 71
#define WML_ATTR_Row_valign_VAL_Row_baseline 72
#define WML_ATTR_Row_valign_VAL_Row_bottom 73
#define WML_ATTR_Row_valign_VAL_Row_middle 74
#define WML_ATTR_Row_valign_VAL_Row_top 75
#define WML_ATTR_rules__VAL_all 76
#define WML_ATTR_rules__VAL_cols 77
#define WML_ATTR_rules__VAL_groups 78
#define WML_ATTR_rules__VAL_none 79
#define WML_ATTR_rules__VAL_rows 80
#define WML_ATTR_scrolling_VAL_auto 81
#define WML_ATTR_scrolling_VAL_No_ 82
#define WML_ATTR_scrolling_VAL_Yes_ 83
#define WML_ATTR_Selected_VAL_Yes_ 84
#define WML_ATTR_shape_VAL_circle 85
#define WML_ATTR_shape_VAL_polygon 86
#define WML_ATTR_shape_VAL_rectangle 87
#define WML_ATTR_TextAlign_VAL_center_ 88
#define WML_ATTR_TextAlign_VAL_justify_ 89
#define WML_ATTR_TextAlign_VAL_left_ 90
#define WML_ATTR_TextAlign_VAL_right_ 91
#define WML_ATTR_valuetype_VAL_data_ 92
#define WML_ATTR_valuetype_VAL_object_ 93
#define WML_ATTR_valuetype_VAL_ref 94
#define WML_ATTR_DefaultSelected_VAL_Yes_ 95
#define WML_ATTR_Checked_VAL_No_ 96
#define WML_ATTR_IntItemStyle_VAL_disc 97
#define WML_ATTR_IntItemStyle_VAL_Arabic_ 98
#define WML_ATTR_IntItemStyle_VAL_LowerAlpha 99
#define WML_ATTR_IntItemStyle_VAL_UpperAlpha 100
#define WML_ATTR_IntItemStyle_VAL_LowerRoman 101
#define WML_ATTR_IntItemStyle_VAL_UpperRoman 102
#define WML_ATTR_IntItemStyle_VAL_circle 103
#define WML_ATTR_IntItemStyle_VAL_square 104
#define WML_ATTR_Error_type_VAL_BadPosition 105
#define WML_ATTR_Error_type_VAL_UnknownTag 106
#define WML_ATTR_DefaultChecked_VAL_Yes_ 107


#endif
